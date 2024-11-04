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
#include "quantum.h"
#include "combos.h"

enum combos {
  GRAPHITE_DEL_WORD = 0,
  GRAPHITE_ING,
  GRAPHITE_NT,
  GRAPHITE_QUOTE_VE,
  GRAPHITE_QUOTE_RE,
  GRAPHITE_QUOTE_S,
  GRAPHITE_QUOTE_D,
  GRAPHITE_QUOTE_LL,
  GRAPHITE_A_,
  GRAPHITE_A__,
  GRAPHITE_ABOUT,
  GRAPHITE_AFTER,
  GRAPHITE_ALL,
  GRAPHITE_ALSO,
  GRAPHITE_AND,
  GRAPHITE_ANY,
  GRAPHITE_AS,
  GRAPHITE_AT,
  GRAPHITE_BACK,
  GRAPHITE_BE,
  GRAPHITE_BECAUSE,
  GRAPHITE_BEFORE,
  GRAPHITE_BIRTHDAY,
  GRAPHITE_BUT,
  GRAPHITE_BY,
  GRAPHITE_CAN,
  GRAPHITE_CANNOT,
  GRAPHITE_COME,
  GRAPHITE_COULD,
  GRAPHITE_DAY,
  GRAPHITE_DO,
  GRAPHITE_EVEN,
  GRAPHITE_FIND,
  GRAPHITE_FIRST,
  GRAPHITE_FOR,
  GRAPHITE_FROM,
  GRAPHITE_GET,
  GRAPHITE_GIVE,
  GRAPHITE_GO,
  GRAPHITE_GREAT,
  GRAPHITE_HAVE,
  GRAPHITE_HE,
  GRAPHITE_I_,
  GRAPHITE_IF,
  GRAPHITE_IN,
  GRAPHITE_INTO,
  GRAPHITE_IT,
  GRAPHITE_KNOW,
  GRAPHITE_KNOWLEDGE,
  GRAPHITE_LIKE,
  GRAPHITE_LONG,
  GRAPHITE_LOOK,
  GRAPHITE_MAKE,
  GRAPHITE_MAN,
  GRAPHITE_MANY,
  GRAPHITE_MAY,
  GRAPHITE_MORE,
  GRAPHITE_MOST,
  GRAPHITE_MUST,
  GRAPHITE_NEW,
  GRAPHITE_NO,
  GRAPHITE_NOT,
  GRAPHITE_NOW,
  GRAPHITE_OF,
  GRAPHITE_ON,
  GRAPHITE_ONE,
  GRAPHITE_ONLY,
  GRAPHITE_OR,
  GRAPHITE_OTHER,
  GRAPHITE_OUT,
  GRAPHITE_OVER,
  GRAPHITE_SAY,
  GRAPHITE_SEE,
  GRAPHITE_SHE,
  GRAPHITE_SO,
  GRAPHITE_SOME,
  GRAPHITE_STATE,
  GRAPHITE_SUCH,
  GRAPHITE_TAKE,
  GRAPHITE_THAN,
  GRAPHITE_THAT,
  GRAPHITE_THE,
  GRAPHITE_THEIR,
  GRAPHITE_THEM,
  GRAPHITE_THEN,
  GRAPHITE_THERE,
  GRAPHITE_THESE,
  GRAPHITE_THEY,
  GRAPHITE_THINK,
  GRAPHITE_THIS,
  GRAPHITE_THOSE,
  GRAPHITE_TIME,
  GRAPHITE_TO,
  GRAPHITE_UP,
  GRAPHITE_USE,
  GRAPHITE_WAY,
  GRAPHITE_WE,
  GRAPHITE_WHAT,
  GRAPHITE_WHEN,
  GRAPHITE_WHERE,
  GRAPHITE_WHICH,
  GRAPHITE_WHO,
  GRAPHITE_WHY,
  GRAPHITE_WILL,
  GRAPHITE_WITH,
  GRAPHITE_WORK,
  GRAPHITE_WOULD,
  GRAPHITE_YEAR,
  GRAPHITE_YOU
};

const char* get_combos_cmds(uint16_t combo_index);
