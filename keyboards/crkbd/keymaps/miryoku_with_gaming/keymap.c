/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "miryoku_layer_list.h"
#include "miryoku_with_gaming.h"
#include <stdio.h>

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [U_BASE] = LAYOUT_split_3x6_3(
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
   TD(U_TD_U_GAMING),                KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,                                    KC_Y,                KC_U,                KC_I,                KC_O,                KC_P,               KC_NO,
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
               KC_NO,        LGUI_T(KC_A),        LALT_T(KC_S),        LCTL_T(KC_D),        LSFT_T(KC_F),                KC_G,                                    KC_H,        LSFT_T(KC_J),        LCTL_T(KC_K),        LALT_T(KC_L),     LGUI_T(KC_QUOT),               KC_NO,
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
               KC_NO,   LT(U_BUTTON,KC_Z),        ALGR_T(KC_X),                KC_C,                KC_V,                KC_B,                                    KC_N,                KC_M,             KC_COMM,      ALGR_T(KC_DOT),LT(U_BUTTON,KC_SLSH),               KC_NO,
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
                                                                   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)
                                                            //|--------------------+--------------------+--------------------|                    |------------------+-------------------+-------------------|

  ),

  [U_EXTRA] = LAYOUT_split_3x6_3(
KC_NO,KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           KC_NO,
KC_NO,LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      KC_NO,
KC_NO,LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),KC_NO,
LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)
  ),


  [U_TAP] = LAYOUT_split_3x6_3(
KC_NO,    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           KC_NO,
KC_NO,KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_K,              KC_N,              KC_E,              KC_I,              KC_O,              KC_NO,
KC_NO,KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_M,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_NO,
KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL
),

  [U_BUTTON] = LAYOUT_split_3x6_3(
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
KC_NO,U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,KC_NO,
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
KC_NO,KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,KC_NO,
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
KC_NO,U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,KC_NO,
//|-----------------+--------------------+--------------------+--------------------+--------------------+--------------------|                    |-------------------+--------------------+--------------------+--------------------+--------------------+--------------------|
KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3
                                                         //|-------------------+-------------------+-------------------|                    |------------------+-------------------+-------------------|
  ),

  [U_NAV] = LAYOUT_split_3x6_3(
KC_NO,TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             KC_NO,
KC_NO,KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           KC_NO,
KC_NO,U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_NO,
U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL
  ),

  [U_MOUSE] = LAYOUT_split_3x6_3(
KC_NO,TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             KC_NO,
KC_NO,KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           KC_NO,
KC_NO,U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           KC_NO,
U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3
  ),

  [U_MEDIA] = LAYOUT_split_3x6_3(
KC_NO,TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           KC_NO,
KC_NO,KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           KC_NO,
KC_NO,U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              KC_NO,
U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE
  ),

  [U_NUM] = LAYOUT_split_3x6_3(
KC_NO,KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     KC_NO,
KC_NO,KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_NO,
KC_NO,KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              KC_NO,
KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA
  ),

  [U_SYM] = LAYOUT_split_3x6_3(
KC_NO,KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     KC_NO,
KC_NO,KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_NO,
KC_NO,KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,              KC_NO,
KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA
  ),

  [U_FUN] = LAYOUT_split_3x6_3(
KC_NO,KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     KC_NO,
KC_NO,KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_NO,
KC_NO,KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              KC_NO,
KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA
  ),

  [U_GAMING] = LAYOUT_split_3x6_3(
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
    TG(U_GAMING2),  KC_LALT,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP,
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
    KC_J,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
    KC_M,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,     KC_MINS, KC_COMM, KC_DOT,  KC_SCLN, KC_SLSH, KC_BSLS,
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
                               KC_ESC,  KC_SPC, KC_TAB,   KC_ENT,  KC_RALT, TD(U_TD_U_BASE)
//                            +--------+--------+--------++--------+--------+--------+
    ),

    [U_GAMING2] = LAYOUT_split_3x6_3(
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
    KC_TRNS, KC_TRNS, KC_L,    KC_TRNS, KC_T,    KC_O,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
    KC_P,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_G,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
    KC_I,    KC_TRNS, KC_B,    KC_N,    KC_H,    KC_K,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
// +--------+--------+--------+--------+--------+--------++--------+--------+--------+--------+--------+--------+
                               KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, TG(U_GAMING2)
//                            +--------+--------+--------++--------+--------+--------+
    )
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    NULL
};


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
//   return rotation;
  return OLED_ROTATION_270;
}

#define MIRYOKU_X(LAYER, STRING) const int L_##LAYER = (1 << U_##LAYER);
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

void oled_write_line(const char *line)
{
    int len = strlen(line);
    if (len >= oled_max_chars())
    {
        oled_write(line, false);
    }
    else
    {
        oled_write_ln(line, false);
    }
}

void oled_render_layer_state(void) {
    // oled_write_P(PSTR("Layer: "), false);
    uint8_t layer = get_highest_layer(layer_state);
    if (!layer) {
        layer = get_highest_layer(default_layer_state);
    }
    switch (layer) {
#define MIRYOKU_X(LAYER, STRING) \
case U_##LAYER: \
    oled_write_line(STRING); \
    break;
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
    }
    oled_write_line("");
    if (layer == U_GAMING)
    {
      oled_write_line(" qwer");
      oled_write_line(" asdf");
      oled_write_line(" zxcv");
      oled_write_line("j");
      oled_write_line("m");
    }
    else if (layer == U_GAMING2)
    {
      oled_write_line(" lwto");
      oled_write_line(" asdg");
      oled_write_line(" bnhk");
      oled_write_line("p");
      oled_write_line("i");
    }
    else
    {
      oled_write_line("");
      oled_write_line("");
      oled_write_line("");
      oled_write_line("");
      oled_write_line("");
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write_ln(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_debug(void) {
    char layer_hex_string[8];
    char default_layer_hex_string[8];
    sprintf(layer_hex_string, "0x%04x", layer_state);
    sprintf(default_layer_hex_string, "0x%04x", default_layer_state);
    oled_write_ln_P(PSTR(layer_hex_string), false);
    oled_write_ln_P(PSTR(default_layer_hex_string), false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        // oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

