
#include "spacerockmedia.h"
#include "rgb_matrix.h"
#include "lib/lib8tion/lib8tion.h"

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) {
        return false;
    }
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    if (
                        // F Keys
                        (layer == _NAV && row == 2)
                        // digits
                        || (layer == _MEDIA && (col >= 14 && col <= 19))
                        // rgb inputs
                        || (layer == _ADJUST && (row >= 1 && row <= 3))
                    ) {
                        rgb_matrix_set_color(index, RGB_MAGENTA);
                    // WASD
                    } else if (layer == _NAV &&
                          ((row == 0 && col == 3) || (row == 1 && col >= 2 && col <= 4))
                          ) {
                        rgb_matrix_set_color(index, RGB_ORANGE);
                    }
                    // else {
                    //   rgb_matrix_set_color(index, RGB_GREEN);
                    // }
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) {
    return true;
}
bool rgb_matrix_indicators_user(void) {
    return rgb_matrix_indicators_keymap();
}
