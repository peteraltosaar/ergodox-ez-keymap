// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H

// Layers
#define BASE 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3
#define _MOD 4

#define ________ KC_TRNS

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define NAV MO(_NAV)
#define F_NAV LT(NAV, KC_F)

#define MOD MO(_MOD)
#define D_MOD LT(MOD, KC_D)

#define ALT_UP LALT(KC_UP)
#define ALT_DOWN LALT(KC_DOWN)
#define ALTLEFT LALT(KC_LEFT)
#define ALTRGHT LALT(KC_RGHT)
#define GUILEFT LGUI(KC_LEFT)
#define GUIRGHT LGUI(KC_RGHT)

#define BSPWORD LALT(KC_BSPC)
#define DELWORD LALT(KC_DEL)

#define CTL_TAB LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 *
 * ,----------------------------------------------------------------.    ,----------------------------------------------------------------.
 * | Ctrl+Tab |   1    |   2    |   3    |   4    |   5    |        |    |        |   6    |   7    |   8    |   9    |   0    |          |
 * |----------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+----------|
 * |   Tab    |   Q    |   W    |   E    |   R    |   T    |        |    |        |   Y    |   U    |   I    |   O    |   P    |Backspace |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |   Esc    |   A    |   S    |   D    | F/Nav  |   G    |--------|    |--------|   H    |   J    |   K    |   L    |   ;    |    "     |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * | LShift   |   Z    |   X    |   C    |   V    |   B    |        |    |        |   N    |   M    |   ,    |   .    |   /    |          |
 * `----------+--------+--------+--------+--------+-----------------'    `-----------------+--------+--------+--------+--------+----------'
 *   |        |        |        |        | Lower  |                                        | Raise  |        |        |        |        |
 *   `--------------------------------------------'                                        `--------------------------------------------'
 *                                                 ,-----------------.  ,-----------------.
 *                                                 |        |        |  |        |        |
 *                                        ,--------|--------|--------|  |--------+--------+--------.
 *                                        |        |        |        |  |        |        |        |
 *                                        | Space  |        |--------|  |--------|        | Enter  |
 *                                        |        |        |        |  |        |        |        |
 *                                        `--------------------------'  `--------------------------'
 */
[BASE] = LAYOUT_ergodox(

  // left hand
   CTL_TAB,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5, ________,
    KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T, ________,
    KC_ESC,     KC_A,     KC_S,    D_MOD,    F_NAV,     KC_G,
   KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B, ________,
  ________,  KC_LCTL,  KC_LALT,  KC_LGUI,    LOWER,
                                                              ________, ________,
                                                                        ________,
                                                      KC_SPC, ________, ________,

  // right hand
            ________,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, ________,
            ________,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
                          KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,
            ________,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH, ________,
                         RAISE, ________, ________, ________, ________,
  ________, ________,
  ________,
  ________, ________,   KC_ENT

),

/* Lower
 *
 * ,----------------------------------------------------------------.    ,----------------------------------------------------------------.
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+----------|
 * |          |   !    |   @    |   #    |   $    |   %    |        |    |        |   ^    |   &    |   *    |   (    |   )    |          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |--------|    |--------|        |   _    |   +    |   {    |   }    |    |     |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'    `-----------------+--------+--------+--------+--------+----------'
 *   |        |        |        |        |        |                                        |        |        |        |        |        |
 *   `--------------------------------------------'                                        `--------------------------------------------'
 *                                                 ,-----------------.  ,-----------------.
 *                                                 |        |        |  |        |        |
 *                                        ,--------|--------|--------|  |--------+--------+--------.
 *                                        |        |        |        |  |        |        |        |
 *                                        |        |        |--------|  |--------|        |        |
 *                                        |        |        |        |  |        |        |        |
 *                                        `--------------------------'  `--------------------------'
 */
[_LOWER] = LAYOUT_ergodox(

  // left hand
  ________, ________, ________, ________, ________, ________, ________,
  ________,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC, ________,
  ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________,
                                                              ________, ________,
                                                                        ________,
                                                    ________, ________, ________,

  // right hand
            ________, ________, ________, ________, ________, ________, ________,
            ________,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN, ________,
                      ________,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
            ________, ________, ________, ________, ________, ________, ________,
                      ________, ________, ________, ________, ________,
  ________, ________,
  ________,
  ________, ________, ________

),

/* Raise
 *
 * ,----------------------------------------------------------------.    ,----------------------------------------------------------------.
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |--------|    |--------|        |   -    |   =    |   [    |   ]    |    \     |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'    `-----------------+--------+--------+--------+--------+----------'
 *   |        |        |        |        |        |                                        |        |        |        |        |        |
 *   `--------------------------------------------'                                        `--------------------------------------------'
 *                                                 ,-----------------.  ,-----------------.
 *                                                 |        |        |  |        |        |
 *                                        ,--------|--------|--------|  |--------+--------+--------.
 *                                        |        |        |        |  |        |        |        |
 *                                        |        |        |--------|  |--------|        |        |
 *                                        |        |        |        |  |        |        |        |
 *                                        `--------------------------'  `--------------------------'
 */
[_RAISE] = LAYOUT_ergodox(

  // left hand
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________,
                                                              ________, ________,
                                                                        ________,
                                                    ________, ________, ________,

  // right hand
            ________, ________, ________, ________, ________, ________, ________,
            ________, ________, ________, ________, ________, ________, ________,
                      ________,  KC_MINS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
            ________, ________, ________, ________, ________, ________, ________,
                      ________, ________, ________, ________, ________,
  ________, ________,
  ________,
  ________, ________, ________

),

/* Navigation
 *
 * ,----------------------------------------------------------------.    ,----------------------------------------------------------------.
 * |          |        |        |        |        |        |        |    |        |        |        | Alt+Up |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |   Up   |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |F / Nav |        |--------|    |--------|Alt+Left|  Left  |  Down  | Right  |Alt+Rght|          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |Gui+Left|Alt+Down|Gui+Rght|        |          |
 * `----------+--------+--------+--------+--------+-----------------'    `-----------------+--------+--------+--------+--------+----------'
 *   |        |        |        |        |        |                                        |        |        |        |        |        |
 *   `--------------------------------------------'                                        `--------------------------------------------'
 *                                                 ,-----------------.  ,-----------------.
 *                                                 |        |        |  |        |        |
 *                                        ,--------|--------|--------|  |--------+--------+--------.
 *                                        |        |        |        |  |        |        |        |
 *                                        |        |        |--------|  |--------|        |        |
 *                                        |        |        |        |  |        |        |        |
 *                                        `--------------------------'  `--------------------------'
 */
[_NAV] = LAYOUT_ergodox(

  // left hand
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________,    F_NAV, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________,
                                                              ________, ________,
                                                                        ________,
                                                    ________, ________, ________,

  // right hand
            ________, ________, ________,   ALT_UP, ________, ________, ________,
            ________, ________, ________,    KC_UP, ________, ________, ________,
                       ALTLEFT,  KC_LEFT,  KC_DOWN,  KC_RGHT,  ALTRGHT, ________,
            ________, ________,  GUILEFT, ALT_DOWN,  GUIRGHT, ________, ________,
                      ________, ________, ________, ________, ________,
  ________, ________,
  ________,
  ________, ________, ________

),

/* Modification
 *
 * ,----------------------------------------------------------------.    ,----------------------------------------------------------------.
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |--------|    |--------|Bsp Word|Backspce|        | Delete |Del Word|          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'    `-----------------+--------+--------+--------+--------+----------'
 *   |        |        |        |        |        |                                        |        |        |        |        |        |
 *   `--------------------------------------------'                                        `--------------------------------------------'
 *                                                 ,-----------------.  ,-----------------.
 *                                                 |        |        |  |        |        |
 *                                        ,--------|--------|--------|  |--------+--------+--------.
 *                                        |        |        |        |  |        |        |        |
 *                                        |        |        |--------|  |--------|        |        |
 *                                        |        |        |        |  |        |        |        |
 *                                        `--------------------------'  `--------------------------'
 */
[_MOD] = LAYOUT_ergodox(

  // left hand
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________,    D_MOD, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________,
                                                              ________, ________,
                                                                        ________,
                                                    ________, ________, ________,

  // right hand
            ________, ________, ________, ________, ________, ________, ________,
            ________, ________, ________, ________, ________, ________, ________,
                       BSPWORD,  KC_BSPC, ________,   KC_DEL,  DELWORD, ________,
            ________, ________, ________, ________, ________, ________, ________,
                      ________, ________, ________, ________, ________,
  ________, ________,
  ________,
  ________, ________, ________
)

};
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    /*case MDIA:
      ergodox_right_led_2_on();
      break;*/
    default:
      // none
      break;
  }

};

/* <Layer Name>
 *
 * ,----------------------------------------------------------------.    ,----------------------------------------------------------------.
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |--------|    |--------|        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |    |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'    `-----------------+--------+--------+--------+--------+----------'
 *   |        |        |        |        |        |                                        |        |        |        |        |        |
 *   `--------------------------------------------'                                        `--------------------------------------------'
 *                                                 ,-----------------.  ,-----------------.
 *                                                 |        |        |  |        |        |
 *                                        ,--------|--------|--------|  |--------+--------+--------.
 *                                        |        |        |        |  |        |        |        |
 *                                        |        |        |--------|  |--------|        |        |
 *                                        |        |        |        |  |        |        |        |
 *                                        `--------------------------'  `--------------------------'
 */
/*[_LAYER] = LAYOUT_ergodox(

  // left hand
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________, ________, ________,
  ________, ________, ________, ________, ________,
                                                              ________, ________,
                                                                        ________,
                                                    ________, ________, ________,

  // right hand
            ________, ________, ________, ________, ________, ________, ________,
            ________, ________, ________, ________, ________, ________, ________,
                      ________, ________, ________, ________, ________, ________,
            ________, ________, ________, ________, ________, ________, ________,
                      ________, ________, ________, ________, ________,
  ________, ________,
  ________,
  ________, ________, ________

),*/
