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

/* Jump and selection functions are now defined in their own feature files */
#include "../jump_cursor/jump.h"

/* ==================== TAP DANCE DEFINITIONS ==================== */

/* Define all tap dance actions using ACTION_TAP_DANCE_FN_ADVANCED */
/* The array is defined in keymap.c for introspection visibility */
