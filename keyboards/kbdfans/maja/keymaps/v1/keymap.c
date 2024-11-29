//  '##::::'##::::'###::::::::::'##::::'###::::
//   ###::'###:::'## ##::::::::: ##:::'## ##:::
//   ####'####::'##:. ##:::::::: ##::'##:. ##::
//   ## ### ##:'##:::. ##::::::: ##:'##:::. ##:
//   ##. #: ##: #########:'##::: ##: #########:
//   ##:.:: ##: ##.... ##: ##::: ##: ##.... ##:
//   ##:::: ##: ##:::: ##:. ######:: ##:::: ##:
//  ..:::::..::..:::::..:::......:::..:::::..::
//  maja/v1/keymap.c
#include QMK_KEYBOARD_H

#include "layers.h"
#include "config/config.h"
#include "getreuer/getreuer.h"
#include "helpers/helpers.h"
#include "magic/magic.h"
#include "shortcuts/shortcuts.h"
#include "symbols/symbols.h"
#include "tap_dance/tap_dance.h"
#include "jump_cursor/jump.h"

// We need to include this .c file here, because we can only skip 1 `INTROSPECTION_KEYMAP_C` file.
#include "tap_dance/tap_dance_extract.c"

#define LAY_WRAPPER(...) LAYOUT(__VA_ARGS__)

#define __X__ KC_NO
#define GRPT TO(_GRAPHITE)
#define BASE TO(_BASE)
#define _________NUMBERS_ROW_LEFT___________ __X__, __X__, __X__, __X__, __X__, __X__
#define _________NUMBERS_ROW_RIGHT__________ __X__, __X__, __X__, __X__, __X__, __X__

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAY_WRAPPER( /* Base */
		QK_GESC,	__________QWERTY_LEFT_NUMBERS_______,	/* || */		_________QWERTY_RIGHT_NUMBERS_______,					KC_BSPC,	/* || */	KC_DEL,
	    KC_TAB,		__________QWERTY_LEFT_ROW_1_________,	/* || */		_________QWERTY_RIGHT_ROW_1_________,	KC_LBRC,KC_RBRC,KC_BSLS,	/* || */	KC_PGUP,
		KC_CAPS,	__________QWERTY_LEFT_ROW_2_________,	/* || */		_________QWERTY_RIGHT_ROW_2_________,	KC_QUOT,		KC_ENT,		/* || */	KC_PGDN,
	    KC_LSFT,	__________QWERTY_LEFT_ROW_3_________,	/* || */ GRPT,	_________QWERTY_RIGHT_ROW_3_________,	KC_RSFT,					/* || */	KC_UP,
	    KC_LCTL, KC_LGUI,  _____QWERTY_LEFT_THUMBS______,	/* || */		_________QWERTY_RIGHT_THUMBS________,					/* || */	KC_LEFT, KC_DOWN,   KC_RIGHT
        ),
	[_GAME] = LAY_WRAPPER( /* Base */
		QK_GESC,	____DEFAULT_QWERTY_LEFT_NUMBERS_____,	/* || */		____DEFAULT_QWERTY_RIGHT_NUMBERS____,					KC_BSPC,	/* || */	KC_DEL,
	    KC_TAB,		____DEFAULT_QWERTY_LEFT_ROW_1_______,	/* || */		____DEFAULT_QWERTY_RIGHT_ROW_1______,	KC_LBRC,KC_RBRC,KC_BSLS,	/* || */	KC_PGUP,
		KC_CAPS,	____DEFAULT_QWERTY_LEFT_ROW_2_______,	/* || */		____DEFAULT_QWERTY_RIGHT_ROW_2______,	KC_QUOT,		KC_ENT,		/* || */	KC_PGDN,
	    KC_LSFT,	_____DEFAULT_QWERTY_LEFT_ROW_3______,	/* || */ BASE,	____DEFAULT_QWERTY_RIGHT_ROW_3______,	KC_RSFT,					/* || */	KC_UP,
	    KC_LCTL, KC_LGUI,  __DEFAULT_QWERTY_LEFT_THUMBS_,	/* || */		____DEFAULT_QWERTY_RIGHT_THUMBS_____,					/* || */	KC_LEFT, KC_DOWN,   KC_RIGHT
        ),
	[_GRAPHITE] = LAY_WRAPPER(
		QK_GESC,	_________NUMBERS_ROW_LEFT___________,	/* || */		_________NUMBERS_ROW_RIGHT__________, __X__,					/* || */	TG(_CONFIG),
	    KC_TAB,		_________GRAPHITE_LEFT_ROW_1________,	/* || */		________GRAPHITE_RIGHT_ROW_1________, __X__,	__X__, __X__,	/* || */	TO(_BASE),
	    __X__,		_________GRAPHITE_LEFT_ROW_2________,	/* || */		________GRAPHITE_RIGHT_ROW_2________, __X__,	__X__,			/* || */	QK_BOOT,
	    KC_LSFT,	_________GRAPHITE_LEFT_ROW_3________,	/* || */ BASE,	________GRAPHITE_RIGHT_ROW_3________, KC_RSFT,					/* || */	__X__,
	    __X__, __X__, _________GRAPHITE_LEFT_THUMBS_______,	/* || */		________GRAPHITE_RIGHT_THUMBS_______,					/* || */	__X__,	__X__,	__X__
    ),
    [_ACTIONS] = LAY_WRAPPER(
	  QK_GESC,		_________NUMBERS_ROW_LEFT___________,	/* || */		_________NUMBERS_ROW_RIGHT__________, __X__,					/* || */	__X__,
	  __X__,		__________ACTIONS_LEFT_ROW_1________,	/* || */		_________ACTIONS_RIGHT_ROW_1________, __X__,	__X__, __X__,	/* || */	TO(_BASE),
	  __X__,		__________ACTIONS_LEFT_ROW_2________,	/* || */		_________ACTIONS_RIGHT_ROW_2________, __X__,	__X__,			/* || */	__X__,
	  __X__,		__________ACTIONS_LEFT_ROW_3________,	/* || */ __X__,	_________ACTIONS_RIGHT_ROW_3________, __X__,					/* || */	__X__,
	  __X__, __X__, __________ACTIONS_LEFT_THUMBS_______,	/* || */		_________ACTIONS_RIGHT_THUMBS_______,					/* || */	__X__,	__X__,	__X__
    ),
    [_SYMBOLS] = LAY_WRAPPER(
	  QK_GESC,		_________NUMBERS_ROW_LEFT___________,	/* || */		_________NUMBERS_ROW_RIGHT__________, __X__,					/* || */	__X__,
	  __X__,		__________SYMBOLS_LEFT_ROW_1________,	/* || */		_________SYMBOLS_RIGHT_ROW_1________, __X__,	__X__, __X__,	/* || */	TO(_BASE),
	  __X__,		__________SYMBOLS_LEFT_ROW_2________,	/* || */		_________SYMBOLS_RIGHT_ROW_2________, __X__,	__X__,			/* || */	__X__,
	  __X__,		__________SYMBOLS_LEFT_ROW_3________,	/* || */ __X__,	_________SYMBOLS_RIGHT_ROW_3________, __X__,					/* || */	__X__,
	  __X__, __X__, __________SYMBOLS_LEFT_THUMBS_______,	/* || */		_________SYMBOLS_RIGHT_THUMBS_______,					/* || */	__X__,	__X__,	__X__
     ),
    [_ACCENTS] = LAY_WRAPPER(
	  QK_GESC,		_________NUMBERS_ROW_LEFT___________,	/* || */		_________NUMBERS_ROW_RIGHT__________, __X__,					/* || */	__X__,
	  __X__,		__________ACCENTS_LEFT_ROW_1________,	/* || */		_________ACCENTS_RIGHT_ROW_1________, __X__,	__X__, __X__,	/* || */	TO(_BASE),
	  __X__,		__________ACCENTS_LEFT_ROW_2________,	/* || */		_________ACCENTS_RIGHT_ROW_2________, __X__,	__X__,			/* || */	__X__,
	  __X__,		__________ACCENTS_LEFT_ROW_3________,	/* || */ __X__,	_________ACCENTS_RIGHT_ROW_3________, __X__,					/* || */	__X__,
	  __X__, __X__, __________ACCENTS_LEFT_THUMBS_______,	/* || */		_________ACCENTS_RIGHT_THUMBS_______,					/* || */	__X__,	__X__,	__X__
    ),
    [_NUMPAD_SOUND] = LAY_WRAPPER(
	  QK_GESC,		_________NUMBERS_ROW_LEFT___________,	/* || */		_________NUMBERS_ROW_RIGHT__________, __X__,					/* || */	__X__,
	  __X__,		___________NUMPAD_ROW_1_____________,	/* || */		____________SOUND_ROW_1_____________, __X__,	__X__, __X__,	/* || */	TO(_BASE),
	  __X__,		___________NUMPAD_ROW_2_____________,	/* || */		____________SOUND_ROW_2_____________, __X__,	__X__,			/* || */	__X__,
	  __X__,		___________NUMPAD_ROW_3_____________,	/* || */ __X__,	____________SOUND_ROW_3_____________, __X__,					/* || */	__X__,
	  __X__, __X__, ___________NUMPAD_THUMBS____________,	/* || */		____________SOUND_THUMBS____________,					/* || */	__X__,	__X__,	__X__
    ),
    [_CONFIG] = LAY_WRAPPER(
	  TO(_BASE),	_________NUMBERS_ROW_LEFT___________,	/* || */		_________NUMBERS_ROW_RIGHT__________, __X__,					/* || */	TO(_GAME),
	  __X__,		__________CONFIG_LEFT_ROW_1_________,	/* || */		_________CONFIG_RIGHT_ROW_1________, __X__,	__X__, __X__,		/* || */	__X__,
	  __X__,		__________CONFIG_LEFT_ROW_2_________,	/* || */		_________CONFIG_RIGHT_ROW_2________, __X__,	__X__,				/* || */	__X__,
	  __X__,		__________CONFIG_LEFT_ROW_3_________,	/* || */ __X__,	_________CONFIG_RIGHT_ROW_3________, __X__,						/* || */	__X__,
	  __X__, __X__, __________CONFIG_LEFT_THUMBS________,	/* || */		_________CONFIG_RIGHT_THUMBS_______,					/* || */	__X__,	__X__,	__X__
    )
 };
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) { // clang-format off
  if (!process_selection(keycode, record)) { return false; }
  if (!process_layer_lock(keycode, record, LAYER_LOCK)) { return false; }
  if (!process_magic_key(keycode, record)) { return false; }
  if (!process_shortcuts(keycode, record)) { return false; }
  if (!process_symbols(keycode, record)) { return false; }
  if (!process_graphite_keys(keycode, record)) { return false; }
  if (!process_config(keycode, record)) { return false; }
  if (!process_jump_cursor(keycode, record)) { return false; } // clang-format on
  return true;
};

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  clear_last_message(record);
  return true;
}

void matrix_scan_user(void) {
  layer_lock_task();
  alt_tab_task();
};

void keyboard_post_init_user(void) {
  init_alt_tab_state();
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case L4_A:
    case L4_SCLN:
    case L4_N:
    case L4_I:
    case SFT_SLSH:
    case SFT_Q:
      return TAPPING_TERM + 150;
    case CTL_L:
    case CTL_U:
    case L3_R:
    case L3_E:
    case L3_S:
    case L3_L:
      return TAPPING_TERM + 100;
    case ALT_D:
    case L2_T:
    case ALT_O:
    case L2_A:
    case L2_D:
    case L2_K:
      return TAPPING_TERM + 100;
    case TD(TD_SELECTION_BACKWARD):
    case TD(TD_SELECTION_FORWARD):
    case TD(TD_JUMP_BACKWARD):
    case TD(TD_JUMP_FORWARD):
      return 100;
    default:
      return TAPPING_TERM;
  }
  return TAPPING_TERM;
};
