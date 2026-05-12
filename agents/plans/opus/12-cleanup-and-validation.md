# Step 12 — Cleanup and Validation

**Priority**: LOW — final polish after all features are working.

## Tasks

### 12.1 Remove dead code

- Remove `__TMP_EMPTY` from keymap.c (should be replaced by accents layer by now)
- Remove unused `CTL_ARCANE` from `graphite.h`
- Remove the `#ifndef __THUMBS__________` / `#undef` block in `farkann_thumbs.h` (lines 42-44 — this is a no-op, `#ifndef` then `#undef` does nothing)
- Clean up commented-out SRC entries in rules.mk

### 12.2 Fix copyright headers

Scan all v2 files. Any file with `Copyright 2025` should become `Copyright 2025-2026`. Any new file should have `Copyright 2026`.

### 12.3 Verify magic/arcane content per layout

The magic and arcane mappings in `magic_sturdy.c`, `magic_colemak.c`, `magic_qwerty.c` use `case KC_X:` where `KC_X` represents the **output letter**, not the physical key position. Since all layouts produce the same letter outputs (pressing the "B" key on any layout outputs "b"), the magic/arcane mappings are **semantic** — they are based on which letter was last typed. This means the `KC_B` → "efore" mapping works correctly regardless of layout, because `get_last_keycode()` returns the output keycode.

**Action**: Verify this by reading `repeat.c` — `get_last_keycode()` returns the basic keycode that was sent, not the physical position. If this is confirmed (it should be), no changes are needed to the magic files. They are correct as-is.

### 12.4 Multi-layout combos

This is fully addressed in Step 02 (`02-rework-combo-generation.md`). No action needed here.

### 12.5 Remove `LEADER_ENABLE` if unused

If no leader sequences were added during the migration, remove `LEADER_ENABLE = yes` from rules.mk to save firmware space.

### 12.6 Run final compilation and size check

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Check firmware size. The Cosmos Dactyl uses an RP2040 (or similar) so space is generous, but verify you're not at the limit.

### 12.7 Create a feature checklist

Document which v1 features are ported, which are new (Arcane), and which are intentionally excluded:

| Feature | V1 | V2 | Status |
|---------|----|----|--------|
| Graphite layout | Yes | Yes | Ported |
| Multi-layout | Partial | Yes | New |
| Magic key | Yes | Yes | Ported + per-layout |
| Arcane key | No | Yes | New |
| Word combos | Yes | Yes | Ported |
| Cycling combos | Yes | Yes | Ported (disabled) |
| Chord teacher | Yes | Stub | Partial |
| OS shortcuts | Yes | Yes | Ported |
| French accents | Yes | Yes | Ported |
| Tap dances | Yes | Yes | Ported |
| Layer lock | Yes | Yes | Ported |
| Select word | Yes | Yes | Ported |
| Sentence case | Yes | Yes | Ported |
| Selection | Yes | Yes | Ported |
| Jump cursor | Yes | Yes | Ported |
| Display | Yes | Yes | Ported |
| DOT_EXLM / QUOT_UNDS | Yes | No | TODO |
| Alt-Tab manager | Yes | No | TODO |

## Files Modified

Various cleanup edits across all v2 files.
