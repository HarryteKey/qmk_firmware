#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define _BS 0
#define _SH 1
#define _LW 2
#define _RS 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KANA = SAFE_RANGE,
  AT,
  CARET,
  COLON,
};

#define KC_LOWR LT(_LW, KC_MHEN) // タップで無変換 ホールドでLower
#define KC_RASE LT(_RS, KC_HENK) // タップで変換   ホールドでRaise
#define KC_SH LM(_SH, MOD_LSFT)  // シフトレイヤー

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
  * |      | Win  | Alt  | Alt+`|Lower |    Space    |Raise |   -  | Left | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_BS] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    MO(_SH), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT, \
    KC_LSFT, KC_LWIN, KC_LALT, KC_ZKHK, MO(_LW), KC_SPC,           MO(_RS), KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* _SH(Shift)
  * ,-----------------------------------------------------------------------------------.
  * | ESC  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bcsp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   :  | Ent  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  | Up   | Shift|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      | Win  | Alt  | Alt+`|Lower | Space       |Raise |   _  | Left | Down |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_SH] = LAYOUT( \
    _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, _______, \
    _______, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______, \
    _______, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), JP_COLN, _______, \
    _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_A), S(KC_A), _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______, S(KC_RO),_______, _______, _______  \
  ),

  /* _LW(Lower)
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   ~  |   $  |   %  |   ^  |   @  |   =  |   (  |   )  |   &  |   |  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   !  |   ?  |   -  |   +  |   #  |   "  |   {  |   }  |   /  |   \  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | XXX  | XXX  |   /  |   *  | XXX  |   '  |   [  |   ]  | XXX  |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LW] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, JP_TILD, JP_DLR,  JP_PERC, JP_CIRC, JP_AT,   JP_EQL,  JP_LPRN, JP_RPRN, JP_AMPR, JP_PIPE, _______, \
    _______, JP_EXLM, JP_QUES, JP_MINS, JP_PLUS, JP_HASH, JP_DQUO, JP_LCBR, JP_RCBR, JP_SLSH, JP_BSLS, _______, \
    _______, XXXXXXX, XXXXXXX, JP_SLSH, JP_ASTR, XXXXXXX, JP_QUOT, JP_LBRC, JP_RBRC, XXXXXXX, _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______  \
  ),

   /* _RS(Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  F12 |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  | XXX  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_RS] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,  \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______  \
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
      return false;
      break;
    case AT:
      if (record->event.pressed) {
        // when keycode is pressed
        unregister_code(KC_LSFT);
        register_code(KC_LBRC);
      } else {
        // when keycode is released
        unregister_code(KC_LBRC);
        register_code(KC_LSFT);
      }
      return false;
      break;
    case CARET:
      if (record->event.pressed) {
        // when keycode is pressed
        unregister_code(KC_LSFT);
        register_code(KC_EQL);
      } else {
        // when keycode is released
        unregister_code(KC_EQL);
        register_code(KC_LSFT);
      }
      return false;
      break;
      case COLON:
      if (record->event.pressed) {
        // when keycode is pressed
        unregister_code(KC_LSFT);
        register_code(KC_QUOT);
      } else {
        // when keycode is released
        unregister_code(KC_QUOT);
        register_code(KC_LSFT);
      }
      return false;
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
