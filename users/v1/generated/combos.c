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

#include QMK_KEYBOARD_H
#include "combos.h"

const uint16_t PROGMEM GRAPHITE_DEL_WORD_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_BSPC, COMBO_END};
const uint16_t PROGMEM GRAPHITE_NT_COMBO[] = {GRAPHITE_N, GRAPHITE_QUOT, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_QUOTE_VE_COMBO[] = {GRAPHITE_QUOT, GRAPHITE_V, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_QUOTE_RE_COMBO[] = {GRAPHITE_QUOT, GRAPHITE_R, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_QUOTE_S_COMBO[] = {GRAPHITE_QUOT, GRAPHITE_S, GRAPHITE_MAGIC, COMBO_END};
const uint16_t PROGMEM GRAPHITE_QUOTE_D_COMBO[] = {GRAPHITE_QUOT, GRAPHITE_D, GRAPHITE_MAGIC, COMBO_END};
const uint16_t PROGMEM GRAPHITE_QUOTE_LL_COMBO[] = {GRAPHITE_QUOT, GRAPHITE_L, GRAPHITE_MAGIC, COMBO_END};
const uint16_t PROGMEM GRAPHITE_A__COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_A___COMBO[] = {GRAPHITE_BSPC, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ABOUT_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_U, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_AFTER_COMBO[] = {GRAPHITE_F, GRAPHITE_T, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ALL_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_A, GRAPHITE_L, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ALSO_COMBO[] = {GRAPHITE_A, GRAPHITE_L, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_AND_COMBO[] = {GRAPHITE_A, GRAPHITE_N, GRAPHITE_D, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ANY_COMBO[] = {GRAPHITE_A, GRAPHITE_N, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_AS_COMBO[] = {GRAPHITE_A, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_AT_COMBO[] = {GRAPHITE_A, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BACK_COMBO[] = {GRAPHITE_B, GRAPHITE_C, GRAPHITE_K, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BE_COMBO[] = {GRAPHITE_B, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BECAUSE_COMBO[] = {GRAPHITE_B, GRAPHITE_C, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BEFORE_COMBO[] = {GRAPHITE_B, GRAPHITE_F, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BIRTHDAY_COMBO[] = {GRAPHITE_B, GRAPHITE_D, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BUT_COMBO[] = {GRAPHITE_B, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_BY_COMBO[] = {GRAPHITE_B, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_CAN_COMBO[] = {GRAPHITE_C, GRAPHITE_A, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_CANNOT_COMBO[] = {GRAPHITE_C, GRAPHITE_A, GRAPHITE_N, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_COME_COMBO[] = {GRAPHITE_C, GRAPHITE_M, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_COULD_COMBO[] = {GRAPHITE_C, GRAPHITE_O, GRAPHITE_U, COMBO_END};
const uint16_t PROGMEM GRAPHITE_DAY_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_D, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_DO_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_D, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_EVEN_COMBO[] = {GRAPHITE_E, GRAPHITE_V, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_FIND_COMBO[] = {GRAPHITE_F, GRAPHITE_N, GRAPHITE_D, COMBO_END};
const uint16_t PROGMEM GRAPHITE_FIRST_COMBO[] = {GRAPHITE_F, GRAPHITE_I, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_FOR_COMBO[] = {GRAPHITE_F, GRAPHITE_O, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_FROM_COMBO[] = {GRAPHITE_F, GRAPHITE_R, GRAPHITE_M, COMBO_END};
const uint16_t PROGMEM GRAPHITE_GET_COMBO[] = {GRAPHITE_G, GRAPHITE_E, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_GIVE_COMBO[] = {GRAPHITE_G, GRAPHITE_I, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_GO_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_G, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_GREAT_COMBO[] = {GRAPHITE_G, GRAPHITE_R, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_HAVE_COMBO[] = {GRAPHITE_H, GRAPHITE_V, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_HE_COMBO[] = {GRAPHITE_H, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_I__COMBO[] = {GRAPHITE_I, GRAPHITE_MAGIC, COMBO_END};
const uint16_t PROGMEM GRAPHITE_IF_COMBO[] = {GRAPHITE_I, GRAPHITE_F, COMBO_END};
const uint16_t PROGMEM GRAPHITE_IN_COMBO[] = {GRAPHITE_I, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_INTO_COMBO[] = {GRAPHITE_I, GRAPHITE_N, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_IT_COMBO[] = {GRAPHITE_I, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_KNOW_COMBO[] = {GRAPHITE_K, GRAPHITE_N, GRAPHITE_W, COMBO_END};
const uint16_t PROGMEM GRAPHITE_KNOWLEDGE_COMBO[] = {GRAPHITE_K, GRAPHITE_N, GRAPHITE_W, GRAPHITE_L, COMBO_END};
const uint16_t PROGMEM GRAPHITE_LIKE_COMBO[] = {GRAPHITE_L, GRAPHITE_K, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_LONG_COMBO[] = {GRAPHITE_L, GRAPHITE_N, GRAPHITE_G, COMBO_END};
const uint16_t PROGMEM GRAPHITE_LOOK_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_L, GRAPHITE_K, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MAKE_COMBO[] = {GRAPHITE_M, GRAPHITE_K, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MAN_COMBO[] = {GRAPHITE_M, GRAPHITE_A, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MANY_COMBO[] = {GRAPHITE_M, GRAPHITE_A, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MAY_COMBO[] = {GRAPHITE_M, GRAPHITE_A, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MORE_COMBO[] = {GRAPHITE_M, GRAPHITE_R, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MOST_COMBO[] = {GRAPHITE_M, GRAPHITE_O, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_MUST_COMBO[] = {GRAPHITE_U, GRAPHITE_S, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_NEW_COMBO[] = {GRAPHITE_N, GRAPHITE_E, GRAPHITE_W, COMBO_END};
const uint16_t PROGMEM GRAPHITE_NO_COMBO[] = {GRAPHITE_N, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_NOT_COMBO[] = {GRAPHITE_N, GRAPHITE_O, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_NOW_COMBO[] = {GRAPHITE_N, GRAPHITE_O, GRAPHITE_W, COMBO_END};
const uint16_t PROGMEM GRAPHITE_OF_COMBO[] = {GRAPHITE_O, GRAPHITE_F, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ON_COMBO[] = {GRAPHITE_O, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ONE_COMBO[] = {GRAPHITE_O, GRAPHITE_N, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_ONLY_COMBO[] = {GRAPHITE_O, GRAPHITE_L, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_OR_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_O, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_OTHER_COMBO[] = {GRAPHITE_O, GRAPHITE_T, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_OUT_COMBO[] = {GRAPHITE_O, GRAPHITE_U, GRAPHITE_T, COMBO_END};
const uint16_t PROGMEM GRAPHITE_OVER_COMBO[] = {GRAPHITE_O, GRAPHITE_V, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_SAY_COMBO[] = {GRAPHITE_S, GRAPHITE_A, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_SEE_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_S, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_SHE_COMBO[] = {GRAPHITE_S, GRAPHITE_H, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_SO_COMBO[] = {GRAPHITE_S, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_SOME_COMBO[] = {GRAPHITE_S, GRAPHITE_M, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_STATE_COMBO[] = {GRAPHITE_S, GRAPHITE_T, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_SUCH_COMBO[] = {GRAPHITE_S, GRAPHITE_U, GRAPHITE_H, COMBO_END};
const uint16_t PROGMEM GRAPHITE_TAKE_COMBO[] = {GRAPHITE_T, GRAPHITE_K, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THAN_COMBO[] = {GRAPHITE_T, GRAPHITE_H, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THAT_COMBO[] = {GRAPHITE_T, GRAPHITE_H, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THE_COMBO[] = {GRAPHITE_T, GRAPHITE_H, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THEIR_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_T, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THEM_COMBO[] = {GRAPHITE_T, GRAPHITE_H, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THEN_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_T, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THERE_COMBO[] = {GRAPHITE_T, GRAPHITE_H, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THESE_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_T, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THEY_COMBO[] = {GRAPHITE_T, GRAPHITE_E, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THINK_COMBO[] = {GRAPHITE_T, GRAPHITE_I, GRAPHITE_K, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THIS_COMBO[] = {GRAPHITE_T, GRAPHITE_H, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_THOSE_COMBO[] = {GRAPHITE_T, GRAPHITE_O, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_TIME_COMBO[] = {GRAPHITE_T, GRAPHITE_I, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_TO_COMBO[] = {GRAPHITE_T, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_UP_COMBO[] = {GRAPHITE_U, GRAPHITE_P, COMBO_END};
const uint16_t PROGMEM GRAPHITE_USE_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_U, GRAPHITE_S, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WAY_COMBO[] = {GRAPHITE_W, GRAPHITE_A, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WE_COMBO[] = {GRAPHITE_W, GRAPHITE_E, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WHAT_COMBO[] = {GRAPHITE_W, GRAPHITE_H, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WHEN_COMBO[] = {GRAPHITE_W, GRAPHITE_H, GRAPHITE_N, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WHERE_COMBO[] = {GRAPHITE_W, GRAPHITE_H, GRAPHITE_R, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WHICH_COMBO[] = {GRAPHITE_W, GRAPHITE_H, GRAPHITE_I, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WHO_COMBO[] = {GRAPHITE_W, GRAPHITE_H, GRAPHITE_O, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WHY_COMBO[] = {GRAPHITE_MAGIC, GRAPHITE_W, GRAPHITE_Y, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WILL_COMBO[] = {GRAPHITE_W, GRAPHITE_I, GRAPHITE_L, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WITH_COMBO[] = {GRAPHITE_W, GRAPHITE_T, GRAPHITE_H, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WORK_COMBO[] = {GRAPHITE_W, GRAPHITE_R, GRAPHITE_K, COMBO_END};
const uint16_t PROGMEM GRAPHITE_WOULD_COMBO[] = {GRAPHITE_W, GRAPHITE_L, GRAPHITE_D, COMBO_END};
const uint16_t PROGMEM GRAPHITE_YEAR_COMBO[] = {GRAPHITE_Y, GRAPHITE_E, GRAPHITE_A, COMBO_END};
const uint16_t PROGMEM GRAPHITE_YOU_COMBO[] = {GRAPHITE_Y, GRAPHITE_O, GRAPHITE_U, COMBO_END};

combo_t key_combos[] = {
  [GRAPHITE_DEL_WORD] = COMBO(GRAPHITE_DEL_WORD_COMBO, KC_NO),
  [GRAPHITE_NT] = COMBO_ACTION(GRAPHITE_NT_COMBO),
  [GRAPHITE_QUOTE_VE] = COMBO_ACTION(GRAPHITE_QUOTE_VE_COMBO),
  [GRAPHITE_QUOTE_RE] = COMBO_ACTION(GRAPHITE_QUOTE_RE_COMBO),
  [GRAPHITE_QUOTE_S] = COMBO_ACTION(GRAPHITE_QUOTE_S_COMBO),
  [GRAPHITE_QUOTE_D] = COMBO_ACTION(GRAPHITE_QUOTE_D_COMBO),
  [GRAPHITE_QUOTE_LL] = COMBO_ACTION(GRAPHITE_QUOTE_LL_COMBO),
  [GRAPHITE_A_] = COMBO_ACTION(GRAPHITE_A__COMBO),
  [GRAPHITE_A__] = COMBO_ACTION(GRAPHITE_A___COMBO),
  [GRAPHITE_ABOUT] = COMBO_ACTION(GRAPHITE_ABOUT_COMBO),
  [GRAPHITE_AFTER] = COMBO_ACTION(GRAPHITE_AFTER_COMBO),
  [GRAPHITE_ALL] = COMBO_ACTION(GRAPHITE_ALL_COMBO),
  [GRAPHITE_ALSO] = COMBO_ACTION(GRAPHITE_ALSO_COMBO),
  [GRAPHITE_AND] = COMBO_ACTION(GRAPHITE_AND_COMBO),
  [GRAPHITE_ANY] = COMBO_ACTION(GRAPHITE_ANY_COMBO),
  [GRAPHITE_AS] = COMBO_ACTION(GRAPHITE_AS_COMBO),
  [GRAPHITE_AT] = COMBO_ACTION(GRAPHITE_AT_COMBO),
  [GRAPHITE_BACK] = COMBO_ACTION(GRAPHITE_BACK_COMBO),
  [GRAPHITE_BE] = COMBO_ACTION(GRAPHITE_BE_COMBO),
  [GRAPHITE_BECAUSE] = COMBO_ACTION(GRAPHITE_BECAUSE_COMBO),
  [GRAPHITE_BEFORE] = COMBO_ACTION(GRAPHITE_BEFORE_COMBO),
  [GRAPHITE_BIRTHDAY] = COMBO_ACTION(GRAPHITE_BIRTHDAY_COMBO),
  [GRAPHITE_BUT] = COMBO_ACTION(GRAPHITE_BUT_COMBO),
  [GRAPHITE_BY] = COMBO_ACTION(GRAPHITE_BY_COMBO),
  [GRAPHITE_CAN] = COMBO_ACTION(GRAPHITE_CAN_COMBO),
  [GRAPHITE_CANNOT] = COMBO_ACTION(GRAPHITE_CANNOT_COMBO),
  [GRAPHITE_COME] = COMBO_ACTION(GRAPHITE_COME_COMBO),
  [GRAPHITE_COULD] = COMBO_ACTION(GRAPHITE_COULD_COMBO),
  [GRAPHITE_DAY] = COMBO_ACTION(GRAPHITE_DAY_COMBO),
  [GRAPHITE_DO] = COMBO_ACTION(GRAPHITE_DO_COMBO),
  [GRAPHITE_EVEN] = COMBO_ACTION(GRAPHITE_EVEN_COMBO),
  [GRAPHITE_FIND] = COMBO_ACTION(GRAPHITE_FIND_COMBO),
  [GRAPHITE_FIRST] = COMBO_ACTION(GRAPHITE_FIRST_COMBO),
  [GRAPHITE_FOR] = COMBO_ACTION(GRAPHITE_FOR_COMBO),
  [GRAPHITE_FROM] = COMBO_ACTION(GRAPHITE_FROM_COMBO),
  [GRAPHITE_GET] = COMBO_ACTION(GRAPHITE_GET_COMBO),
  [GRAPHITE_GIVE] = COMBO_ACTION(GRAPHITE_GIVE_COMBO),
  [GRAPHITE_GO] = COMBO_ACTION(GRAPHITE_GO_COMBO),
  [GRAPHITE_GREAT] = COMBO_ACTION(GRAPHITE_GREAT_COMBO),
  [GRAPHITE_HAVE] = COMBO_ACTION(GRAPHITE_HAVE_COMBO),
  [GRAPHITE_HE] = COMBO_ACTION(GRAPHITE_HE_COMBO),
  [GRAPHITE_I_] = COMBO_ACTION(GRAPHITE_I__COMBO),
  [GRAPHITE_IF] = COMBO_ACTION(GRAPHITE_IF_COMBO),
  [GRAPHITE_IN] = COMBO_ACTION(GRAPHITE_IN_COMBO),
  [GRAPHITE_INTO] = COMBO_ACTION(GRAPHITE_INTO_COMBO),
  [GRAPHITE_IT] = COMBO_ACTION(GRAPHITE_IT_COMBO),
  [GRAPHITE_KNOW] = COMBO_ACTION(GRAPHITE_KNOW_COMBO),
  [GRAPHITE_KNOWLEDGE] = COMBO_ACTION(GRAPHITE_KNOWLEDGE_COMBO),
  [GRAPHITE_LIKE] = COMBO_ACTION(GRAPHITE_LIKE_COMBO),
  [GRAPHITE_LONG] = COMBO_ACTION(GRAPHITE_LONG_COMBO),
  [GRAPHITE_LOOK] = COMBO_ACTION(GRAPHITE_LOOK_COMBO),
  [GRAPHITE_MAKE] = COMBO_ACTION(GRAPHITE_MAKE_COMBO),
  [GRAPHITE_MAN] = COMBO_ACTION(GRAPHITE_MAN_COMBO),
  [GRAPHITE_MANY] = COMBO_ACTION(GRAPHITE_MANY_COMBO),
  [GRAPHITE_MAY] = COMBO_ACTION(GRAPHITE_MAY_COMBO),
  [GRAPHITE_MORE] = COMBO_ACTION(GRAPHITE_MORE_COMBO),
  [GRAPHITE_MOST] = COMBO_ACTION(GRAPHITE_MOST_COMBO),
  [GRAPHITE_MUST] = COMBO_ACTION(GRAPHITE_MUST_COMBO),
  [GRAPHITE_NEW] = COMBO_ACTION(GRAPHITE_NEW_COMBO),
  [GRAPHITE_NO] = COMBO_ACTION(GRAPHITE_NO_COMBO),
  [GRAPHITE_NOT] = COMBO_ACTION(GRAPHITE_NOT_COMBO),
  [GRAPHITE_NOW] = COMBO_ACTION(GRAPHITE_NOW_COMBO),
  [GRAPHITE_OF] = COMBO_ACTION(GRAPHITE_OF_COMBO),
  [GRAPHITE_ON] = COMBO_ACTION(GRAPHITE_ON_COMBO),
  [GRAPHITE_ONE] = COMBO_ACTION(GRAPHITE_ONE_COMBO),
  [GRAPHITE_ONLY] = COMBO_ACTION(GRAPHITE_ONLY_COMBO),
  [GRAPHITE_OR] = COMBO_ACTION(GRAPHITE_OR_COMBO),
  [GRAPHITE_OTHER] = COMBO_ACTION(GRAPHITE_OTHER_COMBO),
  [GRAPHITE_OUT] = COMBO_ACTION(GRAPHITE_OUT_COMBO),
  [GRAPHITE_OVER] = COMBO_ACTION(GRAPHITE_OVER_COMBO),
  [GRAPHITE_SAY] = COMBO_ACTION(GRAPHITE_SAY_COMBO),
  [GRAPHITE_SEE] = COMBO_ACTION(GRAPHITE_SEE_COMBO),
  [GRAPHITE_SHE] = COMBO_ACTION(GRAPHITE_SHE_COMBO),
  [GRAPHITE_SO] = COMBO_ACTION(GRAPHITE_SO_COMBO),
  [GRAPHITE_SOME] = COMBO_ACTION(GRAPHITE_SOME_COMBO),
  [GRAPHITE_STATE] = COMBO_ACTION(GRAPHITE_STATE_COMBO),
  [GRAPHITE_SUCH] = COMBO_ACTION(GRAPHITE_SUCH_COMBO),
  [GRAPHITE_TAKE] = COMBO_ACTION(GRAPHITE_TAKE_COMBO),
  [GRAPHITE_THAN] = COMBO_ACTION(GRAPHITE_THAN_COMBO),
  [GRAPHITE_THAT] = COMBO_ACTION(GRAPHITE_THAT_COMBO),
  [GRAPHITE_THE] = COMBO_ACTION(GRAPHITE_THE_COMBO),
  [GRAPHITE_THEIR] = COMBO_ACTION(GRAPHITE_THEIR_COMBO),
  [GRAPHITE_THEM] = COMBO_ACTION(GRAPHITE_THEM_COMBO),
  [GRAPHITE_THEN] = COMBO_ACTION(GRAPHITE_THEN_COMBO),
  [GRAPHITE_THERE] = COMBO_ACTION(GRAPHITE_THERE_COMBO),
  [GRAPHITE_THESE] = COMBO_ACTION(GRAPHITE_THESE_COMBO),
  [GRAPHITE_THEY] = COMBO_ACTION(GRAPHITE_THEY_COMBO),
  [GRAPHITE_THINK] = COMBO_ACTION(GRAPHITE_THINK_COMBO),
  [GRAPHITE_THIS] = COMBO_ACTION(GRAPHITE_THIS_COMBO),
  [GRAPHITE_THOSE] = COMBO_ACTION(GRAPHITE_THOSE_COMBO),
  [GRAPHITE_TIME] = COMBO_ACTION(GRAPHITE_TIME_COMBO),
  [GRAPHITE_TO] = COMBO_ACTION(GRAPHITE_TO_COMBO),
  [GRAPHITE_UP] = COMBO_ACTION(GRAPHITE_UP_COMBO),
  [GRAPHITE_USE] = COMBO_ACTION(GRAPHITE_USE_COMBO),
  [GRAPHITE_WAY] = COMBO_ACTION(GRAPHITE_WAY_COMBO),
  [GRAPHITE_WE] = COMBO_ACTION(GRAPHITE_WE_COMBO),
  [GRAPHITE_WHAT] = COMBO_ACTION(GRAPHITE_WHAT_COMBO),
  [GRAPHITE_WHEN] = COMBO_ACTION(GRAPHITE_WHEN_COMBO),
  [GRAPHITE_WHERE] = COMBO_ACTION(GRAPHITE_WHERE_COMBO),
  [GRAPHITE_WHICH] = COMBO_ACTION(GRAPHITE_WHICH_COMBO),
  [GRAPHITE_WHO] = COMBO_ACTION(GRAPHITE_WHO_COMBO),
  [GRAPHITE_WHY] = COMBO_ACTION(GRAPHITE_WHY_COMBO),
  [GRAPHITE_WILL] = COMBO_ACTION(GRAPHITE_WILL_COMBO),
  [GRAPHITE_WITH] = COMBO_ACTION(GRAPHITE_WITH_COMBO),
  [GRAPHITE_WORK] = COMBO_ACTION(GRAPHITE_WORK_COMBO),
  [GRAPHITE_WOULD] = COMBO_ACTION(GRAPHITE_WOULD_COMBO),
  [GRAPHITE_YEAR] = COMBO_ACTION(GRAPHITE_YEAR_COMBO),
  [GRAPHITE_YOU] = COMBO_ACTION(GRAPHITE_YOU_COMBO)
};

static const char *combo_cmds[] = {
  [GRAPHITE_NT] = "\bn't",
  [GRAPHITE_QUOTE_VE] = "\b've",
  [GRAPHITE_QUOTE_RE] = "\b're",
  [GRAPHITE_QUOTE_S] = "\b's",
  [GRAPHITE_QUOTE_D] = "\b'd",
  [GRAPHITE_QUOTE_LL] = "\b'll",
  [GRAPHITE_A_] = "a",
  [GRAPHITE_A__] = "A",
  [GRAPHITE_ABOUT] = "about",
  [GRAPHITE_AFTER] = "after",
  [GRAPHITE_ALL] = "all",
  [GRAPHITE_ALSO] = "also",
  [GRAPHITE_AND] = "and",
  [GRAPHITE_ANY] = "any",
  [GRAPHITE_AS] = "as",
  [GRAPHITE_AT] = "at",
  [GRAPHITE_BACK] = "back",
  [GRAPHITE_BE] = "be",
  [GRAPHITE_BECAUSE] = "because",
  [GRAPHITE_BEFORE] = "before",
  [GRAPHITE_BIRTHDAY] = "birthday",
  [GRAPHITE_BUT] = ", but",
  [GRAPHITE_BY] = "by",
  [GRAPHITE_CAN] = "can",
  [GRAPHITE_CANNOT] = "can not",
  [GRAPHITE_COME] = "come",
  [GRAPHITE_COULD] = "could",
  [GRAPHITE_DAY] = "day",
  [GRAPHITE_DO] = "do",
  [GRAPHITE_EVEN] = "even",
  [GRAPHITE_FIND] = "find",
  [GRAPHITE_FIRST] = "first",
  [GRAPHITE_FOR] = "for",
  [GRAPHITE_FROM] = "from",
  [GRAPHITE_GET] = "get",
  [GRAPHITE_GIVE] = "give",
  [GRAPHITE_GO] = "go",
  [GRAPHITE_GREAT] = "great",
  [GRAPHITE_HAVE] = "have",
  [GRAPHITE_HE] = "he",
  [GRAPHITE_I_] = "I",
  [GRAPHITE_IF] = "if",
  [GRAPHITE_IN] = "in",
  [GRAPHITE_INTO] = "into",
  [GRAPHITE_IT] = "it",
  [GRAPHITE_KNOW] = "know",
  [GRAPHITE_KNOWLEDGE] = "knowledge",
  [GRAPHITE_LIKE] = "like",
  [GRAPHITE_LONG] = "long",
  [GRAPHITE_LOOK] = "look",
  [GRAPHITE_MAKE] = "make",
  [GRAPHITE_MAN] = "man",
  [GRAPHITE_MANY] = "many",
  [GRAPHITE_MAY] = "may",
  [GRAPHITE_MORE] = "more",
  [GRAPHITE_MOST] = "most",
  [GRAPHITE_MUST] = "must",
  [GRAPHITE_NEW] = "new",
  [GRAPHITE_NO] = "no",
  [GRAPHITE_NOT] = "not",
  [GRAPHITE_NOW] = "now",
  [GRAPHITE_OF] = "of",
  [GRAPHITE_ON] = "on",
  [GRAPHITE_ONE] = "one",
  [GRAPHITE_ONLY] = "only",
  [GRAPHITE_OR] = "or",
  [GRAPHITE_OTHER] = "other",
  [GRAPHITE_OUT] = "out",
  [GRAPHITE_OVER] = "over",
  [GRAPHITE_SAY] = "say",
  [GRAPHITE_SEE] = "see",
  [GRAPHITE_SHE] = "she",
  [GRAPHITE_SO] = "so",
  [GRAPHITE_SOME] = "some",
  [GRAPHITE_STATE] = "state",
  [GRAPHITE_SUCH] = "such",
  [GRAPHITE_TAKE] = "take",
  [GRAPHITE_THAN] = "than",
  [GRAPHITE_THAT] = "that",
  [GRAPHITE_THE] = "the",
  [GRAPHITE_THEIR] = "their",
  [GRAPHITE_THEM] = "them",
  [GRAPHITE_THEN] = "then",
  [GRAPHITE_THERE] = "there",
  [GRAPHITE_THESE] = "these",
  [GRAPHITE_THEY] = "they",
  [GRAPHITE_THINK] = "think",
  [GRAPHITE_THIS] = "this",
  [GRAPHITE_THOSE] = "those",
  [GRAPHITE_TIME] = "time",
  [GRAPHITE_TO] = "to",
  [GRAPHITE_UP] = "up",
  [GRAPHITE_USE] = "use",
  [GRAPHITE_WAY] = "way",
  [GRAPHITE_WE] = "we",
  [GRAPHITE_WHAT] = "what",
  [GRAPHITE_WHEN] = "when",
  [GRAPHITE_WHERE] = "where",
  [GRAPHITE_WHICH] = "which",
  [GRAPHITE_WHO] = "who",
  [GRAPHITE_WHY] = "why",
  [GRAPHITE_WILL] = "will",
  [GRAPHITE_WITH] = "with",
  [GRAPHITE_WORK] = "work",
  [GRAPHITE_WOULD] = "would",
  [GRAPHITE_YEAR] = "year",
  [GRAPHITE_YOU] = "you"
};

const char* get_combos_cmds(uint16_t combo_index){
    return combo_cmds[combo_index];
};