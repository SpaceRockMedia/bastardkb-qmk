
#include QMK_KEYBOARD_H
#include "features/callum.h"
#include "features/swapper.h"

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LY_DEF:
    case TG_DEF:
    case LY_COLE:
    case LY_GAME:
    case LY_NAV:
    case LY_ADJ:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LY_DEF:
    case TG_DEF:
    case LY_COLE:
    case LY_GAME:
    case LY_NAV:
    case LY_ADJ:
    case KC_LSFT:
    case OS_LSFT:
    case OS_RSFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
