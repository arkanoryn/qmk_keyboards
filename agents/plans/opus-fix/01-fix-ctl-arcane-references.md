# Step 01 — Fix Undefined `CTL_ARCANE` References

**Priority**: HIGH — this is a latent compilation blocker.

## Problem

`CTL_ARCANE` was the old v1 pattern (`RCTL_T(ARCANE)`) which doesn't work with custom keycodes. Step 09 replaced it with `ALT_ARCANE` (using `KC_F23` proxy) in `graphite.h` and `farkann_thumbs.h`, but two layout files still reference the undefined symbol.

## Files to Fix

### 1.1 Fix `users/v2/layers/layouts/colemak.h:109`

Replace:
```c
#define COLEMAK_ARCANE CTL_ARCANE
```

With:
```c
#define COLEMAK_ARCANE ALT_ARCANE
```

### 1.2 Fix `users/v2/layers/layouts/sturdy.h:110`

Replace:
```c
#define STURDY_ARCANE CTL_ARCANE
```

With:
```c
#define STURDY_ARCANE ALT_ARCANE
```

## Rationale

`ALT_ARCANE` is defined in `farkann_thumbs.h` as `RALT_T(KC_F23)` and is the correct v2 proxy for the Arcane key. All layout-specific ARCANE aliases should point to this same thumb key definition since the physical thumb key is the same regardless of which base layout is active.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Confirm no "undeclared identifier CTL_ARCANE" errors.

## Files Modified

| File | Action |
|------|--------|
| `users/v2/layers/layouts/colemak.h` | EDIT — replace `CTL_ARCANE` with `ALT_ARCANE` |
| `users/v2/layers/layouts/sturdy.h` | EDIT — replace `CTL_ARCANE` with `ALT_ARCANE` |
