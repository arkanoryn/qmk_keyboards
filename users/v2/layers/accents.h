/* Copyright 2025-2026 Ark'Anoryn (@arkanoryn)
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

#pragma once

#include QMK_KEYBOARD_H

/* Left side: utility keys + punctuation */
#define __________ACCENTS_LEFT_ROW_1________ CW_TOGG, KC_ASTR, KC_AMPR, KC_PERCENT, CKC(CMD_REDO)
#define __________ACCENTS_LEFT_ROW_2________ KC_TAB,  KC_DQUO, KC_EXLM, KC_QUES,    CKC(CMD_UNDO)
#define __________ACCENTS_LEFT_ROW_3________ __X__,   __X__,   __X__,   __X__,       __X__

/* Right side: French accented characters */
#define _________ACCENTS_RIGHT_ROW_1________ __X__, CKC(E_CIRC),    CKC(U_GRAVE), CKC(I_CIRC),  CKC(I_TREMA)
#define _________ACCENTS_RIGHT_ROW_2________ __X__, CKC(E_AIGU),    CKC(E_GRAVE), CKC(A_GRAVE), CKC(O_CIRC)
#define _________ACCENTS_RIGHT_ROW_3________ __X__, CKC(C_CEDILLE), CKC(U_CIRC),  CKC(A_CIRC),  __X__

#define ___ACCENTS_ROW_1___ __________ACCENTS_LEFT_ROW_1________, _________ACCENTS_RIGHT_ROW_1________
#define ___ACCENTS_ROW_2___ __________ACCENTS_LEFT_ROW_2________, _________ACCENTS_RIGHT_ROW_2________
#define ___ACCENTS_ROW_3___ __________ACCENTS_LEFT_ROW_3________, _________ACCENTS_RIGHT_ROW_3________

/* Thumb cluster for accents layer (Cosmos Dactyl: 6L + 4R) */
#define ___ACCENTS_THUMBS__________ __X__, KC_LSFT, __X__, __X__, QK_LLCK, __X__, __X__, __X__, __X__, __X__
