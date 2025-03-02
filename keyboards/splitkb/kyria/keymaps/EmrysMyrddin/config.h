/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define OLED_DISPLAY_128X64

#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5
// #define RGBLIGHT_SLEEP
// #define RGBLIGHT_LAYERS
// #define RGBLIGHT_DISABLE_KEYCODES

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2

// Tap-Hold
#define TAPPING_TERM 125
#define PERMISSIVE_HOLD

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

// OS Detection
#define OS_DETECTION_KEYBOARD_RESET // To reset OS Detection on USB reset, when using a KVM
#define OS_DETECTION_SINGLE_REPORT  // Avoid late callback calls on some KVM and macOS on ARM

// Split synchronisation for OLED display
// Configuration for Split Keyboards
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
// #define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE
