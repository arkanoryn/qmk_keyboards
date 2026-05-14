#include "ark_v1.h"
#include "config.h"
#include "teacher/chord_teacher.h"

bool process_config(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef CHORD_TEACHER_ENABLE
        case CYCLE_CHORD_MODE:
            if (record->event.pressed) {
                set_teacher_chord_mode(get_teacher_chord_mode() + 1);
            }
            return false;
#endif // CHORD_TEACHER_ENABLE
        case TOGGLE_STURDY:
            layer_off(_CONFIG);
            layer_clear();
            set_single_default_layer(_STURDY);
            return false;
        case TOGGLE_COLEMAK:
            layer_off(_CONFIG);
            layer_clear();
            set_single_default_layer(_COLEMAK);
            return false;
        case TOGGLE_QWERTY:
            layer_off(_CONFIG);
            layer_clear();
            set_single_default_layer(_QWERTY);
            return false;
        case TOGGLE_GRAPHITE:
            layer_off(_CONFIG);
            layer_clear();
            set_single_default_layer(_GRAPHITE);
            return false;
        case TOGGLE_GAME:
            layer_off(_CONFIG);
            layer_clear();
            set_single_default_layer(_GAME);
            return false;
        default:
            return true;
    }
};
