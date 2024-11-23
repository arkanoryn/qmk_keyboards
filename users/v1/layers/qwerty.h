/*
** This file contains the different keycode definition dedicated to QWERTY.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
*/
#pragma once

#include QMK_KEYBOARD_H
#include "layers.h" // each keyboard should have this file with the available layers enum

#define __X__ KC_NO
#define _____ KC_TRNS
#define MEH_SPC MEH_T(KC_SPC)

// clang-format off
#define CTL_W       LCTL_T(KC_W)
#define ALT_E       LALT_T(KC_E)
#define GUI_R       LGUI_T(KC_R)
#define GUI_U       RGUI_T(KC_U)
#define ALT_I       RALT_T(KC_I)
#define CTL_O       RCTL_T(KC_O)
#define L4_A        LT(_NUMPAD_SOUND, KC_A)
#define L3_S        LT(_ACCENTS, KC_S)
#define L2_D        LT(_SYMBOLS, KC_D)
#define L1_F        LT(_ACTIONS, KC_F)
#define L1_J        LT(_ACTIONS, KC_J)
#define L2_K        LT(_SYMBOLS, KC_K)
#define L3_L        LT(_ACCENTS, KC_L)
#define L4_SCLN        LT(_NUMPAD_SOUND, KC_SCLN)
// clang-format off

// TODO: add a link to the QWERTY layer image

#define __________QWERTY_LEFT_NUMBERS_______ KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6
#define __________QWERTY_LEFT_ROW_1_________ KC_Q,		CTL_W,		ALT_E,		GUI_R,		KC_T
#define __________QWERTY_LEFT_ROW_2_________ L4_A,		L3_S,		L2_D,		L1_F,		KC_G
#define __________QWERTY_LEFT_ROW_3_________ KC_Z,		KC_X,		KC_C,		KC_V,		KC_B
#define _____QWERTY_LEFT_THUMBS______ MEH_SPC,	 KC_LALT

#define _________QWERTY_RIGHT_NUMBERS_______ KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL
#define _________QWERTY_RIGHT_ROW_1_________ KC_Y,		GUI_U,		ALT_I,		CTL_O,		KC_P
#define _________QWERTY_RIGHT_ROW_2_________ KC_H,		L1_J,		L2_K,		L3_L,		L4_SCLN
#define _________QWERTY_RIGHT_ROW_3_________ KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH
#define _________QWERTY_RIGHT_THUMBS________ KC_BSPC,	KC_ENT

#define ____DEFAULT_QWERTY_LEFT_NUMBERS_____ KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6
#define ____DEFAULT_QWERTY_LEFT_ROW_1_______ KC_Q,		KC_W,		KC_E,		KC_R,		KC_T
#define ____DEFAULT_QWERTY_LEFT_ROW_2_______ KC_A,		KC_S,		KC_D,		KC_F,		KC_G
#define _____DEFAULT_QWERTY_LEFT_ROW_3______ KC_Z,		KC_X,		KC_C,		KC_V,		KC_B
#define __DEFAULT_QWERTY_LEFT_THUMBS_ KC_SPC,	 KC_LALT

#define ____DEFAULT_QWERTY_RIGHT_NUMBERS____ KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL
#define ____DEFAULT_QWERTY_RIGHT_ROW_1______ KC_Y,		KC_U,		KC_I,		KC_O,		KC_P
#define ____DEFAULT_QWERTY_RIGHT_ROW_2______ KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN
#define ____DEFAULT_QWERTY_RIGHT_ROW_3______ KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH
#define ____DEFAULT_QWERTY_RIGHT_THUMBS_____ KC_SPC,	KC_RCTL

// QWERTY_ keys
#define QWERTY_A L4_A
#define QWERTY_B KC_B
#define QWERTY_C KC_C
#define QWERTY_D L2_D
#define QWERTY_E ALT_E
#define QWERTY_F L1_F
#define QWERTY_G KC_G
#define QWERTY_H KC_H
#define QWERTY_I ALT_I
#define QWERTY_J KC_J
#define QWERTY_K KC_K
#define QWERTY_L CTL_L
#define QWERTY_M KC_M
#define QWERTY_N L4_N
#define QWERTY_O ALT_O
#define QWERTY_P KC_P
#define QWERTY_Q SFT_Q
#define QWERTY_R L3_R
#define QWERTY_S L1_S
#define QWERTY_T L2_T
#define QWERTY_U CTL_U
#define QWERTY_V KC_V
#define QWERTY_W GUI_W
#define QWERTY_X KC_X
#define QWERTY_Y KC_Y
#define QWERTY_Z KC_Z
#define QWERTY_DOT DOT_EXLM
#define QWERTY_BSPC KC_BSPC
#define QWERTY_SPC MEH_SPC
#define QWERTY_ENT KC_ENT
#define QWERTY_SLSH SFT_SLSH
#define QWERTY_QUOT QUOT_UNDS
#define QWERTY_MAGIC MAGIC
#define QWERTY_COMM KC_COMM

