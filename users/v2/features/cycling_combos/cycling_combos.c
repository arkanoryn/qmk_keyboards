/* Copyright 2026 Pierre-Nicolas SORMANI, aka Ark'Anoryn (@arkanoryn)
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

#include "cycling_combos.h"
#include "combos/generated/combos.h"

static cycling_combos_state_t cycling_combos_state = {
    .is_combo_active     = false,
    .is_cyclable         = false,
    .last_cycle_combo_id = 0,
    .shift_enabled       = false,
    .cycle_position      = 0,
};

#ifdef CYCLE_COMBO_ENABLE
void init_cycling_combos_state(void) {
  cycling_combos_state.is_combo_active     = false;
  cycling_combos_state.is_cyclable         = false;
  cycling_combos_state.last_cycle_combo_id = 0;
  cycling_combos_state.shift_enabled       = false;
  cycling_combos_state.cycle_position      = 0;
}

cycling_combos_state_t* get_cycling_combo_state(void) {
  return &cycling_combos_state;
}
#endif // CYCLE_COMBO_ENABLE

// Cycle definitions for combos that can be cycled
// These are the combos that have multiple variants (e.g., ask/asks/asked/asking)
static const char *cycle_combo_output[][LONGEST_CYCLE] = {
    [GRAPHITE_ASK]       = {"ask", "asks", "asked", "asking", NULL, NULL},
    [GRAPHITE_BACK]      = {"back", "backs", "backed", "backing", NULL, NULL},
    [GRAPHITE_BE]        = {"be", "been", "being", NULL, NULL, NULL},
    [GRAPHITE_BECOME]    = {"become", "becomes", "became", "becoming", NULL, NULL},
    [GRAPHITE_BEGIN]     = {"begin", "begins", "began", "beginning", NULL, NULL},
    [GRAPHITE_BUT]       = {", but", "but", NULL, NULL, NULL, NULL},
    [GRAPHITE_CALL]      = {"call", "calls", "called", "calling", NULL, NULL},
    [GRAPHITE_CAN]       = {"can", "could", "can not", "cann't", "could not", "could'nt"},
    [GRAPHITE_CANNOT]    = {"can not", "could not", "cann't", "could'nt", "can", "could"},
    [GRAPHITE_CHANGE]    = {"change", "changes", "changed", "changing", NULL, NULL},
    [GRAPHITE_CHILD]     = {"child", "children", NULL, NULL, NULL, NULL},
    [GRAPHITE_COME]      = {"come", "comes", "came", "coming", NULL, NULL},
    [GRAPHITE_CONSIDER]  = {"consider", "considers", "considered", "considering", NULL, NULL},
    [GRAPHITE_COULD]     = {"could", "could not", "could'nt", "can", "can not", "cann't"},
    [GRAPHITE_COURSE]    = {"course", "courses", NULL, NULL, NULL, NULL},
    [GRAPHITE_DAY]       = {"day", "days", NULL, NULL, NULL, NULL},
    [GRAPHITE_DEVELOP]   = {"develop", "develops", "developed", "developing", NULL, NULL},
    [GRAPHITE_DO]        = {"do", "does", "did", "doing", NULL, NULL},
    [GRAPHITE_EARLY]     = {"early", "earlier", "earliest", NULL, NULL, NULL},
    [GRAPHITE_EAT]       = {"eat", "eats", "ate", "eating", NULL, NULL},
    [GRAPHITE_END]       = {"end", "ends", "ended", "ending", NULL, NULL},
    [GRAPHITE_EYE]       = {"eye", "eyes", "eyed", "eyeing", NULL, NULL},
    [GRAPHITE_FACE]      = {"face", "faces", "faced", "facing", NULL, NULL},
    [GRAPHITE_FACT]      = {"fact", "facts", NULL, NULL, NULL, NULL},
    [GRAPHITE_FEEL]      = {"feel", "feels", "felt", "feeling", NULL, NULL},
    [GRAPHITE_FEW]       = {"few", "fewer", "fewest", NULL, NULL, NULL},
    [GRAPHITE_FIND]      = {"find", "finds", "found", "finding", NULL, NULL},
    [GRAPHITE_FOLLOW]    = {"follow", "follows", "followed", "following", NULL, NULL},
    [GRAPHITE_FORM]      = {"form", "forms", "formed", "forming", NULL, NULL},
    [GRAPHITE_GENERAL]   = {"general", "generals", NULL, NULL, NULL, NULL},
    [GRAPHITE_GET]       = {"get", "gets", "got", "getting", NULL, NULL},
    [GRAPHITE_GIVE]      = {"give", "gives", "gave", "giving", NULL, NULL},
    [GRAPHITE_GO]        = {"go", "goes", "went", "going", NULL, NULL},
    [GRAPHITE_GOOD]      = {"good", "better", "best", NULL, NULL, NULL},
    [GRAPHITE_GOVERN]    = {"govern", "governs", "governed", "governing", NULL, NULL},
    [GRAPHITE_GREAT]     = {"great", "greater", "greatest", NULL, NULL, NULL},
    [GRAPHITE_GROUP]     = {"group", "groups", "grouped", "grouping", NULL, NULL},
    [GRAPHITE_HAND]      = {"hand", "hands", NULL, NULL, NULL, NULL},
    [GRAPHITE_HAVE]      = {"have", "has", "had", "having", NULL, NULL},
    [GRAPHITE_HE]        = {"he", "they", NULL, NULL, NULL, NULL},
    [GRAPHITE_HEAD]      = {"head", "heads", "headed", "heading", NULL, NULL},
    [GRAPHITE_HELP]      = {"help", "helps", "helped", "helping", NULL, NULL},
    [GRAPHITE_HIGH]      = {"high", "higher", "highest", NULL, NULL, NULL},
    [GRAPHITE_HOLD]      = {"hold", "holds", "held", "holding", NULL, NULL},
    [GRAPHITE_HOME]      = {"home", "homes", "homed", "homing", NULL, NULL},
    [GRAPHITE_HOUSE]     = {"house", "houses", NULL, NULL, NULL, NULL},
    [GRAPHITE_I_]        = {"I", "we", NULL, NULL, NULL, NULL},
    [GRAPHITE_INCREASE]  = {"increase", "increases", "increased", "increasing", NULL, NULL},
    [GRAPHITE_INTEREST]  = {"interest", "interests", "interested", "interesting", NULL, NULL},
    [GRAPHITE_IT]        = {"it", "them", NULL, NULL, NULL, NULL},
    [GRAPHITE_KEEP]      = {"keep", "keeps", "keept", "keeping", NULL, NULL},
    [GRAPHITE_KNOW]      = {"know", "knows", "knew", "knowing", NULL, NULL},
    [GRAPHITE_KNOWLEDGE] = {"knowledge", "knowledgeable", NULL, NULL, NULL, NULL},
    [GRAPHITE_LARGE]     = {"large", "larger", "largest", NULL, NULL, NULL},
    [GRAPHITE_LATE]      = {"late", "later", "latest", NULL, NULL, NULL},
    [GRAPHITE_LEAD]      = {"lead", "leads", "led", "leading", NULL, NULL},
    [GRAPHITE_LEAVE]     = {"leave", "leaves", "left", "leaving", NULL, NULL},
    [GRAPHITE_LIFE]      = {"life", "lives", NULL, NULL, NULL, NULL},
    [GRAPHITE_LIKE]      = {"like", "likes", "liked", "liking", NULL, NULL},
    [GRAPHITE_LINE]      = {"line", "lines", "lined", "lining", NULL, NULL},
    [GRAPHITE_LITTLE]    = {"little", "littler", "littlest", NULL, NULL, NULL},
    [GRAPHITE_LONG]      = {"long", "longer", "longest", NULL, NULL, NULL},
    [GRAPHITE_LOOK]      = {"look", "looks", "looked", "looking", NULL, NULL},
    [GRAPHITE_MAKE]      = {"make", "made", "making", NULL, NULL, NULL},
    [GRAPHITE_MAN]       = {"man", "men", NULL, NULL, NULL, NULL},
    [GRAPHITE_MANY]      = {"many", "more", "most", NULL, NULL, NULL},
    [GRAPHITE_MAY]       = {"may", "might", NULL, NULL, NULL, NULL},
    [GRAPHITE_MEAN]      = {"mean", "means", "meant", "meaning", NULL, NULL},
    [GRAPHITE_MIGHT]     = {"might", "may", NULL, NULL, NULL, NULL},
    [GRAPHITE_MORE]      = {"more", "most", "many", NULL, NULL, NULL},
    [GRAPHITE_MOST]      = {"most", "many", "more", NULL, NULL, NULL},
    [GRAPHITE_MOVE]      = {"move", "moves", "moved", "moving", NULL, NULL},
    [GRAPHITE_NATION]    = {"nation", "nations", NULL, NULL, NULL, NULL},
    [GRAPHITE_NEED]      = {"need", "needs", "needed", "needing", NULL, NULL},
    [GRAPHITE_NEW]       = {"new", "news", "newer", "newest", NULL, NULL},
    [GRAPHITE_NUMBER]    = {"number", "numbers", NULL, NULL, NULL, NULL},
    [GRAPHITE_OLD]       = {"old", "older", "oldest", NULL, NULL, NULL},
    [GRAPHITE_ONE]       = {"one", "ones", NULL, NULL, NULL, NULL},
    [GRAPHITE_OPEN]      = {"open", "opens", "opened", "opening", NULL, NULL},
    [GRAPHITE_OR]        = {"or", ", or", " or ", "or ", NULL, NULL},
    [GRAPHITE_ORDER]     = {"order", "orders", "ordered", "ordering", NULL, NULL},
    [GRAPHITE_OTHER]     = {"other", "others", NULL, NULL, NULL, NULL},
    [GRAPHITE_OUT]       = {"out", "outs", "outed", "outing", NULL, NULL},
    [GRAPHITE_OWN]       = {"own", "own", "owned", "owning", NULL, NULL},
    [GRAPHITE_PART]      = {"part", "parts", "parted", "parting", NULL, NULL},
    [GRAPHITE_PEOPLE]    = {"people", "person", NULL, NULL, NULL, NULL},
    [GRAPHITE_PERSON]    = {"person", "people", NULL, NULL, NULL, NULL},
    [GRAPHITE_PLACE]     = {"place", "places", NULL, NULL, NULL, NULL},
    [GRAPHITE_PLAN]      = {"plan", "plans", "planned", "planning", NULL, NULL},
    [GRAPHITE_PLAY]      = {"play", "plays", "played", "playing", NULL, NULL},
    [GRAPHITE_POINT]     = {"point", "points", "pointed", "pointing", NULL, NULL},
    [GRAPHITE_PRESENT]   = {"present", "presents", "presented", "presenting", NULL, NULL},
    [GRAPHITE_PROBLEM]   = {"problem", "problems", NULL, NULL, NULL, NULL},
    [GRAPHITE_PROGRAM]   = {"program", "programs", "programmed", "programming", NULL, NULL},
    [GRAPHITE_RIGHT]     = {"right", "rights", NULL, NULL, NULL, NULL},
    [GRAPHITE_RUN]       = {"run", "runs", "ran", "running", NULL, NULL},
    [GRAPHITE_SAME]      = {"same", NULL, NULL, NULL, NULL, NULL},
    [GRAPHITE_SAY]       = {"say", "says", "said", "saying", NULL, NULL},
    [GRAPHITE_SCHOOL]    = {"school", "schools", NULL, NULL, NULL, NULL},
    [GRAPHITE_SEE]       = {"see", "sees", "saw", "seeing", NULL, NULL},
    [GRAPHITE_SEEM]      = {"seem", "seems", "seemed", "seeming", NULL, NULL},
    [GRAPHITE_SET]       = {"set", "sets", "seted", "setting", NULL, NULL},
    [GRAPHITE_SHE]       = {"she", "they", NULL, NULL, NULL, NULL},
    [GRAPHITE_SHOULD]    = {"should", NULL, NULL, NULL, NULL, NULL},
    [GRAPHITE_SHOW]      = {"show", "shows", "shown", "showing", NULL, NULL},
    [GRAPHITE_SMALL]     = {"small", "smaller", "smallest", NULL, NULL, NULL},
    [GRAPHITE_SOME]      = {"take", "takes", "took", "taking", NULL, NULL},
    [GRAPHITE_STAND]     = {"stand", "stands", "stood", "standing", NULL, NULL},
    [GRAPHITE_STATE]     = {"state", "states", "stated", "stating", NULL, NULL},
    [GRAPHITE_SYSTEM]    = {"system", "systems", NULL, NULL, NULL, NULL},
    [GRAPHITE_TAKE]      = {"take", "takes", "took", "taking", NULL, NULL},
    [GRAPHITE_TELL]      = {"tell", "tells", "told", "telling", NULL, NULL},
    [GRAPHITE_THAN]      = {"than", NULL, NULL, NULL, NULL, NULL},
    [GRAPHITE_THAT]      = {"that", "those", NULL, NULL, NULL, NULL},
    [GRAPHITE_THEIR]     = {"their", "his", "her", "its", NULL, NULL},
    [GRAPHITE_THESE]     = {"these", "this", NULL, NULL, NULL, NULL},
    [GRAPHITE_THEY]      = {"they", "he", "she", "it", NULL, NULL},
    [GRAPHITE_THING]     = {"thing", "things", NULL, NULL, NULL, NULL},
    [GRAPHITE_THINK]     = {"think", "thinks", "thought", "thinking", NULL, NULL},
    [GRAPHITE_THIS]      = {"this", "these", NULL, NULL, NULL, NULL},
    [GRAPHITE_THOSE]     = {"those", "that", NULL, NULL, NULL, NULL},
    [GRAPHITE_TURN]      = {"turn", "turns", "turned", "turning", NULL, NULL},
    [GRAPHITE_USE]       = {"use", "uses", "used", "using", NULL, NULL},
    [GRAPHITE_WANT]      = {"want", "wants", "wanted", "wanting", NULL, NULL},
    [GRAPHITE_WAY]       = {"way", "ways", NULL, NULL, NULL, NULL},
    [GRAPHITE_WE]        = {"we", "I", NULL, NULL, NULL, NULL},
    [GRAPHITE_WELL]      = {"well", "wells", NULL, NULL, NULL, NULL},
    [GRAPHITE_WHO]       = {"who", "whom", "whose", NULL, NULL, NULL},
    [GRAPHITE_WILL]      = {"will", "wills", "willed", "willing", NULL, NULL},
    [GRAPHITE_WORD]      = {"word", "words", "worded", "wording", NULL, NULL},
    [GRAPHITE_WORK]      = {"work", "works", "worked", "working", NULL, NULL},
    [GRAPHITE_WORLD]     = {"world", "worlds", NULL, NULL, NULL, NULL},
    [GRAPHITE_WOULD]     = {"would", "will", NULL, NULL, NULL, NULL},
    [GRAPHITE_WRITE]     = {"write", "writes", "wrote", "writing", NULL, NULL},
    [GRAPHITE_YEAR]      = {"year", "years", NULL, NULL, NULL, NULL},
    [GRAPHITE_YOU]       = {"you", "y'all", NULL, NULL, NULL, NULL},
    [GRAPHITE_LOOSE]     = {"loose", "looses", "lost", "loosing", NULL, NULL},
    [GRAPHITE_LOST]      = {"lost", "loses", NULL, NULL, NULL, NULL},
};

// Helper function to match combo index with cycling combo enum
// This is a simplified version - in the generated version this would be more comprehensive
static uint16_t match_combo_index_with_cycling_combo(uint16_t combo_index) {
  // For now, we'll use a direct mapping for the cycling combos
  // This should eventually be generated by the script
  switch (combo_index) {
    case GRAPHITE_ASK: return GRAPHITE_ASK;
    case GRAPHITE_BACK: return GRAPHITE_BACK;
    case GRAPHITE_BE: return GRAPHITE_BE;
    case GRAPHITE_BECOME: return GRAPHITE_BECOME;
    case GRAPHITE_BEGIN: return GRAPHITE_BEGIN;
    case GRAPHITE_BUT: return GRAPHITE_BUT;
    case GRAPHITE_CALL: return GRAPHITE_CALL;
    case GRAPHITE_CAN: return GRAPHITE_CAN;
    case GRAPHITE_CANNOT: return GRAPHITE_CANNOT;
    case GRAPHITE_CHANGE: return GRAPHITE_CHANGE;
    case GRAPHITE_CHILD: return GRAPHITE_CHILD;
    case GRAPHITE_COME: return GRAPHITE_COME;
    case GRAPHITE_CONSIDER: return GRAPHITE_CONSIDER;
    case GRAPHITE_COULD: return GRAPHITE_COULD;
    case GRAPHITE_COURSE: return GRAPHITE_COURSE;
    case GRAPHITE_DAY: return GRAPHITE_DAY;
    case GRAPHITE_DEVELOP: return GRAPHITE_DEVELOP;
    case GRAPHITE_DO: return GRAPHITE_DO;
    case GRAPHITE_EARLY: return GRAPHITE_EARLY;
    case GRAPHITE_EAT: return GRAPHITE_EAT;
    case GRAPHITE_END: return GRAPHITE_END;
    case GRAPHITE_EYE: return GRAPHITE_EYE;
    case GRAPHITE_FACE: return GRAPHITE_FACE;
    case GRAPHITE_FACT: return GRAPHITE_FACT;
    case GRAPHITE_FEEL: return GRAPHITE_FEEL;
    case GRAPHITE_FEW: return GRAPHITE_FEW;
    case GRAPHITE_FIND: return GRAPHITE_FIND;
    case GRAPHITE_FOLLOW: return GRAPHITE_FOLLOW;
    case GRAPHITE_FORM: return GRAPHITE_FORM;
    case GRAPHITE_GENERAL: return GRAPHITE_GENERAL;
    case GRAPHITE_GET: return GRAPHITE_GET;
    case GRAPHITE_GIVE: return GRAPHITE_GIVE;
    case GRAPHITE_GO: return GRAPHITE_GO;
    case GRAPHITE_GOOD: return GRAPHITE_GOOD;
    case GRAPHITE_GOVERN: return GRAPHITE_GOVERN;
    case GRAPHITE_GREAT: return GRAPHITE_GREAT;
    case GRAPHITE_GROUP: return GRAPHITE_GROUP;
    case GRAPHITE_HAND: return GRAPHITE_HAND;
    case GRAPHITE_HAVE: return GRAPHITE_HAVE;
    case GRAPHITE_HE: return GRAPHITE_HE;
    case GRAPHITE_HEAD: return GRAPHITE_HEAD;
    case GRAPHITE_HELP: return GRAPHITE_HELP;
    case GRAPHITE_HIGH: return GRAPHITE_HIGH;
    case GRAPHITE_HOLD: return GRAPHITE_HOLD;
    case GRAPHITE_HOME: return GRAPHITE_HOME;
    case GRAPHITE_HOUSE: return GRAPHITE_HOUSE;
    case GRAPHITE_I_: return GRAPHITE_I_;
    case GRAPHITE_INCREASE: return GRAPHITE_INCREASE;
    case GRAPHITE_INTEREST: return GRAPHITE_INTEREST;
    case GRAPHITE_IT: return GRAPHITE_IT;
    case GRAPHITE_KEEP: return GRAPHITE_KEEP;
    case GRAPHITE_KNOW: return GRAPHITE_KNOW;
    case GRAPHITE_KNOWLEDGE: return GRAPHITE_KNOWLEDGE;
    case GRAPHITE_LARGE: return GRAPHITE_LARGE;
    case GRAPHITE_LATE: return GRAPHITE_LATE;
    case GRAPHITE_LEAD: return GRAPHITE_LEAD;
    case GRAPHITE_LEAVE: return GRAPHITE_LEAVE;
    case GRAPHITE_LIFE: return GRAPHITE_LIFE;
    case GRAPHITE_LIKE: return GRAPHITE_LIKE;
    case GRAPHITE_LINE: return GRAPHITE_LINE;
    case GRAPHITE_LITTLE: return GRAPHITE_LITTLE;
    case GRAPHITE_LONG: return GRAPHITE_LONG;
    case GRAPHITE_LOOK: return GRAPHITE_LOOK;
    case GRAPHITE_MAKE: return GRAPHITE_MAKE;
    case GRAPHITE_MAN: return GRAPHITE_MAN;
    case GRAPHITE_MANY: return GRAPHITE_MANY;
    case GRAPHITE_MAY: return GRAPHITE_MAY;
    case GRAPHITE_MEAN: return GRAPHITE_MEAN;
    case GRAPHITE_MIGHT: return GRAPHITE_MIGHT;
    case GRAPHITE_MORE: return GRAPHITE_MORE;
    case GRAPHITE_MOST: return GRAPHITE_MOST;
    case GRAPHITE_MOVE: return GRAPHITE_MOVE;
    case GRAPHITE_NATION: return GRAPHITE_NATION;
    case GRAPHITE_NEED: return GRAPHITE_NEED;
    case GRAPHITE_NEW: return GRAPHITE_NEW;
    case GRAPHITE_NUMBER: return GRAPHITE_NUMBER;
    case GRAPHITE_OLD: return GRAPHITE_OLD;
    case GRAPHITE_ONE: return GRAPHITE_ONE;
    case GRAPHITE_OPEN: return GRAPHITE_OPEN;
    case GRAPHITE_OR: return GRAPHITE_OR;
    case GRAPHITE_ORDER: return GRAPHITE_ORDER;
    case GRAPHITE_OTHER: return GRAPHITE_OTHER;
    case GRAPHITE_OUT: return GRAPHITE_OUT;
    case GRAPHITE_OWN: return GRAPHITE_OWN;
    case GRAPHITE_PART: return GRAPHITE_PART;
    case GRAPHITE_PEOPLE: return GRAPHITE_PEOPLE;
    case GRAPHITE_PERSON: return GRAPHITE_PERSON;
    case GRAPHITE_PLACE: return GRAPHITE_PLACE;
    case GRAPHITE_PLAN: return GRAPHITE_PLAN;
    case GRAPHITE_PLAY: return GRAPHITE_PLAY;
    case GRAPHITE_POINT: return GRAPHITE_POINT;
    case GRAPHITE_PRESENT: return GRAPHITE_PRESENT;
    case GRAPHITE_PROBLEM: return GRAPHITE_PROBLEM;
    case GRAPHITE_PROGRAM: return GRAPHITE_PROGRAM;
    case GRAPHITE_RIGHT: return GRAPHITE_RIGHT;
    case GRAPHITE_RUN: return GRAPHITE_RUN;
    case GRAPHITE_SAME: return GRAPHITE_SAME;
    case GRAPHITE_SAY: return GRAPHITE_SAY;
    case GRAPHITE_SCHOOL: return GRAPHITE_SCHOOL;
    case GRAPHITE_SEE: return GRAPHITE_SEE;
    case GRAPHITE_SEEM: return GRAPHITE_SEEM;
    case GRAPHITE_SET: return GRAPHITE_SET;
    case GRAPHITE_SHE: return GRAPHITE_SHE;
    case GRAPHITE_SHOW: return GRAPHITE_SHOW;
    case GRAPHITE_SMALL: return GRAPHITE_SMALL;
    case GRAPHITE_SOME: return GRAPHITE_SOME;
    case GRAPHITE_STAND: return GRAPHITE_STAND;
    case GRAPHITE_STATE: return GRAPHITE_STATE;
    case GRAPHITE_SYSTEM: return GRAPHITE_SYSTEM;
    case GRAPHITE_TAKE: return GRAPHITE_TAKE;
    case GRAPHITE_TELL: return GRAPHITE_TELL;
    case GRAPHITE_THAN: return GRAPHITE_THAN;
    case GRAPHITE_THAT: return GRAPHITE_THAT;
    case GRAPHITE_THEIR: return GRAPHITE_THEIR;
    case GRAPHITE_THESE: return GRAPHITE_THESE;
    case GRAPHITE_THEY: return GRAPHITE_THEY;
    case GRAPHITE_THING: return GRAPHITE_THING;
    case GRAPHITE_THINK: return GRAPHITE_THINK;
    case GRAPHITE_THIS: return GRAPHITE_THIS;
    case GRAPHITE_THOSE: return GRAPHITE_THOSE;
    case GRAPHITE_TURN: return GRAPHITE_TURN;
    case GRAPHITE_USE: return GRAPHITE_USE;
    case GRAPHITE_WANT: return GRAPHITE_WANT;
    case GRAPHITE_WAY: return GRAPHITE_WAY;
    case GRAPHITE_WE: return GRAPHITE_WE;
    case GRAPHITE_WELL: return GRAPHITE_WELL;
    case GRAPHITE_WHO: return GRAPHITE_WHO;
    case GRAPHITE_WILL: return GRAPHITE_WILL;
    case GRAPHITE_WORD: return GRAPHITE_WORD;
    case GRAPHITE_WORK: return GRAPHITE_WORK;
    case GRAPHITE_WORLD: return GRAPHITE_WORLD;
    case GRAPHITE_WOULD: return GRAPHITE_WOULD;
    case GRAPHITE_WRITE: return GRAPHITE_WRITE;
    case GRAPHITE_YEAR: return GRAPHITE_YEAR;
    case GRAPHITE_YOU: return GRAPHITE_YOU;
    case GRAPHITE_LOOSE: return GRAPHITE_LOOSE;
    case GRAPHITE_LOST: return GRAPHITE_LOST;
    default: return _LAST_COMBO_ID; // Not a cyclable combo
  }
}

void backspace_current_output(void) {
  const size_t str_len = strlen(cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position]);

  for (int i = 0; i < str_len; ++i) {
    tap_code16(KC_BSPC);
  }
}

void cycle_forward(void) {
  cycling_combos_state.cycle_position++;
  if (cycling_combos_state.cycle_position == LONGEST_CYCLE || cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position] == NULL) {
    cycling_combos_state.cycle_position = 0;
  }

  if (cycling_combos_state.shift_enabled) {
    set_oneshot_mods(MOD_BIT(KC_LSFT));
  }

  send_string(cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position]);
}

void cycle_backward(uint8_t mods) {
  if (cycling_combos_state.cycle_position > 0) {
    cycling_combos_state.cycle_position--;
  } else {
    cycling_combos_state.cycle_position = LONGEST_CYCLE - 1;
    while (cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position] == NULL) {
      cycling_combos_state.cycle_position--;
    }
  }

  del_mods(MOD_MASK_SHIFT);
  if (cycling_combos_state.shift_enabled) {
    set_oneshot_mods(MOD_BIT(KC_LSFT));
  }
  send_string(cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position]);
  set_mods(mods);
}

bool cycle(void) {
  if (cycling_combos_state.is_cyclable) {
    const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    backspace_current_output();

    // if (ARCANE || (mods & MOD_MASK_SHIFT)) {
    if (mods & MOD_MASK_SHIFT) {
      cycle_backward(mods);
    } else {
      cycle_forward();
    }

    return false;
  }
  return true;
}

void process_magic_combo_event(uint16_t combo_index) {
#ifdef CYCLE_COMBO_ENABLE
    init_cycling_combos_state();

    cycling_combos_state_t* combos_state = get_cycling_combo_state();
    const uint8_t           mods         = get_mods() | get_oneshot_mods() | get_weak_mods();

    combos_state->is_combo_active = true;
    combos_state->shift_enabled   = mods & MOD_MASK_SHIFT;
    combos_state->is_cyclable     = true;

    const uint16_t cycle_id = match_combo_index_with_cycling_combo(combo_index);

    if (cycle_id < _LAST_COMBO_ID && cycle_combo_output[cycle_id][0] != NULL) {
        combos_state->last_cycle_combo_id = cycle_id;
    } else {
        combos_state->is_cyclable = false;
    }
#endif // CYCLE_COMBO_ENABLE
}
