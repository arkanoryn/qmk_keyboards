# Step 03 — Fix Getreuer SRC Paths in rules.mk

**Priority**: MEDIUM — inconsistent path resolution; fragile if build system changes.

## Problem

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

Most SRC entries use relative paths (resolved from `users/v2/` via QMK's userspace VPATH):
```makefile
SRC += features/repeat/repeat.c \
       features/actions/actions.c \
       ...
```

But the Getreuer sources use a `users/v2/` prefix:
```makefile
SRC += users/v2/lib/getreuer/select_word/select_word.c \
       users/v2/lib/getreuer/sentence_case/sentence_case.c \
       users/v2/lib/getreuer/sentence_case/override.c
```

This is inconsistent. If the relative paths work (they do, because QMK adds the userspace dir to VPATH), then the Getreuer paths should follow the same pattern.

## Task

### 3.1 Fix Getreuer SRC paths

**File**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk`

Replace:
```makefile
# Getreuer library sources
SRC += users/v2/lib/getreuer/select_word/select_word.c \
       users/v2/lib/getreuer/sentence_case/sentence_case.c \
       users/v2/lib/getreuer/sentence_case/override.c
```

With:
```makefile
# Getreuer library sources
SRC += lib/getreuer/select_word/select_word.c \
       lib/getreuer/sentence_case/sentence_case.c \
       lib/getreuer/sentence_case/override.c
```

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

If compilation fails with "file not found" for the Getreuer sources, revert to the `users/v2/` prefix and instead change ALL other SRC entries to also use `users/v2/` prefix. The key outcome is consistency.

## Files Modified

| File | Action |
|------|--------|
| `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/rules.mk` | EDIT — make Getreuer paths consistent with other SRC entries |
