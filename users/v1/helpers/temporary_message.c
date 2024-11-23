#include QMK_KEYBOARD_H
#include "quantum.h"
#include "helpers.h"

uint8_t last_message_length = 0;

void send_temporary_string(const char *str) {
  last_message_length += strlen(str);
  send_string(str);
};

void clear_last_message(keyrecord_t *record) {
  if (!record->event.pressed || last_message_length == 0) {
    return;
  }

  do {
    tap_code16(KC_BSPC);
  } while (--last_message_length);
};
