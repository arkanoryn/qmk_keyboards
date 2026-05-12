# Implementation Prompt for V2 QMK Migration

## Your Role

You are implementing a QMK keyboard firmware migration from v1 to v2. You will be given a specific step file to implement. Follow its instructions exactly — every decision has already been made for you. Do not improvise, do not skip steps, do not reorder.

## Project Structure

This is a QMK keyboard firmware repository. The relevant paths are:

- **V2 keymap**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/`
- **V2 userspace**: `users/v2/`
- **V1 reference** (read-only, for porting): `users/v1/` and `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v1/`
- **Plan files**: `agents/plans/opus/` — step-by-step instructions you must follow

## Coding Rules

You MUST follow these rules for every file you create or edit:

1. **Copyright header**: Every `.c` and `.h` file must start with this exact header:
```c
/* Copyright 2026 Ark'Anoryn (@arkanoryn)
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
```
If a file already has the header with year 2025, change it to `2025-2026`.

2. **Indentation**: 4 spaces, no tabs.
3. **Brace style**: Opening brace on same line. Closing brace aligned with opening statement. Always include braces even for single-line blocks.
4. **Header guards**: Use `#pragma once`, never `#ifndef`/`#define`/`#endif` guards.
5. **Comments**: Use C-style `/* */`. Explain *why*, not *what*.
6. **Naming**: Files `snake_case.c`, functions `snake_case()`, constants `UPPER_CASE`, custom keycodes follow QMK conventions (`KC_`, `LT()`, etc.).
7. **Preprocessor**: Keep `#` at column 0, indent directives with spaces after `#` (e.g., `#    ifdef`).

## Build & Verification

After completing each step, compile to verify:
```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```
The firmware **must compile without errors** before you stop. If it fails, fix the errors before moving on. Warnings are acceptable but errors are not.

## Key Technical Context

- **V2 supports 5 base layers**: Graphite (default), Qwerty, Colemak, Sturdy, Game. Features that are layout-specific (magic, arcane, combos) must handle all layouts or guard with `#ifdef`.
- **Magic key**: Context-aware repeat key. Each layout has its own mapping file (`features/repeat/magic_graphite.c`, etc.). Already implemented.
- **Arcane key**: Second context-aware key with *different* mappings than Magic (e.g., after `E`, Magic→`EE`, Arcane→`ED`). Already implemented.
- **Mod-tap with custom keycodes doesn't work in QMK** (keycodes > 0xFF). The solution is to use `KC_F24`/`KC_F23` as proxies and intercept them in `process_record_user`.
- **Layer Lock** uses native QMK (`QK_LLCK` + `LAYER_LOCK_ENABLE = yes` in rules.mk). Do NOT import Getreuer's layer lock library.
- **Shortcuts/actions** use a table-driven `actions[]` array pattern. Never use inline `tap_code16()` calls for shortcuts.
- **Combo generation**: Python scripts in `users/v2/scripts/generator/` generate C code from CSV word lists. Keys in CSV are bare letters; the script prepends a layout prefix (e.g., `GR_` for Graphite).
- **V1 is the reference implementation**. When the step file says "port from v1", read the v1 file and adapt it for v2's architecture (multi-layout, `features/` directory structure, etc.).

## How to Work

1. Read the step file completely before writing any code.
2. Use the todo list tool to track each sub-task in the step file.
3. Implement changes in the exact order specified.
4. After each logical group of changes, compile to check for errors.
5. When you encounter a v1 file to port, read it first, then adapt — do not copy blindly.
6. Mark each sub-task as completed as you finish it.
7. Do not modify files outside the scope of the current step unless fixing a compilation error caused by your changes.

## Your Task

Read file `agents/plans/opus/STEP_FILE_HERE` and implement the steps described there.
