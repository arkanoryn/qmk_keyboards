# Step 06 — Add Clarifying Comment for SEL_WORD on Actions Layer

**Priority**: LOW — readability improvement.

## Problem

**File**: `users/v2/layers/actions.h:53`

```c
#define ACTIONS_2_10 SEL_WORD
```

This looks inconsistent with other action keys that use `CKC(ACTION_NAME)`. However, it is **correct** — `SEL_WORD` is a custom keycode from `custom_keycodes` enum (a standalone feature, not part of the `actions_id_e` table). It would be wrong to wrap it in `CKC()`. A comment clarifies this for future readers.

## Task

### 6.1 Add comment to SEL_WORD definition

**File**: `users/v2/layers/actions.h`

Replace:
```c
#define ACTIONS_2_10 SEL_WORD
```

With:
```c
#define ACTIONS_2_10 SEL_WORD  /* Custom keycode (select_word feature), not an action — do NOT wrap in CKC() */
```

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

## Files Modified

| File | Action |
|------|--------|
| `users/v2/layers/actions.h` | EDIT — add clarifying comment |
