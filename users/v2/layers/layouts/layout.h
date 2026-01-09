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

#include "layers.h" // each keyboard should have this file with the available layers enum

// Helper macro to append KC_TAB and KC_BSPC to a row
#define ___ROW_1_WITH_EXTRA_COLS(row) KC_TAB, row, KC_BSPC
#define ___ROW_2_WITH_EXTRA_COLS(row) KC_CAPS, row, KC_ENT
#define ___ROW_3_WITH_EXTRA_COLS(row) KC_LSHFT, row, KC_RSHFT
