#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "combos.h"
#include "magic/magic.h"
#include "magic/cycling_combos.h"
#include "teacher/chord_teacher.h"

#ifndef COMBO_TIMEOUT
#  define COMBO_TIMEOUT 9000 // miliseconds
#endif                       // COMBO_TIMEOUT

static uint16_t idle_timer = 0;

void set_combo_event_timer(void) {
  idle_timer = timer_read() + SELECT_WORD_TIMEOUT;
}


void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    set_combo_event_timer();
    reset_teacher_state(true);
    process_magic_combo_event(combo_index);

    if (mods & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        set_oneshot_mods(MOD_BIT(KC_LSFT)); // Shift mod to capitalize.
    }
    send_string(get_combos_cmds(combo_index));
    if (mods & MOD_MASK_SHIFT) {
      set_mods(mods);
    }
  }
};

void combo_event_task(void) {
  if (get_cycling_combo_state()->is_combo_active && timer_expired(timer_read(), idle_timer)) {
    init_cycling_combos_state();
  }
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  // We need this otherwise there's no way to toggle chords back on
  if (combo_index == GRAPHITE_CONFIG_LAYER) {
    return true;
  }

  if (get_teacher_chord_mode() == TEACHER_CHORD_MODE_OFF) {
    return false;
  }

  return true;
}
