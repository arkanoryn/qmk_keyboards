/**
 * @file symbols.h
 * @brief symbols, a script to manage most-used symbols in macOS and winOS.
 *
 * Overview
 * --------
 * TODO
 *
 * @note When a layer is "locked", other layer keys such as `TO(layer)` or
 * manually calling `layer_off(layer)` will override and unlock the layer.
 *
 * Configuration
 * -------------
 *
 * In your keymap.c or other main header:
 * - Define `_FIRST_SYMBOL_ID` that should be either 0 or the _LAST_*
 *   from another of our `SAFE_RANGE` enum.
 * - Ensure that you have a KEYMAP_MAIN_H that is linked to your main header.
 * - Add this file to your SRC in `rules.mk`
 */
#pragma once

#include QMK_KEYBOARD_H

// clang-format off
typedef enum {
  E_CIRC = _FIRST_SYMBOL_ID,
  E_AIGU,
  C_CEDILLE,
  U_GRAVE,
  E_GRAVE,
  U_CIRC,
  I_CIRC,
  A_GRAVE,
  A_CIRC,
  I_TREMA,
  O_CIRC,
  _LAST_ACCENT_IGNORE,
  EURO,
  _LAST_SYMBOL_ID
} symbols_id_e;

#define WIN_CIRCONFLEXE         A(S(KC_6))
#define WIN_AIGU                A(KC_QUOTE)
#define WIN_GRAVE               A(KC_GRAVE)
#define WIN_TREMA               A(S(KC_QUOTE))
#define WIN_CEDILLE             A(KC_QUOTE)
#define MAC_CIRCONFLEXE         LOPT(KC_I)
#define MAC_AIGU                LOPT(KC_E)
#define MAC_GRAVE               LOPT(KC_GRAVE)
#define MAC_TREMA               LOPT(KC_U)
#define CIRCONFLEXE             (detected_host_os() == OS_MACOS ? MAC_CIRCONFLEXE : WIN_CIRCONFLEXE)
#define AIGU                    (detected_host_os() == OS_MACOS ? MAC_AIGU : WIN_AIGU)
#define GRAVE                   (detected_host_os() == OS_MACOS ? MAC_GRAVE : WIN_GRAVE)
#define TREMA                   (detected_host_os() == OS_MACOS ? MAC_TREMA : WIN_TREMA)
#define WIN_EUR                 SS_LCTL(SS_LALT("5"))
#define MAC_EUR                 SS_LALT(SS_LSFT("2"))
// clang-format on

bool process_accents(symbols_id_e id);
bool process_symbols(uint16_t keycode, keyrecord_t *record);
