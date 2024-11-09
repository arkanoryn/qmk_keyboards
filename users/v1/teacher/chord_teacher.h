/*
** TODO:
*/
#pragma once

#include "ark_v1.h"

typedef enum {
  TEACHER_CHORD_MODE_NORMAL = 0,
  TEACHER_CHORD_MODE_CORRECTIVE,
  TEACHER_CHORD_MODE_OFF,
  _CHORD_MODE_LENGTH,
} teacher_chord_mode_e;

#ifndef TOPLAYER
#  define TOPLAYER CONFIG
#endif // TOPLAYER

#ifndef DEFAULT_TEACHER_CHORD_MODE
#  define DEFAULT_TEACHER_CHORD_MODE TEACHER_CHORD_MODE_CORRECTIVE
#endif // DEFAULT_TEACHER_CHORD_MODE

bool                 process_chord_teacher(uint16_t keycode, keyrecord_t *record);
void                 init_teacher_state(void);
void                 reset_teacher_state(bool clear_teacher_state);
void                 chord_teacher_task(void);
teacher_chord_mode_e get_teacher_chord_mode(void);
void                 set_teacher_chord_mode(teacher_chord_mode_e new_mode);
