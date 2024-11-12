#ifdef OLED_ENABLE
#  include "oled_driver.h"
#  include QMK_KEYBOARD_H
#  include "ark_v1.h"
#  include "oled.h"
#  include "teacher/chord_teacher.h"

oled_state_s state = {};

void update_oled_state(void) {
  state.teacher_mode = get_teacher_chord_mode();
  state.chord_buffer = get_teacher_chord_buffer();
}

oled_state_s get_oled_state(void) {
  return state;
}

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
  oled_write_ln_P(PSTR("T_MOD"), true);

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

// not working for some reasons.
void render_chord_buffer(void) {
  oled_write_ln_P(PSTR("T_BUF"), true);
  if (state.chord_buffer == NULL || state.chord_buffer[0] == '\0') {
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
  } else {
    oled_write_ln_P(PSTR(state.chord_buffer), false);
  }
}

void render_master_active(void) {
  render_highest_layer();
  render_space();
  render_user_LED_state();
  render_space();
  oled_set_cursor(0, 6);
  render_mods_status();
  render_luna(0, 11);
  oled_set_cursor(2, 14);
  render_wpm();
}

void render_off_hand_active(void) {
  oled_set_cursor(0, 0);
  render_flame();
  oled_set_cursor(0, 5);
  render_space();
  render_teacher_mode();
  render_space();
//   render_chord_buffer();
  // this I can only get on the main board, apparently || need to push to the state to make it work
  // render_clock(0, 11);
};

bool manage_timeout(void) {
#  if OLED_TIMEOUT > 0
  /* the animation prevents the normal timeout from occuring */
  if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return false;
  } else {
    oled_on();
  }
#  endif
  return true;
};

bool oled_task_user() {
  if (!manage_timeout()) {
    return false;
  };

  if (is_keyboard_master()) {
    render_master_active();
  } else {
    render_off_hand_active();
  }
  return false;
};

bool process_oled_displays(uint16_t keycode, keyrecord_t* record) {
  //   if (!process_clock(keycode, record)) { return false; }
  process_pet_status(keycode, record);
  return true;
};

void user_sync_state_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
  memcpy(&state, in_data, sizeof(oled_state_s));
};

#endif // OLED_ENABLE
