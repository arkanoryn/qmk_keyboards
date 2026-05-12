# Step 04 — Implement Accents Layer

**Priority**: HIGH — the accents layer is currently a stub (`__TMP_EMPTY`).

## Problem Summary

The `_ACCENTS` layer in keymap.c uses `__TMP_EMPTY` (all `KC_0`). V1 has a fully implemented accents layer with French accents (é, è, ê, ç, à, â, ù, û, î, ï, ô) using OS-aware dead key sequences.

## Reference

- V1 layer definition: `users/v1/layers/accents.h`
- V1 accent processing: `users/v1/symbols/accents.c`
- V1 dead key constants: `users/v1/symbols/symbols.h` (lines 43-57)
- V1 accent keycodes: `users/v1/symbols/symbols.h` `symbols_id_e` enum (lines 26-41)

## Tasks

### 4.1 Add accent keycodes to the actions enum

**File**: `users/v2/features/actions/actions.h`

Add these entries to the `actions_id_e` enum, **before** `_LAST_ACTION_ID`:

```c
    /* French Accents */
    E_CIRC,       /* ê */
    E_AIGU,       /* é */
    C_CEDILLE,    /* ç */
    U_GRAVE,      /* ù */
    E_GRAVE,      /* è */
    U_CIRC,       /* û */
    I_CIRC,       /* î */
    A_GRAVE,      /* à */
    A_CIRC,       /* â */
    I_TREMA,      /* ï */
    O_CIRC,       /* ô */
    EURO,         /* € */
```

These names match v1's enum exactly. The `CKC()` macro converts them to custom keycodes.

### 4.2 Create `users/v2/features/accents/accents.h`

```c
/* [copyright header] */

#pragma once

#include QMK_KEYBOARD_H
#include "os_detection.h"

/* OS-aware dead key constants */
#define WIN_CIRCONFLEXE         A(S(KC_6))
#define WIN_AIGU                A(KC_QUOTE)
#define WIN_GRAVE               A(KC_GRAVE)
#define WIN_TREMA               A(S(KC_QUOTE))
#define WIN_CEDILLE             A(KC_QUOTE)
#define MAC_CIRCONFLEXE         LOPT(KC_I)
#define MAC_AIGU                LOPT(KC_E)
#define MAC_GRAVE               LOPT(KC_GRAVE)
#define MAC_TREMA               LOPT(KC_U)
#define CIRCONFLEXE             (detected_host_os() == OS_MACOS ? MAC_CIRCONFLEXE : WIN_CIRCONFLEXE)
#define AIGU                    (detected_host_os() == OS_MACOS ? MAC_AIGU : WIN_AIGU)
#define GRAVE                   (detected_host_os() == OS_MACOS ? MAC_GRAVE : WIN_GRAVE)
#define TREMA                   (detected_host_os() == OS_MACOS ? MAC_TREMA : WIN_TREMA)
#define WIN_EUR                 SS_LCTL(SS_LALT("5"))
#define MAC_EUR                 SS_LALT(SS_LSFT("2"))

bool process_accents(uint16_t keycode, keyrecord_t *record);
```

### 4.3 Create `users/v2/features/accents/accents.c`

Port directly from `users/v1/symbols/accents.c`. The full implementation:

```c
/* [copyright header] */

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "farkann_v2.h"
#include "accents.h"
#include "features/actions/actions.h"

static void process_accent(uint16_t accent_str, uint8_t letter_code) {
    const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    if (mods & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        tap_code16(accent_str);
        add_mods(MOD_MASK_SHIFT);
    } else {
        tap_code16(accent_str);
    }
    tap_code16(letter_code);
}

bool process_accents(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) { return true; }

    switch (keycode) {
        case CKC(E_CIRC):    process_accent(CIRCONFLEXE, KC_E); return false;
        case CKC(E_AIGU):    process_accent(AIGU, KC_E);        return false;
        case CKC(U_GRAVE):   process_accent(GRAVE, KC_U);       return false;
        case CKC(E_GRAVE):   process_accent(GRAVE, KC_E);       return false;
        case CKC(U_CIRC):    process_accent(CIRCONFLEXE, KC_U); return false;
        case CKC(I_CIRC):    process_accent(CIRCONFLEXE, KC_I); return false;
        case CKC(A_GRAVE):   process_accent(GRAVE, KC_A);       return false;
        case CKC(A_CIRC):    process_accent(CIRCONFLEXE, KC_A); return false;
        case CKC(I_TREMA):   process_accent(TREMA, KC_I);       return false;
        case CKC(O_CIRC):    process_accent(CIRCONFLEXE, KC_O); return false;
        case CKC(C_CEDILLE):
            if (detected_host_os() == OS_MACOS) {
                tap_code16(A(KC_C));
            } else {
                process_accent(WIN_CEDILLE, KC_C);
            }
            return false;
        case CKC(EURO):
            if (detected_host_os() == OS_MACOS) {
                send_string(MAC_EUR);
            } else {
                send_string(WIN_EUR);
            }
            return false;
        default:
            return true;
    }
}
```

### 4.4 Create `users/v2/layers/accents.h`

Port from `users/v1/layers/accents.h`. The v2 version for the Cosmos Dactyl (THUMBCLUSTER_LEFT=6, THUMBCLUSTER_RIGHT=4):

```c
/* [copyright header] */

#pragma once

#include QMK_KEYBOARD_H

/* Left side: utility keys + punctuation */
#define __________ACCENTS_LEFT_ROW_1________ CW_TOGG, KC_ASTR, KC_AMPR, KC_PERCENT, CKC(CMD_REDO)
#define __________ACCENTS_LEFT_ROW_2________ KC_TAB,  KC_DQUO, KC_EXLM, KC_QUES,    CKC(CMD_UNDO)
#define __________ACCENTS_LEFT_ROW_3________ __X__,   __X__,   __X__,   __X__,       __X__

/* Right side: French accented characters */
#define _________ACCENTS_RIGHT_ROW_1________ __X__, CKC(E_CIRC),    CKC(U_GRAVE), CKC(I_CIRC),  CKC(I_TREMA)
#define _________ACCENTS_RIGHT_ROW_2________ __X__, CKC(E_AIGU),    CKC(E_GRAVE), CKC(A_GRAVE), CKC(O_CIRC)
#define _________ACCENTS_RIGHT_ROW_3________ __X__, CKC(C_CEDILLE), CKC(U_CIRC),  CKC(A_CIRC),  __X__

#define ___ACCENTS_ROW_1___ __________ACCENTS_LEFT_ROW_1________, _________ACCENTS_RIGHT_ROW_1________
#define ___ACCENTS_ROW_2___ __________ACCENTS_LEFT_ROW_2________, _________ACCENTS_RIGHT_ROW_2________
#define ___ACCENTS_ROW_3___ __________ACCENTS_LEFT_ROW_3________, _________ACCENTS_RIGHT_ROW_3________

/* Thumb cluster for accents layer (Cosmos Dactyl: 6L + 4R) */
#define ___ACCENTS_THUMBS__________ __X__, KC_LSFT, __X__, __X__, QK_LLCK, __X__, __X__, __X__, __X__, __X__
```

Note: The thumb uses `QK_LLCK` (native QMK Layer Lock) instead of v1's custom `LAYER_LOCK`.

### 4.5 Update `layers.h` to include accents

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/layers.h`

Uncomment line 26:
```c
#include "layers/accents.h"
```

### 4.6 Update keymap.c

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/keymap.c`

Replace the `_ACCENTS` layer entry:

```c
    [_ACCENTS] = LAYOUT(
#ifdef FARKANN_NUMBER_ROW
        __TMP_EMPTY,
#endif
        ___ACCENTS_ROW_1___, ___ACCENTS_ROW_2___, ___ACCENTS_ROW_3___, __EXTRA_ROW__, ___ACCENTS_THUMBS__________),
```

### 4.7 Enable the feature flag

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/config.h`

Uncomment line 38:
```c
#define FARKANN_FRENCH_ACCENTS
```

### 4.8 Add to rules.mk and process chain

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`
```makefile
SRC += features/accents/accents.c
```

**File**: `users/v2/process_record.c` — add to chain after `process_actions`:
```c
#include "features/accents/accents.h"

/* In the chain, after process_actions: */
if (!process_accents(keycode, record)) { return false; }
```

### 4.9 Add accent entries to the `actions[]` table

**File**: `users/v2/features/actions/actions.c`

The new accent enum entries will cause the `static_assert` on line 59 to fail because the `actions[]` table doesn't have rows for them. Add empty placeholder rows for the accent keycodes (they are NOT dispatched through the table — they have their own `process_accents` handler):

```c
    [E_CIRC]    = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [E_AIGU]    = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [C_CEDILLE] = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [U_GRAVE]   = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [E_GRAVE]   = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [U_CIRC]    = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [I_CIRC]    = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [A_GRAVE]   = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [A_CIRC]    = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [I_TREMA]   = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [O_CIRC]    = {.on_linux = "", .on_macOS = "", .on_windows = ""},
    [EURO]      = {.on_linux = "", .on_macOS = "", .on_windows = ""},
```

This is necessary because the `actions[]` array is sized by `_LAST_ACTION_ID` and the `static_assert` validates the count. The accents are intercepted by `process_accents()` in the process chain BEFORE `process_actions()` reaches them, so the empty table entries are never used.

**Alternative (cleaner)**: Move accent enum values to a separate enum AFTER `_LAST_ACTION_ID` so they don't inflate the actions table. This requires changing `_FIRST_COMBO_ID` to use the new last accent ID. Choose this approach if you prefer not to have empty rows.

**Decision**: Use the placeholder rows approach (simpler, no enum restructuring needed).

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Flash and test: activate accents layer, press accent keys, verify correct characters appear on macOS and Linux/Windows.

## Files Created/Modified

| File | Action |
|------|--------|
| `users/v2/features/accents/accents.h` | CREATE |
| `users/v2/features/accents/accents.c` | CREATE |
| `users/v2/layers/accents.h` | CREATE |
| `users/v2/features/actions/actions.h` | EDIT — add accent keycodes to enum |
| `users/v2/features/actions/actions.c` | EDIT — add placeholder rows to actions[] table |
| `keyboards/.../keymaps/v2/layers.h` | EDIT — uncomment accents include |
| `keyboards/.../keymaps/v2/keymap.c` | EDIT — replace stub with accent rows |
| `keyboards/.../keymaps/v2/config.h` | EDIT — uncomment FARKANN_FRENCH_ACCENTS |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT — add SRC |
| `users/v2/process_record.c` | EDIT — add to chain |
