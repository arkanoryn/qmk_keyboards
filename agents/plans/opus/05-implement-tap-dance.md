# Step 05 — Implement Tap Dances

**Priority**: HIGH — the Actions layer has `KC_0` placeholders where tap dances should be.

## Problem Summary

V1 defines 11 tap dances (Esc, Search, Tab New/Close, New Window, Jump Fwd/Bwd, Selection Fwd/Bwd, Copy, Cut). V2's actions layer has commented-out references like `// TD(TD_ESC)` replaced with `KC_0`.

## Reference

- V1 implementation: `users/v1/tap_dance/tap_dance.c`
- V1 actions layer: `users/v1/layers/actions.h` (shows where tap dances are placed)

## Tasks

### 5.1 Create `users/v2/features/tap_dance/tap_dance.h`

```c
/* [copyright header] */

#pragma once

#include QMK_KEYBOARD_H

/* Tap dance enum */
enum tap_dances {
    TD_ESC,          /* 1-tap: Esc, 2-tap: Caps Lock */
    TD_SEARCH,       /* 1-tap: Cmd/Ctrl+F, 2-tap: Cmd/Ctrl+Shift+F */
    TD_TAB_NEW,      /* 1-tap: new tab, 2-tap: restore tab */
    TD_TAB_CLOSE,    /* 1-tap: close tab, 2-tap: close window */
    TD_NEW_WINDOW,   /* 1-tap: new window, hold: new incognito */
    TD_JUMP_FWD,     /* Forward word/line jumping with acceleration */
    TD_JUMP_BWD,     /* Backward word/line jumping with acceleration */
    TD_SEL_FWD,      /* Forward selection with acceleration */
    TD_SEL_BWD,      /* Backward selection with acceleration */
    TD_COPY,         /* 1-tap: copy, 2-tap: copy line */
    TD_CUT,          /* 1-tap: cut, 2-tap: cut line */
};
```

### 5.2 Create `users/v2/features/tap_dance/tap_dance.c`

Port from `users/v1/tap_dance/tap_dance.c`. The v1 implementation uses:
- `ACTION_TAP_DANCE_FN_ADVANCED()` for complex tap dances
- OS detection for platform-specific shortcuts
- Timer-based acceleration for jump/selection dances

Copy the v1 implementation and adapt:
- Update includes to use v2 paths
- Use v2's OS detection from `actions.c`

### 5.3 Update the Actions layer

**File**: `users/v2/layers/actions.h`

Replace all `KC_0 // TD(TD_XXX)` placeholders with actual `TD(TD_XXX)` calls:

```c
/* Example: replace */
KC_0, /* // TD(TD_ESC) */
/* with */
TD(TD_ESC),
```

### 5.4 Enable tap dance in rules.mk

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

Add:
```makefile
TAP_DANCE_ENABLE = yes
```

And add to SRC:
```makefile
SRC += features/tap_dance/tap_dance.c
```

### 5.5 Update includes

The tap dance header needs to be included where `TD()` is used. Ensure `layers/actions.h` includes the tap dance header or that it's included via `farkann_v2.h`.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Flash and test each tap dance on the actions layer.

## Files Created/Modified

| File | Action |
|------|--------|
| `users/v2/features/tap_dance/tap_dance.h` | CREATE |
| `users/v2/features/tap_dance/tap_dance.c` | CREATE |
| `users/v2/layers/actions.h` | EDIT — replace KC_0 placeholders |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT — enable tap dance + SRC |
