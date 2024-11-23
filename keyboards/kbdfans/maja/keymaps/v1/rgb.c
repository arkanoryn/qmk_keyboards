#include QMK_KEYBOARD_H

#include "layers.h"

void set_layer_keys_colors(uint8_t r, uint8_t g, uint8_t b) {
  rgb_matrix_set_color(48, r, g, b);
  rgb_matrix_set_color(47, r, g, b);
  rgb_matrix_set_color(49, r, g, b);
  rgb_matrix_set_color(50, r, g, b);
  rgb_matrix_set_color(51, r, g, b);
  rgb_matrix_set_color(52, r, g, b);
}

void set_layer_colors(void) {
  switch (get_highest_layer(layer_state | default_layer_state)) {
    case _BASE:
      set_layer_keys_colors(RGB_GOLD);
      break;
    case _GRAPHITE:
      set_layer_keys_colors(RGB_WHITE);
      break;
    case _CONFIG:
      set_layer_keys_colors(RGB_GREEN);
      break;
    case _ACTIONS:
      set_layer_keys_colors(RGB_BLUE);
      break;
    case _SYMBOLS:
      set_layer_keys_colors(RGB_AZURE);
      break;
    case _ACCENTS:
      set_layer_keys_colors(RGB_CYAN);
      break;
    case _NUMPAD_SOUND:
      set_layer_keys_colors(RGB_SPRINGGREEN);
      break;
  }
};

void set_keys(uint8_t led_min, uint8_t led_max) {
  HSV hsv  = rgb_matrix_config.hsv;
  HSV hsv2 = hsv;
  RGB rgb  = hsv_to_rgb(hsv);

  for (uint8_t i = led_min; i < led_max; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
      hsv2 = hsv;
      hsv2.h += rgb_matrix_config.speed;
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    } else if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x01 == LED_FLAG_MODIFIER
      hsv2 = hsv;
      hsv2.h += rgb_matrix_config.speed % 25;
      rgb = hsv_to_rgb(hsv2);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    } else if (HAS_FLAGS(g_led_config.flags[i], 0x03)) { // 0x01 == LED_FLAG_MODIFIER
      hsv2 = hsv;
      hsv2.h += rgb_matrix_config.speed % 10;
      rgb = hsv_to_rgb(hsv2);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    } else if (HAS_FLAGS(g_led_config.flags[i], 0x05)) { // 0x01 == LED_FLAG_MODIFIER
      hsv2 = hsv;
      hsv2.h += rgb_matrix_config.speed % 180;
      rgb = hsv_to_rgb(hsv2);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  set_keys(led_min, led_max);
  set_layer_colors();
  return true;
};
