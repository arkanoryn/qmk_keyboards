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
    case GRAPHITE_EAT: return EAT;
    case GRAPHITE_LEARN: return LEARN;
    case GRAPHITE_DEVELOPER: return DEVELOPER;
    case GRAPHITE_HI: return HI;
    case GRAPHITE_YEAH: return YEAH;
    case GRAPHITE_THANK_YOU: return THANK_YOU;
    case GRAPHITE_WTF: return WTF;
    case GRAPHITE_I_VE: return I_VE;
    case GRAPHITE_I_M: return I_M;
    case GRAPHITE_GOD: return GOD;
    case GRAPHITE_PROJECT: return PROJECT;
    case GRAPHITE_PRODUCT_COMBO: return PRODUCT_COMBO;
    case GRAPHITE_LOST: return LOST;
    case GRAPHITE_LOOSE: return LOOSE;
    case GRAPHITE_ASK: return ASK;
    case GRAPHITE_BACK: return BACK;
    case GRAPHITE_BE: return BE;
    case GRAPHITE_BECOME: return BECOME;
    case GRAPHITE_BEGIN: return BEGIN;
    case GRAPHITE_BUT: return BUT;
    case GRAPHITE_CALL: return CALL;
    case GRAPHITE_CAN: return CAN;
    case GRAPHITE_CANNOT: return CANNOT;
    case GRAPHITE_CHANGE: return CHANGE;
    case GRAPHITE_CHILD: return CHILD;
    case GRAPHITE_COME: return COME;
    case GRAPHITE_CONSIDER: return CONSIDER;
    case GRAPHITE_COULD: return COULD;
    case GRAPHITE_COURSE: return COURSE;
    case GRAPHITE_DAY: return DAY;
    case GRAPHITE_DEVELOP: return DEVELOP;
    case GRAPHITE_DO: return DO;
    case GRAPHITE_EARLY: return EARLY;
    case GRAPHITE_END: return END;
    case GRAPHITE_EYE: return EYE;
    case GRAPHITE_FACE: return FACE;
    case GRAPHITE_FACT: return FACT;
    case GRAPHITE_FEEL: return FEEL;
    case GRAPHITE_FEW: return FEW;
    case GRAPHITE_FIND: return FIND;
    case GRAPHITE_FOLLOW: return FOLLOW;
    case GRAPHITE_FORM: return FORM;
    case GRAPHITE_GENERAL: return GENERAL;
    case GRAPHITE_GET: return GET;
    case GRAPHITE_GIVE: return GIVE;
    case GRAPHITE_GO: return GO;
    case GRAPHITE_GOOD: return GOOD;
    case GRAPHITE_GOVERN: return GOVERN;
    case GRAPHITE_GREAT: return GREAT;
    case GRAPHITE_GROUP: return GROUP;
    case GRAPHITE_HAND: return HAND;
    case GRAPHITE_HAVE: return HAVE;
    case GRAPHITE_HE: return HE;
    case GRAPHITE_HEAD: return HEAD;
    case GRAPHITE_HELP: return HELP;
    case GRAPHITE_HIGH: return HIGH;
    case GRAPHITE_HOLD: return HOLD;
    case GRAPHITE_HOME: return HOME;
    case GRAPHITE_HOUSE: return HOUSE;
    case GRAPHITE_I_: return I_;
    case GRAPHITE_INCREASE: return INCREASE;
    case GRAPHITE_INTEREST: return INTEREST;
    case GRAPHITE_IT: return IT;
    case GRAPHITE_KEEP: return KEEP;
    case GRAPHITE_KNOW: return KNOW;
    case GRAPHITE_KNOWLEDGE: return KNOWLEDGE;
    case GRAPHITE_LARGE: return LARGE;
    case GRAPHITE_LATE: return LATE;
    case GRAPHITE_LEAD: return LEAD;
    case GRAPHITE_LEAVE: return LEAVE;
    case GRAPHITE_LIFE: return LIFE;
    case GRAPHITE_LIKE: return LIKE;
    case GRAPHITE_LINE: return LINE;
    case GRAPHITE_LITTLE: return LITTLE;
    case GRAPHITE_LONG: return LONG;
    case GRAPHITE_LOOK: return LOOK;
    case GRAPHITE_MAKE: return MAKE;
    case GRAPHITE_MAN: return MAN;
    case GRAPHITE_MANY: return MANY;
    case GRAPHITE_MAY: return MAY;
    case GRAPHITE_MEAN: return MEAN;
    case GRAPHITE_MIGHT: return MIGHT;
    case GRAPHITE_MORE: return MORE;
    case GRAPHITE_MOST: return MOST;
    case GRAPHITE_MOVE: return MOVE;
    case GRAPHITE_NATION: return NATION;
    case GRAPHITE_NEED: return NEED;
    case GRAPHITE_NEW: return NEW;
    case GRAPHITE_NUMBER: return NUMBER;
    case GRAPHITE_OLD: return OLD;
    case GRAPHITE_ONE: return ONE;
    case GRAPHITE_OPEN: return OPEN;
    case GRAPHITE_OR: return OR;
    case GRAPHITE_ORDER: return ORDER;
    case GRAPHITE_OTHER: return OTHER;
    case GRAPHITE_OUT: return OUT;
    case GRAPHITE_OWN: return OWN;
    case GRAPHITE_PART: return PART;
    case GRAPHITE_PEOPLE: return PEOPLE;
    case GRAPHITE_PERSON: return PERSON;
    case GRAPHITE_PLACE: return PLACE;
    case GRAPHITE_PLAN: return PLAN;
    case GRAPHITE_PLAY: return PLAY;
    case GRAPHITE_POINT: return POINT;
    case GRAPHITE_PRESENT: return PRESENT;
    case GRAPHITE_PROBLEM: return PROBLEM;
    case GRAPHITE_PROGRAM: return PROGRAM;
    case GRAPHITE_RIGHT: return RIGHT;
    case GRAPHITE_RUN: return RUN;
    case GRAPHITE_SAY: return SAY;
    case GRAPHITE_SCHOOL: return SCHOOL;
    case GRAPHITE_SEE: return SEE;
    case GRAPHITE_SEEM: return SEEM;
    case GRAPHITE_SET: return SET;
    case GRAPHITE_SHE: return SHE;
    case GRAPHITE_SHOW: return SHOW;
    case GRAPHITE_SMALL: return SMALL;
    case GRAPHITE_SOME: return SOME;
    case GRAPHITE_STAND: return STAND;
    case GRAPHITE_STATE: return STATE;
    case GRAPHITE_SYSTEM: return SYSTEM;
    case GRAPHITE_TELL: return TELL;
    case GRAPHITE_THAT: return THAT;
    case GRAPHITE_THEIR: return THEIR;
    case GRAPHITE_THESE: return THESE;
    case GRAPHITE_THEY: return THEY;
    case GRAPHITE_THING: return THING;
    case GRAPHITE_THINK: return THINK;
    case GRAPHITE_THIS: return THIS;
    case GRAPHITE_THOSE: return THOSE;
    case GRAPHITE_TURN: return TURN;
    case GRAPHITE_USE: return USE;
    case GRAPHITE_WANT: return WANT;
    case GRAPHITE_WAY: return WAY;
    case GRAPHITE_WE: return WE;
    case GRAPHITE_WELL: return WELL;
    case GRAPHITE_WHO: return WHO;
    case GRAPHITE_WILL: return WILL;
    case GRAPHITE_WORD: return WORD;
    case GRAPHITE_WORK: return WORK;
    case GRAPHITE_WORLD: return WORLD;
    case GRAPHITE_WOULD: return WOULD;
    case GRAPHITE_WRITE: return WRITE;
    case GRAPHITE_YEAR: return YEAR;
    case GRAPHITE_YOU: return YOU;
  }
  return _LAST_CYCLING_COMBO;
};
