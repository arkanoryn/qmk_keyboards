#include "ark_v1.h"
#include "correction.h"
#include "virtser.h"

extern setting_dup_force SETTING_DUP_FORCE;
extern setting_virt_serial SETTING_VIRT_SERIAL;
extern setting_chord_mode SETTING_CHORD_MODE;

#define VIRT_KEYS 34
#define VIRT_KEYMULT_DOWN 0
#define VIRT_KEYMULT_UP 1
#define VIRT_KEYMULT_TAP 2
#define VIRT_KEYMULT_HOLD 3
#define VIRT_KEYMULT_LAST 4

#define VIRT_WARN 0
#define VIRT_HEARTBEAT 1
#define VIRT_KEYS_START VIRT_HEARTBEAT + 1
#define VIRT_KEYS_END VIRT_KEYS_START + VIRT_KEYS *VIRT_KEYMULT_LAST
#define VIRT_COMBO_SHIFTED VIRT_KEYS_END + 1
#define VIRT_CHORD_STARTED VIRT_COMBO_SHIFTED + 1
#define VIRT_CHORD_ENDED_INDETERMINATE VIRT_CHORD_STARTED + 1
#define VIRT_CHORD_ENDED_TAP VIRT_CHORD_ENDED_INDETERMINATE + 1
#define VIRT_CHORD_ENDED_HOLD VIRT_CHORD_ENDED_TAP + 1
#define VIRT_LAYER_ZERO VIRT_CHORD_ENDED_HOLD + 1
#define VIRT_LAYER_LAST VIRT_LAYER_ZERO + TOPLAYER
#define VIRT_MOD_ZERO VIRT_LAYER_LAST + 1
#define VIRT_SHIFT_DOWN VIRT_MOD_ZERO
#define VIRT_SHIFT_UP VIRT_SHIFT_DOWN + 1
#define VIRT_CTRL_DOWN VIRT_SHIFT_UP + 1
#define VIRT_CTRL_UP VIRT_CTRL_DOWN + 1
#define VIRT_ALT_DOWN VIRT_CTRL_UP + 1
#define VIRT_ALT_UP VIRT_ALT_DOWN + 1
#define VIRT_GUI_DOWN VIRT_ALT_UP + 1
#define VIRT_GUI_UP VIRT_GUI_DOWN + 1
#define VIRT_MOD_LAST VIRT_GUI_UP
#define VIRT_SETTINGS VIRT_MOD_LAST + 1
#define VIRT_SUPPRESSED_KEY VIRT_SETTINGS + 1
#define VIRT_LAST VIRT_SUPPRESS_KEY

#define VIRT_SETTING_DUP_FORCE 0
#define VIRT_SETTING_VIRT_SERIAL 1
#define VIRT_SETTING_CHORD_MODE 2

#if VIRT_LAST > 255
#  error Virt sidechannel message size exceeds one byte
#endif

#define VIRT_TIMEOUT 1000

static uint16_t recv_timer;
static uint8_t  prev_mods;

void virt_send(uint8_t byte) {
  if (timer_elapsed(recv_timer) > VIRT_TIMEOUT) {
    return;
  }

  if (SETTING_VIRT_SERIAL == VIRT_SERIAL_DISABLED) {
    return;
  }

  virtser_send(byte);
}

void emit_new_mods(keyrecord_t *record) {
  uint8_t mods = get_mods() | get_oneshot_mods();
  if (mods == prev_mods) {
    return;
  }

#define MOD_VIRTSEND(modifier)                           \
  bool now_##modifier = mods & MOD_MASK_##modifier;      \
  bool was_##modifier = prev_mods & MOD_MASK_##modifier; \
  if (now_##modifier && !was_##modifier) {               \
    virt_send(VIRT_##modifier##_DOWN);                   \
  } else if (!now_##modifier && was_##modifier) {        \
    virt_send(VIRT_##modifier##_UP);                     \
  }

  MOD_VIRTSEND(SHIFT);
  MOD_VIRTSEND(CTRL);
  MOD_VIRTSEND(ALT);
  MOD_VIRTSEND(GUI);

  prev_mods = mods;
}

void emit_virt_key(keyrecord_t *record, bool pressed, bool held, bool tap) {
  emit_new_mods(record);

  if (!pressed) {
    return;
  }

  uint8_t col = record->event.key.col;
  uint8_t row = 0;

  switch (record->event.key.col) {
    case 0: // bnq 'yk left-thumb-outer (MEH_SPC) right-thumb-inner (BSPC)
      break;
    case 1: // lrx fhp left-thumb-inner (MAGIC) right-thumb-outer (ENT)
      break;
    case 2: // wsc oa,
      break;
    case 3: // wsc ue.
      break;
    case 4: // zgv ji/
      break;
    default:
      return;
  }

  switch (record->event.key.row) {
    case 0: // bldwz
      row = 0;
      break;
    case 1: // nrtsg
      row = 1;
      break;
    case 2: // qxmcv
      row = 2;
      break;
    case 3: // left thumbs
      row = 3;
      break;
    case 4: // 'fouj
      row = 0;
      col += 5;
      break;
    case 5: // yhaei
      row = 1;
      col += 5;
      break;
    case 6: // kp,./
      row = 2;
      col += 5;
      break;
    case 7: // right thumbs
      row = 3;
      col += 2;
      break;
    default:
      return;
  }

  uint8_t mult = 0;

  if (held) {
    mult = VIRT_KEYMULT_HOLD;
  } else if (tap) {
    mult = VIRT_KEYMULT_TAP;
  } else if (!record->event.pressed) {
    mult = VIRT_KEYMULT_UP;
  } else {
    mult = VIRT_KEYMULT_DOWN;
  }

  uint8_t msg = VIRT_KEYS_START + row * 10 + col + mult * VIRT_KEYS;
  virt_send(msg);
}

extern combo_t key_combos[];

void emit_virt_combo(uint16_t combo_index, bool shifted, uint8_t event) {
  virt_send(VIRT_CHORD_STARTED);
  if (shifted) {
    virt_send(VIRT_COMBO_SHIFTED);
  }

  combo_t combo     = key_combos[combo_index];
  int     key_count = 0;
  while (true) {
    uint16_t key = pgm_read_word(&combo.keys[key_count]);
    if (COMBO_END == key) break;

    switch (key) {
        // clang-format off
        // line 1
      case KC_B: virt_send(VIRT_KEYS_START+0); break;
      case CTL_L: virt_send(VIRT_KEYS_START+1); break;
      case ALT_D: virt_send(VIRT_KEYS_START+2); break;
      case GUI_W: virt_send(VIRT_KEYS_START+3); break;
      case KC_Z: virt_send(VIRT_KEYS_START+4); break;
      case KC_QUOT: virt_send(VIRT_KEYS_START+5); break;
      case GUI_F: virt_send(VIRT_KEYS_START+6); break;
      case ALT_O: virt_send(VIRT_KEYS_START+7); break;
      case CTL_U: virt_send(VIRT_KEYS_START+8); break;
      case KC_J: virt_send(VIRT_KEYS_START+9); break;
      // line 2
      case L4_N: virt_send(VIRT_KEYS_START+10); break;
      case L3_R: virt_send(VIRT_KEYS_START+11); break;
      case L2_T: virt_send(VIRT_KEYS_START+12); break;
      case L1_S: virt_send(VIRT_KEYS_START+13); break;
      case KC_G: virt_send(VIRT_KEYS_START+14); break;
      case KC_Y: virt_send(VIRT_KEYS_START+15); break;
      case L1_H: virt_send(VIRT_KEYS_START+16); break;
      case L2_A: virt_send(VIRT_KEYS_START+17); break;
      case L3_E: virt_send(VIRT_KEYS_START+18); break;
      case L4_I: virt_send(VIRT_KEYS_START+19); break;
      // line 3
      case SFT_Q: virt_send(VIRT_KEYS_START+20); break;
      case KC_X: virt_send(VIRT_KEYS_START+21); break;
      case KC_M: virt_send(VIRT_KEYS_START+22); break;
      case KC_C: virt_send(VIRT_KEYS_START+23); break;
      case KC_V: virt_send(VIRT_KEYS_START+24); break;
      case KC_K: virt_send(VIRT_KEYS_START+25); break;
      case KC_P: virt_send(VIRT_KEYS_START+26); break;
      case KC_COMM: virt_send(VIRT_KEYS_START+27); break;
      case KC_DOT: virt_send(VIRT_KEYS_START+28); break;
      case SFT_SLSH: virt_send(VIRT_KEYS_START+29); break;
      case MEH_SPC: virt_send(VIRT_KEYS_START+30); break;
      case MAGIC: virt_send(VIRT_KEYS_START+31); break;
      case KC_BSPC: virt_send(VIRT_KEYS_START+32); break;
      case KC_ENT: virt_send(VIRT_KEYS_START+33); break;
      default: virt_send(VIRT_WARN); break;
        // clang-format on
    }

    key_count++;
  }
  virt_send(event);
}

void emit_virt_layer(layer_state_t state) {
  virt_send(VIRT_LAYER_ZERO + get_highest_layer(state));
}

void emit_virt_setting_enum(uint8_t option, uint8_t value) {
  virt_send(VIRT_SETTINGS);
  virt_send(option);
  virt_send(value);
}

void virtser_recv(const uint8_t ch) {
  switch (ch) {
    case VIRT_HEARTBEAT:
      recv_timer = timer_read();
      break;
    case VIRT_SETTINGS:
      emit_virt_setting_enum(VIRT_SETTING_DUP_FORCE, SETTING_DUP_FORCE);
      emit_virt_setting_enum(VIRT_SETTING_VIRT_SERIAL, SETTING_VIRT_SERIAL);
      emit_virt_setting_enum(VIRT_SETTING_CHORD_MODE, SETTING_CHORD_MODE);
      break;
  }
}

// setting_dup_force SETTING_DUP_FORCE = 0;
// setting_virt_serial SETTING_VIRT_SERIAL = 0;
// setting_chord_mode SETTING_CHORD_MODE = CHORD_MODE_CORRECTIVE;

// #ifdef VIRT_SIDECHANNEL
// #include "virt_sidechannel.c"
// #else
// #define emit_virt_key(...) ;
// #define emit_virt_combo(...) ;
// #define emit_virt_layer(...) ;
// #define virt_send(...) ;
// #endif

// uint8_t last_message_length = 0;
/* #define SEND_MESSAGE(msg) { \
//   last_message_length += strlen(msg); \
//   SEND_STRING(msg); \
// }
*/

// void clear_last_message(void) {
//   if (last_message_length == 0) {
//     return;
//   }

//   do {
//     tap_code16(KC_BSPC);
//   } while (--last_message_length);
// }

// #define GET_TAP_KC(dual_role_key) (dual_role_key & 0xFF)
// uint16_t last_keycode = KC_NO;
// uint8_t last_modifier = 0;
// uint8_t mod_state;
// uint8_t oneshot_mod_state;
// bool process_repeat_key(uint16_t keycode, keyrecord_t *record) {
//   if ((keycode == AT0 || keycode == ST0 || keycode == NT0) && record->tap.count) {
//     if (record->event.pressed) {
//       if (last_chord) {
//         last_chord_cycle = process_chord_dup(last_chord, last_chord_cycle);
// #ifdef VIRT_SIDECHANNEL
//         emit_virt_key(record, record->event.pressed, false, true);
// #endif
//         return false;
//       }
//       register_mods(last_modifier);
//       register_code16(last_keycode);
//     } else {
//       if (last_chord) {
//         return false;
//       }
//       unregister_code16(last_keycode);
//       unregister_mods(last_modifier);
//     }
//     return false;
//   } else {
//     switch (keycode) {
//       case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
//       case QK_MOMENTARY ... QK_MOMENTARY_MAX:
//       case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
//       case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
//       case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
//       case QK_TO ... QK_TO_MAX:
//       case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
//         break;
//       default: {
//         uint16_t next_keycode = KC_NO;
//         uint8_t next_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;

//         switch (keycode) {
//           case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
//           case QK_MOD_TAP ... QK_MOD_TAP_MAX:
//             if (record->event.pressed) {
//               next_keycode = GET_TAP_KC(keycode);
//             }
//             break;
//           default:
//             if (record->event.pressed) {
//               next_keycode = keycode;
//             }
//             break;
//         }

//         if (SETTING_DUP_FORCE == DUP_FORCE_ON) {
//           if (next_keycode >= KC_A && next_keycode <= KC_Z) {
//             if (last_keycode == next_keycode && last_modifier == next_modifier) {
// #ifdef VIRT_SIDECHANNEL
//               virt_send(VIRT_SUPPRESSED_KEY);
// #endif
//               return false;
//             }
//           }
//         }

//         uint8_t current_mod_state = get_mods();
//         uint8_t current_oneshot_mod_state = get_oneshot_mods();
//         uint8_t current_modifier = current_oneshot_mod_state > current_mod_state ? current_oneshot_mod_state : current_mod_state;

//         if (SETTING_CHORD_MODE == CHORD_MODE_EXCLUSIVE) {
//           if ((current_modifier & MOD_MASK_CAG) == 0 && next_keycode >= KC_A && next_keycode <= KC_Z) {
// #ifdef VIRT_SIDECHANNEL
//             virt_send(VIRT_SUPPRESSED_KEY);
// #endif
//             return false;
//           }
//         }

//         if (SETTING_CHORD_MODE == CHORD_MODE_CORRECTIVE) {
//           if (!process_chord_correction(next_keycode, current_modifier)) {
//             return false;
//           }
//         }

//         last_modifier = next_modifier;

//         if (next_keycode != KC_NO) {
//           last_keycode = next_keycode;
//         }

//         break;
//       }
//     }
//   }

//   mod_state = get_mods();
//   oneshot_mod_state = get_oneshot_mods();
//   return true;
// }

// bool process_setting_keys(uint16_t keycode, keyrecord_t *record) {
//   if (!record->event.pressed) {
//     return true;
//   }

//   switch (keycode) {
//     case KC_DUP_FORCE:
//       if (++SETTING_DUP_FORCE == _DUP_FORCE_LENGTH) {
//         SETTING_DUP_FORCE = 0;
//       }
// #ifdef VIRT_SIDECHANNEL
//       emit_virt_setting_enum(VIRT_SETTING_DUP_FORCE, SETTING_DUP_FORCE);
// #endif
//       return false;

//     case KC_VIRT_SERIAL: {
// #ifdef VIRT_SIDECHANNEL
//       // We want to make sure the last event before disabling gets sent
//       setting_virt_serial next = SETTING_VIRT_SERIAL;
//       if (++next == _VIRT_SERUAL_LENGTH) {
//         next = 0;
//       }

//       if (next == VIRT_SERIAL_DISABLED) {
//         emit_virt_setting_enum(VIRT_SETTING_VIRT_SERIAL, next);
//       }

//       SETTING_VIRT_SERIAL = next;

//       if (SETTING_VIRT_SERIAL == VIRT_SERIAL_ENABLED) {
//         emit_virt_setting_enum(VIRT_SETTING_VIRT_SERIAL, SETTING_VIRT_SERIAL);
//       }
// #endif

//       return false;
//     }

//     case KC_CHORD_MODE:
//       if (++SETTING_CHORD_MODE == _CHORD_MODE_LENGTH) {
//         SETTING_CHORD_MODE = 0;
//       }
// #ifdef VIRT_SIDECHANNEL
//       emit_virt_setting_enum(VIRT_SETTING_CHORD_MODE, SETTING_CHORD_MODE);
// #endif
//       return false;

//     case KC_SHOW_SETTINGS:
//       SEND_MESSAGE("[");

//       switch (SETTING_DUP_FORCE) {
//         case DUP_FORCE_OFF:
//           SEND_MESSAGE("d-");
//           break;
//         case DUP_FORCE_ON:
//           SEND_MESSAGE("D+");
//           break;
//         case _DUP_FORCE_LENGTH:
//           __builtin_unreachable();
//       }

//       SEND_MESSAGE(",");

//       switch (SETTING_VIRT_SERIAL) {
//         case VIRT_SERIAL_ENABLED:
//           SEND_MESSAGE("v+");
//           break;
//         case VIRT_SERIAL_DISABLED:
//           SEND_MESSAGE("V-");
//           break;
//         case _VIRT_SERUAL_LENGTH:
//           __builtin_unreachable();
//       }

//       SEND_MESSAGE(",");

//       switch (SETTING_CHORD_MODE) {
//         case CHORD_MODE_NORMAL:
//           SEND_MESSAGE("c");
//           break;
//         case CHORD_MODE_CORRECTIVE:
//           SEND_MESSAGE("CC");
//           break;
//         case CHORD_MODE_EXCLUSIVE:
//           SEND_MESSAGE("CX");
//           break;
//         case CHORD_MODE_OFF:
//           SEND_MESSAGE("C0");
//           break;
//         case _CHORD_MODE_LENGTH:
//           __builtin_unreachable();
//       }

//       SEND_MESSAGE("]");
//       return false;
//   }

//   return true;
// }

// bool process_postcomplete_action(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed && record->tap.count && (keycode == AT3 || keycode == ST3 || keycode == NT3)) {
//     if (last_correction != NULL) {
//       SEND_MESSAGE("[");
//       SEND_MESSAGE(last_correction);
//       SEND_MESSAGE("]");
//       reset_correction(true);
//       return false;
//     }
//   }

//   return true;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (!process_postcomplete_action(keycode, record)) {
//     return false;
//   }

//   if (!process_repeat_key(keycode, record)) {
//     return false;
//   }

//   bool prev_sentence_mode = sentence_mode;

//   if (record->event.pressed) {
//     last_chord = 0;
//     last_chord_length = 0;
//     sentence_mode = false;
//     last_correction = NULL;
//   }

//   if (!process_taphold(keycode, record, prev_sentence_mode)) {
//     return false;
//   }

//   if (!process_setting_keys(keycode, record)) {
//     return false;
//   }

//   return true;
// }

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case AT0:
//     case AT1:
//     case AT2:
//     case AT3:
//       return true;
//     default:
//       return false;
//     }
// }

// bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     clear_last_message();
//   }

// #ifdef VIRT_SIDECHANNEL
//   emit_virt_key(record, true, false, false);
// #endif

//   return true;
// }

// #ifdef VIRT_SIDECHANNEL
// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   emit_virt_key(record, record->event.pressed, false, true);
// }
// #endif

// #ifdef VIRT_SIDECHANNEL
// layer_state_t layer_state_set_user(layer_state_t state) {
//   emit_virt_layer(state);
//   return state;
// }
// #endif
