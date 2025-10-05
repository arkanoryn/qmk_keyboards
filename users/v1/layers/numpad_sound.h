/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
**
*/
#pragma once

#include QMK_KEYBOARD_H
#include "ark_v1.h" // root_config
#include "layers.h" // each keyboard should have this file with the available layers enum

#define __X__ KC_NO
#define _____ KC_TRNS

#define ___________NUMPAD_ROW_1_____________ KC_PAST, KC_4, KC_5, KC_6, KC_PPLS
#define ___________NUMPAD_ROW_2_____________ KC_P0, KC_1, KC_2, KC_3, KC_EQL
#define ___________NUMPAD_ROW_3_____________ KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS
#define ___________NUMPAD_THUMBS____________ KC_ENT, KC_DOT

#define ____________SOUND_ROW_1_____________ __X__, __X__, __X__, __X__, __X__
#define ____________SOUND_ROW_2_____________ KC_MNXT, KC_VOLU, KC_LCTL, KC_LGUI, __X__
#define ____________SOUND_ROW_3_____________ KC_MPLY, KC_VOLD, __X__, __X__, __X__
#define ____________SOUND_THUMBS____________ __X__, LAYER_LOCK
