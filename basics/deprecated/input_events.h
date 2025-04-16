#pragma once

#define Q_KEY_EVENT_COUNT 100
#define Q_FIRST_KEY_OFFSET 4
namespace InputEvents {

    enum KeyCode
    {
        KEYCODE_A = 4,
        KEYCODE_B = 5,
        KEYCODE_C = 6,
        KEYCODE_D = 7,
        KEYCODE_E = 8,
        KEYCODE_F = 9,
        KEYCODE_G = 10,
        KEYCODE_H = 11,
        KEYCODE_I = 12,
        KEYCODE_J = 13,
        KEYCODE_K = 14,
        KEYCODE_L = 15,
        KEYCODE_M = 16,
        KEYCODE_N = 17,
        KEYCODE_O = 18,
        KEYCODE_P = 19,
        KEYCODE_Q = 20,
        KEYCODE_R = 21,
        KEYCODE_S = 22,
        KEYCODE_T = 23,
        KEYCODE_U = 24,
        KEYCODE_V = 25,
        KEYCODE_W = 26,
        KEYCODE_X = 27,
        KEYCODE_Y = 28,
        KEYCODE_Z = 29,
    
        KEYCODE_1 = 30,
        KEYCODE_2 = 31,
        KEYCODE_3 = 32,
        KEYCODE_4 = 33,
        KEYCODE_5 = 34,
        KEYCODE_6 = 35,
        KEYCODE_7 = 36,
        KEYCODE_8 = 37,
        KEYCODE_9 = 38,
        KEYCODE_0 = 39,
    
        KEYCODE_RETURN = 40,
        KEYCODE_ESCAPE = 41,
        KEYCODE_BACKSPACE = 42,
        KEYCODE_TAB = 43,
        KEYCODE_SPACE = 44,
    
        KEYCODE_MINUS = 45,
        KEYCODE_EQUALS = 46,
        KEYCODE_LEFTBRACKET = 47,
        KEYCODE_RIGHTBRACKET = 48,
        KEYCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                      *   key on ISO keyboards and at the right end
                                      *   of the QWERTY row on ANSI keyboards.
                                      *   Produces REVERSE SOLIDUS (backslash) and
                                      *   VERTICAL LINE in a US layout, REVERSE
                                      *   SOLIDUS and VERTICAL LINE in a UK Mac
                                      *   layout, NUMBER SIGN and TILDE in a UK
                                      *   Windows layout, DOLLAR SIGN and POUND SIGN
                                      *   in a Swiss German layout, NUMBER SIGN and
                                      *   APOSTROPHE in a German layout, GRAVE
                                      *   ACCENT and POUND SIGN in a French Mac
                                      *   layout, and ASTERISK and MICRO SIGN in a
                                      *   French Windows layout.
                                      */
        KEYCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                      *   instead of 49 for the same key, but all
                                      *   OSes I've seen treat the two codes
                                      *   identically. So, as an implementor, unless
                                      *   your keyboard generates both of those
                                      *   codes and your OS treats them differently,
                                      *   you should generate KEYCODE_BACKSLASH
                                      *   instead of this code. As a user, you
                                      *   should not rely on this code because SDL
                                      *   will never generate it with most (all?)
                                      *   keyboards.
                                      */
        KEYCODE_SEMICOLON = 51,
        KEYCODE_APOSTROPHE = 52,
        KEYCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                                  *   and ISO keyboards). Produces GRAVE ACCENT and
                                  *   TILDE in a US Windows layout and in US and UK
                                  *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                  *   and NOT SIGN in a UK Windows layout, SECTION
                                  *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                  *   layouts on ISO keyboards, SECTION SIGN and
                                  *   DEGREE SIGN in a Swiss German layout (Mac:
                                  *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                  *   DEGREE SIGN in a German layout (Mac: only on
                                  *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                  *   French Windows layout, COMMERCIAL AT and
                                  *   NUMBER SIGN in a French Mac layout on ISO
                                  *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                  *   SIGN in a Swiss German, German, or French Mac
                                  *   layout on ANSI keyboards.
                                  */
        KEYCODE_COMMA = 54,
        KEYCODE_PERIOD = 55,
        KEYCODE_SLASH = 56,
    
        KEYCODE_CAPSLOCK = 57,
    
        KEYCODE_F1 = 58,
        KEYCODE_F2 = 59,
        KEYCODE_F3 = 60,
        KEYCODE_F4 = 61,
        KEYCODE_F5 = 62,
        KEYCODE_F6 = 63,
        KEYCODE_F7 = 64,
        KEYCODE_F8 = 65,
        KEYCODE_F9 = 66,
        KEYCODE_F10 = 67,
        KEYCODE_F11 = 68,
        KEYCODE_F12 = 69,
    
        KEYCODE_PRINTSCREEN = 70,
        KEYCODE_SCROLLLOCK = 71,
        KEYCODE_PAUSE = 72,
        KEYCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                       does send code 73, not 117) */
        KEYCODE_HOME = 74,
        KEYCODE_PAGEUP = 75,
        KEYCODE_DELETE = 76,
        KEYCODE_END = 77,
        KEYCODE_PAGEDOWN = 78,
        KEYCODE_RIGHT = 79,
        KEYCODE_LEFT = 80,
        KEYCODE_DOWN = 81,
        KEYCODE_UP = 82,
    };

}
