#include QMK_KEYBOARD_H

#define _BS 0
#define _LW 1
#define _RS 2
#define _AD 3

// Defines the keycodes used by our macros in process_record_user
/*enum custom_keycodes {

};*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _BS(Base)
  * ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |
  * |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |
  * |------+------+------+------+------+------|
  * | Ctrl |   A  |   S  |   D  |   F  |   G  |
  * |------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |
  * |------+------+------+------+------+------|
  * | Adj  |             | Raise| Lower| Space|
  * `-----------------------------------------'
  */
  [_BS] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,\
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,\
    KC_LALT,                   MO(_RS), MO(_LW), KC_SPC\
  ),

  /* _LW(Lower)
  * ,-----------------------------------------.
  * | ESC  |   6  |   7  |   8  |   9  |   0  |
  * |------+------+------+------+------+------|
  * | Tab  |      |      |      |      |      |
  * |------+------+------+------+------+------|
  * | Ctrl |  F1  |  F2  |  F3  |  F4  |  F5  |
  * |------+------+------+------+------+------|
  * | Shift|  F6  |  F7  |  F8  |  F9  | F10  |
  * |------+------+------+------+------+------|
  * | Adj  |             | Lower| Raise| Space|
  * `-----------------------------------------'
  */
  [_LW] = LAYOUT( \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,\
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,\
    _______,                   _______, _______, _______\
  ),

  /* _RS(Raise)
  * ,-----------------------------------------.
  * |      |      |      |      |Rokuga|Screen|
  * |------+------+------+------+------+------|
  * |      |      |      |      |      | PGUP |
  * |------+------+------+------+------+------|
  * |      |      |      |      |      | PGDN |
  * |------+------+------+------+------+------|
  * |      | ALT_Z| ALT_X| ALT_C|RGBoff| Win  |
  * |------+------+------+------+------+------|
  * |      |             | Lower| Raise| Space|
  * `-----------------------------------------'
  */
  [_RS] = LAYOUT( \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, A(KC_0), A(KC_DEL),\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,\
    _______, A(KC_Z), A(KC_X), A(KC_C), RGB_TOG, KC_LWIN,\
    _______,                   _______, _______, _______\
  ),

  /* _AD(Adjust)
  * ,-----------------------------------------.
  * |      |      |      |      |      |      |
  * |------+------+------+------+------+------|
  * |      |      |      |      |      |      |
  * |------+------+------+------+------+------|
  * |      |      |      |      |      |      |
  * |------+------+------+------+------+------|
  * |      |      |      |      |      |      |
  * |------+------+------+------+------+------|
  * |      |             | Lower| Raise| Space|
  * `-----------------------------------------'
  */
  [_AD] = LAYOUT( \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    _______,                   _______, _______, _______\
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

const rgblight_segment_t PROGMEM rgb_bs[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 5, HSV_GREEN},
  {5, 15, HSV_TURQUOISE},
  {20, 8, HSV_PINK},
  {28, 6, HSV_AZURE}
);

const rgblight_segment_t PROGMEM rgb_lw[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 10, HSV_GREEN},
  {10, 10, HSV_YELLOW},
  {20, 8, HSV_PINK},
  {28, 6, HSV_CYAN}
);

const rgblight_segment_t PROGMEM rgb_rs[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 1, HSV_RED},
  {4, 1, HSV_ORANGE},
  {15, 3, RGB_AZURE},
  {18, 1, HSV_GREEN},
  {19, 1, HSV_BLUE},
  {0, 3, HSV_TURQUOISE},
  {5, 10, HSV_TURQUOISE},
  {13, 2, HSV_TURQUOISE},
  {20, 8, HSV_PINK},
  {28, 6, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_ad[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 5, HSV_GREEN},
  {5, 15, HSV_TURQUOISE},
  {20, 8, HSV_PINK},
  {28, 6, HSV_AZURE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  rgb_bs,
  rgb_lw,
  rgb_rs,
  rgb_ad
);

void keyboard_post_init_user(void) {
  rgblight_layers = rgb_layers;
  rgblight_disable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BS));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LW));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RS));
  rgblight_set_layer_state(3, layer_state_cmp(state, _AD));
  return state;
}
