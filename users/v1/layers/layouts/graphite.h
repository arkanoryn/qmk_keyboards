/* Copyright 2025 Ark'Anoryn (@arkanoryn)
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

#pragma once

#include QMK_KEYBOARD_H
#include "layout.h" // each keyboard should have this file with the available layers enum

/* Side: Left, ROW: 1 */
#define GRAPHITE_1_01 KC_B
#define GRAPHITE_1_02 LCTL_T(KC_L)
#define GRAPHITE_1_03 LALT_T(KC_D)
#define GRAPHITE_1_04 LGUI_T(KC_W)
#define GRAPHITE_1_05 KC_Z
/* Side: Right, ROW: 1 */
#define GRAPHITE_1_06 QUOT_UNDS
#define GRAPHITE_1_07 RGUI_T(KC_F)
#define GRAPHITE_1_08 RALT_T(KC_O)
#define GRAPHITE_1_09 RCTL_T(KC_U)
#define GRAPHITE_1_10 KC_J
/* Side: Left, ROW: 2 */
#define GRAPHITE_2_01 LT(_NUMPAD_SOUND, KC_N)
#define GRAPHITE_2_02 LT(_ACCENTS, KC_R)
#define GRAPHITE_2_03 LT(_SYMBOLS, KC_T)
#define GRAPHITE_2_04 LT(_ACTIONS, KC_S)
#define GRAPHITE_2_05 KC_G
/* Side: Right, ROW: 2 */
#define GRAPHITE_2_06 KC_Y
#define GRAPHITE_2_07 LT(_ACTIONS, KC_H)
#define GRAPHITE_2_08 LT(_SYMBOLS, KC_A)
#define GRAPHITE_2_09 LT(_ACCENTS, KC_E)
#define GRAPHITE_2_10 LT(_NUMPAD_SOUND, KC_I)
/* Side: Left, ROW: 3 */
#define GRAPHITE_3_01 LSFT_T(KC_Q)
#define GRAPHITE_3_02 KC_X
#define GRAPHITE_3_03 KC_M
#define GRAPHITE_3_04 KC_C
#define GRAPHITE_3_05 KC_V
/* Side: Right, ROW: 3 */
#define GRAPHITE_3_06 KC_K
#define GRAPHITE_3_07 KC_P
#define GRAPHITE_3_08 DOT_EXLM
#define GRAPHITE_3_09 KC_COMM
#define GRAPHITE_3_10 RSFT_T(KC_SLSH)

#define ___GRAPHITE_CORE_ROW_1___ GRAPHITE_1_01, GRAPHITE_1_02, GRAPHITE_1_03, GRAPHITE_1_04, GRAPHITE_1_05, GRAPHITE_1_06, GRAPHITE_1_07, GRAPHITE_1_08, GRAPHITE_1_09, GRAPHITE_1_10
#define ___GRAPHITE_CORE_ROW_2___ GRAPHITE_2_01, GRAPHITE_2_02, GRAPHITE_2_03, GRAPHITE_2_04, GRAPHITE_2_05, GRAPHITE_2_06, GRAPHITE_2_07, GRAPHITE_2_08, GRAPHITE_2_09, GRAPHITE_2_10
#define ___GRAPHITE_CORE_ROW_3___ GRAPHITE_3_01, GRAPHITE_3_02, GRAPHITE_3_03, GRAPHITE_3_04, GRAPHITE_3_05, GRAPHITE_3_06, GRAPHITE_3_07, GRAPHITE_3_08, GRAPHITE_3_09, GRAPHITE_3_10

#ifdef FARKANN_EXTRA_COLS
#   define ___GRAPHITE_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___GRAPHITE_CORE_ROW_1___)
#   define ___GRAPHITE_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___GRAPHITE_CORE_ROW_2___)
#   define ___GRAPHITE_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___GRAPHITE_CORE_ROW_3___)
#else
#   define ___GRAPHITE_ROW_1___ ___GRAPHITE_CORE_ROW_1___
#   define ___GRAPHITE_ROW_2___ ___GRAPHITE_CORE_ROW_2___
#   define ___GRAPHITE_ROW_3___ ___GRAPHITE_CORE_ROW_3___
#endif

// clang-format off
#define CTL_L       LCTL_T(KC_L)
#define ALT_D       LALT_T(KC_D)
#define GUI_W       LGUI_T(KC_W)
#define GUI_F       RGUI_T(KC_F)
#define ALT_O       RALT_T(KC_O)
#define CTL_U       RCTL_T(KC_U)

#define L4_N        LT(_NUMPAD_SOUND, KC_N)
#define L3_R        LT(_ACCENTS, KC_R)
#define L2_T        LT(_SYMBOLS, KC_T)
#define L1_S        LT(_ACTIONS, KC_S)
#define L1_H        LT(_ACTIONS, KC_H)
#define L2_A        LT(_SYMBOLS, KC_A)
#define L3_E        LT(_ACCENTS, KC_E)
#define L4_I        LT(_NUMPAD_SOUND, KC_I)

#define SFT_Q       LSFT_T(KC_Q)
#define SFT_SLSH    RSFT_T(KC_SLSH)

#define SFT_MAGIC   LSFT_T(MAGIC)
#define MEH_SPC     MEH_T(KC_SPC)
#define GUI_GESC    LGUI_T(QK_GESC)
#define CTL_STAB    LCTL_T(S(KC_TAB))
#define ALT_TAB     LALT_T(KC_TAB)

#define GUI_DEL    RGUI_T(KC_DEL)
#define SFT_BSPC   RSFT_T(KC_BSPC)
#define CTL_ARCANE QK_BOOT // RCTL_T(ARCANE)
#define ALT_ENT    RALT_T(KC_ENT)
// clang-format on

// Need these for the combos
// GRAPHITE_ keys
#define GRAPHITE_A L2_A
#define GRAPHITE_B KC_B
#define GRAPHITE_C KC_C
#define GRAPHITE_D ALT_D
#define GRAPHITE_E L3_E
#define GRAPHITE_F GUI_F
#define GRAPHITE_G KC_G
#define GRAPHITE_H L1_H
#define GRAPHITE_I L4_I
#define GRAPHITE_J KC_J
#define GRAPHITE_K KC_K
#define GRAPHITE_L CTL_L
#define GRAPHITE_M KC_M
#define GRAPHITE_N L4_N
#define GRAPHITE_O ALT_O
#define GRAPHITE_P KC_P
#define GRAPHITE_Q SFT_Q
#define GRAPHITE_R L3_R
#define GRAPHITE_S L1_S
#define GRAPHITE_T L2_T
#define GRAPHITE_U CTL_U
#define GRAPHITE_V KC_V
#define GRAPHITE_W GUI_W
#define GRAPHITE_X KC_X
#define GRAPHITE_Y KC_Y
#define GRAPHITE_Z KC_Z
#define GRAPHITE_DOT DOT_EXLM
#define GRAPHITE_BSPC SFT_BSPC
#define GRAPHITE_SPC MEH_SPC
#define GRAPHITE_ENT ALT_ENT
#define GRAPHITE_SLSH SFT_SLSH
#define GRAPHITE_QUOT QUOT_UNDS
#define GRAPHITE_MAGIC SFT_MAGIC
#define GRAPHITE_ARCANE CTL_ARCANE
#define GRAPHITE_GESC GUI_GESC
#define GRAPHITE_COMM KC_COMM
