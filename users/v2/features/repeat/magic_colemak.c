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

/* Get MAGIC key for Colemak layout */
bool process_magic_key_colemak(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case COLEMAK_B: SEND_STRING("efore"); break;
        case COLEMAK_L: SEND_STRING("l"); break;
        case COLEMAK_D: SEND_STRING("evelop"); break;
        case COLEMAK_W: SEND_STRING("hat"); break;
        case COLEMAK_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case COLEMAK_N: SEND_STRING("n"); break;
        case COLEMAK_R: SEND_STRING("l"); break;
        case COLEMAK_T: SEND_STRING("ment"); break;
        case COLEMAK_S: SEND_STRING("s"); break;
        case COLEMAK_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case COLEMAK_Q: SEND_STRING("q"); break;
        case COLEMAK_X: SEND_STRING("x"); break;
        case COLEMAK_M: SEND_STRING("ent"); break;
        case COLEMAK_C: SEND_STRING("c"); break;
        case COLEMAK_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case COLEMAK_F: SEND_STRING("f"); break;
        case COLEMAK_O:  SEND_STRING("a"); break;
        case COLEMAK_U: SEND_STRING("u"); break;
        case COLEMAK_J: SEND_STRING("j"); break;
        /* Middle row right */
        case COLEMAK_Y: SEND_STRING("ou"); break;
        case COLEMAK_H: SEND_STRING("owever"); break;
        case COLEMAK_A: SEND_STRING("o"); break;
        case COLEMAK_E: SEND_STRING("u"); break;
        case COLEMAK_I: SEND_STRING("on"); break;
        /* Bottom row right */
        case COLEMAK_K: SEND_STRING("k"); break;
        case COLEMAK_P:  SEND_STRING("p"); break;
        case COLEMAK_DOT: SEND_STRING("com"); break;
        case COLEMAK_COMM: SEND_STRING(" but"); break;
        case COLEMAK_SLSH: break;
    }
    return false;
}

/* Get ARCANE key for Colemak layout */
bool process_arcane_key_colemak(uint16_t keycode, uint8_t mods) {
    switch (get_last_keycode()) {
        /* Left hand keys */
        case COLEMAK_B: SEND_STRING("ecause"); break;
        case COLEMAK_L: SEND_STRING("l"); break;
        case COLEMAK_D: SEND_STRING("evelop"); break;
        case COLEMAK_W: SEND_STRING("hat"); break;
        case COLEMAK_Z: SEND_STRING("z"); break;
        /* Middle row left */
        case COLEMAK_N: SEND_STRING("n"); break;
        case COLEMAK_R: SEND_STRING("l"); break;
        case COLEMAK_T: SEND_STRING("ment"); break;
        case COLEMAK_S: SEND_STRING("s"); break;
        case COLEMAK_G: SEND_STRING("g"); break;
        /* Bottom row left */
        case COLEMAK_Q: SEND_STRING("q"); break;
        case COLEMAK_X: SEND_STRING("x"); break;
        case COLEMAK_M: SEND_STRING("ent"); break;
        case COLEMAK_C: SEND_STRING("c"); break;
        case COLEMAK_V: SEND_STRING("v"); break;

        /* Right hand keys */
        case COLEMAK_F: SEND_STRING("or"); break;
        case COLEMAK_O:  SEND_STRING("a"); break;
        case COLEMAK_U: SEND_STRING("u"); break;
        case COLEMAK_J: SEND_STRING("j"); break;
        /* Middle row right */
        case COLEMAK_Y: SEND_STRING("ou"); break;
        case COLEMAK_H: SEND_STRING("ow"); break;
        case COLEMAK_A: SEND_STRING("o"); break;
        case COLEMAK_E: SEND_STRING("u"); break;
        case COLEMAK_I: SEND_STRING("ng"); break;
        /* Bottom row right */
        case COLEMAK_K: SEND_STRING("k"); break;
        case COLEMAK_P:  SEND_STRING("h"); break;
        case COLEMAK_DOT: break;
        case COLEMAK_COMM: break;
        case COLEMAK_SLSH: break;
    }
    return false;
}
