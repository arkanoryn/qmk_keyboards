#include "magic.h"

/*
**    ///////////////
**   /// CYCLING ///
**  ///////////////
**
**
** This part is about cycling.
** At some point it's going to be move to its own file(s)
*/

static combos_state_t combos_state = {
    .combo_active     = false,
    .can_cycle        = false,
    .last_combo_index = 0,
    .shifted          = false,
    .cycle_position   = 0,
};

static const char *cycle_combo_output[][LONGEST_CYCLE] = {
    [BE_BE]          = {"be", "been", "being"},
    // [BT_BUT]         = {", but", "but"},
    // [CAN_CAN]        = {"can", "could", "can not", "cann't", "could not", "could'nt"},
    // [CANT_CANNOT]    = {"can not", "could not", "cann't", "could'nt", "can", "could"},
    // [DOMAGIC_DO]     = {"do", "does", "did", "doing"},
    // [HE_HE]          = {"he", "they"},
    // [HVE_HAVE]       = {"have", "haves", "had", "having"},
    [1]       = {"have", "haves", "had", "having"},
    // [ISPC_ISPC]      = {"I ", "we "},
    // [IT_IT]          = {"it", "them"},
    // [MAGICGO_GO]     = {"go", "went"},
    // [MAGICOR_OR]     = {"or", ", or", " or ", "or "},
    // [MAGICTR_THEIR]  = {"their", "his", "her", "its"},
    // [MAGICTS_THESE]  = {"these", "this"},
    // [MAN_MAN]        = {"man", "men"},
    // [MKE_MAKE]       = {"make", "made", "making"},
    // [MRE_MORE]       = {"more", "most", "many"},
    // [ONE_ONE]        = {"one", "ones"},
    // [OTR_OTHER]      = {"other", "others"},
    // [OUT_OUT]        = {"out", "outs", "outed", "outing"},
    // [SAY_SAY]        = {"say", "says", "said", "saying"},
    // [SHE_SHE]        = {"she", "they"},
    // [THA_THAT]       = {"that", "those"},
    // [THI_THINK]      = {"think", "thought", "thinking"},
    // [THS_THIS]       = {"this", "these"},
    // [THY_THEY]       = {"they", "he", "she", "it"},
    // [TOS_THOSE]      = {"those", "that"},
    // [WESPC_WESPC]    = {"we ", "I "},
    // [WHO_WHO]        = {"who", "whom", "whose"},
    // [WLD_WOULD]      = {"would", "will"},
    // [WLMAGIC_WILL]   = {"will", "wills", "willed", "willing"},
    // [YOU_YOU]        = {"you ", "y'all "},
    // [STE_STATE]      = {"state", "states", "stated", "stating"},
    // [NEW_NEW]        = {"new", "news", "newer", "newest"},
    // [YEA_YEAR]       = {"year", "years"},
    // [TKE_SOME]       = {"take", "takes", "took", "taking"},
    // [CME_COME]       = {"come", "comes", "came", "coming"},
    // [KNW_KNOW]       = {"know", "knows", "knew", "knowing"},
    // [KNWL_KNOWLEDGE] = {"knowledge", "knowledgeable"},
    // [MAGICSE_SEE]    = {"see", "sees", "saw", "seeing"},
    // [USE_USE]        = {"use", "uses", "used", "using"},
    // [GET_GET]        = {"get", "gets", "got", "getting"},
    // [MAGICIE_LIKE]   = {"like", "likes", "liked", "liking"},
    // [WRK_WORK]       = {"work", "works", "worked", "working"},
    // [MAGICGE_GIVE]   = {"give", "gives", "gave", "giving"},
    // [MOS_MOST]       = {"most", "many", "more"},
    // [MAGICFN_FIND]   = {"find", "finds", "found", "finding"},
    // [MAGICDA_DAY]    = {"day", "days"},
    // [WAY_WAY]        = {"way", "ways"},
    // [MAN_MANY]       = {"many", "more", "most"},
    // [MAGICLK_LOOK]   = {"look", "looks", "looked", "looking"},
    // [GRE_GREAT]      = {"great", "greater", "greatest"},
    // [BCK_BACK]       = {"back", "backs", "backed", "backing"},
    // [LNG_LONG]       = {"long", "longer", "longest"},
};

// static uint8_t current_cycle[ARRAY_SIZE(cycle_combo_output)] = {0};

// // /* FIXME: maybe u8 is not enough? */
// // /* FIXME: check that first <= index <= last (?) */
// // void update_combo_output(uint8_t index) {
// //     uint8_t next_val = combo_output[index] + 1;
// //     if (next_val == LONGEST_CYCLE || cycle_combo_output[next_val] == NULL) {
// //         next_val = 0;
// //     }
// //     combo_output[index] = next_val;
// // }

// // void send_cycle_combo(uint8_t index) {
// //     const uint8_t str_index = combo_output[index];
// //     const char *str = cycle_combo_output[index][str_index];
// //     send_string(str);
// // }

void cycle_forward(void) {
  combos_state.cycle_position++;
  if (combos_state.cycle_position == LONGEST_CYCLE || cycle_combo_output[combos_state.last_combo_index][combos_state.cycle_position] == NULL) {
    combos_state.cycle_position = 0;
  }
  send_string(cycle_combo_output[combos_state.last_combo_index][combos_state.cycle_position]);
}

void cycle_backward(void) {
  combos_state.cycle_position = LONGEST_CYCLE;
  for (int i = LONGEST_CYCLE; i > -1 && cycle_combo_output[combos_state.last_combo_index][combos_state.cycle_position] == NULL; --i) { // can I not replace I with cycle_position directly?
    combos_state.cycle_position--;
  }
  send_string(cycle_combo_output[combos_state.last_combo_index][combos_state.cycle_position]);
}

bool cycle(void) {
  if (combos_state.can_cycle) {
    const uint8_t mods             = get_mods() | get_oneshot_mods() | get_weak_mods();
    const size_t  previous_str_len = strlen(cycle_combo_output[combos_state.last_combo_index][combos_state.cycle_position]);

    for (int i = 0; i < previous_str_len; ++i) {
      tap_code16(KC_BSPC);
    }

    // send KC_BSPC for all characters of the current str
    // if shifted: apply shift mods

    if (mods & MOD_MASK_SHIFT) {
      cycle_backward();
    } else {
      cycle_forward();
    }

    return false;
  }
  return true;
}

// use that if the key pressed is not a combo
void init_combos_state(void) {
  combos_state.combo_active     = false;
  combos_state.can_cycle        = false;
  combos_state.last_combo_index = 0;
  combos_state.shifted          = false;
  combos_state.cycle_position   = 0;
};

void xyz(uint16_t combo_index) {
  init_combos_state();
  combos_state.shifted = false; // TODO

  combos_state.can_cycle = true;

  switch (combo_index) {
    case (1):
      combos_state.last_combo_index = 1;
      break;
    default:
      combos_state.can_cycle = false;
  }
};

combos_state_t get_combo_index(void) {
  return combos_state;
}

// /*
// **    /////////////////////
// **   /// CYCLING - END ///
// **  /////////////////////
// */

bool process_magic_key(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case MAGIC:
      if (record->event.pressed && combos_state.can_cycle) {
        cycle();
      }
      return false;
    default:
      return true;
  }
  return true;
}
