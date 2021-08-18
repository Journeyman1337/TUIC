#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiMouseButtonToString") {
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_1)) == std::string("MOUSE_BUTTON_1"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_2)) == std::string("MOUSE_BUTTON_2"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_3)) == std::string("MOUSE_BUTTON_3"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_4)) == std::string("MOUSE_BUTTON_4"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_5)) == std::string("MOUSE_BUTTON_5"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_6)) == std::string("MOUSE_BUTTON_6"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_7)) == std::string("MOUSE_BUTTON_7"));
    REQUIRE(std::string(tuiMouseButtonToString(TUI_MOUSE_BUTTON_8)) == std::string("MOUSE_BUTTON_8"));
}

TEST_CASE("tuiStringToMouseButton") {
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_1") == TUI_MOUSE_BUTTON_1);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_2") == TUI_MOUSE_BUTTON_2);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_3") == TUI_MOUSE_BUTTON_3);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_4") == TUI_MOUSE_BUTTON_4);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_5") == TUI_MOUSE_BUTTON_5);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_6") == TUI_MOUSE_BUTTON_6);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_7") == TUI_MOUSE_BUTTON_7);
    REQUIRE(tuiStringToMouseButton("MOUSE_BUTTON_8") == TUI_MOUSE_BUTTON_8);
}
