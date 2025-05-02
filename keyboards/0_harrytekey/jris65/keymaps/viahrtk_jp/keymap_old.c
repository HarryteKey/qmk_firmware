#include QMK_KEYBOARD_H
#include "twpair_on_jis.h"

enum custom_keycodes {
  MY_ZKHK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_DEL, 
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP, 
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_BSLS, KC_ENT,  KC_PGDN,
		KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_ZKHK,          KC_UP,   KC_DEL, 
		KC_GRV,  KC_LGUI, KC_LALT,                            LT(2, KC_SPC),                               MO(1),   KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT),

	[1] = LAYOUT(
     /* |------+------+------+------+------+------+------+------+------+------+------+------|
      * |      |   /  |   *  |   -  |   +  |   =  |   \| |   [{ |   ]} |   `~ |   &  |      |
      * |------+------+------+------+------+-------------+------+------+------+------+------|
      * |      |   %  |   ^  |   !  |   :  |   "  |  ←  |  ↓  |  ↑  |  →  |  DEL |      |
      * |------+------+------+------+------+------|------+------+------+------+------+------|
      * |      |   #  |   $  |   ?  |   ;  |   '  |   _  |   (  |   )  |   @  |      |      |
      * |------+------+------+------+------+------+------+------+------+------+------+------| */
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV,  KC_AMPR, _______, _______, _______, _______, 
		_______, KC_PERC, KC_CIRC, KC_EXLM, KC_COLN, KC_DQUO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______, _______, _______, _______, 
		_______, _______, KC_HASH, KC_DLR,  KC_QUES, KC_SCLN, KC_QUOT, KC_UNDS, KC_LPRN, KC_RPRN, KC_AT,   _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______),

	[2] = LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR, 
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_HOME, 
		KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______, _______, _______, KC_END, 
		_______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_INS, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______),

	[3] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
  switch (keycode) {
    case MY_ZKHK:
      if (record->event.pressed) {
        tap_code(KC_GRV);
      }
      return false;
      break;    
  }

  // type writer pairing on jis keyboard
  if (!twpair_on_jis(keycode, record)) return false;

  return true;
}