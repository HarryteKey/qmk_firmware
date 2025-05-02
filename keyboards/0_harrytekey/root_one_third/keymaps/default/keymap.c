#include QMK_KEYBOARD_H

#define _BS 0
#define _LW 1
#define _RS 2
#define _AD 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KANA = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _BS(Base)
  * ,-----------------------------------------------------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bcsp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Ent  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | Up   | Shift|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Adj  | Win  | Alt  | Alt+`|Lower |    Space    |Raise |   -  | Left | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_BS] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT, \
    TG(_AD), KC_LWIN, KC_LALT, KANA,    MO(_LW), KC_SPC,           MO(_RS), KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* _LW(Lower)
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   `  |   ~  |   %  |   ^  | XXX  |   =  |   (  |   )  |   &  |   |  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   !  |   ?  |   -  |   +  | XXX  |   "  |   {  |   }  |   /  |   \  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | XXX  | XXX  |   /  |   *  | XXX  |   '  |   [  |   ]  | XXX  |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LW] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_GRV,  KC_TILD, KC_PERC, KC_CIRC, XXXXXXX, KC_EQL,  KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE, _______, \
    _______, KC_EXLM, KC_QUES, KC_MINS, KC_PLUS, XXXXXXX, KC_DQUO, KC_LCBR, KC_RCBR, KC_SLSH, KC_BSLS, _______, \
    _______, XXXXXXX, XXXXXXX, KC_SLSH, KC_ASTR, XXXXXXX, KC_QUOT, KC_LBRC, KC_RBRC, XXXXXXX, _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______  \
  ),

  /* _RS(Raise)
  * ,-----------------------------------------------------------------------------------.
  * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_RS] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______  \
  ),

  /* _AD(Adjust)
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |   /  |   *  |  BS  |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |   7  |   8  |   9  |   -  |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |   4  |   5  |   6  |   +  |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |   1  |   2  |   3  | Enter|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |  Adj |      |      |   0  |   .  |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_AD] = LAYOUT( \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    KC_TRNS, _______, _______, KC_0,    KC_PDOT, _______,          _______, _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KANA:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING(SS_LALT("`"));
      } else {
        // when keycode is released
      }
    break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
