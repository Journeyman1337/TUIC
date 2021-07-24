#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiButtonStateToString") {
    REQUIRE(std::string(tuiButtonStateToString(TUI_BUTTON_RELEASE)) == std::string("BUTTON_RELEASE"));
    REQUIRE(std::string(tuiButtonStateToString(TUI_BUTTON_PRESS)) == std::string("BUTTON_PRESS"));
    REQUIRE(std::string(tuiButtonStateToString(TUI_BUTTON_REPEAT)) == std::string("BUTTON_REPEAT"));
}

TEST_CASE("tuiStringToButtonState") {
    REQUIRE(tuiStringToButtonState("BUTTON_RELEASE") == TUI_BUTTON_RELEASE);
    REQUIRE(tuiStringToButtonState("BUTTON_PRESS") == TUI_BUTTON_PRESS);
    REQUIRE(tuiStringToButtonState("BUTTON_REPEAT") == TUI_BUTTON_REPEAT);
}
