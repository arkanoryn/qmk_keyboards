#include QMK_KEYBOARD_H

#include "layers.h"
#include "helpers/helpers.h"
#include "shortcuts/shortcuts.h"

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
       [_SYMBOLS] = LAYOUT( /* Base */
		QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
	    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
		CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
	    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  MO(1),   KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
	    KC_LCTL,                 KC_LGUI,  KC_LALT,      KC_SPC,         KC_RALT,        KC_RCTL,                      KC_LEFT, KC_DOWN,   KC_RIGHT
           ),
       [_ACCENTS] = LAYOUT( /* Base */
		QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
	    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
		CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
	    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  MO(1),   KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
	    KC_LCTL,                 KC_LGUI,  KC_LALT,      KC_SPC,         KC_RALT,        KC_RCTL,                      KC_LEFT, KC_DOWN,   KC_RIGHT
           ),
       [_NUMPAD_SOUND] = LAYOUT( /* Base */
		QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
	    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
		CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
	    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  MO(1),   KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
	    KC_LCTL,                 KC_LGUI,  KC_LALT,      KC_SPC,         KC_RALT,        KC_RCTL,                      KC_LEFT, KC_DOWN,   KC_RIGHT
           ),
       [_CONFIG] = LAYOUT( /* Base */
		QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
	    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
		CTL_T(KC_CAPS),KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
	    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  MO(1),   KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
	    KC_LCTL,                 KC_LGUI,  KC_LALT,      KC_SPC,         KC_RALT,        KC_RCTL,                      KC_LEFT, KC_DOWN,   KC_RIGHT
       )
 };
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // clang-format off
//   if (!process_sentence_case(keycode, record)) { return false; }
//   if (!process_chord_teacher(keycode, record)) { return false; }
//   if (!process_magic_key(keycode, record)) { return false; }
//   if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }
  if (!process_shortcuts(keycode, record)) { return false; }
//   if (!process_symbols(keycode, record)) { return false; }
//   if (!process_select_word(keycode, record, SEL_WORD)) { return false; }
//   if (!process_oled_displays(keycode, record)) { return false; }
//   if (!process_graphite_keys(keycode, record)) { return false; }
//   if (!process_config(keycode, record)) { return false; } // clang-format on

  return true;
};

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  clear_last_message(record);
  return true;
}

void matrix_scan_user(void) {
  //   layer_lock_task();
  //   select_word_task();
  alt_tab_task();
  //   combo_event_task();
  //   chord_teacher_task();
  //   sentence_case_task();
};

void keyboard_post_init_user(void) {
  init_alt_tab_state();
  //   init_cycling_combos_state();
  //   init_teacher_state();
  //   init_oled_state();
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
}
