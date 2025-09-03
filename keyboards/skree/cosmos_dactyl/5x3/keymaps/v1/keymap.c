#include QMK_KEYBOARD_H
/* #include "oled_driver.h" */
/* #include "transactions.h" */
/**/
#include "ark_v1.h"
#include "layers.h"
/* #include "helpers/helpers.h" */
/* #include "combos/combos.h" */
/* #include "getreuer/getreuer.h" */
/* #include "magic/magic.h" */
/* #include "oled/oled.h" */
/* #include "shortcuts/shortcuts.h" */
/* #include "symbols/symbols.h" */
/* #include "teacher/chord_teacher.h" */
/* #include "config/config.h" */

#define LAY_WRAPPER(...) LAYOUT_5x3(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAY_WRAPPER(
        _________GRAPHITE_LEFT_ROW_1________, /* || */ ________GRAPHITE_RIGHT_ROW_1________,
        _________GRAPHITE_LEFT_ROW_2________, /* || */ ________GRAPHITE_RIGHT_ROW_2________,
        _________GRAPHITE_LEFT_ROW_3________, /* || */ ________GRAPHITE_RIGHT_ROW_3________,
        KC_A,   KC_B,                                                           KC_D,
        QK_BOOT,   KC_Y,   KC_Z,               /**/ QK_BOOT,   KC_D,
        KC_TAB, KC_SPC, KC_K,               /**/ KC_BSPC,KC_ENT
    )
}; // clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // clang-format off
  /* if (!process_sentence_case(keycode, record)) { return false; } */
  /* if (!process_chord_teacher(keycode, record)) { return false; } */
  /* if (!process_magic_key(keycode, record)) { return false; } */
  /* if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; } */
  /* if (!process_shortcuts(keycode, record)) { return false; } */
  /* if (!process_symbols(keycode, record)) { return false; } */
  /* if (!process_select_word(keycode, record, SEL_WORD)) { return false; } */
  /* if (!process_oled_displays(keycode, record)) { return false; } */
  /* if (!process_graphite_keys(keycode, record)) { return false; } */
  /* if (!process_config(keycode, record)) { return false; } // clang-format on */

  return true;
};

/* bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   clear_last_message(record); */
/*   return true; */
/* } */
/**/
/* void matrix_scan_user(void) { */
/*   layer_lock_task(); */
/*   select_word_task(); */
/*   alt_tab_task(); */
/*   combo_event_task(); */
/*   chord_teacher_task(); */
/*   sentence_case_task(); */
/* }; */
/**/
/* void keyboard_post_init_user(void) { */
/*   init_alt_tab_state(); */
/*   init_cycling_combos_state(); */
/*   init_teacher_state(); */
/*   init_oled_state(); */
/* }; */
/**/
/* void housekeeping_task_user(void) { */
/*   oled_housekeeping_task(); */
/* }; */
/**/
/* void keyboard_pre_init_user(void) { */
/*   // Set our LED pin as output */
/*   setPinOutput(24); */
/*   // Turn the LED off */
/*   // (Due to technical reasons, high is off and low is on) */
/*   writePinHigh(24); */
/* }; */
/**/
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case L4_N: */
/*     case L4_I: */
/*     case SFT_SLSH: */
/*     case SFT_Q: */
/*       return TAPPING_TERM + 150; */
/*     case CTL_L: */
/*     case L3_R: */
/*     case CTL_U: */
/*     case L3_E: */
/*       return TAPPING_TERM + 100; */
/*     // case ALT_D: */
/*     // case L2_T: */
/*     // case ALT_O: */
/*     // case L2_A: */
/*     //   return TAPPING_TERM + 100; */
/*     default: */
/*       return TAPPING_TERM; */
/*   } */
/* } */
/**/
