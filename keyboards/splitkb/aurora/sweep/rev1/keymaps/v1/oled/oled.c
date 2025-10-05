#ifdef OLED_ENABLE
#  include "oled_driver.h"
#  include "transactions.h"
#  include QMK_KEYBOARD_H
#  include "ark_v1.h"
#  include "oled.h"
#  include "teacher/chord_teacher.h"

oled_state_s oled_state = {};

void update_oled_state(void) {
  oled_state.teacher_mode = get_teacher_chord_mode();
  oled_state.chord_buffer = get_teacher_chord_buffer();
};

oled_state_s get_oled_state(void) {
  return oled_state;
};

void render_highest_layer(void) {
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR("GRPT"), false);
      break;
    case _ACTIONS:
      oled_write_ln_P(PSTR("ACTS"), false);
      break;
    case _SYMBOLS:
      oled_write_ln_P(PSTR("SYMB"), false);
      break;
    case _ACCENTS:
      oled_write_ln_P(PSTR("ACNT"), false);
      break;
    case _NUMPAD_SOUND:
      oled_write_ln_P(PSTR("NUM"), false);
      break;
    case _CONFIG:
      oled_write_ln_P(PSTR("CONF"), false);
      break;
    default:
      oled_write_ln_P(PSTR("??"), false);
  }
};

void render_teacher_mode(void) {
  switch (oled_state.teacher_mode) {
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

// not working for some reasons when on the slave side.
void render_chord_buffer(void) {
  if (oled_state.chord_buffer == NULL || oled_state.chord_buffer[0] == '\0') {
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("     "), false);
  } else {
    oled_write_ln_P(PSTR(oled_state.chord_buffer), false);
  }
}

void render_off_hand_active(void) {
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

void render_master_active(void) {
  oled_set_cursor(0, 0);
  render_flame();
  oled_set_cursor(0, 4);
  render_teacher_mode();
  render_space();
  render_chord_buffer();
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
  memcpy(&oled_state, in_data, sizeof(oled_state_s));
};

void oled_housekeeping_task(void) {
  if (is_keyboard_master()) { // move to "oled_housekeeping_task"
    static uint32_t last_sync = 0;

    if (timer_elapsed32(last_sync) > 500) {
      update_oled_state();
      const oled_state_s state = get_oled_state();

      if (transaction_rpc_send(USER_SYNC_STATE, sizeof(state), &state)) {
        last_sync = timer_read32();
      } else {
        dprint("Slave sync failed!\n");
      }
    }
  }
};

void init_oled_state(void) {
  //   defer_exec(clock_callback(0, NULL), clock_callback, NULL); // move to "init_oled"
  transaction_register_rpc(USER_SYNC_STATE, user_sync_state_handler); // move to "init_oled"
                                                                      //   oled_clear(); // move_to "init _oled"

  oled_state.teacher_mode = get_teacher_chord_mode();
  oled_state.chord_buffer = get_teacher_chord_buffer();
}

#endif // OLED_ENABLE
