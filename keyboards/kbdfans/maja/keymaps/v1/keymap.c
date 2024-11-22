#include QMK_KEYBOARD_H

#include "layers.h"
#include "helpers/helpers.h"
#include "combos/combos.h"
#include "getreuer/getreuer.h"
#include "magic/magic.h"
#include "shortcuts/shortcuts.h"
#include "symbols/symbols.h"
#include "teacher/chord_teacher.h"
#include "config/config.h"

#define LAY_WRAPPER(...) LAYOUT(__VA_ARGS__)

#define __X__ KC_NO
#define _________NUMBERS_ROW_LEFT___________ __X__, __X__, __X__, __X__, __X__, __X__
#define _________NUMBERS_ROW_RIGHT__________ __X__, __X__, __X__, __X__, __X__, __X__

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT( /* Base */
		QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
	    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
		CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
	    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  TO(_GRAPHITE),   KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
	    KC_LCTL,                 KC_LGUI,  KC_SPC,  KC_LALT,         KC_SPC,        KC_RCTL,                      KC_LEFT, KC_DOWN,   KC_RIGHT
        ),
	[_GRAPHITE] = LAY_WRAPPER(
		QK_GESC,      _________NUMBERS_ROW_LEFT___________,    /* || */        _________NUMBERS_ROW_RIGHT__________, __X__,                   /* || */ QK_BOOT,
	    __X__,        _________GRAPHITE_LEFT_ROW_1________,    /* || */        ________GRAPHITE_RIGHT_ROW_1________, __X__,  __X__, __X__,    /* || */ TO(_BASE),
	    __X__,        _________GRAPHITE_LEFT_ROW_2________,    /* || */        ________GRAPHITE_RIGHT_ROW_2________, __X__,  __X__,           /* || */ __X__,
	    __X__,        _________GRAPHITE_LEFT_ROW_3________,    /* || */ __X__, ________GRAPHITE_RIGHT_ROW_3________, __X__,                   /* || */ __X__,
	    __X__, __X__, _________GRAPHITE_LEFT_THUMBS_______,    /* || */        ________GRAPHITE_RIGHT_THUMBS_______,                   /* || */ __X__, __X__,  __X__
    ),
    [_ACTIONS] = LAY_WRAPPER(
	  QK_GESC,      _________NUMBERS_ROW_LEFT___________,    /* || */        _________NUMBERS_ROW_RIGHT__________, __X__,                   /* || */ QK_BOOT,
	  __X__,        __________ACTIONS_LEFT_ROW_1________,    /* || */        _________ACTIONS_RIGHT_ROW_1________, __X__,  __X__, __X__,    /* || */ TO(_BASE),
	  __X__,        __________ACTIONS_LEFT_ROW_2________,    /* || */        _________ACTIONS_RIGHT_ROW_2________, __X__,  __X__,           /* || */ __X__,
	  __X__,        __________ACTIONS_LEFT_ROW_3________,    /* || */ __X__, _________ACTIONS_RIGHT_ROW_3________, __X__,                   /* || */ __X__,
	  __X__, __X__, __________ACTIONS_LEFT_THUMBS_______,    /* || */        ________GRAPHITE_RIGHT_THUMBS_______,                   /* || */ __X__, __X__,  __X__
    ),
    [_SYMBOLS] = LAY_WRAPPER(
	  QK_GESC,      _________NUMBERS_ROW_LEFT___________,    /* || */        _________NUMBERS_ROW_RIGHT__________, __X__,                   /* || */ QK_BOOT,
	  __X__,        __________SYMBOLS_LEFT_ROW_1________,    /* || */        _________SYMBOLS_RIGHT_ROW_1________, __X__,  __X__, __X__,    /* || */ TO(_BASE),
	  __X__,        __________SYMBOLS_LEFT_ROW_2________,    /* || */        _________SYMBOLS_RIGHT_ROW_2________, __X__,  __X__,           /* || */ __X__,
	  __X__,        __________SYMBOLS_LEFT_ROW_3________,    /* || */ __X__, _________SYMBOLS_RIGHT_ROW_3________, __X__,                   /* || */ __X__,
	  __X__, __X__, __________SYMBOLS_LEFT_THUMBS_______,    /* || */        _________SYMBOLS_RIGHT_THUMBS_______,                   /* || */ __X__, __X__,  __X__
     ),
    [_ACCENTS] = LAY_WRAPPER(
	  QK_GESC,      _________NUMBERS_ROW_LEFT___________,    /* || */        _________NUMBERS_ROW_RIGHT__________, __X__,                   /* || */ QK_BOOT,
	  __X__,        __________ACCENTS_LEFT_ROW_1________,    /* || */        _________ACCENTS_RIGHT_ROW_1________, __X__,  __X__, __X__,    /* || */ TO(_BASE),
	  __X__,        __________ACCENTS_LEFT_ROW_2________,    /* || */        _________ACCENTS_RIGHT_ROW_2________, __X__,  __X__,           /* || */ __X__,
	  __X__,        __________ACCENTS_LEFT_ROW_3________,    /* || */ __X__, _________ACCENTS_RIGHT_ROW_3________, __X__,                   /* || */ __X__,
	  __X__, __X__, __________ACCENTS_LEFT_THUMBS_______,    /* || */        _________ACCENTS_RIGHT_THUMBS_______,                   /* || */ __X__, __X__,  __X__
    ),
    [_NUMPAD_SOUND] = LAY_WRAPPER(
	  QK_GESC,      _________NUMBERS_ROW_LEFT___________,    /* || */        _________NUMBERS_ROW_RIGHT__________, __X__,                   /* || */ QK_BOOT,
	  __X__,        ___________NUMPAD_ROW_1_____________,    /* || */        ____________SOUND_ROW_1_____________, __X__,  __X__, __X__,    /* || */ TO(_BASE),
	  __X__,        ___________NUMPAD_ROW_2_____________,    /* || */        ____________SOUND_ROW_2_____________, __X__,  __X__,           /* || */ __X__,
	  __X__,        ___________NUMPAD_ROW_3_____________,    /* || */ __X__, ____________SOUND_ROW_3_____________, __X__,                   /* || */ __X__,
	  __X__, __X__, ___________NUMPAD_THUMBS____________,    /* || */        ____________SOUND_THUMBS____________,                   /* || */ __X__, __X__,  __X__
    ),
    [_CONFIG] = LAY_WRAPPER(
	  QK_GESC,      _________NUMBERS_ROW_LEFT___________,    /* || */        _________NUMBERS_ROW_RIGHT__________, __X__,                   /* || */ QK_BOOT,
	  __X__,        __________CONFIG_LEFT_ROW_1_________,    /* || */        _________CONFIG_RIGHT_ROW_1________, __X__,  __X__, __X__,    /* || */ TO(_BASE),
	  __X__,        __________CONFIG_LEFT_ROW_1_________,    /* || */        _________CONFIG_RIGHT_ROW_1________, __X__,  __X__,           /* || */ __X__,
	  __X__,        __________CONFIG_LEFT_ROW_1_________,    /* || */ __X__, _________CONFIG_RIGHT_ROW_1________, __X__,                   /* || */ __X__,
	  __X__, __X__, __________CONFIG_LEFT_THUMBS________,    /* || */        _________CONFIG_RIGHT_THUMBS_______,                   /* || */ __X__, __X__,  __X__
    )
 };
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // clang-format off
  if (!process_sentence_case(keycode, record)) { return false; }
//   if (!process_chord_teacher(keycode, record)) { return false; }
  if (!process_magic_key(keycode, record)) { return false; }
  if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }
  if (!process_shortcuts(keycode, record)) { return false; }
  if (!process_symbols(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SEL_WORD)) { return false; }
  if (!process_graphite_keys(keycode, record)) { return false; }
  if (!process_config(keycode, record)) { return false; } // clang-format on

  return true;
};

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  clear_last_message(record);
  return true;
}

void matrix_scan_user(void) {
  layer_lock_task();
  select_word_task();
  alt_tab_task();
  combo_event_task();
  chord_teacher_task();
  sentence_case_task();
};

void keyboard_post_init_user(void) {
  init_alt_tab_state();
  init_cycling_combos_state();
  init_teacher_state();
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case L4_N:
    case L4_I:
    case SFT_SLSH:
    case SFT_Q:
      return TAPPING_TERM + 150;
    case CTL_L:
    case L3_R:
    case CTL_U:
    case L3_E:
      return TAPPING_TERM + 100;
    // case ALT_D:
    // case L2_T:
    // case ALT_O:
    // case L2_A:
    //   return TAPPING_TERM + 100;
    default:
      return TAPPING_TERM;
  }
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i < led_max; i++) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
      case _BASE:
        rgb_matrix_set_color(i, RGB_GOLD);
        break;
      case _GRAPHITE:
        rgb_matrix_set_color(i, RGB_RED);
        break;
      case _CONFIG:
        rgb_matrix_set_color(i, RGB_GREEN);
        break;
      case _ACTIONS:
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
      case _SYMBOLS:
        rgb_matrix_set_color(i, RGB_AZURE);
        break;
      case _ACCENTS:
        rgb_matrix_set_color(i, RGB_CYAN);
        break;
      case _NUMPAD_SOUND:
        rgb_matrix_set_color(i, HSV_SPRINGGREEN);
        break;
      default:
        break;
    }
  }
  return false;
};
