/* Copyright 2025-2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

// Function declarations for helper functions
void v2_helper_init(void);
bool process_v2_helpers(uint16_t keycode, keyrecord_t *record);

// Mod helper functions
const uint8_t all_mods(void);      // Returns all mods currently enabled
bool          is_shifted(void);    // returns if shift is enabled or not
void          disable_shift(void); // del mods and weak mods and onshot for shift.