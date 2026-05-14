/* Copyright 2026 Ark'Anoryn (@arkanoryn)
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

/* Get MAGIC key for Graphite layout */
bool process_magic_key_graphite(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case GRAPHITE_B: SEND_STRING("efore"); break;
        case GRAPHITE_L: SEND_STRING("l"); break;
        case GRAPHITE_D: SEND_STRING("evelop"); break;
        case GRAPHITE_W: SEND_STRING("hat"); break;
        case GRAPHITE_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case GRAPHITE_N: SEND_STRING("n"); break;
        case GRAPHITE_R: SEND_STRING("l"); break;
        case GRAPHITE_T: SEND_STRING("ment"); break;
        case GRAPHITE_S: SEND_STRING("s"); break;
        case GRAPHITE_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case GRAPHITE_Q: SEND_STRING("q"); break;
        case GRAPHITE_X: SEND_STRING("x"); break;
        case GRAPHITE_M: SEND_STRING("ent"); break;
        case GRAPHITE_C: SEND_STRING("c"); break;
        case GRAPHITE_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case GRAPHITE_F: SEND_STRING("f"); break;
        case GRAPHITE_O:  SEND_STRING("a"); break;
        case GRAPHITE_U: SEND_STRING("u"); break;
        case GRAPHITE_J: SEND_STRING("j"); break;
        case GRAPHITE_QUOTE: SEND_STRING("ll"); break;
        /* Middle row right */
        case GRAPHITE_Y: SEND_STRING("ou"); break;
        case GRAPHITE_H: SEND_STRING("owever"); break;
        case GRAPHITE_A: SEND_STRING("o"); break;
        case GRAPHITE_E: SEND_STRING("u"); break;
        case GRAPHITE_I: SEND_STRING("on"); break;
        /* Bottom row right */
        case GRAPHITE_K: SEND_STRING("k"); break;
        case GRAPHITE_P:  SEND_STRING("p"); break;
        case GRAPHITE_DOT: SEND_STRING("com"); break;
        case GRAPHITE_COMM: SEND_STRING(" but"); break;
        case GRAPHITE_SLSH: break;
    }
    return false;
}

/* Get ARCANE key for Graphite layout */
bool process_arcane_key_graphite(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case GRAPHITE_B: SEND_STRING("ecause"); break;
        case GRAPHITE_L: SEND_STRING("l"); break;
        case GRAPHITE_D: SEND_STRING("evelop"); break;
        case GRAPHITE_W: SEND_STRING("hat"); break;
        case GRAPHITE_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case GRAPHITE_N: SEND_STRING("n"); break;
        case GRAPHITE_R: SEND_STRING("l"); break;
        case GRAPHITE_T: SEND_STRING("ment"); break;
        case GRAPHITE_S: SEND_STRING("s"); break;
        case GRAPHITE_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case GRAPHITE_Q: SEND_STRING("q"); break;
        case GRAPHITE_X: SEND_STRING("x"); break;
        case GRAPHITE_M: SEND_STRING("ent"); break;
        case GRAPHITE_C: SEND_STRING("c"); break;
        case GRAPHITE_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case GRAPHITE_F: SEND_STRING("or"); break;
        case GRAPHITE_O:  SEND_STRING("a"); break;
        case GRAPHITE_U: SEND_STRING("u"); break;
        case GRAPHITE_J: SEND_STRING("j"); break;
        case GRAPHITE_QUOTE: SEND_STRING("ve"); break;
        /* Middle row right */
        case GRAPHITE_Y: SEND_STRING("ou"); break;
        case GRAPHITE_H: SEND_STRING("ow"); break;
        case GRAPHITE_A: SEND_STRING("o"); break;
        case GRAPHITE_E: SEND_STRING("u"); break;
        case GRAPHITE_I: SEND_STRING("ng"); break;
        /* Bottom row right */
        case GRAPHITE_K: SEND_STRING("k"); break;
        case GRAPHITE_P:  SEND_STRING("h"); break;
        case GRAPHITE_DOT: break;
        case GRAPHITE_COMM: break;
        case GRAPHITE_SLSH: break;
    }
    return false;
}
