#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>
#define TO_STRING(value) #value

TEST_CASE("tuiBlendModeToString") {
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_NORMAL)) == std::string(TO_STRING(TUI_BLEND_NORMAL)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_FG_RED)) == std::string(TO_STRING(TUI_BLEND_FG_RED)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_FG_GREEN)) == std::string(TO_STRING(TUI_BLEND_FG_GREEN)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_FG_BLUE)) == std::string(TO_STRING(TUI_BLEND_FG_BLUE)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_FG_ALPHA)) == std::string(TO_STRING(TUI_BLEND_FG_ALPHA)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_BG_RED)) == std::string(TO_STRING(TUI_BLEND_BG_RED)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_BG_GREEN)) == std::string(TO_STRING(TUI_BLEND_BG_GREEN)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_BG_BLUE)) == std::string(TO_STRING(TUI_BLEND_BG_BLUE)));
    REQUIRE(std::string(tuiBlendModeToString(TUI_BLEND_BG_ALPHA)) == std::string(TO_STRING(TUI_BLEND_BG_ALPHA)));
}

TEST_CASE("tuiStringToBlendMode") {
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_NORMAL)) == TUI_BLEND_NORMAL);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_FG_RED)) == TUI_BLEND_FG_RED);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_FG_GREEN)) == TUI_BLEND_FG_GREEN);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_FG_BLUE)) == TUI_BLEND_FG_BLUE);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_FG_ALPHA)) == TUI_BLEND_FG_ALPHA);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_BG_RED)) == TUI_BLEND_BG_RED);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_BG_GREEN)) == TUI_BLEND_BG_GREEN);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_BG_BLUE)) == TUI_BLEND_BG_BLUE);
    REQUIRE(tuiStringToBlendMode(TO_STRING(TUI_BLEND_BG_ALPHA)) == TUI_BLEND_BG_ALPHA);
}