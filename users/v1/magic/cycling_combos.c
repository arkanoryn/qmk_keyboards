/*
**
** TODO:
**
*/
#include "magic.h"
#include "cycling_combos.h"
#include "generated/cycles.h"

static cycling_combos_state_t cycling_combos_state = {
    .is_combo_active     = false,
    .is_cyclable         = false,
    .last_cycle_combo_id = 0,
    .shift_enabled       = false,
    .cycle_position      = 0,
};

// use that if the key pressed is not a combo
void init_cycling_combos_state(void) {
  cycling_combos_state.is_combo_active     = false;
  cycling_combos_state.is_cyclable         = false;
  cycling_combos_state.last_cycle_combo_id = 0;
  cycling_combos_state.shift_enabled       = false;
  cycling_combos_state.cycle_position      = 0;
};

cycling_combos_state_t *get_cycling_combo_state(void) {
  return &cycling_combos_state;
}

static const char *cycle_combo_output[][LONGEST_CYCLE] = {
    [BACK]      = {"back", "backs", "backed", "backing"},
    [BE]        = {"be", "been", "being"},
    [BUT]       = {", but", "but"},
    [CAN]       = {"can", "could", "can not", "cann't", "could not", "could'nt"},
    [CANNOT]    = {"can not", "could not", "cann't", "could'nt", "can", "could"},
    [COME]      = {"come", "comes", "came", "coming"},
    [COULD]     = {"could", "could not", "could'nt", "can", "can not", "cann't"},
    [DAY]       = {"day", "days"},
    [DO]        = {"do", "does", "did", "doing"},
    [FIND]      = {"find", "finds", "found", "finding"},
    [GET]       = {"get", "gets", "got", "getting"},
    [GIVE]      = {"give", "gives", "gave", "giving"},
    [GO]        = {"go", "went"},
    [GREAT]     = {"great", "greater", "greatest"},
    [HAVE]      = {"have", "has", "had", "having"},
    [HE]        = {"he", "they"},
    [I_]        = {"I", "we"},
    [IT]        = {"it", "them"},
    [KNOW]      = {"know", "knows", "knew", "knowing"},
    [KNOWLEDGE] = {"knowledge", "knowledgeable"},
    [LIKE]      = {"like", "likes", "liked", "liking"},
    [LONG]      = {"long", "longer", "longest"},
    [LOOK]      = {"look", "looks", "looked", "looking"},
    [MAKE]      = {"make", "made", "making"},
    [MAN]       = {"man", "men"},
    [MANY]      = {"many", "more", "most"},
    [MORE]      = {"more", "most", "many"},
    [MOST]      = {"most", "many", "more"},
    [NEW]       = {"new", "news", "newer", "newest"},
    [ONE]       = {"one", "ones"},
    [OR]        = {"or", ", or", " or ", "or "},
    [OTHER]     = {"other", "others"},
    [OUT]       = {"out", "outs", "outed", "outing"},
    [SAY]       = {"say", "says", "said", "saying"},
    [SEE]       = {"see", "sees", "saw", "seeing"},
    [SHE]       = {"she", "they"},
    [SOME]      = {"take", "takes", "took", "taking"},
    [STATE]     = {"state", "states", "stated", "stating"},
    [THAT]      = {"that", "those"},
    [THEIR]     = {"their", "his", "her", "its"},
    [THESE]     = {"these", "this"},
    [THEY]      = {"they", "he", "she", "it"},
    [THINK]     = {"think", "thought", "thinking"},
    [THIS]      = {"this", "these"},
    [THOSE]     = {"those", "that"},
    [USE]       = {"use", "uses", "used", "using"},
    [WAY]       = {"way", "ways"},
    [WE]        = {"we ", "I "},
    [WHO]       = {"who", "whom", "whose"},
    [WILL]      = {"will", "wills", "willed", "willing"},
    [WORK]      = {"work", "works", "worked", "working"},
    [WOULD]     = {"would", "will"},
    [YEAR]      = {"year", "years"},
    [YOU]       = {"you ", "y'all "},
};

void backspace_current_output(void) {
    const size_t  str_len = strlen(cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position]);

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
    SEND_STRING("one off is on\n");
    set_oneshot_mods(MOD_BIT(KC_LSFT));
  }

  send_string(cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position]);
}

void cycle_backward(void) {
  if (cycling_combos_state.cycle_position > 0) {
    cycling_combos_state.cycle_position--;
  } else {
    cycling_combos_state.cycle_position = LONGEST_CYCLE - 1;
    while (cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position] == NULL) {
      cycling_combos_state.cycle_position--;
    }
  }

  del_mods(MOD_MASK_SHIFT); // TODO: be less brute force and disable / enable only the mods that are enabled at the time of call
  if (cycling_combos_state.shift_enabled) {
    set_oneshot_mods(MOD_BIT(KC_LSFT));
  }
  send_string(cycle_combo_output[cycling_combos_state.last_cycle_combo_id][cycling_combos_state.cycle_position]);
  add_mods(MOD_MASK_SHIFT);
}

bool cycle(void) {
  if (cycling_combos_state.is_cyclable) {
    const uint8_t mods             = get_mods() | get_oneshot_mods() | get_weak_mods();

    backspace_current_output();
    if (mods & MOD_MASK_SHIFT) {
      cycle_backward();
    } else {
      cycle_forward();
    }

    return false;
  }
  return true;
}
