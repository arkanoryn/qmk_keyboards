/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

void process_magic_key(uint16_t last_keycode) {
  if (layer_state_is(_GRAPHITE)) {
    process_magic_key_graphite(last_keycode, get_last_mods());
  }
}

void process_arcane_key(uint16_t last_keycode) {
  if (layer_state_is(_GRAPHITE)) {
    process_arcane_key_graphite(last_keycode, get_last_mods());
  }
}

bool process_repeat_keys(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  uint16_t last_keycode = get_last_keycode();

  switch (keycode) {
    case SFT_MAGIC:
      /* if the MAGIC key is held, we don't want to repeat but use the */
      /* mod instead */
      if (record->tap.count == 0) {
        return true;
      }

    case MAGIC:
      if (record->event.pressed) {
        if (last_keycode != KC_NO) {
          process_magic_key(last_keycode);
        }
        return false; /* Don't process further */
      }

    case ALT_ARCANE:
      /* if the ARCANE key is held, we don't want to repeat but use the */
      /* mod instead */
      if (record->tap.count == 0) {
        return true;
      }

    case ARCANE:
            if (record->event.pressed) {
                if (last_keycode != KC_NO) {
                    process_arcane_key(last_keycode);
                }
                return false; // Don't process further
            }

      return false; /* Don't process further */

    default:
      return true;
  }

  return true; /* Continue processing other features */
}
