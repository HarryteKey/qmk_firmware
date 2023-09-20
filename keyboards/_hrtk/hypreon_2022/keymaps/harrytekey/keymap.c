#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define _BS 0
#define _SH 1
#define _LW 2
#define _RS 3
#define _GM 4
#define _GL 5

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  AT = SAFE_RANGE,
  CARET,
  COLON,
  ANIMTOG,
  LEDTOG,
  RAINBOW,
  STATIC,
  LOWER,
  RAISE,
  GAME,
};

#define SHIFT LM(_SH, MOD_LSFT) // Shift Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _BS(Base)
  * ,-----------------------------------------------------------------------------------.
  * | Game |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bcsp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  | Ent  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |  Up  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | ESC  | Win  | Alt  | ZKHK | Lower| Space| Shift| Raise|   -  | Left | Down | Right|
  * `-----------------------------------------------------------------------------------'
  */
  [_BS] = LAYOUT( \
    GAME,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    SHIFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_DEL,  \
    KC_ESC, KC_LWIN, KC_LALT, KC_ZKHK,  MO(_LW), KC_SPC,  SHIFT,   MO(_RS), KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* _SH(Shift)
  * ,-----------------------------------------------------------------------------------.
  * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   :  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |   _  |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_SH] = LAYOUT( \
    _______, _______, AT,      _______, _______, _______, CARET,   JP_6,    JP_COLN, JP_8,    JP_9,    _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, COLON,   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, JP_BSLS, _______, _______, _______  \
  ),

  /* _LW(Lower)
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   /  |   *  |   -  |   +  |   =  |   \  |   {  |   }  |   ^  |   %  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   1  |   2  |   3  |   4  |   5  |   "  |   (  |   )  |   !  |   ?  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |   6  |   7  |   8  |   9  |   0  |   '  |   [  |   ]  |   @  |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LW] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, JP_SLSH, JP_ASTR, KC_MINS, JP_PLUS, JP_EQL,  JP_BSLS, JP_LCBR, JP_RCBR, JP_CIRC, JP_PERC, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JP_DQUO, JP_LPRN, JP_RPRN, JP_EXLM, JP_QUES, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_QUOT, JP_LBRC, JP_RBRC, JP_AT,   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* _RS(Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |  F11 |  F12 |   #  |   &  |   |  |   $  |   ~  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |  F1  |  F2  |  F3  |  F4  |  F5  | Left | Down |Right |  Up  |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F6  |  F7  |  F8  |  F9  |  F10 |AniTOG|RgbTOG|Rainbw|Static|      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_RS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_F11,  KC_F12,  JP_HASH, JP_AMPR, JP_PIPE, JP_DLR,  JP_TILD, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  ANIMTOG, LEDTOG,  RAINBOW, STATIC,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* _GM(Game)
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bcsp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Ctrl |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  | Ent  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |  Up  |   /  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Caps |   m  | Alt  | Esc  | Lower| Space| Zkhk |   ^  |   -  | Left | Down | Right|
  * `-----------------------------------------------------------------------------------'
  */
  [_GM] = LAYOUT( \
    GAME,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
    KC_CAPS, KC_M,    KC_LALT, KC_ESC,  MO(_GL), KC_SPC,  JP_ZKHK, JP_CIRC, JP_MINS, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* _GL(Game Layer)
  * ,-----------------------------------------------------------------------------------.
  * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   i  |  Up  |      |      |      | Pscr | Slck | Pause|   @  |   [  |  F12 |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      | Left | Down | Right|Rokuga|Screen| Ins  | Home | PgUp |   :  |   ]  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |RGBoff|  Win | Del  |  End | PgDn |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_GL] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    _______, KC_I,    KC_UP,   _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, JP_AT,   JP_LBRC, KC_F12,  \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, A(KC_0),A(KC_DEL),KC_INS,  KC_HOME, KC_PGUP, JP_COLN, JP_RBRC, _______, \
    _______, _______, _______, _______, LEDTOG, KC_LWIN, KC_DEL,  KC_END,  KC_PGDN, JP_BSLS, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  )
};

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
static bool led_anim = true;
static bool led_GM = false;
static bool led_GL = false;
static int gradient_num = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AT:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        register_code(KC_LSFT);
      } else {
      }
      return false;
      break;
    case CARET:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_EQL);
        unregister_code(KC_EQL);
        register_code(KC_LSFT);
      } else {
      }
      return false;
      break;
    case COLON:
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_QUOT);
        unregister_code(KC_QUOT);
        register_code(KC_LSFT);
      } else {
      }
      return false;
      break;

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

    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LW);
      } else {
        layer_off(_LW);
        if ( lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM) ) {
          register_code(KC_MHEN);
          unregister_code(KC_MHEN);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RS);
      } else {
        layer_off(_RS);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_HENK);
          unregister_code(KC_HENK);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        rgblight_enable_noeeprom();
        led_GM = rgblight_get_layer_state(4);
        led_GL = rgblight_get_layer_state(5);
        if (led_GM||led_GL == true){
          rgblight_disable_noeeprom();
        }
        layer_invert(_GM);
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
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
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
/*{12,  1, HSV_WHITE},
  {13,  1, HSV_RED},
  {14,  1, HSV_CORAL},
  {15,  1, HSV_ORANGE},
  {16,  1, HSV_GOLDENROD},

  {22,  1, HSV_GOLD},
  {23,  1, HSV_YELLOW},
  {24,  1, HSV_CHARTREUSE},
  {25,  1, HSV_GREEN},
  {26,  1, HSV_SPRINGGREEN},

  {32,  1, HSV_TURQUOISE},
  {33,  1, HSV_TEAL},
  {34,  1, HSV_CYAN},
  {35,  1, HSV_AZURE},
  {36,  1, HSV_BLUE},

  {42,  1, HSV_PURPLE},
  {43,  1, HSV_MAGENTA},
  {44,  1, HSV_PINK}*/
);

const rgblight_segment_t PROGMEM rgb_sh[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_AZURE}
);

const rgblight_segment_t PROGMEM rgb_lw[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_TEAL}
);

const rgblight_segment_t PROGMEM rgb_rs[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_gm[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_GOLDENROD}
);

const rgblight_segment_t PROGMEM rgb_gl[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  12, HSV_GOLDENROD},
  {35, 1,  HSV_RED},
  {36, 1,  HSV_ORANGE},
  {45, 1,  HSV_GREEN},
  {46, 1,  HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_caps[] = RGBLIGHT_LAYER_SEGMENTS(
  {52, 1,  HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  rgb_bs,
  rgb_sh,
  rgb_lw,
  rgb_rs,
  rgb_gm,
  rgb_gl,
  rgb_caps
);

void keyboard_post_init_user(void) {
  rgblight_layers = rgb_layers;
  rgblight_disable_noeeprom();
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(6, led_state.caps_lock);
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BS));
  rgblight_set_layer_state(1, layer_state_cmp(state, _SH));
  rgblight_set_layer_state(2, layer_state_cmp(state, _LW));
  rgblight_set_layer_state(3, layer_state_cmp(state, _RS));
  rgblight_set_layer_state(4, layer_state_cmp(state, _GM));
  rgblight_set_layer_state(5, layer_state_cmp(state, _GL));
  return state;
}