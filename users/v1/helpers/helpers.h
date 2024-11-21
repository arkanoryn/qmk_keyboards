#pragma once

// Source: graphite.c

// like all process function, this one serves to process the special keys from
// the Graphite layer.
bool process_graphite_keys(uint16_t keycode, keyrecord_t *record);

//  Source: temporary_message.c

/*
**  Sends keystroke matching the string received in arguments.
**    The function works with the `clear_last_message` that is expected
**    to be called in the `pre_process_record_user` and make the "str"
**    temporary.
*/
void send_temporary_string(const char *str);
void clear_last_message(keyrecord_t *record);

//  Source: helpers.c

const uint8_t all_mods(void);      // Returns all mods currently enabled
bool          is_shifted(void);    // returns if shift is enabled or not
void          disable_shift(void); // del mods and weak mods and onshot for shift.
