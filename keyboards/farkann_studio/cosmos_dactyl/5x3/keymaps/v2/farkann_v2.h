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

// Layer definitions
#include "layers.h"

#ifndef NEW_SAFE_RANGE
#  define NEW_SAFE_RANGE SAFE_RANGE // + _LAST_SHORTCUT_ID + _LAST_SYMBOL_ID
#endif                              // NEW_SAFE_RANGE

// Custom keycodes
enum custom_keycodes {
  LAYER_LOCK = SAFE_RANGE,
  MAGIC,
  ARCANE,
};
