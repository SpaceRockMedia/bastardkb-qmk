// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
#define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#if defined(RGB_MATRIX_DEFAULT_MODE)
#    undef RGB_MATRIX_DEFAULT_MODE
#endif
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Sets the default mode, if none has been set
#if defined(RGB_MATRIX_DEFAULT_VAL)
#    undef RGB_MATRIX_DEFAULT_VAL
#endif
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#if defined(RGB_MATRIX_DEFAULT_SPD)
#    undef RGB_MATRIX_DEFAULT_SPD
#endif
#define RGB_MATRIX_DEFAULT_SPD 127 // Sets the default animation speed, if none has been set
#define ENABLE_RGB_MATRIX_ALPHAS_MODS

// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_BAND_SAT
// #define ENABLE_RGB_MATRIX_BAND_VAL
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define ENABLE_RGB_MATRIX_CYCLE_ALL
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define ENABLE_RGB_MATRIX_DUAL_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN
// required RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// requires RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Heatmap Config

// In order to change the delay of temperature decrease define
// #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 25

// Limit the distance the effect spreads to surrounding keys.
// #define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40

// Limit how hot surrounding keys get from each press.
// #define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16

// Remove the spread effect entirely.
// #define RGB_MATRIX_TYPING_HEATMAP_SLIM

// It’s also possible to adjust the tempo of heating up.
// It’s defined as the number of shades that are increased on the HSV scale.
// Decreasing this value increases the number of keystrokes needed to fully heat up the key.
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32

// Solid reactive effects will pulse RGB light on key presses with user configurable hues.
// To enable gradient mode that will automatically change reactive color,
// add the following define:
#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
