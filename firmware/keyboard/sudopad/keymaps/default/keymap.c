#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(KC_X), LCTL(KC_C), LCTL(KC_V)
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("      hi"), false);
    return false;
}
#endif
