#pragma once

#include "ark_v1.h"

enum layers {
  _GRAPHITE,     // GRAPHITE
  _QWERTY,       // QWERTY Layout
  _GAME,         // QWERTY Layout, but without any modifier keys on hold
  _COLEMAK,
  _STURDY,
  _ACTIONS,      // ACTIONS
  _SYMBOLS,      // SYMBOLS
  _ACCENTS,      // ACCENTS
  _NUMPAD_SOUND, // NUMPAD & MULTIMEDIA
  _CONFIG,       // KEYBOARD CONFIGURATION
  _FN
};

#define __X__ KC_NO
#define _____ KC_TRNS

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#include "layers/accents.h"
#include "layers/actions.h"
#include "layers/config.h"
#include "layers/extra_row.h"
#include "layers/layouts/colemak.h"
#include "layers/layouts/graphite.h"
#include "layers/layouts/layout.h"
#include "layers/layouts/qwerty.h"
#include "layers/layouts/sturdy.h"
#include "layers/layouts/farkann_thumbs.h"
#include "layers/num_row.h"
#include "layers/numpad_sound.h"
#include "layers/qwerty.h"
#include "layers/symbols.h"

