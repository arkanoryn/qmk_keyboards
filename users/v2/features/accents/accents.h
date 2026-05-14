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
#include <os_detection.h>

/* OS-aware dead key constants */
#define WIN_CIRCONFLEXE         A(S(KC_6))
#define WIN_AIGU                A(KC_QUOTE)
#define WIN_GRAVE               A(KC_GRAVE)
#define WIN_TREMA               A(S(KC_QUOTE))
#define WIN_CEDILLE             A(KC_QUOTE)
#define MAC_CIRCONFLEXE         LOPT(KC_I)
#define MAC_AIGU                LOPT(KC_E)
#define MAC_GRAVE               LOPT(KC_GRAVE)
#define MAC_TREMA               LOPT(KC_U)
#define CIRCONFLEXE             (detected_host_os() == OS_MACOS ? MAC_CIRCONFLEXE : WIN_CIRCONFLEXE)
#define AIGU                    (detected_host_os() == OS_MACOS ? MAC_AIGU : WIN_AIGU)
#define GRAVE                   (detected_host_os() == OS_MACOS ? MAC_GRAVE : WIN_GRAVE)
#define TREMA                   (detected_host_os() == OS_MACOS ? MAC_TREMA : WIN_TREMA)
#define WIN_EUR                 SS_LCTL(SS_LALT("5"))
#define MAC_EUR                 SS_LALT(SS_LSFT("2"))

bool process_accents(uint16_t keycode, keyrecord_t *record);
