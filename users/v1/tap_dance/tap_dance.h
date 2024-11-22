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
typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP, // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  bool       is_press_action;
  td_state_t state;
} td_tap_t;

enum {
  TD_NEW_WINDOW = 0,
};

// td_state_t cur_dance(tap_dance_state_t *state);

// // For the x tap dance. Put it here so it can be used in any keymap
// void x_finished(tap_dance_state_t *state, void *user_data);
// void x_reset(tap_dance_state_t *state, void *user_data);