#include QMK_KEYBOARD_H
#include <string.h>
#include <stdio.h>
#include "luna.c"
//#include "bongocat.c"
#include "other.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

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
    if(layer_state_is(CMK_R)) {
        oled_write_P(PSTR("Reversed\n"), false);
    } else if(layer_state_is(LWR_R)) {
        oled_write_P(PSTR("R Sym & Nums\n"), false);
    } else if(layer_state_is(RSE_R)) {
        oled_write_P(PSTR("R Nav & Fn \n"), false);
    } else if(layer_state_is(LWR)) {
        oled_write_P(PSTR("Sym & Nums\n"), false);
    } else if(layer_state_is(RSE)) {
        oled_write_P(PSTR("Nav & Fn\n"), false);
    } else if(layer_state_is(GAME_NUM)) {
        oled_write_P(PSTR("Num row\n"), false);
    } else if(layer_state_is(GAME_ARROWS)) {
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

char wpm_str[10];

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default();
        render_layer_status();
        render_os();
        render_wpm();
        animate_luna();
    } else {
//        animate_bongocat();
        oled_set_cursor(0, 7);
        uint8_t n  = get_current_wpm();
        wpm_str[3] = '\0';
        wpm_str[2] = '0' + n % 10;
        wpm_str[1] = '0' + (n /= 10) % 10;
        wpm_str[0] = '0' + n / 10;
        oled_write_P(PSTR("          "), false);
        oled_write(wpm_str, false);
    }
    return false;
}
