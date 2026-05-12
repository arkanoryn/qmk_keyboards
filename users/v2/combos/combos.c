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

#include QMK_KEYBOARD_H
#include "farkann_v2.h"
#include "layers.h"
#include "helpers/helpers.h"
#include "combos.h"
#include "features/actions/actions.h"
#include "features/repeat/repeat.h"

// Optional dependencies - cycling combos support
#ifdef CYCLE_COMBO_ENABLE
#  include "features/cycling_combos/cycling_combos.h"
#endif

// Optional dependencies - chord teacher support
#ifdef CHORD_TEACHER_ENABLE
#  include "features/chord_teacher/chord_teacher.h"
#endif

#ifndef CYCLE_COMBO_TIMEOUT
#  define CYCLE_COMBO_TIMEOUT 9000 // milliseconds - time window for cycling through combo variants
#endif

static uint16_t idle_timer = 0;
const char     *root_combo_str = NULL;

void set_combo_event_timer(void) {
  idle_timer = timer_read() + CYCLE_COMBO_TIMEOUT;
}

void process_del_word(void) {
  disable_shift();

#ifdef CHORD_TEACHER_ENABLE
  if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_CORRECTIVE) {
    reset_teacher_state(true);
  }
#endif // CHORD_TEACHER_ENABLE

#ifdef CYCLE_COMBO_ENABLE
  if (get_cycling_combo_state()->is_combo_active) {
    if (get_cycling_combo_state()->is_cyclable) {
      backspace_current_output();
    } else {
      const size_t str_len = strlen(root_combo_str);
      for (int i = 0; i < str_len; ++i) {
        tap_code16(KC_BSPC);
      }
    }
  } else {
#endif // CYCLE_COMBO_ENABLE
    send_action(WORD_BACKSPACE);
#ifdef CYCLE_COMBO_ENABLE
  }
#endif // CYCLE_COMBO_ENABLE
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    const uint8_t mods = all_mods();
    const bool    shifted = is_shifted();

    switch (combo_index) {
      case GRAPHITE_DEL_WORD:
        process_del_word();
        break;
      case GRAPHITE_SFT_ENT:
        add_mods(MOD_MASK_SHIFT);
        tap_code16(KC_ENT);
        set_mods(mods);
        break;
      case GRAPHITE_C_ENT:
        (detected_host_os() == OS_MACOS ? add_mods(MOD_MASK_GUI) : add_mods(MOD_MASK_CTRL));
        tap_code16(KC_ENT);
        set_mods(mods);
        break;
      case GRAPHITE_CONFIG_LAYER:
        layer_on(_CONFIG);
        break;
      default:
        root_combo_str = get_combos_cmds(combo_index);
        set_combo_event_timer();

#ifdef CHORD_TEACHER_ENABLE
        reset_teacher_state(true);
#endif // CHORD_TEACHER_ENABLE

#ifdef CYCLE_COMBO_ENABLE
        process_magic_combo_event(combo_index);
#endif // CYCLE_COMBO_ENABLE

        if (shifted) {
          del_mods(MOD_MASK_SHIFT);
          set_oneshot_mods(MOD_BIT(KC_LSFT));
        }
        send_string(root_combo_str);
        if (shifted) {
          set_mods(mods);
        }
    }
  }
}

void combo_event_task(void) {
#ifdef CYCLE_COMBO_ENABLE
  if (get_cycling_combo_state()->is_combo_active && timer_expired(timer_read(), idle_timer)) {
    init_cycling_combos_state();
  }
#endif // CYCLE_COMBO_ENABLE
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  // Always allow config layer combo (needed to toggle chords back on)
  // As we would no longer be able to access the Config Layer without it
  if (combo_index == GRAPHITE_CONFIG_LAYER) return true;

#ifdef CHORD_TEACHER_ENABLE
  if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) return false;
#endif // CHORD_TEACHER_ENABLE

  return true;
}
