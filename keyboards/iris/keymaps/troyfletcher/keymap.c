#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 3
#define _NUMPAD 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  NUMPAD,
  ADJUST,
  EMAIL, // macro for typing my email
  VIMWRITE, // macro for writing in Vim
  TMUXLOWERRUN, // macro for running code between vim and another tmux pane
  TMUXLASTWINDOW, // macro for running code between vim and another tmux pane
  TMUXSWAPPANE, // macro for running code between vim and another tmux pane
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MOUS TT(_MOUSE)
#define KC_NUMP TT(_NUMPAD)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_EMAL EMAIL
#define KC_VIMW VIMWRITE
#define KC_TMLR TMUXLOWERRUN
#define KC_TMLW TMUXLASTWINDOW
#define KC_TMSP TMUXSWAPPANE

#define KC_ALTTB LALT(KC_TAB)       // Alt + Tab, switch to last window
#define KC_BRTBR LCTL(KC_TAB)       // Browser tab right
#define KC_BRTBL LSFT(LCTL(KC_TAB)) // Browser tab left
#define KC_CTLESC CTL_T(KC_ESC)     // Control when held, ESC when tapped
#define KC_ALTENT ALT_T(KC_ENT)     // Alt when held, Enter when tapped
#define KC_SFTBKS SFT_T(KC_BSPC)    // Shift when held, Backspace when tapped
#define KC_PTTY LSFT(KC_INS)        // Paste into a putty terminal
#define KC_CLOS LALT(KC_F4)         // Close
#define KC_CADL LCTL(LALT(KC_DEL))  // Ctrl+Alt+Del
#define KC_WNLK LGUI(KC_L)          // Lock Session
#define KC_UNDO LCTL(KC_Z)          // UNDO
#define KC_CUT LCTL(KC_X)           // CUT
#define KC_COPY LCTL(KC_C)          // COPY
#define KC_PASTE LCTL(KC_V)         // PASTE

//  _____                _____ _      _       _               
// |_   _| __ ___  _   _|  ___| | ___| |_ ___| |__   ___ _ __ 
//   | || '__/ _ \| | | | |_  | |/ _ \ __/ __| '_ \ / _ \ '__|
//   | || | | (_) | |_| |  _| | |  __/ || (__| | | |  __/ |   
//   |_||_|  \___/ \__, |_|   |_|\___|\__\___|_| |_|\___|_|   
//                 |___/                                      

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,LBRC ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RALT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,NUMP,     BSLS, N  , M  ,COMM,DOT ,SLSH,RBRC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                      NUMP,CTLESC,LOWR,       SPC,  RASE,LGUI,
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,ESC ,MOUS,ENT ,APP ,PTTY,                   ,MUTE,TMSP,TMLW,MPLY,LPRN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    LCTL,ALTTB,TAB,RGHT,BRTBL,BRTBR,              LEFT,DOWN ,UP ,RGHT,VOLD,VOLU,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,NUMP,    ,    ,MOUS,MOUS,    ,         , DEL,BSPC,    ,    ,PERC,RPRN,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,LOWR,             ,    ,LGUI    
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EMAL,VIMW,EQL ,AMPR,TILD,               HOME,UNDS,ASTR,END ,PLUS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL,AT  ,MNXT,MINS,    ,GRAVE,              HOME,PGDN,PGUP,END ,DLR ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,    ,CLOS,CALC,TMLR,EXLM,CADL,     WNLK,PLUS,HASH,    ,CIRC,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,RALT,    ,             ,RASE,    
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,               ACL0,ACL1,ACL2,    ,    ,RST ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,PGUP,BRTBL,UP,BRTBR,DEL ,                   ,    ,    ,SLCK,PSCR,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RALT,PGDN,LEFT,DOWN,RGHT,BSPC,               MS_L,MS_D,MS_U,MS_R,BTN1,BTN2,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,UNDO,CUT ,COPY,PASTE,MOUS,    ,     WH_U,PLUS,END ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,CTLESC,SPC,        WH_D,    ,    
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB ,PGUP,BRTBL,UP,BRTBR,DEL ,               SLSH, 7  , 8  , 9  ,MINS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
   ALTENT,PGDN,LEFT,DOWN,RGHT,BSPC,               ASTR, 4  , 5  , 6  ,PLUS,TAB ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,UNDO,CUT ,COPY,PASTE,   ,NUMP,         ,BSPC, 1  , 2  , 3  ,ENT ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                          ,CTLESC,SPC ,          0  , DOT,    
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_STEP, RESET  , _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("fletcher.troy@gmail.com");
      }
      return false;
    case VIMWRITE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE));
        SEND_STRING(":w");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
    case TMUXLOWERRUN: // Run vim selected line in lower pane
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(200);
        SEND_STRING(SS_LCTRL("a"));
        SEND_STRING("o");
        _delay_ms(100);
        SEND_STRING(SS_LCTRL("a"));
        SEND_STRING("]");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING(SS_LCTRL("a"));
        SEND_STRING("o");
        SEND_STRING("`>");
      }
      return false;
      break;
    case TMUXSWAPPANE: // Run vim selected line in lower pane
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a"));
        SEND_STRING("l");
      }
      return false;
      break;
    case TMUXLASTWINDOW: // Run vim selected line in lower pane
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("a"));
        SEND_STRING(SS_LCTRL("o"));
      }
      return false;
      break;
  }
  return true;
}
