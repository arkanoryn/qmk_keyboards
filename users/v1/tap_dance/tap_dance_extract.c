#include QMK_KEYBOARD_H
#include "tap_dance.h"
#include "selection/selection.h"
#include "jump_cursor/jump.h"

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
    // DELETE
    // BSPC
    // CTRL+UP
    // CTRL+DOWN
    // INSERT NEW LINE UP
    // INSERT NEW LINE DOWN
    // JOIN LINES
    // PRINT SCREEN
    // REFRESH PAGE
    // RENAME
    // CTRL / CMD + 1=2=3=4
}; // clang-format on
