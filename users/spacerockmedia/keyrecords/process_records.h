// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "spacerockmedia.h"

typedef enum userspace_custom_keycodes {
    LY_DEF = QK_USER,
    TG_DEF,
    LY_COLE,
    LY_GAME,
    OS_LSFT,
    OS_RSFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    OS_COPY,
    OS_CUT,
    OS_PASTE,
    OS_UNDO,
    OS_REDO,
    OS_SAVE,
    SW_WIN,
    CTALDEL,
    SEARCH,
    OPN,
    CAPWORD,
    KC_TOGG,
    KC_QWER,
    KC_COLE,
    OS_SWAP,
    SNAP1,
    SNAP2,
    MAKE_H,
    REPEAT,
    ALTREP,
} CUSTOM_KEYCODES_T;

#define xxxxxxx KC_NO
#define _______ KC_TRNS

//
// Layers
//
#define LY_NAV TT(_NAV)
#define LY_ADJ TO(_ADJUST)
#define LY_MED MO(_MEDIA)

//
// Abbreviations
//

#define UNDO LCTL(KC_Z)
#define CUT  LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Y)

#define KHYP MOD_HYPR
#define KMEH MOD_MEH
#define M_UP MEH(KC_UP)
#define M_DOWN MEH(KC_DOWN)
#define M_LEFT MEH(KC_LEFT)
#define M_RIGHT MEH(KC_RGHT)
#define M_PGUP MEH(KC_PGUP)
#define M_PGDN MEH(KC_PGDN)

#define MT_PGUP MT(KC_PGUP, KC_PGDN)

//
// Mods
//
#define OSM_LALT OSM(MOD_LALT)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RGUI OSM(MOD_RGUI)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RCTL OSM(MOD_RCTL)

// (For OS X, you'll want to change these editing keys to LGUI(KC_Z) etc.)

//
// Some windows shortcuts
//

// Everything
#define CTALDEL HYPR_T(KC_SPACE)
// Task Manager
#define CTALESC LCTL(LALT(KC_ESC))
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_QUO CTL_T(KC_QUOT)
