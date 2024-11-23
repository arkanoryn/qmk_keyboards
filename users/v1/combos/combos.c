#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "helpers/helpers.h"
#include "combos.h"
#include "magic/magic.h"
#include "magic/cycling_combos.h"
#include "teacher/chord_teacher.h"

#ifndef COMBO_TIMEOUT
#  define COMBO_TIMEOUT 9000 // miliseconds
#endif                       // COMBO_TIMEOUT

static uint16_t idle_timer     = 0;
const char     *root_combo_str = NULL;

void set_combo_event_timer(void) {
  idle_timer = timer_read() + SELECT_WORD_TIMEOUT;
}

void process_del_word(void) {
  disable_shift();

#ifdef CHORD_TEACHER_ENABLE
  if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_CORRECTIVE) {
    reset_teacher_state(true);
  }
#endif // CHORD_TEACHER_ENABLE
#ifdef CYCLE_COMBO_ENABLE
  if (get_cycling_combo_state()->is_combo_active) {
    if (get_cycling_combo_state()->is_cyclable) {
      backspace_current_output();
    } else {
      const size_t str_len = strlen(root_combo_str);

      for (int i = 0; i < str_len; ++i) {
        tap_code16(KC_BSPC);
      }
    }
  } else {
#endif // CYCLE_COMBO_ENABLE
    send_string(detected_host_os() == OS_MACOS ? MAC_WORD_BACKSPACE : WIN_WORD_BACKSPACE);
#ifdef CYCLE_COMBO_ENABLE
  }
#endif // CYCLE_COMBO_ENABLE
  return;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    const uint8_t mods    = all_mods();
    const bool    shifted = is_shifted();

    switch (combo_index) {
      // TODO: should have a custom key-code and be managed as a custom action or shortcut
      case GRAPHITE_DEL_WORD:
        process_del_word();
        break;
      case GRAPHITE_SFT_ENT:
        add_mods(MOD_MASK_SHIFT);
        tap_code16(KC_ENT);
        set_mods(mods);
        break;
      case GRAPHITE_C_ENT:
        (detected_host_os() == OS_MACOS ? add_mods(MOD_MASK_GUI) : add_mods(MOD_MASK_CTRL));
        tap_code16(KC_ENT);
        set_mods(mods);
        break;
      case GRAPHITE_CONFIG_LAYER:
        layer_on(_CONFIG);
        break;
      default:
        root_combo_str = get_combos_cmds(combo_index);
        set_combo_event_timer();

#ifdef CHORD_TEACHER_ENABLE
        reset_teacher_state(true);
#endif // CHORD_TEACHER_ENABLE

#ifdef CYCLE_COMBO_ENABLE
        process_magic_combo_event(combo_index);
#endif // CYCLE_COMBO_ENABLE

        if (shifted) {
          del_mods(MOD_MASK_SHIFT);
          set_oneshot_mods(MOD_BIT(KC_LSFT)); // Shift mod to capitalize.
        }
        send_string(root_combo_str);
        if (shifted) {
          set_mods(mods);
        }
    }
  }
};

void combo_event_task(void) {
#ifdef CYCLE_COMBO_ENABLE
  if (get_cycling_combo_state()->is_combo_active && timer_expired(timer_read(), idle_timer)) {
    init_cycling_combos_state();
  }
#endif // CYCLE_COMBO_ENABLE
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  // We need this otherwise there's no way to toggle chords back on
  // As we would no longer be able to access the Config Layer (access is via a combo)
  if (combo_index == GRAPHITE_CONFIG_LAYER) return true;

#ifdef CHORD_TEACHER_ENABLE
  if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) return false;
#endif // CHORD_TEACHER_ENABLE

  return true;
}
