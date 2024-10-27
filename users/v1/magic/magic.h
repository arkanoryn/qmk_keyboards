#pragma once
/*
// # Description
// TODO
//
// # QMK features required:
// * TODO
//
// # Configuration options
** - add `void init_combos_state(void);` to the `void keyboard_pre_init_user(void)`
** in your keymap.
** - Redefine `LONGEST_CYCLE` if required
** - Add the following snippet to your `process_record_user`
**
**      if (!process_magic_key(keycode, record)) {
**          return false;
**      }
*/

#include "quantum.h"
#include "ark_v1.h"
#include "generated_cycles_enum.h"

void process_magic_combo_event(uint16_t combo_index);

// Handler function for Cool feature. Call this from process_record_user().
// Args `keycode` and `record` are the current key event to handle. Returns
// true if default handling should continue; false if it should be skipped.
bool process_magic_key(uint16_t keycode, keyrecord_t *record);

// Task function for Cool feature. Call this from matrix_scan_user().
// void chord_task(void);
