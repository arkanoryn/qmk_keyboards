/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
**
** /!\ This layer requires the implementation of the symbols
*/
#pragma once

#include QMK_KEYBOARD_H
#include "ark_v1.h" // root_config
#include "layers.h" // each keyboard should have this file with the available layers enum
#include "symbols/symbols.h"

#define __X__ KC_NO
#define _____ KC_TRNS

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#define __________ACCENTS_LEFT_ROW_1________ CW_TOGG, KC_ASTR, KC_AMPR, KC_PERCENT, CKC(CMD_REDO)
#define __________ACCENTS_LEFT_ROW_2________ KC_TAB, KC_DQUO, KC_EXLM, KC_QUES, CKC(CMD_UNDO)
#define __________ACCENTS_LEFT_ROW_3________ __X__, __X__, __X__, __X__, __X__
#define __________ACCENTS_LEFT_THUMBS_______ __X__, KC_LSFT

#define _________ACCENTS_RIGHT_ROW_1________ __X__, CKC(E_CIRC), CKC(U_GRAVE), CKC(I_CIRC), CKC(I_TREMA)
#define _________ACCENTS_RIGHT_ROW_2________ __X__, CKC(E_AIGU), CKC(E_GRAVE), CKC(A_GRAVE), CKC(O_CIRC)
#define _________ACCENTS_RIGHT_ROW_3________ __X__, CKC(C_CEDILLE), CKC(U_CIRC), CKC(A_CIRC), __X__
#define _________ACCENTS_RIGHT_THUMBS_______ __X__, LAYER_LOCK
