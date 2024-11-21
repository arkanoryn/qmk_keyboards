#include QMK_KEYBOARD_H
#include "helpers.h"

const uint8_t all_mods(void) {
  return (get_mods() | get_oneshot_mods() | get_weak_mods());
};

bool is_shifted(void) {
  return (all_mods() & MOD_MASK_SHIFT);
};

void disable_shift(void) {
  del_mods(MOD_MASK_SHIFT);
  del_oneshot_mods(MOD_MASK_SHIFT);
}
