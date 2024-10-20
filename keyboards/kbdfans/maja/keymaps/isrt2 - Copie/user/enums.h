#ifndef __ENUMS_H__
#define __ENUMS_H__

#include QMK_KEYBOARD_H

enum layers {
    ISRT,
    QWER,		// QWERTY
	GAME,		// GAMING QWERTY, NO MODIFIER
    GRPT,       // GRAPHITE
    ACT,		// ACTIONS
    SMBL,		// SYMBOLS
	ACCT,		// ACCENTS
    NPD,	    // NUMPAD & MULTIMEDIA
};

enum combos {
    ESC,
	TAB,
    ENT,
    BSPC,
    DEL,
};

typedef enum {
    // ACTIONS
    APP_CLOSE = 0,
	APP_NEXT,
    APP_NEW_WINDOW,
	APP_PREV,
	CMD_COPY,				// also LD
    CMD_CUT,				// also LD
	CMD_PASTE,				// also LD
	CMD_REDO,				// also LD
	CMD_UNDO,				// also LD,
	LD_SAVE,
	LD_SEARCH,
	LD_SELECT_ALL,
	LINE_BACKSPACE,
	LINE_DEL,
	LINE_JUMPL,
	LINE_JUMPR,
    LINE_SELECTL,
    LINE_SELECTR,
	TAB_CLOSE,
	TAB_REOPEN,
    TAB_NEW,
	WORD_BACKSPACE,
	WORD_DEL,
	WORD_JUMPL,
	WORD_JUMPR,
    WORD_SELECTL,
    WORD_SELECTR,
    LAST_ACTION
} e_actions_id;

typedef enum {
    FIRST_ACCENT = LAST_ACTION,
    E_CIRC,
    E_AIGU,
    C_CEDILLE,
    U_GRAVE,
    E_GRAVE,
    U_CIRC,
    I_CIRC,
    A_GRAVE,
    A_CIRC,
    I_TREMA,
    O_CIRC,
    LAST_ACCENT
} e_accents_id;

enum custom_keycodes {
	CKC_EURO = SAFE_RANGE + LAST_ACTION + LAST_ACCENT,
};

#endif // __ENUMS_H__
