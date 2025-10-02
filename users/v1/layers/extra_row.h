/* Copyright 2025 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

#if EXTRA_ROW_LEFT == 1 && EXTRA_ROW_RIGHT == 1
#define __EXTRA_ROW__ KC_NO, KC_NO
#elif EXTRA_ROW_LEFT == 1 && EXTRA_ROW_RIGHT == 2
#define __EXTRA_ROW__ KC_NO, KC_NO, KC_NO
#elif EXTRA_ROW_LEFT == 2 && EXTRA_ROW_RIGHT == 1
#define __EXTRA_ROW__ QK_BOOT, KC_NO, QK_BOOT
#elif EXTRA_ROW_LEFT == 2 && EXTRA_ROW_RIGHT == 2
#define __EXTRA_ROW__ KC_NO, KC_NO, KC_NO, KC_NO
#endif
