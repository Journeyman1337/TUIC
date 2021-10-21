#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>


TEST_CASE("tuiCropCircleGetCircleCenterPoint2")
{
	{
		REQUIRE(tuiCropCircleGetCircleCenterPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetCircleCenterPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetCircleCenterPoint2(tuiCropCircle(4, 5, 0.0f, 0, 0, 0, 0)).x == 4);
		REQUIRE(tuiCropCircleGetCircleCenterPoint2(tuiCropCircle(4, 5, 0.0f, 0, 0, 0, 0)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetCircleCenterPoint2(tuiCropCircle(14, 15, 0.0f, 0, 0, 10, 10)).x == 14);
		REQUIRE(tuiCropCircleGetCircleCenterPoint2(tuiCropCircle(14, 15, 0.0f, 0, 0, 10, 10)).y == 15);
	}
}

TEST_CASE("tuiCropCircleGetCircleLeftX")
{
	REQUIRE(tuiCropCircleGetCircleLeftX(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCircleLeftX(tuiCropCircle(10, 10, 5.0f, 0, 0, 0, 0)) == 5);
	REQUIRE(tuiCropCircleGetCircleLeftX(tuiCropCircle(25, 25, -2.0f, 0, 0, 0, 0)) == 23);
}

TEST_CASE("tuiCropCircleGetCircleRightX")
{
	REQUIRE(tuiCropCircleGetCircleRightX(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCircleRightX(tuiCropCircle(10, 10, 5.0f, 0, 0, 0, 0)) == 15);
	REQUIRE(tuiCropCircleGetCircleRightX(tuiCropCircle(25, 25, -2.0f, 0, 0, 0, 0)) == 27);
}

TEST_CASE("tuiCropCircleGetCircleTopY")
{
	REQUIRE(tuiCropCircleGetCircleTopY(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCircleTopY(tuiCropCircle(10, 10, 5.0f, 0, 0, 0, 0)) == 5);
	REQUIRE(tuiCropCircleGetCircleTopY(tuiCropCircle(25, 25, -2.0f, 0, 0, 0, 0)) == 23);
}

TEST_CASE("tuiCropCircleGetCircleBottomY")
{
	REQUIRE(tuiCropCircleGetCircleBottomY(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCircleBottomY(tuiCropCircle(10, 10, 5.0f, 0, 0, 0, 0)) == 15);
	REQUIRE(tuiCropCircleGetCircleBottomY(tuiCropCircle(25, 25, -2.0f, 0, 0, 0, 0)) == 27);
}

TEST_CASE("tuiCropCircleGetCircleDimensions")
{
	REQUIRE(tuiCropCircleGetCircleDimensions(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCircleDimensions(tuiCropCircle(10, 10, 5.0f, 0, 0, 0, 0)) == 10);
	REQUIRE(tuiCropCircleGetCircleDimensions(tuiCropCircle(25, 25, -2.0f, 0, 0, 0, 0)) == 4);
}

TEST_CASE("tuiCropCircleGetCircleBoundingRect")
{
	{
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).width == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).height == 0);
	}

	{
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, 5.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, 5.0f, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, 5.0f, 0, 0, 0, 0)).width == 10);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, 5.0f, 0, 0, 0, 0)).height == 10);
	}

	{
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, -5.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, -5.0f, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, -5.0f, 0, 0, 0, 0)).width == 10);
		REQUIRE(tuiCropCircleGetCircleBoundingRect(tuiCropCircle(5, 5, -5.0f, 0, 0, 0, 0)).height == 10);
	}
}

TEST_CASE("tuiCropCircleGetCropFarX")
{
	REQUIRE(tuiCropCircleGetCropFarX(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCropFarX(tuiCropCircle(0, 0, 0.0f, 0, 0, 100, 100)) == 99);
	REQUIRE(tuiCropCircleGetCropFarX(tuiCropCircle(0, 0, 0.0f, 10, 10, 100, 100)) == 109);
	REQUIRE(tuiCropCircleGetCropFarX(tuiCropCircle(0, 0, 0.0f, -5, -5, -100, -100)) == 94);
}

TEST_CASE("tuiCropCircleGetCropFarY")
{
	REQUIRE(tuiCropCircleGetCropFarY(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetCropFarY(tuiCropCircle(0, 0, 0.0f, 0, 0, 100, 100)) == 99);
	REQUIRE(tuiCropCircleGetCropFarY(tuiCropCircle(0, 0, 0.0f, 10, 10, 100, 100)) == 109);
	REQUIRE(tuiCropCircleGetCropFarY(tuiCropCircle(0, 0, 0.0f, -5, -5, -100, -100)) == 94);
}

TEST_CASE("tuiCropCircleGetLeftX")
{
	REQUIRE(tuiCropCircleGetLeftX(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetLeftX(tuiCropCircle(0, 0, 5.0f, -10, -10, 20, 20)) == -5);
	REQUIRE(tuiCropCircleGetLeftX(tuiCropCircle(0, 0, 5.0f, -0, -0, 10, 10)) == 0);
	REQUIRE(tuiCropCircleGetLeftX(tuiCropCircle(0, 0, 5.0f, -10, -10, 10, 10)) == -5);
}

TEST_CASE("tuiCropCircleGetRightX")
{
	REQUIRE(tuiCropCircleGetRightX(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetRightX(tuiCropCircle(0, 0, 5.0f, -10, -10, 20, 20)) == 5);
	REQUIRE(tuiCropCircleGetRightX(tuiCropCircle(0, 0, 5.0f, -0, -0, 10, 10)) == 5);
	REQUIRE(tuiCropCircleGetRightX(tuiCropCircle(0, 0, 5.0f, -10, -10, 10, 10)) == -1);
}

TEST_CASE("tuiCropCircleGetTopY")
{
	REQUIRE(tuiCropCircleGetTopY(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetTopY(tuiCropCircle(0, 0, 5.0f, -10, -10, 20, 20)) == -5);
	REQUIRE(tuiCropCircleGetTopY(tuiCropCircle(0, 0, 5.0f, -0, -0, 10, 10)) == 0);
	REQUIRE(tuiCropCircleGetTopY(tuiCropCircle(0, 0, 5.0f, -10, -10, 10, 10)) == -5);
}

TEST_CASE("tuiCropCircleGetBottomY")
{
	REQUIRE(tuiCropCircleGetBottomY(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropCircleGetBottomY(tuiCropCircle(0, 0, 5.0f, -10, -10, 20, 20)) == 5);
	REQUIRE(tuiCropCircleGetBottomY(tuiCropCircle(0, 0, 5.0f, -0, -0, 10, 10)) == 5);
	REQUIRE(tuiCropCircleGetBottomY(tuiCropCircle(0, 0, 5.0f, -10, -10, 10, 10)) == -1);
}

TEST_CASE("tuiCropCircleGetCropRect")
{
	{
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).width == 0);
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).height == 0);
	}

	{
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).x == 1);
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).y == 1);
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).width == 2);
		REQUIRE(tuiCropCircleGetCropRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).height == 2);
	}
}

TEST_CASE("tuiCropCircleGetBoundingRect")
{
	{
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).width == 0);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).height == 0);
	}

	{
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).x == 0);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).y == 0);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).width == 0);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 0.0f, 1, 1, 2, 2)).height == 0);
	}

	{
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 5.0f, 1, 1, 2, 2)).x == 1);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 5.0f, 1, 1, 2, 2)).y == 1);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 5.0f, 1, 1, 2, 2)).width == 2);
		REQUIRE(tuiCropCircleGetBoundingRect(tuiCropCircle(0, 0, 5.0f, 1, 1, 2, 2)).height == 2);
	}
}

TEST_CASE("tuiCropCircleGetLeftPoint2")
{
	{
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).x == 0);
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).x == 0);
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, 5.0f, 5, 5, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, 5.0f, 5, 5, 20, 20)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, -5.0f, 5, 5, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetLeftPoint2(tuiCropCircle(5, 5, -5.0f, 5, 5, 20, 20)).y == 5);
	}
}

TEST_CASE("tuiCropCircleGetRightPoint2")
{
	{
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).x == 9);
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).x == 9);
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 5, 5)).x == -6);
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 5, 5)).y == -6);
	}

	{
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 5, 5)).x == -6);
		REQUIRE(tuiCropCircleGetRightPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 5, 5)).y == -6);
	}
}

TEST_CASE("tuiCropCircleGetTopPoint2")
{
	{
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, 5.0f, 5, 5, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, 5.0f, 5, 5, 20, 20)).y == 5);
	}

	{
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, -5.0f, 5, 5, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetTopPoint2(tuiCropCircle(5, 5, -5.0f, 5, 5, 20, 20)).y == 5);
	}
}

TEST_CASE("tuiCropCircleGetBottomPoint2")
{
	{
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(0, 0, 0.0f, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 20, 20)).y == 9);
	}

	{
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).x == 5);
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 20, 20)).y == 9);
	}

	{
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 5, 5)).x == -6);
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, 5.0f, -10, -10, 5, 5)).y == -6);
	}

	{
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 5, 5)).x == -6);
		REQUIRE(tuiCropCircleGetBottomPoint2(tuiCropCircle(5, 5, -5.0f, -10, -10, 5, 5)).y == -6);
	}
}


TEST_CASE("tuiCropCircleIsDegenerate")
{

}

TEST_CASE("tuiCropCircleContainsPoint2")
{

}

TEST_CASE("tuiCropCircleContainsLine")
{

}

TEST_CASE("tuiCropCircleContainsRect")
{

}

TEST_CASE("tuiCropCircleContainsCircle")
{

}

TEST_CASE("tuiCropCircleContainsCropCircle")
{

}

TEST_CASE("tuiCropCircleIntersectsLine")
{

}

TEST_CASE("tuiCropCircleIntersectsRect")
{

}

TEST_CASE("tuiCropCircleIntersectsCircle")
{

}

TEST_CASE("tuiCropCircleIntersectsCropCircle")
{

}

TEST_CASE("tuiCropCircleIntersectsRing")
{

}