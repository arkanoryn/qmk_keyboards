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

// Define __X__ for empty keys
#ifndef __X__
#  define __X__ KC_NO
#endif

// Define TAB_NEXT and TAB_PREV for tab navigation
#define TAB_NEXT LCTL(KC_TAB)
#define TAB_PREV RCS(KC_TAB)

// Individual action key defines for better configurability
// TAP_DANCE placeholders - will be replaced with TD() functions when enabled

/* Side: Left, ROW: 1 */
#define ACTIONS_1_01 KC_0 // TD(TD_ESC)
#define ACTIONS_1_02 KC_0 // TD(TD_SEARCH)
#define ACTIONS_1_03 CKC(ALFRED)
#define ACTIONS_1_04 KC_DEL
#define ACTIONS_1_05 CKC(APP_PREV)
/* Side: Right, ROW: 1 */
#define ACTIONS_1_06 KC_PGUP
#define ACTIONS_1_07 KC_0 // TD(TD_JUMP_BACKWARD)
#define ACTIONS_1_08 KC_0 // TD(TD_JUMP_FORWARD)
#define ACTIONS_1_09 KC_HOME
#define ACTIONS_1_10 KC_END
/* Side: Left, ROW: 2 */
#define ACTIONS_2_01 KC_TAB
#define ACTIONS_2_02 CKC(CMD_SAVE)
#define ACTIONS_2_03 __X__
#define ACTIONS_2_04 __X__
#define ACTIONS_2_05 CKC(APP_NEXT)
/* Side: Right, ROW: 2 */
#define ACTIONS_2_06 KC_PGDN
#define ACTIONS_2_07 KC_LEFT
#define ACTIONS_2_08 KC_DOWN
#define ACTIONS_2_09 KC_UP
#define ACTIONS_2_10 KC_RIGHT
/* Side: Left, ROW: 3 */
#define ACTIONS_3_01 CKC(TASK_MNGR)
#define ACTIONS_3_02 CKC(CMD_REDO)
#define ACTIONS_3_03 CKC(CMD_UNDO)
#define ACTIONS_3_04 KC_0 // TD(TD_NEW_WINDOW)
#define ACTIONS_3_05 CKC(APP_CLOSE)
/* Side: Right, ROW: 3 */
#define ACTIONS_3_06 CKC(TAB_REOPEN)
#define ACTIONS_3_07 KC_0 // TD(TD_TAB_NEW)
#define ACTIONS_3_08 KC_0 // TD(TD_TAB_CLOSE)
#define ACTIONS_3_09 TAB_NEXT
#define ACTIONS_3_10 TAB_PREV

#define ___ACTIONS_CORE_ROW_1___ ACTIONS_1_01, ACTIONS_1_02, ACTIONS_1_03, ACTIONS_1_04, ACTIONS_1_05, ACTIONS_1_06, ACTIONS_1_07, ACTIONS_1_08, ACTIONS_1_09, ACTIONS_1_10
#define ___ACTIONS_CORE_ROW_2___ ACTIONS_2_01, ACTIONS_2_02, ACTIONS_2_03, ACTIONS_2_04, ACTIONS_2_05, ACTIONS_2_06, ACTIONS_2_07, ACTIONS_2_08, ACTIONS_2_09, ACTIONS_2_10
#define ___ACTIONS_CORE_ROW_3___ ACTIONS_3_01, ACTIONS_3_02, ACTIONS_3_03, ACTIONS_3_04, ACTIONS_3_05, ACTIONS_3_06, ACTIONS_3_07, ACTIONS_3_08, ACTIONS_3_09, ACTIONS_3_10

// #ifdef FARKANN_EXTRA_COLS
// #   define ___ACTIONS_ROW_1___ ___ROW_1_WITH_EXTRA_COLS(___ACTIONS_CORE_ROW_1___)
// #   define ___ACTIONS_ROW_2___ ___ROW_2_WITH_EXTRA_COLS(___ACTIONS_CORE_ROW_2___)
// #   define ___ACTIONS_ROW_3___ ___ROW_3_WITH_EXTRA_COLS(___ACTIONS_CORE_ROW_3___)
// #else
#define ___ACTIONS_ROW_1___ ___ACTIONS_CORE_ROW_1___
#define ___ACTIONS_ROW_2___ ___ACTIONS_CORE_ROW_2___
#define ___ACTIONS_ROW_3___ ___ACTIONS_CORE_ROW_3___
// #endif
