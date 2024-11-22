/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// OS configurations
#define OS_DETECTION_KEYBOARD_RESET
#define OS_DETECTION_DEBOUNCE 200

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define SELECT_WORD_TIMEOUT 2000
#define SENTENCE_CASE_TIMEOUT 2000

// #define VIRT_SIDECHANNEL

// #define COMBO_STRICT_TIMER   // starts time on the first key of the combo
#define COMBO_TERM 60        // default is 50
#define COMBO_SHOULD_TRIGGER // can define on which layer (for example) a combo is triggerable

// CAPS WORD config
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT    // Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_IDLE_TIMEOUT 15000 // When idle, turn off Caps Word after X seconds.

#ifdef OLED_ENABLE
#  define SPLIT_OLED_ENABLE
// Configuration to send data from main to off hand board
#  define SPLIT_TRANSACTION_IDS_USER USER_SYNC_STATE

#  define OLED_TIMEOUT 120000
#  define OLED_BRIGHTNESS 120

#  define WPM_SAMPLE_SECONDS 10
#  define WPM_SAMPLE_PERIODS 50
#  define WPM_LAUNCH_CONTROL

#  define SPLIT_WPM_ENABLE
#  define SPLIT_TRANSPORT_MIRROR
#  define SPLIT_LAYER_STATE_ENABLE
#  define SPLIT_LED_STATE_ENABLE
#  define SPLIT_MODS_ENABLE
#endif

#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_SLEEP
#  define RGB_MATRIX_KEYPRESSES
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#  define ENABLE_RGB_MATRIX_SOLID_SPLASH
#  define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#endif

// #ifdef MOUSEKEY_ENABLE
//      // The default is 100
// #    define MOUSEKEY_WHEEL_INTERVAL 50
//      // The default is 40
// #    define MOUSEKEY_WHEEL_TIME_TO_MAX 100
// #endif
