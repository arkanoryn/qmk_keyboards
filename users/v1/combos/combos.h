/*
 * Requirements:
 * - add `INTROSPECTION_KEYMAP_C = generated/combos.c` to your `rules.mk`
 */
#pragma once

#include QMK_KEYBOARD_H
#include "ark_v1.h" // KEYMAP_MAIN_H
#include "generated/combos.h"
#include "layers.h"

#define COMBO_STR_MAX_LENGTH 15

void set_combo_event_timer(void);
void combo_event_task(void);
