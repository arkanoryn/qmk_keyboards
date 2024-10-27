/*
* Requirements:
* - add `INTROSPECTION_KEYMAP_C = combos/generated_combos.c` to your `rules.mk`
*/
#pragma once

#include "quantum.h"
#include "ark_v1.h" // KEYMAP_MAIN_H
#include "generated_combos.h"

#define COMBO_STR_MAX_LENGTH 15

#define ISRT_A        L3_A
#define ISRT_B        KC_B
#define ISRT_C        CTL_C
#define ISRT_D        KC_D
#define ISRT_E        L2_E
#define ISRT_F        GUI_F
#define ISRT_G        KC_G
#define ISRT_H        KC_H
#define ISRT_I        L4_I
#define ISRT_J        KC_J
#define ISRT_K        KC_K
#define ISRT_L        ALT_L
#define ISRT_M        GUI_M
#define ISRT_N        L1_N
#define ISRT_O        L4_O
#define ISRT_P        KC_P
#define ISRT_Q        SFT_Q
#define ISRT_R        L2_R
#define ISRT_S        L3_S
#define ISRT_T        L1_T
#define ISRT_U        ALT_U
#define ISRT_V        KC_V
#define ISRT_W        KC_W
#define ISRT_X        SFT_X
#define ISRT_Y        KC_Y
#define ISRT_Z        KC_Z
#define ISRT_BSPC     KC_BSPC
#define ISRT_SPC      MEH_SPC
#define ISRT_SLSH     SFT_SLSH
#define ISRT_QUOT     KC_QUOT
#define ISRT_MAGIC    MAGIC
#define ISRT_COMM     CTL_COMM

#define GRAPHITE_A          L2_A
#define GRAPHITE_B          KC_B
#define GRAPHITE_C          KC_C
#define GRAPHITE_D          ALT_D
#define GRAPHITE_E          L3_E
#define GRAPHITE_F          GUI_F
#define GRAPHITE_G          KC_G
#define GRAPHITE_H          L1_H
#define GRAPHITE_I          L4_I
#define GRAPHITE_J          KC_J
#define GRAPHITE_K          KC_K
#define GRAPHITE_L          CTL_L
#define GRAPHITE_M          KC_M
#define GRAPHITE_N          L4_N
#define GRAPHITE_O          ALT_O
#define GRAPHITE_P          KC_P
#define GRAPHITE_Q          SFT_Q
#define GRAPHITE_R          L3_R
#define GRAPHITE_S          L1_S
#define GRAPHITE_T          L2_T
#define GRAPHITE_U          CTL_U
#define GRAPHITE_V          KC_V
#define GRAPHITE_W          GUI_W
#define GRAPHITE_X          KC_X
#define GRAPHITE_Y          KC_Y
#define GRAPHITE_Z          KC_Z
#define GRAPHITE_BSPC       KC_BSPC
#define GRAPHITE_SPC        KC_SPC
#define GRAPHITE_SLSH       SFT_SLSH
#define GRAPHITE_QUOT       KC_QUOT
#define GRAPHITE_MAGIC      MAGIC
#define GRAPHITE_COMM       KC_COMM

void set_combo_event_timer(void);
void combo_event_task(void);
