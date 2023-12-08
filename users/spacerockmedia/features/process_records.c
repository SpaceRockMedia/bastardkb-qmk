
#include "spacerockmedia.h"
#include "features/process_records.h"
#include "features/swapper.h"
#include "features/keyswapper.h"
#include "os_detection.h"

#ifdef FEATURE_SWAPPER_ENABLE
    bool sw_win_active = false;
    bool sw_lang_active = false;
#endif

#ifdef FEATURE_CALLUM_ENABLE
    oneshot_state os_shft_state = os_up_unqueued;
    oneshot_state os_ctrl_state = os_up_unqueued;
    oneshot_state os_alt_state = os_up_unqueued;
    oneshot_state os_cmd_state = os_up_unqueued;
#endif

bool process_record_features(uint16_t keycode, keyrecord_t *record) {

    switch (detected_host_os()) {
        case OS_MACOS:
            //
            // Callum's Swapper
            #ifdef FEATURE_SWAPPER_ENABLE
                update_swapper(
                    &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
                    keycode, record
                );
            #endif

            // we dont need to test for keycodes as we always will be swapping these keys
            // when we need to process them

            #ifdef FEATURE_KEYSWAPPER_ENABLE
                keyswapper(record, KC_LCTL, KC_LCMD);
                keyswapper(record, KC_RCTL, KC_RCMD);
                keyswapper(record, KC_LCMD, KC_LCTL);
                keyswapper(record, KC_RCMD, KC_RCTL);
            #endif

            break;
        default:
            //
            // Callum's Swapper
            #ifdef FEATURE_SWAPPER_ENABLE
                update_swapper(
                    &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
                    keycode, record
                );
            #endif
            break;
    }

    //
    // Callum
    #ifdef FEATURE_CALLUM_ENABLE
        update_oneshot(
            &os_shft_state, KC_LSFT, OS_LSFT,
            keycode, record
        );
        update_oneshot(
            &os_shft_state, KC_RSFT, OS_RSFT,
            keycode, record
        );
        update_oneshot(
            &os_ctrl_state, KC_LCTL, OS_CTRL,
            keycode, record
        );
        update_oneshot(
            &os_alt_state, KC_LALT, OS_ALT,
            keycode, record
        );
        update_oneshot(
            &os_cmd_state, KC_LGUI, OS_CMD,
            keycode, record
        );
        //break;
    #endif

    //
    // Sentence Case
    #ifdef FEATURE_SENTENCE_CASE_ENABLE
        if (!process_sentence_case(keycode, record)) { return false; }
    #endif

    return true;
}
