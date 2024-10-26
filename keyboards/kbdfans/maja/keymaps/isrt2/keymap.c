#pragma once

#include QMK_KEYBOARD_H
#include "os_detection.h"

#define __X__	KC_NO
#define _____	KC_TRNS

#include "./user/enums.h"
#include "./keymap.h"
#include "./user/commands/shortcuts.c"
#include "./user/commands/accents.c"
#include "./user/combos.c"
#include "./user/leader.c"

#include "features/layer_lock.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ISRT] = LAYOUT(
		__X__,  __X__,	__X__,	__X__,	__X__,	__X__,  __X__,	/* | */		__X__,		__X__,		__X__,		__X__,		__X__,		__X__,			__X__,	/* | */		TO(QWER),
		__X__,  KC_Y,	CTL_C,	ALT_L,	GUI_M,	KC_K,			/* | */		KC_Z,		GUI_F,		ALT_U,		CTL_COMM,	KC_QUOT,	__X__,	__X__,	__X__,	/* | */		TO(NPD),
		__X__,  L4_I,	L3_S,	L2_R,	L1_T,	KC_G,			/* | */		KC_P,		L1_N,		L2_E,		L3_A,		L4_O,		__X__,	__X__,			/* | */		TO(GAME),
		__X__,  SFT_Q,	KC_V,	KC_W,	KC_D,	KC_J,			/* | */		KC_B,		KC_H,		KC_SLSH,	KC_DOT,		SFT_X,		__X__,	__X__,			/* | */		__X__,
		__X__,  __X__,				   MEH_SPC,	QK_LEAD,		/* | */		KC_BSPC,	KC_ENT,														/* | */		__X__,		__X__,		__X__
	),
	[QWER] = LAYOUT(
		QK_GESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	/* | */		KC_7,		KC_8,	KC_9,	KC_0,		KC_MINS,	KC_EQL,			KC_BSPC,	/* | */			KC_DEL,
		KC_TAB,		KC_Q,	CTL_W,	ALT_E,	GUI_R,	KC_T,			/* | */		KC_Y,		GUI_U,	ALT_I,	CTL_O,		KC_P,		KC_LBRC, KC_RBRC, KC_BSLS,	/* | */			KC_HOME,
		KC_CAPS,	L4_A,	L3_S,	L2_D,	L1_F,	KC_G,			/* | */		KC_H,		L1_J,	L2_K,	L3_L,		L4_SCLN,	KC_QUOT, KC_ENT,			/* | */			KC_END,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,			/* | */		TO(ISRT),	KC_N,	KC_M,	KC_COMM,	KC_DOT,		KC_SLSH, KC_RSFT,			/* | */			KC_UP,
		KC_LCTL,	KC_LGUI,			   MEH_SPC,	KC_LALT,		/* | */		KC_SPC,		KC_RCTL,													/* | */		KC_LEFT,	KC_DOWN,	KC_RGHT
	),
	[GAME] = LAYOUT(
		QK_GESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	/* | */		KC_7,		KC_8,	KC_9,	KC_0,		KC_MINS,	KC_EQL,					KC_BSPC,	/* | */	KC_DEL,
		KC_TAB,		KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,			/* | */		KC_Y,		KC_U,	KC_I,	KC_O,		KC_P,		KC_LBRC,	KC_RBRC,	KC_BSLS,	/* | */	KC_PGUP,
		KC_CAPS,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			/* | */		KC_H,		KC_J,	KC_K,	KC_L,		KC_SCLN,	KC_QUOT,	KC_ENT,					/* | */	KC_PGDN,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,			/* | */		TO(ISRT),	KC_N,	KC_M,	KC_COMM,	KC_DOT,		KC_SLSH,	KC_RSFT,				/* | */	KC_UP,
		KC_LCTL,	KC_LGUI,				KC_SPC,	KC_LALT,		/* | */		KC_RALT,	KC_RCTL,													/* | */		KC_LEFT,	KC_DOWN,   KC_RIGHT
	),
	[GRPT] = LAYOUT(
		__X__,	__X__,  __X__,	__X__,  __X__,  __X__,	__X__,	/* | */		__X__,		__X__,	__X__,	__X__,		__X__,	__X__,              __X__,		/* | */     TO(QWER),
		__X__,	KC_B,   CTL_L,	ALT_D,  GUI_W,  KC_Z,			/* | */		KC_QUOT,	GUI_F,	ALT_O,	CTL_U,		KC_J,	__X__,	    __X__,  __X__,		/* | */     TO(NPD),
		__X__,	L4_N,   L3_R,	L2_T,   L1_S,   KC_G,			/* | */		KC_Y,		L1_H,	L2_A,	L3_E,		L4_I,	__X__,	    __X__,              /* | */     TO(ISRT),
		__X__,	SFT_Q,	KC_X,   KC_M,   KC_C,   KC_V,			/* | */		__X__,		KC_K,	KC_P,	KC_COMM,	KC_DOT,	SFT_SLSH,   __X__,              /* | */     __X__,
		__X__,  __X__,				   MEH_SPC,	QK_LEAD,	    /* | */		KC_BSPC,	KC_ENT,														/* | */		__X__,  __X__,		__X__
	),
	[ACT] = LAYOUT(
		__X__,    	__X__,			__X__,          __X__,                  __X__,                  __X__,  __X__,  /* | */ __X__,				__X__,			    __X__,			    __X__,			__X__,			__X__,		    				__X__,		/* | */			__X__,
		__X__,      QK_GESC,		CKC(CMD_COPY),  CKC(LINE_BACKSPACE),    CKC(WORD_BACKSPACE),    KC_PGUP,		/* | */ KC_HOME,    		CKC(WORD_JUMPL),    CKC(WORD_JUMPR),    RCS(KC_TAB),	LCTL(KC_TAB),	__X__,		    	__X__,		__X__,		/* | */			__X__,
		__X__,      CKC(APP_PREV),  CKC(APP_NEXT),  KC_DEL,			        KC_BSPC,                KC_PGDN,		/* | */ KC_END,             KC_LEFT,		    KC_DOWN,            KC_UP,			KC_RIGHT,		__X__,		    	__X__,					/* | */			__X__,
		__X__,      CKC(CMD_CUT),   CKC(CMD_PASTE), CKC(LINE_DEL),		    CKC(WORD_DEL),          CKC(TAB_CLOSE),	/* | */ CKC(TAB_REOPEN),    CKC(LINE_JUMPL),	CKC(LINE_JUMPR),	CKC(TASK_MNGR),	LYR_LOCK,		__X__,		    	__X__,					/* | */			__X__,
		__X__,      __X__,                                          CKC(LINE_SELECTL),      CKC(WORD_SELECTL),      /* | */ CKC(WORD_SELECTR),  CKC(LINE_SELECTR),																	    					/* | */		__X__,		__X__,		__X__
	),
	[SMBL] = LAYOUT(
		__X__,	__X__,		__X__,		__X__,		__X__,		__X__,	__X__,	/* | */	__X__,	__X__,		__X__,		__X__,		__X__,		__X__,				__X__,	/* | */	__X__,
		__X__,	KC_CAPS,	KC_AT,		KC_HASH,	KC_DOLLAR,	CKC_EURO,		/* | */	__X__,	KC_LBRC,	KC_RBRC,	KC_SCLN,	__X__,		__X__,	__X__,		__X__,	/* | */	__X__,
		__X__,	KC_GRV,		KC_UNDS,	KC_TILDE,	KC_MINS,	KC_PLUS,		/* | */	KC_EQL,	KC_LPRN,	KC_RPRN,	KC_COLN,	__X__,		__X__,	__X__,				/* | */	__X__,
		__X__,	__X__,		__X__,		KC_LT,		KC_GT,		KC_CIRC,		/* | */	__X__,	KC_LCBR,	KC_RCBR,	KC_BSLS,	__X__,		__X__,	__X__,				/* | */	__X__,
		__X__,	__X__,								__X__,		__X__,	        /* | */	__X__,	LYR_LOCK,													/* | */		__X__,		__X__,		__X__
	),
	[ACCT] = LAYOUT(
		__X__,	__X__,		__X__,		__X__,		__X__,		__X__,	__X__,	/* | */	__X__,	__X__,			__X__,			__X__,          __X__,			__X__,				__X__,  	/* | */			__X__,
		__X__,	CW_TOGG,	KC_ASTR,	KC_AMPR,	KC_PERCENT,	CKC(CMD_REDO),	/* | */	__X__,	CKC(E_CIRC),     CKC(U_GRAVE),	CKC(I_CIRC),    CKC(I_TREMA),	__X__,	__X__,		__X__,		/* | */			__X__,
		__X__,	KC_TAB,		KC_DQUO,	KC_EXLM,	KC_QUES,	CKC(CMD_UNDO),	/* | */	__X__,	CKC(E_AIGU),     CKC(E_GRAVE),	CKC(A_GRAVE),   CKC(O_CIRC),    __X__,	__X__,					/* | */			__X__,
		__X__,	TO(GAME),	TO(QWER),	TO(GRPT),	TO(NPD),	__X__,      	/* | */	__X__,	CKC(C_CEDILLE),	CKC(U_CIRC),    CKC(A_CIRC),    __X__,		    __X__,	__X__,					/* | */			__X__,
		__X__,	__X__,								__X__,	 	KC_LSFT,        /* | */	__X__,	LYR_LOCK,																				/* | */		__X__,		__X__,		__X__
	),
	[NPD] = LAYOUT( // multimedia is to
		__X__,		__X__,		__X__,		__X__,		__X__,		__X__,	__X__,	/* | */	__X__,		__X__,		__X__,		__X__,		__X__,		__X__,			__X__,	/* | */	QK_BOOT,
		__X__,		KC_PAST,	KC_P7,		KC_P8,		KC_P9,		KC_PPLS,		/* | */	RGB_TOG,	RGB_MOD,	RGB_RMOD,	RGB_SAI,	RGB_SAD,	__X__,	__X__,	__X__,	/* | */	__X__,
		__X__,		KC_P0,		KC_P4,		KC_P5,		KC_P6,		KC_PENT,		/* | */	KC_PSCR,	RGB_HUI,	RGB_HUD,	RGB_VAI,	RGB_VAD,	__X__,	__X__,			/* | */	__X__,
		__X__,		KC_PSLS,	KC_P1,		KC_P2,		KC_P3,		KC_PMNS,		/* | */	KC_MNXT,	KC_VOLU,	KC_VOLD,	RGB_SPI,	RGB_SPD,	__X__,	__X__,			/* | */	__X__,
		__X__,		__X__,								KC_ENT,		KC_DOT,			/* | */	KC_MPLY,	LYR_LOCK,												/* | */		__X__,		__X__,		__X__
	)
};

// For now I leave this function here. If it increase in size, it will get its own file.
bool process_custom_keycodes(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case CKC_EURO:
      detected_host_os() == OS_MACOS ? send_string(MAC_EUR) : send_string(WIN_EUR);
      return false;
  }
  return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, LYR_LOCK)) {
    return false;
  }
  if (!process_shortcuts(keycode, record)) {
    return false;
  }
  if (!process_accents(keycode, record)) {
    return false;
  }
  if (!process_custom_keycodes(keycode, record)) {
    return false;
  }
  return true;
};

void matrix_scan_user(void) {
  layer_lock_task();

  // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 150) {
      detected_host_os() == OS_MACOS ? unregister_code(KC_LCMD) : unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i < led_max; i++) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
      case ISRT:
        rgb_matrix_set_color(i, RGB_WHITE);
        break;
      case QWER:
        rgb_matrix_set_color(i, RGB_GOLD);
        break;
      case GAME:
        rgb_matrix_set_color(i, RGB_RED);
        break;
      case GRPT:
        rgb_matrix_set_color(i, RGB_GREEN);
        break;
      case ACT:
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
      case SMBL:
        rgb_matrix_set_color(i, RGB_AZURE);
        break;
      case ACCT:
        rgb_matrix_set_color(i, RGB_CYAN);
        break;
      case NPD:
        rgb_matrix_set_color(i, HSV_SPRINGGREEN);
        break;
      default:
        break;
    }
  }
  return false;
};
