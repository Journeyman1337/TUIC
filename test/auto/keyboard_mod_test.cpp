#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiKeyboardModToString") {
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_SHIFT)) == std::string("MOD_SHIFT"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_CONTROL)) == std::string("MOD_CONTROL"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_ALT)) == std::string("MOD_ALT"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_SUPER)) == std::string("MOD_SUPER"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_CAPS_LOCK)) == std::string("MOD_CAPS_LOCK"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_NUM_LOCK)) == std::string("MOD_NUM_LOCK"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_NONE)) == std::string("MOD_NONE"));
    REQUIRE(std::string(tuiKeyboardModToString(TUI_MOD_ALL)) == std::string("MOD_ALL"));
}

TEST_CASE("tuiStringToKeyboardMod") {
    REQUIRE(tuiStringToKeyboardMod("MOD_SHIFT") == TUI_MOD_SHIFT);
    REQUIRE(tuiStringToKeyboardMod("MOD_CONTROL") == TUI_MOD_CONTROL);
    REQUIRE(tuiStringToKeyboardMod("MOD_ALT") == TUI_MOD_ALT);
    REQUIRE(tuiStringToKeyboardMod("MOD_SUPER") == TUI_MOD_SUPER);
    REQUIRE(tuiStringToKeyboardMod("MOD_CAPS_LOCK") == TUI_MOD_CAPS_LOCK);
    REQUIRE(tuiStringToKeyboardMod("MOD_NUM_LOCK") == TUI_MOD_NUM_LOCK);
    REQUIRE(tuiStringToKeyboardMod("MOD_NONE") == TUI_MOD_NONE);
    REQUIRE(tuiStringToKeyboardMod("MOD_ALL") == TUI_MOD_ALL);
}
