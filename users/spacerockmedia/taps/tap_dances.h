// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "spacerockmedia.h"

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Our custom TD keys
enum {
    HYP_NAV,
    NAV_CTL,
    MEH_NUM,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

void HYP_NAV_finished(tap_dance_state_t *state, void *user_data);
void HYP_NAV_reset(tap_dance_state_t *state, void *user_data);
