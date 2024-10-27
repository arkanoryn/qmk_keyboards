#include QMK_KEYBOARD_H
#include "os_detection.h"

#include "commands.h"

void process_accent(uint16_t accent_str, uint8_t letter_code) {
  const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

  if (mods & MOD_MASK_SHIFT) {
    del_mods(MOD_MASK_SHIFT);
    tap_code16(accent_str);
    add_mods(MOD_MASK_SHIFT);
  } else {
    tap_code16(accent_str);
  }
  tap_code16(letter_code);
};

bool send_accent(e_accents_id id) {
  switch (id) {
    case E_CIRC:
      process_accent(CIRCONFLEXE, KC_E);
      return false;
    case E_AIGU:
      process_accent(AIGU, KC_E);
      return false;
    case U_GRAVE:
      process_accent(GRAVE, KC_U);
      return false;
    case E_GRAVE:
      process_accent(GRAVE, KC_E);
      return false;
    case U_CIRC:
      process_accent(CIRCONFLEXE, KC_U);
      return false;
    case I_CIRC:
      process_accent(CIRCONFLEXE, KC_I);
      return false;
    case A_GRAVE:
      process_accent(GRAVE, KC_A);
      return false;
    case A_CIRC:
      process_accent(CIRCONFLEXE, KC_A);
      return false;
    case I_TREMA:
      process_accent(TREMA, KC_I);
      return false;
    case O_CIRC:
      process_accent(CIRCONFLEXE, KC_O);
      return false;
    case C_CEDILLE:
      if (detected_host_os() == OS_MACOS) {
        tap_code16(A(KC_C));
      } else {
        process_accent(WIN_CEDILLE, KC_C);
      }
      return false;
    default:
      return true;
  };
  return true;
};

bool process_accents(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case CKC(FIRST_ACCENT + 1)... CKC(LAST_ACCENT) - 1:
      return send_accent(keycode - CKC(0));
  }
  return true;
};
