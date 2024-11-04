/*
**  /!\ This file is generated with the script `scripts/main.py`
**  Do NOT manually modify or create files in the `generated/` folder.
**  Prefer re-running the script: `python main.py`
**  ex:
**
**       $> python main.py
**
**  Copyright 2024 Pierre-Nicolas "Ark'Anoryn" Sormani <arkanoryn@gmail.com>
**  SPDX-License-Identifier: GPL-2.0-or-later
**
*/

#include "combos.h"
#include "cycles.h"

cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index) {
  switch(combo_index) {
    case GRAPHITE_BACK: return BACK;
    case GRAPHITE_BE: return BE;
    case GRAPHITE_BUT: return BUT;
    case GRAPHITE_CAN: return CAN;
    case GRAPHITE_CANNOT: return CANNOT;
    case GRAPHITE_COME: return COME;
    case GRAPHITE_COULD: return COULD;
    case GRAPHITE_DAY: return DAY;
    case GRAPHITE_DO: return DO;
    case GRAPHITE_FIND: return FIND;
    case GRAPHITE_GET: return GET;
    case GRAPHITE_GIVE: return GIVE;
    case GRAPHITE_GO: return GO;
    case GRAPHITE_GREAT: return GREAT;
    case GRAPHITE_HAVE: return HAVE;
    case GRAPHITE_HE: return HE;
    case GRAPHITE_I_: return I_;
    case GRAPHITE_IT: return IT;
    case GRAPHITE_KNOW: return KNOW;
    case GRAPHITE_KNOWLEDGE: return KNOWLEDGE;
    case GRAPHITE_LIKE: return LIKE;
    case GRAPHITE_LONG: return LONG;
    case GRAPHITE_LOOK: return LOOK;
    case GRAPHITE_MAKE: return MAKE;
    case GRAPHITE_MAN: return MAN;
    case GRAPHITE_MANY: return MANY;
    case GRAPHITE_MORE: return MORE;
    case GRAPHITE_MOST: return MOST;
    case GRAPHITE_NEW: return NEW;
    case GRAPHITE_ONE: return ONE;
    case GRAPHITE_OR: return OR;
    case GRAPHITE_OTHER: return OTHER;
    case GRAPHITE_OUT: return OUT;
    case GRAPHITE_SAY: return SAY;
    case GRAPHITE_SEE: return SEE;
    case GRAPHITE_SHE: return SHE;
    case GRAPHITE_SOME: return SOME;
    case GRAPHITE_STATE: return STATE;
    case GRAPHITE_THAT: return THAT;
    case GRAPHITE_THEIR: return THEIR;
    case GRAPHITE_THESE: return THESE;
    case GRAPHITE_THEY: return THEY;
    case GRAPHITE_THINK: return THINK;
    case GRAPHITE_THIS: return THIS;
    case GRAPHITE_THOSE: return THOSE;
    case GRAPHITE_USE: return USE;
    case GRAPHITE_WAY: return WAY;
    case GRAPHITE_WE: return WE;
    case GRAPHITE_WHO: return WHO;
    case GRAPHITE_WILL: return WILL;
    case GRAPHITE_WORK: return WORK;
    case GRAPHITE_WOULD: return WOULD;
    case GRAPHITE_YEAR: return YEAR;
    case GRAPHITE_YOU: return YOU;
  }
  return _LAST_CYCLING_COMBO;
};
