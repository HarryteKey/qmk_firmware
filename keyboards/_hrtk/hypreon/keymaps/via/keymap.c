#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

#define _BS 0
#define _LW 1
#define _RS 2
#define _AD 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  ANIMTOG = SAFE_RANGE,
  LEDTOG,
  RAINBOW,
  STATIC
};

#define SHIFT LM(_SH, MOD_LSFT) // Shift Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _BS(Base)
  * ,-----------------------------------------------------------------------------------.
  * | Adj  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bcsp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  | Ent  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |  Up  | Shift|
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ESC  | Win  | Alt  | ZKHK | Lower| Space| Shift| Raise|   -  | Left | Down | Right|
  * `-----------------------------------------------------------------------------------'
  */
  [_BS] = LAYOUT( \
    TG(_AD), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT, \
    KC_ESC,  KC_LWIN, KC_LALT, JP_ZKHK, MO(_LW), KC_SPC,  KC_LSFT, MO(_RS), KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* _LW(Lower)
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   1  |   2  |   3  |   4  |   5  |   \  |   {  |   }  |   ^  |   %  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   6  |   7  |   8  |   9  |   0  |   "  |   (  |   )  |   !  |   ?  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   -  |   /  |   *  |   +  |   =  |   '  |   [  |   ]  |   @  |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LW] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSLS, KC_LCBR, KC_RCBR, KC_CIRC, KC_PERC, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQUO, KC_LPRN, KC_RPRN, KC_EXLM, KC_QUES, _______, \
    _______, KC_MINS, KC_SLSH, KC_ASTR, KC_PLUS, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC, KC_AT,   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* _RS(Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |   #  |   &  |   |  |   $  |   ~  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Left | Down |Right |  Up  |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F11 |  F12 |      |      |      |AniTOG|RgbTOG|Rainbw|Static|      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_RS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_HASH, KC_AMPR, KC_PIPE, KC_DLR,  KC_TILD, _______, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, KC_F11,  KC_F12,  _______, _______, _______, ANIMTOG, LEDTOG,  RAINBOW, STATIC,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* _AD(Adjust)
  * ,-----------------------------------------------------------------------------------.
  * | Adj  |      |      |   /  |   *  |  BS  |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |   7  |   8  |   9  |   -  |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |   4  |   5  |   6  |   +  |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |   1  |   2  |   3  | Enter|      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |   0  |   .  |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_AD] = LAYOUT( \
    KC_TRNS, XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PMNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, KC_0,    KC_PDOT, _______, _______, _______, _______, _______, _______, _______, _______  \
  )
};

static bool led_anim = true;
static int gradient_num = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ANIMTOG:
      if (record->event.pressed) {
        if (led_anim == true) {
          rgblight_sethsv_noeeprom(0, 0, 0);
          led_anim = false;
        } else {
          rgblight_reload_from_eeprom();
          rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
          led_anim = true;
        }
      } else {
      }
      return false;
      break;
    case LEDTOG:
      if (record->event.pressed) {
        rgblight_toggle_noeeprom();
      } else {
      }
      return false;
      break;
    case RAINBOW:
      if (record->event.pressed) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
      } else {
      }
      return false;
      break;
    case STATIC:
      if (record->event.pressed) {
        if (rgblight_get_mode() >= RGBLIGHT_MODE_STATIC_GRADIENT && rgblight_get_mode() <= RGBLIGHT_MODE_STATIC_GRADIENT+9) {
          gradient_num = (gradient_num + 1) % 10;
          rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + gradient_num);
        } else {
          gradient_num = 0;
          rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
        }
      } else {
      }
      return false;
      break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder
      if (clockwise) {
        register_code(KC_VOLU);
      } else {
        register_code(KC_VOLD);
      }
    }/*else if (index == 1) { // Second encoder 
      if (clockwise) {
        tap_code(KC_WH_U);
      } else {
        tap_code(KC_WH_D);
      }
    }*/
    return true;
}

void led_set_user(uint8_t usb_led) {

}

const rgblight_segment_t PROGMEM rgb_bs[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_AZURE}
);

const rgblight_segment_t PROGMEM rgb_lw[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_TEAL}
);

const rgblight_segment_t PROGMEM rgb_rs[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_ad[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_GOLDENROD}
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