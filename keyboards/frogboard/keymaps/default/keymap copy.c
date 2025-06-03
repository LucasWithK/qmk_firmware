// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum unicode_names {
    ae,
    AE,
    oe,
    OE,
    ue,
    UE,
    SS,
    EU
};

const uint32_t PROGMEM unicode_map[] = {
    [ae] = 0x00E4,  // ä
    [AE] = 0x00C4,  // Ä
    [oe] = 0x00F6,  // ö
    [OE] = 0x00D6,  // Ö
    [ue] = 0x00FC,  // ü
    [UE] = 0x00DC,  // Ü
    [SS] = 0x00DF,  // ß
    [EU] = 0x20AC,  // €
};

enum custom_keycodes {
    MY_UC_NEXT = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MY_UC_NEXT:
        if (record->event.pressed) {;
            unicode_input_mode_step();
            switch (get_unicode_input_mode()) {
                case UNICODE_MODE_LINUX:
                    SEND_STRING("UNICODE_MODE_LINUX");
                    break;
                case UNICODE_MODE_MACOS:
                    SEND_STRING("UNICODE_MODE_MACOS");
                    break;
                case UNICODE_MODE_WINCOMPOSE:
                    SEND_STRING("UNICODE_MODE_WINCOMPOSE");
                    break;
            };
        }
        break;
    }
    return true;
};

#define BASE 0
#define NUMS 1
#define NAVI 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,               KC_W,               KC_F,               KC_P,               KC_B,
        KC_J,               KC_L,               KC_U,               KC_Y,               KC_SCLN,

        KC_A,               KC_R,               KC_S,               KC_T,               KC_G,
        KC_M,               KC_N,               KC_E,               KC_I,               KC_O,

        KC_Z,               KC_X,               KC_C,               KC_D,               KC_V,
        KC_K,               KC_H,               KC_COMM,            KC_DOT,             KC_SLSH,

        ALT_T(KC_LGUI),     SFT_T(KC_BSPC),     CTL_T(KC_DEL),
        LT(NAVI, KC_ENT),   KC_SPC,             LT(NUMS, KC_TAB)
    ),

    [NUMS] = LAYOUT(
        KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,
        KC_F6,              KC_F7,              KC_F8,              KC_F9,              KC_F10,

        KC_1,               KC_2,               KC_3,               KC_4,               KC_5,
        KC_6,               KC_7,               KC_8,               KC_9,               KC_0,

        KC_ESC,             KC_GRV,             KC_EQL,             KC_MINS,            KC_F11,
        KC_F12,             KC_LBRC,            KC_RBRC,            KC_QUOT,            KC_BSLS,

        KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,            KC_TRNS
    ),

    [NAVI] = LAYOUT(
        KC_SCRL,            KC_PGUP,            KC_UP,              KC_PGDN,            KC_NO,
        KC_NO,              KC_NO,              KC_NO,              KC_NO,              MY_UC_NEXT,

        KC_CAPS,            KC_LEFT,            KC_DOWN,            KC_RIGHT,           KC_NO,
        UM(EU),             UP(ae, AE),         UP(oe, OE),         UP(ue, UE),         UM(SS),

        KC_NUM,             KC_INS,             KC_HOME,            KC_END,             KC_NO,
        KC_NO,              KC_PSCR,            KC_PAUS,            KC_NO,              KC_NO,

        KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,            KC_TRNS
    ),
};