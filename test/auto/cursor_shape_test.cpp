#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiCursorShapeToString") {
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_ARROW)) == std::string("CURSOR_SHAPE_ARROW"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_IBEAM)) == std::string("CURSOR_SHAPE_IBEAM"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_CROSSHAIR)) == std::string("CURSOR_SHAPE_CROSSHAIR"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_POINTING_HAND)) == std::string("CURSOR_SHAPE_POINTING_HAND"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_RESIZE_EW)) == std::string("CURSOR_SHAPE_RESIZE_EW"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_RESIZE_NS)) == std::string("CURSOR_SHAPE_RESIZE_NS"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_RESIZE_NWSE)) == std::string("CURSOR_SHAPE_RESIZE_NWSE"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_RESIZE_NESW)) == std::string("CURSOR_SHAPE_RESIZE_NESW"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_RESIZE_ALL)) == std::string("CURSOR_SHAPE_RESIZE_ALL"));
    REQUIRE(std::string(tuiCursorShapeToString(TUI_CURSOR_SHAPE_NOT_ALLOWED)) == std::string("CURSOR_SHAPE_NOT_ALLOWED"));
}

TEST_CASE("tuiStringToCursorShape") {
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_ARROW") == TUI_CURSOR_SHAPE_ARROW);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_IBEAM") == TUI_CURSOR_SHAPE_IBEAM);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_CROSSHAIR") == TUI_CURSOR_SHAPE_CROSSHAIR);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_POINTING_HAND") == TUI_CURSOR_SHAPE_POINTING_HAND);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_RESIZE_EW") == TUI_CURSOR_SHAPE_RESIZE_EW);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_RESIZE_NS") == TUI_CURSOR_SHAPE_RESIZE_NS);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_RESIZE_NWSE") == TUI_CURSOR_SHAPE_RESIZE_NWSE);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_RESIZE_NESW") == TUI_CURSOR_SHAPE_RESIZE_NESW);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_RESIZE_ALL") == TUI_CURSOR_SHAPE_RESIZE_ALL);
    REQUIRE(tuiStringToCursorShape("CURSOR_SHAPE_NOT_ALLOWED") == TUI_CURSOR_SHAPE_NOT_ALLOWED);
}
