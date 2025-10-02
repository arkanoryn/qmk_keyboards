#include QMK_KEYBOARD_H

#include "ark_v1.h"
#include "layers.h"
#include "helpers/helpers.h"
#include "combos/combos.h"
#include "getreuer/getreuer.h"
#include "magic/magic.h"
#include "shortcuts/shortcuts.h"
#include "symbols/symbols.h"
#include "teacher/chord_teacher.h"
#include "config/config.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_GRAPHITE] = LAYOUT(
        #ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
        #endif // FARKANN_NUMBER_ROW
        ___GRAPHITE_ROW_1___,
        ___GRAPHITE_ROW_2___,
        ___GRAPHITE_ROW_3___,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
  // [_ACTIONS] = LAY_WRAPPER(
  //   __________ACTIONS_LEFT_ROW_1________, /* || */ _________ACTIONS_RIGHT_ROW_1________,
  //   __________ACTIONS_LEFT_ROW_2________, /* || */ _________ACTIONS_RIGHT_ROW_2________,
  //   __________ACTIONS_LEFT_ROW_3________, /* || */ _________ACTIONS_RIGHT_ROW_3________,
  //       KC_NO,   KC_NO,                                                           KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO
  //  ),
  // [_SYMBOLS] = LAY_WRAPPER(
  //   __________SYMBOLS_LEFT_ROW_1________, /* || */ _________SYMBOLS_RIGHT_ROW_1________,
  //   __________SYMBOLS_LEFT_ROW_2________, /* || */ _________SYMBOLS_RIGHT_ROW_2________,
  //   __________SYMBOLS_LEFT_ROW_3________, /* || */ _________SYMBOLS_RIGHT_ROW_3________,
  //       KC_NO,   KC_NO,                                                           KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO
  // ),
  // [_ACCENTS] = LAY_WRAPPER(
  //   __________ACCENTS_LEFT_ROW_1________, /* || */ _________ACCENTS_RIGHT_ROW_1________,
  //   __________ACCENTS_LEFT_ROW_2________, /* || */ _________ACCENTS_RIGHT_ROW_2________,
  //   __________ACCENTS_LEFT_ROW_3________, /* || */ _________ACCENTS_RIGHT_ROW_3________,
  //       KC_NO,   KC_NO,                                                           KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO
  // ),
  // [_NUMPAD_SOUND] = LAY_WRAPPER(
  //   ___________NUMPAD_ROW_1_____________, /* || */ ____________SOUND_ROW_1_____________,
  //   ___________NUMPAD_ROW_2_____________, /* || */ ____________SOUND_ROW_2_____________,
  //   ___________NUMPAD_ROW_3_____________, /* || */ ____________SOUND_ROW_3_____________,
  //       KC_NO,   KC_NO,                                                           KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO,
  //       KC_NO, KC_NO, KC_NO,               /**/ KC_NO, KC_NO
  // ),
  /* [_CONFIG] = LAY_WRAPPER( */
  /*   __________CONFIG_LEFT_ROW_1_________,  _________CONFIG_RIGHT_ROW_1________, */
  /*   __________CONFIG_LEFT_ROW_2_________,  _________CONFIG_RIGHT_ROW_2________, */
  /*   __________CONFIG_LEFT_ROW_3_________,  _________CONFIG_RIGHT_ROW_3________, */
  /*       KC_NO,   KC_NO,                                                           KC_NO, */
  /*       KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, */
  /*       KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO */
  /* ), */
    [_QWERTY] = LAYOUT(
        #ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
        #endif // FARKANN_NUMBER_ROW
        ___QWERTY_ROW_1___,
        ___QWERTY_ROW_2___,
        ___QWERTY_ROW_3___,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_GAME] = LAYOUT(
        #ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
        #endif // FARKANN_NUMBER_ROW
        ___GAME_ROW_1___,
        ___GAME_ROW_2___,
        ___GAME_ROW_3___,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_COLEMAK] = LAYOUT(
        #ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
        #endif // FARKANN_NUMBER_ROW
        ___COLEMAK_ROW_1___,
        ___COLEMAK_ROW_2___,
        ___COLEMAK_ROW_3___,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_STURDY] = LAYOUT(
        #ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
        #endif // FARKANN_NUMBER_ROW
        ___STURDY_ROW_1___,
        ___STURDY_ROW_2___,
        ___STURDY_ROW_3___,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
}; // clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // clang-format off
  if (!process_sentence_case(keycode, record)) { return false; }
  if (!process_chord_teacher(keycode, record)) { return false; }
  if (!process_magic_key(keycode, record)) { return false; }
  if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }
  if (!process_shortcuts(keycode, record)) { return false; }
  if (!process_symbols(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SEL_WORD)) { return false; }
  if (!process_graphite_keys(keycode, record)) { return false; }
  if (!process_config(keycode, record)) { return false; } // clang-format on

  return true;
};

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  clear_last_message(record);
  return true;
}

void matrix_scan_user(void) {
  layer_lock_task();
  select_word_task();
  alt_tab_task();
  combo_event_task();
  chord_teacher_task();
  sentence_case_task();
};

// static painter_device_t display;

void keyboard_post_init_user(void) {
    init_alt_tab_state();
    init_cycling_combos_state();
    init_teacher_state();
    // // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
};

void housekeeping_task_user(void) {
    // static uint32_t last_draw = 0;
    // if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
    //     last_draw = timer_read32();
    //     // Draw 8px-wide rainbow filled rectangles down the left side of the display
    //     for (int i = 0; i < 239; i+=8) {
    //         qp_rect(display, 0, i, 7, i+7, i, 255, 255, true);
    //     }
    //     qp_flush(display);
    // }
};

void keyboard_pre_init_user(void) {};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L4_N:
        case L4_I:
        case SFT_SLSH:
        case SFT_Q:
            return TAPPING_TERM + 150;
        case CTL_L:
        case L3_R:
        case CTL_U:
        case L3_E:
            return TAPPING_TERM + 100;
        // case ALT_D:
        // case L2_T:
        // case ALT_O:
        // case L2_A:
        //   return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
