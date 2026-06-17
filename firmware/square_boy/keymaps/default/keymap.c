// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// DEAR PERSON WHO IS LOOKING AT THIS FOR STARDANCE:
// pleese check this carefully :)
// it is my first time using qmk, and i have no idea about c either
// have a lovely day :D

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *      col2row
     *              pin 9 | pin 11 | pin 10
     *      pin 4
     *      pin 7
     *      pin 8
     *
     */

    /*
    matrix

    */
    [_BASE] = LAYOUT(
        LGUI(KC_Q), LGUI(KC_E), LGUI(KC_ENT),
        LGUI(KC_B), LCTL(KC_Z), LGUI(KC_Y),
        LCTL(KC_C), LSFT(LCTL(KC_C)), LCTL(KC_V)
    ),

    [_NUMPAD] = LAYOUT(
        KC_P7, KC_P8, KC_P9,
        KC_P4, KC_P5, KC_P6,
        KC_P1, KC_P2, KC_P3
    ),
};

//const uint16_t PROGMEM encoder_map[][1][2] = {
  //  [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
//};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [_BASE]   = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_NUMPAD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};



#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
