/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

#include <assert.h>
#include QMK_KEYBOARD_H
#include "farkann_v2.h"
#include "actions.h"

// clang-format off
// Cross-platform action definitions
const action_s actions[] = {
    [ALFRED]                   = {.on_linux = SS_LGUI(" "),                             .on_macOS = SS_LCMD(" "),                       .on_windows = SS_LGUI(" ")},
    [APP_CLOSE]                = {.on_linux = SS_LGUI("q"),                             .on_macOS = SS_LCMD("q"),                       .on_windows = SS_LALT(SS_TAP(X_F4))},
    [APP_NEW_WINDOW_INCOGNITO] = {.on_linux = SS_LCTL(SS_LSFT("n")),                    .on_macOS = SS_LCMD(SS_LSFT("n")),              .on_windows = SS_LCTL(SS_LSFT("n"))},
    [APP_NEW_WINDOW]           = {.on_linux = SS_LCTL("n"),                             .on_macOS = SS_LCMD("n"),                       .on_windows = SS_LCTL("n")},
    [APP_NEXT]                 = {.on_linux = SS_TAP(X_TAB),                            .on_macOS = SS_TAP(X_TAB),                      .on_windows = SS_TAP(X_TAB)},
    [APP_PREV]                 = {.on_linux = SS_LSFT(SS_TAP(X_TAB)),                   .on_macOS = SS_LSFT(SS_TAP(X_TAB)),             .on_windows = SS_LSFT(SS_TAP(X_TAB))},
    [CMD_COPY]                 = {.on_linux = SS_LCTL("c"),                             .on_macOS = SS_LCMD("c"),                       .on_windows = SS_LCTL("c")},
    [CMD_CUT]                  = {.on_linux = SS_LCTL("x"),                             .on_macOS = SS_LCMD("x"),                       .on_windows = SS_LCTL("x")},
    [CMD_PASTE]                = {.on_linux = SS_LCTL("v"),                             .on_macOS = SS_LCMD("v"),                       .on_windows = SS_LCTL("v")},
    [CMD_REDO]                 = {.on_linux = SS_LCTL("y"),                             .on_macOS = SS_LCMD(SS_LSFT("z")),              .on_windows = SS_LCTL("y")},
    [CMD_SAVE]                 = {.on_linux = SS_LCTL("s"),                             .on_macOS = SS_LCMD("s"),                       .on_windows = SS_LCTL("s")},
    [CMD_SEARCH_ALL]           = {.on_linux = SS_LCTL(SS_LSFT("f")),                    .on_macOS = SS_LCMD(SS_LSFT("f")),              .on_windows = SS_LCTL(SS_LSFT("f"))},
    [CMD_SEARCH]               = {.on_linux = SS_LCTL("f"),                             .on_macOS = SS_LCMD("f"),                       .on_windows = SS_LCTL("f")},
    [CMD_UNDO]                 = {.on_linux = SS_LCTL("z"),                             .on_macOS = SS_LCMD("z"),                       .on_windows = SS_LCTL("z")},
    [CMD_SELECT_ALL]           = {.on_linux = SS_LCTL("a"),                             .on_macOS = SS_LCMD("a"),                       .on_windows = SS_LCTL("a")},
    [LINE_BACKSPACE]           = {.on_linux = SS_LCTL(SS_LSFT(SS_TAP(X_BACKSPACE))),    .on_macOS = SS_LCMD(SS_TAP(X_BACKSPACE)),       .on_windows = SS_LCTL(SS_LSFT(SS_TAP(X_BACKSPACE)))},
    [LINE_DEL]                 = {.on_linux = SS_LCTL(SS_LSFT(SS_TAP(X_DELETE))),       .on_macOS = SS_LCMD(SS_TAP(X_DELETE)),          .on_windows = SS_LCTL(SS_LSFT(SS_TAP(X_DELETE)))},
    [LINE_JUMPL]               = {.on_linux = SS_TAP(X_HOME),                           .on_macOS = SS_LCMD(SS_TAP(X_LEFT)),            .on_windows = SS_TAP(X_HOME)},
    [LINE_JUMPR]               = {.on_linux = SS_TAP(X_END),                            .on_macOS = SS_LCMD(SS_TAP(X_RIGHT)),           .on_windows = SS_TAP(X_END)},
    [LINE_SELECTL]             = {.on_linux = SS_LSFT(SS_TAP(X_HOME)),                  .on_macOS = SS_LCMD(SS_LSFT(SS_TAP(X_LEFT))),   .on_windows = SS_LSFT(SS_TAP(X_HOME))},
    [LINE_SELECTR]             = {.on_linux = SS_LSFT(SS_TAP(X_END)),                   .on_macOS = SS_LCMD(SS_LSFT(SS_TAP(X_RIGHT))),  .on_windows = SS_LSFT(SS_TAP(X_END))},
    [TAB_CLOSE]                = {.on_linux = SS_LCTL("w"),                             .on_macOS = SS_LCMD("w"),                       .on_windows = SS_LCTL("w")},
    [TAB_NEW]                  = {.on_linux = SS_LCTL("t"),                             .on_macOS = SS_LCMD("t"),                       .on_windows = SS_LCTL("t")},
    [TAB_REOPEN]               = {.on_linux = SS_LCTL(SS_LSFT("t")),                    .on_macOS = SS_LCMD(SS_LSFT("t")),              .on_windows = SS_LCTL(SS_LSFT("t"))},
    [TASK_MNGR]                = {.on_linux = SS_LCTL(SS_LALT(SS_TAP(X_DEL))),          .on_macOS = SS_LCMD(SS_LOPT(SS_TAP(X_ESC))),    .on_windows = SS_LCTL(SS_LALT(SS_TAP(X_DEL)))},
    [WINDOW_CLOSE]             = {.on_linux = SS_LGUI(SS_LSFT("q")),                    .on_macOS = SS_LCMD(SS_LSFT("w")),              .on_windows = SS_LCTL(SS_LSFT("w"))},
    [WORD_BACKSPACE]           = {.on_linux = SS_LCTL(SS_TAP(X_BACKSPACE)),             .on_macOS = SS_LALT(SS_TAP(X_BACKSPACE)),       .on_windows = SS_LCTL(SS_TAP(X_BACKSPACE))},
    [WORD_DEL]                 = {.on_linux = SS_LCTL(SS_TAP(X_DELETE)),                .on_macOS = SS_LALT(SS_TAP(X_DELETE)),          .on_windows = SS_LCTL(SS_TAP(X_DELETE))},
    [WORD_JUMPL]               = {.on_linux = SS_LCTL(SS_TAP(X_LEFT)),                  .on_macOS = SS_LALT(SS_TAP(X_LEFT)),            .on_windows = SS_LCTL(SS_TAP(X_LEFT))},
    [WORD_JUMPR]               = {.on_linux = SS_LCTL(SS_TAP(X_RIGHT)),                 .on_macOS = SS_LALT(SS_TAP(X_RIGHT)),           .on_windows = SS_LCTL(SS_TAP(X_RIGHT))},
    [WORD_SELECTL]             = {.on_linux = SS_LSFT(SS_TAP(X_LEFT)),                  .on_macOS = SS_LALT(SS_LSFT(SS_TAP(X_LEFT))),   .on_windows = SS_LSFT(SS_TAP(X_LEFT))},
    [WORD_SELECTR]             = {.on_linux = SS_LSFT(SS_TAP(X_RIGHT)),                 .on_macOS = SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))),  .on_windows = SS_LSFT(SS_TAP(X_RIGHT))},
};
// clang-format on
static_assert(ARRAY_SIZE(actions) == _LAST_ACTION_ID, "Mismatch"); // ensure that we have all the actions from the enum

// Alt-tab state and processing
#define CMD_OR_ALT (detected_host_os() == OS_MACOS ? KC_LCMD : KC_LALT)
alt_tab_s alt_tab_state = {0};

void send_action(actions_id_e id) {
  action_s     action      = actions[id];
  os_variant_t detected_os = detected_host_os();

  if (detected_os == OS_MACOS) {
    send_string(action.on_macOS);
  } else if (detected_os == OS_WINDOWS) {
    send_string(action.on_windows);
  } else if (detected_os == OS_LINUX) {
    send_string(action.on_linux);
  }
}

void init_alt_tab_state(void) {
  alt_tab_state.active = false;
  alt_tab_state.timer  = 0;
}

void alt_tab_task(void) {
  if (alt_tab_state.active) {
    if (timer_elapsed(alt_tab_state.timer) > ALT_TAB_TIMER) {
      unregister_code(CMD_OR_ALT);
      alt_tab_state.active = false;
    }
  }
}

void process_tabbing(actions_id_e id, keyrecord_t *record) {
  if (record->event.pressed) {
    alt_tab_state.timer = timer_read();

    if (!alt_tab_state.active) {
      alt_tab_state.active = true;
      register_code(CMD_OR_ALT);
    }
    send_action(id);
  }
}

bool process_one_action(actions_id_e id, keyrecord_t *record) {
  assert(id < _LAST_ACTION_ID);

  switch (id) {
    // case APP_NEXT:
    // case APP_PREV:
    //   process_tabbing(id, record);
    //   return false;
    default:
      if (!record->event.pressed) {
        return true;
      }

      send_action(id);
      return false;
  }
  return true;
}

bool process_actions(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CKC(_FIRST_ACTION_ID)... CKC(_LAST_ACTION_ID) - 1:
      return process_one_action(keycode - CKC(_FIRST_ACTION_ID), record);
  }

  // alt tab is a special shortcuts and we want to unregister the ALT / CMD
  //   if the feature is active and the layer-key is released
  //   if (alt_tab_state.active && !record->event.pressed) {
  //     unregister_code(CMD_OR_ALT);
  //     alt_tab_state.active = false;
  //   }
  return true;
}
