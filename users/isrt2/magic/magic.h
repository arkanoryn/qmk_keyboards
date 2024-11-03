#pragma once
//
// # Description
// TODO
//
// # QMK features required:
// * TODO
//
// # Configuration options
// * TODO

#include "quantum.h"
#include "keymap.h"

/*
**    ///////////////
**   /// CYCLING ///
**  ///////////////
**
**
** This part is about cycling.
** At some point it's going to be move to its own file(s)
*/

#define LONGEST_CYCLE 6

typedef struct {
  bool     combo_active;
  bool     can_cycle;
  uint16_t last_combo_index;
  bool     shifted;
  uint8_t  cycle_position;
} combos_state_t;

typedef enum {
  HVE_HAVE = 0,
  BE_BE,
} cycling_combos_e;

void init_combos_state(void);
void xyz(uint16_t combo_index);

/*
**    /////////////////////
**   /// CYCLING - END ///
**  /////////////////////
*/
// Handler function for Cool feature. Call this from process_record_user().
// Args `keycode` and `record` are the current key event to handle. Returns
// true if default handling should continue; false if it should be skipped.
bool process_magic_key(uint16_t keycode, keyrecord_t *record);

// Task function for Cool feature. Call this from matrix_scan_user().
// void chord_task(void);
