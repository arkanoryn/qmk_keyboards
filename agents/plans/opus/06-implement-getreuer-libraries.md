# Step 06 — Implement Getreuer Libraries and Native Layer Lock

**Priority**: HIGH — Layer Lock, Select Word, and Sentence Case are core usability features from v1.

## Problem Summary

V1 uses three Pascal Getreuer libraries:
1. **Layer Lock** — tap to lock current layer, 5-minute idle timeout
2. **Select Word** — single key to select word/line, OS-aware
3. **Sentence Case** — auto-capitalizes after sentence-ending punctuation

V2 defines `LAYER_LOCK` as a custom keycode but never processes it. The other two features are completely absent.

**Important**: Layer Lock is now a **native QMK feature** (since QMK added it upstream). We do NOT need to copy Getreuer's library for it — just enable the built-in feature. See: https://docs.qmk.fm/features/layer_lock

## Tasks

### 6.1 Enable native QMK Layer Lock

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

Add:
```makefile
LAYER_LOCK_ENABLE = yes
```

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/config.h`

Add:
```c
/* Layer Lock configuration — unlock after 5 minutes idle */
#define LAYER_LOCK_IDLE_TIMEOUT 300000
```

### 6.2 Replace custom `LAYER_LOCK` keycode with QMK's `QK_LLCK`

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/farkann_v2.h`

Remove `LAYER_LOCK` from the `custom_keycodes` enum:
```c
/* BEFORE */
enum custom_keycodes {
    LAYER_LOCK = NEW_SAFE_RANGE,
    MAGIC,
    ARCANE,
};

/* AFTER */
enum custom_keycodes {
    MAGIC = NEW_SAFE_RANGE,
    ARCANE,
};
```

Then, anywhere `LAYER_LOCK` is used in layer definitions, replace it with `QK_LLCK` (QMK's native Layer Lock keycode). Search all layer headers (`symbols.h`, `numpad_sound.h`, `fn.h`, etc.) for references.

No custom `process_record` handling is needed — QMK processes `QK_LLCK` automatically.

### 6.3 Add Layer Lock status callback (deferred to Step 11)

Skip this task for now. The `layer_lock_set_user()` callback will be added when the display is implemented in Step 11.

### 6.4 Copy Getreuer Select Word and Sentence Case

Layer Lock is native, but **Select Word** and **Sentence Case** are still third-party. Copy from v1:

```
users/v2/lib/getreuer/
├── select_word/
│   ├── select_word.h
│   └── select_word.c
└── sentence_case/
    ├── sentence_case.h
    ├── sentence_case.c
    └── override.c
```

Do NOT copy `layer_lock/` — it's no longer needed.

### 6.5 Wire Select Word and Sentence Case into process_record chain

**File**: `users/v2/process_record.c`

Add includes and chain calls:

```c
#include "lib/getreuer/select_word/select_word.h"
#include "lib/getreuer/sentence_case/sentence_case.h"

/* In the chain: */
if (!process_select_word(keycode, record, SEL_WORD)) { return false; }
if (!process_sentence_case(keycode, record)) { return false; }
```

Where `SEL_WORD` is a custom keycode (see task 6.7).

### 6.6 Add to rules.mk

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

```makefile
SRC += lib/getreuer/select_word/select_word.c \
       lib/getreuer/sentence_case/sentence_case.c \
       lib/getreuer/sentence_case/override.c
```

### 6.7 Add `SEL_WORD` custom keycode and place it on the Actions layer

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/farkann_v2.h`

Add `SEL_WORD` to the `custom_keycodes` enum:

```c
enum custom_keycodes {
    MAGIC = NEW_SAFE_RANGE,
    ARCANE,
    SEL_WORD,
};
```

**File**: `users/v2/layers/actions.h`

Place `SEL_WORD` on the Actions layer. In v1, it is accessible from the actions layer. Place it in the same position as v1's actions layer (check `users/v1/layers/actions.h` for the exact position and replicate it). If the exact position cannot be determined, place it on the right-hand home row pinky position on the Actions layer (row 2, column 10).

### 6.8 Implement `sentence_case_press_user` override

Copy `users/v1/getreuer/sentence_case/override.c` which customizes which keys count as sentence-ending punctuation.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Flash and test:
- **Layer Lock**: hold `MO(_SYMBOLS)`, tap `QK_LLCK`, release MO key — symbols layer stays active. Tap `QK_LLCK` again to unlock.
- **Select Word**: press key once for word selection, again for line
- **Sentence Case**: type a sentence ending with `.`, verify next letter is auto-capitalized

## Files Created/Modified

| File | Action |
|------|--------|
| `keyboards/.../keymaps/v2/rules.mk` | EDIT — add `LAYER_LOCK_ENABLE = yes` + Getreuer SRC |
| `keyboards/.../keymaps/v2/config.h` | EDIT — add `LAYER_LOCK_IDLE_TIMEOUT` |
| `keyboards/.../keymaps/v2/farkann_v2.h` | EDIT — remove custom `LAYER_LOCK` keycode |
| Layer headers referencing `LAYER_LOCK` | EDIT — replace with `QK_LLCK` |
| `users/v2/lib/getreuer/select_word/` | CREATE (copy from v1) |
| `users/v2/lib/getreuer/sentence_case/` | CREATE (copy from v1) |
| `users/v2/process_record.c` | EDIT — add select_word + sentence_case to chain |
