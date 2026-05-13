# Step 05 — Remove Dead Code and Guard Conditional Includes

**Priority**: LOW — code hygiene.

## Tasks

### 5.1 Remove `#ifndef/#undef` no-op block

**File**: `users/v2/layers/layouts/farkann_thumbs.h`

Remove lines 42-44:
```c
#ifndef __THUMBS__________
#undef __THUMBS__________
#endif
```

This block does nothing: `#ifndef` checks if a macro is NOT defined, then `#undef` tries to undefine it — but it's already not defined. The intent was likely to allow redefinition, but the active `#define __THUMBS__________` on line 56 works without this guard.

### 5.2 Guard conditional includes in `combos.c`

**File**: `users/v2/features/combos/combos.c`

Replace:
```c
#include "features/cycling_combos/cycling_combos.h"
#include "features/chord_teacher/chord_teacher.h"
```

With:
```c
#ifdef CYCLE_COMBO_ENABLE
#    include "features/cycling_combos/cycling_combos.h"
#endif

#ifdef CHORD_TEACHER_ENABLE
#    include "features/chord_teacher/chord_teacher.h"
#endif
```

This matches how the features are used conditionally throughout the rest of the file.

### 5.3 Remove dead `#include` in `tap_dance.c`

**File**: `users/v2/features/tap_dance/tap_dance.c`

Remove the trailing include near the end of the file:
```c
/* Jump and selection functions are now defined in their own feature files */
#include "../jump_cursor/jump.h"
```

This include is unnecessary — the jump functions (`td_process_jump_forward`, etc.) are declared in `tap_dance.h` and defined in `jump.c`. Including the header here at the bottom of the `.c` file serves no purpose (it doesn't bring implementations, just declarations that are never used within this file).

### 5.4 Remove commented-out legacy SRC block in rules.mk

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

Remove the commented-out v1-style SRC block at the bottom:
```makefile
#   combos/combos.c \
# 	helpers/helpers.c \
# 	helpers/graphite.c \
# 	symbols/symbols.c \
# 	selection/selection.c \
# 	tap_dance/tap_dance.c \
# 	magic/magic.c
```

These are leftover v1 paths that no longer apply.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

## Files Modified

| File | Action |
|------|--------|
| `users/v2/layers/layouts/farkann_thumbs.h` | EDIT — remove #ifndef/#undef block |
| `users/v2/features/combos/combos.c` | EDIT — guard conditional includes |
| `users/v2/features/tap_dance/tap_dance.c` | EDIT — remove dead include |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT — remove commented legacy SRC |
