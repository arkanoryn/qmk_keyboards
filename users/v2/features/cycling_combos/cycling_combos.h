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

#ifndef LONGEST_CYCLE
#  define LONGEST_CYCLE 6
#endif // LONGEST_CYCLE

typedef struct {
  bool     is_combo_active;
  bool     is_cyclable;
  bool     shift_enabled;
  uint16_t last_cycle_combo_id;
  uint8_t  cycle_position;
} cycling_combos_state_t;

/*
** initialize the state for combos and cycles
** need to be put in the `void keyboard_post_init_user(void)` function.
*/
void init_cycling_combos_state(void);

// send_string as many backspaces as the current combo has.
void backspace_current_output(void);

/*
** Returns the current state of the cycle for combos & magic
*/
cycling_combos_state_t* get_cycling_combo_state(void);

/*
** Cycles through the possibilities of the current combo, if any.
** Returns true if it was NOT possible to cycle and false if something occured.
*/
bool cycle(void);

/*
** Process magic combo event (called from process_combo_event)
*/
void process_magic_combo_event(uint16_t combo_index);
