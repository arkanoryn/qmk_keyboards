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

// Process repeat key events
bool process_repeat_keys(uint16_t keycode, keyrecord_t *record);

// Graphite-specific key processing
bool process_magic_key_graphite(uint16_t keycode, uint8_t mods);
bool process_arcane_key_graphite(uint16_t keycode, uint8_t mods);

// Sturdy-specific key processing
bool process_magic_key_sturdy(uint16_t keycode, uint8_t mods);
bool process_arcane_key_sturdy(uint16_t keycode, uint8_t mods);

// Colemak-specific key processing
bool process_magic_key_colemak(uint16_t keycode, uint8_t mods);
bool process_arcane_key_colemak(uint16_t keycode, uint8_t mods);

// Qwerty-specific key processing
bool process_magic_key_qwerty(uint16_t keycode, uint8_t mods);
bool process_arcane_key_qwerty(uint16_t keycode, uint8_t mods);
