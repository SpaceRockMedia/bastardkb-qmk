#include "spacerockmedia.h"
#include <stdio.h>
#include <ctype.h>

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    // if ((mods & MOD_MASK_CTRL)) {   // Was Ctrl held?
    //     switch (keycode) {
    //         case KC_Y: return C(KC_Z);  // Ctrl + Y reverses to Ctrl + Z.
    //         case KC_Z: return C(KC_Y);  // Ctrl + Z reverses to Ctrl + Y.
    //     }
    // }

    return KC_TRNS;  // Defer to the defaults.
}
