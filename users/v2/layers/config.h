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

#ifndef CKC
#include "layers.h"
#  define CKC(x) (SAFE_RANGE + x) /* generate custom keycode from enum */
#endif                            /* CKC */

#define ___CONFIG_CORE_ROW_1___ __X__, __X__, __X__, __X__, __X__, /* || */ RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI
#define ___CONFIG_CORE_ROW_2___ __X__, __X__, __X__, __X__, __X__, /* || */ RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
#define ___CONFIG_CORE_ROW_3___ QK_BOOT, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#define ___CONFIG_EXTRA_ROW__ __EXTRA_ROW__

#ifdef RGB_MATRIX_ENABLE
#  ifdef FARKANN_EXTRA_COLS
#    define ___CONFIG_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___CONFIG_CORE_ROW_1___)
#    define ___CONFIG_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___CONFIG_CORE_ROW_2___)
#    define ___CONFIG_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___CONFIG_CORE_ROW_3___)
#  else
#    define ___CONFIG_ROW_1___ ___CONFIG_CORE_ROW_1___
#    define ___CONFIG_ROW_2___ ___CONFIG_CORE_ROW_2___
#    define ___CONFIG_ROW_3___ ___CONFIG_CORE_ROW_3___
#  endif
#else
#  ifdef FARKANN_EXTRA_COLS
#    define ___CONFIG_ROW_1_NO_RGB___ __X__, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#    define ___CONFIG_ROW_2_NO_RGB___ __X__, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#    define ___CONFIG_ROW_3_NO_RGB___ QK_BOOT, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#    define ___CONFIG_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___CONFIG_ROW_1_NO_RGB___)
#    define ___CONFIG_ROW_2___ ___ROW_1_WITH_EXTRA_COLS(___CONFIG_ROW_2_NO_RGB___)
#    define ___CONFIG_ROW_3___ ___ROW_1_WITH_EXTRA_COLS(___CONFIG_ROW_3_NO_RGB___)
#  else
#    define ___CONFIG_ROW_1___ __X__, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#    define ___CONFIG_ROW_2___ __X__, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#    define ___CONFIG_ROW_3___ QK_BOOT, __X__, __X__, __X__, __X__, /* || */ __X__, __X__, __X__, __X__, __X__
#  endif
#endif

#define CONFIG_L1 __X__
#define CONFIG_L2 KC_LSFT
#define CONFIG_L3 __X__
#define CONFIG_L4 __X__
#define CONFIG_L5 __X__
#define CONFIG_L6 __X__
#define CONFIG_R1 __X__
#define CONFIG_R2 TG(_CONFIG)
#define CONFIG_R3 __X__
#define CONFIG_R4 __X__
#define CONFIG_R5 __X__
#define CONFIG_R6 __X__

#if THUMBCLUSTER_LEFT == 5
#  if THUMBCLUSTER_RIGHT == 4
#    define ___CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_L4, CONFIG_L5, CONFIG_R3, CONFIG_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_R4, CONFIG_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_R4, CONFIG_R5, CONFIG_R6
#  endif /* THUMBCLUSTER_RIGHT */
#elif THUMBCLUSTER_LEFT == 6
#  if THUMBCLUSTER_RIGHT == 4
#    define ___CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_L4, CONFIG_L5, CONFIG_L6, CONFIG_R3, CONFIG_R4
#  elif THUMBCLUSTER_RIGHT == 5
#    define ___CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_L6, CONFIG_R4, CONFIG_R5
#  elif THUMBCLUSTER_RIGHT == 6
#    define ___CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_L6, CONFIG_R4, CONFIG_R5, CONFIG_R6
#  endif /* THUMBCLUSTER_RIGHT */
#endif   /* THUMBCLUSTER_LEFT */
