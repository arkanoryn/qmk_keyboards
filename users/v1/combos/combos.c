#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "combos.h"
#include "magic/magic.h"
#include "magic/cycling_combos.h"

#ifndef COMBO_TIMEOUT
#  define COMBO_TIMEOUT 9000 // miliseconds
#endif                       // COMBO_TIMEOUT

static uint16_t idle_timer = 0;

void set_combo_event_timer(void) {
  idle_timer = timer_read() + SELECT_WORD_TIMEOUT;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (pressed) {
    set_combo_event_timer();
    process_magic_combo_event(combo_index);
  }
};

void combo_event_task(void) {
  if (get_cycling_combo_state()->is_combo_active && timer_expired(timer_read(), idle_timer)) {
    init_cycling_combos_state();
  }
};
