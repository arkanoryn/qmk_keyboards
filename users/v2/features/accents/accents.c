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
#include <os_detection.h>
#include "farkann_v2.h"
#include "accents.h"
#include "features/actions/actions.h"

static void process_accent(uint16_t accent_str, uint8_t letter_code) {
    const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    if (mods & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        tap_code16(accent_str);
        add_mods(MOD_MASK_SHIFT);
    } else {
        tap_code16(accent_str);
    }
    tap_code16(letter_code);
}

bool process_accents(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) { return true; }

    switch (keycode) {
        case CKC(E_CIRC):    process_accent(CIRCONFLEXE, KC_E); return false;
        case CKC(E_AIGU):    process_accent(AIGU, KC_E);        return false;
        case CKC(U_GRAVE):   process_accent(GRAVE, KC_U);       return false;
        case CKC(E_GRAVE):   process_accent(GRAVE, KC_E);       return false;
        case CKC(U_CIRC):    process_accent(CIRCONFLEXE, KC_U); return false;
        case CKC(I_CIRC):    process_accent(CIRCONFLEXE, KC_I); return false;
        case CKC(A_GRAVE):   process_accent(GRAVE, KC_A);       return false;
        case CKC(A_CIRC):    process_accent(CIRCONFLEXE, KC_A); return false;
        case CKC(I_TREMA):   process_accent(TREMA, KC_I);       return false;
        case CKC(O_CIRC):    process_accent(CIRCONFLEXE, KC_O); return false;
        case CKC(C_CEDILLE):
            if (detected_host_os() == OS_MACOS) {
                tap_code16(A(KC_C));
            } else {
                process_accent(WIN_CEDILLE, KC_C);
            }
            return false;
        case CKC(EURO):
            if (detected_host_os() == OS_MACOS) {
                send_string(MAC_EUR);
            } else {
                send_string(WIN_EUR);
            }
            return false;
        default:
            return true;
    }
}
