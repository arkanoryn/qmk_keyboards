#include "ark_v1.h"
#include "config.h"
#include "teacher/chord_teacher.h"

bool process_config(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifdef CHORD_TEACHER_ENABLE
    case CYCLE_CHORD_MODE:
      if (record->event.pressed) {
        set_teacher_chord_mode(get_teacher_chord_mode() + 1);
      }
      return false;
#endif // CHORD_TEACHER_ENABLE
    default:
      return true;
  }
};
