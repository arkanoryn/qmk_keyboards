/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

#define ___NUMPAD_SOUND_CORE_ROW_1___ KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, /* || */ KC_VOLU, KC_VOLD, KC_NUM, TG(_FN), __X__
#define ___NUMPAD_SOUND_CORE_ROW_2___ KC_P0, KC_P1, KC_P2, KC_P3, KC_EQL, /* || */ KC_MNXT, KC_LSFT, KC_LCTL, KC_LGUI, __X__
#define ___NUMPAD_SOUND_CORE_ROW_3___ KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, /* || */ KC_MPLY, __X__, __X__, __X__, __X__
#define ___NUMPAD_SOUND_EXTRA_ROW__ __EXTRA_ROW__

#ifdef FARKANN_EXTRA_COLS
#  define ___NUMPAD_SOUND_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___NUMPAD_SOUND_CORE_ROW_1___)
#  define ___NUMPAD_SOUND_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___NUMPAD_SOUND_CORE_ROW_2___)
#  define ___NUMPAD_SOUND_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___NUMPAD_SOUND_CORE_ROW_3___)
#else
#  define ___NUMPAD_SOUND_ROW_1___ ___NUMPAD_SOUND_CORE_ROW_1___
#  define ___NUMPAD_SOUND_ROW_2___ ___NUMPAD_SOUND_CORE_ROW_2___
#  define ___NUMPAD_SOUND_ROW_3___ ___NUMPAD_SOUND_CORE_ROW_3___
#endif

#define NUMPAD_SOUND_L1 KC_ENT
#define NUMPAD_SOUND_L2 KC_DOT
#define NUMPAD_SOUND_L3 __X__
#define NUMPAD_SOUND_L4 __X__
#define NUMPAD_SOUND_L5 __X__
#define NUMPAD_SOUND_L6 __X__
#define NUMPAD_SOUND_R1 __X__
#define NUMPAD_SOUND_R2 LAYER_LOCK
#define NUMPAD_SOUND_R3 __X__
#define NUMPAD_SOUND_R4 __X__
#define NUMPAD_SOUND_R5 __X__
#define NUMPAD_SOUND_R6 __X__

#if THUMBCLUSTER_LEFT == 5
#  if THUMBCLUSTER_RIGHT == 4
#    define ___NUMPAD_SOUND_THUMBS__________ NUMPAD_SOUND_L1, NUMPAD_SOUND_L2, NUMPAD_SOUND_L3, NUMPAD_SOUND_R1, NUMPAD_SOUND_R2, NUMPAD_SOUND_L4, NUMPAD_SOUND_L5, NUMPAD_SOUND_R3, NUMPAD_SOUND_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___NUMPAD_SOUND_THUMBS__________ NUMPAD_SOUND_L1, NUMPAD_SOUND_L2, NUMPAD_SOUND_L3, NUMPAD_SOUND_R1, NUMPAD_SOUND_R2, NUMPAD_SOUND_R3, NUMPAD_SOUND_L4, NUMPAD_SOUND_L5, NUMPAD_SOUND_R4, NUMPAD_SOUND_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___NUMPAD_SOUND_THUMBS__________ NUMPAD_SOUND_L1, NUMPAD_SOUND_L2, NUMPAD_SOUND_L3, NUMPAD_SOUND_R1, NUMPAD_SOUND_R2, NUMPAD_SOUND_R3, NUMPAD_SOUND_L4, NUMPAD_SOUND_L5, NUMPAD_SOUND_R4, NUMPAD_SOUND_R5, NUMPAD_SOUND_R6
#  endif /* THUMBCLUSTER_RIGHT */
#elif THUMBCLUSTER_LEFT == 6
#  if THUMBCLUSTER_RIGHT == 4
#    define ___NUMPAD_SOUND_THUMBS__________ NUMPAD_SOUND_L1, NUMPAD_SOUND_L2, NUMPAD_SOUND_L3, NUMPAD_SOUND_R1, NUMPAD_SOUND_R2, NUMPAD_SOUND_L4, NUMPAD_SOUND_L5, NUMPAD_SOUND_L6, NUMPAD_SOUND_R3, NUMPAD_SOUND_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___NUMPAD_SOUND_THUMBS__________ NUMPAD_SOUND_L1, NUMPAD_SOUND_L2, NUMPAD_SOUND_L3, NUMPAD_SOUND_R1, NUMPAD_SOUND_R2, NUMPAD_SOUND_R3, NUMPAD_SOUND_L4, NUMPAD_SOUND_L5, NUMPAD_SOUND_L6, NUMPAD_SOUND_R4, NUMPAD_SOUND_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___NUMPAD_SOUND_THUMBS__________ NUMPAD_SOUND_L1, NUMPAD_SOUND_L2, NUMPAD_SOUND_L3, NUMPAD_SOUND_R1, NUMPAD_SOUND_R2, NUMPAD_SOUND_R3, NUMPAD_SOUND_L4, NUMPAD_SOUND_L5, NUMPAD_SOUND_L6, NUMPAD_SOUND_R4, NUMPAD_SOUND_R5, NUMPAD_SOUND_R6
#  endif /* THUMBCLUSTER_RIGHT */
#endif   /* THUMBCLUSTER_LEFT */