/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "twpair_on_jis.h"

// clang-format off
enum __layers {
    _Base,
    _Lw,
    _Rs,
    _FN
};

enum custom_keycodes {
  MY_ZKHK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_Base] = LAYOUT( /* Base */
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_DEL,
		KC_ESC,  KC_LGUI, KC_LALT,          LT(1, KC_SPC),    LT(2, KC_GRV),    KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT),

    [_Lw] = LAYOUT( /* Lower
      * |------+------+------+------+------+------+------+------+------+------+------+------|
      * |      |   /  |   *  |   -  |   +  |   =  |   \| |   [{ |   ]} |   `~ |   &  |      |
      * |------+------+------+------+------+-------------+------+------+------+------+------|
      * |      |   %  |   ^  |   !  |   :  |   "  |  ←  |  ↓  |  ↑  |  →  |  DEL |      |
      * |------+------+------+------+------+------|------+------+------+------+------+------|
      * |      |   #  |   $  |   ?  |   ;  |   '  |   _  |   (  |   )  |   @  |      |      |
      * |------+------+------+------+------+------+------+------+------+------+------+------| */
		_______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV,  KC_AMPR, _______,
    _______, KC_PERC, KC_CIRC, KC_EXLM, KC_COLN, KC_DQUO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______,
    _______, KC_HASH, KC_DLR,  KC_QUES, KC_SCLN, KC_QUOT, KC_UNDS, KC_LPRN, KC_RPRN, KC_AT,   _______, _______,
		_______, _______, _______,          _______,          _______,          MO(_FN), _______, _______, _______),

    [_Rs] = LAYOUT( /* Raise */
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  _______,
		_______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE, RGB_TOG,
		_______, _______, _______,          _______,          _______,          _______, _______, _______, RGB_MOD),

    [_FN] = LAYOUT( /* Fn */
		QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, RGB_VAI, _______,
		_______, _______, _______,          _______,          _______,          _______, RGB_SPI, RGB_VAD, RGB_SAI)
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

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, 1, 2, 3);
// }
