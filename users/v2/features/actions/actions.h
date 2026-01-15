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

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#ifndef ALT_TAB_TIMER
#  define ALT_TAB_TIMER 5000 // milliseconds
#endif

/*
 * Action structure for cross-platform shortcut definitions
 */
typedef struct {
  const char *on_linux;
  const char *on_macOS;
  const char *on_windows;
} action_s;

/*
 * State structure for alt-tab functionality
 */
typedef struct {
  bool     active;
  uint16_t timer;
} alt_tab_s;

/*
 * Enum defining all available actions
 */
typedef enum {
    ALFRED = _FIRST_ACTION_ID,
    APP_CLOSE,
    APP_NEW_WINDOW_INCOGNITO,
    APP_NEW_WINDOW,
    APP_NEXT,
    APP_PREV,
    CMD_COPY,
    CMD_CUT,
    CMD_PASTE,
    CMD_REDO,
    CMD_SAVE,
    CMD_SEARCH_ALL,
    CMD_SEARCH,
    CMD_UNDO,
    CMD_SELECT_ALL,
    LINE_BACKSPACE,
    LINE_DEL,
    LINE_JUMPL,
    LINE_JUMPR,
    LINE_SELECTL,
    LINE_SELECTR,
    TAB_CLOSE,
    TAB_NEW,
    TAB_REOPEN,
    TASK_MNGR,
    WINDOW_CLOSE,
    WORD_BACKSPACE,
    WORD_DEL,
    WORD_JUMPL,
    WORD_JUMPR,
    WORD_SELECTL,
    WORD_SELECTR,
    _LAST_ACTION_ID
} actions_id_e;

/*
 * Function declarations for action processing
 */
bool process_actions(uint16_t keycode, keyrecord_t *record);
void init_alt_tab_state(void);
void alt_tab_task(void);
void send_action(actions_id_e id);
