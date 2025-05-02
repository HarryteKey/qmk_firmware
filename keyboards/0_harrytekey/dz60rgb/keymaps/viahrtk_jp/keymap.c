#include QMK_KEYBOARD_H
#include "twpair_on_jis.h"

enum custom_keycodes {
  MY_ZKHK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MY_ZKHK,          KC_UP,   KC_DEL,
        KC_ESC,  KC_LGUI, KC_LALT,                            LT(2, KC_SPC),             MO(3),   TG(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, 
        _______, _______, _______, KC_SPC,                                               _______, _______, _______, _______, _______
    ),

    [2] = LAYOUT(
     /* |------+------+------+------+------+------+------+------+------+------+------+------|
      * |      |   /  |   *  |   &  |   +  |   =  |   _  |   [  |   ]  |   {  |   }  |      |
      * |------+------+------+------+------+-------------+------+------+------+------+------|
      * | CAPS |   %  |   ^  |   \| |   ;: |   !  |  ←  |  ↓  |  ↑  |  →  |  BS  |  DEL |
      * |------+------+------+------+------+------|------+------+------+------+------+------|
      * |      |   #  |   $  |   `~ |   '" |   ?  |   -  |   (  |   )  |   @  |      |      |
      * |------+------+------+------+------+------+------+------+------+------+------+------| */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______,
        _______, KC_SLSH, KC_ASTR, KC_AMPR, KC_PLUS, KC_EQL,  KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PGUP, KC_PGDN, KC_PSCR, 
        KC_CAPS, KC_PERC, KC_CIRC, KC_BSLS, KC_SCLN, KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_DEL,           _______, 
        _______, KC_HASH, KC_DLR,  KC_GRV,  KC_QUOT, KC_QUES, KC_UNDS, KC_LPRN, KC_RPRN, KC_AT,   _______,          _______, KC_INS, 
        _______, _______, _______, _______,                                              _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, 
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, 
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_DEL,           _______, 
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE,          RGB_VAI, RGB_TOG, 
        _______, _______, _______, _______,                                              _______, _______, RGB_SPI, RGB_VAD, RGB_MOD
    )
};

static bool lt_pressed = false;
static uint16_t lt_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
  switch (keycode) {
    case MY_ZKHK:
      if (record->event.pressed) {
        tap_code(KC_GRV);
      }
      return false;
      break;

    case LT(2, KC_SPC):
      if (record->event.pressed) {
        lt_pressed = true;
        lt_pressed_time = record->event.time;
      } else {
        lt_pressed = false;
      }
      return true;
      break;

    case KC_ENT:
      if (record->event.pressed) {
        if (lt_pressed && (timer_elapsed(lt_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_SPC);
        }
      }
      return true;
      break;
  }

  // type writer pairing on jis keyboard
  if (!twpair_on_jis(keycode, record)) return false;

  return true;
}
