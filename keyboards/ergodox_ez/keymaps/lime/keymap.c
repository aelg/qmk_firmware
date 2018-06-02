#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


//#include "keymap_german.h"

//#include "keymap_nordic.h"


#define BASE 0 // default layer
#define COLEMAK 1 // default layer
#define SYMB 2 // symbols
#define MOUSE 3 // media keys
#define XMONAD 4 // media keys
#define NAV 5 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
    // left hand
    KC_EQUAL,        KC_EXLM,      KC_AT,            KC_HASH,     KC_DLR,       KC_PERC,  DF(COLEMAK),
    KC_DELETE,       KC_Q,         KC_W,             KC_E,        KC_R,         KC_T,     KC_ESCAPE,
    KC_BSPACE,       KC_A,         LT(NAV,KC_S),       LT(MOUSE,KC_D),  LT(SYMB,KC_F),    KC_G,
    KC_LSHIFT,       CTL_T(KC_Z),  KC_X,             KC_C,        KC_V,         KC_B,     ALL_T(KC_NO),
    LT(SYMB,KC_GRAVE),  KC_QUOTE,     LALT(KC_LSHIFT),  KC_LEFT,     KC_RIGHT,     
                                             ALT_T(KC_APPLICATION),  KC_LGUI,
                                                                     KC_HOME,
                                      LT(SYMB,KC_SPACE),  KC_DELETE,  KC_END,
    
                                        
    // right hand
    DF(COLEMAK),     KC_CIRC,      KC_AMPR,          KC_KP_ASTERISK,  KC_LPRN,          KC_RPRN,              KC_MINUS,
    TG(SYMB),        KC_Y,         KC_U,             KC_I,            KC_O,             KC_P,                 KC_BSLASH,
                     KC_H,         KC_J,             KC_K,            KC_L,             LT(MOUSE,KC_SCOLON),  GUI_T(KC_QUOTE),
    MEH_T(KC_NO),    KC_N,         KC_M,             KC_COMMA,        KC_DOT,           RCTL_T(KC_SLASH),     KC_RSHIFT,
                                   KC_DOWN,          KC_UP,           KC_LBRACKET,      KC_RBRACKET,          MO(SYMB),
    KC_LALT,    CTL_T(KC_ESCAPE),
    KC_PGUP,
    KC_PGDOWN,  KC_TAB,  LT(XMONAD,KC_ENTER)
),

[COLEMAK] = LAYOUT_ergodox(
    // left hand
    KC_EQUAL,        KC_EXLM,      KC_AT,            KC_HASH,         KC_DLR,         KC_PERC,       DF(BASE),
    KC_DELETE,       KC_Q,         KC_W,             KC_F,            KC_P,           KC_G,          TG(SYMB),
    KC_BSPACE,       KC_A,         LT(NAV,KC_R),     LT(MOUSE,KC_S),  LT(SYMB,KC_T),  KC_D,
    KC_LSHIFT,       CTL_T(KC_Z),  KC_X,             KC_C,            KC_V,           KC_B,          ALL_T(KC_NO),
    LT(SYMB,KC_GRAVE),  KC_QUOTE,     LALT(KC_LSHIFT),  KC_LEFT,     KC_RIGHT,     
                                             ALT_T(KC_APPLICATION),  KC_LGUI,
                                                                     KC_HOME,
                                        LT(SYMB,KC_SPACE),  KC_DELETE,  KC_END,
    
                                        
    // right hand
    DF(BASE),        KC_CIRC,      KC_AMPR,          KC_KP_ASTERISK,  KC_LPRN,          KC_RPRN,           KC_MINUS,
    TG(SYMB),        KC_J,         KC_L,             KC_U,            KC_Y,             KC_SCOLON,         KC_BSLASH,
                     KC_H,         KC_N,             KC_E,            KC_I,             LT(MOUSE,KC_O),    GUI_T(KC_QUOTE),
    MEH_T(KC_NO),    KC_K,         KC_M,             KC_COMMA,        KC_DOT,           RCTL_T(KC_SLASH),  KC_RSHIFT,
                                   KC_DOWN,          KC_UP,           KC_LBRACKET,      KC_RBRACKET,MO(SYMB),
    KC_LALT,    CTL_T(KC_ESCAPE),
    KC_PGUP,
    KC_PGDOWN,  KC_TAB,  LT(XMONAD,KC_ENTER)
),
  [SYMB] = LAYOUT_ergodox(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_TRANSPARENT,KC_GRAVE,KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_MOD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_VAI,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_DOT,KC_0,KC_EQUAL,KC_TRANSPARENT,RGB_TOG,RGB_SLD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_HUD,KC_TRANSPARENT),

  [MOUSE] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_LEFT,KC_MS_UP,KC_MS_WH_RIGHT,KC_MS_WH_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_TRANSPARENT,KC_MS_RIGHT,KC_MS_WH_DOWN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_UP,KC_MS_WH_LEFT,KC_MS_UP,KC_MS_WH_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_DOWN,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WWW_BACK),

  [XMONAD] = LAYOUT_ergodox(KC_TRANSPARENT,LGUI(KC_1),LGUI(KC_2),LGUI(KC_3),LGUI(KC_4),LGUI(KC_5),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_6),LGUI(KC_7),LGUI(KC_8),LGUI(KC_9),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_H),LGUI(KC_J),LGUI(KC_K),LGUI(KC_L),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [NAV] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGUP,KC_HOME,KC_UP,KC_END,KC_TRANSPARENT,KC_TRANSPARENT,KC_PGDOWN,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(KC_J),LGUI(KC_K),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LGUI(LSFT(KC_C)),LGUI(LSFT(KC_ENTER))),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
