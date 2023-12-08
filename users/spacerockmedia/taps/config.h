// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TAPPING_TERM 350
#define TAPPING_TERM_PER_KEY

// https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
// The PERMISSIVE_HOLD option is not noticeable if you also enable
// HOLD_ON_OTHER_KEY_PRESS because the latter option considers both the “nested
// tap” and “rolling press” sequences like shown above as a hold action, not the
// tap action. HOLD_ON_OTHER_KEY_PRESS makes the Tap-Or-Hold decision earlier in
// the chain of key events, thus taking a precedence over PERMISSIVE_HOLD.
// define PERMISSIVE_HOLD
// define PERMISSIVE_HOLD_PER_KEY

// https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif

// #define TAP_CODE_DELAY 5

#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY
