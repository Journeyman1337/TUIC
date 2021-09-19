#include <TUIC/tuic.h>
#include <catch2/catch.hpp>

TEST_CASE("tuiPoint2GetMagnitude")
{
	REQUIRE(tuiPoint2GetMagnitude(tuiPoint2(0, 0)) == 0.0f);
	REQUIRE(tuiPoint2GetMagnitude(tuiPoint2(1, 0)) == 1.0f);
	REQUIRE(tuiPoint2GetMagnitude(tuiPoint2(1, 1)) == 1.4142135623730951f);
	REQUIRE(tuiPoint2GetMagnitude(tuiPoint2(1, 5)) == 5.0990195135927845f);
	REQUIRE(tuiPoint2GetMagnitude(tuiPoint2(5, -5)) == 7.0710678118654755f);
	REQUIRE(tuiPoint2GetMagnitude(tuiPoint2(2000, 2425)) == 3143.34614702f);
}

TEST_CASE("tuiPoint2GetDistance")
{
	REQUIRE(tuiPoint2GetDistance(tuiPoint2(0, 0), tuiPoint2(0, 0)) == 0.0f);
	REQUIRE(tuiPoint2GetDistance(tuiPoint2(0, 0), tuiPoint2(1, 0)) == 1.0f);
	REQUIRE(tuiPoint2GetDistance(tuiPoint2(5, 5), tuiPoint2(-5, -5)) == 14.1421356237f);
	REQUIRE(tuiPoint2GetDistance(tuiPoint2(15, -15), tuiPoint2(50, 20)) == 49.497475f);
	REQUIRE(tuiPoint2GetDistance(tuiPoint2(2424, 100233), tuiPoint2(2000, 2425)) == 31251.40039f);
}

TEST_CASE("tuiPoint2GetPerpDotProduct")
{
	REQUIRE(tuiPoint2GetPerpDotProduct(tuiPoint2(4, 2), tuiPoint2(2, 4)) == 12);
	REQUIRE(tuiPoint2GetPerpDotProduct(tuiPoint2(0, 0), tuiPoint2(0, 0)) == 0);
	REQUIRE(tuiPoint2GetPerpDotProduct(tuiPoint2(242, 11), tuiPoint2(-24, 25)) == 6314);
	REQUIRE(tuiPoint2GetPerpDotProduct(tuiPoint2(5, 10), tuiPoint2(15, 20)) == -50);
}

TEST_CASE("tuiPoint2GetDotProduct")
{
	REQUIRE(tuiPoint2GetDotProduct(tuiPoint2(0, 0), tuiPoint2(0, 0)) == 0.0f);
	REQUIRE(tuiPoint2GetDotProduct(tuiPoint2(1, 1), tuiPoint2(0, 0)) == 0.0f);
	REQUIRE(tuiPoint2GetDotProduct(tuiPoint2(50, -2), tuiPoint2(155, 9)) > 0.9951f);
	REQUIRE(tuiPoint2GetDotProduct(tuiPoint2(50, -2), tuiPoint2(155, 9)) < 0.9953f);
	REQUIRE(tuiPoint2GetDotProduct(tuiPoint2(255, 255), tuiPoint2(-255, -255)) > -1.01f);
	REQUIRE(tuiPoint2GetDotProduct(tuiPoint2(255, 255), tuiPoint2(-255, -255)) < -0.99f);
}