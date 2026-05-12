# Step 01 — Fix Compilation Blockers

**Priority**: CRITICAL — nothing else works until this compiles.

## Problem Summary

The v2 keymap cannot compile due to several structural issues: missing userspace rules.mk, broken SRC paths, missing preprocessor defines, assert.h usage, circular includes, and switch fallthrough bugs.

## Tasks

### 1.1 Create `users/v2/rules.mk`

QMK expects `users/<username>/rules.mk` to exist. Without it, the userspace is not picked up and SRC paths fail.

**Create file** `users/v2/rules.mk` with this content:

```makefile
# Copyright 2026 Ark'Anoryn (@arkanoryn)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# V2 userspace rules - intentionally empty.
# All SRC and feature flags are managed in the keymap-level rules.mk.
```

QMK adds the userspace directory to the include/source path automatically when `users/<name>/rules.mk` exists. The SRC paths in the keymap `rules.mk` (e.g., `features/repeat/repeat.c`) will resolve relative to `users/v2/`. This is the same mechanism v1 uses.

### 1.2 Add `THUMBCLUSTER_LEFT` and `THUMBCLUSTER_RIGHT` to config.h

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/config.h`

Add after line 17 (`#pragma once`):

```c
/* Cosmos Dactyl 5x3 thumb cluster configuration */
#define THUMBCLUSTER_LEFT 6
#define THUMBCLUSTER_RIGHT 4
```

These values come from the Cosmos Dactyl physical layout (6 left thumb keys, 4 right thumb keys). They are used by `layers/symbols.h`, `layers/numpad_sound.h`, `layers/config.h`, and `layers/fn.h` to select the correct thumb row macros.

**However**: Check `farkann_thumbs.h` first — currently the `__THUMBS__________` macro is hardcoded (line 56, the `#if`/`#elif` block is fully commented out). The layer-specific thumb macros (`___SYMBOLS_THUMBS__________` etc.) in other layer files DO use `#if THUMBCLUSTER_LEFT == ...` guards. So adding these defines will make those layer thumb macros resolve correctly.

### 1.3 Remove `<assert.h>` from `actions.c`

**File**: `users/v2/features/actions/actions.c`

Find and remove:
```c
#include <assert.h>
```

Replace any `assert()` calls with a bounds-check guard. For example, replace `assert(id < _LAST_ACTION_ID);` with `if (id >= _LAST_ACTION_ID) { return true; }`.

AVR and ARM embedded toolchains used by QMK may not provide `<assert.h>`, or it may bloat the firmware. Keep the `static_assert` on line 59 — that is a compile-time check and is fine.

### 1.4 Fix circular include between `farkann_v2.h` and `layers.h`

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/layers.h`

`layers.h` line 3 includes `farkann_v2.h`, and `farkann_v2.h` includes `layers.h`. This is a circular dependency. **Remove line 3** (`#include "farkann_v2.h"`) from `layers.h`. The dependency should be one-way: `farkann_v2.h` includes `layers.h`, not the other way around. `layers.h` only needs `QMK_KEYBOARD_H` (add `#include QMK_KEYBOARD_H` if not already present) and the layer layout headers.

### 1.5 Fix switch fallthrough in `repeat.c`

**File**: `users/v2/features/repeat/repeat.c`

The current `switch` block at line 51-86 has fallthrough between cases. Each case should have proper `break` or `return` statements:

**Replace the entire switch block (lines 51-86) with**:

```c
    switch (keycode) {
        case SFT_MAGIC:
            /* If the MAGIC key is held, use the mod instead */
            if (record->tap.count == 0) {
                return true;
            }
            /* Fall through to MAGIC on tap */
            /* fallthrough */
        case MAGIC:
            if (last_keycode != KC_NO) {
                process_magic_key(last_keycode);
            }
            return false;

        case ALT_ARCANE:
            /* If the ARCANE key is held, use the mod instead */
            if (record->tap.count == 0) {
                return true;
            }
            /* Fall through to ARCANE on tap */
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

Key changes:
- Removed the redundant `if (record->event.pressed)` check (already checked at line 45)
- Added proper fallthrough from `SFT_MAGIC` to `MAGIC` (intentional)
- Added proper fallthrough from `ALT_ARCANE` to `ARCANE` (intentional)
- Fixed `ARCANE` case indentation
- Removed unreachable `return false` after the ARCANE case

### 1.6 Remove `LEADER_ENABLE` from rules.mk

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

`LEADER_ENABLE = yes` is set but no leader sequences are defined anywhere. This wastes firmware space.
- Comment it out: `# LEADER_ENABLE = yes`

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

At this point the firmware should compile (though many features won't work yet because `process_record_user` is missing — that's Step 03).

## Files Modified

| File | Action |
|------|--------|
| `users/v2/rules.mk` | CREATE |
| `keyboards/.../keymaps/v2/config.h` | EDIT — add THUMBCLUSTER defines |
| `users/v2/features/actions/actions.c` | EDIT — remove assert.h |
| `keyboards/.../keymaps/v2/layers.h` | EDIT — remove circular include |
| `users/v2/features/repeat/repeat.c` | EDIT — fix switch fallthrough |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT — optionally comment LEADER_ENABLE |
