#include "ark_v1.h"
#include "config.h"
#include "teacher/chord_teacher.h"

bool process_config(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CYCLE_CHORD_MODE:
      if (record->event.pressed) {
        set_teacher_chord_mode(get_teacher_chord_mode() + 1);
      }
      return false;
  }
  return true;
};
