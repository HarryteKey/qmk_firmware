/* Copyright 2018-2020 eswai <@eswai>
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

/*

  OSで日本語キーボード(logical bit pairing)と設定/認識されているキーボードで、
  USキーキャップの文字、記号(typewriter pairing)を正しく出力する。

  例: Shift + 2 で @ を入力する

  変換された文字はキーリピートが無効です。

*/

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

const uint16_t us2jis[][2] = {
  {KC_LPRN, JP_LPRN},
  {KC_RPRN, JP_RPRN},
  {KC_AT,   JP_AT},
  {KC_LBRC, JP_LBRC},
  {KC_RBRC, JP_RBRC},
  {KC_LCBR, JP_LCBR},
  {KC_RCBR, JP_RCBR},
  //{KC_MINS, JP_MINS},
  {KC_EQL,  JP_EQL},
  {KC_BSLS, JP_BSLS},
  //{KC_SCLN, JP_SCLN},
  {KC_QUOT, JP_QUOT},
  {KC_GRV,  JP_GRV},
  {KC_PLUS, JP_PLUS},
  {KC_COLN, JP_COLN},
  {KC_UNDS, JP_UNDS},
  {KC_PIPE, JP_PIPE},
  {KC_DQT,  JP_DQUO},
  {KC_ASTR, JP_ASTR},
  {KC_TILD, JP_TILD},
  {KC_AMPR, JP_AMPR},
  {KC_CIRC, JP_CIRC},
};

/*
  //us配列:シフト状態 jis認識:別シフト の記号
  {KC_GRV,  S(KC_LBRC)}, // `
  {KC_AMPR, S(KC_6)},    // &
  {KC_ASTR, S(KC_QUOT)}, // *
  {KC_LPRN, S(KC_8)},    // (
  {KC_RPRN, S(KC_9)},    // )
  {KC_UNDS, S(KC_INT1)}, // _
  {KC_PLUS, S(KC_SCLN)}, // +
  {KC_LCBR, S(KC_RBRC)}, // {
  {KC_RCBR, S(KC_NUHS)}, // }
  {KC_PIPE, S(KC_INT3)}, // |
  {KC_DQT,  S(KC_2)},    // "

  //us配列:シフト状態 jis認識:非シフト の記号
  {KC_AT,   KC_LBRC}, // @
  {KC_CIRC, KC_EQL},  // ^
  {KC_COLN, KC_QUOT}, // :

  //us配列:非シフト状態 jis認識:別シフト の記号
  {KC_TILD, S(KC_EQL)},  // ~
  {KC_EQL,  S(KC_MINS)}, // =
  {KC_QUOT, S(KC_7)},    // '

  //us配列:非シフト状態 jis認識:非別シフト の記号
  {KC_LBRC, KC_RBRC}, // [
  {KC_RBRC, KC_NUHS}, // ]
  {KC_BSLS, KC_INT1}, // (backslash)
*/

bool twpair_on_jis(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;

  uint16_t skeycode; // シフトビットを反映したキーコード
  bool lshifted = get_mods() & MOD_BIT(KC_LSFT); // シフトキーの状態

  if (lshifted) {
    skeycode = QK_LSFT | keycode;
  } else {
    skeycode = keycode;
  }

  for (int i = 0; i < sizeof(us2jis) / sizeof(us2jis[0]); i++) {
    if (us2jis[i][0] == skeycode) {
      unregister_code(KC_LSFT);
      if ((us2jis[i][1] & QK_LSFT) == QK_LSFT) {
        register_code(KC_LSFT);
        tap_code(us2jis[i][1]);
        unregister_code(KC_LSFT);
      } else {
        tap_code(us2jis[i][1]);
      }
      if (lshifted) register_code(KC_LSFT);
      return false;
    }
  }

  return true;
}