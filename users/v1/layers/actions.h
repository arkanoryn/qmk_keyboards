/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
**
** /!\ This layer requires the implementation of the shortcuts
*/
#pragma once

#include QMK_KEYBOARD_H
#include "layers.h" // each keyboard should have this file with the available layers enum
#include "shortcuts/shortcuts.h"
#include "tap_dance/tap_dance.h"

#define __X__ KC_NO
#define _____ KC_TRNS

#define TAB_NEXT LCTL(KC_TAB)
#define TAB_PREV RCS(KC_TAB)

#ifndef CKC
#  define CKC(x) (SAFE_RANGE + x) // generate custom keycode from enum
#endif                            // CKC

#define __________ACTIONS_LEFT_ROW_1________ TD(TD_ESC), TD(TD_SEARCH), CKC(ALFRED), KC_DEL, CKC(APP_PREV)
#define __________ACTIONS_LEFT_ROW_2________ KC_TAB, CKC(CMD_SAVE), TD(TD_SELECTION_BACKWARD), TD(TD_SELECTION_FORWARD), CKC(APP_NEXT)
#define __________ACTIONS_LEFT_ROW_3________ CKC(TASK_MNGR), CKC(CMD_REDO), CKC(CMD_UNDO), TD(TD_NEW_WINDOW), CKC(APP_CLOSE)
#define __________ACTIONS_LEFT_THUMBS_______ TD(TD_COPY), CKC(CMD_PASTE)

#define _________ACTIONS_RIGHT_ROW_1________ KC_PGUP, TD(TD_JUMP_BACKWARD), TD(TD_JUMP_FORWARD), KC_HOME, KC_END
#define _________ACTIONS_RIGHT_ROW_2________ KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
#define _________ACTIONS_RIGHT_ROW_3________ CKC(TAB_REOPEN), TD(TD_TAB_NEW), TD(TD_TAB_CLOSE), TAB_NEXT, TAB_PREV
#define _________ACTIONS_RIGHT_THUMBS_______ TD(TD_CUT), LAYER_LOCK
