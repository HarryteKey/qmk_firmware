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
#include QMK_KEYBOARD_H

#include "analog.h"
#include "pointing_device.h"
#include <print.h>

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    CALIB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        MO(_FN), CALIB,
        KC_TAB,  KC_SPC
    ),
    [_FN] = LAYOUT(
        QMKBEST, QMKURL,
        RESET,   KC_B
    )
};

// Set Parameters
uint16_t minAxisX = 190;  // Depends on each stick
uint16_t maxAxisX = 835;
uint16_t minAxisY = 210;
uint16_t maxAxisY = 800;

float maxCursorSpeed = 0.2;
float precisionSpeed = 0.01;

int8_t xPolarity = 1;
int8_t yPolarity = 1;
int8_t hPolarity = 1;
int8_t vPolarity = -1;

uint8_t cursorPollingTime = 10;
uint8_t scrollPollingTime = 100;

int16_t xOrigin, yOrigin;

uint16_t lastCursor = 0;

bool isCalib = false;
uint16_t lastCalib = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
        case CALIB:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                isCalib = !isCalib;
                if (isCalib == true) { 
                    print("calibration start\n");
                    minAxisX = maxAxisX = minAxisY = maxAxisY = 500;
                } else {
                    print("calibration end\n"); 
                    uprintf("minAxisX is %d \n", minAxisX);
                    uprintf("maxAxisX is %d \n", maxAxisX);
                    uprintf("minAxisY is %d \n", minAxisY);
                    uprintf("maxAxisY is %d \n", maxAxisY);
                }
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

//joystick
int16_t axisCoordinate(uint8_t pin, uint16_t origin) {
    int8_t  direction;
    int16_t distanceFromOrigin;
    int16_t range;

    int16_t position = analogReadPin(pin);

    if (origin == position) {
        return 0;
    } else if (origin > position) {
        if (pin == (uint8_t)XJOY_PIN) {
            distanceFromOrigin = origin - position;
            range              = origin - minAxisX;
            direction          = -1;
        } else {
            distanceFromOrigin = origin - position;
            range              = origin - minAxisY;
            direction          = -1;            
        }
    } else {
        if (pin == (uint8_t)XJOY_PIN) {
            distanceFromOrigin = position - origin;
            range              = maxAxisX - origin;
            direction          = 1;
        } else {
            distanceFromOrigin = position - origin;
            range              = maxAxisY - origin;
            direction          = 1;         
        }
    }

    float   percent    = (float)distanceFromOrigin / range;
    int16_t coordinate = (int16_t)(percent * 127);
    if (coordinate < 0) {
        return 0;
    } else if (coordinate > 127) {
        return 127 * direction;
    } else {
        return coordinate * direction;
    }
}

int8_t axisToMouseComponent(uint8_t pin, int16_t origin, float maxSpeed, int8_t polarity) {
    int coordinate = axisCoordinate(pin, origin);
    if (coordinate == 0) {
        return 0;
    } else {
        float percent = (float)coordinate / 127;
        return percent * maxSpeed * polarity * abs(coordinate);
    }
}

void pointing_device_task(void) {
    report_mouse_t report = pointing_device_get_report();

    // todo read as one vector
    if (isCalib == true){
        if (timer_elapsed(lastCalib) > cursorPollingTime) {
            lastCalib = timer_read();
            int16_t xAxis = analogReadPin(XJOY_PIN);
            int16_t yAxis = analogReadPin(YJOY_PIN);
            if (xAxis < minAxisX) { minAxisX = xAxis; }
            if (xAxis > maxAxisX) { maxAxisX = xAxis; }
            if (yAxis < minAxisY) { minAxisY = yAxis; }
            if (yAxis > maxAxisY) { maxAxisY = yAxis; }
        }
    } else {
        if (layer_state_is(_FN)) {
            if (timer_elapsed(lastCursor) > scrollPollingTime) {
                lastCursor = timer_read();
                report.h   = axisToMouseComponent(XJOY_PIN, xOrigin, precisionSpeed, hPolarity);
                report.v   = axisToMouseComponent(YJOY_PIN, yOrigin, precisionSpeed, vPolarity);
            }
            /*if (timer_elapsed(lastCursor) > cursorTimeout) {
                    lastCursor = timer_read();
                    report.x   = axisToMouseComponent(XJOY_PIN, xOrigin, precisionSpeed, xPolarity);
                    report.y   = axisToMouseComponent(YJOY_PIN, yOrigin, precisionSpeed, yPolarity);
            }*/
        } else {
            if (timer_elapsed(lastCursor) > cursorPollingTime) {
                lastCursor = timer_read();
                report.x   = axisToMouseComponent(XJOY_PIN, xOrigin, maxCursorSpeed, xPolarity);
                report.y   = axisToMouseComponent(YJOY_PIN, yOrigin, maxCursorSpeed, yPolarity);
            }
        }
    }

    if ( readPin(JOYSTICK_PIN) == 0x00 ) {
        report.buttons |= MOUSE_BTN1;
    } else {
        report.buttons &= ~MOUSE_BTN1;
    }

    pointing_device_set_report(report);
    pointing_device_send();
}

void matrix_init_user(void) {
    // init pin
    setPinInputHigh(JOYSTICK_PIN);
    // Account for drift
    xOrigin = analogReadPin(XJOY_PIN);
    yOrigin = analogReadPin(YJOY_PIN);
}