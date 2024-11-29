/**
 * @file shortcuts.h
 * @brief Shortcuts, a script to manage most-used shortcuts in macOS and winOS.
 *
 * Overview
 * --------
 * TODO
 *
 * Configuration
 * -------------
 *
 * In your keymap.c or other main header:
 * - Define `_FIRST_SHORTCUT_ID` that should be either 0 or the _LAST_* from another `SAFE_RANGE`.
 * - Ensure that you have a KEYMAP_MAIN_H that is linked to your main header.
 * - call `void init_alt_tab_state(void);` in the `keyboard_post_init_user` function.
 * - Add this file to your SRC in `rules.mk`
 */
#pragma once

#include QMK_KEYBOARD_H
#include "ark_v1.h" // TODO: should be KEYMAP_MAIN_H

#ifndef ALT_TAB_TIMER
#  define ALT_TAB_TIMER 5000 // miliseconds
#endif                       // ALT_TAB_TIMER

/*
 * The struct used by the script to determine in which OS we are running
 * and run the script accordingly.
 */
typedef struct {
  const char *on_macOS;
  const char *on_winOS;
} action_s;

typedef struct {
  bool     active;
  uint16_t timer;
} alt_tab_s;

// clang-format off
typedef enum {
  ALFRED = _FIRST_SHORTCUT_ID,
  APP_CLOSE,
  APP_NEW_WINDOW_INCOGNITO,
  APP_NEW_WINDOW,
  APP_NEXT,
  APP_PREV,
  CMD_COPY,
  CMD_CUT,
  CMD_PASTE,
  CMD_REDO,
  CMD_SAVE,
  CMD_SEARCH_ALL,
  CMD_SEARCH,
  CMD_UNDO,
  CMD_SELECT_ALL,
  LINE_BACKSPACE,
  LINE_DEL,
  LINE_JUMPL,
  LINE_JUMPR,
  LINE_SELECTL,
  LINE_SELECTR,
  TAB_CLOSE,
  TAB_NEW,
  TAB_REOPEN,
  TASK_MNGR,
  WINDOW_CLOSE,
  WORD_BACKSPACE,
  WORD_DEL,
  WORD_JUMPL,
  WORD_JUMPR,
  WORD_SELECTL,
  WORD_SELECTR,
  _LAST_SHORTCUT_ID
} shortcuts_id_e;
// clang-format on

/**
 * Handler function for Shortcuts that work in both macOS and winOS.
 *
 *     #include "shortcuts/shortcuts.h"
 *
 *     bool process_record_user(uint16_t keycode, keyrecord_t* record) {
 *       if (!process_shortcuts(keycode, record)) { return false; }
 *       // Your macros ...
 *
 *       return true;
 *     }
 */
bool process_shortcuts(uint16_t keycode, keyrecord_t *record);
void init_alt_tab_state(void);
void alt_tab_task(void);
void send_action(shortcuts_id_e id);
