#pragma once

#include QMK_KEYBOARD_H

// clang-format off
enum {
    STATE_NONE,        // No selection.
    STATE_SELECTED,    // Macro released with something selected.
    STATE_WORD,        // Macro held with word(s) selected.
    STATE_FIRST_LINE,  // Macro held with one line selected.
    STATE_LINE         // Macro held with multiple lines selected.
};
// clang-format on

typedef enum {
  SELECTION_FORWARD = 0,
  SELECTION_BACKWARD,
} direction_e;

typedef enum {
  SELECTION_WORD = 0,
  SELECTION_LINE,
  SELECTION_WHOLE_LINE,
} type_e;

typedef struct {
  bool           is_active;
  direction_e    direction;
  type_e         type;
  deferred_token token;
  uint8_t        rep_count;
} selection_state_s;

void td_process_selection_backward(tap_dance_state_t *td_state, void *user_data);
void td_process_selection_forward(tap_dance_state_t *td_state, void *user_data);
bool process_selection(uint16_t keycode, keyrecord_t *record);
void select_current_line(direction_e direction);
void select_current_word(direction_e direction);
