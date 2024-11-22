// /*
// **
// ** TODO:
// **
// */
// #include QMK_KEYBOARD_H
// #include "ark_v1.h"
// #include "tap_dance.h"

// /* Return an integer that corresponds to what kind of tap dance should be executed.
//  *
//  * How to figure out tap dance state: interrupted and pressed.
//  *
//  * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
//  *  under the tapping term. This is typically indicative that you are trying to "tap" the key.
//  *
//  * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
//  *  has ended, but the key is still being pressed down. This generally means the key is being "held".
//  *
//  * One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
//  *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
//  *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
//  *
//  * Good places to put an advanced tap dance:
//  *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
//  *
//  * Criteria for "good placement" of a tap dance key:
//  *  Not a key that is hit frequently in a sentence
//  *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
//  *    in a web form. So 'tab' would be a poor choice for a tap dance.
//  *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
//  *    letter 'p', the word 'pepper' would be quite frustrating to type.
//  *
//  * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
//  *
//  */
// td_state_t cur_dance(tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//     // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//     else
//       return TD_SINGLE_HOLD;
//   } else if (state->count == 2) {
//     // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//     // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//     // keystrokes of the key, and not the 'double tap' action/macro.
//     if (state->interrupted)
//       return TD_DOUBLE_SINGLE_TAP;
//     else if (state->pressed)
//       return TD_DOUBLE_HOLD;
//     else
//       return TD_DOUBLE_TAP;
//   }
//   // Assumes no one is trying to type the same letter three times (at least not quickly).
//   // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//   // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
//   if (state->count == 3) {
//     if (state->interrupted || !state->pressed) {
//       send_string("triple tap");
//       return TD_TRIPLE_TAP;
//     } else {
//       send_string("triple hold");
//       return TD_TRIPLE_HOLD;
//     }
//   } else {
//     char result[50];

//     sprintf(result, "%d", state->count);

//     send_string(result);
//     return TD_UNKNOWN;
//   }
// }

// // Create an instance of 'td_tap_t' for the 'x' tap dance.
// static td_tap_t xtap_state = {.is_press_action = true, .state = TD_NONE};

// void x_finished(tap_dance_state_t *state, void *user_data) {
//   xtap_state.state = cur_dance(state);
//   switch (xtap_state.state) {
//     case TD_SINGLE_TAP:
//       register_code(KC_X);
//       break;
//     case TD_SINGLE_HOLD:
//       break;
//     case TD_DOUBLE_TAP:
//       break;
//     case TD_DOUBLE_HOLD:
//       break;
//     // Last case is for fast typing. Assuming your key is `f`:
//     // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//     // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//     case TD_DOUBLE_SINGLE_TAP:
//       tap_code(KC_X);
//       register_code(KC_X);
//       break;
//     case TD_TRIPLE_TAP:
//       send_string("triple tap");
//       break;
//     default:
//       break;
//   }
// }

// void x_reset(tap_dance_state_t *state, void *user_data) {
//   switch (xtap_state.state) {
//     case TD_SINGLE_TAP:
//       send_string("single tap");
//       unregister_code(KC_X);
//       break;
//     case TD_SINGLE_HOLD:
//       send_string("single hold");
//       break;
//     case TD_DOUBLE_TAP:
//       send_string("double tap");
//       unregister_code(KC_ESC);
//       break;
//     case TD_DOUBLE_HOLD:
//       send_string("double hold");
//       break;
//     case TD_DOUBLE_SINGLE_TAP:
//       send_string("double single tap");
//       unregister_code(KC_X);
//       break;
//     case TD_TRIPLE_TAP:
//       send_string("triple tap");
//       unregister_code(KC_X);
//       break;
//     default:
//       break;
//   }
//   xtap_state.state = TD_NONE;
// }

// // #define APP_NEW_WINDOW (detected_host_os() == OS_MACOS ? SS_LCMD("n") : SS_LCTL("n"))
// // #define APP_NEW_WINDOW_INCOGNITO (detected_host_os() == OS_MACOS ? SS_LCMD(SS_LSFT("n")) : SS_LCTL(SS_LSFT("n")))

// // void process_new_window(tap_dance_state_t *state, void *user_data) {
// //   if (state->count == 0) {
// //     send_string(APP_NEW_WINDOW_INCOGNITO);
// //   } else {
// //     send_string(APP_NEW_WINDOW_INCOGNITO);
// //   }
// // };

// // tap_dance_action_t tap_dance_actions[] = {
// //     [TD_NEW_WINDOW] = ACTION_TAP_DANCE_FN(process_new_window),
// // };
// // bool process_tap_dance(uint16_t keycode, keyrecord_t *record) {
// //   switch (keycode) {
// //     case TD(TD_NEW_WINDOW): // list all tap dance keycodes with tap-hold configurations
// //       action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
// //       if (!record->event.pressed && action->state.count && !action->state.finished) {
// //         tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
// //         tap_code16(tap_hold->tap);
// //       }
// //   }
// //   return true;
// // };
