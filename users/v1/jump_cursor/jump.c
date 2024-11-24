/*
**
** TODO:
**
*/
#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "shortcuts/shortcuts.h"
#include "selection/selection.h"
#include "jump.h"

jump_state_s state = {
    .token     = INVALID_DEFERRED_TOKEN,
    .rep_count = 0,
    .direction = SELECTION_FORWARD,
};

static const uint8_t INIT_DELAY_MS          = 250;
static const uint8_t REP_DELAY_MS[] PROGMEM = {238, 238, 238, 199, 199, 199, 168, 168, 168};

direction_e get_jump_state_direction(void) {
  return state.direction;
}

void cancel_jump_state_token(void) {
  state.token = INVALID_DEFERRED_TOKEN;
}

uint32_t jump_callback(uint32_t trigger_time, void *cb_arg) {
  get_jump_state_direction() == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL);
  if (state.rep_count < sizeof(REP_DELAY_MS)) {
    ++state.rep_count;
  }
  return pgm_read_byte(REP_DELAY_MS - 1 + state.rep_count);
};

static void td_process_jump(tap_dance_state_t *td_state, direction_e direction) {
  td_state_t cur_state = cur_dance(td_state);

  if (cur_state == TD_1_TAP) {
    direction == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL);
  } else if (cur_state == TD_2_HOLD) {
    direction == SELECTION_FORWARD ? send_action(WORD_JUMPR) : send_action(WORD_JUMPL); // we should move and then start the repeat
    state.rep_count = 0;
    state.direction = direction;
    state.token     = defer_exec(INIT_DELAY_MS, jump_callback, NULL);
  } else {
    direction == SELECTION_FORWARD ? send_action(LINE_JUMPR) : send_action(LINE_JUMPL);
  }
};

void td_process_jump_backward(tap_dance_state_t *td_state, void *user_data) {
  td_process_jump(td_state, SELECTION_BACKWARD);
};

void td_process_jump_forward(tap_dance_state_t *td_state, void *user_data) {
  td_process_jump(td_state, SELECTION_FORWARD);
};

bool process_jump_cursor(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_JUMP_BACKWARD):
    case TD(TD_JUMP_FORWARD):
      if (!record->event.pressed) {
        cancel_deferred_exec(state.token);
        cancel_jump_state_token();
      }
  }
  return true;
};
