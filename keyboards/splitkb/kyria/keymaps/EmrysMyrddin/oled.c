#include QMK_KEYBOARD_H
#include <string.h>
#include "luna.c"
#include "other.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_default(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case CMK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        default:
            oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_layer_status(void) {
    oled_write_P(PSTR("Layer:  "), false);
    if (layer_state_is(CMK_R)) {
        oled_write_P(PSTR("Reversed\n"), false);
    } else if (layer_state_is(LWR_R)) {
        oled_write_P(PSTR("R Sym & Nums\n"), false);
    } else if (layer_state_is(RSE_R)) {
        oled_write_P(PSTR("R Nav & Fn \n"), false);
    } else if (layer_state_is(LWR)) {
        oled_write_P(PSTR("Sym & Nums\n"), false);
    } else if (layer_state_is(RSE)) {
        oled_write_P(PSTR("Nav & Fn\n"), false);
    } else if (layer_state_is(GAME_NUM)) {
        oled_write_P(PSTR("Num row\n"), false);
    } else if (layer_state_is(GAME_ARROWS)) {
        oled_write_P(PSTR("Arrows\n"), false);
    } else {
        oled_write_P(PSTR("Base\n"), false);
    }
}

void write_int_to_string(char* ref, uint8_t num) {
    // Words per minute is just assumed to remain under a thousand.
    char num_string[4];
    itoa(num, num_string, 10);
    strcat(ref, num_string);
}

void oled_write_with_int(char* str, uint8_t number) {
    write_int_to_string(str, number);
    oled_write(str, false);
}

static void render_os(void) {
    if (layer_state_is(WIN)) {
        oled_write_P(PSTR("OS:     Windows\n"), false);
    } else {
        oled_write_P(PSTR("OS:     macOS\n"), false);
    }
}

static void render_wpm(void) {
    char num[32] = "WPM:       ";
    write_int_to_string(num, get_current_wpm());
    oled_write_ln(num, false);
}

static void render_rgb_config(void) {
    hsv_t hsv = rgblight_get_hsv();
    oled_write_P(PSTR("HSV: "), false);
    char value[4] = "000";
    oled_write(itoa(hsv.h, value, 10), false);
    oled_write_P(PSTR(" "), false);
    oled_write(itoa(hsv.s, value, 10), false);
    oled_write_P(PSTR(" "), false);
    oled_write(itoa(hsv.v, value, 10), false);
    oled_write_P(PSTR("\n"), false);
}

#define OFF_TIMEOUT 60000
#define FADE_OUT_DURATION 5000
bool  right_cleaned_up = false;
hsv_t original_underglow_hsv;

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        uint32_t last_activity = MIN(last_matrix_activity_elapsed(), last_encoder_activity_elapsed());
        if (last_activity > OFF_TIMEOUT + FADE_OUT_DURATION) {
            rgblight_disable_noeeprom();
            oled_off();
            return false;
        } else if (last_activity > OFF_TIMEOUT) {
            rgblight_sethsv_noeeprom(original_underglow_hsv.h, original_underglow_hsv.s, original_underglow_hsv.v - original_underglow_hsv.v * ((float)last_activity - (float)OFF_TIMEOUT) / (float)FADE_OUT_DURATION);
        } else {
            rgblight_reload_from_eeprom();
            original_underglow_hsv = rgblight_get_hsv();
            oled_on();
        }
    }

    if (is_oled_on()) {
        if (is_keyboard_left()) {
            render_default();
            render_layer_status();
            render_os();
            render_wpm();
            // animate_luna();
        } else {
            if (!right_cleaned_up) {
                oled_clear();
                right_cleaned_up = true;
            }
            render_rgb_config();
            animate_luna();
        }
    }

    return false;
}
