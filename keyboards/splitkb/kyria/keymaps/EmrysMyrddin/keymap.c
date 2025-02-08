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
#include QMK_KEYBOARD_H
#include "other.h"

enum custom_keycodes {
    DSK_NXT= SAFE_RANGE,
    DSK_PRV,
    PRINT,
    LOCK,
    KC_OS,
    KC_BT,
    KC_QT,
    KC_TL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak-dhm
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ; : |  ^   |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |  O   | ' "  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | TAB  |   Z  |   X  |   C  |   D  |   V  | Mute | CtEnt|  | ESC  |  OS  |   K  |   H  | ,  < | . >  | /  ? | ` ~  |
 * `--------------------+------+------+------+------+------|  |------|------+------+------+------+--------------------'
 *                      | Play | Ctrl | GUI  | Shift| Raise|  | Lower| Shift| GUI | Alt  | SLEEP |
 *                      |      |      |  - _ | Enter| Del  |  | BSCP | Space|     |      |       |
 *                      `----------------------------------'  `----------------------------------'
 */
    [CMK] = LAYOUT(
       KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,    KC_B,                                                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_CIRC,
LT(CMK_R, KC_ESC),     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                           KC_M,    KC_N,    KC_E,    KC_I,    KC_O, LT(CMK_R, KC_QUOT),
        KC_TAB, KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,KC_MUTE,     MO(LWR_R),    MO(RSE_R),    KC_OS, KC_K,    KC_H, KC_COMM, KC_DOT,  KC_SLASH, KC_GRV,
             KC_MPLY, KC_LCTL, LGUI_T(KC_MINS), LSFT_T(KC_ENT), LT(RSE, KC_DEL),   LT(LWR, KC_BSPC), RSFT_T(KC_SPC), KC_RGUI, KC_RALT, G(A(KC_EJCT))
    ),

    [CMK_R] = LAYOUT(
       KC_CIRC,  KC_SCLN,     KC_Y,    KC_U,    KC_L,    KC_J,                                                 KC_B,    KC_P,    KC_F,    KC_W,    KC_Q,  KC_TAB,
       _______,     KC_O,    KC_I,    KC_E,    KC_N,    KC_M,                                   KC_G,    KC_T,    KC_S,    KC_R,    KC_A, _______,
       KC_GRV, KC_SLASH,     KC_DOT,    KC_COMM,    KC_H,    KC_K,      KC_OS,    LT(RSE, KC_ESC),    C(KC_ENT),    KC_MUTE, KC_V,    KC_D, KC_C, KC_X,  KC_Z, KC_TAB,
             G(A(KC_EJCT)), KC_RALT, KC_RGUI, RSFT_T(KC_SPC), LT(LWR, KC_BSPC),   LT(RSE, KC_DEL),  LSFT_T(KC_ENT), LGUI_T(KC_MINS), KC_LCTL, KC_MPLY
    ),
/*
 * Lower Layer: Numpad, Symbol
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ~    |  $   |  @   |  [ { |  ] } |  \   |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  | QWERTY |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   `    |  #   |  !   |  (   |  )   |  /   |                              | *    | 4 $  | 5 %  | 6 ^  |  +   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   '    |      |  €   |  {   |  }   |  |   |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  | Colemak|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LWR] = LAYOUT(
      KC_TL, KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, DF(GAME),
      LT(LWR_R, KC_BT), KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_SLSH,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_PLUS, MO(LWR_R),
      KC_QT,  _______,ALGR(KC_5),KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, MO(RSE_R), _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  DF(CMK),
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [LWR_R] = LAYOUT(
      DF(GAME), KC_MINS,  KC_9,   KC_8, KC_7, KC_SLSH,                                               KC_BSLS , KC_RBRC, KC_LBRC, KC_AT, KC_DLR, KC_TL,
      _______, KC_PLUS, KC_6, KC_5, KC_4, KC_ASTR,                                     KC_SLSH, KC_RPRN,    KC_LPRN,    KC_EXLM, KC_HASH, _______,
      DF(CMK),  KC_EQL,KC_3,KC_2, KC_1, KC_0, _______, _______, _______, _______, KC_PIPE,    KC_RCBR,    KC_LCBR,    ALGR(KC_5), _______,  KC_QT,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Media, nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Prns  | Home | cLeft| Up   | cRght| Pgup |                              | LoScr|  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+------|                              |------|------+------+------+------+--------|
 * |  Lock  | End  | Left | Down | Right| Pgdn |                              |      |  F5  |  F6  |  F7  |  F8  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Sleep |      |  <M  |  M>  | <D   | D>   |      |      |  |      |      |      |  F1  |  F2  |  F3  |  F4  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+------+---------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RSE] = LAYOUT(
      PRINT, KC_HOME,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_PGUP,                              KC_SCROLL_LOCK, KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
      LT(RSE_R, LOCK), KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     _______,KC_F5,   KC_F6,   KC_F7,   KC_F8,  MO(RSE_R),
      KC_SLEP, _______, KC_MPRV, KC_MNXT, DSK_PRV, DSK_NXT, _______, _______, _______, _______, _______,KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [RSE_R] = LAYOUT(
      PRINT, KC_HOME,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_PGUP,                              KC_PGUP, C(KC_RGHT),   KC_UP,  C(KC_LEFT),  KC_HOME, PRINT,
      _______, KC_F8,  KC_F7, KC_F6, KC_F5, _______,                                    KC_PGDN ,KC_LEFT, KC_DOWN,   KC_RGHT,   KC_END,  _______,
      _______, KC_F4, KC_F3, KC_F2, KC_F1, _______, _______, _______, _______, _______, DSK_NXT,DSK_PRV,   KC_MNXT,   KC_MPRV,   _______,  KC_SLEP,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

   [GAME] = LAYOUT(
     KC_TAB,  KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,                                          KC_T ,  KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,
     KC_ESC,  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                                          KC_G ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , _______,
     KC_CAPS, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V   , _______, _______, _______, _______,   KC_B ,  KC_N  ,  KC_M  ,KC_COMMA, KC_DOT ,KC_SLASH,
                                _______, MO(GAME_NUM), KC_ENT , KC_SPC , KC_DEL,  _______, _______, _______, MO(GAME_ARROWS), _______
   ),
   [GAME_NUM] = LAYOUT(
      _______,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,
      _______,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,                                     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [GAME_ARROWS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_PAGE_UP, KC_UP, KC_PAGE_DOWN, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  DF(CMK),
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


/*
* Layer template
*
* ,-------------------------------------------.                              ,-------------------------------------------.
* |        |      |      |      |      |      |                              |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                              |      |      |      |      |      |        |
* |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
*                        |      |  Alt | Ctrl |      |      |  |      |      | Ctrl | Alt  |      |
*                        |      |      | - _  |      |      |  |      |      |      |      |      |
*                        `----------------------------------'  `----------------------------------'
*/
    [WIN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_LALT, LCTL_T(KC_MINS), _______, _______, _______, _______, KC_RCTL, KC_RALT, _______
    ),
    [WIN_RSE_LWR] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_LGUI, _______, _______, _______, _______, _______, _______, KC_RGUI, _______
    ),


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DSK_PRV:
            if (record->event.pressed) {
                if (user_config.osIsWindows) {
                    tap_code16(C(A(KC_LEFT)));
                } else {
                    tap_code16(C(G(KC_LEFT)));
                }
            }
            break;
        case DSK_NXT:
            if (record->event.pressed) {
                if (user_config.osIsWindows) {
                    tap_code16(C(A(KC_RIGHT)));
                } else {
                    tap_code16(C(G(KC_RIGHT)));
                }
            }
            break;
        case PRINT: // Print screen
            if (record->event.pressed) {
                if (user_config.osIsWindows) {
                    tap_code16(C(S(KC_PSCR)));
                } else {
                    tap_code16(S(G(KC_S)));
                }
            }
            break;
        case LOCK: // Lock the computer
            if (record->event.pressed) {
                if (user_config.osIsWindows) {
                    tap_code16(LCA(KC_L));
                } else {
                    tap_code16(G(KC_L));
                }
            }
            break;
        case KC_OS: // Switch OS between Windows and Mac
            if(record->event.pressed) {
                user_config.osIsWindows = !user_config.osIsWindows;
                eeconfig_update_user(user_config.raw);
                if(user_config.osIsWindows) {
                    layer_on(WIN);
                } else {
                    layer_off(WIN);
                }
            }
            break;
        case KC_BT: // Write character backtick depending on OS
            if(record->event.pressed) {
                tap_code16(KC_GRV);
                if(user_config.osIsWindows) {
                    tap_code16(KC_SPC);
                }
            }
            break;
        case KC_QT: // Write character quote depending on OS
            if(record->event.pressed) {
                tap_code16(KC_QUOT);
                if(user_config.osIsWindows) {
                    tap_code16(KC_SPC);
                }
            }
            break;
        case KC_TL: // Write character tilde depending on OS
            if(record->event.pressed) {
                tap_code16(KC_TILD);
                if(user_config.osIsWindows) {
                    tap_code16(KC_SPC);
                }
            }
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if(layer_state_cmp(state, LWR) || layer_state_cmp(state, RSE)) {
        // To allow customization of the RSE and LWR layers on windows, we enable a windows specific layout
        if(user_config.osIsWindows) {
            state |= ((layer_state_t)1 << WIN_RSE_LWR);
        }
    } else {
        // Always disable the layer in case the windows mode have been disabled
        state &= ~((layer_state_t)1 << WIN_RSE_LWR);
    }

    return state;
}
