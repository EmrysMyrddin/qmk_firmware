#include "other.h"

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case RSE:
            case LWR:
                if (clockwise) {
                    tap_code16(G(KC_Z));
                } else {
                    tap_code16(G(S(KC_Z)));
                }
                break;
            default :
                if (clockwise) {
                    tap_code16(C(KC_LEFT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case RSE:
            case LWR:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            default:
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    if (clockwise) {
                        rgblight_increase_hue();
                    } else {
                        rgblight_decrease_hue();
                    }
                } else if (keyboard_report->mods & MOD_BIT(KC_LCTL)) {
                    if (clockwise) {
                        rgblight_increase_sat();
                    } else {
                        rgblight_decrease_sat();
                    }
                } else if (keyboard_report->mods & MOD_BIT(KC_RALT)) {
                    if (clockwise) {
                        rgblight_increase_val();
                    } else {
                        rgblight_decrease_val();
                    }
                } else {
                    if (!clockwise) {
                        tap_code16(G(A(KC_LEFT)));
                    } else {
                        tap_code16(G(A(KC_RIGHT)));
                    }
                }
        }
    }
}
