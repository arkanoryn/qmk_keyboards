#pragma once

#include "getreuer/layer_lock/layer_lock.h"
#define LAYER_LOCK_IDLE_TIMEOUT 300000  // Turn off LYR_LOCK after 300 seconds (5 minutes).

#define _FIRST_SHORTCUT_ID 0
#include "shortcuts/shortcuts.h"

#define _FIRST_SYMBOL_ID _LAST_SHORTCUT_ID
#include "symbols/symbols.h"

enum layers {
  GRPT, // GRAPHITE
  ISRT,
  ACT,  // ACTIONS
  SMBL, // SYMBOLS
  ACCT, // ACCENTS
  NPD,  // NUMPAD & MULTIMEDIA
  CONFIG,  // KEYBOARD CONFIGURATION
};

#define CKC(x)      (SAFE_RANGE + x)        // generate custom keycode from enum

#define MEH_SPC     MEH_T(KC_SPC)

#define WIN_EUR     SS_LCTL(SS_LALT("5"))
#define MAC_EUR     SS_LALT(SS_LSFT("2"))

// ISRT KEYMAP DEFINES
#define CTL_C       LCTL_T(KC_C)
#define ALT_L       LALT_T(KC_L)
#define GUI_M       LGUI_T(KC_M)
#define GUI_F       RGUI_T(KC_F)
#define ALT_U       RALT_T(KC_U)
#define CTL_COMM    RCTL_T(KC_COMM)
#define L4_I        LT(NPD, KC_I)
#define L3_S        LT(ACCT, KC_S)
#define L2_R        LT(SMBL, KC_R)
#define L1_T        LT(ACT, KC_T)
#define L1_N        LT(ACT, KC_N)
#define L2_E        LT(SMBL, KC_E)
#define L3_A        LT(ACCT, KC_A)
#define L4_O        LT(NPD, KC_O)
#define SFT_Q       LSFT_T(KC_Q)
#define SFT_X       RSFT_T(KC_X)

// GRAPHITE KEYMAP DEFINES
#define CTL_L       LCTL_T(KC_L)
#define ALT_D       LALT_T(KC_D)
#define GUI_W       LGUI_T(KC_W)
#define GUI_F       RGUI_T(KC_F)
#define ALT_O       RALT_T(KC_O)
#define CTL_U       RCTL_T(KC_U)
#define L4_N        LT(NPD, KC_N)
#define L3_R        LT(ACCT, KC_R)
#define L2_T        LT(SMBL, KC_T)
#define L1_S        LT(ACT, KC_S)
#define L1_H        LT(ACT, KC_H)
#define L2_A        LT(SMBL, KC_A)
#define L3_E        LT(ACCT, KC_E)
#define L4_I        LT(NPD, KC_I)
#define SFT_Q       LSFT_T(KC_Q)
#define SFT_SLSH    RSFT_T(KC_SLSH)

#ifndef NEW_SAFE_RANGE
#  define NEW_SAFE_RANGE SAFE_RANGE + _LAST_SHORTCUT_ID + _LAST_SYMBOL_ID
#endif // NEW_SAFE_RANGE

enum custom_keycodes {
  LYR_LOCK = NEW_SAFE_RANGE,
  MAGIC,
  SEL_WORD,
  QUOT_UNDER,
  DOT_EXLM,
  QUOT_UNDS,
  SFT_ENT,
  C_ENT,
  TOGGLE_CONFIG_LYR,
  CYCLE_CHORD_MODE,

  // CLOCK, currently on hold
//   CLOCKUP,
//   CLOCKDN,
//   CLOCKNX,
};

// will have to be move to its own source / helper folder /file
void    send_temporary_string(const char *str);
