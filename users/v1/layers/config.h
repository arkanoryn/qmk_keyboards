/*
** This file contains the different keycode definition dedicated to Graphite.
** Here we are only looking at the generic 5 rows of the 3 alpha column.
**  If a keyboard has more key, around the rows, the modifications should be done in the keymap.c
**
*/
#pragma once

#include QMK_KEYBOARD_H
#include "ark_v1.h" // root_config
#include "layers.h" // each keyboard should have this file with the available layers enum

#define __X__ KC_NO

#define __________CONFIG_LEFT_ROW_1_________ CYCLE_CHORD_MODE, __X__, __X__, __X__, __X__
#define __________CONFIG_LEFT_ROW_2_________ __X__, __X__, __X__, __X__, __X__
#define __________CONFIG_LEFT_ROW_3_________ QK_BOOT, __X__, __X__, __X__, __X__
#define __________CONFIG_LEFT_THUMBS________ __X__, __X__

#define _________CONFIG_RIGHT_ROW_1________ RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI
#define _________CONFIG_RIGHT_ROW_2________ RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
#define _________CONFIG_RIGHT_ROW_3________ __X__, __X__, __X__, __X__, __X__
#define _________CONFIG_RIGHT_THUMBS_______ RGB_TOG, TG(_CONFIG) // we turned ON the config layer, so now we want to turn it back off
