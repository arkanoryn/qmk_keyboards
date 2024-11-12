#include "oled_driver.h"
#include QMK_KEYBOARD_H
#include "ark_v1.h"
#include "oled.h"
#include "teacher/chord_teacher.h"

oled_state_s state = {};

void update_oled_state(void) {
  state.teacher_mode = get_teacher_chord_mode();
  state.chord_buffer = get_teacher_chord_buffer();
}

oled_state_s get_oled_state(void) {
  return state;
}

#ifdef OLED_ENABLE

// static void render_nickname(void) {
// static const char PROGMEM clean_nickname[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 192, 192, 192, 192, 192, 192, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 123, 123, 123, 123, 127, 127, 115, 115, 115, 127, 63, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 60,  60,  60,  60,  60,  124, 252, 252, 220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  188, 188, 188, 252, 252, 252, 252, 252, 188, 188, 60, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,   7,   3,   3,   1,   1,   3,   3,   231, 231, 224, 224, 224, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 240, 240, 240, 240, 240, 112, 112, 112, 241, 225, 193, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 30, 30, 30, 31, 31, 30, 30, 30, 15, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 247, 247, 247, 247, 247, 247, 247, 255, 127, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 240, 248, 56,  56,  56,  56,  248, 240, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 195, 199, 199, 199, 199, 199, 199, 195, 193, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,  131, 195, 195, 195, 195, 199, 207, 207, 205, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 62, 60, 63,  63,  63,  59,  59,  59,  59,  59,  59,  59,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 220, 220, 220, 220, 220, 220, 220, 252, 252, 252, 0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,   3,   3,   3,   3,   3,   3,   3,   1,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//     oled_write_raw_P(clean_nickname, sizeof(clean_nickname));
// };

static void render_flame(void) {
  static const char PROGMEM raw_logo[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 208, 240, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 244, 227, 192, 248, 254, 255, 255, 255, 255, 255, 255, 255, 224, 240, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 63, 63, 127, 127, 255, 255, 255, 127, 127, 127, 63, 63, 15, 3, 0, 0, 0, 0, 0, 0, 0, 0};

  oled_write_raw_P(raw_logo, sizeof(raw_logo));
};

void render_highest_layer(void) {
  switch (get_highest_layer(layer_state)) {
    case GRPT:
      oled_write_ln_P(PSTR("GRPT"), false);
      break;
    case ISRT:
      oled_write_ln_P(PSTR("ISRT"), false);
      break;
    case ACT:
      oled_write_ln_P(PSTR("ACTS"), false);
      break;
    case SMBL:
      oled_write_ln_P(PSTR("SYMB"), false);
      break;
    case ACCT:
      oled_write_ln_P(PSTR("ACNT"), false);
      break;
    case NPD:
      oled_write_ln_P(PSTR("NUM"), false);
      break;
    case CONFIG:
      oled_write_ln_P(PSTR("CONF"), false);
      break;
    default:
      oled_write_ln_P(PSTR("??"), false);
  }
};

void render_teacher_mode(void) {
  oled_write_ln_P(PSTR("MODE:"), true);

  switch (state.teacher_mode) {
    case TEACHER_CHORD_MODE_NORMAL:
      oled_write_ln_P(PSTR("NORM"), false);
      break;
    case TEACHER_CHORD_MODE_CORRECTIVE:
      oled_write_ln_P(PSTR("CORRE"), false);
      break;
    case TEACHER_CHORD_MODE_OFF:
      oled_write_ln_P(PSTR("OFF"), false);
      break;
    default:
      break;
  };
};

void render_user_LED_state(void) {
  // Host Keyboard LED Status
  led_t led_usb_state = host_keyboard_led_state();
  oled_write_P(led_usb_state.num_lock ? PSTR("N ") : PSTR("  "), false);
  oled_write_P(led_usb_state.caps_lock ? PSTR("C ") : PSTR("  "), false);
  oled_write_P(led_usb_state.scroll_lock ? PSTR("S ") : PSTR("  "), false);
}

void render_chord_buffer(void) {
  if (state.chord_buffer == NULL) {
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
  } else {
    oled_write_ln_P(PSTR(state.chord_buffer), false);
  }
}

bool oled_task_user() {
#  if OLED_TIMEOUT > 0
  /* the animation prevents the normal timeout from occuring */
  if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return false;
  } else {
    oled_on();
  }
#  endif

  if (is_keyboard_master()) {
    render_highest_layer();
    render_space();
    render_wpm();
    render_user_LED_state();
    render_space();
    oled_set_cursor(0, 6);
    render_mods_status();
    render_luna(0, 12);
  } else {
    oled_set_cursor(0, 0);
    render_flame();
    oled_set_cursor(0, 5);
    render_space();
    render_teacher_mode();
    render_space();
    render_chord_buffer();
    // this I can only get on the main board, apparently || need to push to the state to make it work
    // render_clock(0, 11);
  }
  return false;
};

void user_sync_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
  memcpy(&state, in_data, sizeof(oled_state_s));
}

#endif // OLED_ENABLE
