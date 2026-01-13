/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
*/
#pragma once

#include QMK_KEYBOARD_H
#include "layout.h" // each keyboard should have this file with the available layers enum

/* Side: Left, ROW: 1 */
#define COLEMAK_1_01 KC_Q
#define COLEMAK_1_02 LCTL_T(KC_W)
#define COLEMAK_1_03 LALT_T(KC_F)
#define COLEMAK_1_04 LGUI_T(KC_P)
#define COLEMAK_1_05 KC_G
/* Side: Right, ROW: 1 */
#define COLEMAK_1_06 KC_J
#define COLEMAK_1_07 RGUI_T(KC_L)
#define COLEMAK_1_08 RALT_T(KC_U)
#define COLEMAK_1_09 RCTL_T(KC_Y)
#define COLEMAK_1_10 KC_SCLN
/* Side: Left, ROW: 2 */
#define COLEMAK_2_01 LT(_NUMPAD_SOUND, KC_A)
#define COLEMAK_2_02 LT(_ACCENTS, KC_R)
#define COLEMAK_2_03 LT(_SYMBOLS, KC_S)
#define COLEMAK_2_04 LT(_ACTIONS, KC_T)
#define COLEMAK_2_05 KC_D
/* Side: Right, ROW: 2 */
#define COLEMAK_2_06 KC_H
#define COLEMAK_2_07 LT(_ACTIONS, KC_N)
#define COLEMAK_2_08 LT(_SYMBOLS, KC_E)
#define COLEMAK_2_09 LT(_ACCENTS, KC_I)
#define COLEMAK_2_10 LT(_NUMPAD_SOUND, KC_O)
/* Side: Left, ROW: 3 */
#define COLEMAK_3_01 LSFT_T(KC_Z)
#define COLEMAK_3_02 KC_X
#define COLEMAK_3_03 KC_C
#define COLEMAK_3_04 KC_V
#define COLEMAK_3_05 KC_B
/* Side: Right, ROW: 3 */
#define COLEMAK_3_06 KC_K
#define COLEMAK_3_07 KC_M
#define COLEMAK_3_08 KC_COMM
#define COLEMAK_3_09 KC_DOT
#define COLEMAK_3_10 RSFT_T(KC_SLSH)

#define ___COLEMAK_CORE_ROW_1___ COLEMAK_1_01, COLEMAK_1_02, COLEMAK_1_03, COLEMAK_1_04, COLEMAK_1_05, COLEMAK_1_06, COLEMAK_1_07, COLEMAK_1_08, COLEMAK_1_09, COLEMAK_1_10
#define ___COLEMAK_CORE_ROW_2___ COLEMAK_2_01, COLEMAK_2_02, COLEMAK_2_03, COLEMAK_2_04, COLEMAK_2_05, COLEMAK_2_06, COLEMAK_2_07, COLEMAK_2_08, COLEMAK_2_09, COLEMAK_2_10
#define ___COLEMAK_CORE_ROW_3___ COLEMAK_3_01, COLEMAK_3_02, COLEMAK_3_03, COLEMAK_3_04, COLEMAK_3_05, COLEMAK_3_06, COLEMAK_3_07, COLEMAK_3_08, COLEMAK_3_09, COLEMAK_3_10

#ifdef FARKANN_EXTRA_COLS
#   define ___COLEMAK_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___COLEMAK_CORE_ROW_1___)
#   define ___COLEMAK_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___COLEMAK_CORE_ROW_2___)
#   define ___COLEMAK_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___COLEMAK_CORE_ROW_3___)
#else
#   define ___COLEMAK_ROW_1___ ___COLEMAK_CORE_ROW_1___
#   define ___COLEMAK_ROW_2___ ___COLEMAK_CORE_ROW_2___
#   define ___COLEMAK_ROW_3___ ___COLEMAK_CORE_ROW_3___
#endif

#define COLEMAK_A COLEMAK_2_01
#define COLEMAK_B COLEMAK_3_05
#define COLEMAK_C COLEMAK_3_03
#define COLEMAK_D COLEMAK_2_05
#define COLEMAK_E COLEMAK_2_08
#define COLEMAK_F COLEMAK_1_03
#define COLEMAK_G COLEMAK_1_05
#define COLEMAK_H COLEMAK_2_06
#define COLEMAK_I COLEMAK_2_09
#define COLEMAK_J COLEMAK_1_06
#define COLEMAK_K COLEMAK_3_06
#define COLEMAK_L COLEMAK_1_02
#define COLEMAK_M COLEMAK_3_07
#define COLEMAK_N COLEMAK_2_07
#define COLEMAK_O COLEMAK_2_10
#define COLEMAK_P COLEMAK_1_01
#define COLEMAK_Q COLEMAK_3_01
#define COLEMAK_R COLEMAK_2_02
#define COLEMAK_S COLEMAK_2_03
#define COLEMAK_T COLEMAK_2_04
#define COLEMAK_U COLEMAK_1_08
#define COLEMAK_V COLEMAK_3_04
#define COLEMAK_W COLEMAK_1_02
#define COLEMAK_X COLEMAK_3_02
#define COLEMAK_Y COLEMAK_1_09
#define COLEMAK_Z COLEMAK_3_01
#define COLEMAK_DOT COLEMAK_3_09
#define COLEMAK_BSPC SFT_BSPC
#define COLEMAK_SPC MEH_SPC
#define COLEMAK_ENT ALT_ENT
#define COLEMAK_SLSH COLEMAK_3_10
#define COLEMAK_QUOT COLEMAK_1_06
#define COLEMAK_MAGIC SFT_MAGIC
#define COLEMAK_ARCANE CTL_ARCANE
#define COLEMAK_GESC GUI_GESC
#define COLEMAK_COMM COLEMAK_3_08
