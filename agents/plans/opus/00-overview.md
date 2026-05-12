# V2 Migration Plan — Overview

## Context

V1 is a working QMK userspace for the Cosmos Dactyl 5x3 (also Aurora Sweep and KBDFans Maja). It implements Graphite layout with ~16 features including magic key, word combos, cycling combos, chord teacher, OS-aware shortcuts, French accents, tap dances, selection/jump cursor, Getreuer libraries (layer lock, select word, sentence case), and a Quantum Painter display.

V2 aims to:
- Support **multiple base layers** (Graphite, Qwerty, Colemak, Sturdy, Game)
- Add an **ARCANE key** (second context-aware repeat with different mappings than Magic)
- More thumb keys (6 left + 4 right on Cosmos Dactyl)

## Current V2 State

### What Works (implemented)
- All 5 base layout definitions (Graphite, Qwerty, Colemak, Sturdy, Game)
- Symbols, Numpad/Sound, Config, FN layer definitions
- Magic key logic for all 4 layouts (`features/repeat/magic_*.c`)
- Arcane key logic for all 4 layouts (same files)
- Repeat key dispatcher (`features/repeat/repeat.c`)
- Actions layer with OS-aware shortcuts (`features/actions/`)
- Word combos (~240 definitions in `combos/generated/`)
- Cycling combos (disabled, code exists)
- Chord teacher (disabled, stub exists)
- Thumb cluster definition with Magic + Arcane positions

### What Is Broken (compilation blockers)
1. **No `process_record_user`** — all custom keycode handling is dead code
2. **Combo array naming mismatch** — `generated/combos.c` defines `*_COMBO_COMBO[]` but keymap.c references `*_COMBO[]`
3. **Incomplete extern declarations** in `generated/combos.h` (only ~65 of ~240)
4. **Missing `users/v2/rules.mk`** — SRC paths in keymap rules.mk resolve relative to keymap dir, not users/v2
5. **Missing `THUMBCLUSTER_LEFT`/`THUMBCLUSTER_RIGHT`** defines — needed by symbols/numpad/config/fn thumb macros
6. **`LSFT_T(MAGIC)` / `RALT_T(ARCANE)` invalid** — mod-tap doesn't work with custom keycodes above 0xFF
7. **Switch fallthrough bugs** in `repeat.c` — missing `break` statements between cases
8. **`<assert.h>` in `actions.c`** — may not exist in embedded toolchain
9. **Circular include** between `farkann_v2.h` and `layers.h`

### What Is Missing (not yet implemented)
1. **Accents layer** — completely stubbed (`__TMP_EMPTY`)
2. **Tap dances** — Actions layer has `KC_0` placeholders where tap dances should be
3. **Getreuer libraries** — layer lock, select word, sentence case
4. **Alt-tab feature** — APP_NEXT/APP_PREV handlers are commented out in actions.c
5. **Selection feature** — word/line selection with tap-dance modes
6. **Jump cursor feature** — word/line jumping
7. **Symbols processing** — `DOT_EXLM`, `QUOT_UNDS` dual-function keys
8. **Code generation scripts** — v2 has no `scripts/` directory; generated files were manually created
9. **Display** — Quantum Painter / OLED (low priority)
10. **Leader sequences** — enabled in rules.mk but nothing defined

## Implementation Order

| Step | File | Priority | Description |
|------|------|----------|-------------|
| 01 | `01-fix-compilation-blockers.md` | CRITICAL | Fix all issues preventing compilation |
| 02 | `02-rework-combo-generation.md` | CRITICAL | Port v1 scripts, rework for multi-layout combo generation |
| 03 | `03-implement-process-record-user.md` | CRITICAL | Wire up the process_record chain |
| 04 | `04-implement-accents-layer.md` | HIGH | Port French accents from v1 |
| 05 | `05-implement-tap-dance.md` | HIGH | Port tap dances from v1 |
| 06 | `06-implement-getreuer-libraries.md` | HIGH | Port layer lock, select word, sentence case |
| 07 | `07-implement-shortcuts.md` | LOW | Verify shortcuts (already implemented), enable alt-tab |
| 08 | `08-implement-selection-and-jump.md` | MEDIUM | Port selection and jump cursor |
| 09 | `09-fix-magic-arcane-modtap.md` | MEDIUM | Fix mod-tap with custom keycodes |
| 10 | `10-implement-code-generation.md` | ~~MERGED~~ | Merged into Step 02 |
| 11 | `11-implement-display.md` | LOW | Port Quantum Painter display |
| 12 | `12-cleanup-and-validation.md` | LOW | Final cleanup, remove dead code, validate |

## Key Architectural Differences V1 vs V2

| Aspect | V1 | V2 |
|--------|----|----|
| Base layouts | Graphite only (others defined but secondary) | Multi-layout first-class support |
| Magic key | Single, Graphite-specific | Per-layout dispatch |
| Arcane key | Does not exist | New feature, per-layout dispatch |
| Thumb keys | 2-3 per side depending on keyboard | 6 left + 4 right on Cosmos Dactyl |
| Combos | Graphite-only, auto-generated | Graphite-only (same limitation) |
| Features dir | Flat (`magic/`, `shortcuts/`, etc.) | Nested under `features/` |
| Userspace | `users/v1/` with `rules.mk` | `users/v2/` — missing `rules.mk` |

## Verification

After each step, run:
```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

The firmware must compile without errors before moving to the next step.
