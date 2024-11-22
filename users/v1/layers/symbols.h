/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
**
** /!\ This layer requires the implementation of the symbols
*/
#pragma once

#include QMK_KEYBOARD_H
#include "layers.h" // each keyboard should have this file with the available layers enum
#include "symbols/symbols.h"

#define __X__ KC_NO
#define _____ KC_TRNS

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#define __________SYMBOLS_LEFT_ROW_1________ KC_CAPS, KC_AT, KC_HASH, KC_DOLLAR, CKC(EURO)
#define __________SYMBOLS_LEFT_ROW_2________ KC_TILDE, KC_GRV, KC_UNDS, KC_MINS, KC_PLUS
#define __________SYMBOLS_LEFT_ROW_3________ __X__, KC_PIPE, KC_LT, KC_GT, KC_CIRC
#define __________SYMBOLS_LEFT_THUMBS_______ __X__, __X__

#define _________SYMBOLS_RIGHT_ROW_1________ KC_SLSH, KC_LBRC, KC_RBRC, KC_SCLN, __X__
#define _________SYMBOLS_RIGHT_ROW_2________ KC_EQL, KC_LPRN, KC_RPRN, KC_COLN, __X__
#define _________SYMBOLS_RIGHT_ROW_3________ __X__, KC_LCBR, KC_RCBR, KC_BSLS, __X__
#define _________SYMBOLS_RIGHT_THUMBS_______ KC_PERCENT, LAYER_LOCK
