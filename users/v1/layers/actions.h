/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
**
** /!\ This layer requires the implementation of the shortcuts
*/
#pragma once

#include QMK_KEYBOARD_H
// #include "ark_v1.h" // root_config
#include "layers.h" // each keyboard should have this file with the available layers enum
#include "shortcuts/shortcuts.h"

#define __X__ KC_NO
#define _____ KC_TRNS

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#define __________ACTIONS_LEFT_ROW_1________ KC_ESC, CKC(CMD_COPY), CKC(LINE_BACKSPACE), CKC(WORD_BACKSPACE), KC_PGUP
#define __________ACTIONS_LEFT_ROW_2________ CKC(APP_PREV), CKC(APP_NEXT), KC_DEL, SEL_WORD, KC_PGDN
#define __________ACTIONS_LEFT_ROW_3________ CKC(CMD_CUT), CKC(CMD_PASTE), CKC(LINE_DEL), CKC(WORD_DEL), CKC(TAB_CLOSE)
#define __________ACTIONS_LEFT_THUMBS_______ CKC(LINE_SELECTL), CKC(WORD_SELECTL)

#define _________ACTIONS_RIGHT_ROW_1________ KC_HOME, CKC(WORD_JUMPL), CKC(WORD_JUMPR), RCS(KC_TAB), LCTL(KC_TAB)
#define _________ACTIONS_RIGHT_ROW_2________ KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
#define _________ACTIONS_RIGHT_ROW_3________ CKC(TAB_REOPEN), CKC(LINE_JUMPL), CKC(LINE_JUMPR), CKC(TASK_MNGR), __X__
#define _________ACTIONS_RIGHT_THUMBS_______ __X__, LAYER_LOCK
