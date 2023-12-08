#include QMK_KEYBOARD_H
#include "features/leader.h"

#ifdef AUDIO_ENABLE
    float leader_start_song[][2] = SONG(ONE_UP_SOUND);
    float leader_succeed_song[][2] = SONG(ALL_STAR);
    float leader_fail_song[][2] = SONG(RICK_ROLL);
#endif

__attribute__((weak))
bool leader_start_keymap(void) {
    return true;
}

void leader_start_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(leader_start_song);
    #endif
    // Do something when the leader key is pressed

    leader_start_keymap();
}

__attribute__((weak))
bool leader_end_keymap(bool did_leader_succeed) {
    #ifdef AUDIO_ENABLE
        if (did_leader_succeed) {
            PLAY_SONG(leader_succeed_song);
        } else {
            PLAY_SONG(leader_fail_song);
        }
    #endif
    return did_leader_succeed;
}

void leader_end_user(void) {
    bool did_leader_succeed = false;

    if (leader_sequence_one_key(KC_Q)) {
        tap_code16(KC_F1);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_W)) {
        tap_code16(KC_F2);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_E)) {
        tap_code16(KC_F3);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_R)) {
        tap_code16(KC_F4);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_T)) {
        tap_code16(KC_F5);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_Y)) {
        tap_code16(KC_F6);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_U)) {
        tap_code16(KC_F7);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_I)) {
        tap_code16(KC_F8);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_O)) {
        tap_code16(KC_F9);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_P)) {
        tap_code16(KC_F10);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_SCLN)) {
        tap_code16(KC_F11);
        did_leader_succeed = true;
    } else if (leader_sequence_one_key(KC_SLSH)) {
        tap_code16(KC_F12);
        did_leader_succeed = true;
    }

    leader_end_keymap(did_leader_succeed);
}
