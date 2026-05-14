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

#include "farkann_v2.h"
#include "repeat.h"

static void process_magic_key(uint16_t last_keycode) {
    (void)last_keycode;
  if (layer_state_is(_GRAPHITE)) {
    process_magic_key_graphite(last_keycode, get_last_mods());
  } else if (layer_state_is(_STURDY)) {
    process_magic_key_sturdy(last_keycode, get_last_mods());
  } else if (layer_state_is(_COLEMAK)) {
    process_magic_key_colemak(last_keycode, get_last_mods());
  } else if (layer_state_is(_QWERTY)) {
    process_magic_key_qwerty(last_keycode, get_last_mods());
  }
}

static void process_arcane_key(uint16_t last_keycode) {
    (void)last_keycode;
  if (layer_state_is(_GRAPHITE)) {
    process_arcane_key_graphite(last_keycode, get_last_mods());
  } else if (layer_state_is(_STURDY)) {
    process_arcane_key_sturdy(last_keycode, get_last_mods());
  } else if (layer_state_is(_COLEMAK)) {
    process_arcane_key_colemak(last_keycode, get_last_mods());
  } else if (layer_state_is(_QWERTY)) {
    process_arcane_key_qwerty(last_keycode, get_last_mods());
  }
}

bool process_repeat_keys(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  uint16_t last_keycode = get_last_keycode();

    switch (keycode) {
        case KC_F24:
            /* SFT_MAGIC tap — if held, QMK handles Shift automatically */
            /* fallthrough */
        case MAGIC:
            if (last_keycode != KC_NO) {
                process_magic_key(last_keycode);
            }
            return false;

        case KC_F23:
            /* ALT_ARCANE tap — if held, QMK handles Alt automatically */
            /* fallthrough */
        case ARCANE:
            if (last_keycode != KC_NO) {
                process_arcane_key(last_keycode);
            }
            return false;

        default:
            return true;
    }
}
