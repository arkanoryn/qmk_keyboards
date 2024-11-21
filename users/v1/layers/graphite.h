/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
*/
#pragma once

#include QMK_KEYBOARD_H
#include "ark_v1.h" // root_config
#include "layers.h" // each keyboard should have this file with the available layers enum

#define __X__ KC_NO
#define _____ KC_TRNS
#define MEH_SPC MEH_T(KC_SPC)

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
// clang-format off

// TODO: add a link to the graphite layer image

#define _________GRAPHITE_LEFT_ROW_1________ KC_B,		CTL_L,		ALT_D,		 GUI_W,		KC_Z
#define _________GRAPHITE_LEFT_ROW_2________ L4_N,		L3_R,		L2_T,		L1_S,		KC_G
#define _________GRAPHITE_LEFT_ROW_3________ SFT_Q,		KC_X,		KC_M,		KC_C,		KC_V
#define _________GRAPHITE_LEFT_THUMBS_______ MEH_SPC,	 MAGIC

#define ________GRAPHITE_RIGHT_ROW_1________ QUOT_UNDS,	GUI_F,		ALT_O,		CTL_U,		KC_J
#define ________GRAPHITE_RIGHT_ROW_2________ KC_Y,		L1_H,		L2_A,		L3_E,		L4_I
#define ________GRAPHITE_RIGHT_ROW_3________ KC_K,		KC_P,		DOT_EXLM,	KC_COMM,	SFT_SLSH
#define ________GRAPHITE_RIGHT_THUMBS_______ KC_BSPC,	KC_ENT

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
#define GRAPHITE_BSPC KC_BSPC
#define GRAPHITE_SPC MEH_SPC
#define GRAPHITE_ENT KC_ENT
#define GRAPHITE_SLSH SFT_SLSH
#define GRAPHITE_QUOT QUOT_UNDS
#define GRAPHITE_MAGIC MAGIC
#define GRAPHITE_COMM KC_COMM

