/*
** /!\ This file is generated with the script `combos/scripts/parser.py`
** Do NOT manually modify. Change / create files under `combos/definitions` and
** re-run the script: `python3 parser.py <filename>`
** ex:
**
**     $> python3 parser.py qwerty.csv
*/
#pragma once

typedef enum {
  BACK = 0,
  BE,
  BUT,
  CAN,
  CANNOT,
  COME,
  COULD,
  DAY,
  DO,
  FIND,
  GET,
  GIVE,
  GO,
  GREAT,
  HAVE,
  HE,
  I_,
  IT,
  KNOW,
  KNOWLEDGE,
  LIKE,
  LONG,
  LOOK,
  MAKE,
  MAN,
  MANY,
  MORE,
  MOST,
  NEW,
  ONE,
  OR,
  OTHER,
  OUT,
  SAY,
  SEE,
  SHE,
  SOME,
  STATE,
  THAT,
  THEIR,
  THESE,
  THEY,
  THINK,
  THIS,
  THOSE,
  USE,
  WAY,
  WE,
  WHO,
  WILL,
  WORK,
  WOULD,
  YEAR,
  YOU,
  _LAST_CYCLING_COMBO
} cycling_combos_e;

cycling_combos_e match_combo_index_with_cycling_combo(uint16_t combo_index);
