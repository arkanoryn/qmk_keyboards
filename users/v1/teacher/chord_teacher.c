/*
** This is stolen from [sartak's](https://github.com/sartak/qmk-config/blob/a3b1cd5592d503ae7f2dc201b58ef5b729f4b9b0/keymap.c#L554)
** implementation and modified to my need (eventually)
*/

#include "quantum.h"
#include "ark_v1.h"
#include "chord_teacher.h"
#include "generated/correct_chords.h"
#include "combos/combos.h"

#define TEACHER_CORRECTION_BUFFER_LENGTH 20
#define CORRECTION_TIMEOUT 15000

typedef struct {
  char                 buffer[TEACHER_CORRECTION_BUFFER_LENGTH];
  uint8_t              length;
  bool                 skip;
  char                *last_correction;
  uint16_t             timer;
  teacher_chord_mode_e mode;
} teacher_s;

// clang-format off
static teacher_s teacher_state = {
    .buffer          = {0},
    .length          = 0,
    .skip            = true, // wait til we see the first space
    .last_correction = NULL,
    .timer           = 0,
    .mode            = DEFAULT_TEACHER_CHORD_MODE,
};
// clang-format on

void init_teacher_state(void) {
  teacher_state.length                       = 0;
  teacher_state.buffer[teacher_state.length] = 0;
  teacher_state.skip                         = false; // wait til we see the first space
  teacher_state.last_correction              = NULL;
  teacher_state.timer                        = 0;
  teacher_state.mode                         = DEFAULT_TEACHER_CHORD_MODE;
};

void reset_teacher_state(bool clear_teacher_state) {
  if (clear_teacher_state) {
    teacher_state.last_correction = NULL;
  }
  teacher_state.length                       = 0;
  teacher_state.buffer[teacher_state.length] = 0;
  teacher_state.skip                         = false;
  teacher_state.timer                        = timer_read();
};

// FIXME: this must be a generic solution
uint16_t is_valid_alphakey(uint16_t keycode) {
  switch (keycode) {
    case GRAPHITE_A:
    case GRAPHITE_B:
    case GRAPHITE_C:
    case GRAPHITE_D:
    case GRAPHITE_E:
    case GRAPHITE_F:
    case GRAPHITE_G:
    case GRAPHITE_H:
    case GRAPHITE_I:
    case GRAPHITE_J:
    case GRAPHITE_K:
    case GRAPHITE_L:
    case GRAPHITE_M:
    case GRAPHITE_N:
    case GRAPHITE_O:
    case GRAPHITE_P:
    case GRAPHITE_Q:
    case GRAPHITE_R:
    case GRAPHITE_S:
    case GRAPHITE_T:
    case GRAPHITE_U:
    case GRAPHITE_V:
    case GRAPHITE_W:
    case GRAPHITE_X:
    case GRAPHITE_Y:
    case GRAPHITE_Z:
      return true;
  }
  return false;
};

bool try_correct(void) {
  teacher_state.last_correction = check_chord(teacher_state.buffer);
  if (teacher_state.last_correction == NULL) {
    return true;
  }

  for (uint16_t i = 0; i < teacher_state.length - 1; i++) {
    tap_code16(KC_BSPC);
  }
  send_temporary_string(teacher_state.last_correction);
  reset_teacher_state(false);
  return false;
};

void chord_teacher_task(void) {
  if (timer_elapsed(teacher_state.timer) > CORRECTION_TIMEOUT) {
    if (!teacher_state.skip && teacher_state.length == 0) {
      teacher_state.timer = timer_read();
    } else {
      teacher_state.skip = true;
    }
  }
}

void update_buffer(char new_char) {
  teacher_state.buffer[teacher_state.length++] = new_char;
  teacher_state.buffer[teacher_state.length]   = 0;
}

bool process_chord_teacher(uint16_t keycode, keyrecord_t *record) {
  if (teacher_state.mode != TEACHER_CHORD_MODE_CORRECTIVE) {
    return true;
  }
  if (!record->event.pressed || keycode == KC_NO || teacher_state.skip) {
    return true;
  }
  if (teacher_state.length > TEACHER_CORRECTION_BUFFER_LENGTH - 1) {
    teacher_state.skip = true;
    return true;
  }

  const uint8_t current_mod_state         = get_mods();
  const uint8_t current_oneshot_mod_state = get_oneshot_mods();
  const uint8_t mods                      = current_oneshot_mod_state > current_mod_state ? current_oneshot_mod_state : current_mod_state;

  if ((mods & MOD_MASK_CAG) == 0 && is_valid_alphakey(keycode)) {
    update_buffer((keycode - KC_A + 'A') | ((mods & MOD_MASK_SHIFT) ? 0 : 0x20));

    if (!try_correct()) {
      return false;
    }
  } else if (keycode == MEH_SPC || keycode == KC_ENT) {
    if (!teacher_state.skip) {
      update_buffer(' ');

      if (!try_correct()) {
        return false;
      }
    }

    reset_teacher_state(true);
  } else if (keycode == KC_BSPC) {
    teacher_state.timer = timer_read();
    // if we press BSPC, we should also remove it from the current string with which
    // we are going to run the comparison. We should however ensure that we are not
    // going BELOW 0, in which case we reset (safety first)
    (teacher_state.length > 0) ? teacher_state.length-- : reset_teacher_state(true);
  } else {
    teacher_state.skip = true;
  }

  return true;
};

char *get_teacher_chord_buffer(void) {
  return teacher_state.buffer;
};

teacher_chord_mode_e get_teacher_chord_mode(void) {
  return teacher_state.mode;
};

void set_teacher_chord_mode(teacher_chord_mode_e new_mode) {
  teacher_state.mode = new_mode;

  if (new_mode == _CHORD_MODE_LENGTH) {
    teacher_state.mode = TEACHER_CHORD_MODE_NORMAL;
  }
};
