# Step 09 — Fix Magic/Arcane Mod-Tap

**Priority**: MEDIUM — the current implementation works partially but has a fundamental QMK limitation.

## Problem Summary

`SFT_MAGIC` is `LSFT_T(MAGIC)` and `ALT_ARCANE` is `RALT_T(ARCANE)`. QMK's mod-tap requires the tap keycode to be a **basic keycode** (0x00-0xFF range). `MAGIC` and `ARCANE` are custom keycodes well above this range.

## Solution: Use Proxy Basic Keycodes

Use unused basic keycodes (`KC_F24` and `KC_F23`) as proxies for the tap portion, then intercept them in `process_record_user` to trigger Magic/Arcane behavior.

## Tasks

### 9.1 Update thumb key definitions

**File**: `users/v2/layers/layouts/farkann_thumbs.h`

Replace:
```c
#define SFT_MAGIC   LSFT_T(MAGIC)
#define ALT_ARCANE  RALT_T(ARCANE)
```

With:
```c
#define SFT_MAGIC   LSFT_T(KC_F24)
#define ALT_ARCANE  RALT_T(KC_F23)
```

### 9.2 Update `repeat.c` to handle proxy keycodes

**File**: `users/v2/features/repeat/repeat.c`

Replace the `SFT_MAGIC` and `ALT_ARCANE` cases in the switch block with `KC_F24` and `KC_F23`:

```c
    switch (keycode) {
        case KC_F24:
            /* SFT_MAGIC tap — if held, QMK handles Shift automatically */
            /* fallthrough */
        case MAGIC:
            if (last_keycode != KC_NO) {
                process_magic_key(last_keycode);
            }
            return false;

        case KC_F23:
            /* ALT_ARCANE tap — if held, QMK handles Alt automatically */
            /* fallthrough */
        case ARCANE:
            if (last_keycode != KC_NO) {
                process_arcane_key(last_keycode);
            }
            return false;

        default:
            return true;
    }
```

No `record->tap.count` check is needed anymore — when the key is held, QMK sends the modifier and does NOT send `KC_F24`/`KC_F23`. When tapped, QMK sends `KC_F24`/`KC_F23` which our handler intercepts.

### 9.3 Update `remember_last_key_user`

**File**: `users/v2/process_record.c`

Update the exclusion list to use proxy keycodes:

```c
bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case KC_F24:   /* SFT_MAGIC tap */
        case MAGIC:
        case KC_F23:   /* ALT_ARCANE tap */
        case ARCANE:
            return false;
    }
    return true;
}
```

### 9.4 Remove dead `CTL_ARCANE` definition

**File**: `users/v2/layers/layouts/graphite.h`

Remove `#define CTL_ARCANE RCTL_T(ARCANE)` — it is unused (thumbs use `ALT_ARCANE` from `farkann_thumbs.h`).

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Flash and test all four scenarios:
1. **Tap SFT_MAGIC** → triggers Magic key (context-aware completion)
2. **Hold SFT_MAGIC** → activates Shift
3. **Tap ALT_ARCANE** → triggers Arcane key (second repeat)
4. **Hold ALT_ARCANE** → activates Right Alt

## Files Modified

| File | Action |
|------|--------|
| `users/v2/layers/layouts/farkann_thumbs.h` | EDIT — use KC_F24/KC_F23 proxies |
| `users/v2/features/repeat/repeat.c` | EDIT — handle KC_F24/KC_F23 |
| `users/v2/process_record.c` | EDIT — update remember_last_key_user |
| `users/v2/layers/layouts/graphite.h` | EDIT — remove dead CTL_ARCANE |
