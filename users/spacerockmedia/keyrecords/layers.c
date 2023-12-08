
#include "spacerockmedia.h"

bool process_records_layers(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_DEF:
            if (record->event.pressed) {
                layer_clear();
                if (IS_LAYER_ON(_GAME)) {
                    set_single_persistent_default_layer(_COLEMAK);
                    layer_move(_COLEMAK);
                } else {
                    set_single_persistent_default_layer(_GAME);
                    layer_move(_GAME);
                }
                #ifdef HAPTIC_ENABLE
                  drv2605l_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case LY_DEF:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_GAME)) {
                    layer_clear();
                    layer_move(_GAME);
                } else {
                    layer_clear();
                    layer_move(_COLEMAK);
                }
                #ifdef HAPTIC_ENABLE
                  drv2605l_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
    }

    return true;
}
