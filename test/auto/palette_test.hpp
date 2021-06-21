#pragma once
#include <TUIC/tuic.h>
#include "catch.hpp"

TEST_CASE("tuiClassicColorGetBackground") {
    REQUIRE(tuiClassicColorGetBackground(43) == 2);
    REQUIRE(tuiClassicColorGetBackground(155) == 9);
    REQUIRE(tuiClassicColorGetBackground(1) == 0);
    REQUIRE(tuiClassicColorGetBackground(15) == 0);
}

TEST_CASE("tuiClassicColorGetForeground") {
    REQUIRE(tuiClassicColorGetForeground(43) == 11);
    REQUIRE(tuiClassicColorGetForeground(155) == 11);
    REQUIRE(tuiClassicColorGetForeground(1) == 1);
    REQUIRE(tuiClassicColorGetForeground(15) == 15);
}

TEST_CASE("tuiClassicColorCombine") {
    REQUIRE(tuiClassicColorCombine(0, 15) == 240);
    REQUIRE(tuiClassicColorCombine(1, 0) == 1);
    REQUIRE(tuiClassicColorCombine(1, 14) == 225);
    REQUIRE(tuiClassicColorCombine(3, 5) == 83);
}
