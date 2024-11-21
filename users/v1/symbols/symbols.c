#include QMK_KEYBOARD_H
#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "ark_v1.h" // TODO: should be KEYMAP_MAIN_H
#include "symbols.h"

bool process_symbols(uint16_t keycode, keyrecord_t *record) {
  // clang-format off
  if (!record->event.pressed) { return true; }
  // clang-format on

  switch (keycode) {
    case CKC(_FIRST_SYMBOL_ID)... CKC(_LAST_ACCENT_IGNORE) - 1:
      return process_accents(keycode - CKC(0));
    case CKC(EURO):
      detected_host_os() == OS_MACOS ? send_string(MAC_EUR) : send_string(WIN_EUR);
      return false;
  }
  return true;
};
