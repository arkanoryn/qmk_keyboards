#include QMK_KEYBOARD_H

#include "./enums.h"
#include "./commands/shortcuts.c"

void isrt_leader_end_user(void) {
   if (leader_sequence_one_key(KC_Y)) {
        send_shortcut(APP_CLOSE);
   } else if (leader_sequence_one_key(LT(ACCT, KC_S))) {
        send_shortcut(LD_SAVE);
   } else if (leader_sequence_one_key(LGUI_T(KC_M))) {
        send_shortcut(LD_SEARCH);
   } else if (leader_sequence_one_key(LT(NPD, KC_I))) {
        send_shortcut(LD_SELECT_ALL);
   } else if (leader_sequence_one_key(LT(ACT, KC_T))) {
        send_shortcut(CMD_COPY);
   } else if (leader_sequence_one_key(KC_G)) {
        send_shortcut(CMD_CUT);
   } else if (leader_sequence_one_key(LT(SMBL, KC_R))) {
        send_shortcut(CMD_PASTE);
   } else if (leader_sequence_one_key(LSFT_T(KC_Q))) {
        send_shortcut(CMD_UNDO);
   } else if (leader_sequence_one_key(KC_K)) {
        send_shortcut(TAB_NEW);
   } else if (leader_sequence_one_key(KC_B)) {
        send_shortcut(APP_NEW_WINDOW);
   } else if (leader_sequence_two_keys(LT(ACT, KC_T), LT(ACT, KC_T))) {
        send_shortcut(LD_SELECT_ALL);
        send_shortcut(CMD_COPY);
   } else if (leader_sequence_two_keys(LSFT_T(KC_Q), LSFT_T(KC_Q))) {
        send_shortcut(CMD_REDO);
   } else if (leader_sequence_two_keys(LGUI_T(KC_M), KC_P)) {
        SEND_STRING("pierrenicolas.sormani@gmail.com");
   } else if (leader_sequence_two_keys(LGUI_T(KC_M), KC_G)) {
        SEND_STRING("arkanoryn@gmail.com");
   } else if (leader_sequence_two_keys(LGUI_T(KC_M), LT(ACCT, KC_A))) {
        SEND_STRING("psormani@anynines.com");
   }

   // CTRL/CMD + / for commenting lines
   // DF to the different layers
   // RENAME!?!

}

// } else if (leader_sequence_two_keys(KC_D, KC_D)) {
//     // Leader, d, d => Ctrl+A, Ctrl+C
//     SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
// } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
//     // Leader, d, d, s => Types the below string
//     SEND_STRING("https://start.duckduckgo.com\n");
// } else if (leader_sequence_two_keys(KC_A, KC_S)) {
//     // Leader, a, s => GUI+S
//     tap_code16(LGUI(KC_S));

void leader_end_user(void) {
    if (layer_state_is(ISRT)) {
        isrt_leader_end_user();
    }

};
