#include QMK_KEYBOARD_H

#define KEYMAP_MAIN_H "ark_v1.h"

#include KEYMAP_MAIN_H
#include "shortcuts/shortcuts.h"
#include "combos/combos.h"
#include "symbols/symbols.h"
#include "magic/magic.h"
#include "magic/cycling_combos.h"
#include "getreuer/layer_lock/layer_lock.h"

#include "getreuer/select_word/select_word.h"

#define __X__	KC_NO
#define _____	KC_TRNS

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  ,----------+----------+----------+----------+----------.                            ,----------+----------+----------+----------+----------.
//  |     Y    | C / CLT  | L / ALT  |  M / GUI |     K    |                            |     Z    | F / GUI  | U / ALT  | ,< / CLT |    ' "   |
//  +----------+----------+----------+----------+----------+                            +----------+----------+----------+----------+----------+
//  |  I / L4  |  S / L3  |  R / L2  |  T / L1  |     G    |                            |  P / L1  |  N / L2  |  E / L3  |  A / L4  |     O    |
//  +----------+----------+----------+----------+----------+                            +----------+----------+----------+----------+----------+
//  | Q / SFT  |     V    |     W    |     D    |     J    |                            |     B    |     H    |    / ?   |    . >   | X / SFT  |
//  +----------+----------+----------+----------+----------+-----------.       ,--------+----------+----------+----------+----------+----------+
//                                               | MEH / SPC |  MAGIC  |       |  Bksp  |    ENT   |
//                                               `-----------+---------'       `--------+----------'
  [GRPT] = LAYOUT(
  	KC_B,	CTL_L,	ALT_D,  GUI_W,  KC_Z,			/* | */			KC_QUOT,	GUI_F,		ALT_O,		CTL_U,		KC_J,
  	L4_N,	L3_R,	L2_T,	L1_S,	KC_G,			/* | */			KC_Y,		L1_H,		L2_A,		L3_E,		L4_I,
  	SFT_Q,	KC_X,	KC_M,	KC_C,	KC_V,			/* | */			KC_K,		KC_P,		KC_COMM,	KC_DOT,	SFT_SLSH,
  							MEH_SPC,		MAGIC,	/* | */		KC_BSPC,	KC_ENT
  ),
  [ISRT] = LAYOUT(
	KC_Y,	CTL_C,	ALT_L,	GUI_M,	KC_K,			/* | */			KC_Z,		GUI_F,		ALT_U,		CTL_COMM,	KC_QUOT,
	L4_I,	L3_S,	L2_R,	L1_T,	KC_G,			/* | */			KC_P,		L1_N,		L2_E,		L3_A,		L4_O,
	SFT_Q,	KC_V,	KC_W,	KC_D,	KC_J,			/* | */			KC_B,		KC_H,		KC_SLSH,	KC_DOT,		SFT_X,
								MEH_SPC,	MAGIC,	/* | */		KC_BSPC,	KC_ENT
  ),
  [ACT] = LAYOUT(
  	QK_GESC,		CKC(CMD_COPY),  CKC(LINE_BACKSPACE),    CKC(WORD_BACKSPACE),    KC_PGUP,		            /* | */ KC_HOME,    		CKC(WORD_JUMPL),    CKC(WORD_JUMPR),    RCS(KC_TAB),	LCTL(KC_TAB),
  	CKC(APP_PREV),  CKC(APP_NEXT),  KC_DEL,			        SEL_WORD,               KC_PGDN,		            /* | */ KC_END,             KC_LEFT,		    KC_DOWN,            KC_UP,			KC_RIGHT,
  	CKC(CMD_CUT),   CKC(CMD_PASTE), CKC(LINE_DEL),		    CKC(WORD_DEL),          CKC(TAB_CLOSE),	            /* | */ CKC(TAB_REOPEN),    CKC(LINE_JUMPL),	CKC(LINE_JUMPR),	CKC(TASK_MNGR),	LYR_LOCK,
  	                                                        CKC(LINE_SELECTL),          CKC(WORD_SELECTL),      /* | */ __X__,      __X__
  ),
  [SMBL] = LAYOUT(
  	KC_CAPS,	KC_AT,		KC_HASH,	KC_DOLLAR,	CKC(EURO),		/* | */	__X__,	KC_LBRC,	KC_RBRC,	KC_SCLN,	__X__,
  	KC_GRV,		KC_UNDS,	KC_TILDE,	KC_MINS,	KC_PLUS,		/* | */	KC_EQL,	KC_LPRN,	KC_RPRN,	KC_COLN,	__X__,
  	__X__,		__X__,		KC_LT,		KC_GT,		KC_CIRC,		/* | */	__X__,	KC_LCBR,	KC_RCBR,	KC_BSLS,	__X__,
  	      								__X__,		__X__,	        /* | */	__X__,	LYR_LOCK
  ),
  [ACCT] = LAYOUT(
  	CW_TOGG,	KC_ASTR,	KC_AMPR,	KC_PERCENT,	CKC(CMD_REDO),	/* | */	__X__,	CKC(E_CIRC),     CKC(U_GRAVE),	CKC(I_CIRC),    CKC(I_TREMA),
  	KC_TAB,		KC_DQUO,	KC_EXLM,	KC_QUES,	CKC(CMD_UNDO),	/* | */	__X__,	CKC(E_AIGU),     CKC(E_GRAVE),	CKC(A_GRAVE),   CKC(O_CIRC),
  	DF(GRPT),	__X__,		__X__,		__X__,		__X__,      	/* | */	__X__,	CKC(C_CEDILLE),	CKC(U_CIRC),    CKC(A_CIRC),    __X__,
  	      								__X__,	 	KC_LSFT,        /* | */	__X__,	LYR_LOCK
  ),
  [NPD] = LAYOUT( // multimedia is to
  	KC_PAST,	KC_P4,		KC_P5,		KC_P6,		KC_PPLS,		/* | */	RGB_TOG,	RGB_MOD,	RGB_RMOD,	RGB_SAI,	RGB_SAD,
  	KC_P0,		KC_P1,		KC_P2,		KC_P3,		KC_PENT,		/* | */	KC_PSCR,	RGB_HUI,	RGB_HUD,	RGB_VAI,	RGB_VAD,
  	KC_PSLS,	KC_P7,		KC_P8,		KC_P9,		KC_PMNS,		/* | */	KC_MNXT,	KC_VOLU,	KC_VOLD,	RGB_SPI,	RGB_SPD,
  	      								KC_ENT,		KC_DOT,			/* | */	KC_MPLY,	LYR_LOCK
  )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // clang-format off
  if (!process_magic_key(keycode, record)) { return false; }
  if (!process_layer_lock(keycode, record, LYR_LOCK)) { return false; }
  if (!process_shortcuts(keycode, record)) { return false; }
  if (!process_symbols(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SEL_WORD)) { return false; }
  // clang-format on

  return true;
};

void matrix_scan_user(void) {
  layer_lock_task();
  select_word_task();
  alt_tab_task();
  combo_event_task();
};

void keyboard_post_init_user(void) {
  init_alt_tab_state();
  init_cycling_combos_state();
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
};
