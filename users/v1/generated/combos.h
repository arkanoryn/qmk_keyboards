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

#pragma once

#include QMK_KEYBOARD_H
#include "combos.h"

enum combos {
  GRAPHITE_ARE = 0,
  GRAPHITE_EAT,
  GRAPHITE_LEARN,
  GRAPHITE_DEVELOPER,
  GRAPHITE_ING,
  GRAPHITE_NT,
  GRAPHITE_QUOTE_VE,
  GRAPHITE_QUOTE_RE,
  GRAPHITE_QUOTE_S,
  GRAPHITE_QUOTE_D,
  GRAPHITE_QUOTE_LL,
  GRAPHITE_HI,
  GRAPHITE_YEAH,
  GRAPHITE_THANK_YOU,
  GRAPHITE_WTF,
  GRAPHITE_I_VE,
  GRAPHITE_I_M,
  GRAPHITE_I_LL,
  GRAPHITE_GOD,
  GRAPHITE_PROJECT,
  GRAPHITE_PRODUCT_COMBO,
  GRAPHITE_LOST,
  GRAPHITE_LOOSE,
  GRAPHITE_DEL_WORD,
  GRAPHITE_CONFIG_LAYER,
  GRAPHITE_TAB_C,
  GRAPHITE_EXLM,
  GRAPHITE_QUES,
  GRAPHITE_SFT_ENT,
  GRAPHITE_C_ENT,
  GRAPHITE_A__,
  GRAPHITE_ABOUT,
  GRAPHITE_AFTER,
  GRAPHITE_AGAIN,
  GRAPHITE_AGAINST,
  GRAPHITE_ALL,
  GRAPHITE_ALSO,
  GRAPHITE_AND,
  GRAPHITE_ANOTHER,
  GRAPHITE_ANY,
  GRAPHITE_AROUND,
  GRAPHITE_AS,
  GRAPHITE_ASK,
  GRAPHITE_AT,
  GRAPHITE_BACK,
  GRAPHITE_BE,
  GRAPHITE_BECAUSE,
  GRAPHITE_BECOME,
  GRAPHITE_BEFORE,
  GRAPHITE_BEGIN,
  GRAPHITE_BETWEEN,
  GRAPHITE_BIRTHDAY,
  GRAPHITE_BOTH,
  GRAPHITE_BUT,
  GRAPHITE_BY,
  GRAPHITE_CALL,
  GRAPHITE_CAN,
  GRAPHITE_CANNOT,
  GRAPHITE_CHANGE,
  GRAPHITE_CHILD,
  GRAPHITE_COME,
  GRAPHITE_CONSIDER,
  GRAPHITE_COULD,
  GRAPHITE_COURSE,
  GRAPHITE_DAY,
  GRAPHITE_DEVELOP,
  GRAPHITE_DO,
  GRAPHITE_DOWN,
  GRAPHITE_DURING,
  GRAPHITE_EACH,
  GRAPHITE_EARLY,
  GRAPHITE_END,
  GRAPHITE_EVEN,
  GRAPHITE_EYE,
  GRAPHITE_FACE,
  GRAPHITE_FACT,
  GRAPHITE_FEEL,
  GRAPHITE_FEW,
  GRAPHITE_FIND,
  GRAPHITE_FIRST,
  GRAPHITE_FOLLOW,
  GRAPHITE_FOR,
  GRAPHITE_FORM,
  GRAPHITE_FROM,
  GRAPHITE_GENERAL,
  GRAPHITE_GET,
  GRAPHITE_GIVE,
  GRAPHITE_GO,
  GRAPHITE_GOOD,
  GRAPHITE_GOVERN,
  GRAPHITE_GREAT,
  GRAPHITE_GROUP,
  GRAPHITE_HAND,
  GRAPHITE_HAVE,
  GRAPHITE_HE,
  GRAPHITE_HEAD,
  GRAPHITE_HELP,
  GRAPHITE_HERE,
  GRAPHITE_HIGH,
  GRAPHITE_HOLD,
  GRAPHITE_HOME,
  GRAPHITE_HOUSE,
  GRAPHITE_HOW,
  GRAPHITE_HOWEVER,
  GRAPHITE_I_,
  GRAPHITE_IF,
  GRAPHITE_IN,
  GRAPHITE_INCREASE,
  GRAPHITE_INTEREST,
  GRAPHITE_INTO,
  GRAPHITE_IT,
  GRAPHITE_JUST,
  GRAPHITE_KEEP,
  GRAPHITE_KNOW,
  GRAPHITE_KNOWLEDGE,
  GRAPHITE_LARGE,
  GRAPHITE_LAST,
  GRAPHITE_LATE,
  GRAPHITE_LEAD,
  GRAPHITE_LEAVE,
  GRAPHITE_LIFE,
  GRAPHITE_LIKE,
  GRAPHITE_LINE,
  GRAPHITE_LITTLE,
  GRAPHITE_LONG,
  GRAPHITE_LOOK,
  GRAPHITE_MAKE,
  GRAPHITE_MAN,
  GRAPHITE_MANY,
  GRAPHITE_MAY,
  GRAPHITE_MEAN,
  GRAPHITE_MIGHT,
  GRAPHITE_MORE,
  GRAPHITE_MOST,
  GRAPHITE_MOVE,
  GRAPHITE_MUST,
  GRAPHITE_NATION,
  GRAPHITE_NEED,
  GRAPHITE_NEVER,
  GRAPHITE_NEW,
  GRAPHITE_NO,
  GRAPHITE_NOT,
  GRAPHITE_NOW,
  GRAPHITE_NUMBER,
  GRAPHITE_OF,
  GRAPHITE_OFF,
  GRAPHITE_OLD,
  GRAPHITE_ON,
  GRAPHITE_ONE,
  GRAPHITE_ONLY,
  GRAPHITE_OPEN,
  GRAPHITE_OR,
  GRAPHITE_ORDER,
  GRAPHITE_OTHER,
  GRAPHITE_OUT,
  GRAPHITE_OVER,
  GRAPHITE_OWN,
  GRAPHITE_PART,
  GRAPHITE_PEOPLE,
  GRAPHITE_PERSON,
  GRAPHITE_PLACE,
  GRAPHITE_PLAN,
  GRAPHITE_PLAY,
  GRAPHITE_POINT,
  GRAPHITE_POSSIBLE,
  GRAPHITE_PRESENT,
  GRAPHITE_PROBLEM,
  GRAPHITE_PROGRAM,
  GRAPHITE_PUBLIC,
  GRAPHITE_REAL,
  GRAPHITE_RIGHT,
  GRAPHITE_RUN,
  GRAPHITE_SAME,
  GRAPHITE_SAY,
  GRAPHITE_SCHOOL,
  GRAPHITE_SEE,
  GRAPHITE_SEEM,
  GRAPHITE_SET,
  GRAPHITE_SHE,
  GRAPHITE_SHOULD,
  GRAPHITE_SHOW,
  GRAPHITE_SINCE,
  GRAPHITE_SMALL,
  GRAPHITE_SO,
  GRAPHITE_SOME,
  GRAPHITE_STAND,
  GRAPHITE_STATE,
  GRAPHITE_STILL,
  GRAPHITE_SUCH,
  GRAPHITE_SYSTEM,
  GRAPHITE_TAKE,
  GRAPHITE_TELL,
  GRAPHITE_THAN,
  GRAPHITE_THAT,
  GRAPHITE_THE,
  GRAPHITE_THEIR,
  GRAPHITE_THEM,
  GRAPHITE_THEN,
  GRAPHITE_THERE,
  GRAPHITE_THESE,
  GRAPHITE_THEY,
  GRAPHITE_THING,
  GRAPHITE_THINK,
  GRAPHITE_THIS,
  GRAPHITE_THOSE,
  GRAPHITE_TIME,
  GRAPHITE_TO,
  GRAPHITE_TOO,
  GRAPHITE_TURN,
  GRAPHITE_UNDER,
  GRAPHITE_UP,
  GRAPHITE_USE,
  GRAPHITE_VERY,
  GRAPHITE_WANT,
  GRAPHITE_WAY,
  GRAPHITE_WE,
  GRAPHITE_WELL,
  GRAPHITE_WHAT,
  GRAPHITE_WHEN,
  GRAPHITE_WHERE,
  GRAPHITE_WHICH,
  GRAPHITE_WHILE,
  GRAPHITE_WHO,
  GRAPHITE_WHY,
  GRAPHITE_WILL,
  GRAPHITE_WITH,
  GRAPHITE_WITHOUT,
  GRAPHITE_WORD,
  GRAPHITE_WORK,
  GRAPHITE_WORLD,
  GRAPHITE_WOULD,
  GRAPHITE_WRITE,
  GRAPHITE_YEAR,
  GRAPHITE_YOU
};

const char* get_combos_cmds(uint16_t combo_index);
