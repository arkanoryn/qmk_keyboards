#include QMK_KEYBOARD_H

#define __X__	KC_NO
#define _____	KC_TRNS

#include "./user/enums.h"
#include "./user/commands/shortcuts.c"
#include "./user/commands/accents.c"
#include "./user/combos.c"
#include "./user/leader.c"

#define SC(x) (SAFE_RANGE + x)                          // shortcuts

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ISRT] = LAYOUT(
		__X__,		__X__,			__X__,			__X__,			__X__,			__X__,	__X__,	/* | */		__X__,			__X__,			__X__,			__X__,				__X__,			__X__,			    			__X__,		/* | */			TO(QWER),
		__X__,		KC_Y,			LCTL_T(KC_C),	LALT_T(KC_L),	LGUI_T(KC_M),	KC_K,			/* | */		KC_Z,			RGUI_T(KC_F),	RALT_T(KC_U),	RCTL_T(KC_COMM), 	KC_QUOT, 		__X__,	 		    __X__, 		__X__,		/* | */			TO(NPD),
		__X__,		LT(NPD, KC_I),	LT(ACCT, KC_S),	LT(SMBL, KC_R),	LT(ACT, KC_T),	KC_G,			/* | */		KC_P,			LT(ACT, KC_N),	LT(SMBL, KC_E),	LT(ACCT, KC_A),		LT(NPD, KC_O),	__X__,			    __X__,					/* | */			DF(GAME),
		__X__,		LSFT_T(KC_Q),	KC_V,			KC_W,			KC_D,			KC_J,			/* | */		KC_B,			KC_H,			KC_SLSH,		KC_DOT,				RSFT_T(KC_X),	__X__,				__X__,					/* | */			__X__,
		__X__,										__X__,			MEH_T(KC_SPC),	QK_LEAD,		/* | */		KC_BSPC,		KC_ENT,																				    				/* | */		__X__,		__X__,		__X__
	),
	[QWER] = LAYOUT(
		QK_GESC,	KC_1,			KC_2,			KC_3,			KC_4,			KC_5,	KC_6,	/* | */		KC_7,			KC_8,			KC_9,			KC_0,				KC_MINS,		    KC_EQL,						KC_BSPC,	/* | */			KC_DEL,
		KC_TAB,		KC_Q,			LCTL_T(KC_W),	LALT_T(KC_E),	LGUI_T(KC_R),	KC_T,			/* | */		KC_Y,			RGUI_T(KC_U),	RALT_T(KC_I),	RCTL_T(KC_O), 		KC_P, 			    KC_LBRC, 		KC_RBRC,	KC_BSLS,	/* | */			KC_HOME,
		KC_CAPS,	LT(NPD, KC_A),  LT(ACCT, KC_S),	LT(SMBL, KC_D),	LT(ACT, KC_F),	KC_G,			/* | */		KC_H,			LT(ACT, KC_J),	LT(SMBL, KC_K),	LT(ACCT, KC_L),		LT(NPD, KC_SCLN),   KC_QUOT,		KC_ENT,					/* | */			KC_END,
		KC_LSFT,	KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,			/* | */		TO(ISRT),		KC_N,			KC_M,			KC_COMM,			KC_DOT,			    KC_SLSH,		KC_RSFT,				/* | */			KC_UP,
		KC_LCTL,									KC_LGUI,		MEH_T(KC_SPC),	KC_LALT,		/* | */		KC_SPC,			KC_RCTL,																    							/* | */		KC_LEFT,	KC_DOWN,	KC_RGHT
	),
	[GAME] = LAYOUT(
		QK_GESC,	KC_1,			KC_2,			KC_3,			KC_4,			KC_5,	KC_6,	/* | */		KC_7,			KC_8,			KC_9,			KC_0,				KC_MINS,		    KC_EQL,						KC_BSPC,	/* | */			KC_DEL,
		KC_TAB,		KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,			/* | */		KC_Y,			KC_U,			KC_I,			KC_O,				KC_P,			    KC_LBRC,		KC_RBRC,	KC_BSLS,	/* | */			KC_PGUP,
		KC_CAPS,	KC_A,			KC_S,			KC_D,			KC_F,			KC_G,			/* | */		KC_H,			KC_J,			KC_K,			KC_L,				KC_SCLN,		    KC_QUOT,		KC_ENT,					/* | */			KC_PGDN,
		KC_LSFT,	KC_Z,			KC_X,			KC_C,			KC_V,			KC_B,			/* | */		TO(ISRT),		KC_N,			KC_M,			KC_COMM,			KC_DOT,			    KC_SLSH,		KC_RSFT,				/* | */			KC_UP,
		KC_LCTL,									KC_LGUI,		KC_SPC,			KC_LALT,		/* | */		KC_RALT,        KC_RCTL,                      											    							/* | */		KC_LEFT,	KC_DOWN,   KC_RIGHT
	),
	[GRPT] = LAYOUT(
		__X__,		__X__,			__X__,			__X__,			__X__,			__X__,	__X__,	/* | */		__X__,			__X__,			__X__,			__X__,				__X__,			    __X__,						__X__,		/* | */			TO(QWER),
		__X__,		KC_B,			LCTL_T(KC_L),	LALT_T(KC_D),	LGUI_T(KC_W),	KC_Z,			/* | */		KC_QUOT,		RGUI_T(KC_F),	RALT_T(KC_O),	RCTL_T(KC_U), 	    KC_J,    		    __X__,	 		__X__, 		__X__,		/* | */			TO(NPD),
		__X__,		LT(NPD, KC_N),	LT(ACCT, KC_R),	LT(SMBL, KC_T),	LT(ACT, KC_S),	KC_G,			/* | */		KC_Y,			LT(ACT, KC_H),	LT(SMBL, KC_A),	LT(ACCT, KC_E),		LT(NPD, KC_I),	    __X__,			__X__,					/* | */			TO(ISRT),
		__X__,		LSFT_T(KC_Q),	KC_X,			KC_M,			KC_C,			KC_V,			/* | */		__X__,			KC_K,			KC_P,			KC_COMM,		    KC_DOT,	    	    RSFT_T(KC_SLSH),__X__,					/* | */			__X__,
		__X__,										__X__,			MEH_T(KC_SPC),	QK_LEAD,		/* | */		KC_BSPC,		KC_ENT,																	    							/* | */		__X__,		__X__,		__X__
	),
	[ACT] = LAYOUT(
		__X__,    	__X__,			__X__,          __X__,          __X__,          __X__,	__X__,	        /* | */		__X__,			__X__,			__X__,			__X__,				__X__,			__X__,		    				__X__,		/* | */			__X__,
		__X__,      QK_GESC,		SC(CMD_COPY),    SC(LINE_BACKSPACE),SC(WORD_BACKSPACE),	KC_PGUP,		/* | */		KC_HOME,    	SC(WORD_JUMPL),  SC(WORD_JUMPR),  RCS(KC_TAB),		LCTL(KC_TAB),	__X__,		    	__X__,		__X__,		/* | */			__X__,
		__X__,      SC(APP_PREV),   SC(APP_NEXT),    KC_DEL,			KC_BSPC,            KC_PGDN,		/* | */		KC_END, 		KC_LEFT,        KC_DOWN,		KC_UP,				KC_RIGHT,		__X__,		    	__X__,					/* | */			__X__,
		__X__,      SC(CMD_CUT),    SC(CMD_PASTE),   SC(LINE_DEL),		SC(WORD_DEL),		SC(TAB_CLOSE),	/* | */		SC(TAB_REOPEN),  SC(LINE_JUMPL),  SC(LINE_JUMPR),  __X__,			__X__,	    	__X__,		    	__X__,					/* | */			__X__,
		__X__,										__X__,				SC(LINE_SELECTL),   SC(WORD_SELECTL),/* | */	SC(WORD_SELECTR),SC(LINE_SELECTR),																	    					/* | */		__X__,		__X__,		__X__
	),
	[SMBL] = LAYOUT(
		__X__,   	 __X__,			__X__,          __X__,          __X__,          __X__,	__X__,	/* | */		__X__,			__X__,			__X__,			__X__,				__X__,			__X__,		    				__X__,		/* | */			__X__,
		__X__,		KC_CAPS,        KC_AT,          KC_HASH,		KC_DOLLAR,      CKC_EURO,		/* | */		__X__,	        KC_LBRC,        KC_RBRC,		KC_SCLN,			__X__,          __X__,		    	__X__,		__X__,		/* | */			__X__,
		__X__,		KC_GRV,         KC_UNDS,        KC_TILDE,		KC_MINS,        KC_PLUS,		/* | */		KC_EQL,	        KC_LPRN,        KC_RPRN,		KC_COLN,			__X__,	        __X__,		    	__X__,					/* | */			__X__,
		__X__,		__X__,        	__X__,			KC_LT,			KC_GT,			__X__,			/* | */		__X__,			KC_LCBR,        KC_RCBR,		KC_BSLS,			__X__,			__X__,		    	__X__,					/* | */			__X__,
		__X__,										__X__,			__X__,		    __X__,	        /* | */		__X__,	        DF(ISRT),																		    					/* | */		__X__,		__X__,		__X__
	),
	[ACCT] = LAYOUT(
		__X__,		__X__,			__X__,          __X__,          __X__,          __X__,	__X__,	/* | */		__X__,			__X__,			__X__,			__X__,				__X__,			__X__,                          __X__,  	/* | */			__X__,
		__X__,		CW_TOGG,      	KC_ASTR,        KC_AMPR,		KC_PERCENT,     SC(CMD_REDO),	/* | */	    __X__,			SC(E_CIRC),     SC(U_GRAVE),	SC(I_CIRC),			SC(I_TREMA),	__X__,		        __X__,		__X__,		/* | */			__X__,
		__X__,		KC_TAB,         KC_DQUO,        KC_EXLM,		KC_QUES,        SC(CMD_UNDO),	/* | */	    __X__,			SC(E_AIGU),     SC(E_GRAVE),	SC(A_GRAVE),		SC(O_CIRC),	 	__X__,		        __X__,					/* | */			__X__,
		__X__,		TO(GAME),       TO(QWER),		TO(GRPT),		DF(NPD),	    __X__,      	/* | */	    __X__,			SC(C_CEDILLE),  SC(U_CIRC),		SC(A_CIRC),         __X__,          __X__,              __X__,					/* | */			__X__,
		__X__,										__X__,			__X__,		    KC_LSFT,        /* | */		__X__,	        DF(ISRT),																							/* | */		__X__,		__X__,		__X__
	),
	[NPD] = LAYOUT( // multimedia is to do
		__X__,		__X__,			__X__,          __X__,          __X__,          __X__,	__X__,	/* | */		__X__,			__X__,			__X__,			__X__,				__X__,			__X__,			    			__X__,		/* | */			QK_BOOT,
		__X__,		KC_PAST,        KC_P7,          KC_P8,			KC_P9,          KC_PPLS,		/* | */	    RGB_TOG,		RGB_MOD,		RGB_RMOD,		RGB_SAI,		    RGB_SAD,		__X__,			    __X__,		__X__,		/* | */			__X__,
		__X__,		KC_P0,          KC_P4,          KC_P5,			KC_P6,          KC_PENT,		/* | */	    KC_PSCR,		RGB_HUI,		RGB_HUD,		RGB_VAI,		    RGB_VAD,		__X__,			    __X__,					/* | */			__X__,
		__X__,		KC_PSLS,         KC_P1,          KC_P2,			KC_P3,          KC_PMNS,		/* | */	    KC_MNXT,		KC_VOLU,		KC_VOLD,		RGB_SPI,			RGB_SPD,		__X__,			    __X__,					/* | */			__X__,
		__X__,										__X__,			KC_EQL,			KC_DOT,			/* | */	    KC_MPLY,	    DF(ISRT),																			    					/* | */		__X__,		__X__,		__X__
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SC(0)... SC(LAST_ACTION) - 1:
			if (record->event.pressed) {
				send_shortcut(keycode - SC(0));
			}
			return false;
		case SC(FIRST_ACCENT + 1)... SC(LAST_ACCENT) - 1:
			if (record->event.pressed) {
				return send_accent(keycode - SC(0));
			}
			return false;
		case CKC_EURO:
			if (record->event.pressed) {
				SEND_STRING("CTRL+ALT+6 on winOS");
			}
		default:
			return true;
	};
	return true;
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
}
