#include <TUIC/tuic.h>
#include <catch2/catch.hpp>

TEST_CASE("tuiLineGetLeftX")
{
	REQUIRE(tuiLineGetLeftX(tuiLine(0, 0, 0, 0)) == 0); // zeroed out
	REQUIRE(tuiLineGetLeftX(tuiLine(-50, 0, 50, 0)) == -50); // different x
	REQUIRE(tuiLineGetLeftX(tuiLine(1, 20, 1, -20)) == 1); // no y
	REQUIRE(tuiLineGetLeftX(tuiLine(-2000000000, 0, 0, 0)) == -2000000000); // start x
	REQUIRE(tuiLineGetLeftX(tuiLine(0, 0, -2000000000, 0)) == -2000000000); // end x
}

TEST_CASE("tuiLineGetRightX")
{
	REQUIRE(tuiLineGetRightX(tuiLine(0, 0, 0, 0)) == 0);
	REQUIRE(tuiLineGetRightX(tuiLine(-50, 0, 50, 0)) == 50);
	REQUIRE(tuiLineGetRightX(tuiLine(1, 20, 1, -20)) == 1);
	REQUIRE(tuiLineGetRightX(tuiLine(2000000000, 0, 0, 0)) == 2000000000);
	REQUIRE(tuiLineGetRightX(tuiLine(0, 0, 2000000000, 0)) == 2000000000);
}

TEST_CASE("tuiLineGetTopY")
{
	REQUIRE(tuiLineGetTopY(tuiLine(0, 0, 0, 0)) == 0);
	REQUIRE(tuiLineGetTopY(tuiLine(0, -50, 0, 50)) == -50);
	REQUIRE(tuiLineGetTopY(tuiLine(20, 1, -20, 1)) == 1);
	REQUIRE(tuiLineGetTopY(tuiLine(0, -2000000000, 0, 0)) == -2000000000);
	REQUIRE(tuiLineGetTopY(tuiLine(0, 0, 0, -2000000000)) == -2000000000);
}

TEST_CASE("tuiLineGetBottomY")
{
	REQUIRE(tuiLineGetBottomY(tuiLine(0, 0, 0, 0)) == 0);
	REQUIRE(tuiLineGetBottomY(tuiLine(0, -50, 0, 50)) == 50);
	REQUIRE(tuiLineGetBottomY(tuiLine(20, 1, -20, 1)) == 1);
	REQUIRE(tuiLineGetBottomY(tuiLine(0, 2000000000, 0, 0)) == 2000000000);
	REQUIRE(tuiLineGetBottomY(tuiLine(0, 0, 0, 2000000000)) == 2000000000);
}

TEST_CASE("tuiLineGetBoundingRect")
{
	{
		REQUIRE(tuiLineGetBoundingRect(tuiLine(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(0, 0, 0, 0)).y == 0);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(0, 0, 0, 0)).width == 0);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(0, 0, 0, 0)).height == 0);
	}

	{
		REQUIRE(tuiLineGetBoundingRect(tuiLine(-50, -50, 50, 50)).x == -50);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(-50, -50, 50, 50)).y == -50);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(-50, -50, 50, 50)).width == 100);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(-50, -50, 50, 50)).height == 100);
	}

	{
		REQUIRE(tuiLineGetBoundingRect(tuiLine(50, 50, -50, -50)).x == -50);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(50, 50, -50, -50)).y == -50);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(50, 50, -50, -50)).width == 100);
		REQUIRE(tuiLineGetBoundingRect(tuiLine(50, 50, -50, -50)).height == 100);
	}
}

TEST_CASE("tuiLineGetStartPoint2")
{
	{
		REQUIRE(tuiLineGetStartPoint2(tuiLine(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiLineGetStartPoint2(tuiLine(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiLineGetStartPoint2(tuiLine(1, 1, 0, 0)).x == 1);
		REQUIRE(tuiLineGetStartPoint2(tuiLine(1, 1, 0, 0)).y == 1);
	}

	{
		REQUIRE(tuiLineGetStartPoint2(tuiLine(0, 0, 1, 1)).x == 0);
		REQUIRE(tuiLineGetStartPoint2(tuiLine(0, 0, 1, 1)).y == 0);
	}
}

TEST_CASE("tuiLineGetEndPoint2")
{
	{
		REQUIRE(tuiLineGetEndPoint2(tuiLine(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiLineGetEndPoint2(tuiLine(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiLineGetEndPoint2(tuiLine(0, 0, 1, 1)).x == 1);
		REQUIRE(tuiLineGetEndPoint2(tuiLine(0, 0, 1, 1)).y == 1);
	}

	{
		REQUIRE(tuiLineGetEndPoint2(tuiLine(1, 1, 0, 0)).x == 0);
		REQUIRE(tuiLineGetEndPoint2(tuiLine(1, 1, 0, 0)).y == 0);
	}
}

TEST_CASE("tuiLineGetTranslationPoint2")
{
	{
		REQUIRE(tuiLineGetTranslationPoint2(tuiLine(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiLineGetTranslationPoint2(tuiLine(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiLineGetTranslationPoint2(tuiLine(0, 0, 1, 1)).x == 1);
		REQUIRE(tuiLineGetTranslationPoint2(tuiLine(0, 0, 1, 1)).y == 1);
	}

	{
		REQUIRE(tuiLineGetTranslationPoint2(tuiLine(1, 1, 0, 0)).x == -1);
		REQUIRE(tuiLineGetTranslationPoint2(tuiLine(1, 1, 0, 0)).y == -1);
	}
}

TEST_CASE("tuiLineGetLength")
{
	REQUIRE(tuiLineGetLength(tuiLine(0, 0, 0, 0)) == 0.0f);
	REQUIRE(tuiLineGetLength(tuiLine(0, 0, 1, 0)) == 1.0f);
	REQUIRE(tuiLineGetLength(tuiLine(0, 0, 0, 1)) == 1.0f);
	REQUIRE(tuiLineGetLength(tuiLine(1, 0, 0, 0)) == 1.0f);
	REQUIRE(tuiLineGetLength(tuiLine(0, 1, 0, 0)) == 1.0f);
	REQUIRE(tuiLineGetLength(tuiLine(1, 1, 0, 0)) > 1.41420f);
	REQUIRE(tuiLineGetLength(tuiLine(1, 1, 0, 0)) < 1.41422f);
	REQUIRE(tuiLineGetLength(tuiLine(0, 0, 1, 1)) > 1.41420f);
	REQUIRE(tuiLineGetLength(tuiLine(0, 0, 1, 1)) < 1.41422f);
}

TEST_CASE("tuiLineGetDiagonalWidth")
{
	REQUIRE(tuiLineGetDiagonalWidth(tuiLine(0, 0, 0, 0)) == 1);
	REQUIRE(tuiLineGetDiagonalWidth(tuiLine(0, 0, 5, 0)) == 6);
	REQUIRE(tuiLineGetDiagonalWidth(tuiLine(-57, 0, 0, 0)) == 58);
	REQUIRE(tuiLineGetDiagonalWidth(tuiLine(0, 0, 0, 25235)) == 1);
	REQUIRE(tuiLineGetDiagonalWidth(tuiLine(0, 2, 0, 0)) == 1);
}

TEST_CASE("tuiLineGetDiagonalHeight")
{
	REQUIRE(tuiLineGetDiagonalHeight(tuiLine(0, 0, 0, 0)) == 1);
	REQUIRE(tuiLineGetDiagonalHeight(tuiLine(0, 0, 0, 63)) == 64);
	REQUIRE(tuiLineGetDiagonalHeight(tuiLine(0, -2343, 0, 0)) == 2344);
	REQUIRE(tuiLineGetDiagonalHeight(tuiLine(0, 0, 1, 0)) == 1);
	REQUIRE(tuiLineGetDiagonalHeight(tuiLine(1, 0, 0, 0)) == 1);
}

TEST_CASE("tuiLineGetDiagonalLength")
{
	REQUIRE(tuiLineGetDiagonalLength(tuiLine(0, 0, 0, 0)) == 1);
	REQUIRE(tuiLineGetDiagonalLength(tuiLine(50, 0, 0, 0)) == 51);
	REQUIRE(tuiLineGetDiagonalLength(tuiLine(0, -1024, 0, 0)) == 1025);
	REQUIRE(tuiLineGetDiagonalLength(tuiLine(0, 0, 290, 0)) == 291);
	REQUIRE(tuiLineGetDiagonalLength(tuiLine(0, 0, 0, 522)) == 523);
	REQUIRE(tuiLineGetDiagonalLength(tuiLine(-602, 57, 0, 0)) == 603);
}

TEST_CASE("tuiLinesGetCrossProductZ")
{
	REQUIRE(tuiLinesGetCrossProductZ(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)) == 0);
	REQUIRE(tuiLinesGetCrossProductZ(tuiLine(0, 0, 100, 100), tuiLine(100, 100, 0, 0)) == 0);
	REQUIRE(tuiLinesGetCrossProductZ(tuiLine(244, 23, -20, 32), tuiLine(251, 2192, -90, 1)) == 581493);
	REQUIRE(tuiLinesGetCrossProductZ(tuiLine(225, 3290, 21, -332), tuiLine(-298, -92, -325, 3626)) == -856266);
	REQUIRE(tuiLinesGetCrossProductZ(tuiLine(-390, 12, 155, 3), tuiLine(9008, 2, 125157, 8)) == 1048611);
	REQUIRE(tuiLinesGetCrossProductZ(tuiLine(12356123, 8035, 23525, 979332), tuiLine(263, 223192, -235590, 2355123)) == -1303123269);
}

TEST_CASE("tuiLinesGetDotProduct")
{
	REQUIRE(tuiLinesGetDotProduct(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)) == 0);
	REQUIRE(tuiLinesGetDotProduct(tuiLine(100, 0, 0, 100), tuiLine(100, 0, 100, 0)) == 0);
	REQUIRE(tuiLinesGetDotProduct(tuiLine(100, 100, 0, 0), tuiLine(0, 0, 100, 100)) == -20000);
	REQUIRE(tuiLinesGetDotProduct(tuiLine(123535, 233, 0, 3530), tuiLine(-33508, 230, -3100, 99999)) == 867453409);
}

TEST_CASE("tuiLinesParallel")
{
	REQUIRE(tuiLinesParallel(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiLinesParallel(tuiLine(-1, 3, 14, 3), tuiLine(224, 44, -124, 44)));
	REQUIRE(tuiLinesParallel(tuiLine(-1, -1, 15, 15), tuiLine(-90, -90, -124, -124)));
	REQUIRE(tuiLinesParallel(tuiLine(0, 3, 2, 9), tuiLine(8, 19, 10, 25)));
	REQUIRE(!tuiLinesParallel(tuiLine(25, 89, 2442, 266), tuiLine(23, 55, 14, 25)));
}

TEST_CASE("tuiLinesCollinear")
{
	REQUIRE(tuiLinesCollinear(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiLinesCollinear(tuiLine(-22, -22, 66, 66), tuiLine(-33, -33, 99, 99)));
	REQUIRE(tuiLinesCollinear(tuiLine(1, 4, 3, 10), tuiLine(5, 16, 7, 22)));
	REQUIRE(!tuiLinesCollinear(tuiLine(25, 89, 2442, 266), tuiLine(23, 55, 14, 25)));
}

TEST_CASE("tuiLinesPerpendicular")
{
	REQUIRE(tuiLinesPerpendicular(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiLinesPerpendicular(tuiLine(1, 0, -1, 0), tuiLine(0, 1, 0, -1)));
	REQUIRE(tuiLinesPerpendicular(tuiLine(1, 1, -1, -1), tuiLine(1, -1, -1, 1)));
	REQUIRE(tuiLinesPerpendicular(tuiLine(1, 1, -1, -1), tuiLine(1, -1, -1, 1)));
	REQUIRE(tuiLinesPerpendicular(tuiLine(9, 29, 15, 47), tuiLine(9, -1, 15, -3)));
	REQUIRE(!tuiLinesPerpendicular(tuiLine(-25, -25, 78, 78), tuiLine(-12, -12, 65, 65)));
}

TEST_CASE("tuiLineContainsPoint2")
{
	REQUIRE(tuiLineContainsPoint2(tuiLine(0, 0, 0, 0), tuiPoint2(0, 0)));
	REQUIRE(tuiLineContainsPoint2(tuiLine(-1, 1, 1, -1), tuiPoint2(0, 0)));
	REQUIRE(tuiLineContainsPoint2(tuiLine(2000000, 3, -2000000, 3), tuiPoint2(0, 3)));
	REQUIRE(tuiLineContainsPoint2(tuiLine(3, 2000000, 3, -2000000), tuiPoint2(3, 0)));
	REQUIRE(!tuiLineContainsPoint2(tuiLine(-100, 200, -424, 244), tuiPoint2(1, 0)));
}

TEST_CASE("tuiLineContainsLine")
{
	REQUIRE(tuiLineContainsLine(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiLineContainsLine(tuiLine(-1, -1, 1, 1), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiLineContainsLine(tuiLine(100, 0, -100, 0), tuiLine(90, 0, -90, 0)));
	REQUIRE(!tuiLineContainsLine(tuiLine(4, 0, -4, 0), tuiLine(244, 2425, 23, 24)));
}

TEST_CASE("tuiLineIntersectsLine")
{
	REQUIRE(tuiLineIntersectsLine(tuiLine(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiLineIntersectsLine(tuiLine(-1, -1, 1, 1), tuiLine(1, -1, -1, 1)));
	REQUIRE(tuiLineIntersectsLine(tuiLine(2, 3, 15, 4), tuiLine(4, 15, 7, -20)));
	REQUIRE(!tuiLineIntersectsLine(tuiLine(-2, -3, -4, -5), tuiLine(2, 3, 4, 5)));
}