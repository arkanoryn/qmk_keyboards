# Opus-Fix — Post-Implementation Cleanup

## Context

After reviewing the 12 commits implementing Steps 01–09 of the opus migration plan, several issues were identified. These are mostly cleanup items (originally scoped for Step 12) plus a couple of latent bugs.

## Implementation Order

| Step | File | Priority | Description |
|------|------|----------|-------------|
| 01 | `01-fix-ctl-arcane-references.md` | HIGH | Fix undefined `CTL_ARCANE` in colemak.h and sturdy.h |
| 02 | `02-fix-del-word-thumb.md` | MEDIUM | Replace `KC_ESC` placeholder with `CKC(WORD_BACKSPACE)` |
| 03 | `03-fix-getreuer-src-paths.md` | MEDIUM | Make SRC paths consistent in rules.mk |
| 04 | `04-add-missing-copyright-headers.md` | LOW | Add headers to combos.c and combos.h |
| 05 | `05-remove-dead-code.md` | LOW | Remove #ifndef/#undef no-op, dead include, guard conditional includes |
| 06 | `06-add-sel-word-comment.md` | LOW | Add clarifying comment for SEL_WORD on actions layer |

## Verification

After all steps, compile:
```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```
