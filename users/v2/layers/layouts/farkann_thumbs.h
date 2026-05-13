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

/*
** This file contains the different possibilities our keyboards can have for the Thumb Clusters.
*/

#pragma once

#include QMK_KEYBOARD_H

// Left side Thumb keys
#define MEH_SPC     MEH_T(KC_SPC)
#define SFT_MAGIC   LSFT_T(KC_F24)
#define GUI_ESC     LGUI_T(KC_ESC)
#define CTL_TAB     LCTL_T(KC_TAB)
#define ALT_CAPS    LALT_T(KC_CAPS)
#define DEL_WORD    KC_ESC // TODO: add the correct key press, once we are working on the function keys

// Right side Thumb keys
#define ALT_ARCANE  RALT_T(KC_F23)
#define SFT_BSPC    RSFT_T(KC_BSPC)
#define GUI_DEL     RGUI_T(KC_DEL)
#define CTL_ENTR    RCTL_T(KC_ENT)
// // TODO: choose what to put on other keys for keyboards with 5 and 6 thumb clusters. Could be left and right click
// #define THUMB_R5 KC_HOME
// #define THUMB_R6 KC_END

#ifndef __THUMBS__________
#undef __THUMBS__________
#endif

// THUMBCLUSTER_LEFT == 5
// #if THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 4
// #define __THUMBS__________ MEH_SPC, SFT_MAGIC, GUI_ESC, ALT_ARCANE, SFT_BSPC, CTL_TAB, ALT_CAPS, DEL_WORD, GUI_DEL, CTL_ENTR
// #elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 5
// #define __THUMBS__________ MEH_SPC, SFT_MAGIC, GUI_ESC, ALT_ARCANE, SFT_BSPC, RCTL_TAB, ALT_CAPS, DEL_WORD, GUI_DEL, CTL_ENTR
// #elif THUMBCLUSTER_LEFT == 5 && THUMBCLUSTER_RIGHT == 6
// #define __THUMBS__________ THUMB_L1, THUMB_L2, THUMB_L3, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_L4, THUMB_L5, THUMB_R4, THUMB_R5, THUMB_R6

// THUMBCLUSTER_LEFT == 6
// #elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 4
#define __THUMBS__________ MEH_SPC, SFT_MAGIC, GUI_ESC, ALT_ARCANE, SFT_BSPC, CTL_TAB, ALT_CAPS, DEL_WORD, GUI_DEL, CTL_ENTR
// #elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 5
// #define __THUMBS__________ THUMB_L1, THUMB_L2, THUMB_L3, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_L4, THUMB_L5, THUMB_L6, THUMB_R4, THUMB_R5
// #elif THUMBCLUSTER_LEFT == 6 && THUMBCLUSTER_RIGHT == 6
// #define __THUMBS__________ THUMB_L1, THUMB_L2, THUMB_L3, THUMB_R1, THUMB_R2, THUMB_R3, THUMB_L4, THUMB_L5, THUMB_L6, THUMB_R4, THUMB_R5, THUMB_R6
// #endif
