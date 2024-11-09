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
    // 100 most used
    [ASK]       = {"ask", "asks", "asked", "asking"},
    [BACK]      = {"back", "backs", "backed", "backing"},
    [BE]        = {"be", "been", "being"},
    [BECOME]    = {"become", "becomes", "became", "becoming"},
    [BEGIN]     = {"begin", "begins", "began", "beginning"},
    [BUT]       = {", but", "but"},
    [CALL]      = {"call", "calls", "called", "calling"},
    [CAN]       = {"can", "could", "can not", "cann't", "could not", "could'nt"},
    [CANNOT]    = {"can not", "could not", "cann't", "could'nt", "can", "could"},
    [CHANGE]    = {"change", "changes", "changed", "changing"},
    [CHILD]     = {"child", "children"},
    [COME]      = {"come", "comes", "came", "coming"},
    [CONSIDER]  = {"consider", "considers", "considered", "considering"},
    [COULD]     = {"could", "could not", "could'nt", "can", "can not", "cann't"},
    [COURSE]    = {"course", "courses"},
    [DAY]       = {"day", "days"},
    [DEVELOP]   = {"develop", "develops", "developed", "developing"},
    [DO]        = {"do", "does", "did", "doing"},
    [EARLY]     = {"early", "earlier", "earliest"},
    [EARLY]     = {"early", "earlier", "earliest"},
    [END]       = {"end", "ends", "ended", "ending"},
    [EYE]       = {"eye", "eyes", "eyed", "eyeing"},
    [FACE]      = {"face", "faces", "faced", "facing"},
    [FACT]      = {"fact", "facts"},
    [FEEL]      = {"feel", "feels", "felt", "feeling"},
    [FEW]       = {"few", "fewer", "fewest"},
    [FIND]      = {"find", "finds", "found", "finding"},
    [FOLLOW]    = {"follow", "follows", "followed", "following"},
    [FORM]      = {"form", "forms", "formed", "forming"},
    [GENERAL]   = {"general", "generals"},
    [GET]       = {"get", "gets", "got", "getting"},
    [GIVE]      = {"give", "gives", "gave", "giving"},
    [GO]        = {"go", "goes", "went", "going"},
    [GOOD]      = {"good", "better", "best"},
    [GOVERN]    = {"govern", "governs", "governed", "governing"},
    [GREAT]     = {"great", "greater", "greatest"},
    [GROUP]     = {"group", "groups", "grouped", "grouping"},
    [HAND]      = {"hand", "hands"},
    [HAVE]      = {"have", "has", "had", "having"},
    [HE]        = {"he", "they"},
    [HEAD]      = {"head", "heads", "headed", "heading"},
    [HELP]      = {"help", "helps", "helped", "helping"},
    [HIGH]      = {"high", "higher", "highest"},
    [HOLD]      = {"hold", "holds", "held", "holding"},
    [HOME]      = {"home", "homes", "homed", "homing"},
    [HOUSE]     = {"house", "houses"},
    [I_]        = {"I", "we"},
    [INCREASE]  = {"increase", "increases", "increased", "increasing"},
    [INTEREST]  = {"interest", "interests", "interested", "interesting"},
    [IT]        = {"it", "them"},
    [KEEP]      = {"keep", "keeps", "keept", "keeping"},
    [KNOW]      = {"know", "knows", "knew", "knowing"},
    [KNOWLEDGE] = {"knowledge", "knowledgeable"},
    [LARGE]     = {"large", "larger", "largest"},
    [LATE]      = {"late", "later", "latest"},
    [LEAD]      = {"lead", "leads", "led", "leading"},
    [LEAVE]     = {"leave", "leaves", "left", "leaving"},
    [LIFE]      = {"life", "lives"},
    [LIKE]      = {"like", "likes", "liked", "liking"},
    [LINE]      = {"line", "lines", "lined", "lining"},
    [LITTLE]    = {"little", "littler", "littlest"},
    [LONG]      = {"long", "longer", "longest"},
    [LOOK]      = {"look", "looks", "looked", "looking"},
    [MAKE]      = {"make", "made", "making"},
    [MAN]       = {"man", "men"},
    [MANY]      = {"many", "more", "most"},
    [MAY]       = {"may", "might"},
    [MEAN]      = {"mean", "means", "meant", "meaning"},
    [MIGHT]     = {"might", "may"},
    [MORE]      = {"more", "most", "many"},
    [MOST]      = {"most", "many", "more"},
    [MOVE]      = {"move", "moves", "moved", "moving"},
    [NATION]    = {"nation", "nations"},
    [NEED]      = {"need", "needs", "needed", "needing"},
    [NEW]       = {"new", "news", "newer", "newest"},
    [NUMBER]    = {"number", "numbers"},
    [OLD]       = {"old", "older", "oldest"},
    [ONE]       = {"one", "ones"},
    [OPEN]      = {"open", "opens", "opened", "opening"},
    [OR]        = {"or", ", or", " or ", "or "},
    [ORDER]     = {"order", "orders", "ordered", "ordering"},
    [OTHER]     = {"other", "others"},
    [OUT]       = {"out", "outs", "outed", "outing"},
    [OWN]       = {"own", "own", "owned", "owning"},
    [PART]      = {"part", "parts", "parted", "parting"},
    [PEOPLE]    = {"people", "person"},
    [PERSON]    = {"person", "people"},
    [PLACE]     = {"place", "places"},
    [PLAN]      = {"plan", "plans", "planned", "planning"},
    [PLAY]      = {"play", "plays", "played", "playing"},
    [POINT]     = {"point", "points", "pointed", "pointing"},
    [PRESENT]   = {"present", "presents", "presented", "presenting"},
    [PROBLEM]   = {"problem", "problems"},
    [PROGRAM]   = {"program", "programs", "programmed", "programming"},
    [RIGHT]     = {"right", "rights"},
    [RUN]       = {"run", "runs", "ran", "running"},
    [SAY]       = {"say", "says", "said", "saying"},
    [SCHOOL]    = {"school", "schools"},
    [SEE]       = {"see", "sees", "saw", "seeing"},
    [SEEM]      = {"seem", "seems", "seemed", "seeming"},
    [SET]       = {"set", "sets", "seted", "setting"},
    [SHE]       = {"she", "they"},
    [SHOW]      = {"show", "shows", "shown", "showing"},
    [SMALL]     = {"small", "smaller", "smallest"},
    [SOME]      = {"take", "takes", "took", "taking"},
    [STAND]     = {"stand", "stands", "stood", "standing"},
    [STATE]     = {"state", "states", "stated", "stating"},
    [SYSTEM]    = {"system", "systems"},
    [TELL]      = {"tell", "tells", "told", "telling"},
    [THAT]      = {"that", "those"},
    [THEIR]     = {"their", "his", "her", "its"},
    [THESE]     = {"these", "this"},
    [THEY]      = {"they", "he", "she", "it"},
    [THING]     = {"thing", "things"},
    [THINK]     = {"think", "thinks", "thought", "thinking"},
    [THIS]      = {"this", "these"},
    [THOSE]     = {"those", "that"},
    [TURN]      = {"turn", "turns", "turned", "turning"},
    [USE]       = {"use", "uses", "used", "using"},
    [WANT]      = {"want", "wants", "wanted", "wanting"},
    [WAY]       = {"way", "ways"},
    [WE]        = {"we", "I"},
    [WELL]      = {"well", "wells"},
    [WHO]       = {"who", "whom", "whose"},
    [WILL]      = {"will", "wills", "willed", "willing"},
    [WORD]      = {"word", "words", "worded", "wording"},
    [WORK]      = {"work", "works", "worked", "working"},
    [WORLD]     = {"world", "worlds"},
    [WOULD]     = {"would", "will"},
    [WRITE]     = {"write", "writes", "wrote", "writing"},
    [YEAR]      = {"year", "years"},
    [YOU]       = {"you", "y'all"},

    // 1000 words most used
    [LEARN] = {"learn", "learns", "learned", "learning"},

    // personal
    // common words
    [WTF]       = {"fuck", "What the fuck", "wtf"},
    [HI]        = {"Hi!", "Hey!"},
    [I_VE]    = {"I've'", "you've"},
    [I_M]      = {"I'm", "you're"},
    [YEAH]      = {"Yeah!", "Yep!"},
    [THANK_YOU] = {"thank you!", "thanks!", "Thank you very much!"},

    [DEVELOPER]     = {"developer", "developers"},
    [GOD]           = {"god ", "gods"},
    [LOOSE]         = {"loose", "looses", "lost", "loosing"},
    [LOST]          = {"lost", "loses"},
    [PRODUCT_COMBO] = {"product", "products"},
    [PROJECT]       = {"project", "projects", "projected", "will project"},

};

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

    if (mods & MOD_MASK_SHIFT) {
      cycle_backward(mods);
    } else {
      cycle_forward();
    }

    return false;
  }
  return true;
}
