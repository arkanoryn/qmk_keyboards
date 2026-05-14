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
#include "selection.h"
#include "farkann_v2.h"
#include "helpers/helpers.h"
#include "features/tap_dance/tap_dance.h"

static const uint8_t INIT_DELAY_MS          = 250;
static const uint8_t REP_DELAY_MS[] PROGMEM = {238, 238, 199, 199, 168, 168, 132, 132, 132, 99, 99, 79, 79, 79, 79, 65, 65, 65, 65, 57, 49, 43};

static selection_state_s state = {
    .is_active = false,
    .direction = SELECTION_FORWARD,
    .type      = SELECTION_WORD,
    .token     = INVALID_DEFERRED_TOKEN,
    .rep_count = 0,
};

static void move_to_word(selection_direction_e direction) {
    direction == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL);
}

static void move_to_next_line(selection_direction_e direction) {
    direction == SELECTION_FORWARD ? tap_code16(KC_DOWN) : tap_code16(KC_UP);
}

static void move_to_next_whole_line(selection_direction_e direction) {
    if (direction == SELECTION_FORWARD) {
        tap_code16(KC_DOWN);
        send_action(LINE_JUMPR);
    } else {
        tap_code16(KC_UP);
        send_action(LINE_JUMPL);
    }
}

static void select_line(selection_direction_e direction) {
    direction == SELECTION_FORWARD ? send_action(LINE_JUMPR) : send_action(LINE_JUMPL);
}

void select_current_line(selection_direction_e direction) {
    direction == SELECTION_FORWARD ? send_action(LINE_JUMPL) : send_action(LINE_JUMPR);
    register_mods(MOD_BIT(KC_LSFT));
    select_line(direction);
}

void select_current_word(selection_direction_e direction) {
    direction == SELECTION_FORWARD ? send_action(WORD_JUMPL) : send_action(WORD_JUMPR);
    register_mods(MOD_BIT(KC_LSFT));
    move_to_word(direction);
}

static uint32_t selection_callback(uint32_t trigger_time, void *cb_arg) {
    switch (state.type) {
        case SELECTION_WORD:
            move_to_word(state.direction);
            break;
        case SELECTION_LINE:
            move_to_next_line(state.direction);
            break;
        case SELECTION_WHOLE_LINE:
            move_to_next_whole_line(state.direction);
            break;
        default:
            break;
    }

    if (state.rep_count < sizeof(REP_DELAY_MS)) {
        ++state.rep_count;
    }
    return pgm_read_byte(REP_DELAY_MS - 1 + state.rep_count);
}

static void process_active_selection(tap_dance_state_t *td_state, selection_direction_e direction) {
    td_state_t cur_state = cur_dance(td_state);
    state.direction      = direction;

    if (cur_state == TD_1_TAP || cur_state == TD_2_TAP || cur_state == TD_2_HOLD) {
        state.type = SELECTION_WORD;
        move_to_word(direction);
    } else if (cur_state == TD_1_HOLD) {
        state.type = SELECTION_WHOLE_LINE;
        move_to_next_whole_line(direction);
    } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
        state.type = SELECTION_LINE;
        move_to_next_line(direction);
    } else {
        state.is_active = false;
    }

    if (cur_state == TD_1_HOLD || cur_state == TD_2_HOLD || cur_state == TD_3_HOLD) {
        state.token = defer_exec(INIT_DELAY_MS, selection_callback, NULL);
    }
}

static void start_selection(tap_dance_state_t *td_state, selection_direction_e direction) {
    td_state_t cur_state = cur_dance(td_state);
    state.is_active      = true;
    state.direction      = direction;

    send_keyboard_report();
    if (cur_state == TD_1_TAP) {
        state.type = SELECTION_WORD;
        register_mods(MOD_BIT(KC_LSFT));
        move_to_word(direction);
    } else if (cur_state == TD_1_HOLD) {
        state.type = SELECTION_WHOLE_LINE;
        select_current_line(direction);
    } else if (cur_state == TD_2_TAP || cur_state == TD_2_HOLD) {
        state.type = SELECTION_WORD;
        select_current_word(direction);
    } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
        state.type = SELECTION_LINE;
        register_mods(MOD_BIT(KC_LSFT));
        select_line(direction);
    } else {
        state.is_active = false;
    }

    if (cur_state == TD_1_HOLD || cur_state == TD_2_HOLD || cur_state == TD_3_HOLD) {
        state.token = defer_exec(INIT_DELAY_MS, selection_callback, NULL);
    }
}

void td_process_selection(tap_dance_state_t *td_state, selection_direction_e direction) {
    state.direction = direction;
    state.rep_count = 0;

    if (state.is_active) {
        process_active_selection(td_state, direction);
    } else {
        disable_shift();
        start_selection(td_state, direction);
    }
}

void td_process_selection_backward(tap_dance_state_t *td_state, void *user_data) {
    td_process_selection(td_state, SELECTION_BACKWARD);
}

void td_process_selection_forward(tap_dance_state_t *td_state, void *user_data) {
    td_process_selection(td_state, SELECTION_FORWARD);
}

bool process_selection(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_SEL_BWD):
        case TD(TD_SEL_FWD):
            if (!record->event.pressed) {
                cancel_deferred_exec(state.token);
            }
            break;
        default:
            if (state.is_active && record->event.pressed) {
                unregister_mods(MOD_BIT(KC_LSFT));
                state.is_active = false;
            }
    }
    return true;
}
