#pragma once

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Layer Lock config
#define LAYER_LOCK_IDLE_TIMEOUT 300000 // Turn off after 60 seconds.

// OS configurations
#define OS_DETECTION_KEYBOARD_RESET
#define OS_DETECTION_DEBOUNCE 200

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define SELECT_WORD_TIMEOUT 2000
#define SENTENCE_CASE_TIMEOUT 2000

#define COMBO_TERM 60        // default is 50
#define COMBO_SHOULD_TRIGGER // can define on which layer (for example) a combo is triggerable

// CAPS WORD config
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT    // Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_IDLE_TIMEOUT 15000 // When idle, turn off Caps Word after X seconds.

#define RGB_MATRIX_TIMEOUT 300000 // in milliseconds = 5 minutes
