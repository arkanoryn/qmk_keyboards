/* Copyright 2025-2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "farkann_v2.h"

#define __EXTRA_ROW__ KC_A, KC_B, KC_C
#define __TMP_EMPTY KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0, KC_0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_GRAPHITE] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___GRAPHITE_ROW_1___, ___GRAPHITE_ROW_2___, ___GRAPHITE_ROW_3___, __EXTRA_ROW__, __THUMBS__________),
    [_QWERTY] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___QWERTY_ROW_1___, ___QWERTY_ROW_2___, ___QWERTY_ROW_3___, __EXTRA_ROW__, __THUMBS__________),
    [_GAME] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___GAME_ROW_1___, ___GAME_ROW_2___, ___GAME_ROW_3___, __EXTRA_ROW__, __THUMBS__________),
    [_COLEMAK] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___COLEMAK_ROW_1___, ___COLEMAK_ROW_2___, ___COLEMAK_ROW_3___, __EXTRA_ROW__, __THUMBS__________),
    [_STURDY] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___STURDY_ROW_1___, ___STURDY_ROW_2___, ___STURDY_ROW_3___, __EXTRA_ROW__, __THUMBS__________),
    [_ACTIONS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __NUMBERS_ROW_____,
#endif // FARKANN_NUMBER_ROW
        ___ACTIONS_ROW_1___, ___ACTIONS_ROW_2___, ___ACTIONS_ROW_3___, __EXTRA_ROW__, __THUMBS__________),
    [_SYMBOLS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        ___SYMBOLS_ROW_1___,
#endif // FARKANN_NUMBER_ROW
        ___SYMBOLS_ROW_1___, ___SYMBOLS_ROW_2___, ___SYMBOLS_ROW_3___, __EXTRA_ROW__, ___SYMBOLS_THUMBS__________),
    [_ACCENTS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
#endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY, __TMP_EMPTY, __TMP_EMPTY, __EXTRA_ROW__, __THUMBS__________),
    [_NUMPAD_SOUND] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        ___NUMPAD_SOUND_ROW_1___,
#endif // FARKANN_NUMBER_ROW
        ___NUMPAD_SOUND_ROW_1___, ___NUMPAD_SOUND_ROW_2___, ___NUMPAD_SOUND_ROW_3___, __EXTRA_ROW__, ___NUMPAD_SOUND_THUMBS__________),
    [_CONFIG] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        ___CONFIG_ROW_1___,
#endif // FARKANN_NUMBER_ROW
        ___CONFIG_ROW_1___, ___CONFIG_ROW_2___, ___CONFIG_ROW_3___, __EXTRA_ROW__, ___CONFIG_THUMBS__________),
    [_FN] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        ___FN_ROW_1___,
#endif // FARKANN_NUMBER_ROW
        ___FN_ROW_1___, ___FN_ROW_2___, ___FN_ROW_3___, __EXTRA_ROW__, ___FN_THUMBS__________),
};

// Add matrix_scan_user function for combo event task
void matrix_scan_user(void) {
  // combo_event_task();
}

// Add keyboard_post_init_user function for initialization
void keyboard_post_init_user(void) {
// #ifdef CYCLE_COMBO_ENABLE
//   init_cycling_combos_state();
// #endif
#ifdef CHORD_TEACHER_ENABLE
  init_teacher_state();
#endif
}

// Combo should trigger callback - implementation is in features/combos/combos.c
// bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
// //   // Always allow config layer combo (needed to toggle chords back on)
// //   // As we would no longer be able to access the Config Layer without it
// //   if (combo_index == GRAPHITE_CONFIG_LAYER) return true;
// //
// // #ifdef CHORD_TEACHER_ENABLE
// //   if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) return false;
// // #endif // CHORD_TEACHER_ENABLE
// \n// //   return true;
// }
