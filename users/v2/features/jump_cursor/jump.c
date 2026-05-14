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
#include "jump.h"
#include "farkann_v2.h"
#include "features/tap_dance/tap_dance.h"

static jump_state_s jump_state = {
    .token     = INVALID_DEFERRED_TOKEN,
    .rep_count = 0,
    .direction = SELECTION_FORWARD,
};

static const uint8_t INIT_DELAY_MS          = 250;
static const uint8_t REP_DELAY_MS[] PROGMEM = {238, 238, 238, 199, 199, 199, 168, 168, 168, 134};

selection_direction_e get_jump_state_direction(void) {
    return jump_state.direction;
}

void cancel_jump_state_token(void) {
    jump_state.token = INVALID_DEFERRED_TOKEN;
}

static uint32_t jump_callback(uint32_t trigger_time, void *cb_arg) {
    get_jump_state_direction() == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL);
    if (jump_state.rep_count < sizeof(REP_DELAY_MS)) {
        ++jump_state.rep_count;
    }
    return pgm_read_byte(REP_DELAY_MS - 1 + jump_state.rep_count);
}

void td_process_jump(tap_dance_state_t *td_state, selection_direction_e direction) {
    td_state_t cur_state = cur_dance(td_state);

    if (cur_state == TD_1_TAP) {
        direction == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL);
    } else if (cur_state == TD_1_HOLD) {
        direction == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL);
        jump_state.rep_count = 0;
        jump_state.direction = direction;
        jump_state.token     = defer_exec(INIT_DELAY_MS, jump_callback, NULL);
    } else {
        direction == SELECTION_FORWARD ? send_action(LINE_JUMPR) : send_action(LINE_JUMPL);
    }
}

void td_process_jump_backward(tap_dance_state_t *td_state, void *user_data) {
    td_process_jump(td_state, SELECTION_BACKWARD);
}

void td_process_jump_forward(tap_dance_state_t *td_state, void *user_data) {
    td_process_jump(td_state, SELECTION_FORWARD);
}

bool process_jump_cursor(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_JUMP_BWD):
        case TD(TD_JUMP_FWD):
            if (!record->event.pressed) {
                cancel_deferred_exec(jump_state.token);
                cancel_jump_state_token();
            }
    }
    return true;
}
