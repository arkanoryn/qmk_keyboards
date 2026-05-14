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
#include "layers.h"

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) /* generate custom keycode from enum */
#endif                            /* CKC */

#define ___SYMBOLS_CORE_ROW_1___ KC_CAPS, KC_AT, KC_HASH, KC_DOLLAR, __X__, /* || */ KC_SLSH, KC_LBRC, KC_RBRC, KC_SCLN, __X__
#define ___SYMBOLS_CORE_ROW_2___ KC_TILDE, KC_GRV, KC_UNDS, KC_MINS, KC_PLUS, /* || */ KC_EQL, KC_LPRN, KC_RPRN, KC_COLN, __X__
#define ___SYMBOLS_CORE_ROW_3___ __X__, KC_PIPE, KC_LT, KC_GT, KC_CIRC, /* || */ __X__, KC_LCBR, KC_RCBR, KC_BSLS, __X__
#define ___SYMBOLS_EXTRA_ROW__ __EXTRA_ROW__

#ifdef FARKANN_EXTRA_COLS
#  define ___SYMBOLS_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___SYMBOLS_CORE_ROW_1___)
#  define ___SYMBOLS_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___SYMBOLS_CORE_ROW_2___)
#  define ___SYMBOLS_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___SYMBOLS_CORE_ROW_3___)
#else
#  define ___SYMBOLS_ROW_1___ ___SYMBOLS_CORE_ROW_1___
#  define ___SYMBOLS_ROW_2___ ___SYMBOLS_CORE_ROW_2___
#  define ___SYMBOLS_ROW_3___ ___SYMBOLS_CORE_ROW_3___
#endif

#define SYMBOL_L1 __X__
#define SYMBOL_L2 __X__
#define SYMBOL_L3 __X__
#define SYMBOL_L4 __X__
#define SYMBOL_L5 __X__
#define SYMBOL_L6 __X__
#define SYMBOL_R1 KC_PERCENT
#define SYMBOL_R2 QK_LLCK
#define SYMBOL_R3 __X__
#define SYMBOL_R4 __X__
#define SYMBOL_R5 __X__
#define SYMBOL_R6 __X__

#if THUMBCLUSTER_LEFT == 5
#  if THUMBCLUSTER_RIGHT == 4
#    define ___SYMBOLS_THUMBS__________ SYMBOL_L1, SYMBOL_L2, SYMBOL_L3, SYMBOL_R1, SYMBOL_R2, SYMBOL_L4, SYMBOL_L5, SYMBOL_R3, SYMBOL_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___SYMBOLS_THUMBS__________ SYMBOL_L1, SYMBOL_L2, SYMBOL_L3, SYMBOL_R1, SYMBOL_R2, SYMBOL_R3, SYMBOL_L4, SYMBOL_L5, SYMBOL_R4, SYMBOL_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___SYMBOLS_THUMBS__________ SYMBOL_L1, SYMBOL_L2, SYMBOL_L3, SYMBOL_R1, SYMBOL_R2, SYMBOL_R3, SYMBOL_L4, SYMBOL_L5, SYMBOL_R4, SYMBOL_R5, SYMBOL_R6
#  endif /* THUMBCLUSTER_RIGHT */
#elif THUMBCLUSTER_LEFT == 6
#  if THUMBCLUSTER_RIGHT == 4
#    define ___SYMBOLS_THUMBS__________ SYMBOL_L1, SYMBOL_L2, SYMBOL_L3, SYMBOL_R1, SYMBOL_R2, SYMBOL_L4, SYMBOL_L5, SYMBOL_L6, SYMBOL_R3, SYMBOL_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___SYMBOLS_THUMBS__________ SYMBOL_L1, SYMBOL_L2, SYMBOL_L3, SYMBOL_R1, SYMBOL_R2, SYMBOL_R3, SYMBOL_L4, SYMBOL_L5, SYMBOL_L6, SYMBOL_R4, SYMBOL_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___SYMBOLS_THUMBS__________ SYMBOL_L1, SYMBOL_L2, SYMBOL_L3, SYMBOL_R1, SYMBOL_R2, SYMBOL_R3, SYMBOL_L4, SYMBOL_L5, SYMBOL_L6, SYMBOL_R4, SYMBOL_R5, SYMBOL_R6
#  endif /* THUMBCLUSTER_RIGHT */
#endif   /* THUMBCLUSTER_LEFT */
