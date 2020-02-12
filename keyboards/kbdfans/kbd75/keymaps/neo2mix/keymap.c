#include QMK_KEYBOARD_H

#define _ISO     0  // the basic layer
#define _ISM     1  // permanent Layer for mixed ISO/NEO2 functionality
#define _FN      2  // FN function layer
#define _N4      3  // NEO2 layer 4
#define _EMPTY   4  // an empty layer


// Custom macros
#define SPC_N4      LT(_N4,KC_SPC)     // Tap for KC_SPC,  hold for Neo Layer 4
#define NUBS_N4     LT(_N4,KC_NUBS)    // Tap for KC_NUBS, hold for Neo Layer 4
#define BSLS_N4     LT(_N4,KC_BSLS)    // Tap for KC_BSLS, hold for Neo Layer 4
//#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
//#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
//#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ISO] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NLCK,  KC_SLCK,  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   SPC_N4   ,KC_SPC,                       KC_RALT,  MO(_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_ISM] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  BSLS_N4,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  NUBS_N4,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),


  [_FN] = LAYOUT(
    _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLCK,  _______,  KC_PSCR,  KC_PAUS,  KC_INS,
    _______,  TG(_ISM), _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  KC_APP,   _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_BRTG,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_N4] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSLS,  KC_PAST,  KC_PMNS,  _______,  _______,  _______,  _______,
    _______,  KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   KC_PGDN,  _______,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  _______,  _______,  _______,            _______,
    _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   _______,  KC_P4,    KC_P5,    KC_P6,    KC_COMM,  KC_DOT,                       _______,  _______,
    _______,  _______,  _______,  KC_TAB,   _______,  KC_ENT,   _______,  _______,  KC_P1,    KC_P2,    KC_P3,    _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  KC_P0,                        _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_EMPTY] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),
};


/*
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case ISO_LY:
        rgblight_setrgb_blue();
        break;
    case FN_LY:
        rgblight_setrgb_red();
        break;
    case N4_LY:
        rgblight_setrgb_white();
        break;
    default:
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
    return state;
}
*/

  /*
void led_set_user(uint8_t usb_led) {

  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(B0);
    } else {
        writePinHigh(B0);
        }*/

    //if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    //    writePinLow(B2);
    //} else {
    //    writePinHigh(B2);
    //}

  /*
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinLow(B1);
    } else {
        writePinHigh(B1);
    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {
        writePinLow(B3);
    } else {
        writePinHigh(B3);
    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {
        writePinLow(B4);
    } else {
        writePinHigh(B4);
    }

}
  */


//void matrix_init_user(void) {
  //setPinOutput(B2);
  //  setPinOutput(B0);
  //setPinOutput(B1);
  //setPinOutput(B3);
  //setPinOutput(B4);
  //setPinOutput(B5);
  /*
  writePinHigh(B0);
  writePinHigh(B1);
  writePinHigh(B2);
  writePinHigh(B3);
  writePinHigh(B4);
  */
  //}
