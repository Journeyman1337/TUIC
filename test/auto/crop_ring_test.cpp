#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>


TEST_CASE("tuiCropRingGetRingCenterPoint2")
{
	{
		REQUIRE(tuiCropRingGetRingCenterPoint2(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropRingGetRingCenterPoint2(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropRingGetRingCenterPoint2(tuiCropRing(15, 15, 0.0f, 0.0f, 0, 0, 0, 0)).x == 15);
		REQUIRE(tuiCropRingGetRingCenterPoint2(tuiCropRing(15, 15, 0.0f, 0.0f, 0, 0, 0, 0)).y == 15);
	}

	{
		REQUIRE(tuiCropRingGetRingCenterPoint2(tuiCropRing(-2, 3, 4.0f, 2.0f, 0, 0, 10, 10)).x == -2);
		REQUIRE(tuiCropRingGetRingCenterPoint2(tuiCropRing(-2, 3, 4.0f, 2.0f, 0, 0, 10, 10)).y == 3);
	}
}

TEST_CASE("tuiCropRingGetRingLeftX")
{
	REQUIRE(tuiCropRingGetRingLeftX(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetRingLeftX(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 5);
	REQUIRE(tuiCropRingGetRingLeftX(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 6);
}

TEST_CASE("tuiCropRingGetRingRightX")
{
	REQUIRE(tuiCropRingGetRingRightX(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetRingRightX(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 25);
	REQUIRE(tuiCropRingGetRingRightX(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 14);
}

TEST_CASE("tuiCropRingGetRingTopY")
{
	REQUIRE(tuiCropRingGetRingTopY(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetRingTopY(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 5);
	REQUIRE(tuiCropRingGetRingTopY(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 6);
}

TEST_CASE("tuiCropRingGetRingBottomY")
{
	REQUIRE(tuiCropRingGetRingBottomY(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetRingBottomY(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 25);
	REQUIRE(tuiCropRingGetRingBottomY(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 14);
}

TEST_CASE("tuiCropRingGetInnerRingRadius")
{
	REQUIRE(tuiCropRingGetInnerRingRadius(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0.0f);
	REQUIRE(tuiCropRingGetInnerRingRadius(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 8.0f);
	REQUIRE(tuiCropRingGetInnerRingRadius(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 2.0f);
}

TEST_CASE("tuiCropRingGetInnerRingLeftX")
{
	REQUIRE(tuiCropRingGetInnerRingLeftX(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetInnerRingLeftX(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 7);
	REQUIRE(tuiCropRingGetInnerRingLeftX(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 8);
}

TEST_CASE("tuiCropRingGetInnerRingRightX")
{
	REQUIRE(tuiCropRingGetInnerRingRightX(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetInnerRingRightX(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 23);
	REQUIRE(tuiCropRingGetInnerRingRightX(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 12);
}

TEST_CASE("tuiCropRingGetInnerRingTopY")
{
	REQUIRE(tuiCropRingGetInnerRingTopY(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetInnerRingTopY(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 7);
	REQUIRE(tuiCropRingGetInnerRingTopY(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 8);
}

TEST_CASE("tuiCropRingGetInnerRingBottomY")
{
	REQUIRE(tuiCropRingGetInnerRingBottomY(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetInnerRingBottomY(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 23);
	REQUIRE(tuiCropRingGetInnerRingBottomY(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 12);
}

TEST_CASE("tuiCropRingGetRingDimensions")
{
	REQUIRE(tuiCropRingGetRingDimensions(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetRingDimensions(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 20);
	REQUIRE(tuiCropRingGetRingDimensions(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 8);
}

TEST_CASE("tuiCropRingGetRingInnerDimensions")
{
	REQUIRE(tuiCropRingGetRingInnerDimensions(tuiCropRing(0, 0, 0.0f, 0.0f, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropRingGetRingInnerDimensions(tuiCropRing(15, 15, 10.0f, 2.0f, 0, 0, 0, 0)) == 16);
	REQUIRE(tuiCropRingGetRingInnerDimensions(tuiCropRing(10, 10, 4.0f, 2.0f, 0, 0, 10, 10)) == 4);
}

TEST_CASE("tuiCropRingGetCropFarX")
{

}

TEST_CASE("tuiCropRingGetCropFarY")
{

}

TEST_CASE("tuiCropRingGetLeftX")
{

}

TEST_CASE("tuiCropRingGetRightX")
{

}

TEST_CASE("tuiCropRingGetTopY")
{

}

TEST_CASE("tuiCropRingGetBottomY")
{

}

TEST_CASE("tuiCropRingGetRing")
{

}

TEST_CASE("tuiCropRingGetRingCircle")
{

}

TEST_CASE("tuiCropRingGetRingInnerCircle")
{

}

TEST_CASE("tuiCropRingGetRingBoundingRect")
{

}

TEST_CASE("tuiCropRingGetInnerRingBoundingRect")
{

}

TEST_CASE("tuiCropRingGetBoundingRect")
{

}

TEST_CASE("tuiCropRingGetRingLeftPoint2")
{

}

TEST_CASE("tuiCropRingGetRingRightPoint2")
{

}

TEST_CASE("tuiCropRingGetRingTopPoint2")
{

}

TEST_CASE("tuiCropRingGetRingBottomPoint2")
{

}

TEST_CASE("tuiCropRingGetRingInnerLeftPoint2")
{

}

TEST_CASE("tuiCropRingGetRingInnerRightPoint2")
{

}

TEST_CASE("tuiCropRingGetRingInnerBottomPoint2")
{

}

TEST_CASE("tuiCropRingIsDegenerate")
{

}

TEST_CASE("tuiCropRingContainsPoint2")
{

}

TEST_CASE("tuiCropRingIntersetsLine")
{

}

TEST_CASE("tuiCropRingIntersectsRect")
{

}

TEST_CASE("tuiCropRingIntersectsCircle")
{

}

TEST_CASE("tuiCropRingIntersectsRing")
{

}

TEST_CASE("tuiCropRingIntersectsCropRing")
{

}