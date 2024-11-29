/*
// # Description
// TODO
//
// # QMK features required:
// * TODO
//
// # Configuration options
*/
#pragma once

typedef enum { // clang-format off
  TD_NONE,
  TD_UNKNOWN,
  TD_1_TAP,
  TD_1_HOLD,
  TD_2_TAP,
  TD_2_HOLD,
  TD_2_SINGLE_TAP,
  TD_3_TAP,
  TD_3_HOLD,
  TD_4_TAP,
  TD_4_HOLD,
  TD_5_TAP,
  TD_5_HOLD,
} td_state_t; // clang-format on

enum {
  TD_NEW_WINDOW = 0,
  TD_SEARCH,
  TD_ESC,
  TD_TAB_NEW,
  TD_TAB_CLOSE,
  TD_JUMP_FORWARD,
  TD_JUMP_BACKWARD,
  TD_SELECTION_FORWARD,
  TD_SELECTION_BACKWARD,
  TD_COPY,
  TD_CUT,
};

td_state_t cur_dance(tap_dance_state_t *state);
// #ifdef DEBUG_ENABLE
void show_count(tap_dance_state_t *state);
// #endif // DEBUG_ENABLE

void td_process_cut(tap_dance_state_t *td_state, void *user_data);
void td_process_copy(tap_dance_state_t *td_state, void *user_data);
void td_process_esc(tap_dance_state_t *state, void *user_data);
void td_process_tab_close(tap_dance_state_t *state, void *user_data);
void td_process_tab_new(tap_dance_state_t *state, void *user_data);
void td_process_search(tap_dance_state_t *state, void *user_data);
void td_process_new_window(tap_dance_state_t *state, void *user_data);
