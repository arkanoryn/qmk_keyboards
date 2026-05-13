# Step 04 — Add Missing Copyright Headers

**Priority**: LOW — project policy requires headers on all files.

## Problem

Two files in `users/v2/features/combos/` are missing the required copyright header.

## Tasks

### 4.1 Add copyright header to `users/v2/features/combos/combos.c`

The file currently starts with:
```c
#include QMK_KEYBOARD_H
```

Add the standard copyright header before the first `#include`:

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

### 4.2 Add copyright header to `users/v2/features/combos/combos.h`

The file currently starts with:
```c
/*
 * Requirements:
 * - add `INTROSPECTION_KEYMAP_C = generated/combos.c` to your `rules.mk`
 */
```

Replace with the copyright header followed by the requirements comment:

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

/*
 * Requirements:
 * - add `INTROSPECTION_KEYMAP_C = generated/combos.c` to your `rules.mk`
 */
```

## Verification

```bash
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
```

## Files Modified

| File | Action |
|------|--------|
| `users/v2/features/combos/combos.c` | EDIT — add copyright header |
| `users/v2/features/combos/combos.h` | EDIT — add copyright header |
