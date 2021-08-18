#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiAtlasTypeToString") {
    REQUIRE(std::string(tuiAtlasTypeToString(TUI_ATLAS_COORDS)) == std::string(TO_STRING(TUI_ATLAS_COORDS)));
    REQUIRE(std::string(tuiAtlasTypeToString(TUI_ATLAS_GRID)) == std::string(TO_STRING(TUI_ATLAS_GRID)));
}

TEST_CASE("tuiStringToAtlasType") {
    REQUIRE(tuiStringToAtlasType(TO_STRING(TUI_ATLAS_COORDS)) == TUI_ATLAS_COORDS);
    REQUIRE(tuiStringToAtlasType(TO_STRING(TUI_ATLAS_GRID)) == TUI_ATLAS_GRID);
}
