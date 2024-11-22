#include QMK_KEYBOARD_H


#define _QWERTY  0
#define _PROG    1
#define _CONTROL 2
#define _GAMG    3

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


enum custom_keycodes {
    DRGSCRL = SAFE_RANGE,
    LOWCPI = SAFE_RANGE + 1
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 15.0
#define SCROLL_DIVISOR_V 30.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
      KC_EQL,       KC_1,            KC_2,        KC_3,               KC_4,         KC_5,                  KC_6,        KC_7,         KC_8,        KC_9,    KC_0,                    TG(_GAMG),
      KC_TAB,       KC_Q,            KC_W,        SFT_T(KC_E),        LGUI_T(KC_R), KC_T,                  KC_Y,        RGUI_T(KC_U), SFT_T(KC_I), KC_O,    KC_P,                    KC_DEL,
      KC_ESC,       LT(_PROG, KC_A), KC_S,        LT(_CONTROL, KC_D), KC_F,         KC_G,                  KC_H,        KC_J,         KC_K,        KC_L,    LT(_PROG, KC_SEMICOLON), LT(_CONTROL, KC_QUOT),
      KC_LSFT,      CTL_Z,           KC_X,        KC_C,               LSG_T(KC_V),  KC_B,                  KC_N,        RSG_T(KC_M),  KC_COMM,     KC_DOT,  CTL_SLS,                 KC_RSFT,
      RCTL(KC_QUOT),KC_LEFT_ALT,     KC_LEFT,     KC_RGHT,            KC_SPC,                              KC_ENT,      KC_SPC,       KC_UP,       KC_DOWN, KC_LBRC,                 KC_RBRC,
      KC_BSPC,      KC_PGDN,         KC_PGUP,                                                              KC_BSPC,     S(KC_INS),    KC_HOME,     KC_END
  ),

  [_PROG] = LAYOUT(
      KC_F12,       KC_F1,           KC_F2,       KC_F3,              KC_F4,        KC_F5,                KC_F6,        KC_F7,       KC_F8,      KC_F9,    KC_F10,                   KC_F11,
      _______,      RCS(KC_4),       S(KC_MINS),  F_CBRL,             F_CBRR,       KC_CAPS,              KC_GRAVE,     S(KC_2),     S(KC_3),    F_PIPE,   KC_DEL,                   _______,
      KC_BSPC,      RCS(KC_5),       KC_MINS,     F_RBRL,             F_RBRR,       S(KC_6),              S(KC_4),      F_SBRL,      F_SBRR,     F_TILD,   F_EQL,                    _______,
      _______,      RCS(KC_6),       S(KC_EQL),   KC_BACKSLASH,       KC_SLASH,     F_ABRL,               F_ABRR,       S(KC_QUOT),  KC_QUOT,    S(KC_7),  S(KC_8),                  _______,
      _______,      _______,         _______,     _______,            _______,                            _______,      _______,     _______,    _______,  _______,                  _______,
      _______,      _______,         _______,                                                             _______,      _______,     _______,    _______
  ),

  [_CONTROL] = LAYOUT(
      RGB_M_B,      RGB_M_R,         UG_PREV,     UG_NEXT,            UG_VALU,      UG_NEXT,               _______,      _______,     _______,    _______,  _______,                 KC_PSCR,
      _______,      KC_1,            KC_2,        KC_3,               KC_4,         KC_5,                  KC_LEFT,      KC_DOWN,     KC_UP,      KC_RGHT,  RCTL(KC_F),              _______,
      _______,      _______,         _______,     _______,            _______,      _______,               KC_BSPC,      MS_BTN1,     MS_BTN3,    MS_BTN2,  DRGSCRL,                 _______,
      _______,      KC_6,            KC_7,        KC_8,               KC_9,         KC_0,                  KC_INS,       S(KC_INS),   LOWCPI,     _______,  CW_TOGG,                 _______,
      _______,      _______,         _______,     _______,            KC_ESC,                              _______,      KC_DEL,      _______,    _______,  _______,                 _______,
      _______,      _______,         _______,                                                              _______,      KC_MNXT,     KC_MPLY,    KC_MPRV
  ),

  [_GAMG] = LAYOUT(
      KC_ESC,      KC_1,             KC_2,        KC_3,               KC_4,         KC_5,                 KC_6,         KC_7,        KC_8,       KC_9,     KC_0  ,                   TG(_GAMG),
      _______,     KC_Q,             KC_W,        KC_E,               KC_R,         KC_T,                 KC_Y,         LSG_T(KC_U), KC_I,       KC_O,     RGUI_T(KC_P),             _______,
      KC_LCTL,     KC_A,             KC_S,        KC_D,               KC_F,         KC_G,                 KC_H,         KC_J,        KC_K,       KC_L,     LT(_PROG, KC_SEMICOLON),  _______,
      KC_LSFT,     _______,          KC_X,        KC_C,               KC_V,         KC_B,                 KC_N,         KC_M,        KC_COMM,    KC_DOT,   CTL_SLS,                  _______,
      KC_LEFT_ALT, _______,          _______,     _______,            KC_SPC,                             _______,      _______,     _______,    KC_RBRC,  _______,                  _______,
      _______,     _______,          _______,                                                             _______,      _______,     _______,    _______
  )
};

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRGSCRL:
            // Toggle set_scrolling when DRGSCRL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        case LOWCPI:
            if (record->event.pressed) {
                pointing_device_set_cpi(200);
            } else {
                pointing_device_set_cpi(500);
            }
            break;
        default:
            break;
    }
    return true;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_CONTROL); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}



const rgblight_segment_t PROGMEM std_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 23, HSV_AZURE},
    {23, 44, HSV_AZURE}
);
const rgblight_segment_t PROGMEM prog_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 44, HSV_BLUE}
);
const rgblight_segment_t PROGMEM control_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 44, HSV_GREEN}
);
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 44, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    std_layer,          // Default mode
    prog_layer,    // Overrides caps lock layer
    control_layer,    // Overrides other layers
    gaming_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    //rgblight_layers = rgb_layers;
    rgblight_enable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != _CONTROL) {
        set_scrolling = false;
    }

    //rgb layers
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _PROG));
    rgblight_set_layer_state(2, layer_state_cmp(state, _CONTROL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMG));
    return state;
}
