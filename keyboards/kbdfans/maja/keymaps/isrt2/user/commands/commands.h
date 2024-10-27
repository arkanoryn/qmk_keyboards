#pragma once

#include "./../enums.h"
#include "./../../keymap.h"

/*
**    ///////////////
**   /// ACCENTS ///
**  ///////////////
**
**
** This part is about accents.
** At some point it's going to be move to its own header file, maybe.
*/

#define WIN_CIRCONFLEXE         A(S(KC_6))
#define WIN_AIGU                A(KC_QUOTE)
#define WIN_GRAVE               A(KC_GRAVE)
#define WIN_TREMA               A(S(KC_QUOTE))
#define WIN_CEDILLE             A(KC_QUOTE)
#define MAC_CIRCONFLEXE         LOPT(KC_I)
#define MAC_AIGU                LOPT(KC_E)
#define MAC_GRAVE               LOPT(KC_GRAVE)
#define MAC_TREMA               LOPT(KC_U)
#define CIRCONFLEXE             (detected_host_os() == OS_MACOS ? MAC_CIRCONFLEXE : WIN_CIRCONFLEXE)
#define AIGU                    (detected_host_os() == OS_MACOS ? MAC_AIGU : WIN_AIGU)
#define GRAVE                   (detected_host_os() == OS_MACOS ? MAC_GRAVE : WIN_GRAVE)
#define TREMA                   (detected_host_os() == OS_MACOS ? MAC_TREMA : WIN_TREMA)

/*
**    /////////////////////
**   /// ACCENTS - END ///
**  /////////////////////
*/

/*
**    ////////////////////////
**   /// GLOBAL VARIABLES ///
**  ////////////////////////
*/


/*
**    /////////////////
**   /// FUNCTIONS ///
**  /////////////////
*/
bool process_accents(uint16_t keycode, keyrecord_t *record);
bool process_shortcuts(uint16_t keycode, keyrecord_t *record);
uint16_t send_shortcut(e_actions_id id, bool is_alt_tab_active);
