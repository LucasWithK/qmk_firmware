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

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

#define BASE 0
#define MAIN 1
#define OTHR 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,               KC_W,               KC_F,               KC_P,               KC_B,
        KC_J,               KC_L,               KC_U,               KC_Y,               KC_SCLN,

        KC_A,               KC_R,               KC_S,               KC_T,               KC_G,
        KC_M,               KC_N,               KC_E,               KC_I,               KC_O,

        GUI_T(KC_Z),        ALT_T(KC_X),        CTL_T(KC_C),       LSFT_T(KC_D),       KC_V,
        KC_K,               RSFT_T(KC_H),       CTL_T(KC_COMM),    ALT_T(KC_DOT),      GUI_T(KC_SLSH),

        KC_ESC,             KC_BSPC,            KC_DEL,
        LT(OTHR, KC_ENT),   LT(MAIN, KC_SPC),   KC_TAB
    ),

    [MAIN] = LAYOUT(
        KC_1,               KC_2,               KC_3,               KC_4,               KC_5,
        KC_6,               KC_7,               KC_8,               KC_9,               KC_0,

        KC_GRV,             KC_EQL,             KC_MINS,            KC_QUOT,            KC_NO,
        KC_NO,              KC_LEFT,            KC_DOWN,            KC_UP,              KC_RIGHT,

        GUI_T(KC_NO),       ALT_T(KC_NO),       CTL_T(KC_NO),       LSFT_T(KC_NO),      KC_NO,
        KC_NO,              RSFT_T(KC_LBRC),    CTL_T(KC_RBRC),     ALT_T(KC_BSLS),     GUI_T(KC_NO),

        KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,            KC_TRNS
    ),

    [OTHR] = LAYOUT(
        KC_F1,              KC_F2,              KC_F3,              KC_F4,              KC_F5,
        KC_F6,              KC_F7,              KC_F8,              KC_F9,              KC_F10,

        UM(SS),             UP(ue, UE),         UP(oe, OE),         UP(ae, AE),         UM(EU),
        KC_F11,             KC_F12,             KC_NO,              KC_NO,              KC_NO,

        GUI_T(KC_CAPS),     ALT_T(KC_INS),      CTL_T(KC_HOME),     LSFT_T(KC_END),     MY_UC_NEXT,
        KC_PSCR,            RSFT_T(KC_PAUS),    CTL_T(KC_PGDN),     ALT_T(KC_PGUP),     GUI_T(KC_NUM),

        KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,            KC_TRNS
    ),
};
// maybe move € next no ' on MAIN, F11 and F12 left, put mouse keys on the righ home row in OTHER
// and find a position for left, middle, and right click, and maybe scrolling.
// maybe by moving PDWN, PGUP, INS, HOME, END, to, MAIN layer so the KC_NOs get filled.
// or find often used combos that can be put there, but maybe that does not work with the tap hold keys.