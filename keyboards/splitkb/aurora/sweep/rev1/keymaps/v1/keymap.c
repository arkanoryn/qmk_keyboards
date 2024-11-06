#include QMK_KEYBOARD_H

#define KEYMAP_MAIN_H "ark_v1.h"

#include KEYMAP_MAIN_H
#include "shortcuts/shortcuts.h"
#include "combos/combos.h"
#include "symbols/symbols.h"
#include "magic/magic.h"
#include "magic/cycling_combos.h"
#include "teacher/chord_teacher.h"
#include "getreuer/layer_lock/layer_lock.h"
#include "getreuer/select_word/select_word.h"
#include "getreuer/sentence_case/sentence_case.h"


#define __X__ KC_NO
#define _____ KC_TRNS

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
  	KC_B,	CTL_L,	ALT_D,  GUI_W,  KC_Z,			/* | */			QUOT_UNDS,	GUI_F,		ALT_O,		CTL_U,		KC_J,
  	L4_N,	L3_R,	L2_T,	L1_S,	KC_G,			/* | */			KC_Y,		L1_H,		L2_A,		L3_E,		L4_I,
  	SFT_Q,	KC_X,	KC_M,	KC_C,	KC_V,			/* | */			KC_K,		KC_P,		DOT_EXLM,	KC_COMM,	SFT_SLSH,
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
  	CKC(CMD_CUT),   CKC(CMD_PASTE), CKC(LINE_DEL),		    CKC(WORD_DEL),          CKC(TAB_CLOSE),	            /* | */ CKC(TAB_REOPEN),    CKC(LINE_JUMPL),	CKC(LINE_JUMPR),	CKC(TASK_MNGR),	__X__,
  	                                                        CKC(LINE_SELECTL),      CKC(WORD_SELECTL),	        /* | */ __X__,      LYR_LOCK
  ),
  [SMBL] = LAYOUT(
  	KC_CAPS,	KC_AT,		KC_HASH,	KC_DOLLAR,	CKC(EURO),		/* | */	__X__,	KC_LBRC,	KC_RBRC,	KC_SCLN,	__X__,
  	KC_TILDE,	KC_GRV,		KC_UNDS,	KC_MINS,	KC_PLUS,		/* | */	KC_EQL,	KC_LPRN,	KC_RPRN,	KC_COLN,	__X__,
  	__X__,		KC_PIPE,	KC_LT,		KC_GT,		KC_CIRC,		/* | */	KC_SLSH,KC_LCBR,	KC_RCBR,	KC_BSLS,	__X__,
  	      								__X__,		__X__,	        /* | */	__X__,	LYR_LOCK
  ),
  [ACCT] = LAYOUT(
  	CW_TOGG,	KC_ASTR,	KC_AMPR,	KC_PERCENT,	CKC(CMD_REDO),	/* | */	__X__,	CKC(E_CIRC),     CKC(U_GRAVE),	CKC(I_CIRC),    CKC(I_TREMA),
  	KC_TAB,		KC_DQUO,	KC_EXLM,	KC_QUES,	CKC(CMD_UNDO),	/* | */	__X__,	CKC(E_AIGU),     CKC(E_GRAVE),	CKC(A_GRAVE),   CKC(O_CIRC),
  	DF(GRPT),	DF(ISRT),	__X__,		__X__,		__X__,      	/* | */	__X__,	CKC(C_CEDILLE),	CKC(U_CIRC),    CKC(A_CIRC),    __X__,
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
//   if (!process_chord_teacher(keycode, record)) { return false; } // FIXME: To add to the if statement: if (SETTING_CHORD_MODE == CHORD_MODE_CORRECTIVE)
  if (!process_sentence_case(keycode, record)) { return false; }
  if (!process_magic_key(keycode, record)) { return false; }
  if (!process_layer_lock(keycode, record, LYR_LOCK)) { return false; }
  if (!process_shortcuts(keycode, record)) { return false; }
  if (!process_symbols(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SEL_WORD)) { return false; }
  // clang-format on

  const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

  switch (keycode) {
    case DOT_EXLM:
      if (record->event.pressed) {
        (mods & MOD_MASK_SHIFT) ? tap_code16(KC_EXLM) : tap_code16(KC_DOT);
      }
      return false;
    case QUOT_UNDS:
      if (record->event.pressed) {
        (mods & MOD_MASK_SHIFT) ? tap_code16(KC_UNDS) : tap_code16(KC_QUOT);
      }
      return false;
    case SFT_ENT:
      if (record->event.pressed) {
        add_mods(MOD_MASK_SHIFT);
        tap_code16(KC_ENT);
        set_mods(mods);
      }
      return false;
    case C_ENT:
      if (record->event.pressed) {
        (detected_host_os() == OS_MACOS ? add_mods(MOD_MASK_GUI) : add_mods(MOD_MASK_CTRL));
        tap_code16(KC_ENT);
        set_mods(mods);
      }
      return false;
  }
  return true;
};

// Could be in an helper file
uint8_t last_message_length = 0;
void    send_temporary_string(const char *str) {
  last_message_length += strlen(str);
  SEND_STRING(str);
}

void clear_last_message(void) {
  if (last_message_length == 0) {
    return;
  }

  do {
    tap_code16(KC_BSPC);
  } while (--last_message_length);
}
// Could be in an helper file -- end

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    clear_last_message();
  }
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

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L4_N:
        case L4_I:
        case SFT_SLSH:
        case SFT_Q:
            return TAPPING_TERM + 200;
        case CTL_L:
        case L3_R:
        case CTL_U:
        case L3_E:
            return TAPPING_TERM + 150;
        case ALT_D:
        case L2_T:
        case ALT_O:
        case L2_A:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
