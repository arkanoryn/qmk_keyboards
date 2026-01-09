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
#define __TMP_EMPTY KC_0, KC_0,KC_0,KC_0,KC_0,KC_0,KC_0,KC_0,KC_0, KC_0

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
    [_QWERTY] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_GAME] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_COLEMAK] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_STURDY] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_ACTIONS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_SYMBOLS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_ACCENTS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_NUMPAD_SOUND] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_CONFIG] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
    [_FN] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        #endif // FARKANN_NUMBER_ROW
        __TMP_EMPTY,
        __TMP_EMPTY,
        __TMP_EMPTY,
        __EXTRA_ROW__,
        __THUMBS__________
    ),
};
