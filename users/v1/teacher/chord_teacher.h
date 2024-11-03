/*
** TODO:
*/
#pragma once

#include "ark_v1.h"

typedef enum {
  CHORD_MODE_NORMAL,
  CHORD_MODE_CORRECTIVE,
  CHORD_MODE_EXCLUSIVE,
  CHORD_MODE_OFF,
  _CHORD_MODE_LENGTH,
} setting_chord_mode;

#ifndef TOPLAYER
#  define TOPLAYER NPD
#endif // TOPLAYER

bool process_chord_teacher(uint16_t keycode, keyrecord_t *record);
void init_teacher_state(void);
void reset_teacher_state(bool clear_teacher_state);
void chord_teacher_task(void);
