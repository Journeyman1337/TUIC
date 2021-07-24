#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiCursorModeToString") {
    REQUIRE(std::string(tuiCursorModeToString(TUI_CURSOR_MODE_NORMAL)) == std::string("CURSOR_MODE_NORMAL"));
    REQUIRE(std::string(tuiCursorModeToString(TUI_CURSOR_MODE_HIDDEN)) == std::string("CURSOR_MODE_HIDDEN"));
    REQUIRE(std::string(tuiCursorModeToString(TUI_CURSOR_MODE_DISABLED)) == std::string("CURSOR_MODE_DISABLED"));
}

TEST_CASE("tuiStringToCursorMode") {
    REQUIRE(tuiStringToCursorMode("CURSOR_MODE_NORMAL") == TUI_CURSOR_MODE_NORMAL);
    REQUIRE(tuiStringToCursorMode("CURSOR_MODE_HIDDEN") == TUI_CURSOR_MODE_HIDDEN);
    REQUIRE(tuiStringToCursorMode("CURSOR_MODE_DISABLED") == TUI_CURSOR_MODE_DISABLED);
}
