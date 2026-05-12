# Step 03 — Implement `process_record_user`

**Priority**: CRITICAL — without this, no custom keycodes work (Magic, Arcane, Actions, Layer Lock — all dead code).

## Problem Summary

V2 has no `process_record_user()` function anywhere. In v1, this function chains ~9 feature processors together. V2 needs the same pattern adapted for its feature set.

## Background

QMK calls `process_record_user(uint16_t keycode, keyrecord_t *record)` for every key event. Returning `false` stops further processing; returning `true` continues. Features are chained: if one returns `false`, later ones don't run.

V1 chain order: `sentence_case → chord_teacher → magic_key → layer_lock → shortcuts → symbols → select_word → graphite_keys → config`

## Tasks

### 3.1 Create `users/v2/process_record.h`

```c
/* [copyright header] */

#pragma once

#include QMK_KEYBOARD_H

bool process_record_v2(uint16_t keycode, keyrecord_t *record);
```

### 3.2 Create `users/v2/process_record.c`

```c
/* [copyright header] */

#include "farkann_v2.h"
#include "process_record.h"
#include "features/repeat/repeat.h"
#include "features/actions/actions.h"

#ifdef CHORD_TEACHER_ENABLE
#    include "features/chord_teacher/chord_teacher.h"
#endif

bool process_record_v2(uint16_t keycode, keyrecord_t *record) {
    /* Chain feature processors. Order matters.
    ** Each returns false to stop processing, true to continue.
    */

#ifdef CHORD_TEACHER_ENABLE
    if (!process_chord_teacher(keycode, record)) { return false; }
#endif

    if (!process_repeat_keys(keycode, record)) { return false; }
    if (!process_actions(keycode, record)) { return false; }

    /* Future features will be added here:
    ** if (!process_accents(keycode, record)) { return false; }
    ** if (!process_symbols(keycode, record)) { return false; }
    */

    return true;
}
```

### 3.3 Add `process_record_user` to `keymap.c`

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/keymap.c`

Add at the end of the file (before the closing of combo functions or after `keyboard_post_init_user`):

```c
#include "process_record.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_v2(keycode, record);
}
```

**Why a separate file instead of inline?** Keeping the processing chain in `users/v2/` means it's shared if you ever add another keyboard to v2, and keymap.c stays focused on layout.

### 3.4 Add to rules.mk

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

Add `process_record.c` to the SRC list:

```makefile
SRC += process_record.c
```

### 3.5 Placeholder for future features

The `process_record_v2` chain will grow as later steps add features. For now, only `process_repeat_keys` and `process_actions` are in the chain. The commented-out lines in the template (step 3.2) show where future features will be inserted. Do NOT add a `LAYER_LOCK` handler — Layer Lock will use QMK's native `QK_LLCK` keycode (see Step 06), which requires no custom processing.

### 3.6 Implement `remember_last_key_user` (for Magic/Arcane)

QMK's repeat key system tracks the last pressed keycode. Magic and Arcane should be excluded from this tracking so pressing Magic doesn't make the "last key" be Magic itself.

**Add to `users/v2/process_record.c`**, after the `process_record_v2` function:

```c
bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case SFT_MAGIC:
        case MAGIC:
        case ALT_ARCANE:
        case ARCANE:
            return false; /* Don't track these as "last key" */
    }
    return true;
}
```

This function is a QMK callback — just defining it is enough; QMK calls it automatically.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Then flash to hardware and test:
- Press a letter, then tap the Magic thumb key → should output the magic continuation
- Press a letter, then tap the Arcane thumb key → should output the arcane continuation
- Action layer keys should work (OS-aware shortcuts)

## Files Created/Modified

| File | Action |
|------|--------|
| `users/v2/process_record.h` | CREATE |
| `users/v2/process_record.c` | CREATE |
| `keyboards/.../keymaps/v2/keymap.c` | EDIT — add process_record_user |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT — add SRC entry |
