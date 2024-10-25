#include QMK_KEYBOARD_H

#include "./enums.h"
#include "./commands/shortcuts.c"

void isrt_leader_end_user(void) {
   if (leader_sequence_one_key(KC_Y)) {
        send_shortcut(APP_CLOSE, false);
   } else if (leader_sequence_one_key(LT(ACCT, KC_S))) {
        send_shortcut(LD_SAVE, false);
   } else if (leader_sequence_one_key(LGUI_T(KC_M))) {
        send_shortcut(LD_SEARCH, false);
   } else if (leader_sequence_one_key(LT(NPD, KC_I))) {
        send_shortcut(LD_SELECT_ALL, false);
   } else if (leader_sequence_one_key(LT(ACT, KC_T))) {
        send_shortcut(CMD_COPY, false);
   } else if (leader_sequence_one_key(KC_G)) {
        send_shortcut(CMD_CUT, false);
   } else if (leader_sequence_one_key(LT(SMBL, KC_R))) {
        send_shortcut(CMD_PASTE, false);
   } else if (leader_sequence_one_key(LSFT_T(KC_Q))) {
        send_shortcut(CMD_UNDO, false);
   } else if (leader_sequence_one_key(KC_K)) {
        send_shortcut(TAB_NEW, false);
   } else if (leader_sequence_one_key(KC_B)) {
        send_shortcut(APP_NEW_WINDOW, false);
   } else if (leader_sequence_two_keys(LT(ACT, KC_T), LT(ACT, KC_T))) {
        send_shortcut(LD_SELECT_ALL, false);
        send_shortcut(CMD_COPY, false);
   } else if (leader_sequence_two_keys(LSFT_T(KC_Q), LSFT_T(KC_Q))) {
        send_shortcut(CMD_REDO, false);
   } else if (leader_sequence_two_keys(LGUI_T(KC_M), KC_P)) {
        SEND_STRING("pierrenicolas.sormani@gmail.com");
   } else if (leader_sequence_two_keys(LGUI_T(KC_M), KC_G)) {
        SEND_STRING("arkanoryn@gmail.com");
   } else if (leader_sequence_two_keys(LGUI_T(KC_M), LT(ACCT, KC_A))) {
        SEND_STRING("psormani@anynines.com");
   }
}

void leader_end_user(void) {
    if (layer_state_is(ISRT)) {
        isrt_leader_end_user();
    }

};
