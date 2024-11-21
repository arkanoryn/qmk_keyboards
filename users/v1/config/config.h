#pragma once
/*
// # Description
// TODO
//
// # QMK features required:
// * TODO
//
// # Configuration options
**
*/

#include QMK_KEYBOARD_H
#include "ark_v1.h"

// Handler function for managing keyboard configuration feature.
// Call this from process_record_user().
// Args `keycode` and `record` are the current key event to handle. Returns
// true if default handling should continue; false if it should be skipped.
bool process_config(uint16_t keycode, keyrecord_t *record);

// Task function for Cool feature. Call this from matrix_scan_user().
// void config_task(void);
