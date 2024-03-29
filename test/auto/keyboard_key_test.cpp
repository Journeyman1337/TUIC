#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiKeyboardKeyToString") {
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_SPACE)) == std::string("KEY_SPACE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_APOSTROPHE)) == std::string("KEY_APOSTROPHE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_COMMA)) == std::string("KEY_COMMA"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_MINUS)) == std::string("KEY_MINUS"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_PERIOD)) == std::string("KEY_PERIOD"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_SLASH)) == std::string("KEY_SLASH"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_0)) == std::string("KEY_0"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_1)) == std::string("KEY_1"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_2)) == std::string("KEY_2"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_3)) == std::string("KEY_3"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_4)) == std::string("KEY_4"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_5)) == std::string("KEY_5"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_6)) == std::string("KEY_6"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_7)) == std::string("KEY_7"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_8)) == std::string("KEY_8"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_9)) == std::string("KEY_9"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_SEMICOLON)) == std::string("KEY_SEMICOLON"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_EQUAL)) == std::string("KEY_EQUAL"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_A)) == std::string("KEY_A"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_B)) == std::string("KEY_B"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_C)) == std::string("KEY_C"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_D)) == std::string("KEY_D"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_E)) == std::string("KEY_E"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F)) == std::string("KEY_F"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_G)) == std::string("KEY_G"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_H)) == std::string("KEY_H"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_I)) == std::string("KEY_I"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_J)) == std::string("KEY_J"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_K)) == std::string("KEY_K"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_L)) == std::string("KEY_L"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_M)) == std::string("KEY_M"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_N)) == std::string("KEY_N"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_O)) == std::string("KEY_O"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_P)) == std::string("KEY_P"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_Q)) == std::string("KEY_Q"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_R)) == std::string("KEY_R"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_S)) == std::string("KEY_S"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_T)) == std::string("KEY_T"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_U)) == std::string("KEY_U"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_V)) == std::string("KEY_V"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_W)) == std::string("KEY_W"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_X)) == std::string("KEY_X"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_Z)) == std::string("KEY_Z"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_LEFT_BRACKET)) == std::string("KEY_LEFT_BRACKET"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_BACKSLASH)) == std::string("KEY_BACKSLASH"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_RIGHT_BRACKET)) == std::string("KEY_RIGHT_BRACKET"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_GRAVE_ACCENT)) == std::string("KEY_GRAVE_ACCENT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_WORLD_1)) == std::string("KEY_WORLD_1"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_WORLD_2)) == std::string("KEY_WORLD_2"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_ESCAPE)) == std::string("KEY_ESCAPE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_ENTER)) == std::string("KEY_ENTER"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_TAB)) == std::string("KEY_TAB"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_BACKSPACE)) == std::string("KEY_BACKSPACE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_INSERT)) == std::string("KEY_INSERT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_DELETE)) == std::string("KEY_DELETE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_RIGHT)) == std::string("KEY_RIGHT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_LEFT)) == std::string("KEY_LEFT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_DOWN)) == std::string("KEY_DOWN"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_UP)) == std::string("KEY_UP"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_PAGE_UP)) == std::string("KEY_PAGE_UP"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_PAGE_DOWN)) == std::string("KEY_PAGE_DOWN"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_HOME)) == std::string("KEY_HOME"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_END)) == std::string("KEY_END"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_CAPS_LOCK)) == std::string("KEY_CAPS_LOCK"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_SCROLL_LOCK)) == std::string("KEY_SCROLL_LOCK"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_NUM_LOCK)) == std::string("KEY_NUM_LOCK"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_PRINT_SCREEN)) == std::string("KEY_PRINT_SCREEN"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_PAUSE)) == std::string("KEY_PAUSE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F1)) == std::string("KEY_F1"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F2)) == std::string("KEY_F2"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F3)) == std::string("KEY_F3"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F4)) == std::string("KEY_F4"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F5)) == std::string("KEY_F5"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F6)) == std::string("KEY_F6"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F7)) == std::string("KEY_F7"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F8)) == std::string("KEY_F8"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F9)) == std::string("KEY_F9"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F10)) == std::string("KEY_F10"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F11)) == std::string("KEY_F11"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F12)) == std::string("KEY_F12"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F13)) == std::string("KEY_F13"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F14)) == std::string("KEY_F14"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F15)) == std::string("KEY_F15"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F16)) == std::string("KEY_F16"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F17)) == std::string("KEY_F17"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F18)) == std::string("KEY_F18"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F19)) == std::string("KEY_F19"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F20)) == std::string("KEY_F20"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F21)) == std::string("KEY_F21"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F22)) == std::string("KEY_F22"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F23)) == std::string("KEY_F23"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F24)) == std::string("KEY_F24"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_F25)) == std::string("KEY_F25"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_0)) == std::string("KEY_KP_0"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_1)) == std::string("KEY_KP_1"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_2)) == std::string("KEY_KP_2"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_3)) == std::string("KEY_KP_3"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_4)) == std::string("KEY_KP_4"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_5)) == std::string("KEY_KP_5"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_6)) == std::string("KEY_KP_6"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_7)) == std::string("KEY_KP_7"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_8)) == std::string("KEY_KP_8"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_9)) == std::string("KEY_KP_9"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_DECIMAL)) == std::string("KEY_KP_DECIMAL"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_DIVIDE)) == std::string("KEY_KP_DIVIDE"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_MULTIPLY)) == std::string("KEY_KP_MULTIPLY"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_SUBTRACT)) == std::string("KEY_KP_SUBTRACT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_ADD)) == std::string("KEY_KP_ADD"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_ENTER)) == std::string("KEY_KP_ENTER"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_KP_EQUAL)) == std::string("KEY_KP_EQUAL"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_LEFT_SHIFT)) == std::string("KEY_LEFT_SHIFT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_LEFT_CONTROL)) == std::string("KEY_LEFT_CONTROL"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_LEFT_ALT)) == std::string("KEY_LEFT_ALT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_LEFT_SUPER)) == std::string("KEY_LEFT_SUPER"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_RIGHT_SHIFT)) == std::string("KEY_RIGHT_SHIFT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_RIGHT_CONTROL)) == std::string("KEY_RIGHT_CONTROL"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_RIGHT_ALT)) == std::string("KEY_RIGHT_ALT"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_RIGHT_SUPER)) == std::string("KEY_RIGHT_SUPER"));
    REQUIRE(std::string(tuiKeyboardKeyToString(TUIK_MENU)) == std::string("KEY_MENU"));
}

TEST_CASE("tuiStringToKeyboardKey") {
    REQUIRE(tuiStringToKeyboardKey("KEY_SPACE") == TUIK_SPACE);
    REQUIRE(tuiStringToKeyboardKey("KEY_APOSTROPHE") == TUIK_APOSTROPHE);
    REQUIRE(tuiStringToKeyboardKey("KEY_COMMA") == TUIK_COMMA);
    REQUIRE(tuiStringToKeyboardKey("KEY_MINUS") == TUIK_MINUS);
    REQUIRE(tuiStringToKeyboardKey("KEY_PERIOD") == TUIK_PERIOD);
    REQUIRE(tuiStringToKeyboardKey("KEY_SLASH") == TUIK_SLASH);
    REQUIRE(tuiStringToKeyboardKey("KEY_0") == TUIK_0);
    REQUIRE(tuiStringToKeyboardKey("KEY_1") == TUIK_1);
    REQUIRE(tuiStringToKeyboardKey("KEY_2") == TUIK_2);
    REQUIRE(tuiStringToKeyboardKey("KEY_3") == TUIK_3);
    REQUIRE(tuiStringToKeyboardKey("KEY_4") == TUIK_4);
    REQUIRE(tuiStringToKeyboardKey("KEY_5") == TUIK_5);
    REQUIRE(tuiStringToKeyboardKey("KEY_6") == TUIK_6);
    REQUIRE(tuiStringToKeyboardKey("KEY_7") == TUIK_7);
    REQUIRE(tuiStringToKeyboardKey("KEY_8") == TUIK_8);
    REQUIRE(tuiStringToKeyboardKey("KEY_9") == TUIK_9);
    REQUIRE(tuiStringToKeyboardKey("KEY_SEMICOLON") == TUIK_SEMICOLON);
    REQUIRE(tuiStringToKeyboardKey("KEY_EQUAL") == TUIK_EQUAL);
    REQUIRE(tuiStringToKeyboardKey("KEY_A") == TUIK_A);
    REQUIRE(tuiStringToKeyboardKey("KEY_B") == TUIK_B);
    REQUIRE(tuiStringToKeyboardKey("KEY_C") == TUIK_C);
    REQUIRE(tuiStringToKeyboardKey("KEY_D") == TUIK_D);
    REQUIRE(tuiStringToKeyboardKey("KEY_E") == TUIK_E);
    REQUIRE(tuiStringToKeyboardKey("KEY_F") == TUIK_F);
    REQUIRE(tuiStringToKeyboardKey("KEY_G") == TUIK_G);
    REQUIRE(tuiStringToKeyboardKey("KEY_H") == TUIK_H);
    REQUIRE(tuiStringToKeyboardKey("KEY_I") == TUIK_I);
    REQUIRE(tuiStringToKeyboardKey("KEY_J") == TUIK_J);
    REQUIRE(tuiStringToKeyboardKey("KEY_K") == TUIK_K);
    REQUIRE(tuiStringToKeyboardKey("KEY_L") == TUIK_L);
    REQUIRE(tuiStringToKeyboardKey("KEY_M") == TUIK_M);
    REQUIRE(tuiStringToKeyboardKey("KEY_N") == TUIK_N);
    REQUIRE(tuiStringToKeyboardKey("KEY_O") == TUIK_O);
    REQUIRE(tuiStringToKeyboardKey("KEY_P") == TUIK_P);
    REQUIRE(tuiStringToKeyboardKey("KEY_Q") == TUIK_Q);
    REQUIRE(tuiStringToKeyboardKey("KEY_R") == TUIK_R);
    REQUIRE(tuiStringToKeyboardKey("KEY_S") == TUIK_S);
    REQUIRE(tuiStringToKeyboardKey("KEY_T") == TUIK_T);
    REQUIRE(tuiStringToKeyboardKey("KEY_U") == TUIK_U);
    REQUIRE(tuiStringToKeyboardKey("KEY_V") == TUIK_V);
    REQUIRE(tuiStringToKeyboardKey("KEY_W") == TUIK_W);
    REQUIRE(tuiStringToKeyboardKey("KEY_X") == TUIK_X);
    REQUIRE(tuiStringToKeyboardKey("KEY_Y") == TUIK_Y);
    REQUIRE(tuiStringToKeyboardKey("KEY_Z") == TUIK_Z);
    REQUIRE(tuiStringToKeyboardKey("KEY_LEFT_BRACKET") == TUIK_LEFT_BRACKET);
    REQUIRE(tuiStringToKeyboardKey("KEY_BACKSLASH") == TUIK_BACKSLASH);
    REQUIRE(tuiStringToKeyboardKey("KEY_RIGHT_BRACKET") == TUIK_RIGHT_BRACKET);
    REQUIRE(tuiStringToKeyboardKey("KEY_GRAVE_ACCENT") == TUIK_GRAVE_ACCENT);
    REQUIRE(tuiStringToKeyboardKey("KEY_WORLD_1") == TUIK_WORLD_1);
    REQUIRE(tuiStringToKeyboardKey("KEY_WORLD_2") == TUIK_WORLD_2);
    REQUIRE(tuiStringToKeyboardKey("KEY_ESCAPE") == TUIK_ESCAPE);
    REQUIRE(tuiStringToKeyboardKey("KEY_ENTER") == TUIK_ENTER);
    REQUIRE(tuiStringToKeyboardKey("KEY_TAB") == TUIK_TAB);
    REQUIRE(tuiStringToKeyboardKey("KEY_BACKSPACE") == TUIK_BACKSPACE);
    REQUIRE(tuiStringToKeyboardKey("KEY_INSERT") == TUIK_INSERT);
    REQUIRE(tuiStringToKeyboardKey("KEY_DELETE") == TUIK_DELETE);
    REQUIRE(tuiStringToKeyboardKey("KEY_RIGHT") == TUIK_RIGHT);
    REQUIRE(tuiStringToKeyboardKey("KEY_LEFT") == TUIK_LEFT);
    REQUIRE(tuiStringToKeyboardKey("KEY_DOWN") == TUIK_DOWN);
    REQUIRE(tuiStringToKeyboardKey("KEY_UP") == TUIK_UP);
    REQUIRE(tuiStringToKeyboardKey("KEY_PAGE_UP") == TUIK_PAGE_UP);
    REQUIRE(tuiStringToKeyboardKey("KEY_PAGE_DOWN") == TUIK_PAGE_DOWN);
    REQUIRE(tuiStringToKeyboardKey("KEY_HOME") == TUIK_HOME);
    REQUIRE(tuiStringToKeyboardKey("KEY_CAPS_LOCK") == TUIK_CAPS_LOCK);
    REQUIRE(tuiStringToKeyboardKey("KEY_SCROLL_LOCK") == TUIK_SCROLL_LOCK);
    REQUIRE(tuiStringToKeyboardKey("KEY_NUM_LOCK") == TUIK_NUM_LOCK);
    REQUIRE(tuiStringToKeyboardKey("KEY_PRINT_SCREEN") == TUIK_PRINT_SCREEN);
    REQUIRE(tuiStringToKeyboardKey("KEY_PAUSE") == TUIK_PAUSE);
    REQUIRE(tuiStringToKeyboardKey("KEY_F1") == TUIK_F1);
    REQUIRE(tuiStringToKeyboardKey("KEY_F2") == TUIK_F2);
    REQUIRE(tuiStringToKeyboardKey("KEY_F3") == TUIK_F3);
    REQUIRE(tuiStringToKeyboardKey("KEY_F4") == TUIK_F4);
    REQUIRE(tuiStringToKeyboardKey("KEY_F5") == TUIK_F5);
    REQUIRE(tuiStringToKeyboardKey("KEY_F6") == TUIK_F6);
    REQUIRE(tuiStringToKeyboardKey("KEY_F7") == TUIK_F7);
    REQUIRE(tuiStringToKeyboardKey("KEY_F8") == TUIK_F8);
    REQUIRE(tuiStringToKeyboardKey("KEY_F9") == TUIK_F9);
    REQUIRE(tuiStringToKeyboardKey("KEY_F10") == TUIK_F10);
    REQUIRE(tuiStringToKeyboardKey("KEY_F11") == TUIK_F11);
    REQUIRE(tuiStringToKeyboardKey("KEY_F12") == TUIK_F12);
    REQUIRE(tuiStringToKeyboardKey("KEY_F13") == TUIK_F13);
    REQUIRE(tuiStringToKeyboardKey("KEY_F14") == TUIK_F14);
    REQUIRE(tuiStringToKeyboardKey("KEY_F15") == TUIK_F15);
    REQUIRE(tuiStringToKeyboardKey("KEY_F16") == TUIK_F16);
    REQUIRE(tuiStringToKeyboardKey("KEY_F17") == TUIK_F17);
    REQUIRE(tuiStringToKeyboardKey("KEY_F18") == TUIK_F18);
    REQUIRE(tuiStringToKeyboardKey("KEY_F19") == TUIK_F19);
    REQUIRE(tuiStringToKeyboardKey("KEY_F20") == TUIK_F20);
    REQUIRE(tuiStringToKeyboardKey("KEY_F21") == TUIK_F21);
    REQUIRE(tuiStringToKeyboardKey("KEY_F22") == TUIK_F22);
    REQUIRE(tuiStringToKeyboardKey("KEY_F23") == TUIK_F23);
    REQUIRE(tuiStringToKeyboardKey("KEY_F24") == TUIK_F24);
    REQUIRE(tuiStringToKeyboardKey("KEY_F25") == TUIK_F25);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_0") == TUIK_KP_0);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_1") == TUIK_KP_1);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_2") == TUIK_KP_2);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_3") == TUIK_KP_3);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_4") == TUIK_KP_4);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_5") == TUIK_KP_5);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_6") == TUIK_KP_6);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_7") == TUIK_KP_7);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_8") == TUIK_KP_8);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_9") == TUIK_KP_9);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_DECIMAL") == TUIK_KP_DECIMAL);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_DIVIDE") == TUIK_KP_DIVIDE);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_MULTIPLY") == TUIK_KP_MULTIPLY);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_SUBTRACT") == TUIK_KP_SUBTRACT);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_ADD") == TUIK_KP_ADD);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_ENTER") == TUIK_KP_ENTER);
    REQUIRE(tuiStringToKeyboardKey("KEY_KP_EQUAL") == TUIK_KP_EQUAL);
    REQUIRE(tuiStringToKeyboardKey("KEY_LEFT_SHIFT") == TUIK_LEFT_SHIFT);
    REQUIRE(tuiStringToKeyboardKey("KEY_LEFT_CONTROL") == TUIK_LEFT_CONTROL);
    REQUIRE(tuiStringToKeyboardKey("KEY_LEFT_ALT") == TUIK_LEFT_ALT);
    REQUIRE(tuiStringToKeyboardKey("KEY_LEFT_SUPER") == TUIK_LEFT_SUPER);
    REQUIRE(tuiStringToKeyboardKey("KEY_RIGHT_SHIFT") == TUIK_RIGHT_SHIFT);
    REQUIRE(tuiStringToKeyboardKey("KEY_RIGHT_CONTROL") == TUIK_RIGHT_CONTROL);
    REQUIRE(tuiStringToKeyboardKey("KEY_RIGHT_ALT") == TUIK_RIGHT_ALT);
    REQUIRE(tuiStringToKeyboardKey("KEY_RIGHT_SUPER") == TUIK_RIGHT_SUPER);
    REQUIRE(tuiStringToKeyboardKey("KEY_MENU") == TUIK_MENU);
}
