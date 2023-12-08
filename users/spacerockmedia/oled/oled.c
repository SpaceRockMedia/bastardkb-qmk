/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2021 John Ezra - wpm graph
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "lib/lib8tion/lib8tion.h"

#include "spacerockmedia.h"
#include "oled/oled.h"
#include "oled/assets.h"

const char *get_layer_name_string(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COLEMAK:
            return "Colemak\n";
        case _GAME:
            return "QWERTY\n";
        case _NAV:
            return "Nav\n";
        case _MEDIA:
            return "Media\n";
        case _ADJUST:
            return "Adjust\n";
        default:
            return "Unknown\n";
    }
}

__attribute__ ((weak))
bool oled_task_keymap(void) {
    return true;
}

bool oled_task_user(void) {
    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Space Rock!\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    oled_write_P(PSTR(get_layer_name_string(layer_state|default_layer_state)), false);

    // Write host Keyboard LED Status to OLEDs
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    oled_task_keymap();

    return false;
}

