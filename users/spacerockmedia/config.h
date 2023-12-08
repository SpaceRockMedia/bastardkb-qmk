// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "features/config.h"

// Use custom magic number so that when switching branches, EEPROM always gets reset
// #define EECONFIG_MAGIC_NUMBER (uint16_t)0x1339

// Will probably only have 16 or less layers.
#define LAYER_STATE_16BIT

#define ENABLE_COMPILE_KEYCODE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000

#if defined(COMBO_ENABLE)
#    include "combos/config.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "rgb/rgb_matrix_config.h"
#endif // RGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
#    include "oled/config.h"
#endif

// Tapping
#include "taps/config.h"
