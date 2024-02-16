# Overall Notes For Programming
##  CUSTOM MACROS
? We use keybinds like LT(_QW, KC_CAPS) since it already has a method of processing keycodes that we want to use (i.e. tap to send given keycode). Furthermore, since shifting to the already active layer is redundant, we know that it won't interfere with pre-existing LT() keybinds.
? LCTL_T(TG(layer)) doesn't work on its own because TG(layer) is a 16-bit keycode and LCTL_T(kc) only accepts 8-bit keycodes for kc.

* Example of changing tap: Hashtag on tap, Left CTRL on hold. 
case LCTL_T(KC_HASH):         //* LCTL_T(KC_HASH) doesn't work on its own because KC_HASH is actually an alias of LSFT(KC_HASH), which is a 16-bit keycode and LCTL_T(kc) only accepts 8-bit keycodes for kc.
    if (record->tap.count && record->event.pressed) { //* intercept key tap. Notice record->tap.count is "true" for tap.
        tap_code16(KC_HASH);  //* send KC_HASH
        return false;         //* returning false ignores further processing of key tap
    }
    return true;              //* return true processes the rest of the key normally. Therefore, sLCTL_T(KC_HASH) will output Left CTRL on hold as described by the keycode.

* Example of changing hold: KC_F12 on tap, enter DFU (bootloader) mode on hold.
case LT(0, KC_F12):
    if (!record->tap.count && record->event.pressed) { //* intercept key hold. Notice record->tap.count is false for hold.
        tap_code16(KC_BOOT);                           //* send KC_BOOT which puts keyboard into DFU mode
        return false;                                  //* returning false ignores further processing of key hold
    }
    return true;                                       //* tapping will output KC_CAPS.

* Example of changing both tap and hold: tap to select all, hold to copy
case LT(0,KC_NO): //* use KC_NO as a _possible_ way to differentiate a macro where you change both the tap and hold keycodes
    if (record->tap.count && record->event.pressed) { //* intercept key tap. Notice record->tap.count is "true" for tap.
        tap_code16(C(KC_A)); //* intercept tap function to send CTRL-A
    } else if (record->event.pressed) {
        tap_code16(C(KC_C)); //* intercept hold function to send CTRL-C
    }
    return false;            //* end all further processing.

* Extra Example
case LT(_QW, CAPSWRD): //* toggle CAPS_WORD on tap, KC_CAPS (caps lock) on hold.
    if (record->tap.count && record->event.pressed) { //* intercept key tap. Notice record->tap.count is "true" for tap.
        caps_word_toggle();
    } else if (record->event.pressed) { //* intercept key hold. Notice record->tap.count is false for hold. Because we are using else if, you do not need to specify !record->tap.count.
        tap_code(KC_CAPS);
    }
    return false; //* end all further processing of key such as key release

## TAP DANCE
Return an integer that corresponds to what kind of tap dance should be executed.

How to figure out tap dance state: interrupted and pressed.

Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
under the tapping term. This is typically indicitive that you are trying to "tap" the key.

Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
has ended, but the key is still being pressed down. This generally means the key is being "held".

One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.

Good places to put an advanced tap dance:
z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon

Criteria for "good placement" of a tap dance key:
* Not a key that is hit frequently in a sentence
* Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
    in a web form. So 'tab' would be a poor choice for a tap dance.
* Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
    letter 'p', the word 'pepper' would be quite frustating to type.

For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
