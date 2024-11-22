// TODO: these should probably be in the config.h layer
#pragma once

#include "getreuer/layer_lock/layer_lock.h"
#define LAYER_LOCK_IDLE_TIMEOUT 300000 // Turn off LAYER_LOCK after 300 seconds (5 minutes).

#define _FIRST_SHORTCUT_ID 0
#include "shortcuts/shortcuts.h"

#define _FIRST_SYMBOL_ID _LAST_SHORTCUT_ID
#include "symbols/symbols.h"

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#include "layers.h"

#ifndef NEW_SAFE_RANGE
#  define NEW_SAFE_RANGE SAFE_RANGE + _LAST_SHORTCUT_ID + _LAST_SYMBOL_ID
#endif // NEW_SAFE_RANGE

enum custom_keycodes {
  LAYER_LOCK = NEW_SAFE_RANGE,
  MAGIC,
  SEL_WORD,
  QUOT_UNDER,
  DOT_EXLM,
  QUOT_UNDS,
  CYCLE_CHORD_MODE,

  // CLOCK, currently on hold
  //   CLOCKUP,
  //   CLOCKDN,
  //   CLOCKNX,
};
