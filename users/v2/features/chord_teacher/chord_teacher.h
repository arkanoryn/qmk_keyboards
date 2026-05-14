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

// Chord teacher modes
typedef enum {
  TEACHER_CHORD_MODE_OFF,
  TEACHER_CHORD_MODE_ON,
  TEACHER_CHORD_MODE_CORRECTIVE
} teacher_chord_mode_t;

// Function declarations
void init_teacher_state(void);
void reset_teacher_state(bool full_reset);
teacher_chord_mode_t get_teacher_chord_mode(void);
