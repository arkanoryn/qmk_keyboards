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

/* Tap dance state enum */
typedef enum { // clang-format off
  TD_NONE,
  TD_UNKNOWN,
  TD_1_TAP,
  TD_1_HOLD,
  TD_2_TAP,
  TD_2_HOLD,
  TD_2_SINGLE_TAP,
  TD_3_TAP,
  TD_3_HOLD,
  TD_4_TAP,
  TD_4_HOLD,
  TD_5_TAP,
  TD_5_HOLD,
} td_state_t; // clang-format on

/* Tap dance enum */
enum tap_dances {
    TD_ESC,          /* 1-tap: Esc, 2-tap: Caps Lock */
    TD_SEARCH,       /* 1-tap: Cmd/Ctrl+F, 2-tap: Cmd/Ctrl+Shift+F */
    TD_TAB_NEW,      /* 1-tap: new tab, 2-tap: restore tab */
    TD_TAB_CLOSE,    /* 1-tap: close tab, 2-tap: close window */
    TD_NEW_WINDOW,   /* 1-tap: new window, hold: new incognito */
    TD_JUMP_BWD,     /* Backward word/line jumping with acceleration */
    TD_JUMP_FWD,     /* Forward word/line jumping with acceleration */
    TD_SEL_BWD,      /* Backward selection with acceleration */
    TD_SEL_FWD,      /* Forward selection with acceleration */
    TD_COPY,         /* 1-tap: copy, 2-tap: copy line */
    TD_CUT,          /* 1-tap: cut, 2-tap: cut line */
};

/* Function declarations */
td_state_t cur_dance(tap_dance_state_t *state);

void td_process_new_window(tap_dance_state_t *state, void *user_data);
void td_process_search(tap_dance_state_t *state, void *user_data);
void td_process_tab_new(tap_dance_state_t *state, void *user_data);
void td_process_tab_close(tap_dance_state_t *state, void *user_data);
void td_process_esc(tap_dance_state_t *state, void *user_data);
void td_process_copy(tap_dance_state_t *td_state, void *user_data);
void td_process_cut(tap_dance_state_t *td_state, void *user_data);
void td_process_jump_forward(tap_dance_state_t *td_state, void *user_data);
void td_process_jump_backward(tap_dance_state_t *td_state, void *user_data);
void td_process_selection_forward(tap_dance_state_t *td_state, void *user_data);
void td_process_selection_backward(tap_dance_state_t *td_state, void *user_data);

/* Tap dance actions array declaration for QMK introspection */
extern tap_dance_action_t tap_dance_actions[];
