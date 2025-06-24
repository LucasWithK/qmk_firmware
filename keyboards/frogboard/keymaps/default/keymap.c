// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
        KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,
        KC_Y,               KC_U,               KC_I,               KC_O,               KC_P,

        LSFT_T(KC_A),       KC_S,               KC_D,               KC_F,               KC_G,
        KC_H,               KC_J,               KC_K,               KC_L,               RSFT_T(KC_SCLN),

        CTL_T(KC_Z),        GUI_T(KC_X),        ALT_T(KC_C),        KC_V,               KC_B,
        KC_N,               KC_M,               ALT_T(KC_COMM),     GUI_T(KC_DOT),      CTL_T(KC_SLSH),

        KC_ESC,             KC_BSPC,            KC_DEL,
        LT(OTHR, KC_ENT),   LT(MAIN, KC_SPC),   KC_TAB
    ),

    [MAIN] = LAYOUT(
        KC_1,               KC_2,               KC_3,               KC_4,               KC_5,
        KC_6,               KC_7,               KC_8,               KC_9,               KC_0,

        LSFT_T(KC_GRV),     KC_NO,              KC_EQL,             KC_MINS,            KC_F11,
        KC_F12,             KC_LBRC,            KC_RBRC,            KC_BSLS,            RSFT_T(KC_QUOT),

        CTL_T(KC_F1),       GUI_T(KC_F2),       ALT_T(KC_F3),       KC_F4,              KC_F5,
        KC_F6,              KC_F7,              ALT_T(KC_F8),       GUI_T(KC_F9),       CTL_T(KC_F10),

        KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,            KC_TRNS
    ),

    [OTHR] = LAYOUT(
        ALGR(KC_Q),         KC_NO,              KC_NO,              KC_NO,              ALGR(KC_5),
        ALGR(KC_Y),         KC_NO,              KC_NO,              KC_NO,              ALGR(KC_P),

        LSFT_T(KC_NO),      ALGR(KC_S),         KC_NO,              KC_NO,              KC_NO,
        KC_LEFT,            KC_DOWN,            KC_UP,              KC_RIGHT,           RSFT_T(KC_NO),

        CTL_T(KC_CAPS),     GUI_T(KC_INS),      ALT_T(KC_HOME),     KC_END,             KC_NO,
        KC_PSCR,            KC_PGDN,            ALT_T(KC_PGUP),     GUI_T(KC_PAUS),     CTL_T(KC_SCRL),

        KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,            KC_TRNS
    ),
};
