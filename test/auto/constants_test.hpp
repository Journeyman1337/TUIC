#pragma once
#include <TUIC/tuic.h>
#include <string>
#include "catch.hpp"

TEST_CASE("tuiDetailModeIsValid") {
    SECTION("Detail modes should all return true") {
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C0_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C4_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C8_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C8NBG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C8NFG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C24_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C24NBG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C24NFG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C32_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C32NBG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C32NFG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C0_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C4_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C8_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C8NBG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C8NFG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C24_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C24NBG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C24NFG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NBG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NFG_FULL) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C0_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C4_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C8_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C8NBG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C8NFG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C24_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C24NBG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C24NFG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C32_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C32NBG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G8_C32NFG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C0_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C4_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C8_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C8NBG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C8NFG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C24_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C24NBG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C24NFG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NBG_SPARSE) == TUI_TRUE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NFG_SPARSE) == TUI_TRUE);
    }
    SECTION("Solo flags should return false.") {
        REQUIRE(tuiDetailIsValid(TUI_GLYPH_FLAG_G8) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_GLYPH_FLAG_G16) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C0) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C4) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C8) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C8NBG) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C8NFG) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C24) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C24NBG) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C24NFG) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C32) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C32NBG) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C32NFG) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_LAYOUT_FLAG_FULL) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_LAYOUT_FLAG_SPARSE) == TUI_FALSE);
    }
    SECTION("Too many flags of one type should return false.") {
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NFG_SPARSE | TUI_LAYOUT_FLAG_FULL) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NFG_SPARSE | TUI_COLOR_FLAG_C0) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_DETAIL_G16_C32NFG_SPARSE | TUI_GLYPH_FLAG_G8) == TUI_FALSE);
    }
    SECTION("Flags of only to kinds should return false.") {
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C0 | TUI_GLYPH_FLAG_G8) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_COLOR_FLAG_C0 | TUI_LAYOUT_FLAG_SPARSE) == TUI_FALSE);
        REQUIRE(tuiDetailIsValid(TUI_LAYOUT_FLAG_SPARSE | TUI_GLYPH_FLAG_G8) == TUI_FALSE);
    }

}

TEST_CASE("tuiBlendModeIsValid") {
    SECTION("Blend modes should return true.") {
        REQUIRE(tuiBlendIsValid(TUI_BLEND_NORMAL) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_FG_RED) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_FG_GREEN) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_FG_BLUE) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_FG_ALPHA) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_BG_RED) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_BG_GREEN) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_BG_BLUE) == TUI_TRUE);
        REQUIRE(tuiBlendIsValid(TUI_BLEND_BG_ALPHA) == TUI_TRUE);
    }
    SECTION("Non blend mode values should return false.") {
        REQUIRE(tuiBlendIsValid(-1) == TUI_FALSE);
        REQUIRE(tuiBlendIsValid(9) == TUI_FALSE);
        REQUIRE(tuiBlendIsValid(999) == TUI_FALSE);
    }
}

TEST_CASE("tuiAtlasTypeIsValid") {
    SECTION("Atlas types should return true.") {
        REQUIRE(tuiAtlasTypeIsValid(TUI_ATLAS_COORDS) == TUI_TRUE);
        REQUIRE(tuiAtlasTypeIsValid(TUI_ATLAS_GRID) == TUI_TRUE);
    }
    SECTION("Non atlas types should return false.") {
        REQUIRE(tuiAtlasTypeIsValid(2) == TUI_FALSE);
        REQUIRE(tuiAtlasTypeIsValid(-1) == TUI_FALSE);
    }
}

TEST_CASE("tuiDetailGetGlyphFlag") {
    REQUIRE(tuiDetailGetGlyphFlag(TUI_DETAIL_G8_C0_FULL) == TUI_GLYPH_FLAG_G8);
    REQUIRE(tuiDetailGetGlyphFlag(TUI_DETAIL_G16_C0_FULL) == TUI_GLYPH_FLAG_G16);
}

TEST_CASE("tuiDetailGetColorFlag") {
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C0_FULL) == TUI_COLOR_FLAG_C0);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C4_FULL) == TUI_COLOR_FLAG_C4);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C8_FULL) == TUI_COLOR_FLAG_C8);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C8NBG_FULL) == TUI_COLOR_FLAG_C8NBG);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C8NFG_FULL) == TUI_COLOR_FLAG_C8NFG);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C24_FULL) == TUI_COLOR_FLAG_C24);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C24NBG_FULL) == TUI_COLOR_FLAG_C24NBG);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C24NFG_FULL) == TUI_COLOR_FLAG_C24NFG);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C32_FULL) == TUI_COLOR_FLAG_C32);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C32NBG_FULL) == TUI_COLOR_FLAG_C32NBG);
    REQUIRE(tuiDetailGetColorFlag(TUI_DETAIL_G8_C32NFG_FULL) == TUI_COLOR_FLAG_C32NFG);
}

TEST_CASE("tuiDetailGetLayoutFlag") {
    REQUIRE(tuiDetailGetLayoutFlag(TUI_DETAIL_G8_C0_FULL) == TUI_LAYOUT_FLAG_FULL);
    REQUIRE(tuiDetailGetLayoutFlag(TUI_DETAIL_G8_C0_SPARSE) == TUI_LAYOUT_FLAG_SPARSE);
}

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

TEST_CASE("tuiDetailModeToString") {
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C0_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C0_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C4_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C4_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C8_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C8_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C8NBG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C8NBG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C8NFG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C8NFG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C24_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C24_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C24NBG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C24NBG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C24NFG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C24NFG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C32_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C32_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C32NBG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C32NBG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C32NFG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G8_C32NFG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C0_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C0_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C4_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C4_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C8_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C8_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C8NBG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C8NBG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C8NFG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C8NFG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C24_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C24_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C24NBG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C24NBG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C24NFG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C24NFG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C32_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C32_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C32NBG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C32NBG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C32NFG_FULL)) == std::string(TO_STRING(TUI_DETAIL_G16_C32NFG_FULL)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C0_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C0_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C4_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C4_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C8_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C8_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C8NBG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C8NBG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C8NFG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C8NFG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C24_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C24_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C24NBG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C24NBG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C24NFG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C24NFG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C32_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C32_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C32NBG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C32NBG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G8_C32NFG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G8_C32NFG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C0_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C0_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C4_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C4_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C8_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C8_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C8NBG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C8NBG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C8NFG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C8NFG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C24_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C24_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C24NBG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C24NBG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C24NFG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C24NFG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C32_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C32_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C32NBG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C32NBG_SPARSE)));
    REQUIRE(std::string(tuiDetailModeToString(TUI_DETAIL_G16_C32NFG_SPARSE)) == std::string(TO_STRING(TUI_DETAIL_G16_C32NFG_SPARSE)));
}

TEST_CASE("tuiAtlasTypeToString") {
    REQUIRE(std::string(tuiAtlasTypeToString(TUI_ATLAS_COORDS)) == std::string(TO_STRING(TUI_ATLAS_COORDS)));
    REQUIRE(std::string(tuiAtlasTypeToString(TUI_ATLAS_GRID)) == std::string(TO_STRING(TUI_ATLAS_GRID)));
}

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

TEST_CASE("tuiStringToDetailMode") {
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C0_FULL)) == TUI_DETAIL_G8_C0_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C4_FULL)) == TUI_DETAIL_G8_C4_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C8_FULL)) == TUI_DETAIL_G8_C8_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C8NBG_FULL)) == TUI_DETAIL_G8_C8NBG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C8NFG_FULL)) == TUI_DETAIL_G8_C8NFG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C24_FULL)) == TUI_DETAIL_G8_C24_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C24NBG_FULL)) == TUI_DETAIL_G8_C24NBG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C24NFG_FULL)) == TUI_DETAIL_G8_C24NFG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C32_FULL)) == TUI_DETAIL_G8_C32_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C32NBG_FULL)) == TUI_DETAIL_G8_C32NBG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C32NFG_FULL)) == TUI_DETAIL_G8_C32NFG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C0_FULL)) == TUI_DETAIL_G16_C0_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C4_FULL)) == TUI_DETAIL_G16_C4_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C8_FULL)) == TUI_DETAIL_G16_C8_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C8NBG_FULL)) == TUI_DETAIL_G16_C8NBG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C8NFG_FULL)) == TUI_DETAIL_G16_C8NFG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C24_FULL)) == TUI_DETAIL_G16_C24_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C24NBG_FULL)) == TUI_DETAIL_G16_C24NBG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C24NFG_FULL)) == TUI_DETAIL_G16_C24NFG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C32_FULL)) == TUI_DETAIL_G16_C32_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C32NBG_FULL)) == TUI_DETAIL_G16_C32NBG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C32NFG_FULL)) == TUI_DETAIL_G16_C32NFG_FULL);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C0_SPARSE)) == TUI_DETAIL_G8_C0_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C4_SPARSE)) == TUI_DETAIL_G8_C4_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C8_SPARSE)) == TUI_DETAIL_G8_C8_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C8NBG_SPARSE)) == TUI_DETAIL_G8_C8NBG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C8NFG_SPARSE)) == TUI_DETAIL_G8_C8NFG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C24_SPARSE)) == TUI_DETAIL_G8_C24_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C24NBG_SPARSE)) == TUI_DETAIL_G8_C24NBG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C24NFG_SPARSE)) == TUI_DETAIL_G8_C24NFG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C32_SPARSE)) == TUI_DETAIL_G8_C32_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C32NBG_SPARSE)) == TUI_DETAIL_G8_C32NBG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G8_C32NFG_SPARSE)) == TUI_DETAIL_G8_C32NFG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C0_SPARSE)) == TUI_DETAIL_G16_C0_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C4_SPARSE)) == TUI_DETAIL_G16_C4_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C8_SPARSE)) == TUI_DETAIL_G16_C8_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C8NBG_SPARSE)) == TUI_DETAIL_G16_C8NBG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C8NFG_SPARSE)) == TUI_DETAIL_G16_C8NFG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C24_SPARSE)) == TUI_DETAIL_G16_C24_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C24NBG_SPARSE)) == TUI_DETAIL_G16_C24NBG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C24NFG_SPARSE)) == TUI_DETAIL_G16_C24NFG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C32_SPARSE)) == TUI_DETAIL_G16_C32_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C32NBG_SPARSE)) == TUI_DETAIL_G16_C32NBG_SPARSE);
    REQUIRE(tuiStringToDetailMode(TO_STRING(TUI_DETAIL_G16_C32NFG_SPARSE)) == TUI_DETAIL_G16_C32NFG_SPARSE);
}

TEST_CASE("tuiStringToAtlasType") {
    REQUIRE(tuiStringToAtlasType(TO_STRING(TUI_ATLAS_COORDS)) == TUI_ATLAS_COORDS);
    REQUIRE(tuiStringToAtlasType(TO_STRING(TUI_ATLAS_GRID)) == TUI_ATLAS_GRID);
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

