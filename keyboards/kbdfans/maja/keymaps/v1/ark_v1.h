#pragma once

#define _FIRST_SHORTCUT_ID 0
#include "shortcuts/shortcuts.h"

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#ifndef NEW_SAFE_RANGE
#  define NEW_SAFE_RANGE SAFE_RANGE + _LAST_SHORTCUT_ID // + _LAST_SYMBOL_ID
#endif                                                  // NEW_SAFE_RANGE

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
