/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _QWERT 0 // Keymap _QWERT: QWERTY Base Layer (Default Layer)
#define _FL 1    // Keymap _FL: Function Key Layer
#define _PD1 2   // Keymap _PD1: Productivity Layer 1

// Define Macro Keycodes
enum custom_keycodes {
  EMAIL_XP = SAFE_RANGE,
  MACRO2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERT] = LAYOUT(
//   1        2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17        18
  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NLCK,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN, // 1
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,   KC_PSLS,  KC_PAST,  KC_PMNS, // 2
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS, // 3
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_P4,    KC_P5,    KC_P6,             // 4
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_P1,    KC_P2,    KC_P3,    LT(_PD1, KC_PENT), // 5
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT            // 6

/* Default Keybinds:
-    1        2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17        18
1 KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PRSC,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN, // 1
2 KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS, // 2
3 KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS, // 3
4 KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_P4,    KC_P5,    KC_P6,             // 4
5 KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT, // 5
6 KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT            // 6
*/
  ),

[_FL] = LAYOUT(
//    1        2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17        18
  _______,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLU,  KC_VOLD,  _______,  _______,  _______,  _______,  _______,  _______, // 1
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, // 2
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, // 3
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,           // 4
  _______,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RGB_VAI,  _______,  _______,  _______,  _______, // 5
  _______,  RESET,    _______,                      _______,                                _______,  _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_MOD,  _______,  _______            // 6

/* Default Keybinds:
-     1        2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17        18
1   RESET,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLU,  KC_VOLD,  _______,  _______,  _______,  _______,  _______,  _______, // 1
2 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, // 2
3 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, // 3
4 _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,           // 4
5 _______,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RGB_VAI,  _______,  _______,  _______,  _______, // 5
6 _______,  UC_M_WI,  _______,                      _______,                                _______,  _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_MOD,  _______,  _______            // 6
*/
  ),

[_PD1] = LAYOUT(
//    1        2         3         4         5         6         7         8         9         10        11        12        13        14        15        16        17        18
  XXXXXXX,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLU,  KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, // 1
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, // 2
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, // 3
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,           // 4
  XXXXXXX,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            RGB_VAI,  EMAIL_XP, XXXXXXX,  XXXXXXX,  XXXXXXX, // 5
  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_RMOD, RGB_VAD,  RGB_MOD,  XXXXXXX,  XXXXXXX            // 6
  ),

};

// Macro Execution
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EMAIL_XP:
      if (record->event.pressed) { // when keycode EMAIL_XP is pressed
        SEND_STRING("xp.pk116@gmail.com");
      } else { // when keycode EMAIL_XP is Released

      }
      break;

    case MACRO2:
      if (record->event.pressed) {
      } else {
      }
      break;
  }

  return true;
};

//? Special Key Mappings
/*
RESET: The RESET keybind refers to the keyboard's DFU (Bootloader) mode. Once RESET is triggered the keyboard will enter DFU (Bootloader) mode,
  allowing you to flash a new firmware to the keyboard using the QMK Toolbox. After flashing is successful, unplug and replug the keyboard.
CAPSWRD: Keycode associated with QMK's "Caps Word" Feature (Caps Word must be enabled by adding CAPS_WORD_ENABLE = yes to your rules.mk file)
*/

//? Compiling and Flashing Firmware
/*
1 Make sure you created this new keymap folder using the QMK MSYS command [qmk new-keymap] rather than copy-pasting the default in file explorer.
2 Open QMK MSYS and use the [ qmk compile -kb <keyboard> -km <keymap> ] command.
  2b If you do not want to have to spell out the keyboard and keymap name/path everytime you compile a new edition of your keymap, you can set the
  defaults using [ qmk config user.keyboard=<keyboard name> ] and [ qmk config user.keymap=<keymap name> ].
  2c Once the defaults are set, you only need to type [qmk compile].
3 Now start QMK Toolbox and set the file path of the compiled keymap (C:\Users\<USERNAME>\qmk_firmware\.build\<firmware name>.bin).
4 Set your keyboard to bootloader mode (the GMMK 2's default method is on the Glorious website or use QMK's RESET keycode on your keyboard if
  you've already flashed the keyboard with QMK).
5 You should see a message in QMK Toolbox notifing you that your keyboard has entered DFU (bootloader) mode.
6 Click the "Flash" button and deal with any errors in your code that will undoubtedly arise, then repeat.
*/