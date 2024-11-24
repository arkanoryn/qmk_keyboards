/*
**
** TODO:
**
*/
#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "tap_dance.h"
#include "shortcuts/shortcuts.h"
#include "jump_cursor/jump.h"
#include "selection/selection.h"

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

// #ifdef DEBUG_ENABLE
void show_count(tap_dance_state_t *state) {
  char str[5];
  sprintf(str, "%d", state->count);
  send_temporary_string(str);
  state->finished ? SEND_STRING(" | finished | ") : SEND_STRING(" | NOT finished | ");
  state->pressed ? SEND_STRING("pressed | ") : SEND_STRING("NOT pressed | ");
  state->interrupted ? SEND_STRING("interrupted | ") : SEND_STRING("NOT interrupted |");
};
// #endif // DEBUG_ENABLE

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
#ifdef CYCLE_COMBO_ENABLE
    init_cycling_combos_state();
#endif // CYCLE_COMBO_ENABLE
  }
};

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
    select_current_word(SELECTION_FORWARD);
    clean_copy();
  } else if (cur_state == TD_2_TAP) {
    register_mods(MOD_BIT(KC_LSFT));
    send_action(LINE_JUMPR);
    clean_copy();
  } else if (cur_state == TD_2_HOLD) {
    select_current_line(SELECTION_FORWARD);
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
    select_current_word(SELECTION_FORWARD);
    clean_cut();
  } else if (cur_state == TD_2_TAP) {
    register_mods(MOD_BIT(KC_LSFT));
    send_action(LINE_JUMPR);
    clean_cut();
  } else if (cur_state == TD_2_HOLD) {
    select_current_line(SELECTION_FORWARD);
    clean_cut();
  } else if (cur_state == TD_3_TAP || cur_state == TD_3_HOLD) {
    send_action(CMD_SELECT_ALL);
    clean_cut();
  }
};

tap_dance_action_t tap_dance_actions[] = {
    // clang-format off
    [TD_ESC]                 = ACTION_TAP_DANCE_FN(td_process_esc),
    [TD_JUMP_BACKWARD]       = ACTION_TAP_DANCE_FN(td_process_jump_backward),
    [TD_JUMP_FORWARD]        = ACTION_TAP_DANCE_FN(td_process_jump_forward),
    [TD_NEW_WINDOW]          = ACTION_TAP_DANCE_FN(td_process_new_window),
    [TD_SEARCH]              = ACTION_TAP_DANCE_FN(td_process_search),
    [TD_SELECTION_BACKWARD]  = ACTION_TAP_DANCE_FN(td_process_selection_backward),
    [TD_SELECTION_FORWARD]   = ACTION_TAP_DANCE_FN(td_process_selection_forward),
    [TD_TAB_CLOSE]           = ACTION_TAP_DANCE_FN(td_process_tab_close),
    [TD_TAB_NEW]             = ACTION_TAP_DANCE_FN(td_process_tab_new),
    [TD_COPY]                = ACTION_TAP_DANCE_FN(td_process_copy),
    [TD_CUT]                 = ACTION_TAP_DANCE_FN(td_process_cut),
}; // clang-format on
