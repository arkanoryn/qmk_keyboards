/* Copyright 2026 Ark'Anoryn (@arkanoryn)
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "tap_dance.h"
#include "farkann_v2.h"
#include "helpers/helpers.h"

/* Helper to extract the current tap dance state */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_1_TAP;
        else
            return TD_1_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return TD_2_SINGLE_TAP;
        else if (state->pressed)
            return TD_2_HOLD;
        else
            return TD_2_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_3_TAP;
        else
            return TD_3_HOLD;
    } else
        return TD_UNKNOWN;
};

/* ==================== SIMPLE TAP DANCES ==================== */

void td_process_new_window(tap_dance_state_t *state, void *user_data) {
    if (cur_dance(state) == TD_1_TAP) {
        send_action(APP_NEW_WINDOW);
    } else {
        send_action(APP_NEW_WINDOW_INCOGNITO);
    }
};

void td_process_search(tap_dance_state_t *state, void *user_data) {
    if (cur_dance(state) == TD_1_TAP) {
        send_action(CMD_SEARCH);
    } else {
        send_action(CMD_SEARCH_ALL);
    }
};

void td_process_tab_new(tap_dance_state_t *state, void *user_data) {
    td_state_t cur_state = cur_dance(state);

    if (cur_state == TD_1_TAP) {
        send_action(TAB_NEW);
    } else if (cur_state == TD_2_TAP || cur_state == TD_2_HOLD) {
        send_action(APP_NEW_WINDOW);
    } else {
        send_action(APP_NEW_WINDOW_INCOGNITO);
    }
};

void td_process_tab_close(tap_dance_state_t *state, void *user_data) {
    td_state_t cur_state = cur_dance(state);

    if (cur_state == TD_1_HOLD) {
        send_action(WINDOW_CLOSE);
    } else {
        send_action(TAB_CLOSE);
    }
};

void td_process_esc(tap_dance_state_t *state, void *user_data) {
    tap_code16(KC_ESC);
    if (cur_dance(state) != TD_1_TAP) {
        disable_shift();
        init_alt_tab_state();
    }
};

/* ==================== COPY/CUT TAP DANCES ==================== */

static void clean_copy(void) {
    disable_shift(); // we don't want to type "CMD/CTRL+SHIFT+C"
    send_action(CMD_COPY);
}

static void clean_cut(void) {
    disable_shift(); // we don't want to type "CMD/CTRL+SHIFT+X"
    send_action(CMD_CUT);
}

void td_process_copy(tap_dance_state_t *td_state, void *user_data) {
    td_state_t cur_state = cur_dance(td_state);

    if (cur_state == TD_1_TAP) {
        clean_copy();
    } else if (cur_state == TD_1_HOLD) {
        register_mods(MOD_BIT(KC_LSFT));
        send_action(WORD_JUMPR);
        clean_copy();
    } else if (cur_state == TD_2_TAP) {
        register_mods(MOD_BIT(KC_LSFT));
        send_action(LINE_JUMPR);
        clean_copy();
    } else if (cur_state == TD_2_HOLD) {
        register_mods(MOD_BIT(KC_LSFT));
        send_action(LINE_JUMPR);
        clean_copy();
    } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
        send_action(CMD_SELECT_ALL);
        clean_copy();
    }
};

void td_process_cut(tap_dance_state_t *td_state, void *user_data) {
    td_state_t cur_state = cur_dance(td_state);

    if (cur_state == TD_1_TAP) {
        clean_cut();
    } else if (cur_state == TD_1_HOLD) {
        register_mods(MOD_BIT(KC_LSFT));
        send_action(WORD_JUMPR);
        clean_cut();
    } else if (cur_state == TD_2_TAP) {
        register_mods(MOD_BIT(KC_LSFT));
        send_action(LINE_JUMPR);
        clean_cut();
    } else if (cur_state == TD_2_HOLD) {
        register_mods(MOD_BIT(KC_LSFT));
        send_action(LINE_JUMPR);
        clean_cut();
    } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
        send_action(CMD_SELECT_ALL);
        clean_cut();
    }
};

/* ==================== JUMP TAP DANCES ==================== */

/* Jump state for acceleration */
typedef struct {
    deferred_token token;
    uint8_t        rep_count;
} jump_state_s;

static jump_state_s jump_state = {
    .token     = INVALID_DEFERRED_TOKEN,
    .rep_count = 0,
};

static const uint8_t INIT_DELAY_MS          = 250;
static const uint8_t REP_DELAY_MS[] PROGMEM = {238, 238, 238, 199, 199, 199, 168, 168, 168, 134};

static uint32_t jump_callback(uint32_t trigger_time, void *cb_arg) {
    send_action(WORD_JUMPR);
    if (jump_state.rep_count < sizeof(REP_DELAY_MS)) {
        ++jump_state.rep_count;
    }
    return pgm_read_byte(REP_DELAY_MS - 1 + jump_state.rep_count);
};

static uint32_t jump_callback_bwd(uint32_t trigger_time, void *cb_arg) {
    send_action(WORD_JUMPL);
    if (jump_state.rep_count < sizeof(REP_DELAY_MS)) {
        ++jump_state.rep_count;
    }
    return pgm_read_byte(REP_DELAY_MS - 1 + jump_state.rep_count);
};

void td_process_jump_forward(tap_dance_state_t *td_state, void *user_data) {
    td_state_t cur_state = cur_dance(td_state);

    if (cur_state == TD_1_TAP) {
        send_action(WORD_JUMPR);
    } else if (cur_state == TD_1_HOLD) {
        send_action(WORD_JUMPR);
        jump_state.rep_count = 0;
        jump_state.token     = defer_exec(INIT_DELAY_MS, jump_callback, NULL);
    } else {
        send_action(LINE_JUMPR);
    }
};

void td_process_jump_backward(tap_dance_state_t *td_state, void *user_data) {
    td_state_t cur_state = cur_dance(td_state);

    if (cur_state == TD_1_TAP) {
        send_action(WORD_JUMPL);
    } else if (cur_state == TD_1_HOLD) {
        send_action(WORD_JUMPL);
        jump_state.rep_count = 0;
        jump_state.token     = defer_exec(INIT_DELAY_MS, jump_callback_bwd, NULL);
    } else {
        send_action(LINE_JUMPL);
    }
};

/* ==================== SELECTION TAP DANCES ==================== */

typedef enum {
    SELECTION_FORWARD = 0,
    SELECTION_BACKWARD,
} selection_direction_e;

typedef struct {
    bool                is_active;
    selection_direction_e direction;
    deferred_token      token;
    uint8_t             rep_count;
} selection_state_s;

static selection_state_s selection_state = {
    .is_active = false,
    .direction = SELECTION_FORWARD,
    .token     = INVALID_DEFERRED_TOKEN,
    .rep_count = 0,
};

static const uint8_t SEL_INIT_DELAY_MS          = 250;
static const uint8_t SEL_REP_DELAY_MS[] PROGMEM = {238, 238, 199, 199, 168, 168, 132, 132, 132, 99, 99, 79, 79, 79, 79, 65, 65, 65, 65, 57, 49, 43};

static uint32_t selection_callback(uint32_t trigger_time, void *cb_arg) {
    if (selection_state.direction == SELECTION_FORWARD) {
        send_action(WORD_JUMPR);
    } else {
        send_action(WORD_JUMPL);
    }

    if (selection_state.rep_count < sizeof(SEL_REP_DELAY_MS)) {
        ++selection_state.rep_count;
    }
    return pgm_read_byte(SEL_REP_DELAY_MS - 1 + selection_state.rep_count);
};

static void select_line(selection_direction_e direction) {
    if (direction == SELECTION_FORWARD) {
        send_action(LINE_JUMPR);
    } else {
        send_action(LINE_JUMPL);
    }
}

static void select_current_line(selection_direction_e direction) {
    if (direction == SELECTION_FORWARD) {
        send_action(LINE_JUMPR);
    } else {
        send_action(LINE_JUMPL);
    }
    register_mods(MOD_BIT(KC_LSFT));
    select_line(direction);
}

static void select_current_word(selection_direction_e direction) {
    if (direction == SELECTION_FORWARD) {
        send_action(WORD_JUMPR);
    } else {
        send_action(WORD_JUMPL);
    }
    register_mods(MOD_BIT(KC_LSFT));
    if (direction == SELECTION_FORWARD) {
        send_action(WORD_JUMPR);
    } else {
        send_action(WORD_JUMPL);
    }
}

static void process_active_selection(tap_dance_state_t *td_state, selection_direction_e direction) {
    td_state_t cur_state = cur_dance(td_state);
    selection_state.direction = direction;

    if (cur_state == TD_1_TAP || cur_state == TD_2_TAP || cur_state == TD_2_HOLD) {
        if (direction == SELECTION_FORWARD) {
            send_action(WORD_JUMPR);
        } else {
            send_action(WORD_JUMPL);
        }
    } else if (cur_state == TD_1_HOLD) {
        if (direction == SELECTION_FORWARD) {
            tap_code16(KC_DOWN);
            send_action(LINE_JUMPR);
        } else {
            tap_code16(KC_UP);
            send_action(LINE_JUMPL);
        }
    } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
        if (direction == SELECTION_FORWARD) {
            tap_code16(KC_DOWN);
        } else {
            tap_code16(KC_UP);
        }
    }

    if (cur_state == TD_1_HOLD || cur_state == TD_2_HOLD || cur_state == TD_3_HOLD) {
        selection_state.token = defer_exec(SEL_INIT_DELAY_MS, selection_callback, NULL);
    }
};

static void start_selection(tap_dance_state_t *td_state, selection_direction_e direction) {
    td_state_t cur_state = cur_dance(td_state);
    selection_state.is_active = true;
    selection_state.direction = direction;
    selection_state.rep_count = 0;

    send_keyboard_report();
    if (cur_state == TD_1_TAP) {
        register_mods(MOD_BIT(KC_LSFT));
        if (direction == SELECTION_FORWARD) {
            send_action(WORD_JUMPR);
        } else {
            send_action(WORD_JUMPL);
        }
    } else if (cur_state == TD_1_HOLD) {
        select_current_line(direction);
    } else if (cur_state == TD_2_TAP || cur_state == TD_2_HOLD) {
        select_current_word(direction);
    } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
        register_mods(MOD_BIT(KC_LSFT));
        select_line(direction);
    }

    if (cur_state == TD_1_HOLD || cur_state == TD_2_HOLD || cur_state == TD_3_HOLD) {
        selection_state.token = defer_exec(SEL_INIT_DELAY_MS, selection_callback, NULL);
    }
};

void td_process_selection_forward(tap_dance_state_t *td_state, void *user_data) {
    if (selection_state.is_active) {
        process_active_selection(td_state, SELECTION_FORWARD);
    } else {
        disable_shift();
        start_selection(td_state, SELECTION_FORWARD);
    }
};

void td_process_selection_backward(tap_dance_state_t *td_state, void *user_data) {
    if (selection_state.is_active) {
        process_active_selection(td_state, SELECTION_BACKWARD);
    } else {
        disable_shift();
        start_selection(td_state, SELECTION_BACKWARD);
    }
};

/* ==================== TAP DANCE DEFINITIONS ==================== */

/* Define all tap dance actions using ACTION_TAP_DANCE_FN_ADVANCED */
/* The array is defined in keymap.c for introspection visibility */
