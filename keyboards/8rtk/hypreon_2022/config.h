/* Copyright 2021 HarrySizuku
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
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x20F6
#define PRODUCT_ID      0x0003
#define DEVICE_VER      0x0001
#define MANUFACTURER    harrytekey
#define PRODUCT         hypreon
#define DESCRIPTION     60key split keyboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { B7, F0, C6, B4, B5 }
#define MATRIX_COL_PINS { B6, C7, D3, D4, D6, D7 }
#define MATRIX_ROW_PINS_RIGHT { F0, F4, C6, D7, B4 }
#define MATRIX_COL_PINS_RIGHT { B6, B5, F1, C7, D4, D6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D0 // or D1, D2, D3, E6
//#define USE_I2C
#define SPLIT_HAND_PIN E6

#define ENCODERS_PAD_A { F1 }
#define ENCODERS_PAD_B { F4 }
//#define ENCODERS_PAD_A_RIGHT { D2 }
//#define ENCODERS_PAD_B_RIGHT { D3 }
#define ENCODER_RESOLUTION 2
//#define ENCODER_RESOLUTION_RIGHT 2

#define RGB_DI_PIN D5
#define RGBLED_NUM 72
#define RGBLED_SPLIT {36, 36}

#ifdef RGB_DI_PIN
  //   #define RGBLIGHT_HUE_STEP 8
  //   #define RGBLIGHT_SAT_STEP 8
  //   #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 128 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
  /*== all animations enable ==*/
  //   #define RGBLIGHT_ANIMATIONS
  /*== or choose animations ==*/
  //   #define RGBLIGHT_EFFECT_ALTERNATING
  //   #define RGBLIGHT_EFFECT_BREATHING
  //   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  //   #define RGBLIGHT_EFFECT_SNAKE
  //   #define RGBLIGHT_EFFECT_KNIGHT
  //   #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  //   #define RGBLIGHT_EFFECT_RGB_TEST
  //   #define RGBLIGHT_EFFECT_TWINKLE
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT

  #define RGBLIGHT_LAYERS
  #define LED_LAYOUT( \
      L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
      L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
      L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
      L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
      L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45, \
      L50, L51, L52, L53, L54, L55, R50, R51, R52, R53, R54, R55  \
  ) \
  { \
      L00, L01, L02, L03, L04, L05, \
      L55, L54, L53, L52, L51, L50, \
      L40, L41, L42, L43, L44, L45, \
      L35, L34, L33, L32, L31, L30, \
      L20, L21, L22, L23, L24, L25, \
      L15, L14, L13, L12, L11, L10, \
      R00, R01, R02, R03, R04, R05, \
      R50, R51, R52, R53, R54, R55, \
      R45, R44, R43, R42, R41, R40, \
      R30, R31, R32, R33, R34, R35, \
      R25, R24, R23, R22, R21, R20, \
      R10, R11, R12, R13, R14, R15  \
  }
  #define RGBLIGHT_LED_MAP LED_LAYOUT( \
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, \
    64, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 68, \
    65, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 69, \
    66, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 70, \
    67, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 71, \
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)

#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

#define FORCE_NKRO