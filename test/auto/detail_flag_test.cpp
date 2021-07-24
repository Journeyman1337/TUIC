#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiDetailFlagToString") {
    REQUIRE(std::string(tuiDetailFlagToString(TUI_GLYPH_FLAG_G8)) == std::string(TO_STRING(TUI_GLYPH_FLAG_G8)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_GLYPH_FLAG_G16)) == std::string(TO_STRING(TUI_GLYPH_FLAG_G16)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C0)) == std::string(TO_STRING(TUI_COLOR_FLAG_C0)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C4)) == std::string(TO_STRING(TUI_COLOR_FLAG_C4)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C8)) == std::string(TO_STRING(TUI_COLOR_FLAG_C8)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C8NFG)) == std::string(TO_STRING(TUI_COLOR_FLAG_C8NFG)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C8NBG)) == std::string(TO_STRING(TUI_COLOR_FLAG_C8NBG)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C24)) == std::string(TO_STRING(TUI_COLOR_FLAG_C24)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C24NFG)) == std::string(TO_STRING(TUI_COLOR_FLAG_C24NFG)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C24NBG)) == std::string(TO_STRING(TUI_COLOR_FLAG_C24NBG)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C32)) == std::string(TO_STRING(TUI_COLOR_FLAG_C32)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C32NFG)) == std::string(TO_STRING(TUI_COLOR_FLAG_C32NFG)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_COLOR_FLAG_C32NBG)) == std::string(TO_STRING(TUI_COLOR_FLAG_C32NBG)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_LAYOUT_FLAG_FULL)) == std::string(TO_STRING(TUI_LAYOUT_FLAG_FULL)));
    REQUIRE(std::string(tuiDetailFlagToString(TUI_LAYOUT_FLAG_SPARSE)) == std::string(TO_STRING(TUI_LAYOUT_FLAG_SPARSE)));
}

TEST_CASE("tuiStringToDetailFlag") {
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_GLYPH_FLAG_G8)) == TUI_GLYPH_FLAG_G8);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_GLYPH_FLAG_G16)) == TUI_GLYPH_FLAG_G16);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C0)) == TUI_COLOR_FLAG_C0);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C4)) == TUI_COLOR_FLAG_C4);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C8)) == TUI_COLOR_FLAG_C8);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C8NFG)) == TUI_COLOR_FLAG_C8NFG);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C8NBG)) == TUI_COLOR_FLAG_C8NBG);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C24)) == TUI_COLOR_FLAG_C24);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C24NFG)) == TUI_COLOR_FLAG_C24NFG);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C24NBG)) == TUI_COLOR_FLAG_C24NBG);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C32)) == TUI_COLOR_FLAG_C32);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C32NFG)) == TUI_COLOR_FLAG_C32NFG);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_COLOR_FLAG_C32NBG)) == TUI_COLOR_FLAG_C32NBG);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_LAYOUT_FLAG_FULL)) == TUI_LAYOUT_FLAG_FULL);
    REQUIRE(tuiStringToDetailFlag(TO_STRING(TUI_LAYOUT_FLAG_SPARSE)) == TUI_LAYOUT_FLAG_SPARSE);
}
