#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "raw_hid.h"
#include <string.h>
#define CK_01 MT(MOD_LSFT, KC_A)
#define CK_02 MT(MOD_LALT,KC_R)
#define CK_03 MT(MOD_LGUI,KC_S)
#define CK_04 MT(MOD_LCTL,KC_T)
#define CK_05 LT(3,KC_X)
#define CK_06 LT(4,KC_C)
#define CK_07 LT(5,KC_D)
#define CK_08 MT(MOD_RCTL,KC_N)
#define CK_09 MT(MOD_RGUI,KC_E)
#define CK_10 MT(MOD_RALT,KC_I)
#define CK_11 MT(MOD_RSFT,KC_O)
#define CK_12 LT(8,KC_H)
#define CK_13 LT(7,KC_COMM)
#define CK_14 LT(6,KC_DOT)
#define CK_15 KC_DEL
#define CK_16 LT(1,KC_ENT)
#define CK_17 MO(12)
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

enum custom_keycodes {
  PW_1 = SAFE_RANGE,
  CARET,
  LTX_ALPH, LTX_BETA, LTX_GAMM, LTX_DELT, LTX_EPSI,
  LTX_ZETA, LTX_ETA,  LTX_THET, LTX_IOTA, LTX_KAPP,
  LTX_LAMB, LTX_MU,   LTX_NU,   LTX_XI,   LTX_PI,
  LTX_RHO,  LTX_SIGM, LTX_TAU,  LTX_UPSI, LTX_PHI,
  LTX_CHI,  LTX_PSI,  LTX_OMEG,
  LTX_TO,   LTX_FROM, LTX_DARR, LTX_IARR,
  LTX_LEQ,  LTX_GEQ,  LTX_NEQ,  LTX_APRX, LTX_IN,
  LTX_SUM,  LTX_INT,  LTX_INF,  LTX_PART, LTX_NABL,
  LTX_SUB,  LTX_SUP,
};

enum unicode_names {
    UN_ALPH, UN_ALPH_U,
    UN_BETA, UN_BETA_U,
    UN_GAMM, UN_GAMM_U,
    UN_DELT, UN_DELT_U,
    UN_EPSI, UN_EPSI_U,
    UN_ZETA, UN_ZETA_U,
    UN_ETA,  UN_ETA_U,
    UN_THET, UN_THET_U,
    UN_IOTA, UN_IOTA_U,
    UN_KAPP, UN_KAPP_U,
    UN_LAMB, UN_LAMB_U,
    UN_MU,   UN_MU_U,
    UN_NU,   UN_NU_U,
    UN_XI,   UN_XI_U,
    UN_PI,   UN_PI_U,
    UN_RHO,  UN_RHO_U,
    UN_SIGM, UN_SIGM_U,
    UN_TAU,  UN_TAU_U,
    UN_UPSI, UN_UPSI_U,
    UN_PHI,  UN_PHI_U,
    UN_CHI,  UN_CHI_U,
    UN_PSI,  UN_PSI_U,
    UN_OMEG, UN_OMEG_U,
    UN_TO, UN_FROM, UN_DARR, UN_IARR,
    UN_LEQ, UN_GEQ, UN_NEQ, UN_APRX, UN_IN,
    UN_SUM, UN_INT, UN_INF, UN_PART, UN_NABLA,
    UN_SUB, UN_SUP,
};

const uint32_t PROGMEM unicode_map[] = {
    [UN_ALPH]  = 0x03B1, [UN_ALPH_U]  = 0x0391,
    [UN_BETA]  = 0x03B2, [UN_BETA_U]  = 0x0392,
    [UN_GAMM]  = 0x03B3, [UN_GAMM_U]  = 0x0393,
    [UN_DELT]  = 0x03B4, [UN_DELT_U]  = 0x0394,
    [UN_EPSI]  = 0x03B5, [UN_EPSI_U]  = 0x0395,
    [UN_ZETA]  = 0x03B6, [UN_ZETA_U]  = 0x0396,
    [UN_ETA]   = 0x03B7, [UN_ETA_U]   = 0x0397,
    [UN_THET]  = 0x03B8, [UN_THET_U]  = 0x0398,
    [UN_IOTA]  = 0x03B9, [UN_IOTA_U]  = 0x0399,
    [UN_KAPP]  = 0x03BA, [UN_KAPP_U]  = 0x039A,
    [UN_LAMB]  = 0x03BB, [UN_LAMB_U]  = 0x039B,
    [UN_MU]    = 0x03BC, [UN_MU_U]    = 0x039C,
    [UN_NU]    = 0x03BD, [UN_NU_U]    = 0x039D,
    [UN_XI]    = 0x03BE, [UN_XI_U]    = 0x039E,
    [UN_PI]    = 0x03C0, [UN_PI_U]    = 0x03A0,
    [UN_RHO]   = 0x03C1, [UN_RHO_U]   = 0x03A1,
    [UN_SIGM]  = 0x03C3, [UN_SIGM_U]  = 0x03A3,
    [UN_TAU]   = 0x03C4, [UN_TAU_U]   = 0x03A4,
    [UN_UPSI]  = 0x03C5, [UN_UPSI_U]  = 0x03A5,
    [UN_PHI]   = 0x03C6, [UN_PHI_U]   = 0x03A6,
    [UN_CHI]   = 0x03C7, [UN_CHI_U]   = 0x03A7,
    [UN_PSI]   = 0x03C8, [UN_PSI_U]   = 0x03A8,
    [UN_OMEG]  = 0x03C9, [UN_OMEG_U]  = 0x03A9,
    [UN_TO]    = 0x2192,
    [UN_FROM]  = 0x2190,
    [UN_DARR]  = 0x21D2,
    [UN_IARR]  = 0x21D4,
    [UN_LEQ]   = 0x2264,
    [UN_GEQ]   = 0x2265,
    [UN_NEQ]   = 0x2260,
    [UN_APRX]  = 0x2248,
    [UN_IN]    = 0x2208,
    [UN_SUM]   = 0x2211,
    [UN_INT]   = 0x222B,
    [UN_INF]   = 0x221E,
    [UN_PART]  = 0x2202,
    [UN_NABLA] = 0x2207,
    [UN_SUB]   = 0x2282,
    [UN_SUP]   = 0x2283,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case PW_1:
    if (record->event.pressed) {
      SEND_STRING("150894");
    }
    return false;
  case CARET:
    if (record->event.pressed) {
      // Sendet '^', dann ein Space, dann löscht das Space -> Ergebnis: '^'
      SEND_STRING("^ ");
      tap_code(KC_BSPC);
    }
    return false;
  case LTX_ALPH: if (record->event.pressed) SEND_STRING("\\alpha"); return false;
  case LTX_BETA: if (record->event.pressed) SEND_STRING("\\beta"); return false;
  case LTX_GAMM: if (record->event.pressed) SEND_STRING("\\gamma"); return false;
  case LTX_DELT: if (record->event.pressed) SEND_STRING("\\delta"); return false;
  case LTX_EPSI: if (record->event.pressed) SEND_STRING("\\varepsilon"); return false;
  case LTX_ZETA: if (record->event.pressed) SEND_STRING("\\zeta"); return false;
  case LTX_ETA:  if (record->event.pressed) SEND_STRING("\\eta"); return false;
  case LTX_THET: if (record->event.pressed) SEND_STRING("\\theta"); return false;
  case LTX_IOTA: if (record->event.pressed) SEND_STRING("\\iota"); return false;
  case LTX_KAPP: if (record->event.pressed) SEND_STRING("\\kappa"); return false;
  case LTX_LAMB: if (record->event.pressed) SEND_STRING("\\lambda"); return false;
  case LTX_MU:   if (record->event.pressed) SEND_STRING("\\mu"); return false;
  case LTX_NU:   if (record->event.pressed) SEND_STRING("\\nu"); return false;
  case LTX_XI:   if (record->event.pressed) SEND_STRING("\\xi"); return false;
  case LTX_PI:   if (record->event.pressed) SEND_STRING("\\pi"); return false;
  case LTX_RHO:  if (record->event.pressed) SEND_STRING("\\rho"); return false;
  case LTX_SIGM: if (record->event.pressed) SEND_STRING("\\sigma"); return false;
  case LTX_TAU:  if (record->event.pressed) SEND_STRING("\\tau"); return false;
  case LTX_UPSI: if (record->event.pressed) SEND_STRING("\\upsilon"); return false;
  case LTX_PHI:  if (record->event.pressed) SEND_STRING("\\varphi"); return false;
  case LTX_CHI:  if (record->event.pressed) SEND_STRING("\\chi"); return false;
  case LTX_PSI:  if (record->event.pressed) SEND_STRING("\\psi"); return false;
  case LTX_OMEG: if (record->event.pressed) SEND_STRING("\\omega"); return false;
  case LTX_TO:   if (record->event.pressed) SEND_STRING("\\to"); return false;
  case LTX_FROM: if (record->event.pressed) SEND_STRING("\\leftarrow"); return false;
  case LTX_DARR: if (record->event.pressed) SEND_STRING("\\Rightarrow"); return false;
  case LTX_IARR: if (record->event.pressed) SEND_STRING("\\Leftrightarrow"); return false;
  case LTX_LEQ:  if (record->event.pressed) SEND_STRING("\\leq"); return false;
  case LTX_GEQ:  if (record->event.pressed) SEND_STRING("\\geq"); return false;
  case LTX_NEQ:  if (record->event.pressed) SEND_STRING("\\neq"); return false;
  case LTX_APRX: if (record->event.pressed) SEND_STRING("\\approx"); return false;
  case LTX_IN:   if (record->event.pressed) SEND_STRING("\\in"); return false;
  case LTX_SUM:  if (record->event.pressed) SEND_STRING("\\sum"); return false;
  case LTX_INT:  if (record->event.pressed) SEND_STRING("\\int"); return false;
  case LTX_INF:  if (record->event.pressed) SEND_STRING("\\infty"); return false;
  case LTX_PART: if (record->event.pressed) SEND_STRING("\\partial"); return false;
  case LTX_NABL: if (record->event.pressed) SEND_STRING("\\nabla"); return false;
  case LTX_SUB:  if (record->event.pressed) SEND_STRING("\\subset"); return false;
  case LTX_SUP:  if (record->event.pressed) SEND_STRING("\\supset"); return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    uint8_t data[32] = {0};
    data[0] = 0x4C;
    data[1] = layer;
    raw_hid_send(data, sizeof(data));
    return state;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_Q, KC_W, KC_F, KC_P, KC_B,     KC_J, KC_L, KC_U, DE_Y, TO(9), KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,CK_01,CK_02,CK_03,CK_04,KC_G,     KC_M, CK_08,CK_09,CK_10,CK_11,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,DE_Z, CK_05,CK_06,CK_07,KC_V,     KC_K, CK_12,CK_13,CK_14,KC_TAB,KC_NO,
  // ╰─────────────────────────────────────┤ ├─────────────────────────────────────╯
                       CK_15, KC_NO,KC_NO,     KC_NO,  KC_SPC,
                              CK_16,CK_17,     CK_18
  //                  ╰────────────────────╯ ╰────────────────╯
  ),
  [1] = LAYOUT(
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_ESC,LCTL(KC_Z),LCTL(LSFT(KC_Z)),KC_TAB,KC_NO,    KC_NO,KC_HOME,KC_PGUP,KC_PGDN,KC_END,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,_______,_______,_______,_______,KC_NO,     KC_NO,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,LCTL(KC_LEFT),KC_NO,KC_NO,LCTL(KC_RGHT),KC_NO,
  // ╰─────────────────────────────────────┤ ├─────────────────────────────────────╯
                   _______,_______,_______,    _______,_______,
                            _______,_______,   _______
  //                  ╰────────────────────╯ ╰────────────────╯
  ),

  [2] = LAYOUT(
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,CK_22,CK_23,CK_24,CK_25,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_NO,KC_NO,KC_NO,CK_27,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰─────────────────────────────────────┤ ├─────────────────────────────────────╯
                         KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                               KC_NO, KC_NO,   KC_NO
  //                  ╰────────────────────╯ ╰────────────────╯
  ),

  [3] = LAYOUT(
   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,    KC_NO, DE_HASH, DE_AT, DE_AMPR, DE_PERC, KC_NO,
   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,LSFT(KC_4),RALT(KC_E),CARET,KC_NO,KC_NO,
   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                KC_NO, KC_NO,    KC_NO
   //                            ╰───────────────────────────╯ ╰──────────────────╯
   ),
  [4] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,    KC_NO, DE_COLN, DE_SCLN, DE_PLUS , DE_ASTR, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,LSFT(KC_0),KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [5] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,    KC_NO, LSFT(KC_MINS), LSFT(KC_1), DE_MINS, DE_UNDS , KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [6] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, DE_SS, DE_ADIA, DE_ODIA, DE_UDIA,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO,LSFT(DE_ADIA),LSFT(DE_ODIA),LSFT(DE_UDIA),KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [7] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, DE_QUOT, DE_DQUO, DE_BSLS, DE_SLSH,KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,DE_TILD,DE_PIPE,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [8] = LAYOUT(
   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, DE_LABK, RALT(KC_7),RALT(KC_8),LSFT(KC_8),KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, DE_RABK, RALT(KC_0),RALT(KC_9),LSFT(KC_9),KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                           KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                KC_NO, KC_NO,    KC_NO
   //                            ╰───────────────────────────╯ ╰──────────────────╯
   ),
  [9] = LAYOUT(  // Selector
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, UC_NEXT,TG(14),TG(15),KC_NO,KC_NO,     KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, TO(2), TO(3), TO(4),KC_NO,    KC_NO, TO(5), TO(6), TO(7), TO(8), KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,TO(10),TO(11),TO(12),TG(13),KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [10] = LAYOUT(  // Media
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP, KC_NO,    KC_NO,KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [11] = LAYOUT(  // F-Tasten
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO,KC_NO,KC_F21,KC_F22,KC_NO, 	KC_NO,KC_F23,KC_F24,KC_NO,TO(0),KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,     KC_F16, KC_F17, KC_F18, KC_F19, KC_F20,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [12] = LAYOUT(  // Maus
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,TO(0),KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,CK_29,CK_30,CK_31,CK_32,KC_NO,    KC_NO,CK_33,CK_34,CK_35,CK_36,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_MS_WH_RIGHT, KC_MS_WH_LEFT, KC_MS_WH_DOWN, 	KC_MS_WH_UP,KC_NO, 	KC_NO, 	LCTL(KC_PLUS), 	LCTL(KC_MINUS), LCTL(KC_MS_WH_UP), LCTL(KC_MS_WH_DOWN),KC_NO,
  // ╰─────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,
                                           KC_NO, 	KC_NO, KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [13] = LAYOUT(  // Mac-Overlay
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,_______,LGUI(KC_Z),LGUI(LSFT(KC_Z)),_______,KC_NO,    KC_NO,_______,_______,_______,_______,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,_______,_______,_______,_______,KC_NO,    KC_NO,_______,_______,_______,_______,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,LALT(KC_LEFT),KC_NO,KC_NO,LALT(KC_RGHT),KC_NO,
  // ╰─────────────────────────────────────┤ ├─────────────────────────────────────╯
                   _______,_______,_______,    _______,_______,
                            _______,_______,   _______
  //                  ╰────────────────────╯ ╰────────────────╯
  ),
  [14] = LAYOUT(  // Unicode (TO(0) = Exit auf linkem Daumen)
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,UM(UN_TO),UM(UN_FROM),UM(UN_DARR),UM(UN_IARR),KC_NO,    UM(UN_LEQ),UM(UN_GEQ),UM(UN_NEQ),UM(UN_APRX),UM(UN_IN),KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,UP(UN_THET,UN_THET_U),UP(UN_OMEG,UN_OMEG_U),UP(UN_PHI,UN_PHI_U),UP(UN_PI,UN_PI_U),UP(UN_BETA,UN_BETA_U),    UM(UN_SUM),UM(UN_INT),UP(UN_LAMB,UN_LAMB_U),UP(UN_UPSI,UN_UPSI_U),UP(UN_PSI,UN_PSI_U),KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,UP(UN_ALPH,UN_ALPH_U),UP(UN_RHO,UN_RHO_U),UP(UN_SIGM,UN_SIGM_U),UP(UN_TAU,UN_TAU_U),UP(UN_GAMM,UN_GAMM_U),    UP(UN_MU,UN_MU_U),UP(UN_NU,UN_NU_U),UP(UN_EPSI,UN_EPSI_U),UP(UN_IOTA,UN_IOTA_U),UP(UN_ETA,UN_ETA_U),KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,UP(UN_ZETA,UN_ZETA_U),UP(UN_CHI,UN_CHI_U),UP(UN_XI,UN_XI_U),UP(UN_DELT,UN_DELT_U),UM(UN_PART),    UP(UN_KAPP,UN_KAPP_U),UM(UN_INF),UM(UN_NABLA),UM(UN_SUB),UM(UN_SUP),KC_NO,
  // ╰─────────────────────────────────────┤ ├─────────────────────────────────────╯
                   TO(0),_______,_______,    _______,_______,
                            _______,_______,   _______
  //                  ╰────────────────────╯ ╰────────────────╯
  ),
  [15] = LAYOUT(  // LaTeX (TO(0) = Exit auf linkem Daumen)
  // ╭─────────────────────────────────────╮ ╭─────────────────────────────────────╮
       KC_NO,LTX_TO,LTX_FROM,LTX_DARR,LTX_IARR,KC_NO,    LTX_LEQ,LTX_GEQ,LTX_NEQ,LTX_APRX,LTX_IN,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,LTX_THET,LTX_OMEG,LTX_PHI,LTX_PI,LTX_BETA,    LTX_SUM,LTX_INT,LTX_LAMB,LTX_UPSI,LTX_PSI,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,LTX_ALPH,LTX_RHO,LTX_SIGM,LTX_TAU,LTX_GAMM,    LTX_MU,LTX_NU,LTX_EPSI,LTX_IOTA,LTX_ETA,KC_NO,
  // ├─────────────────────────────────────┤ ├─────────────────────────────────────┤
       KC_NO,LTX_ZETA,LTX_CHI,LTX_XI,LTX_DELT,LTX_PART,    LTX_KAPP,LTX_INF,LTX_NABL,LTX_SUB,LTX_SUP,KC_NO,
  // ╰─────────────────────────────────────┤ ├─────────────────────────────────────╯
                   TO(0),_______,_______,    _______,_______,
                            _______,_______,   _______
  //                  ╰────────────────────╯ ╰────────────────╯
  ),
};
// clang-format on
