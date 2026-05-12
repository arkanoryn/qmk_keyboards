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
#include "farkann_v2.h"
#include "generated/combos.h"

// Combo configuration defaults
#ifndef COMBO_TERM
#  define COMBO_TERM 60
#endif

#ifndef COMBO_STR_MAX_LENGTH
#  define COMBO_STR_MAX_LENGTH 15
#endif

// Function declarations
void set_combo_event_timer(void);
void combo_event_task(void);
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);
void process_combo_event(uint16_t combo_index, bool pressed);
