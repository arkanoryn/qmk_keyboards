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
#include "painter/display.h"

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
    [_ACTIONS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___ACTIONS_ROW_1___,
        ___ACTIONS_ROW_2___,
        ___ACTIONS_ROW_3___,
        __ACTIONS_EXTRA_ROW__,
        __ACTIONS_THUMBS__________
    ),
    [_SYMBOLS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
        #endif // FARKANN_NUMBER_ROW
        ___SYMBOLS_ROW_1___,
        ___SYMBOLS_ROW_2___,
        ___SYMBOLS_ROW_3___,
        __SYMBOLS_EXTRA_ROW__,
        __SYMBOLS_THUMBS__________
    ),
    [_ACCENTS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___ACCENTS_ROW_1___,
        ___ACCENTS_ROW_2___,
        ___ACCENTS_ROW_3___,
        __ACCENTS_EXTRA_ROW__,
        __ACCENTS_THUMBS__________
    ),
    [_NUMPAD_SOUND] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___NUMPAD_SOUND_ROW_1___,
        ___NUMPAD_SOUND_ROW_2___,
        ___NUMPAD_SOUND_ROW_3___,
        __NUMPAD_SOUND_EXTRA_ROW__,
        __NUMPAD_SOUND_THUMBS__________
    ),
    [_CONFIG] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___CONFIG_ROW_1___,
        ___CONFIG_ROW_2___,
        ___CONFIG_ROW_3___,
        __CONFIG_EXTRA_ROW__,
        __THUMBS__________
    ),
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
    init_displays();
};

void housekeeping_task_user(void) {
    draw();
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
