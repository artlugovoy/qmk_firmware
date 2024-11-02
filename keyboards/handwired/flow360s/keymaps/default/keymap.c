// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// LED 22
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NAVIGATION,
    _SPECIAL,
    _MOUSE,
};

enum custom_keycodes {
    VVV = KC_TRNS,
    XXX = KC_NO,
    CSA_Q = MEH_T(KC_Q),
    CSA_F1 = MEH_T(KC_F1),
    CSA_1 = MEH_T(KC_1),
    CA_W = LCA_T(KC_W),
    CA_F2 = LCA_T(KC_F2),
    CA_2 = LCA_T(KC_2),
    CS_E = C_S_T(KC_E),
    CS_F = C_S_T(KC_F),
    CS_I = C_S_T(KC_I),
    CS_U = C_S_T(KC_U),
    CS_F3 = C_S_T(KC_F3),
    CS_3 = C_S_T(KC_3),
    CS_F8 = C_S_T(KC_F8),
    CS_8 = C_S_T(KC_8),
    CA_O = LCA_T(KC_O),
    CA_Y = LCA_T(KC_Y),
    CA_F9 = LCA_T(KC_F9),
    CA_9 = LCA_T(KC_9),
    CSA_P = MEH_T(KC_P),
    CSA_SCLN = MEH_T(KC_SCLN),
    CSA_F10 = MEH_T(KC_F10),
    CSA_0 = MEH_T(KC_0),
    LGUI_A = LGUI_T(KC_A),
    LGUI_FIND = LGUI_T(KC_FIND),
    LGUI_GRV = LGUI_T(KC_GRV),
    LALT_S = LALT_T(KC_S),
    LALT_R = LALT_T(KC_R),
    LALT_HOME = LALT_T(KC_HOME),
    LCTL_D = LCTL_T(KC_D),
    LCTL_S = LCTL_T(KC_S),
    LCTL_PGUP = LCTL_T(KC_PGUP),
    LCTL_LBRC = LCTL_T(KC_LBRC),
    LSFT_F = LSFT_T(KC_F),
    _LSFT_T = LSFT_T(KC_T),
    LSFT_PGDN = LSFT_T(KC_PGDN),
    LSFT_RBRC = LSFT_T(KC_RBRC),
    RSFT_J = RSFT_T(KC_J),
    RSFT_N = RSFT_T(KC_N),
    RSFT_DOWN = RSFT_T(KC_DOWN),
    RSFT_MINS = RSFT_T(KC_MINS),
    RCTL_K = RCTL_T(KC_K),
    RCTL_E = RCTL_T(KC_E),
    RCTL_UP = RCTL_T(KC_UP),
    RCTL_EQL = RCTL_T(KC_EQL),
    RALT_L = RALT_T(KC_L),
    RALT_I = RALT_T(KC_I),
    RALT_RGHT = RALT_T(KC_RGHT),
    RALT_BSLS = RALT_T(KC_BSLS),
    RGUI_SCLN = RGUI_T(KC_SCLN),
    RGUI_O = RGUI_T(KC_O),
    RGUI_F11 = RGUI_T(KC_F11),
    RGUI_QUOT = RGUI_T(KC_QUOT),
    LT3_SPC = LT(3,KC_SPC),
    LT2_TAB = LT(2,KC_TAB),
    DF_QWERTY = DF(0),
    DF_COLEMAK = DF(1),
};

// Permissive hold per key
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(3, KC_SPC):
      return true; // Enable permissive hold
    case LT(2, KC_TAB):
      return true;
    default:
      return false; // Disable permissive hold
  }
}

// Tapping force hold per key
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_SPC):
            return 0; // Enable force hold
        case LT(2, KC_TAB):
            return 0;
        default:
            return QUICK_TAP_TERM; // Disable force hold
    }
}

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_S_T(KC_E):
    case C_S_T(KC_I):
      return 215;
    default:
      return 190;
  }
}

// Macros
enum macro_events {
    M_KEYMAP = SAFE_RANGE,
    M_COMM,
    M_DOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            CSA_Q,   CA_W,    CS_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    CS_I,    CA_O,    CSA_P,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,                         KC_H,    RSFT_J,  RCTL_K,  RALT_L, RGUI_SCLN,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    CS_I,  KC_DOT,  KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       KC_SPC,  LT2_BSPC, KC_ESC,    KC_DEL, LT2_ENT,  KC_SPC
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_NAVIGATION] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            CSA_F1,  CA_F2,   CS_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   CS_F8,  CA_F9,   CSA_F10,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         LGUI_FIND,LALT_HOME,LCTL_PGUP,LSFT_PGDN,KC_END,                     KC_LEFT,RSFT_DOWN,RCTL_UP,RALT_RGHT,RGUI_F11,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         DF_QWERTY,DF_COLEMAK,KC_VOLD, KC_VOLU, QK_BOOT,                      KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_F12,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                        VVV,    TG(4),    VVV,         VVV,    VVV,     VVV
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_SPECIAL] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            CSA_1,   CA_2,    CS_3,    KC_4,    KC_5,                         KC_6,    KC_7,    CS_8,    CA_9,    CSA_0,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           LGUI_GRV,KC_LALT,LCTL_LBRC,LSFT_RBRC,KC_LPRN,                     KC_RPRN,RSFT_MINS,RCTL_EQL,RALT_BSLS,RGUI_QUOT,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_TILD, KC_CAPS, KC_LCBR, KC_RCBR,TG(_MOUSE),                     EE_CLR, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQUO,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                        VVV,     VVV,     VVV,        VVV,    TG(4),    VVV
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_MOUSE] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, DM_REC1,                      KC_WSTP, KC_ACL2, KC_ACL1, KC_ACL0, KC_WFWD,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, DM_PLY1,                      KC_WREF, KC_BTN1, KC_BTN2, KC_BTN3, KC_WBAK,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           M_KEYMAP,KC_BTN3, KC_BTN2, KC_BTN1,  XXX,                          XXX,     XXX,     XXX,     XXX,     XXX,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                        VVV,    TG(4),    VVV,        VVV,    TG(4),    VVV
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
};

