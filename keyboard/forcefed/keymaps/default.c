// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "forcefed.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

// ideas
// alt + esc = alt/tab
// alt + esc = alt/tab
// sft + esc = tilde
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_DOT}, //13
  {KC_LCTRL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_DOT},    //13
  {KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DOT}, //12
  {KC_DOT,    KC_LGUI, KC_LALT, KC_LBRC, KC_SPC,  KC_RBRC,  KC_TRNS, KC_TRNS, KC_SPC,  KC_RBRC, KC_TRNS, RESET,   KC_DOT}   //9
},
[_RS] = { /* [> RAISE <] */
  {KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_DOT}, //13
  {KC_LCTRL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_DOT},    //13
  {KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DOT}, //12
  {KC_DOT,    KC_LGUI, KC_LALT, KC_LBRC, KC_SPC,  KC_RBRC,  KC_TRNS, KC_TRNS, KC_SPC,  KC_RBRC, KC_TRNS, RESET,   KC_DOT}   //9
},
[_LW] = { /* [> LOWER <] */
  {KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_DOT}, //13
  {KC_LCTRL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_DOT},    //13
  {KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DOT}, //12
  {KC_DOT,    KC_LGUI, KC_LALT, KC_LBRC, KC_SPC,  KC_RBRC,  KC_TRNS, KC_TRNS, KC_SPC,  KC_RBRC, KC_TRNS, RESET,   KC_DOT}   //9
}};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TAP_KEY(2, KC_SPACE),
    [2] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
