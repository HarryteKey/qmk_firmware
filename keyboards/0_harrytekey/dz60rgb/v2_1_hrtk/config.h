/* Copyright 2021 trankimtung
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

#ifdef RGB_MATRIX_ENABLE
# define RGB_MATRIX_SLEEP // turn off effects when suspended
// #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
# define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_PIXEL_RAIN
# define ENABLE_RGB_MATRIX_PIXEL_RAIN
# define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

# define RGB_MATRIX_DEFAULT_HUE 128
# define RGB_MATRIX_DEFAULT_SAT 255
/*
  #define RGB_MATRIX_KEYRELEASES // リアクティブエフェクトは（キー押下ではなく）キーリリースに反応します
  #define RGB_MATRIX_TIMEOUT 0 // RGB が自動的にオフになるまで待機するミリ秒数
  #define RGB_MATRIX_SLEEP // サスペンド時にエフェクトをオフにする
  #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // タスク実行ごとのアニメーションで処理する LED の数を制限します (キーボードの応答性が向上します)
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // アニメーションが LED を更新する頻度をミリ秒単位で制限します。 16 (16ms) は 60fps に制限することに相当します (キーボードの応答性が向上します)。
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // LED の最大輝度を 255 のうち 200 に制限します。定義されていない場合、最大輝度は 255 に設定されます
  #define RGB_MATRIX_DEFAULT_ON true // 何も設定されていない場合は、デフォルトの有効状態を設定します
  #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // 何も設定されていない場合は、デフォルトのモードを設定します
  #define RGB_MATRIX_DEFAULT_HUE 0 // 何も設定されていない場合は、デフォルトの色相値を設定します
  #define RGB_MATRIX_DEFAULT_SAT 255 // 何も設定されていない場合は、デフォルトの彩度値を設定します
  #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // デフォルトの明るさの値を設定します（何も設定されていない場合）
  #define RGB_MATRIX_DEFAULT_SPD 127 // 何も設定されていない場合は、デフォルトのアニメーション速度を設定します
  #define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL // デフォルトの LED フラグを設定します (何も設定されていない場合)
  #define RGB_MATRIX_DISABLE_KEYCODES // キーコードによる RGB マトリックスの制御を無効にします (機能を制御するにはコード関数を使用する必要があります)
  #define RGB_MATRIX_SPLIT { X, Y } // (オプション) 分割キーボードの場合、各半分に接続されている LED の数。 X = 左、Y = 右。
                                        // リアクティブエフェクトが有効な場合は、SPLIT_TRANSPORT_MIRROR も有効にする必要があります。
  #define RGB_TRIGGER_ON_KEYDOWN // キーを押したときに RGB キープレス イベントをトリガーします。 これにより、RGB コントロールの応答性が向上します。 これにより、一部のボードでは RGB が正しく機能しなくなる可能性があります
*/
/*
  RGB_MATRIX_NONE = 0、
  RGB_MATRIX_SOLID_COLOR = 1, // 静的単一色相、速度サポートなし
  RGB_MATRIX_ALPHAS_MODS, // 静的二重色相、速度は二次色相の色相です
  RGB_MATRIX_GRADIENT_UP_DOWN, // 上から下への静的なグラデーション、速度はグラデーションの変化量を制御します
  RGB_MATRIX_GRADIENT_LEFT_RIGHT, // 左から右への静的グラデーション、速度はグラデーションの変化量を制御します
  RGB_MATRIX_BREATHING, // 単一色相の明るさ循環アニメーション
  RGB_MATRIX_BAND_SAT, // 単一の色相バンドのフェード彩度を左から右にスクロール
  RGB_MATRIX_BAND_VAL, // 単一の色相バンドのフェード輝度を左から右にスクロール
  RGB_MATRIX_BAND_PINWHEEL_SAT, // 単一の色相 3 ブレードの回転風車が彩度をフェードします
  RGB_MATRIX_BAND_PINWHEEL_VAL, // 単一の色合いの 3 ブレードの回転風車が明るさをフェードします
  RGB_MATRIX_BAND_SPIRAL_SAT, // 単一の色相の回転スパイラルフェード彩度
  RGB_MATRIX_BAND_SPIRAL_VAL, // 単一の色相の回転スパイラルにより明るさが薄れます
  RGB_MATRIX_CYCLE_ALL, // フルキーボードの単色の色合いをフルグラデーションで循環させる
  RGB_MATRIX_CYCLE_LEFT_RIGHT, // 左から右への完全なグラデーションスクロール
  RGB_MATRIX_CYCLE_UP_DOWN, // フルグラデーションで上から下にスクロール
  RGB_MATRIX_CYCLE_OUT_IN, // フルグラデーションでアウトからインにスクロール
  RGB_MATRIX_CYCLE_OUT_IN_DUAL, // 完全なデュアル グラデーションがアウトからインにスクロールします
  RGB_MATRIX_RAINBOW_MOVING_CHEVRON, // フル グラデーション シェブロン形状で左から右にスクロール
  RGB_MATRIX_CYCLE_PINWHEEL, // キーボードの中心を中心にフルグラデーションで回転する風車
  RGB_MATRIX_CYCLE_SPIRAL, // キーボードの中心を中心にフルグラデーションで回転するスパイラル
  RGB_MATRIX_DUAL_BEACON, // キーボードの中心を中心に回転するフル グラデーション
  RGB_MATRIX_RAINBOW_BEACON, // キーボードの中心を中心に回転する完全にきついグラデーション
  RGB_MATRIX_RAINBOW_PINWHEELS, // キーボードの半分を回転させる完全なデュアル グラデーション
  RGB_MATRIX_FLOWER_BLOOMING, // 前半は左から右にスクロールし、後半は右から左にスクロールする完全にきついグラデーション
  RGB_MATRIX_RAINDROPS, // 単一のキーの色相をランダムに変更します
  RGB_MATRIX_JELLYBEAN_RAINDROPS, // 単一キーの色相と彩度をランダムに変更します
  RGB_MATRIX_HUE_BREATHING, // 色相は同時にわずかに上にシフトし、その後元に戻ります
  RGB_MATRIX_HUE_PENDULUM, // 色相は波状にわずかに右にシフトし、その後左に戻ります
  RGB_MATRIX_HUE_WAVE, // 色相はわずかに上にシフトし、右の波のように下に戻ります
  RGB_MATRIX_PIXEL_FRACTAL, // 単一の色相のフラクタルで満たされたキーが端まで水平方向にパルスします
  RGB_MATRIX_PIXEL_FLOW, // ランダムな色合いの LED 配線に沿ったパルス RGB フロー
  RGB_MATRIX_PIXEL_RAIN, // ランダムな色合いでキーをランダムに明るくします
  RGB_MATRIX_TYPING_HEATMAP, // WPM はどのくらい熱いですか!
  RGB_MATRIX_DIGITAL_RAIN, // あの有名なコンピューター シミュレーション
  RGB_MATRIX_SOLID_REACTIVE_SIMPLE, // キーをパルス的に押して色相と値を設定し、値をフェードアウトします
  RGB_MATRIX_SOLID_REACTIVE, // 静的な単一の色相、パルスキーを押して色相をシフトし、その後現在の色相にフェードします
  RGB_MATRIX_SOLID_REACTIVE_WIDE, // 単一のキーを押すと色相と値がパルスになり、値がフェードアウトします
  RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE, // 複数のキーを押すと色相と値がパルスになり、値がフェードアウトします
  RGB_MATRIX_SOLID_REACTIVE_CROSS, // 色相と値は、単一のキーを押すと同じ列と行をパルスし、値がフェードアウトします
  RGB_MATRIX_SOLID_REACTIVE_MULTICROSS, // 色相と値は、複数のキーを押すと同じ列と行をパルスし、値がフェードアウトします
  RGB_MATRIX_SOLID_REACTIVE_NEXUS, // 単一のキーを押すと、同じ列と行で色相と値が脈動し、値がフェードアウトします
  RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS, // 複数のキーを押すと、同じ列と行で色相と値が脈動し、値がフェードアウトします
  RGB_MATRIX_SPLASH, // 単一のキーを押すと完全なグラデーションと値がパルス化され、その後値がフェードアウトします
  RGB_MATRIX_MULTISPLASH, // 複数のキーを押すと完全なグラデーションと値がパルスされ、値がフェードアウトします
  RGB_MATRIX_SOLID_SPLASH, // キーを 1 回押すと色相と値が脈動し、値がフェードアウトします
  RGB_MATRIX_SOLID_MULTISPLASH, // 複数のキーを押すと色相と値が脈動し、値がフェードアウトします
  RGB_MATRIX_STARLIGHT, // LED はユーザーが設定した色を維持しながら、明るさを変えてランダムにオン/オフします
  RGB_MATRIX_STARLIGHT_DUAL_HUE, // LED はさまざまな明るさでランダムにオン/オフし、ユーザー設定の色相を +- 30 で変更します
  RGB_MATRIX_STARLIGHT_DUAL_SAT, // LED はさまざまな明るさでランダムにオン/オフし、ユーザー設定の彩度を +- 30 で変更します
  RGB_MATRIX_RIVERFLOW, // 呼吸アニメーションを変更し、川の流れをシミュレートするためにキーの位置に応じてオフセットのアニメーションを変更します。
  RGB_MATRIX_EFFECT_MAX
*/

#    define DRIVER_ADDR_1 0b1010000
#    define DRIVER_COUNT 1
#    define RGB_MATRIX_LED_COUNT 63
#endif

#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif

// hrtk
#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1
#define DEBOUNCE 2
#define DEBOUNCE_TYPE sym_eager_pk

//#define DEBUG_MATRIX_SCAN_RATE
