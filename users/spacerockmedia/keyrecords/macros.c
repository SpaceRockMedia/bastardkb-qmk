
#include "spacerockmedia.h"

bool process_records_macros(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘

        case MAKE_H:
            if (record->event.pressed) {
                #ifdef KEYBOARD_klor_2040
                    SEND_STRING ("qmk compile -kb klor/2040 -km spacerockmedia");
                    tap_code(KC_ENTER);
                #endif
                #ifdef KEYBOARD_splitkb_kyria_rev3
                    SEND_STRING ("qmk compile -kb splitkb/kyria/rev3 -km spacerockmedia");
                    tap_code(KC_ENTER);
                #endif
                #ifdef KEYBOARD_splitkb_kyria_rev3
                    SEND_STRING ("qmk compile -kb hillside/52 -km spacerockmedia");
                    tap_code(KC_ENTER);
                #endif
            }
            return false;


// ┌───────────────────────────────────────────────────────────┐
// │ o s  s h o r t c u t                                      │
// └───────────────────────────────────────────────────────────┘

        case OS_COPY:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("c"));
                } else {
                    SEND_STRING(SS_LCTL("c"));
                }
            }
            return true;

        case OS_CUT:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("x"));
                } else {
                    SEND_STRING(SS_LCTL("x"));
                }
            }
            return true;

        case OS_PASTE:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("v"));
                } else {
                    SEND_STRING(SS_LCTL("v"));
                }
            }
            return true;

        case OS_UNDO:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("z"));
                } else {
                    SEND_STRING(SS_LCTL("z"));
                }
            }
            return true;

        case OS_REDO:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD(SS_LSFT("z")));
                } else {
                    SEND_STRING(SS_LCTL(SS_LSFT("z")));
                }
            }
            return true;

        case OS_SAVE:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("s"));
                } else {
                    SEND_STRING(SS_LCTL("s"));
                }
            }
            return true;


// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘

        case SNAP1:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LSFT(SS_LCMD("4")));           //MAC
                } else {
                    SEND_STRING(SS_LWIN(SS_TAP(X_PSCR)));         //WIN
                }
            }
            break;

        case SNAP2:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
                } else {
                    SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
                }
            }
            break;

        case KC_MPLY:
            if (record->event.pressed) {
            #ifdef HAPTIC_ENABLE
                    drv2605l_pulse(sharp_click);
            #endif // HAPTIC_ENABL
            }
            break;

    }
    return true;
}
