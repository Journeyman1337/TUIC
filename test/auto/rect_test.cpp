#include <TUIC/tuic.h>
#include <catch2/catch.hpp>


TEST_CASE("tuiRectGetFarX")
{
	REQUIRE(tuiRectGetFarX(tuiRect(0, 0, 0, 0)) == 0);
	REQUIRE(tuiRectGetFarX(tuiRect(0, 0, 100, 100)) == 99);
	REQUIRE(tuiRectGetFarX(tuiRect(10, 10, 100, 100)) == 109);
	REQUIRE(tuiRectGetFarX(tuiRect(-5, -5, -100, -100)) == 94);
}

TEST_CASE("tuiRectGetFarY")
{
	REQUIRE(tuiRectGetFarY(tuiRect(0, 0, 0, 0)) == 0);
	REQUIRE(tuiRectGetFarY(tuiRect(0, 0, 100, 100)) == 99);
	REQUIRE(tuiRectGetFarY(tuiRect(10, 10, 100, 100)) == 109);
	REQUIRE(tuiRectGetFarY(tuiRect(-5, -5, -100, -100)) == 94);
}

TEST_CASE("tuiRectGetTileWidth")
{
	REQUIRE(tuiRectGetTileWidth(tuiRect(0, 0, 0, 0)) == 0);
	REQUIRE(tuiRectGetTileWidth(tuiRect(0, 0, 4, 4)) == 4);
	REQUIRE(tuiRectGetTileWidth(tuiRect(0, 0, -4, -4)) == 4);
}

TEST_CASE("tuiRectGetTileHeight")
{
	REQUIRE(tuiRectGetTileHeight(tuiRect(0, 0, 0, 0)) == 0);
	REQUIRE(tuiRectGetTileHeight(tuiRect(0, 0, 4, 4)) == 4);
	REQUIRE(tuiRectGetTileHeight(tuiRect(0, 0, -4, -4)) == 4);
}

TEST_CASE("tuiRectIsDegenerate")
{
	REQUIRE(tuiRectIsDegenerate(tuiRect(0, 0, 0, 0)));
	REQUIRE(tuiRectIsDegenerate(tuiRect(0, 0, 1, 0)));
	REQUIRE(tuiRectIsDegenerate(tuiRect(0, 0, 0, 1)));
	REQUIRE(!tuiRectIsDegenerate(tuiRect(0, 0, 1, 1)));
}

TEST_CASE("tuiRectGetTopLeftCornerPoint2")
{
	{
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(0, 0, 10, 10)).x == 0);
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(0, 0, 10, 10)).y == 0);
	}

	{
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(10, 10, 10, 10)).x == 10);
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(10, 10, 10, 10)).y == 10);
	}

	{
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(10, 10, -10, -10)).x == 10);
		REQUIRE(tuiRectGetTopLeftCornerPoint2(tuiRect(10, 10, -10, -10)).y == 10);
	}
}

TEST_CASE("tuiRectGetTopRightCornerPoint2")
{
	{
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(0, 0, 10, 10)).x == 9);
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(0, 0, 10, 10)).y == 0);
	}

	{
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(10, 10, 10, 10)).x == 19);
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(10, 10, 10, 10)).y == 10);
	}

	{
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(10, 10, -10, -10)).x == 19);
		REQUIRE(tuiRectGetTopRightCornerPoint2(tuiRect(10, 10, -10, -10)).y == 10);
	}
}

TEST_CASE("tuiRectGetBottomLeftCornerPoint2")
{
	{
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(0, 0, 10, 10)).x == 0);
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(0, 0, 10, 10)).y == 9);
	}

	{
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(10, 10, 10, 10)).x == 10);
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(10, 10, 10, 10)).y == 19);
	}

	{
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(10, 10, -10, -10)).x == 10);
		REQUIRE(tuiRectGetBottomLeftCornerPoint2(tuiRect(10, 10, -10, -10)).y == 19);
	}
}

TEST_CASE("tuiRectGetBottomRightCornerPoint2")
{
	{
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(0, 0, 0, 0)).x == 0);
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(0, 0, 10, 10)).x == 9);
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(0, 0, 10, 10)).y == 9);
	}

	{
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(10, 10, 10, 10)).x == 19);
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(10, 10, 10, 10)).y == 19);
	}

	{
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(10, 10, -10, -10)).x == 19);
		REQUIRE(tuiRectGetBottomRightCornerPoint2(tuiRect(10, 10, -10, -10)).y == 19);
	}
}

TEST_CASE("tuiRectGetLeftBorderLine")
{
	{
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_y == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_y == 9);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_y == 1);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_y == 8);
	}

	{
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_y == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_y == 9);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_y == 1);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_x == 0);
		REQUIRE(tuiRectGetLeftBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_y == 8);
	}	
}

TEST_CASE("tuiRectGetRightBorderLine")
{
	{
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_y == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_y == 0);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_y == 8);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_y == 1);
	}

	{
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_y == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_y == 0);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_y == 8);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_x == 9);
		REQUIRE(tuiRectGetRightBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_y == 1);
	}
}

TEST_CASE("tuiRectGetTopBorderLine")
{
	{
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_x == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_y == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_x == 9);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_y == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_x == 1);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_y == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_x == 8);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_y == 0);
	}

	{
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_x == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_y == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_x == 9);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_y == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_x == 1);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_y == 0);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_x == 8);
		REQUIRE(tuiRectGetTopBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_y == 0);
	}
}

TEST_CASE("tuiRectGetBottomBorderLine")
{
	{
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_x == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).start_y == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_x == 0);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_TRUE).end_y == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_x == 8);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).start_y == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_x == 1);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, 10, 10), TUI_FALSE).end_y == 9);
	}

	{
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_x == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).start_y == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_x == 0);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_TRUE).end_y == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_x == 8);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).start_y == 9);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_x == 1);
		REQUIRE(tuiRectGetBottomBorderLine(tuiRect(0, 0, -10, -10), TUI_FALSE).end_y == 9);
	}
}

TEST_CASE("tuiRectGetInnerRect")
{
	{
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, 10, 10), 1).x == 1);
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, 10, 10), 1).y == 1);
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, 10, 10), 1).width == 8);
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, 10, 10), 1).height == 8);
	}
	
	{
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, -10, -10), 1).x == 1);
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, -10, -10), 1).y == 1);
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, -10, -10), 1).width == -8);
		REQUIRE(tuiRectGetInnerRect(tuiRect(0, 0, -10, -10), 1).height == -8);
	}
}

TEST_CASE("tuiRectCrop")
{
	{
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(2, 2, 11, 11)).x == 2);
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(2, 2, 11, 11)).y == 2);
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(2, 2, 11, 11)).width == 8);
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(2, 2, 11, 11)).height == 8);
	}

	{
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(-2, -2, 4, 4)).x == 0);
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(-2, -2, 4, 4)).y == 0);
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(-2, -2, 4, 4)).width == 2);
		REQUIRE(tuiRectCrop(tuiRect(0, 0, 10, 10), tuiRect(-2, -2, 4, 4)).height == 2);
	}
}

TEST_CASE("tuiRectContainsPoint2")
{
	REQUIRE(!tuiRectContainsPoint2(tuiRect(0, 0, 0, 0), tuiPoint2(0, 0)));
	REQUIRE(tuiRectContainsPoint2(tuiRect(0, 0, 10, 10), tuiPoint2(5, 5)));
	REQUIRE(!tuiRectContainsPoint2(tuiRect(-10, -10, 20, 20), tuiPoint2(-25, 0)));
}

TEST_CASE("tuiRectContainsLine")
{
	REQUIRE(!tuiRectContainsLine(tuiRect(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiRectContainsLine(tuiRect(0, 0, 10, 10), tuiLine(2, 2, 6, 6)));
	REQUIRE(!tuiRectContainsLine(tuiRect(-10, -10, 20, 20), tuiLine(-25, 0, -23, 0)));
	REQUIRE(!tuiRectContainsLine(tuiRect(0, 0, 10, 10), tuiLine(-2, -2, 6, 6)));
}

TEST_CASE("tuiRectIntersectsLine")
{
	REQUIRE(!tuiRectIntersectsLine(tuiRect(0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiRectIntersectsLine(tuiRect(0, 0, 10, 10), tuiLine(2, 2, 6, 6)));
	REQUIRE(!tuiRectIntersectsLine(tuiRect(-10, -10, 20, 20), tuiLine(-25, 0, -23, 0)));
	REQUIRE(tuiRectIntersectsLine(tuiRect(0, 0, 10, 10), tuiLine(-2, -2, 6, 6)));
}

TEST_CASE("tuiRectIntersectsRect")
{
	REQUIRE(!tuiRectIntersectsRect(tuiRect(0, 0, 0, 0), tuiRect(0, 0, 0, 0)));
	REQUIRE(tuiRectIntersectsRect(tuiRect(0, 0, 5, 5), tuiRect(2, 2, 2, 2)));
	REQUIRE(tuiRectIntersectsRect(tuiRect(-10, -10, 20, 20), tuiRect(0, 0, 5, 5)));
	REQUIRE(!tuiRectIntersectsRect(tuiRect(0, 0, 10, 10), tuiRect(-10, -10, 5, 5)));
}