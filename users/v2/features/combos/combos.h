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

/*
 * Requirements:
 * - add `INTROSPECTION_KEYMAP_C = generated/combos.c` to your `rules.mk`
 */
#pragma once

#include QMK_KEYBOARD_H
#include "farkann_v2.h" // KEYMAP_MAIN_H
#include "generated/combos.h"

#define COMBO_STR_MAX_LENGTH 15
#define WIN_WORD_BACKSPACE SS_LCTL(SS_TAP(X_BACKSPACE))
#define LINUX_WORD_BACKSPACE SS_LCTL(SS_TAP(X_BACKSPACE))
#define MAC_WORD_BACKSPACE SS_LALT(SS_TAP(X_BACKSPACE))

void set_combo_event_timer(void);
void combo_event_task(void);
void word_backspace(void);
