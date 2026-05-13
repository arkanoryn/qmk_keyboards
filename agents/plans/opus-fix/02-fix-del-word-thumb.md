# Step 02 — Fix DEL_WORD Thumb Key Placeholder

**Priority**: MEDIUM — the thumb key currently sends `KC_ESC` instead of deleting a word.

## Problem

**File**: `users/v2/layers/layouts/farkann_thumbs.h:31`

```c
#define DEL_WORD    KC_ESC // TODO: add the correct key press, once we are working on the function keys
```

The `DEL_WORD` thumb key should perform the "word backspace" action (delete the previous word). This is already implemented as `WORD_BACKSPACE` in the actions system.

## Task

### 2.1 Replace the DEL_WORD definition

**File**: `users/v2/layers/layouts/farkann_thumbs.h`

Replace:
```c
#define DEL_WORD    KC_ESC // TODO: add the correct key press, once we are working on the function keys
```

With:
```c
#define DEL_WORD    CKC(WORD_BACKSPACE)
```

This uses the existing `WORD_BACKSPACE` action from `actions_id_e`, which sends `Ctrl+Backspace` on Linux/Windows or `Alt+Backspace` on macOS — exactly what "delete word" means.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Flash and test: tap the DEL_WORD thumb key after typing a word — the entire word should be deleted.

## Files Modified

| File | Action |
|------|--------|
| `users/v2/layers/layouts/farkann_thumbs.h` | EDIT — replace `KC_ESC` with `CKC(WORD_BACKSPACE)` |
