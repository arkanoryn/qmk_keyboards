/* Copyright 2026 Ark'Anoryn (@arkanoryn)
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

#define ___FN_CORE_ROW_1___ KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, /* || */ KC_F1, KC_F2, KC_F3, KC_F4, __X__
#define ___FN_CORE_ROW_2___ KC_P0, KC_P1, KC_P2, KC_P3, KC_EQL, /* || */ KC_F5, KC_F6, KC_F7, KC_F8, __X__
#define ___FN_CORE_ROW_3___ KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, /* || */ KC_F9, KC_F10, KC_F11, KC_F12, __X__
#define ___FN_EXTRA_ROW__ __EXTRA_ROW__

#ifdef FARKANN_EXTRA_COLS
#  define ___FN_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___FN_CORE_ROW_1___)
#  define ___FN_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___FN_CORE_ROW_2___)
#  define ___FN_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___FN_CORE_ROW_3___)
#else
#  define ___FN_ROW_1___ ___FN_CORE_ROW_1___
#  define ___FN_ROW_2___ ___FN_CORE_ROW_2___
#  define ___FN_ROW_3___ ___FN_CORE_ROW_3___
#endif

#define FN_L1 KC_ENT
#define FN_L2 KC_DOT
#define FN_L3 __X__
#define FN_L4 __X__
#define FN_L5 __X__
#define FN_L6 __X__
#define FN_R1 __X__
#define FN_R2 LAYER_LOCK
#define FN_R3 __X__
#define FN_R4 __X__
#define FN_R5 __X__
#define FN_R6 __X__

#if THUMBCLUSTER_LEFT == 5
#  if THUMBCLUSTER_RIGHT == 4
#    define ___FN_THUMBS__________ FN_L1, FN_L2, FN_L3, FN_R1, FN_R2, FN_L4, FN_L5, FN_R3, FN_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___FN_THUMBS__________ FN_L1, FN_L2, FN_L3, FN_R1, FN_R2, FN_R3, FN_L4, FN_L5, FN_R4, FN_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___FN_THUMBS__________ FN_L1, FN_L2, FN_L3, FN_R1, FN_R2, FN_R3, FN_L4, FN_L5, FN_R4, FN_R5, FN_R6
#  endif /* THUMBCLUSTER_RIGHT */
#elif THUMBCLUSTER_LEFT == 6
#  if THUMBCLUSTER_RIGHT == 4
#    define ___FN_THUMBS__________ FN_L1, FN_L2, FN_L3, FN_R1, FN_R2, FN_L4, FN_L5, FN_L6, FN_R3, FN_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___FN_THUMBS__________ FN_L1, FN_L2, FN_L3, FN_R1, FN_R2, FN_R3, FN_L4, FN_L5, FN_L6, FN_R4, FN_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___FN_THUMBS__________ FN_L1, FN_L2, FN_L3, FN_R1, FN_R2, FN_R3, FN_L4, FN_L5, FN_L6, FN_R4, FN_R5, FN_R6
#  endif /* THUMBCLUSTER_RIGHT */
#endif   /* THUMBCLUSTER_LEFT */
