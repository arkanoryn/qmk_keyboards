# v1 to v2 Feature Migration Plan

## Analysis: Missing Features in v2

### Userspace Comparison

#### Features Present in v1 but Missing in v2:

1. **Combos System**
   - v1: `users/v1/combos/combos.h`, `users/v1/combos/combos.c`
   - v2: Missing - no combos directory or files

2. **Magic System**
   - v1: `users/v1/magic/magic.h`, `users/v1/magic/magic.c`, `users/v1/magic/cycling_combos.h`, `users/v1/magic/cycling_combos.c`, `users/v1/magic/repeat.h`, `users/v1/magic/repeat.c`
   - v2: Partially migrated - only `users/v2/features/repeat/` exists, but missing the main magic system

3. **Selection System**
   - v1: `users/v1/selection/selection.h`, `users/v1/selection/selection.c`
   - v2: Missing - no selection directory

4. **Shortcuts System**
   - v1: `users/v1/shortcuts/shortcuts.h`, `users/v1/shortcuts/shortcuts.c`
   - v2: Partially migrated - similar functionality exists in `users/v2/features/actions/` but may not be complete

5. **Teacher System**
   - v1: `users/v1/teacher/chord_teacher.h`, `users/v1/teacher/chord_teacher.c`, `users/v1/teacher/virt_sidechannel.c`
   - v2: Missing - no teacher directory

6. **Getreuer System**
   - v1: `users/v1/getreuer/getreuer.h` with subdirectories for layer_lock, select_word, and sentence_case
   - v2: Missing - no getreuer directory

7. **Tap Dance System**
   - v1: `users/v1/tap_dance/tap_dance.h`, `users/v1/tap_dance/tap_dance.c`, `users/v1/tap_dance/tap_dance_extract.c`
   - v2: Missing - no tap_dance directory

8. **Config System**
   - v1: `users/v1/config/config.h`, `users/v1/config/config.c`
   - v2: Missing - no config directory

9. **Painter/OLED System**
   - v1: `users/v1/painter/display.h`, `users/v1/painter/display.c` with fonts and images
   - v2: Missing - no painter directory

10. **Generated Files**
    - v1: `users/v1/generated/combos.c`, `users/v1/generated/combos.h`, `users/v1/generated/correct_chords.c`, `users/v1/generated/correct_chords.h`, `users/v1/generated/cycles.c`, `users/v1/generated/cycles.h`
    - v2: Missing - no generated directory

11. **Scripts**
    - v1: `users/v1/scripts/generator/` directory with generation scripts
    - v2: Missing - no scripts directory

### Keymap Comparison

#### Missing Custom Keycodes in v2:
- `SEL_WORD`
- `QUOT_UNDER`
- `DOT_EXLM`
- `QUOT_UNDS`
- `CYCLE_CHORD_MODE`
- `TOGGLE_STURDY`
- `TOGGLE_COLEMAK`
- `TOGGLE_QWERTY`
- `TOGGLE_GRAPHITE`
- `TOGGLE_GAME`

#### Missing Feature Support:
- Tap dance processing
- Combo support (commented out)
- Shortcuts system
- Symbols processing
- Selection features
- Teacher/chord training
- Painter/display features
- Most helper functions
- Configuration processing

## Implementation Plan

### Phase 1: Core Infrastructure (High Priority)

1. **Create Combo System** (`users/v2/combos/`)
   - [ ] Implement combo definitions and processing
   - [ ] Create combo header and source files
   - [ ] Integrate with existing layer system
   - [ ] Update `rules.mk` to include combo support

2. **Enhance Magic System** (`users/v2/features/magic/`)
   - [ ] Port main magic functionality from v1
   - [ ] Keep existing repeat feature
   - [ ] Add cycling combos support
   - [ ] Create magic.h and magic.c files

3. **Implement Selection System** (`users/v2/features/selection/`)
   - [ ] Port text selection capabilities
   - [ ] Create selection.h and selection.c files
   - [ ] Integrate with layer system
   - [ ] Add `SEL_WORD` keycode support

### Phase 2: Advanced Features (Medium Priority)

4. **Add Tap Dance Support** (`users/v2/features/tap_dance/`)
   - [ ] Implement tap dance processing
   - [ ] Create tap dance definitions
   - [ ] Integrate with keymap
   - [ ] Add tap dance header and source files

5. **Implement Shortcuts System** (`users/v2/features/shortcuts/`)
   - [ ] Port shortcuts functionality
   - [ ] Enhance existing actions system
   - [ ] Create shortcuts.h and shortcuts.c files
   - [ ] Add missing shortcut keycodes

6. **Add Symbols Processing** (`users/v2/features/symbols/`)
   - [ ] Implement symbol and accent handling
   - [ ] Create symbols processing functions
   - [ ] Add symbols.h and symbols.c files
   - [ ] Add symbol-related keycodes (`QUOT_UNDER`, `DOT_EXLM`, etc.)

### Phase 3: Optional Features (Low Priority)

7. **Teacher System** (`users/v2/features/teacher/`)
   - [ ] Implement chord teaching functionality
   - [ ] Add learning system
   - [ ] Create teacher.h and teacher.c files
   - [ ] Add `CYCLE_CHORD_MODE` keycode

8. **Painter/OLED System** (`users/v2/features/painter/`)
   - [ ] Add display functionality
   - [ ] Implement OLED support
   - [ ] Create painter.h and painter.c files
   - [ ] Add fonts and display resources

9. **Config System** (`users/v2/config/`)
   - [ ] Add configuration management
   - [ ] Implement config processing
   - [ ] Create config.h and config.c files
   - [ ] Add configuration keycodes

### Phase 4: Integration and Testing

10. **Update Keymap Files**
    - [ ] Add missing custom keycodes to `farkann_v2.h`
    - [ ] Update `rules.mk` to include new features
    - [ ] Integrate all systems with main keymap
    - [ ] Update layer definitions and includes

11. **Testing and Validation**
    - [ ] Compile and test each feature incrementally
    - [ ] Ensure compatibility with existing v2 architecture
    - [ ] Validate all features work correctly
    - [ ] Test on target hardware

## Implementation Strategy

### Modular Approach
- Implement each feature as a separate module in the `features/` directory
- Follow v2's cleaner architecture patterns
- Maintain separation of concerns

### Incremental Testing
- Test each feature after implementation
- Use QMK's compilation system for validation
- Test on hardware when possible

### Code Reuse
- Port relevant code from v1 but adapt to v2 architecture
- Modernize code where appropriate
- Improve documentation and comments

### Documentation
- Add proper comments for each feature
- Document custom keycodes and their behavior
- Update README with new features

### Backward Compatibility
- Ensure new features don't break existing functionality
- Maintain compatibility with v2's layer system
- Preserve existing key mappings

## Estimated Timeline

- **Phase 1 (Core)**: 2-3 weeks
- **Phase 2 (Advanced)**: 3-4 weeks
- **Phase 3 (Optional)**: 2-3 weeks
- **Phase 4 (Integration)**: 1-2 weeks

## Priority Recommendations

1. **High Priority**: Combo system, Magic system, Selection system
2. **Medium Priority**: Tap dance, Shortcuts, Symbols processing
3. **Low Priority**: Teacher system, Painter/OLED, Config system

This plan provides a comprehensive roadmap for implementing all missing features from v1 into v2, while maintaining the cleaner, more modular architecture of v2. The phased approach allows for incremental progress and testing.