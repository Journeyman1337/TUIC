#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>


TEST_CASE("tuiCircleGetCenterPoint2")
{
	{
		REQUIRE(tuiCircleGetCenterPoint2(tuiCircle(0, 0, 0.0f)).x == 0);
		REQUIRE(tuiCircleGetCenterPoint2(tuiCircle(0, 0, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiCircleGetCenterPoint2(tuiCircle(10, 10, 5.0f)).x == 10);
		REQUIRE(tuiCircleGetCenterPoint2(tuiCircle(10, 10, 5.0f)).y == 10);
	}

	{
		REQUIRE(tuiCircleGetCenterPoint2(tuiCircle(30, 15, 10.0f)).x == 30);
		REQUIRE(tuiCircleGetCenterPoint2(tuiCircle(30, 15, 10.0f)).y == 15);
	}
}

TEST_CASE("tuiCircleGetLeftX")
{
	REQUIRE(tuiCircleGetLeftX(tuiCircle(0, 0, 0.0f)) == 0);
	REQUIRE(tuiCircleGetLeftX(tuiCircle(10, 10, 5.0f)) == 5);
	REQUIRE(tuiCircleGetLeftX(tuiCircle(25, 25, -2.0f)) == 23);
}

TEST_CASE("tuiCircleGetRightX")
{
	REQUIRE(tuiCircleGetRightX(tuiCircle(0, 0, 0.0f)) == 0);
	REQUIRE(tuiCircleGetRightX(tuiCircle(10, 10, 5.0f)) == 15);
	REQUIRE(tuiCircleGetRightX(tuiCircle(25, 25, -2.0f)) == 27);
}

TEST_CASE("tuiCircleGetTopY")
{
	REQUIRE(tuiCircleGetTopY(tuiCircle(0, 0, 0.0f)) == 0);
	REQUIRE(tuiCircleGetTopY(tuiCircle(10, 10, 5.0f)) == 5);
	REQUIRE(tuiCircleGetTopY(tuiCircle(25, 25, -2.0f)) == 23);
}

TEST_CASE("tuiCircleGetBottomY")
{
	REQUIRE(tuiCircleGetBottomY(tuiCircle(0, 0, 0.0f)) == 0);
	REQUIRE(tuiCircleGetBottomY(tuiCircle(10, 10, 5.0f)) == 15);
	REQUIRE(tuiCircleGetBottomY(tuiCircle(25, 25, -2.0f)) == 27);
}

TEST_CASE("tuiCircleGetDimensions")
{
	REQUIRE(tuiCircleGetDimensions(tuiCircle(0, 0, 0.0f)) == 0);
	REQUIRE(tuiCircleGetDimensions(tuiCircle(10, 10, 5.0f)) == 10);
	REQUIRE(tuiCircleGetDimensions(tuiCircle(25, 25, -2.0f)) == 4);
}

TEST_CASE("tuiCircleGetBoundingRect")
{
	{
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(0, 0, 0.0f)).x == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(0, 0, 0.0f)).y == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(0, 0, 0.0f)).width == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(0, 0, 0.0f)).height == 0);
	}

	{
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, 5.0f)).x == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, 5.0f)).y == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, 5.0f)).width == 10);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, 5.0f)).height == 10);
	}

	{
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, -5.0f)).x == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, -5.0f)).y == 0);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, -5.0f)).width == 10);
		REQUIRE(tuiCircleGetBoundingRect(tuiCircle(5, 5, -5.0f)).height == 10);
	}
}

TEST_CASE("tuiCircleGetLeftPoint2")
{
	{
		REQUIRE(tuiCircleGetLeftPoint2(tuiCircle(0, 0, 0.0f)).x == 0);
		REQUIRE(tuiCircleGetLeftPoint2(tuiCircle(0, 0, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiCircleGetLeftPoint2(tuiCircle(5, 5, 5.0f)).x == 0);
		REQUIRE(tuiCircleGetLeftPoint2(tuiCircle(5, 5, 5.0f)).y == 5);
	}

	{
		REQUIRE(tuiCircleGetLeftPoint2(tuiCircle(5, 5, -5.0f)).x == 0);
		REQUIRE(tuiCircleGetLeftPoint2(tuiCircle(5, 5, -5.0f)).y == 5);
	}
}

TEST_CASE("tuiCircleGetRightPoint2")
{
	{
		REQUIRE(tuiCircleGetRightPoint2(tuiCircle(0, 0, 0.0f)).x == 0);
		REQUIRE(tuiCircleGetRightPoint2(tuiCircle(0, 0, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiCircleGetRightPoint2(tuiCircle(5, 5, 5.0f)).x == 10);
		REQUIRE(tuiCircleGetRightPoint2(tuiCircle(5, 5, 5.0f)).y == 5);
	}

	{
		REQUIRE(tuiCircleGetRightPoint2(tuiCircle(5, 5, -5.0f)).x == 10);
		REQUIRE(tuiCircleGetRightPoint2(tuiCircle(5, 5, -5.0f)).y == 5);
	}
}

TEST_CASE("tuiCircleGetTopPoint2")
{
	{
		REQUIRE(tuiCircleGetTopPoint2(tuiCircle(0, 0, 0.0f)).x == 0);
		REQUIRE(tuiCircleGetTopPoint2(tuiCircle(0, 0, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiCircleGetTopPoint2(tuiCircle(5, 5, 5.0f)).x == 5);
		REQUIRE(tuiCircleGetTopPoint2(tuiCircle(5, 5, 5.0f)).y == 0);
	}

	{
		REQUIRE(tuiCircleGetTopPoint2(tuiCircle(5, 5, -5.0f)).x == 5);
		REQUIRE(tuiCircleGetTopPoint2(tuiCircle(5, 5, -5.0f)).y == 0);
	}
}

TEST_CASE("tuiCircleGetBottomPoint2")
{
	{
		REQUIRE(tuiCircleGetBottomPoint2(tuiCircle(0, 0, 0.0f)).x == 0);
		REQUIRE(tuiCircleGetBottomPoint2(tuiCircle(0, 0, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiCircleGetBottomPoint2(tuiCircle(5, 5, 5.0f)).x == 5);
		REQUIRE(tuiCircleGetBottomPoint2(tuiCircle(5, 5, 5.0f)).y == 10);
	}

	{
		REQUIRE(tuiCircleGetBottomPoint2(tuiCircle(5, 5, -5.0f)).x == 5);
		REQUIRE(tuiCircleGetBottomPoint2(tuiCircle(5, 5, -5.0f)).y == 10);
	}
}

TEST_CASE("tuiCircleIsDegenerate")
{
	REQUIRE(tuiCircleIsDegenerate(tuiCircle(0, 0, 0.0f)));
	REQUIRE(!tuiCircleIsDegenerate(tuiCircle(0, 0, 1.0f)));
	REQUIRE(!tuiCircleIsDegenerate(tuiCircle(0, 0, -1.0f)));
}

TEST_CASE("tuiCircleContainsPoint2")
{
	REQUIRE(!tuiCircleContainsPoint2(tuiCircle(0, 0, 0.0f), tuiPoint2(0, 0)));
	REQUIRE(tuiCircleContainsPoint2(tuiCircle(0, 0, 5.0f), tuiPoint2(0, 0)));
	REQUIRE(!tuiCircleContainsPoint2(tuiCircle(0, 0, 5.0f), tuiPoint2(0, 100)));
}

TEST_CASE("tuiCircleContainsLine")
{
	REQUIRE(!tuiCircleContainsLine(tuiCircle(0, 0, 0.0f), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiCircleContainsLine(tuiCircle(0, 0, 10.0f), tuiLine(-4, -4, 4, 4)));
	REQUIRE(!tuiCircleContainsLine(tuiCircle(0, 0, 10.0f), tuiLine(-25, -20, -15, -15)));
}

TEST_CASE("tuiCircleContainsRect")
{
	REQUIRE(!tuiCircleContainsRect(tuiCircle(0, 0, 0.0f), tuiRect(0, 0, 0, 0)));
	REQUIRE(tuiCircleContainsRect(tuiCircle(0, 0, 10.0f), tuiRect(0, 0, 5, 5)));
	REQUIRE(!tuiCircleContainsRect(tuiCircle(0, 0, 10.0f), tuiRect(0, 0, 0, 0)));
	REQUIRE(!tuiCircleContainsRect(tuiCircle(0, 0, 10.0f), tuiRect(-50, -50, 10, 10)));
}

TEST_CASE("tuiCircleContainsCircle")
{
	REQUIRE(!tuiCircleContainsCircle(tuiCircle(0, 0, 0.0f), tuiCircle(0, 0, 0.0f)));
	REQUIRE(tuiCircleContainsCircle(tuiCircle(0, 0, 15.0f), tuiCircle(0, 0, 5.0f)));
	REQUIRE(!tuiCircleContainsCircle(tuiCircle(0, 0, 5.0f), tuiCircle(0, 0, 0.0f)));
	REQUIRE(!tuiCircleContainsCircle(tuiCircle(0, 0, 0.0f), tuiCircle(0, 0, 5.0f)));
}

TEST_CASE("tuiCircleIntersectsLine")
{
	REQUIRE(!tuiCircleIntersectsLine(tuiCircle(0, 0, 0.0f), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiCircleIntersectsLine(tuiCircle(0, 0, 5.0f), tuiLine(-1, -1, 1, 1)));
	REQUIRE(tuiCircleIntersectsLine(tuiCircle(0, 0, 20.0f), tuiLine(-20, -20, -20, 20)));
	REQUIRE(!tuiCircleIntersectsLine(tuiCircle(0, 0, 5.0f), tuiLine(-20, -20, -19, -19)));
	REQUIRE(!tuiCircleIntersectsLine(tuiCircle(50, 50, -233.0f), tuiLine(-230, -230, 224, -223)));
}

TEST_CASE("tuiCircleIntersectsRect")
{
	REQUIRE(!tuiCircleIntersectsRect(tuiCircle(0, 0, 0.0f), tuiRect(0, 0, 0, 0)));
	REQUIRE(tuiCircleIntersectsRect(tuiCircle(0, 0, 5.0f), tuiRect(-1, -1, 2, 2)));
	REQUIRE(tuiCircleIntersectsRect(tuiCircle(0, 0, 5.0f), tuiRect(5, -5, 10, 10)));
	REQUIRE(!tuiCircleIntersectsRect(tuiCircle(0, 0, 5.0f), tuiRect(50, 50, 10, 10)));
}

TEST_CASE("tuiCircleIntersectsCircle")
{
	REQUIRE(!tuiCircleIntersectsCircle(tuiCircle(0, 0, 0.0f), tuiCircle(0, 0, 0.0f)));
	REQUIRE(tuiCircleIntersectsCircle(tuiCircle(0, 0, 5.0f), tuiCircle(0, 0, 1.0f)));
	REQUIRE(tuiCircleIntersectsCircle(tuiCircle(-3, 0, 10.0f), tuiCircle(3, 0, 10.0f)));
	REQUIRE(tuiCircleIntersectsCircle(tuiCircle(-5, 0, 10.0f), tuiCircle(5, 0, 10.0f)));
	REQUIRE(!tuiCircleIntersectsCircle(tuiCircle(-5, 0, 2.0f), tuiCircle(5, 0, 2.0f)));
}