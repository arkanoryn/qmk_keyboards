#include <assert.h>

#include QMK_KEYBOARD_H
#include "os_detection.h"

#include "ark_v1.h"
#include "shortcuts.h"

const action_s actions[] = {
    // [CMD_COPY]               = { .on_macOS = "this is macOS",                 .on_winOS =     "this is winOS"}, // for testing purpose, replace the key with the one you want
    [CMD_COPY]       = {.on_macOS = SS_LCMD("c"), .on_winOS = SS_LCTL("c")},
    [CMD_PASTE]      = {.on_macOS = SS_LCMD("v"), .on_winOS = SS_LCTL("v")},
    [CMD_CUT]        = {.on_macOS = SS_LCMD("x"), .on_winOS = SS_LCTL("x")},
    [LD_SELECT_ALL]  = {.on_macOS = SS_LCMD("a"), .on_winOS = SS_LCTL("a")},
    [TAB_CLOSE]      = {.on_macOS = SS_LCMD("w"), .on_winOS = SS_LCTL("w")},
    [TAB_NEW]        = {.on_macOS = SS_LCMD("t"), .on_winOS = SS_LCTL("t")},
    [TAB_REOPEN]     = {.on_macOS = SS_LCMD(SS_LSFT("t")), .on_winOS = SS_LCTL(SS_LSFT("t"))},
    [LD_SAVE]        = {.on_macOS = SS_LCMD("s"), .on_winOS = SS_LCTL("s")},
    [CMD_UNDO]       = {.on_macOS = SS_LCMD("z"), .on_winOS = SS_LCTL("z")},
    [CMD_REDO]       = {.on_macOS = SS_LCMD(SS_LSFT("z")), .on_winOS = SS_LCTL(SS_LSFT("z"))},
    [LD_SEARCH]      = {.on_macOS = SS_LCMD("f"), .on_winOS = SS_LCTL("f")},
    [APP_CLOSE]      = {.on_macOS = SS_LCMD("q"), .on_winOS = SS_LALT(SS_TAP(X_F4))},
    [APP_NEXT]       = {.on_macOS = SS_TAP(X_TAB), .on_winOS = SS_TAP(X_TAB)},
    [APP_NEW_WINDOW] = {.on_macOS = SS_LCMD("n"), .on_winOS = SS_LCTL("n")},
    [APP_PREV]       = {.on_macOS = SS_LSFT(SS_TAP(X_TAB)), .on_winOS = SS_LSFT(SS_TAP(X_TAB))},
    [LINE_BACKSPACE] = {.on_macOS = SS_LCMD(SS_TAP(X_BACKSPACE)), .on_winOS = SS_LCTL(SS_LSFT(SS_TAP(X_BACKSPACE)))}, // not working on windows. Maybe do it in 2 steps: select then delete?
    [LINE_DEL]       = {.on_macOS = SS_LCMD(SS_TAP(X_DELETE)), .on_winOS = SS_LCTL(SS_LSFT(SS_TAP(X_DELETE)))},       // not working on widows. Maybe do it in 2 steps: select then delete?
    [LINE_JUMPL]     = {.on_macOS = SS_LCMD(SS_TAP(X_LEFT)), .on_winOS = SS_TAP(X_HOME)},
    [LINE_JUMPR]     = {.on_macOS = SS_LCMD(SS_TAP(X_RIGHT)), .on_winOS = SS_TAP(X_END)},
    [LINE_SELECTL]   = {.on_macOS = SS_LCMD(SS_LSFT(SS_TAP(X_LEFT))), .on_winOS = SS_LSFT(SS_TAP(X_HOME))},
    [LINE_SELECTR]   = {.on_macOS = SS_LCMD(SS_LSFT(SS_TAP(X_RIGHT))), .on_winOS = SS_LSFT(SS_TAP(X_END))},
    [WORD_BACKSPACE] = {.on_macOS = SS_LALT(SS_TAP(X_BACKSPACE)), .on_winOS = SS_LCTL(SS_TAP(X_BACKSPACE))},
    [WORD_DEL]       = {.on_macOS = SS_LALT(SS_TAP(X_DELETE)), .on_winOS = SS_LCTL(SS_TAP(X_DELETE))},
    [WORD_JUMPL]     = {.on_macOS = SS_LALT(SS_TAP(X_LEFT)), .on_winOS = SS_LCTL(SS_TAP(X_LEFT))},
    [WORD_JUMPR]     = {.on_macOS = SS_LALT(SS_TAP(X_RIGHT)), .on_winOS = SS_LCTL(SS_TAP(X_RIGHT))},
    [WORD_SELECTL]   = {.on_macOS = SS_LALT(SS_LSFT(SS_TAP(X_LEFT))), .on_winOS = SS_LSFT(SS_TAP(X_LEFT))},
    [WORD_SELECTR]   = {.on_macOS = SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))), .on_winOS = SS_LSFT(SS_TAP(X_RIGHT))},
    [TASK_MNGR]      = {.on_macOS = SS_LCMD(SS_LOPT(SS_TAP(X_ESC))), .on_winOS = SS_LCTL(SS_LALT(SS_TAP(X_DEL)))},
};
static_assert(ARRAY_SIZE(actions) == _LAST_SHORTCUT_ID, "Mismatch"); // ensure that we have all the actions from the enum

#define CMD_OR_ALT (detected_host_os() == OS_MACOS ? KC_LCMD : KC_LALT)
alt_tab_s alt_tab_state = {0};

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

void manage_tabbing(shortcuts_id_e id, keyrecord_t *record) {
  if (record->event.pressed) {
    alt_tab_state.timer = timer_read();

    if (!alt_tab_state.active) {
      alt_tab_state.active = true;
      register_code(CMD_OR_ALT);
    }
    send_string(detected_host_os() == OS_MACOS ? actions[id].on_macOS : actions[id].on_winOS);
  }
};

bool send_shortcut(shortcuts_id_e id, keyrecord_t *record) {
  assert(id < _LAST_SHORTCUT_ID);

  if (id == APP_NEXT || id == APP_PREV) {
    manage_tabbing(id, record);
  } else if (!record->event.pressed) {
    return true;
  } else {
    send_string(detected_host_os() == OS_MACOS ? actions[id].on_macOS : actions[id].on_winOS);
  }
  return false;
};

bool process_shortcuts(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CKC(0)... CKC(_LAST_SHORTCUT_ID) - 1:
      return send_shortcut(keycode - CKC(0), record);
  }

  // alt tab is a special shortcuts and we want to unregister the ALT / CMD
  //   if the feature is active and the layer-key is released
  if (alt_tab_state.active && !record->event.pressed) {
    unregister_code(CMD_OR_ALT);
    alt_tab_state.active = false;
  }
  return true;
};
