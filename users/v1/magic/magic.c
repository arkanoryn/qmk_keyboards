/*
**
** TODO:
**
*/
#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "magic.h"
#include "combos/combos.h"
#include "cycling_combos.h"
#include "generated/cycles.h"
#include "repeat.h"
#include "teacher/chord_teacher.h"

#ifndef CYCLE_COMBO_ENABLE
cycling_combos_state_t* get_cycling_combo_state(void) {
  return NULL;
};
void init_cycling_combos_state(void) {};
#endif // CYCLE_COMBO_ENABLE

void process_magic_combo_event(uint16_t combo_index) {
#ifdef CYCLE_COMBO_ENABLE
  init_cycling_combos_state();

  cycling_combos_state_t* combos_state = get_cycling_combo_state();
  const uint8_t           mods         = get_mods() | get_oneshot_mods() | get_weak_mods();

  combos_state->is_combo_active = true;
  combos_state->shift_enabled   = mods & MOD_MASK_SHIFT;
  combos_state->is_cyclable     = true;

  const cycling_combos_e cycle_id = match_combo_index_with_cycling_combo(combo_index);

  switch (cycle_id) {
    case 0 ...(_LAST_CYCLING_COMBO - 1):
      combos_state->last_cycle_combo_id = cycle_id;
      break;
    default:
      combos_state->is_cyclable = false;
  }
#endif // CYCLE_COMBO_ENABLE
};

bool process_magic_key(uint16_t keycode, keyrecord_t* record) {
  if (!record->event.pressed) {
    return true;
  }

#ifdef CYCLE_COMBO_ENABLE
  cycling_combos_state_t* combos_state = get_cycling_combo_state();
#endif // CYCLE_COMBO_ENABLE

  switch (keycode) {
    case MAGIC:
#ifdef CYCLE_COMBO_ENABLE
      if (record->event.pressed && combos_state->is_cyclable) {
        set_combo_event_timer();
        cycle();
        return false;
      } else if (record->event.pressed) {
#else
      if (record->event.pressed) {
#endif // CYCLE_COMBO_ENABLE
        process_repeat_event(get_last_keycode(), get_last_mods());
        return false;
      }
      // we want to ignore the reset of the combo (below) if one of the SHIFT key is held
    case SFT_Q:
    case SFT_SLSH:
      if (record->tap.count == 0) {
        return true;
      }
  }

  init_cycling_combos_state();
  return true;
}
