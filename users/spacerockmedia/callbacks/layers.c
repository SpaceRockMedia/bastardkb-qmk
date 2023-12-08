
#include "spacerockmedia.h"


__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

// bool is_entering_layer(layer_state_t state, uint8_t layer) {
//     return false == IS_LAYER_ON_STATE(state, layer);
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    // LED layer indicator
    // writePin(B0, get_highest_layer(state) > 0);

    // // Note that layer_state_set_user() is called on every layer state change.
    // // To react only when entering or exiting a specific ADJUST layer, use a
    // // pattern like this:

    // bool entering_adjust = is_entering_layer(state, _ADJUST);
    // if (entering_adjust) {  // Just entered the ADJUST layer.
    //     // PLAY_SONG(MAJOR_SONG);
    // } else {          // Just exited the ADJUST layer.
    //     // PLAY_SONG(GOODBYE_SONG);
    // }
    // }

    return layer_state_set_keymap(state);
}
