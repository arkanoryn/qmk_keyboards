/*
** contains the helper functions dedicated to the Graphite Layer
*/
#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "helpers.h"

bool process_graphite_keys(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  const bool shift_enabled = is_shifted();

  switch (keycode) {
    case DOT_EXLM:
      shift_enabled ? tap_code16(KC_EXLM) : tap_code16(KC_DOT);
      return false;
    case QUOT_UNDS:
      shift_enabled ? tap_code16(KC_UNDS) : tap_code16(KC_QUOT);
      return false;
  }
  return true;
};
