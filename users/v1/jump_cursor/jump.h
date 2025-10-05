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

#include "selection/selection.h"

typedef struct {
  deferred_token token;
  uint8_t        rep_count;
  direction_e    direction;
} jump_state_s;

bool process_jump_cursor(uint16_t keycode, keyrecord_t *record);
void td_process_jump_forward(tap_dance_state_t *td_state, void *user_data);
void td_process_jump_backward(tap_dance_state_t *td_state, void *user_data);
void cancel_jump_state_token(void);
