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

#include "sentence_case.h"

char sentence_case_press_user(uint16_t keycode,
                              keyrecord_t* record,
                              uint8_t mods) {
  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      case KC_A ... KC_Z:
        return 'a';  // Letter key.

      case KC_DOT:  // . is punctuation, Shift . is a symbol (>)
        return !shifted ? '.' : '#';
      case KC_1:
      case KC_SLSH:
        return shifted ? '.' : '#';
      case KC_EXLM:
      case KC_QUES:
        return '.';
      case KC_2 ... KC_0:  // 2 3 4 5 6 7 8 9 0
      case KC_AT ... KC_RPRN:  // @ # $ % ^ & * ( )
      case KC_MINS ... KC_SCLN:  // - = [ ] backslash ;
      case KC_UNDS ... KC_COLN:  // _ + { } | :
      case KC_GRV:
      case KC_COMM:
        return '#';  // Symbol key.

      case KC_SPC:
        return ' ';  // Space key.

      case KC_QUOT:
        return '\'';  // Quote key.
    }
  }

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
  return '\0';
}
