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

#include "farkann_v2.h"
#include "process_record.h"
#include "features/repeat/repeat.h"
#include "features/actions/actions.h"
#include "features/accents/accents.h"

#ifdef CHORD_TEACHER_ENABLE
#    include "features/chord_teacher/chord_teacher.h"
#endif

bool process_record_v2(uint16_t keycode, keyrecord_t *record) {
    /* Chain feature processors. Order matters.
    ** Each returns false to stop processing, true to continue.
    */

#ifdef CHORD_TEACHER_ENABLE
    if (!process_chord_teacher(keycode, record)) { return false; }
#endif

    if (!process_repeat_keys(keycode, record)) { return false; }
    if (!process_actions(keycode, record)) { return false; }
    if (!process_accents(keycode, record)) { return false; }

    /* Future features will be added here:
    ** if (!process_symbols(keycode, record)) { return false; }
    */

    return true;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case SFT_MAGIC:
        case MAGIC:
        case ALT_ARCANE:
        case ARCANE:
            return false; /* Don't track these as "last key" */
    }
    return true;
}
