#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiFilterModeToString") {
    REQUIRE(std::string(tuiFilterModeToString(TUI_FILTER_POINT)) == std::string(TO_STRING(TUI_FILTER_POINT)));
    REQUIRE(std::string(tuiFilterModeToString(TUI_FILTER_BILINEAR)) == std::string(TO_STRING(TUI_FILTER_BILINEAR)));
}

TEST_CASE("tuiStringToFilterMode") {
    REQUIRE(tuiStringToFilterMode(TO_STRING(TUI_FILTER_POINT)) == TUI_FILTER_POINT);
    REQUIRE(tuiStringToFilterMode(TO_STRING(TUI_FILTER_BILINEAR)) == TUI_FILTER_BILINEAR);
}
