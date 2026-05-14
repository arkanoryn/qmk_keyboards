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

/* Get MAGIC key for Sturdy layout */
bool process_magic_key_sturdy(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case STURDY_B: SEND_STRING("efore"); break;
        case STURDY_L: SEND_STRING("l"); break;
        case STURDY_D: SEND_STRING("evelop"); break;
        case STURDY_W: SEND_STRING("hat"); break;
        case STURDY_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case STURDY_N: SEND_STRING("n"); break;
        case STURDY_R: SEND_STRING("l"); break;
        case STURDY_T: SEND_STRING("ment"); break;
        case STURDY_S: SEND_STRING("s"); break;
        case STURDY_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case STURDY_Q: SEND_STRING("q"); break;
        case STURDY_X: SEND_STRING("x"); break;
        case STURDY_M: SEND_STRING("ent"); break;
        case STURDY_C: SEND_STRING("c"); break;
        case STURDY_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case STURDY_F: SEND_STRING("f"); break;
        case STURDY_O:  SEND_STRING("a"); break;
        case STURDY_U: SEND_STRING("u"); break;
        case STURDY_J: SEND_STRING("j"); break;
        case STURDY_QUOTE: SEND_STRING("ll"); break;
        /* Middle row right */
        case STURDY_Y: SEND_STRING("ou"); break;
        case STURDY_H: SEND_STRING("owever"); break;
        case STURDY_A: SEND_STRING("o"); break;
        case STURDY_E: SEND_STRING("u"); break;
        case STURDY_I: SEND_STRING("on"); break;
        /* Bottom row right */
        case STURDY_K: SEND_STRING("k"); break;
        case STURDY_P:  SEND_STRING("p"); break;
        case STURDY_DOT: SEND_STRING("com"); break;
        case STURDY_COMM: SEND_STRING(" but"); break;
        case STURDY_SLSH: break;
    }
    return false;
}

/* Get ARCANE key for Sturdy layout */
bool process_arcane_key_sturdy(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case STURDY_B: SEND_STRING("ecause"); break;
        case STURDY_L: SEND_STRING("l"); break;
        case STURDY_D: SEND_STRING("evelop"); break;
        case STURDY_W: SEND_STRING("hat"); break;
        case STURDY_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case STURDY_N: SEND_STRING("n"); break;
        case STURDY_R: SEND_STRING("l"); break;
        case STURDY_T: SEND_STRING("ment"); break;
        case STURDY_S: SEND_STRING("s"); break;
        case STURDY_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case STURDY_Q: SEND_STRING("q"); break;
        case STURDY_X: SEND_STRING("x"); break;
        case STURDY_M: SEND_STRING("ent"); break;
        case STURDY_C: SEND_STRING("c"); break;
        case STURDY_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case STURDY_F: SEND_STRING("or"); break;
        case STURDY_O:  SEND_STRING("a"); break;
        case STURDY_U: SEND_STRING("u"); break;
        case STURDY_J: SEND_STRING("j"); break;
        case STURDY_QUOTE: SEND_STRING("ve"); break;
        /* Middle row right */
        case STURDY_Y: SEND_STRING("ou"); break;
        case STURDY_H: SEND_STRING("ow"); break;
        case STURDY_A: SEND_STRING("o"); break;
        case STURDY_E: SEND_STRING("u"); break;
        case STURDY_I: SEND_STRING("ng"); break;
        /* Bottom row right */
        case STURDY_K: SEND_STRING("k"); break;
        case STURDY_P:  SEND_STRING("h"); break;
        case STURDY_DOT: break;
        case STURDY_COMM: break;
        case STURDY_SLSH: break;
    }
    return false;
}
