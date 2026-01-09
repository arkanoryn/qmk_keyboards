# AGENTS.md

This file contains guidelines and commands for agentic coding agents working in this QMK keyboard repository.

## Build Commands

### Primary Working Configuration (v2)
- **Main Keymap**: `keyboards/farkann_studio/cosmos_dactyl/5x3/keymaps/v2/`
- **Main Userspace**: `users/v2/`
- **Compile Command**: `qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2`
- **Alternative**: `make farkann_studio/cosmos_dactyl/5x3:v2`

### Compilation
```bash
# Primary v2 configuration
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v2
make farkann_studio/cosmos_dactyl/5x3:v2

# Legacy configurations
qmk compile -kb splitkb/aurora/sweep/rev1 -km v1
qmk compile -kb kbdfans/maja -km v1
qmk compile -kb farkann_studio/cosmos_dactyl/5x3 -km v1
qmk compile -kb kbdfans/maja -km isrt2

# Using make (delegates to QMK firmware)
make splitkb/aurora/sweep/rev1:v1
make kbdfans/maja:v1
make kbdfans/maja:isrt2
```

### Testing
QMK does not have traditional unit tests. Testing is done by:
- Compiling keymaps to verify syntax
- Flashing to hardware for functional testing
- Using QMK's built-in debugging features

### Linting/Formatting
QMK uses clang-format for code formatting. Check QMK firmware documentation for specific formatting rules.

## Code Style Guidelines

### File Organization
- **Keyboards**: `keyboards/<manufacturer>/<keyboard>/<sub-keyboard>/keymaps/<version>` - Contains keyboard-specific setup following QMK root structure (cannot be changed in this repository)
- **Layouts**: `layouts/` - For creating and managing specific layouts for dedicated keyboards (required by QMK but not currently used)
- **Users**: `users/<version>/` - Custom features that can be used across one or more keyboards
- **Headers**: Use `#pragma once` guard
- **Source files**: Organize in feature-specific subdirectories

### Includes and Imports
```c
// Standard QMK includes first
#include QMK_KEYBOARD_H

// Local includes with relative paths
#include "ark_v1.h"
#include "layers/layers.h"
#include "helpers/helpers.h"
#include "combos/combos.h"
```

### Naming Conventions
- **Files**: lowercase with underscores (`helper_functions.c`)
- **Functions**: snake_case (`process_graphite_keys()`)
- **Variables**: snake_case (`idle_timer`)
- **Constants**: UPPER_CASE with underscores (`COMBO_TIMEOUT`)
- **Macros**: UPPER_CASE with descriptive names (`GRAPHITE_1_01`)
- **Keycodes**: Follow QMK conventions (`KC_`, `LT_()`, `LCTL_T()`)

### Code Structure
```c
/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

#pragma once

// Includes
#include QMK_KEYBOARD_H
#include "local_header.h"

// Constants and macros
#define TIMEOUT 5000

// Function declarations
bool process_feature(uint16_t keycode, keyrecord_t *record);

// Function implementations
bool process_feature(uint16_t keycode, keyrecord_t *record) {
  // Implementation
  return true;
}
```

### Formatting Style (QMK C Conventions)
- **Indentation**: 4 spaces (soft tabs)
- **Brace Style**: Modified One True Brace Style
  - Opening brace: Same line as statement
  - Closing brace: Lined up with first character of opening statement
  - Else if: `} else if (condition) {`
- **Optional Braces**: Always include optional braces
  - Good: `if (condition) { return false; }`
  - Bad: `if (condition) return false;`
- **Comments**: Use C style `/* */` for explanations, avoid obvious comments
- **Line Wrapping**: Generally don't wrap lines, if needed keep under 76 columns
- **Preprocessor**: Use `#pragma once` for headers, accept `#ifdef` and `#if defined()`

### Keymap Layout Pattern
```c
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_A, KC_B, KC_C,
    KC_D, KC_E, KC_F
  ),
  [_SYMBOLS] = LAYOUT(
    KC_1, KC_2, KC_3,
    KC_4, KC_5, KC_6
  )
};
// clang-format on
```

### Feature Organization
- **Combos**: Place in `combos/combos.c` and `combos/combos.h`
- **Layers**: Define in `layers/` subdirectory with layout-specific headers
- **Helpers**: Utility functions in `helpers/helpers.c`
- **OLED**: Display code in `oled/oled.c`
- **Magic**: Advanced features in `magic/magic.c`

### Configuration
- **Keyboard config**: `keyboards/<keyboard>/<revision>/keymaps/<name>/config.h`
- Use `#define` for QMK settings
- Group related settings with comments

### Error Handling
- Use QMK's built-in return conventions
- Process functions should return `true` to continue processing, `false` to stop
- Use `#ifdef` guards for optional features
- Add descriptive comments for complex logic

### Process Record Pattern
```c
bool process_feature_name(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CUSTOM_KEY:
      if (record->event.pressed) {
        // Key press action
      } else {
        // Key release action
      }
      return false; // Stop further processing
  }
  return true; // Continue processing
}
```

### Documentation
- Add function headers for complex functions
- Comment non-obvious keymap choices
- Document custom keycodes and their behavior
- Use inline comments for tricky logic

### Modular Design
- Separate concerns into different files
- Use header files for declarations
- Implement feature flags with `#ifdef`
- Keep keymap.c focused on layout definitions

### File Header Requirement
- **All files must start with the exact copyright header**:
```c
/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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
- **If the header does not exist when editing a file, it must be added**
- **If the header exists but the date is passed, it should be edited accordingly**:
  - Example: `Copyright 2025 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)`
  - Should become: `Copyright 2025-2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)`

### QMK Best Practices
- Use `PROGMEM` for keymaps and large arrays
- Implement proper layer switching
- Handle both press and release events when needed
- Use QMK's timer functions for timing features
- Follow QMK's feature enable/disable patterns in rules.mk
