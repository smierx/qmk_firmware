#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include <string.h>

#define CK_01 MT(MOD_LSFT, KC_A)
#define CK_02 MT(MOD_LALT,KC_R)
#define CK_03 MT(MOD_LGUI,KC_S)
#define CK_04 MT(MOD_LCTL,KC_T)
#define CK_05 LT(8,KC_X)
#define CK_06 LT(9,KC_C)
#define CK_07 LT(10,KC_D)
#define CK_08 MT(MOD_RCTL,KC_N)
#define CK_09 MT(MOD_RGUI,KC_E)
#define CK_10 MT(MOD_RGUI,KC_E)
#define CK_11 MT(MOD_RSFT,KC_O)
#define CK_12 LT(13,KC_H)
#define CK_13 LT(12,KC_COMM)
#define CK_14 LT(11,KC_DOT)
#define CK_15 KC_DEL
#define CK_16 LT(1,KC_ENT)
#define CK_17 MO(15)
#define CK_18 LT(2,KC_BSPC)
#define CK_19 KC_LEFT
#define CK_20 KC_DOWN
#define CK_21 KC_RGHT
#define CK_22 KC_ESC
#define CK_23 LCTL(KC_X)
#define CK_24 LCTL(KC_C)
#define CK_25 LCTL(KC_V)
#define CK_26 LALT(KC_TAB)
#define CK_27 LCTL(KC_A)
#define CK_28 LALT(LSFT(KC_TAB))
#define CK_29 KC_BTN4
#define CK_30 KC_BTN3
#define CK_31 KC_BTN2
#define CK_32 KC_BTN1
#define CK_33 KC_BTN5
#define CK_34 KC_BTN6
#define CK_35 KC_BTN7
#define CK_36 KC_BTN8
typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP, // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;
enum charybdis_keymap_layers {
  LAYER_BASE = 0,
  LAYER_LOWER,
  LAYER_RAISE,
};

enum {
  TD_EXAMPLE,
  TD_PAREN,
  TD_1_BRACKET,
  TD_2_BRACKET,
  TD_QUOTES,
  TD_EQ_PLUS,
  TD_VERTBSL_QUESTION,
  TD_SLASH,
  TD_AE,
  TD_OE,
  TD_UE,
  TD_LA_RA,
  TD_COMMA_DOT,
  TD_SEMICOLON,
  TD_MINUS,
  TD_PERCENT,
  TD_AT_EXCL,
  TD_TAG_DOLLAR,
  TD_AND_MUL,
  TD_HOME_END
};


typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;
// Tap
td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any
// keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

void dance_open_bracket(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(LSFT(KC_8));
    unregister_code16(LSFT(KC_8));
  } else if (state->count == 2) {
    register_code16(RALT(KC_8));
    unregister_code16(RALT(KC_8));
  } else if (state->count == 3) {
    register_code16(RALT(KC_7));
    unregister_code16(RALT(KC_7));
  } else {
    reset_tap_dance(state);
  }
}
void dance_close_bracket(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(LSFT(KC_9));
    unregister_code16(LSFT(KC_9));
  } else if (state->count == 2) {
    register_code16(RALT(KC_9));
    unregister_code16(RALT(KC_9));
  } else if (state->count == 3) {
    register_code16(RALT(KC_0));
    unregister_code16(RALT(KC_0));
  } else {
    reset_tap_dance(state);
  }
}
typedef struct {
  uint16_t tap;
  uint16_t hold;
  uint16_t held;
} tap_dance_tap_hold_t;

// Tap Dance definitions333333333333
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_EXAMPLE] = ACTION_TAP_DANCE_DOUBLE(KC_P1, KC_P2),
    [TD_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_EQ_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_EQL), // ##
    [TD_1_BRACKET] = ACTION_TAP_DANCE_FN(dance_open_bracket),
    [TD_2_BRACKET] = ACTION_TAP_DANCE_FN(dance_close_bracket),
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(DE_QUOT, DE_DQUO),           // ##
    [TD_VERTBSL_QUESTION] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_BSLS), // ##
    [TD_SLASH] = ACTION_TAP_DANCE_DOUBLE(DE_SLSH, DE_BSLS),
    [TD_AE] = ACTION_TAP_DANCE_DOUBLE(DE_ADIA, LSFT(DE_ADIA)),
    [TD_OE] = ACTION_TAP_DANCE_DOUBLE(DE_ODIA, LSFT(DE_ODIA)),
    [TD_UE] = ACTION_TAP_DANCE_DOUBLE(DE_UDIA, LSFT(DE_UDIA)),
    [TD_LA_RA] = ACTION_TAP_DANCE_DOUBLE(DE_LABK, DE_RABK),
    [TD_COMMA_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
    [TD_SEMICOLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_MINS)),
    [TD_PERCENT] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_6), KC_PERC),
    [TD_AT_EXCL] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_1), LSFT(KC_2)),
    [TD_TAG_DOLLAR] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_3), LSFT(KC_4)),
    [TD_AND_MUL] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_7), LSFT(KC_8)),
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};
enum custom_keycodes {
  PW_1 = SAFE_RANGE,
  CARET,
  // Weitere Macros hier
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case PW_1:
    if (record->event.pressed) {
      SEND_STRING("150894");
      layer_off(30);
    }
    return false;
  case CARET:
    if (record->event.pressed) {
    // Sendet '^', dann ein Space, dann löscht das Space -> Ergebnis: '^'
    SEND_STRING("^ ");
    tap_code(KC_BSPC);
}
    return false; // wir haben die Taste verarbeitet
  }
  return true;
}
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_Q, KC_W, KC_F, KC_P, KC_B,     KC_J, KC_L, KC_U, DE_Y, KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  CK_01,CK_02,CK_03,CK_04,KC_G,     KC_M, CK_08,CK_09,CK_10,CK_11,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  DE_Z, CK_05,CK_06,CK_07,KC_V,     KC_K, CK_12,CK_13,CK_14,KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         CK_15,CK_16, CK_17,         CK_18, KC_SPC
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [1] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,     KC_NO,CK_19,CK_20,KC_UP,CK_21,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [2] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       CK_22,CK_23,CK_24,CK_25,KC_NO,    KC_NO,CK_26,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  KC_NO,KC_NO,KC_NO,CK_27,KC_NO,    KC_NO,CK_28,KC_NO,KC_NO,KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [3] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [4] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [5] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [6] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [7] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [8] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [9] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [10] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [11] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [12] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [13] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  [14] = LAYOUT(     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

};
// clang-format on
