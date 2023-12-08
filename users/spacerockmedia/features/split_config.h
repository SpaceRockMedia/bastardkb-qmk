// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_DETECTED_OS_ENABLE
#define SPLIT_HAPTIC_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WPM_ENABLE

#ifdef SPLIT_OLED_ENABLE
#    undef SPLIT_OLED_ENABLE
#endif

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT

#ifdef HAPTIC_ENABLE
#  define SPLIT_HAPTIC_ENABLE
#endif
