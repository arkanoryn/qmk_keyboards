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
#include "../selection/selection.h"

typedef struct {
    deferred_token      token;
    uint8_t             rep_count;
    selection_direction_e direction;
} jump_state_s;

/* Function declarations */
bool process_jump_cursor(uint16_t keycode, keyrecord_t *record);
void td_process_jump_forward(tap_dance_state_t *td_state, void *user_data);
void td_process_jump_backward(tap_dance_state_t *td_state, void *user_data);
void cancel_jump_state_token(void);
