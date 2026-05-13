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

/* Cosmos Dactyl 5x3 thumb cluster configuration */
#define THUMBCLUSTER_LEFT 6
#define THUMBCLUSTER_RIGHT 4

// Basic QMK configuration
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// Combo configuration
#define COMBO_TERM 60
#define COMBO_SHOULD_TRIGGER
// #define COMBO_ONLY_FROM_LAYER 0
#define SELECT_WORD_TIMEOUT 2000

// Caps Word configuration
// #define CAPS_WORD_INVERT_ON_SHIFT
// #define CAPS_WORD_IDLE_TIMEOUT 15000

// OS Detection
#define OS_DETECTION_KEYBOARD_RESET
#define OS_DETECTION_DEBOUNCE 200

// Future feature placeholders
// #define FARKANN_FRENCH_ACCENTS
// #define CYCLE_COMBO_ENABLE
// #define CHORD_TEACHER_ENABLE

// #ifdef QUANTUM_PAINTER_DISPLAY_TIMEOUT
// #undef QUANTUM_PAINTER_DISPLAY_TIMEOUT
// #define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
// #define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS TRUE
// #endif

// #ifdef OLED_ENABLE
// #define SPLIT_OLED_ENABLE
// #define SPLIT_TRANSACTION_IDS_USER USER_SYNC_STATE
// #define OLED_TIMEOUT 120000
// #define OLED_BRIGHTNESS 120
// #endif

// #ifdef RGB_MATRIX_ENABLE
// #define RGB_MATRIX_SLEEP
// #define RGB_MATRIX_KEYPRESSES
// #endif
