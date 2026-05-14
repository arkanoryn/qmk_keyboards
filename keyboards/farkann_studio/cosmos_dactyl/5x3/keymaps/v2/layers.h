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

enum layers {
  _GRAPHITE, // GRAPHITE
  _QWERTY,   // QWERTY Layout
  _GAME,     // QWERTY Layout, but without any modifier keys on hold
  _COLEMAK,
  _STURDY,
  _ACTIONS,      // ACTIONS
  _SYMBOLS,      // SYMBOLS
  _ACCENTS,      // ACCENTS
  _NUMPAD_SOUND, // NUMPAD & MULTIMEDIA
  _CONFIG,       // KEYBOARD CONFIGURATION
  _FN
};

#define __X__ KC_NO
#define _____ KC_TRNS

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#include "layers/accents.h"
#include "layers/actions.h"
#include "layers/layouts/colemak.h"
#include "layers/layouts/graphite.h"
#include "layers/layouts/layout.h"
#include "layers/layouts/qwerty.h"
#include "layers/layouts/sturdy.h"
#include "layers/layouts/farkann_thumbs.h"
// #include "layers/num_row.h"
// #include "layers/numpad_sound.h"
// #include "layers/qwerty.h"
#include "layers/symbols.h"
#include "layers/numpad_sound.h"
#include "layers/config.h"
#include "layers/fn.h"
