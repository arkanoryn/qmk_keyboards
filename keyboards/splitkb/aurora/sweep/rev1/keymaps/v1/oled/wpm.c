#ifdef OLED_ENABLE
#  include QMK_KEYBOARD_H
#  include "ark_v1.h"

bool wpm_keycode_user(uint16_t keycode) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) // clang-format off
  || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
  || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) { // clang-format on
    keycode = keycode & 0xFF;
  } else if (keycode > 0xFF) {
    keycode = 0;
  }

  switch (keycode) {
    case KC_A ... KC_0:
    case KC_TAB ... KC_NUBS:
    case MAGIC:
      // case REP:
      // case NEWSENT:
      return true;
  }

  return false;
}

void render_wpm(void) {
  uint8_t n = get_current_wpm();
  char    render_str[4];

  render_str[3] = '\0';
  render_str[2] = '0' + n % 10;
  render_str[1] = '0' + (n /= 10) % 10;
  render_str[0] = '0' + n / 10;

  oled_write(render_str, false);
}
#endif // OLED_ENABLE
