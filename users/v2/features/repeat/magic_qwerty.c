/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "farkann_v2.h"
#include "repeat.h"

/* Get MAGIC key for Qwerty layout */
bool process_magic_key_qwerty(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case QWERTY_B: SEND_STRING("efore"); break;
        case QWERTY_L: SEND_STRING("l"); break;
        case QWERTY_D: SEND_STRING("evelop"); break;
        case QWERTY_W: SEND_STRING("hat"); break;
        case QWERTY_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case QWERTY_N: SEND_STRING("n"); break;
        case QWERTY_R: SEND_STRING("l"); break;
        case QWERTY_T: SEND_STRING("ment"); break;
        case QWERTY_S: SEND_STRING("s"); break;
        case QWERTY_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case QWERTY_Q: SEND_STRING("q"); break;
        case QWERTY_X: SEND_STRING("x"); break;
        case QWERTY_M: SEND_STRING("ent"); break;
        case QWERTY_C: SEND_STRING("c"); break;
        case QWERTY_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case QWERTY_F: SEND_STRING("f"); break;
        case QWERTY_O:  SEND_STRING("a"); break;
        case QWERTY_U: SEND_STRING("u"); break;
        case QWERTY_J: SEND_STRING("j"); break;
        case QWERTY_QUOTE: SEND_STRING("ll"); break;
        /* Middle row right */
        case QWERTY_Y: SEND_STRING("ou"); break;
        case QWERTY_H: SEND_STRING("owever"); break;
        case QWERTY_A: SEND_STRING("o"); break;
        case QWERTY_E: SEND_STRING("u"); break;
        case QWERTY_I: SEND_STRING("on"); break;
        /* Bottom row right */
        case QWERTY_K: SEND_STRING("k"); break;
        case QWERTY_P:  SEND_STRING("p"); break;
        case QWERTY_DOT: SEND_STRING("com"); break;
        case QWERTY_COMM: SEND_STRING(" but"); break;
        case QWERTY_SLSH: break;
    }
    return false;
}

/* Get ARCANE key for Qwerty layout */
bool process_arcane_key_qwerty(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case QWERTY_B: SEND_STRING("ecause"); break;
        case QWERTY_L: SEND_STRING("l"); break;
        case QWERTY_D: SEND_STRING("evelop"); break;
        case QWERTY_W: SEND_STRING("hat"); break;
        case QWERTY_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case QWERTY_N: SEND_STRING("n"); break;
        case QWERTY_R: SEND_STRING("l"); break;
        case QWERTY_T: SEND_STRING("ment"); break;
        case QWERTY_S: SEND_STRING("s"); break;
        case QWERTY_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case QWERTY_Q: SEND_STRING("q"); break;
        case QWERTY_X: SEND_STRING("x"); break;
        case QWERTY_M: SEND_STRING("ent"); break;
        case QWERTY_C: SEND_STRING("c"); break;
        case QWERTY_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case QWERTY_F: SEND_STRING("or"); break;
        case QWERTY_O:  SEND_STRING("a"); break;
        case QWERTY_U: SEND_STRING("u"); break;
        case QWERTY_J: SEND_STRING("j"); break;
        case QWERTY_QUOTE: SEND_STRING("ve"); break;
        /* Middle row right */
        case QWERTY_Y: SEND_STRING("ou"); break;
        case QWERTY_H: SEND_STRING("ow"); break;
        case QWERTY_A: SEND_STRING("o"); break;
        case QWERTY_E: SEND_STRING("u"); break;
        case QWERTY_I: SEND_STRING("ng"); break;
        /* Bottom row right */
        case QWERTY_K: SEND_STRING("k"); break;
        case QWERTY_P:  SEND_STRING("h"); break;
        case QWERTY_DOT: break;
        case QWERTY_COMM: break;
        case QWERTY_SLSH: break;
    }
    return false;
}