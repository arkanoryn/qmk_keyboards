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

void process_repeat_event(uint16_t keycode, uint8_t mods);
