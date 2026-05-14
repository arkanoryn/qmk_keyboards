/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
*/
#pragma once

#include QMK_KEYBOARD_H
#include "layout.h" // each keyboard should have this file with the available layers enum

/* Side: Left, ROW: 1 */
#define STURDY_1_01 KC_V
#define STURDY_1_02 LCTL_T(KC_M)
#define STURDY_1_03 LALT_T(KC_L)
#define STURDY_1_04 LGUI_T(KC_C)
#define STURDY_1_05 KC_P
/* Side: Right, ROW: 1 */
#define STURDY_1_06 KC_X
#define STURDY_1_07 RGUI_T(KC_F)
#define STURDY_1_08 RALT_T(KC_O)
#define STURDY_1_09 RCTL_T(KC_U)
#define STURDY_1_10 KC_J
/* Side: Left, ROW: 2 */
#define STURDY_2_01 LT(_NUMPAD_SOUND, KC_S)
#define STURDY_2_02 LT(_ACCENTS, KC_T)
#define STURDY_2_03 LT(_SYMBOLS, KC_R)
#define STURDY_2_04 LT(_ACTIONS, KC_D)
#define STURDY_2_05 KC_Y
/* Side: Right, ROW: 2 */
#define STURDY_2_06 KC_DOT
#define STURDY_2_07 LT(_ACTIONS, KC_N)
#define STURDY_2_08 LT(_SYMBOLS, KC_A)
#define STURDY_2_09 LT(_ACCENTS, KC_E)
#define STURDY_2_10 LT(_NUMPAD_SOUND, KC_I)
/* Side: Left, ROW: 3 */
#define STURDY_3_01 LSFT_T(KC_K)
#define STURDY_3_02 KC_Q
#define STURDY_3_03 KC_G
#define STURDY_3_04 KC_W
#define STURDY_3_05 KC_Z
/* Side: Right, ROW: 3 */
#define STURDY_3_06 KC_B
#define STURDY_3_07 KC_H
#define STURDY_3_08 KC_QUOT
#define STURDY_3_09 KC_SCLN
#define STURDY_3_10 RSFT_T(KC_COMM)

#define ___STURDY_CORE_ROW_1___ STURDY_1_01, STURDY_1_02, STURDY_1_03, STURDY_1_04, STURDY_1_05, STURDY_1_06, STURDY_1_07, STURDY_1_08, STURDY_1_09, STURDY_1_10
#define ___STURDY_CORE_ROW_2___ STURDY_2_01, STURDY_2_02, STURDY_2_03, STURDY_2_04, STURDY_2_05, STURDY_2_06, STURDY_2_07, STURDY_2_08, STURDY_2_09, STURDY_2_10
#define ___STURDY_CORE_ROW_3___ STURDY_3_01, STURDY_3_02, STURDY_3_03, STURDY_3_04, STURDY_3_05, STURDY_3_06, STURDY_3_07, STURDY_3_08, STURDY_3_09, STURDY_3_10

#ifdef FARKANN_EXTRA_COLS
#   define ___STURDY_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___STURDY_CORE_ROW_1___)
#   define ___STURDY_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___STURDY_CORE_ROW_2___)
#   define ___STURDY_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___STURDY_CORE_ROW_3___)
#else
#   define ___STURDY_ROW_1___ ___STURDY_CORE_ROW_1___
#   define ___STURDY_ROW_2___ ___STURDY_CORE_ROW_2___
#   define ___STURDY_ROW_3___ ___STURDY_CORE_ROW_3___
#endif

#define STURDY_A STURDY_2_08
#define STURDY_B STURDY_3_06
#define STURDY_C STURDY_1_04
#define STURDY_D STURDY_2_04
#define STURDY_E STURDY_2_09
#define STURDY_F STURDY_1_07
#define STURDY_G STURDY_3_03
#define STURDY_H STURDY_3_07
#define STURDY_I STURDY_2_10
#define STURDY_J STURDY_1_10
#define STURDY_K STURDY_3_01
#define STURDY_L STURDY_1_03
#define STURDY_M STURDY_1_02
#define STURDY_N STURDY_2_07
#define STURDY_O STURDY_1_08
#define STURDY_P STURDY_1_05
#define STURDY_Q STURDY_3_02
#define STURDY_R STURDY_2_03
#define STURDY_S STURDY_2_01
#define STURDY_T STURDY_2_02
#define STURDY_U STURDY_1_09
#define STURDY_V STURDY_1_01
#define STURDY_W STURDY_3_04
#define STURDY_X STURDY_1_06
#define STURDY_Y STURDY_2_05
#define STURDY_Z STURDY_3_05
#define STURDY_COMM STURDY_3_10
#define STURDY_DOT STURDY_2_06
#define STURDY_QUOT STURDY_3_08
#define STURDY_SCLN STURDY_3_09
#define STURDY_BSPC SFT_BSPC
#define STURDY_SPC MEH_SPC
#define STURDY_ENT ALT_ENT
#define STURDY_MAGIC SFT_MAGIC
#define STURDY_ARCANE CTL_ARCANE
#define STURDY_GESC GUI_GESC
