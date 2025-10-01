/* Copyright 2025 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

/*
** This file contains the different possibilities our keyboards can have for the Thumb Clusters.
*/

#pragma once

#include QMK_KEYBOARD_H

// #ifdef FARKANN_POWER_USER
#define L1 LSFT_T(MAGIC)
#define L2 MEH_T(KC_SPC)
#define L3 LGUI_T(KC_ESC)
#define L4 LCTL_T(S(KC_TAB))
#define L5 LALT_T(KC_TAB)
#define L6 KC_PGDN
#define R1 RSFT_T(KC_BSPC)
#define R2 RALT_T(KC_ENT)
#define R3 RCTL_T(ARCANE)
#define R4 RGUI_T(KC_DEL)
#define R5 KC_HOME
#define R6 KC_END
// #else
// #define L1 KC_SPC
// #define L2 KC_ESC
// #define L3 KC_PGUP
// #define L4 S(KC_TAB)
// #define L5 KC_TAB
// #define L6 QK_BOOT // KC_PGDN // RAISE | LOWER
// #define R1 KC_BSPC
// #define R2 KC_ENT
// #define R3 QK_BOOT // KC_LSFT
// #define R4 KC_RCTL
// #define R5 KC_RALT
// #define R6 KC_RGUI
// #endif // FARKANN_POWER_USER

// THUMBCLUSTER_LEFT == 2
#if THUMBCLUSTER_LEFT == 2 && THUMBCLUSTER_RIGHT == 2
#define __THUMBS__________ L1, L2, R1, R2
#elif THUMBCLUSTER_LEFT == 2 && THUMBCLUSTER_RIGHT == 3
#define __THUMBS__________ L1, L2, R1, R2, R3
#elif THUMBCLUSTER_LEFT == 2 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ L1, L2, R1, R2, R3, R4
#elif THUMBCLUSTER_LEFT == 2 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ L1, L2, R1, R2, R3, R4, R5
#elif THUMBCLUSTER_LEFT == 2 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ L1, L2, R1, R2, R3, R4, R5, R6

// THUMBCLUSTER_LEFT == 3
#elif THUMBCLUSTER_LEFT == 3 && THUMBCLUSTER_RIGHT == 2
#define __THUMBS__________ L1, L2, L3, R1, R2
#elif THUMBCLUSTER_LEFT == 3 && THUMBCLUSTER_RIGHT == 3
#define __THUMBS__________ L1, L2, L3, R1, R2, R3
#elif THUMBCLUSTER_LEFT == 3 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, R4
#elif THUMBCLUSTER_LEFT == 3 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, R4, R5
#elif THUMBCLUSTER_LEFT == 3 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, R4, R5, R6

// THUMBCLUSTER_LEFT == 4
#elif THUMBCLUSTER_LEFT == 4 && THUMBCLUSTER_RIGHT == 2
#define __THUMBS__________ L1, L2, R1, R2, L3, L4
#elif THUMBCLUSTER_LEFT == 4 && THUMBCLUSTER_RIGHT == 3
#define __THUMBS__________ L1, L2, R1, R2, R3, L3, L4
#elif THUMBCLUSTER_LEFT == 4 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ L1, L2, R1, R2, L3, L4, R3, R4
#elif THUMBCLUSTER_LEFT == 4 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ L1, L2, R1, R2, R3, L3, L4, R4, R5
#elif THUMBCLUSTER_LEFT == 4 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ L1, L2, R1, R2, R3, L3, L4, R4, R5, R6

// THUMBCLUSTER_LEFT == 5
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 2
#define __THUMBS__________ L1, L2, L3, R1, R2, L4, L5
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 3
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, L4, L5
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ L1, L2, L3, R1, R2, L4, L5, R3, R4
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, L4, L5, R4, R5
#elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, L4, L5, R4, R5, R6

// THUMBCLUSTER_LEFT == 6
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 2
#define __THUMBS__________ L1, L2, L3, R1, R2, L4, L5, L6
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 3
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, L4, L5, L6
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ L1, L2, L3, R1, R2, L4, L5, L6, R3, R4
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 5
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, L4, L5, L6, R4, R5
#elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 6
#define __THUMBS__________ L1, L2, L3, R1, R2, R3, L4, L5, L6, R4, R5, R6
#endif
