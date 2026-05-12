# Step 11 — Implement Display

**Priority**: LOW — cosmetic feature, firmware works without it.

## Problem Summary

V1 uses Quantum Painter (ST7735 LCD) on the Cosmos Dactyl to show chord teacher state and current layer. V2 has display code commented out in config.h.

## Reference

- V1 implementation: `users/v1/painter/display.c`, `users/v1/painter/fonts/font_oled.qff.c`

## Tasks

### 11.1 Create `users/v2/features/display/display.h` and `display.c`

Port from v1's `painter/display.c`. Adapt to show:
- Current active base layer name (Graphite/Qwerty/Colemak/Sturdy/Game)
- Current overlay layer (Actions/Symbols/Accents/Numpad/Config/FN)
- Chord teacher mode (if enabled)
- Magic/Arcane last output (nice-to-have)

### 11.2 Copy font files

Copy `users/v1/painter/fonts/font_oled.qff.c` to `users/v2/features/display/fonts/`.

### 11.3 Enable in config.h

Uncomment the Quantum Painter section in config.h.

### 11.4 Add to rules.mk

```makefile
SRC += features/display/display.c \
       features/display/fonts/font_oled.qff.c
```

### 11.5 Add necessary QMK Painter enables

```makefile
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7735_spi
```

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

Flash and verify display output.

## Files Created/Modified

| File | Action |
|------|--------|
| `users/v2/features/display/display.h` | CREATE |
| `users/v2/features/display/display.c` | CREATE |
| `users/v2/features/display/fonts/` | CREATE (copy from v1) |
| `keyboards/.../keymaps/v2/config.h` | EDIT |
| `keyboards/.../keymaps/v2/rules.mk` | EDIT |
