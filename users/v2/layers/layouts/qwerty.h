/* Copyright 2025-2026 Ark'Anoryn (@arkanoryn)
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
#include "layers.h" // each keyboard should have this file with the available layers enum
// #include "tap_dance/tap_dance.h"

#include "layout.h" // each keyboard should have this file with the available layers enum
#include "farkann_thumbs.h"

#define QWERTY_A LT(_NUMPAD_SOUND, KC_A)
#define QWERTY_B KC_B
#define QWERTY_C KC_C
#define QWERTY_COMM KC_COMM
#define QWERTY_D LT(_SYMBOLS, KC_D)
#define QWERTY_DOT KC_DOT
#define QWERTY_E LALT_T(KC_E)
#define QWERTY_F LT(_ACTIONS, KC_F)
#define QWERTY_G KC_G
#define QWERTY_H KC_H
#define QWERTY_I RALT_T(KC_I)
#define QWERTY_J LT(_ACTIONS, KC_J)
#define QWERTY_K LT(_SYMBOLS, KC_K)
#define QWERTY_L LT(_ACCENTS, KC_L)
#define QWERTY_M KC_M
#define QWERTY_N KC_N
#define QWERTY_O RCTL_T(KC_O)
#define QWERTY_P KC_P
#define QWERTY_Q KC_Q
#define QWERTY_QUOTE KC_QUOT
#define QWERTY_R LGUI_T(KC_R)
#define QWERTY_S LT(_ACCENTS, KC_S)
#define QWERTY_SCLN LT(_NUMPAD_SOUND, KC_SCLN)
#define QWERTY_SLSH RSFT_T(KC_SLSH)
#define QWERTY_T KC_T
#define QWERTY_U RGUI_T(KC_U)
#define QWERTY_V KC_V
#define QWERTY_W LCTL_T(KC_W)
#define QWERTY_X KC_X
#define QWERTY_Y KC_Y
#define QWERTY_Z LSFT_T(KC_Z)

#define ___QWERTY_CORE_ROW_1___ QWERTY_Q, QWERTY_W, QWERTY_E, QWERTY_R, QWERTY_T, /* || */ QWERTY_Y, QWERTY_U, QWERTY_I, QWERTY_O, QWERTY_P
#define ___QWERTY_CORE_ROW_2___ QWERTY_A, QWERTY_S, QWERTY_D, QWERTY_F, QWERTY_G, /* || */ QWERTY_H, QWERTY_J, QWERTY_K, QWERTY_L, QWERTY_SCLN
#define ___QWERTY_CORE_ROW_3___ QWERTY_Z, QWERTY_X, QWERTY_C, QWERTY_V, QWERTY_B, /* || */ QWERTY_N, QWERTY_M, QWERTY_COMM, QWERTY_DOT, QWERTY_SLSH

#define ___GAME_CORE_ROW_1___ KC_Q, KC_W, KC_E, KC_R, KC_T, /* || */ KC_Y, KC_U, KC_I, KC_O, KC_P
#define ___GAME_CORE_ROW_2___ KC_A, KC_S, KC_D, KC_F, KC_G, /* || */ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define ___GAME_CORE_ROW_3___ KC_Z, KC_X, KC_C, KC_V, KC_B, /* || */ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#ifdef FARKANN_EXTRA_COLS
#  define ___QWERTY_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___QWERTY_CORE_ROW_1___)
#  define ___QWERTY_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___QWERTY_CORE_ROW_2___)
#  define ___QWERTY_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___QWERTY_CORE_ROW_3___)

#  define ___GAME_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___GAME_CORE_ROW_1___)
#  define ___GAME_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___GAME_CORE_ROW_2___)
#  define ___GAME_ROW_4___ ___ROW_3_WITH_EXTRA_COLS(___GAME_CORE_ROW_3___)
#else
#  define ___QWERTY_ROW_1___ ___QWERTY_CORE_ROW_1___
#  define ___QWERTY_ROW_2___ ___QWERTY_CORE_ROW_2___
#  define ___QWERTY_ROW_3___ ___QWERTY_CORE_ROW_3___

#  define ___GAME_ROW_1___ ___GAME_CORE_ROW_1___
#  define ___GAME_ROW_2___ ___GAME_CORE_ROW_2___
#  define ___GAME_ROW_3___ ___GAME_CORE_ROW_3___
#endif // FARKANN_EXTRA_COLS

// Need these for the combos
// QWERTY_ keys
#define QWERTY_BSPC SFT_BSPC
#define QWERTY_SPC MEH_SPC
#define QWERTY_ENT CTL_ENTR
#define QWERTY_MAGIC SFT_MAGIC
#define QWERTY_ARCANE ALT_ARCANE
#define QWERTY_GESC GUI_ESC
#define QWERTY_QUOT QWERTY_QUOTE
