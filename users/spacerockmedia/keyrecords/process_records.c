
#include "spacerockmedia.h"
#include "version.h"
#include "features/process_records.c"

#ifdef HAPTIC_ENABLE
    #include "drivers/haptic/drv2605l.h"
#endif //HAPTIC ENABLE

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

// ┌───────────────────────────────────────────────────────────┐
// │ f e a t u r e s                                           │
// └───────────────────────────────────────────────────────────┘

    //
    // Repeat
    // this needs to be the first check for keycodes unless achordion is used then
    // that should be first
    #ifdef FEATURE_REPEAT_KEY_ENABLE
        if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) {
            return false;
        }
    #endif

    // Make sure to process features
    if (!process_record_features(keycode, record)) {
        return false;
    }

    //
    // Deactivte NAV layer if a non nav key is pressed
    if (get_highest_layer(layer_state | default_layer_state) == _NAV) {
        if (record->event.pressed) {
            // if one of the keys below is not pressed then disable _NAV
            switch (keycode) {
                case LY_ADJ:
                // navs
                case KC_PGUP:
                case KC_PGDN:
                case KC_LEFT:
                case KC_RIGHT:
                case KC_DOWN:
                case KC_UP:
                case M_LEFT:
                case M_RIGHT:
                case M_DOWN:
                case M_UP:
                // nums
                case KC_ASTR:
                case KC_SLSH:
                case KC_0:
                case KC_1:
                case KC_2:
                case KC_3:
                case KC_4:
                case KC_5:
                case KC_6:
                case KC_7:
                case KC_8:
                case KC_9:
                case KC_PLUS:
                case KC_MINS:
                case KC_DOT:
                    return true;
                default:
                    layer_off(_NAV);
                    return true;
            }
        }
    }

    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    switch (keycode) {



    }

    return true;
}
