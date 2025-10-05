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

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#define __________CONFIG_LEFT_ROW_1_________ CYCLE_CHORD_MODE, __X__, __X__, __X__, __X__
#define __________CONFIG_LEFT_ROW_2_________ DF(_STURDY), DF(_COLEMAK), DF(_QWERTY), DF(_GRAPHITE), DF(_GAME)
#define __________CONFIG_LEFT_ROW_3_________ QK_BOOT, __X__, __X__, __X__, __X__

#ifdef RGB_MATRIX_ENABLE
#define _________CONFIG_RIGHT_ROW_1________ RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI
#define _________CONFIG_RIGHT_ROW_2________ RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
#else
#define _________CONFIG_RIGHT_ROW_1________ __X__, __X__, __X__, __X__, __X__
#define _________CONFIG_RIGHT_ROW_2________ __X__, __X__, __X__, __X__, __X__

#endif // RGB_MATRIX_ENABLE
#define _________CONFIG_RIGHT_ROW_3________ __X__, __X__, __X__, __X__, __X__
                                                                 //
#define __CONFIG_CORE_ROW_1___  __________CONFIG_LEFT_ROW_1_________, /* || */ _________CONFIG_RIGHT_ROW_1________
#define __CONFIG_CORE_ROW_2___  __________CONFIG_LEFT_ROW_2_________, /* || */ _________CONFIG_RIGHT_ROW_2________
#define __CONFIG_CORE_ROW_3___  __________CONFIG_LEFT_ROW_3_________, /* || */ _________CONFIG_RIGHT_ROW_3________
#define __CONFIG_EXTRA_ROW__ __EXTRA_ROW__

#ifdef FARKANN_EXTRA_COLS
#   define ___CONFIG_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(__CONFIG_CORE_ROW_1___)
#   define ___CONFIG_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(__CONFIG_CORE_ROW_2___)
#   define ___CONFIG_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(__CONFIG_CORE_ROW_3___)
#else
#   define ___CONFIG_ROW_1___ __CONFIG_CORE_ROW_1___
#   define ___CONFIG_ROW_2___ __CONFIG_CORE_ROW_2___
#   define ___CONFIG_ROW_3___ __CONFIG_CORE_ROW_3___
#endif

#define CONFIG_L1 __X__
#define CONFIG_L2 KC_LSFT
#define CONFIG_L3 __X__
#define CONFIG_L4 __X__
#define CONFIG_L5 __X__
#define CONFIG_L6 __X__
#define CONFIG_R1 RGB_TOG
#define CONFIG_R2 TG(_CONFIG)
#define CONFIG_R3 __X__
#define CONFIG_R4 __X__
#define CONFIG_R5 __X__
#define CONFIG_R6 __X__

#if THUMBCLUSTER_LEFT == 2
#   if THUMBCLUSTER_RIGHT == 2
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2
#   elif THUMBCLUSTER_RIGHT == 3
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3
#   elif THUMBCLUSTER_RIGHT == 4
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_R4
#   elif THUMBCLUSTER_RIGHT == 5
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_R4, CONFIG_R5
#   elif THUMBCLUSTER_RIGHT == 6
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_R4, CONFIG_R5, CONFIG_R6
#   endif // THUMBCLUSTER_RIGHT
#elif THUMBCLUSTER_LEFT == 3
#   if THUMBCLUSTER_RIGHT == 2
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2
#   elif THUMBCLUSTER_RIGHT == 3
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3
#   elif THUMBCLUSTER_RIGHT == 4
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_R4
#   elif THUMBCLUSTER_RIGHT == 5
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_R4, CONFIG_R5
#   elif THUMBCLUSTER_RIGHT == 6
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_R4, CONFIG_R5, CONFIG_R6
#   endif // THUMBCLUSTER_RIGHT
#elif THUMBCLUSTER_LEFT == 4
#   if THUMBCLUSTER_RIGHT == 2
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_L3, CONFIG_L4
#   elif THUMBCLUSTER_RIGHT == 3
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L3, CONFIG_L4
#   elif THUMBCLUSTER_RIGHT == 4
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_L3, CONFIG_L4, CONFIG_R3, CONFIG_R4
#   elif THUMBCLUSTER_RIGHT == 5
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L3, CONFIG_L4, CONFIG_R4, CONFIG_R5
#   elif THUMBCLUSTER_RIGHT == 6
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L3, CONFIG_L4, CONFIG_R4, CONFIG_R5, CONFIG_R6
#   endif // THUMBCLUSTER_RIGHT
#elif THUMBCLUSTER_LEFT == 5
#   if THUMBCLUSTER_RIGHT == 2
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_L4, CONFIG_L5
#   elif THUMBCLUSTER_RIGHT == 3
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5
#   elif THUMBCLUSTER_RIGHT == 4
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_L4, CONFIG_L5, CONFIG_R3, CONFIG_R4
#   elif THUMBCLUSTER_RIGHT == 5
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_R4, CONFIG_R5
#   elif THUMBCLUSTER_RIGHT == 6
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_R4, CONFIG_R5, CONFIG_R6
#   endif // THUMBCLUSTER_RIGHT
#elif THUMBCLUSTER_LEFT == 6
#   if THUMBCLUSTER_RIGHT == 2
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_L4, CONFIG_L5, CONFIG_L6
#   elif THUMBCLUSTER_RIGHT == 3
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_L6
#   elif THUMBCLUSTER_RIGHT == 4
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_L4, CONFIG_L5, CONFIG_L6, CONFIG_R3, CONFIG_R4
#   elif THUMBCLUSTER_RIGHT == 5
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_L6, CONFIG_R4, CONFIG_R5
#   elif THUMBCLUSTER_RIGHT == 6
#       define __CONFIG_THUMBS__________ CONFIG_L1, CONFIG_L2, CONFIG_L3, CONFIG_R1, CONFIG_R2, CONFIG_R3, CONFIG_L4, CONFIG_L5, CONFIG_L6, CONFIG_R4, CONFIG_R5, CONFIG_R6
#   endif // THUMBCLUSTER_RIGHT
#endif // THUMBCLUSTER_LEFT
