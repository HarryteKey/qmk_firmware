#include QMK_KEYBOARD_H

enum custom_keycodes {
  MY_ZKHK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_F10, 
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP, 
		KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          XXXXXXX, KC_ENT,  KC_PGDN,
		KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   KC_DEL, 
		KC_GRV,           KC_LGUI, KC_LALT,                   LT(1, KC_SPC),                               MY_ZKHK, MO(2),            KC_LEFT, KC_DOWN, KC_RGHT),

	[1] = LAYOUT(
           /* |------+------+------+------+------+------+------+------+------+------+------+------|
            * |      |   `~ |   @  |   #  |   $  |   %  |   ^  |   &  |   '  |   "  |   \  |      |
            * |------+------+------+------+------+-------------+------+------+------+------+------|
            * | CAPS |   !  |   ?  |   (  |   )  |   =  |  ←  |  ↓  |  ↑  |  →  |  BS  |  DEL |
            * |------+------+------+------+------+------|------+------+------+------+------+------|
            * |      |   [  |   ]  |   {  |   }  |   /  |   *  |   +  |   -  |   _  |   ;  |      |
            * |------+------+------+------+------+------+------+------+------+------+------+------| */
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          KC_GRV,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_QUOT, KC_DQUO, KC_BSLS, _______, _______, _______,          _______, 
		KC_CAPS,          KC_EXLM, KC_QUES, KC_LPRN, KC_RPRN, KC_EQL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_DEL,           _______, _______, _______, 
		_______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_SLSH, KC_ASTR, KC_PLUS, KC_MINS, KC_UNDS, KC_SCLN, _______,                   _______, _______, 
		_______,          _______, _______,                   _______,                                     _______, _______,          _______, _______, _______),

	[2] = LAYOUT(
    QK_BOOT,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR, 
		_______,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______,          KC_HOME, 
		_______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_DEL,           _______, _______, KC_END, 
		_______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE, _______,                   _______, KC_INS, 
		TG(3),            _______, _______,                   _______,                                     _______, _______,          _______, _______, _______),

  [3] = LAYOUT(
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(2), 
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, 
		_______,          _______, _______,                   KC_SPC,                                      _______, _______,          _______, _______, _______)
};

static bool lt_pressed = false;
static uint16_t lt_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
  switch (keycode) {
    case MY_ZKHK:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("`"));
      }
      return false;
      break;

    case LT(1, KC_SPC):
      if (record->event.pressed) {
        lt_pressed = true;
        lt_pressed_time = record->event.time;
      } else {
        lt_pressed = false;
      }
      return true; //通常の動作
        //https://docs.qmk.fm/#/custom_quantum_functions?id=programming-the-behavior-of-any-keycode
        //https://blog.magcho.com/2020/4/qmk_firmwareでctrlとの同時押しをカスタマイズする/
      break;

    case KC_ENT:
      if (record->event.pressed) {
        if (lt_pressed && (timer_elapsed(lt_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_SPC);
          //register_code(KC_ENT);
        } else {
          //register_code(KC_ENT);
        }
      } else {
        //unregister_code(KC_ENT);
      }
      return true; //falseでregister_code()すると意図しないスペースが入る
      break;
  }

  return true;
}
