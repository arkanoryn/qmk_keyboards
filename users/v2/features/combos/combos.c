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

#include QMK_KEYBOARD_H
#include "combos.h"
#ifdef CYCLE_COMBO_ENABLE
#    include "features/cycling_combos/cycling_combos.h"
#endif

#ifdef CHORD_TEACHER_ENABLE
#    include "features/chord_teacher/chord_teacher.h"
#endif

#include "farkann_v2.h"
#include "helpers/helpers.h"

#ifdef CHORD_TEACHER_ENABLE
#    include "features/chord_teacher/chord_teacher.h"
#endif

#ifndef COMBO_TIMEOUT
#  define COMBO_TIMEOUT 9000 // miliseconds
#endif                       // COMBO_TIMEOUT

static uint16_t idle_timer     = 0;
const char     *root_combo_str = NULL;

void set_combo_event_timer(void) {
  idle_timer = timer_read() + SELECT_WORD_TIMEOUT;
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
    word_backspace();
#ifdef CYCLE_COMBO_ENABLE
  }
#endif // CYCLE_COMBO_ENABLE
  return;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    const uint8_t mods    = all_mods();
    const bool    shifted = is_shifted();

    switch (combo_index) {
      // DEL_WORD - per layout
      case GRAPHITE_DEL_WORD:
      case QWERTY_DEL_WORD:
      case STURDY_DEL_WORD:
      case COLEMAK_DEL_WORD:
        process_del_word();
        break;

      // SFT_ENT - per layout
      case GRAPHITE_SFT_ENT:
      case QWERTY_SFT_ENT:
      case STURDY_SFT_ENT:
      case COLEMAK_SFT_ENT:
        add_mods(MOD_MASK_SHIFT);
        tap_code16(KC_ENT);
        set_mods(mods);
        break;

      // C_ENT - per layout
      case GRAPHITE_C_ENT:
      case QWERTY_C_ENT:
      case STURDY_C_ENT:
      case COLEMAK_C_ENT:
        (detected_host_os() == OS_MACOS ? add_mods(MOD_MASK_GUI) : add_mods(MOD_MASK_CTRL));
        tap_code16(KC_ENT);
        set_mods(mods);
        break;

      // CONFIG_LAYER - per layout
      case GRAPHITE_CONFIG_LAYER:
      case QWERTY_CONFIG_LAYER:
      case STURDY_CONFIG_LAYER:
      case COLEMAK_CONFIG_LAYER:
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
          set_oneshot_mods(MOD_BIT(KC_LSFT)); // Shift mod to capitalize.
        }
        send_string(root_combo_str);
        if (shifted) {
          set_mods(mods);
        }
    }
  }
};

void combo_event_task(void) {
#ifdef CYCLE_COMBO_ENABLE
  if (get_cycling_combo_state()->is_combo_active && timer_expired(timer_read(), idle_timer)) {
    init_cycling_combos_state();
  }
#endif // CYCLE_COMBO_ENABLE
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Always allow config layer combos (needed to toggle chords back on)
    // As we would no longer be able to access the Config Layer without it
    if (combo_index == GRAPHITE_CONFIG_LAYER ||
        combo_index == QWERTY_CONFIG_LAYER ||
        combo_index == STURDY_CONFIG_LAYER ||
        combo_index == COLEMAK_CONFIG_LAYER) {
        return true;
    }

    /* Only fire combos when their layout layer is active */
    if (combo_index >= _FIRST_GRAPHITE_COMBO && combo_index <= _LAST_GRAPHITE_COMBO) {
        return layer_state_is(_GRAPHITE);
    }
    if (combo_index >= _FIRST_QWERTY_COMBO && combo_index <= _LAST_QWERTY_COMBO) {
        return layer_state_is(_QWERTY);
    }
    if (combo_index >= _FIRST_STURDY_COMBO && combo_index <= _LAST_STURDY_COMBO) {
        return layer_state_is(_STURDY);
    }
    if (combo_index >= _FIRST_COLEMAK_COMBO && combo_index <= _LAST_COLEMAK_COMBO) {
        return layer_state_is(_COLEMAK);
    }

#ifdef CHORD_TEACHER_ENABLE
    if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) { return false; }
#endif

    return false;
}

void word_backspace() {
  switch (detected_host_os())
  {
    case OS_MACOS:
      send_string(MAC_WORD_BACKSPACE);
      break;
    case OS_WINDOWS:
      send_string(WIN_WORD_BACKSPACE);
      break;
    case OS_LINUX:
      send_string(LINUX_WORD_BACKSPACE);
      break;
    case OS_UNSURE:
    case OS_IOS:
      send_string(SS_TAP(X_BACKSPACE));
      break;
  }
}
