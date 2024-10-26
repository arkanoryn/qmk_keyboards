#pragma once

#include "./user/enums.h"

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

// QWERTY KEYMAP DEFINES
#define CTL_W       LCTL_T(KC_W)
#define ALT_E       LALT_T(KC_E)
#define GUI_R       LGUI_T(KC_R)
#define GUI_U       RGUI_T(KC_U)
#define ALT_I       RALT_T(KC_I)
#define CTL_O       RCTL_T(KC_O)
#define L4_A        LT(NPD, KC_A)
#define L3_S        LT(ACCT, KC_S)
#define L2_D        LT(SMBL, KC_D)
#define L1_F        LT(ACT, KC_F)
#define L1_J        LT(ACT, KC_J)
#define L2_K        LT(SMBL, KC_K)
#define L3_L        LT(ACCT, KC_L)
#define L4_SCLN     LT(NPD, KC_SCLN)

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
