// Combos
// REF: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// REF: https://docs.qmk.fm/#/feature_combo?id=combos

#include QMK_KEYBOARD_H
#include "./../keymap.h"
#include "./enums.h"

const uint16_t PROGMEM ISRT_esc_combo1[] = {KC_Y, CTL_C, COMBO_END};
const uint16_t PROGMEM ISRT_esc_combo2[] = {GUI_M, ALT_L, COMBO_END};
const uint16_t PROGMEM ISRT_tab_combo[] = {L2_R, L1_T, COMBO_END};
const uint16_t PROGMEM ISRT_ent_combo[] = {L2_E, L1_N, COMBO_END};
const uint16_t PROGMEM ISRT_bspc_combo[] = {KC_QUOT, CTL_COMM, COMBO_END};
const uint16_t PROGMEM ISRT_del_combo[] = {KC_QUOT, CTL_COMM, ALT_U, COMBO_END};
const uint16_t PROGMEM ACT_layerlock_combo[] = {CKC(WORD_SELECTR), CKC(LINE_SELECTR), COMBO_END};

combo_t key_combos[] = {
  COMBO(ISRT_esc_combo1, KC_ESC),
  COMBO(ISRT_esc_combo2, KC_ESC),
  COMBO(ISRT_tab_combo, KC_TAB),
  COMBO(ISRT_ent_combo, KC_ENT),
  COMBO(ISRT_bspc_combo, KC_BSPC),
  COMBO(ISRT_del_combo, KC_DEL),
  COMBO(ACT_layerlock_combo, LYR_LOCK),
};
