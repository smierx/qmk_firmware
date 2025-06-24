/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terKC of the GNU General Public License as published by
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
#include <string.h>
#include "keymap_german.h"
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

enum { TD_EXAMPLE, TD_PAREN, TD_1_BRACKET, TD_2_BRACKET, TD_QUOTES, TD_EQ_PLUS, TD_VERTBSL_QUESTION, TD_SLASH, TD_AE, TD_OE, TD_UE, TD_LA_RA, TD_COMMA_DOT, TD_SEMICOLON, TD_MINUS, TD_PERCENT, TD_AT_EXCL, TD_TAG_DOLLAR, TD_AND_MUL, TD_HOME_END };

enum { BASE, SPECIAL, MOUSE, FKEYS, MEDIA, SPECIAL2, NUMBERS, QWERTY };

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;
// Tap
td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
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
    [TD_EXAMPLE]          = ACTION_TAP_DANCE_DOUBLE(KC_P1, KC_P2),
    [TD_PAREN]            = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_EQ_PLUS]          = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_EQL), //##
    [TD_1_BRACKET]        = ACTION_TAP_DANCE_FN(dance_open_bracket),
    [TD_2_BRACKET]        = ACTION_TAP_DANCE_FN(dance_close_bracket),
    [TD_QUOTES]           = ACTION_TAP_DANCE_DOUBLE(DE_QUOT, DE_DQUO), //##
    [TD_VERTBSL_QUESTION] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_BSLS), //##
    [TD_SLASH]            = ACTION_TAP_DANCE_DOUBLE(DE_SLSH, DE_BSLS),
    [TD_AE]               = ACTION_TAP_DANCE_DOUBLE(DE_ADIA, LSFT(DE_ADIA)),
    [TD_OE]               = ACTION_TAP_DANCE_DOUBLE(DE_ODIA, LSFT(DE_ODIA)),
    [TD_UE]               = ACTION_TAP_DANCE_DOUBLE(DE_UDIA, LSFT(DE_UDIA)),
    [TD_LA_RA]            = ACTION_TAP_DANCE_DOUBLE(DE_LABK, DE_RABK),
    [TD_COMMA_DOT]        = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
    [TD_SEMICOLON]        = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_MINUS]            = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_MINS)),
    [TD_PERCENT]          = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_6), KC_PERC),
    [TD_AT_EXCL]          = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_1), LSFT(KC_2)),
    [TD_TAG_DOLLAR]       = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_3), LSFT(KC_4)),
    [TD_AND_MUL]          = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_7), LSFT(KC_8)),
    [TD_HOME_END]         = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};
enum custom_keycodes {
    PW_1 = SAFE_RANGE,
    PW_2,
    PW_3,
    PW_4
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
        case PW_2:
            if (record->event.pressed) {
                SEND_STRING("jenny2911xD!");
                layer_off(30);
            }
            return false;
        case PW_3:
            if (record->event.pressed) {
                SEND_STRING("#jenny2911xD!#");
                layer_off(30);
            }
            return false;
        case PW_4:
            if (record->event.pressed) {
                SEND_STRING("igelbrink23061982xD!");
                layer_off(30);
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_TURQUOISE);
            break;
        case SPECIAL:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_BLUE);  
            break;
        case MOUSE:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_ORANGE);
            break;
        case FKEYS:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GOLD);
            break;
        case MEDIA:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);  
            break;
        case SPECIAL2:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_WHITE);
            break;
        case NUMBERS:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);  
            break;
        case QWERTY:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);  
            break;
        case 8:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_YELLOW);
            break;
        case 9:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_AZURE);
            break;
        case 10:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_RED);
            break;
        case 11:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);  
            break;
        case 12:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);  
            break;
        case 13:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_GREEN);  
            break;
        case 14:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_RED);
            break;
        case 15:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_PURPLE);
            break;
        default:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(HSV_WHITE);  // weiß
            break;
    }
    return state;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
  // ╭──────────────────────────────														────────────────────────╮ ╭───────────────────────────────────────────────                                     ───────╮
       KC_NO,KC_NO,	            KC_NO, 		        KC_NO, 		        KC_NO, 	 	        KC_NO, 						TG(15),TG(14),     		KC_NO,            KC_NO,  		    KC_NO,  			DPI_MOD,
  // ├──────────────────────────────														────────────────────────┤ ├───────────────────────────────────────────────                                     ───────┤
       KC_NO,KC_Q,    			KC_W,    			KC_F,    			KC_P,    			KC_B,                       KC_J, KC_L,    			KC_U,    		  DE_Y,    			KC_NO,		DPI_RMOD,
  // ├──────────────────────────────														────────────────────────┤ ├───────────────────────────────────────────────                                     ───────┤
       KC_NO,MT(MOD_LSFT,KC_A), MT(MOD_LALT,KC_R), 	MT(MOD_LGUI,KC_S), 	MT(MOD_LCTL,KC_T),  KC_G,                       KC_M, MT(MOD_RCTL,KC_N),MT(MOD_RGUI,KC_E),MT(MOD_RALT,KC_I),MT(MOD_RSFT,KC_O), 	KC_NO,
  // ├──────────────────────────────														────────────────────────┤ ├───────────────────────────────────────────────                                     ───────┤
       KC_NO,DE_Z,    			 LT(8,KC_X),    			 LT(9,KC_C),    			 LT(10,KC_D),    			KC_V,                       KC_K, LT(13,KC_H), 			LT(12,KC_COMM),  		  LT(11,KC_DOT), 			KC_NO, 		KC_NO,
  // ╰───────────────────────────────      													────────────────────── ─┤ ├───────────────────────────────────────────────                                     ───────╯
                                									   				KC_DEL, KC_NO,            KC_NO,    KC_NO,  KC_SPC,
                                          											LT(SPECIAL,KC_ENT), MO(MOUSE),      LT(SPECIAL2,KC_BSPC)
  //                            												   ╰───────────     ────────────────╯ ╰─────────────   ─────╯
  ),

    [SPECIAL] = LAYOUT(
    // ╭───────────────────────────────────────────		───────────╮ ╭──────────────────────────────────────────────────────╮
        KC_NO,KC_NO,  KC_NO,	 KC_NO, 	KC_NO, 	      KC_NO, 		KC_NO, 	 KC_NO, 	KC_NO,     KC_NO,  	 KC_NO,  KC_NO,
    // ├───────────────────────────────────────────		───────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO,KC_NO,  KC_NO,KC_NO,KC_NO,   KC_NO, 		KC_NO, KC_NO, 	KC_NO,   KC_NO,  KC_NO,KC_NO,
    // ├───────────────────────────────────────────		───────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,   KC_NO, 		KC_NO, KC_LEFT, 	KC_DOWN,   KC_UP,	 KC_RGHT,KC_NO,
    // ├───────────────────────────────────────────		───────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO,KC_NO,KC_NO,	 KC_NO,KC_NO,KC_NO, 		KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,  KC_NO,
    // ╰───────────────────────────────────────────		───────────┤ ├──────────────────────────────────────────────────────╯
                                            KC_NO,    KC_NO, KC_NO,     KC_NO, KC_NO,
                                                      KC_NO, KC_NO,     KC_NO
    //                            	   ╰───────────────────────────╯ ╰──────────────────╯
    ),

  [SPECIAL2] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO, KC_NO, 	KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_ESC,LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_NO, 	KC_NO,LALT(KC_TAB),      KC_NO,KC_NO,KC_NO,KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_1,  KC_2,      KC_3,      KC_4,      KC_5, 	KC_6, KC_7,	             KC_8, KC_9, KC_0, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_NO, 	KC_NO,     LCTL(KC_A),KC_NO,    KC_NO,LALT(LSFT(KC_TAB)),KC_NO,KC_NO,KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                               KC_NO, KC_NO,    KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
	[MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO,	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 				KC_NO, KC_NO, 	KC_NO,KC_NO,KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 			KC_NO, KC_NO, 	KC_NO, 	KC_NO,	KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_BTN4, 	KC_BTN3, KC_BTN2, KC_BTN1, 	KC_NO, 			KC_NO, 	KC_BTN5, 	KC_BTN6, 	KC_BTN7, KC_BTN8, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO,  	KC_MS_WH_RIGHT, KC_MS_WH_LEFT, KC_MS_WH_DOWN, 	KC_MS_WH_UP,KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, KC_NO, KC_NO,KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,
                                           KC_NO, 	KC_NO, KC_NO
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
	[FKEYS] = LAYOUT( KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[MEDIA] = LAYOUT( KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[NUMBERS]  = LAYOUT( KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[QWERTY]  = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[8] =LAYOUT(
                 // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                      KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
                 // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                      KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,LSFT(KC_4),      RALT(KC_E),KC_CIRC,KC_NO,KC_NO,
                 // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, DE_HASH, DE_AT, DE_AMPR, DE_PERC, KC_NO,
                 // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                      KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
                 // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                                         KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                              KC_NO, KC_NO,    KC_NO
                 //                            ╰───────────────────────────╯ ╰──────────────────╯
                 ),
    [9] = LAYOUT(
                  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                       KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
                  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_EQL,      KC_NO,KC_NO,KC_NO,KC_NO,
                  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO, KC_NO, DE_COLN, DE_SCLN, DE_PLUS , DE_ASTR, KC_NO,
                  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                       KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
                  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                                          KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                               KC_NO, KC_NO,    KC_NO
                  //                            ╰───────────────────────────╯ ╰──────────────────╯
                  ),
    [10] = LAYOUT(
      // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
           KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
      // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,      KC_NO,KC_NO,KC_NO,KC_NO,
      // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_NO,KC_NO, LSFT(KC_MINS), LSFT(KC_1), DE_MINS, DE_UNDS , KC_NO,
      // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
           KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
      // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                              KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                   KC_NO, KC_NO,    KC_NO
      //                            ╰───────────────────────────╯ ╰──────────────────╯
      ),
    [11] = LAYOUT(
       // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
            KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
       // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,      KC_NO,KC_NO,KC_NO,KC_NO,
       // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NO, KC_NO, DE_ADIA, DE_ODIA, DE_UDIA,DE_SS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
       // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
            KC_NO, KC_NO,LSFT(DE_ADIA),LSFT(DE_ODIA),LSFT(DE_UDIA),KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
       // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                               KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                    KC_NO, KC_NO,    KC_NO
       //                            ╰───────────────────────────╯ ╰──────────────────╯
       ),
        [12] = LAYOUT(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
             KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             KC_NO, KC_NO,KC_NO,DE_TILD,DE_PIPE,KC_NO, 	KC_NO,KC_NO,      KC_NO,KC_NO,KC_NO,KC_NO,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             KC_NO, DE_QUOT, DE_DQUO, DE_BSLS, DE_SLSH,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
        // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                                KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                     KC_NO, KC_NO,    KC_NO
        //                            ╰───────────────────────────╯ ╰──────────────────╯
        ),
        [13] = LAYOUT(
         // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
              KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,KC_NO, 	         KC_NO,KC_NO,KC_NO,KC_NO,
         // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
              KC_NO, DE_RABK, RALT(KC_0),RALT(KC_9),LSFT(KC_9),KC_NO, 	KC_NO,KC_NO,      KC_NO,KC_NO,KC_NO,KC_NO,
         // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
              KC_NO, DE_LABK, RALT(KC_7),RALT(KC_8),LSFT(KC_8),                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
              KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
         // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                                 KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                      KC_NO, KC_NO,    KC_NO
         //                            ╰───────────────────────────╯ ╰──────────────────╯
         ),
    [14] = LAYOUT(
                        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                             KC_NO, KC_NO,KC_NO,KC_NO, 	   KC_NO, 	  KC_NO, 	KC_NO,TG(14), 	         KC_NO,KC_NO,KC_NO,KC_NO,
                        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                             KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, 	KC_NO,KC_NO,      KC_NO,KC_NO,KC_NO,KC_NO,
                        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,                       KC_NO, PW_1, PW_2, PW_3, PW_4, KC_NO,
                        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                             KC_NO, KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
                        // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                                                KC_NO,KC_NO,KC_NO,    KC_NO,KC_NO,
                                                                     KC_NO, KC_NO,    KC_NO
                        //                            ╰───────────────────────────╯ ╰──────────────────╯
                        ),
    [15] = LAYOUT(
                    // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
                         KC_NO, KC_NO,	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 				TG(15), KC_NO, 	KC_NO,KC_NO,KC_NO, KC_NO,
                    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                         KC_NO, KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 			KC_NO, KC_BTN5, 	KC_BTN6, 	KC_BTN7, KC_BTN8, KC_NO,
                    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                         KC_NO, KC_NO, 	KC_NO, KC_NO, KC_NO, 	KC_NO, 			KC_NO, 	KC_BTN1, 	KC_BTN2, 	KC_BTN3, KC_BTN4, KC_NO,
                    // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
                         KC_NO,  	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO,KC_NO, 	KC_NO, 	KC_MS_WH_UP,KC_MS_WH_DOWN, KC_MS_WH_LEFT, 	KC_MS_WH_RIGHT,KC_NO,
                    // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                                    KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO,
                                                             KC_NO, 	KC_NO, KC_NO
                    //                            ╰───────────────────────────╯ ╰──────────────────╯
                    )
};
// clang-format on
