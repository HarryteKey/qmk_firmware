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
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    HarryteKey
#define PRODUCT         HS28
#define DESCRIPTION     28key gaming keyboard

/* key matrix size */
#define MATRIX_ROWS 5
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
#define MATRIX_ROW_PINS { F5, F4, F1, F0, C6 }
#define MATRIX_COL_PINS { C7, E6, B3, D7, B4, B5 }
#define UNUSED_PINS 

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
//#define SOFT_SERIAL_PIN D0 // or D1, D2, D3, E6

// #define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 3

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
  #define RGBLED_NUM 34
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 128 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING

//#define DRIVER_LED_TOTAL 34
#define RGBLIGHT_LAYERS

#define LED_LAYOUT( \
    l00, l01, l02, l03, l04, l05, \
    l10, l11, l12, l13, l14, l15, \
    l20, l21, l22, l23, l24, l25, \
    l30, l31, l32, l33, l34, l35, \
    l40, l41, l42, l43, l44, l45, \
    l50,           l51, l52, l53 \
) \
{ \
    l00, l01, l02, l03, l04, l05, \
    l10, l11, l12, l13, l14, l15, \
    l25, l24, l23, l22, l21, l20, \
    l30, l31, l32, l33, l34, l35, \
    l45, l44, l43, l42, l41, l40, \
    l50, l51, l52, l53 \
}

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
  28, 29, 30, 31, 32, 33, \
  20, 0,  1,  2,  3,  4,  \
  21, 5,  6,  7,  8,  9,  \
  22, 10, 11, 12, 13, 14, \
  23, 15, 16, 17, 18, 19, \
  24,         25, 26, 27 )

#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

#define FORCE_NKRO