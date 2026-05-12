# Step 08 — Implement Selection and Jump Cursor

**Priority**: MEDIUM — quality-of-life features from v1.

## Problem Summary

V1 has two features:
1. **Selection** — tap-dance multi-mode: 1-tap=word, hold=whole line, 2-tap=select word, 3-tap=line from cursor, with accelerating auto-repeat
2. **Jump Cursor** — word/line jumping with tap-dance and accelerating auto-repeat

Neither exists in v2.

## Reference

- V1 selection: `users/v1/selection/selection.c`
- V1 jump cursor: `users/v1/jump_cursor/jump.c`

## Tasks

### 8.1 Create `users/v2/features/selection/selection.h` and `selection.c`

Port from v1. Adapt:
- Include paths for v2
- Use v2's OS detection pattern
- Integrate with v2's tap dance system (from Step 05)

### 8.2 Create `users/v2/features/jump_cursor/jump.h` and `jump.c`

Port from v1. Same adaptations as selection.

### 8.3 Wire into process_record chain

**File**: `users/v2/process_record.c`

```c
#include "features/selection/selection.h"
#include "features/jump_cursor/jump.h"

if (!process_selection(keycode, record)) { return false; }
if (!process_jump_cursor(keycode, record)) { return false; }
```

### 8.4 Add to rules.mk

```makefile
SRC += features/selection/selection.c \
       features/jump_cursor/jump.c
```

### 8.5 Connect tap dances

The selection and jump features use tap dances defined in Step 05 (`TD_JUMP_FWD`, `TD_JUMP_BWD`, `TD_SEL_FWD`, `TD_SEL_BWD`). Ensure the tap dance callbacks in `tap_dance.c` call the selection/jump functions.

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

## Files Created/Modified

| File | Action |
|------|--------|
| `users/v2/features/selection/selection.h` | CREATE |
| `users/v2/features/selection/selection.c` | CREATE |
| `users/v2/features/jump_cursor/jump.h` | CREATE |
| `users/v2/features/jump_cursor/jump.c` | CREATE |
| `users/v2/process_record.c` | EDIT |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT |
