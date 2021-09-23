#include <TUIC/tuic.h>
#include <catch2/catch.hpp>


TEST_CASE("tuiRingGetCenterPoint2")
{
	{
		REQUIRE(tuiRingGetCenterPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetCenterPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetCenterPoint2(tuiRing(10, 10, 1.0f, 1.0f)).x == 10);
		REQUIRE(tuiRingGetCenterPoint2(tuiRing(10, 10, 1.0f, 1.0f)).y == 10);
	}
}

TEST_CASE("tuiRingGetLeftX")
{
	REQUIRE(tuiRingGetLeftX(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetLeftX(tuiRing(0, 0, 5.0f, 0.0f)) == -5);
	REQUIRE(tuiRingGetLeftX(tuiRing(0, 0, 5.0f, 4.0f)) == -5);
}

TEST_CASE("tuiRingGetRightX")
{
	REQUIRE(tuiRingGetRightX(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetRightX(tuiRing(0, 0, 5.0f, 0.0f)) == 5);
	REQUIRE(tuiRingGetRightX(tuiRing(0, 0, 5.0f, 4.0f)) == 5);
}

TEST_CASE("tuiRingGetTopY")
{
	REQUIRE(tuiRingGetTopY(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetTopY(tuiRing(0, 0, 5.0f, 0.0f)) == -5);
	REQUIRE(tuiRingGetTopY(tuiRing(0, 0, 5.0f, 4.0f)) == -5);
}

TEST_CASE("tuiRingGetBottomY")
{
	REQUIRE(tuiRingGetBottomY(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetBottomY(tuiRing(0, 0, 5.0f, 0.0f)) == 5);
	REQUIRE(tuiRingGetBottomY(tuiRing(0, 0, 5.0f, 4.0f)) == 5);
}

TEST_CASE("tuiRingGetInnerRadius")
{
	REQUIRE(tuiRingGetInnerRadius(tuiRing(0, 0, 0.0f, 0.0f)) == 0.0f);
	REQUIRE(tuiRingGetInnerRadius(tuiRing(0, 0, 5.0f, 0.0f)) == 5.0f);
	REQUIRE(tuiRingGetInnerRadius(tuiRing(0, 0, 5.0f, 2.0f)) == 3.0f);
	REQUIRE(tuiRingGetInnerRadius(tuiRing(0, 0, 5.0f, -2.0f)) == 3.0f);
}

TEST_CASE("tuiRingGetInnerLeftX")
{
	REQUIRE(tuiRingGetInnerLeftX(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetInnerLeftX(tuiRing(0, 0, 5.0f, 0.0f)) == -5);
	REQUIRE(tuiRingGetInnerLeftX(tuiRing(0, 0, 5.0f, 2.0f)) == -3);
	REQUIRE(tuiRingGetInnerLeftX(tuiRing(0, 0, 5.0f, -2.0f)) == -3);
}

TEST_CASE("tuiRingGetInnerRightX")
{
	REQUIRE(tuiRingGetInnerRightX(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetInnerRightX(tuiRing(0, 0, 5.0f, 0.0f)) == 5);
	REQUIRE(tuiRingGetInnerRightX(tuiRing(0, 0, 5.0f, 2.0f)) == 3);
	REQUIRE(tuiRingGetInnerRightX(tuiRing(0, 0, 5.0f, -2.0f)) == 3);
}

TEST_CASE("tuiRingGetInnerTopY")
{
	REQUIRE(tuiRingGetInnerTopY(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetInnerTopY(tuiRing(0, 0, 5.0f, 0.0f)) == -5);
	REQUIRE(tuiRingGetInnerTopY(tuiRing(0, 0, 5.0f, 2.0f)) == -3);
	REQUIRE(tuiRingGetInnerTopY(tuiRing(0, 0, 5.0f, -2.0f)) == -3);
}

TEST_CASE("tuiRingGetInnerBottomY")
{
	REQUIRE(tuiRingGetInnerBottomY(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetInnerBottomY(tuiRing(0, 0, 5.0f, 0.0f)) == 5);
	REQUIRE(tuiRingGetInnerBottomY(tuiRing(0, 0, 5.0f, 2.0f)) == 3);
	REQUIRE(tuiRingGetInnerBottomY(tuiRing(0, 0, 5.0f, -2.0f)) == 3);
}

TEST_CASE("tuiRingGetDimensions")
{
	REQUIRE(tuiRingGetDimensions(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetDimensions(tuiRing(0, 0, 5.0f, 0.0f)) == 10);
	REQUIRE(tuiRingGetDimensions(tuiRing(0, 0, 8.0f, 3.0f)) == 16);
}

TEST_CASE("tuiRingGetInnerDimensions")
{
	REQUIRE(tuiRingGetInnerDimensions(tuiRing(0, 0, 0.0f, 0.0f)) == 0);
	REQUIRE(tuiRingGetInnerDimensions(tuiRing(0, 0, 5.0f, 3.0f)) == 4);
	REQUIRE(tuiRingGetInnerDimensions(tuiRing(0, 0, 10.0f, 3.0f)) == 14);
}

TEST_CASE("tuiRingGetCircle")
{
	{
		REQUIRE(tuiRingGetCircle(tuiRing(0, 0, 0.0f, 0.0f)).center_x == 0);
		REQUIRE(tuiRingGetCircle(tuiRing(0, 0, 0.0f, 0.0f)).center_y == 0);
		REQUIRE(tuiRingGetCircle(tuiRing(0, 0, 0.0f, 0.0f)).radius == 0.0f);
	}

	{
		REQUIRE(tuiRingGetCircle(tuiRing(5, 4, 3.0f, 0.0f)).center_x == 5);
		REQUIRE(tuiRingGetCircle(tuiRing(5, 4, 3.0f, 0.0f)).center_y == 4);
		REQUIRE(tuiRingGetCircle(tuiRing(5, 4, 3.0f, 0.0f)).radius == 3.0f);
	}

	{
		REQUIRE(tuiRingGetCircle(tuiRing(5, 4, 3.0f, 2.0f)).center_x == 5);
		REQUIRE(tuiRingGetCircle(tuiRing(5, 4, 3.0f, 2.0f)).center_y == 4);
		REQUIRE(tuiRingGetCircle(tuiRing(5, 4, 3.0f, 2.0f)).radius == 3.0f);
	}
}

TEST_CASE("tuiRingGetInnerCircle")
{
	{
		REQUIRE(tuiRingGetInnerCircle(tuiRing(0, 0, 0.0f, 0.0f)).center_x == 0);
		REQUIRE(tuiRingGetInnerCircle(tuiRing(0, 0, 0.0f, 0.0f)).center_y == 0);
		REQUIRE(tuiRingGetInnerCircle(tuiRing(0, 0, 0.0f, 0.0f)).radius == 0.0f);
	}

	{
		REQUIRE(tuiRingGetInnerCircle(tuiRing(5, 4, 3.0f, 0.0f)).center_x == 5);
		REQUIRE(tuiRingGetInnerCircle(tuiRing(5, 4, 3.0f, 0.0f)).center_y == 4);
		REQUIRE(tuiRingGetInnerCircle(tuiRing(5, 4, 3.0f, 0.0f)).radius == 3.0f);
	}

	{
		REQUIRE(tuiRingGetInnerCircle(tuiRing(5, 4, 3.0f, 2.0f)).center_x == 5);
		REQUIRE(tuiRingGetInnerCircle(tuiRing(5, 4, 3.0f, 2.0f)).center_y == 4);
		REQUIRE(tuiRingGetInnerCircle(tuiRing(5, 4, 3.0f, 2.0f)).radius == 1.0f);
	}
}

TEST_CASE("tuiRingGetBoundingRect")
{
	{
		REQUIRE(tuiRingGetBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).width == 0);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).height == 0);
	}

	{
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).x == 2);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).y == 1);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).width == 6);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).height == 6);
	}

	{
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).x == 2);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).y == 1);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).width == 6);
		REQUIRE(tuiRingGetBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).height == 6);
	}
}

TEST_CASE("tuiRingGetInnerBoundingRect")
{
	{
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).width == 0);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(0, 0, 0.0f, 0.0f)).height == 0);
	}

	{
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).x == 2);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).y == 1);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).width == 6);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 0.0f)).height == 6);
	}

	{
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).x == 4);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).y == 3);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).width == 2);
		REQUIRE(tuiRingGetInnerBoundingRect(tuiRing(5, 4, 3.0f, 2.0f)).height == 2);
	}
}

TEST_CASE("tuiRingGetLeftPoint2")
{
	{
		REQUIRE(tuiRingGetLeftPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetLeftPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetLeftPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 2);
		REQUIRE(tuiRingGetLeftPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 4);
	}

	{
		REQUIRE(tuiRingGetLeftPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 2);
		REQUIRE(tuiRingGetLeftPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 4);
	}
}

TEST_CASE("tuiRingGetRightPoint2")
{
	{
		REQUIRE(tuiRingGetRightPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetRightPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetRightPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 8);
		REQUIRE(tuiRingGetRightPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 4);
	}

	{
		REQUIRE(tuiRingGetRightPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 8);
		REQUIRE(tuiRingGetRightPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 4);
	}
}

TEST_CASE("tuiRingGetTopPoint2")
{
	{
		REQUIRE(tuiRingGetTopPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetTopPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetTopPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 5);
		REQUIRE(tuiRingGetTopPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 1);
	}

	{
		REQUIRE(tuiRingGetTopPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 5);
		REQUIRE(tuiRingGetTopPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 1);
	}
}

TEST_CASE("tuiRingGetBottomPoint2")
{
	{
		REQUIRE(tuiRingGetBottomPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetBottomPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetBottomPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 5);
		REQUIRE(tuiRingGetBottomPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 7);
	}

	{
		REQUIRE(tuiRingGetBottomPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 5);
		REQUIRE(tuiRingGetBottomPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 7);
	}
}

TEST_CASE("tuiRingGetInnerLeftPoint2")
{
	{
		REQUIRE(tuiRingGetInnerLeftPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetInnerLeftPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetInnerLeftPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 2);
		REQUIRE(tuiRingGetInnerLeftPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 4);
	}

	{
		REQUIRE(tuiRingGetInnerLeftPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 4);
		REQUIRE(tuiRingGetInnerLeftPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 4);
	}
}

TEST_CASE("tuiRingGetInnerRightPoint2")
{
	{
		REQUIRE(tuiRingGetInnerRightPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetInnerRightPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetInnerRightPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 8);
		REQUIRE(tuiRingGetInnerRightPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 4);
	}

	{
		REQUIRE(tuiRingGetInnerRightPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 6);
		REQUIRE(tuiRingGetInnerRightPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 4);
	}
}

TEST_CASE("tuiRingGetInnerTopPoint2")
{
	{
		REQUIRE(tuiRingGetInnerTopPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetInnerTopPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetInnerTopPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 5);
		REQUIRE(tuiRingGetInnerTopPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 1);
	}

	{
		REQUIRE(tuiRingGetInnerTopPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 5);
		REQUIRE(tuiRingGetInnerTopPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 3);
	}
}

TEST_CASE("tuiRingGetInnerBottomPoint2")
{
	{
		REQUIRE(tuiRingGetInnerBottomPoint2(tuiRing(0, 0, 0.0f, 0.0f)).x == 0);
		REQUIRE(tuiRingGetInnerBottomPoint2(tuiRing(0, 0, 0.0f, 0.0f)).y == 0);
	}

	{
		REQUIRE(tuiRingGetInnerBottomPoint2(tuiRing(5, 4, 3.0f, 0.0f)).x == 5);
		REQUIRE(tuiRingGetInnerBottomPoint2(tuiRing(5, 4, 3.0f, 0.0f)).y == 7);
	}

	{
		REQUIRE(tuiRingGetInnerBottomPoint2(tuiRing(5, 4, 3.0f, 2.0f)).x == 5);
		REQUIRE(tuiRingGetInnerBottomPoint2(tuiRing(5, 4, 3.0f, 2.0f)).y == 5);
	}
}

TEST_CASE("tuiRingIsDegenerate")
{
	REQUIRE(tuiRingIsDegenerate(tuiRing(0, 0, 0.0f, 0.0f)));
	REQUIRE(!tuiRingIsDegenerate(tuiRing(5, 10, 5.0f, 2.0f)));
	REQUIRE(tuiRingIsDegenerate(tuiRing(25, 35, 2.0f, 5.0f)));
	REQUIRE(tuiRingIsDegenerate(tuiRing(10, 50, 0.4f, 0.2f)));
	REQUIRE(tuiRingIsDegenerate(tuiRing(60, 30, 5.0f, 0.3f)));
}

TEST_CASE("tuiRingContainsPoint2")
{
	REQUIRE(!tuiRingContainsPoint2(tuiRing(0, 0, 0.0f, 0.0f), tuiPoint2(0, 0)));
	REQUIRE(tuiRingContainsPoint2(tuiRing(0, 0, 5.0f, 2.0f), tuiPoint2(0, -4)));
	REQUIRE(!tuiRingContainsPoint2(tuiRing(0, 0, 10.0f, 5.0f), tuiPoint2(0, 0)));
	REQUIRE(!tuiRingContainsPoint2(tuiRing(0, 0, 20.0f, 5.0f), tuiPoint2(30, 0)));
}

TEST_CASE("tuiRingIntersetsLine")
{
	REQUIRE(!tuiRingIntersetsLine(tuiRing(0, 0, 0.0f, 0.0f), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiRingIntersetsLine(tuiRing(0, 0, 5.0f, 2.0f), tuiLine(-50, 0, -5, 0)));
	REQUIRE(tuiRingIntersetsLine(tuiRing(0, 0, 5.0f, 2.0f), tuiLine(0, 0, 0, 3)));
	REQUIRE(!tuiRingIntersetsLine(tuiRing(0, 0, 5.0f, 2.0f), tuiLine(-50, -50, -20, -20)));
}

TEST_CASE("tuiRingIntersectsRect")
{
	REQUIRE(!tuiRingIntersectsRect(tuiRing(0, 0, 0.0f, 0.0f), tuiRect(0, 0, 0, 0)));
	REQUIRE(tuiRingIntersectsRect(tuiRing(0, 0, 5.0f, 2.0f), tuiRect(-50, 0, 46, 46)));
	REQUIRE(tuiRingIntersectsRect(tuiRing(0, 0, 5.0f, 2.0f), tuiRect(0, 0, 1, 3)));
	REQUIRE(!tuiRingIntersectsRect(tuiRing(0, 0, 5.0f, 2.0f), tuiRect(-50, -50, -20, -20)));
}

TEST_CASE("tuiRingIntersectsCircle")
{
	REQUIRE(!tuiRingIntersectsCircle(tuiRing(0, 0, 0.0f, 0.0f), tuiCircle(0, 0, 0.0f)));
	REQUIRE(tuiRingIntersectsCircle(tuiRing(0, 0, 5.0f, 2.0f), tuiCircle(-50, 0, 46.0f)));
	REQUIRE(tuiRingIntersectsCircle(tuiRing(0, 0, 5.0f, 2.0f), tuiCircle(0, 0, 3.0f)));
	REQUIRE(!tuiRingIntersectsCircle(tuiRing(0, 0, 5.0f, 2.0f), tuiCircle(-50, -50, 20.0f)));
}

TEST_CASE("tuiRingIntersectsRing")
{
	REQUIRE(!tuiRingIntersectsRing(tuiRing(0, 0, 0.0f, 0.0f), tuiRing(0, 0, 0.0f, 0.0f)));
	REQUIRE(tuiRingIntersectsRing(tuiRing(0, 0, 5.0f, 2.0f), tuiRing(-50, 0, 46.0f, 2.0f)));
	REQUIRE(tuiRingIntersectsRing(tuiRing(0, 0, 5.0f, 2.0f), tuiRing(0, 0, 3.0f, 1.0f)));
	REQUIRE(!tuiRingIntersectsRing(tuiRing(0, 0, 5.0f, 2.0f), tuiRing(-50, -50, 20.0f, 1.0f)));
}