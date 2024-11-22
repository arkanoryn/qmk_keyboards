/*
**  Contains the different layers used by the board.
** /!\ Warning: the layers are only containing the 5x3 central keys
*/
#pragma once

enum layers {
  _BASE,         // QWERTY
  _GRAPHITE,     // GRAPHITE
  _ACTIONS,      // ACTIONS
  _SYMBOLS,      // SYMBOLS
  _ACCENTS,      // ACCENTS
  _NUMPAD_SOUND, // NUMPAD & MULTIMEDIA
  _CONFIG,       // KEYBOARD CONFIGURATION
};

#include "ark_v1.h"
#include "layers/graphite.h"
#include "layers/actions.h"
// #include "layers/symbols.h"
// #include "layers/accents.h"
// #include "layers/numpad_sound.h"
// #include "layers/config.h"
