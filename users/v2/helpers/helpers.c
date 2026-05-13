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

#include "helpers.h"

void v2_helper_init(void) {
  // Initialize helper functions
}

bool process_v2_helpers(uint16_t keycode, keyrecord_t *record) {
  // Process helper-specific keycodes
  return true;
}

// Mod helper functions
const uint8_t all_mods(void) {
  return (get_mods() | get_oneshot_mods() | get_weak_mods());
}

bool is_shifted(void) {
  return (all_mods() & MOD_MASK_SHIFT);
}

void disable_shift(void) {
  del_mods(MOD_MASK_SHIFT);
  del_oneshot_mods(MOD_MASK_SHIFT);
}
