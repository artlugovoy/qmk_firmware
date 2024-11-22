#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _PROG   1
#define _GAMG   2

#define CTL_Z LCTL_T(KC_Z)
#define CTL_SLS LCTL_T(KC_SLSH)
#define WIN_SHIFT LSG_T(KC_DEL)


#define F_EQL KC_EQL // equals sign
#define F_PLUS KC_MINS // +
#define F_TILD S(KC_GRV) // ~

// brackets
#define F_SBRL KC_LBRC // square bracket left
#define F_SBRR KC_RBRC // square bracket right
#define F_CBRL S(KC_LBRC) // curly bracket left
#define F_CBRR S(KC_RBRC) // curly bracket right
#define F_RBRL S(KC_9) // round bracket left
#define F_RBRR S(KC_0) // round bracket right
#define F_ABRL KC_NUBS // angle bracket left
#define F_ABRR S(KC_NUBS) // angle bracket right
#define F_PIPE S(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_6x6(
      KC_EQL,       KC_1,            KC_2,        KC_3,         KC_4,         KC_5,                  KC_6,        KC_7,         KC_8,        KC_9,    KC_0,                    TG(_GAMG),
      KC_TAB,       KC_Q,            KC_W,        SFT_T(KC_E),  LGUI_T(KC_R), KC_T,                  KC_Y,        RGUI_T(KC_U), SFT_T(KC_I), KC_O,    KC_P,                    KC_DEL,
      KC_ESC,       LT(_PROG, KC_A), KC_S,        KC_D,         KC_F,         KC_G,                  KC_H,        KC_J,         KC_K,        KC_L,    LT(_PROG, KC_SEMICOLON), KC_QUOT,
      KC_LSFT,      CTL_Z,           KC_X,        KC_C,         LSG_T(KC_V),  KC_B,                  KC_N,        RSG_T(KC_M),  KC_COMM,     KC_DOT,  CTL_SLS,                 KC_RSFT,
      KC_QUOT,      KC_LEFT_ALT,     KC_LEFT,     KC_RGHT,                                           KC_UP,       KC_DOWN,      KC_LBRC,     KC_RBRC,
      RCTL(KC_INS), KC_DEL,          KC_HOME,     KC_END,       KC_BSPC,      KC_SPC,                S(KC_INS),   KC_DEL,       KC_PGUP,     KC_PGDN, KC_ENT,                  KC_SPC
  ),

  [_PROG] = LAYOUT_6x6(
      KC_F12,       KC_F1,           KC_F2,       KC_F3,        KC_F4,        KC_F5,                KC_F6,        KC_F7,       KC_F8,      KC_F9,    KC_F10,                   KC_F11,
      _______,      RCS(KC_4),       S(KC_MINS),  F_CBRL,       F_CBRR,       KC_CAPS,              KC_GRAVE,     S(KC_2),     S(KC_3),    F_PIPE,   KC_DEL,                   _______,
      _______,      RCS(KC_5),       KC_MINS,     F_RBRL,       F_RBRR,       S(KC_6),              S(KC_4),      F_SBRL,      F_SBRR,     F_TILD,   F_EQL,                    _______,
      _______,      RCS(KC_6),       S(KC_EQL),   KC_BACKSLASH, KC_SLASH,     F_ABRL,               F_ABRR,       S(KC_QUOT),  KC_QUOT,    S(KC_7),  S(KC_8),                  _______,
      _______,      _______,         _______,     _______,                                          _______,      _______,     _______,    _______,
      _______,      _______,         _______,     _______,      _______,      _______,              _______,      _______,     _______,    _______,  _______,                  _______
  ),


  [_GAMG] = LAYOUT_6x6(
      KC_ESC,      KC_1,             KC_2,        KC_3,         KC_4,         KC_5,                 KC_6,         KC_7,        KC_8,       KC_9,     KC_0  ,                   TG(_GAMG),
      _______,     KC_Q,             KC_W,        KC_E,         KC_R,         KC_T,                 KC_Y,         LSG_T(KC_U), KC_I,       KC_O,     RGUI_T(KC_P),             _______,
      KC_LCTL,     KC_A,             KC_S,        KC_D,         KC_F,         KC_G,                 KC_H,         KC_J,        KC_K,       KC_L,     LT(_PROG, KC_SEMICOLON),  _______,
      KC_LSFT,     _______,          KC_X,        KC_C,         KC_V,         KC_B,                 KC_N,         KC_M,        KC_COMM,    KC_DOT,   CTL_SLS,                  _______,
      KC_QUOT,     KC_LEFT_ALT,      KC_LEFT,     KC_RGHT,                                          KC_UP,        KC_DOWN,     KC_LBRC,    KC_RBRC,
      _______,     _______,          _______,     _______,      _______,      _______,              _______,      _______,     _______,    _______,  _______,                  _______
  ),
};
