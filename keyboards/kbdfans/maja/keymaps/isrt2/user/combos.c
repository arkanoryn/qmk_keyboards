// Combos
// REF: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// REF: https://docs.qmk.fm/#/feature_combo?id=combos

#include QMK_KEYBOARD_H
#include "./enums.h"

const uint16_t PROGMEM ISRT_esc_combo1[] = {KC_Y, LCTL_T(KC_C), COMBO_END};
const uint16_t PROGMEM ISRT_esc_combo2[] = {LGUI_T(KC_M), LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM ISRT_tab_combo[] = {LT(SMBL, KC_R),	LT(ACT, KC_T), COMBO_END};
const uint16_t PROGMEM ISRT_ent_combo[] = {LT(SMBL, KC_E), LT(ACT, KC_N), COMBO_END};
const uint16_t PROGMEM ISRT_bspc_combo[] = {KC_QUOT, RCTL_T(KC_COMM), COMBO_END};
const uint16_t PROGMEM ISRT_del_combo[] = {KC_QUOT, RCTL_T(KC_COMM), RALT_T(KC_U), COMBO_END};

combo_t key_combos[] = {
    COMBO(ISRT_esc_combo1, KC_ESC),
    COMBO(ISRT_esc_combo2, KC_ESC),
    COMBO(ISRT_tab_combo, KC_TAB),
    COMBO(ISRT_ent_combo, KC_ENT),
    COMBO(ISRT_bspc_combo, KC_BSPC),
    COMBO(ISRT_del_combo, KC_DEL),
};
