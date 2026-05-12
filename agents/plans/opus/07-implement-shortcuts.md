# Step 07 — Verify and Complete OS-Aware Shortcuts

**Priority**: LOW (was HIGH) — V2's actions module already implements all 32 shortcuts from v1 using the table-driven `actions[]` array. No new shortcuts need to be added.

## Status: ALREADY IMPLEMENTED

V2's `features/actions/actions.c` already contains the complete `actions[]` table with all 32 OS-aware shortcuts from v1:

| Category | Actions |
|----------|---------|
| App management | ALFRED, APP_CLOSE, APP_NEW_WINDOW, APP_NEW_WINDOW_INCOGNITO, APP_NEXT, APP_PREV, TASK_MNGR |
| Commands | CMD_COPY, CMD_CUT, CMD_PASTE, CMD_REDO, CMD_SAVE, CMD_SEARCH, CMD_SEARCH_ALL, CMD_SELECT_ALL, CMD_UNDO |
| Line operations | LINE_BACKSPACE, LINE_DEL, LINE_JUMPL, LINE_JUMPR, LINE_SELECTL, LINE_SELECTR |
| Tab management | TAB_CLOSE, TAB_NEW, TAB_REOPEN |
| Window management | WINDOW_CLOSE |
| Word operations | WORD_BACKSPACE, WORD_DEL, WORD_JUMPL, WORD_JUMPR, WORD_SELECTL, WORD_SELECTR |

Each entry in the `actions[]` table defines `.on_linux`, `.on_macOS`, and `.on_windows` strings. The `send_action()` function dispatches based on `detected_host_os()`. This is the correct table-driven pattern.

## Remaining Tasks (minor)

### 7.1 Fix `assert.h` usage

Already covered in Step 01 (task 1.3). No action needed here — just verify it was done.

### 7.2 Enable APP_NEXT/APP_PREV alt-tab handling

**File**: `users/v2/features/actions/actions.c`, lines 108-111 and 131-134

Uncomment the `process_tabbing` cases for `APP_NEXT` and `APP_PREV`, and uncomment the alt-tab unregister block (lines 131-134). This enables the timer-based alt-tab feature that auto-releases the Cmd/Alt modifier after `ALT_TAB_TIMER` ms.

```c
/* Uncomment these lines: */
case APP_NEXT:
case APP_PREV:
    process_tabbing(id, record);
    return false;
```

And:
```c
/* Uncomment these lines: */
if (alt_tab_state.active && !record->event.pressed) {
    unregister_code(CMD_OR_ALT);
    alt_tab_state.active = false;
}
```

### 7.3 Ensure actions layer uses the table

**File**: `users/v2/layers/actions.h`

Verify all action keys on the Actions layer reference `CKC(ACTION_NAME)` from the enum — they should **not** use raw keycodes like `LCTL(KC_C)`. The whole point of the table-driven system is that layer keys use `CKC(CMD_COPY)` etc., and the `process_actions()` function dispatches through the `actions[]` table to get OS-aware behavior.

Any future shortcuts must be added by:
1. Adding an entry to the `actions_id_e` enum in `actions.h`
2. Adding a row to the `actions[]` table in `actions.c` (with `.on_linux`, `.on_macOS`, `.on_windows`)
3. Placing `CKC(NEW_ACTION)` on the appropriate layer

Never hardcode OS-specific keycodes directly in layer definitions.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

## Files Modified

| File | Action |
|------|--------|
| `users/v2/features/actions/actions.c` | EDIT — remove `assert.h`, fix runtime assert, optionally uncomment alt-tab |
