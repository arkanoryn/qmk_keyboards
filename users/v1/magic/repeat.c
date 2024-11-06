
#include "ark_v1.h"
#include "../combos/combos.h"
#include "repeat.h"

void process_repeat_event_isrt(uint16_t keycode, uint8_t mods) {
  switch (keycode) {
      // clang-format off
    case ISRT_A: SEND_STRING("u"); break;
    case ISRT_B: SEND_STRING("r"); break;
    case ISRT_C: SEND_STRING("c"); break;
    case ISRT_D: SEND_STRING("evelop"); break;
    case ISRT_E: SEND_STRING("u"); break;
    case ISRT_F: SEND_STRING("f"); break;
    case ISRT_G: SEND_STRING("g"); break;
    case ISRT_H: SEND_STRING("owever"); break;
    case ISRT_I: SEND_STRING("on"); break;
    case ISRT_J: SEND_STRING("j"); break;
    case ISRT_K: SEND_STRING("k"); break;
    case ISRT_L: SEND_STRING("l"); break;
    case ISRT_M: SEND_STRING("ent"); break;
    case ISRT_N: SEND_STRING("n"); break;
    case ISRT_O: SEND_STRING("u"); break;
    case ISRT_P: SEND_STRING("h"); break;
    case ISRT_Q: SEND_STRING("q"); break;
    case ISRT_R: SEND_STRING("r"); break;
    case ISRT_S: SEND_STRING("s"); break;
    case ISRT_T: SEND_STRING("ment"); break;
    case ISRT_U: SEND_STRING("u"); break;
    case ISRT_V: SEND_STRING("v"); break;
    case ISRT_W: SEND_STRING("hat"); break;
    case ISRT_X: SEND_STRING("x"); break;
    case ISRT_Y: SEND_STRING("y"); break;
    case ISRT_Z: SEND_STRING("z"); break;
    // clang-format on
    case ISRT_COMM:
      if (mods & MOD_MASK_SHIFT) {
        SEND_STRING("\b=");
      } else {
        SEND_STRING(", but");
        return;
      }
      break;
  }
}

void process_repeat_event_graphite(uint16_t keycode, uint8_t mods) {
  switch (keycode) {
      // clang-format off
    case GRAPHITE_A: SEND_STRING("o"); break;
    case GRAPHITE_B: SEND_STRING("efore"); break;
    case GRAPHITE_C: SEND_STRING("c"); break;
    case GRAPHITE_D: SEND_STRING("evelop"); break;
    case GRAPHITE_E: SEND_STRING("u"); break;
    case GRAPHITE_F: SEND_STRING("f"); break;
    case GRAPHITE_G: SEND_STRING("g"); break;
    case GRAPHITE_H: SEND_STRING("owever"); break;
    case GRAPHITE_I: SEND_STRING("on"); break;
    case GRAPHITE_J: SEND_STRING("j"); break;
    case GRAPHITE_K: SEND_STRING("k"); break;
    case GRAPHITE_L: SEND_STRING("l"); break;
    case GRAPHITE_M: SEND_STRING("ent"); break;
    case GRAPHITE_N: SEND_STRING("n"); break;
    case GRAPHITE_O: SEND_STRING("a"); break;
    case GRAPHITE_P: SEND_STRING("h"); break;
    case GRAPHITE_Q: SEND_STRING("q"); break;
    case GRAPHITE_R: SEND_STRING("l"); break;
    case GRAPHITE_S: SEND_STRING("s"); break;
    case GRAPHITE_T: SEND_STRING("ment"); break;
    case GRAPHITE_U: SEND_STRING("e"); break;
    case GRAPHITE_V: SEND_STRING("v"); break;
    case GRAPHITE_W: SEND_STRING("hat"); break;
    case GRAPHITE_X: SEND_STRING("x"); break;
    case GRAPHITE_Y: SEND_STRING("y"); break;
    case GRAPHITE_Z: SEND_STRING("z"); break;
    case GRAPHITE_DOT: SEND_STRING("com"); break;
    // clang-format on
    case GRAPHITE_ENT:
    case GRAPHITE_SPC:
      add_oneshot_mods(MOD_LSFT);
      break;
    case GRAPHITE_COMM:
      if (mods & MOD_MASK_SHIFT) {
        SEND_STRING("\b=");
      } else {
        SEND_STRING(", but");
        return;
      }
      break;
  }
}

void process_repeat_event(uint16_t keycode, uint8_t mods) {
  if (layer_state_is(ISRT)) {
    process_repeat_event_isrt(keycode, mods);
  } else if (layer_state_is(GRPT)) {
    process_repeat_event_graphite(keycode, mods);
  }
}

// This is to ignore the MAGIC key for the REPEAT function
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
  switch (keycode) {
    case MAGIC:
      return false; // Ignore backspace.
  }

  return true; // Other keys can be repeated.
}
