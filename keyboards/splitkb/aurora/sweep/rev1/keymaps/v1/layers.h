#pragma once

enum layers {
  _BASE,         // GRAPHITE
  _ACTIONS,      // ACTIONS
  _SYMBOLS,      // SYMBOLS
  _ACCENTS,      // ACCENTS
  _NUMPAD_SOUND, // NUMPAD & MULTIMEDIA
  _CONFIG,       // KEYBOARD CONFIGURATION
};

#include "layers/graphite.h"
#include "layers/actions.h"
#include "layers/symbols.h"
#include "layers/accents.h"
#include "layers/numpad_sound.h"
#include "layers/config.h"
