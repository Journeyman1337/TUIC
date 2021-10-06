#include <TUIC/tuic.h>
#include <catch2/catch.hpp>


TEST_CASE("tuiBoxGetFarX")
{
	REQUIRE(tuiBoxGetFarX(tuiBox(0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiBoxGetFarX(tuiBox(0, 0, 100, 100, 1)) == 99);
	REQUIRE(tuiBoxGetFarX(tuiBox(10, 10, 100, 100, 1)) == 109);
	REQUIRE(tuiBoxGetFarX(tuiBox(-5, -5, -100, -100, 1)) == 94);
}

TEST_CASE("tuiBoxGetFarY")
{
	REQUIRE(tuiBoxGetFarY(tuiBox(0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiBoxGetFarY(tuiBox(0, 0, 100, 100, 1)) == 99);
	REQUIRE(tuiBoxGetFarY(tuiBox(10, 10, 100, 100, 1)) == 109);
	REQUIRE(tuiBoxGetFarY(tuiBox(-5, -5, -100, -100, 1)) == 94);
}

TEST_CASE("tuiBoxGetTileWidth")
{
	REQUIRE(tuiBoxGetTileWidth(tuiBox(0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiBoxGetTileWidth(tuiBox(0, 0, 4, 4, 1)) == 4);
	REQUIRE(tuiBoxGetTileWidth(tuiBox(0, 0, -4, -4, 1)) == 4);
}

TEST_CASE("tuiBoxGetTileHeight")
{
	REQUIRE(tuiBoxGetTileHeight(tuiBox(0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiBoxGetTileHeight(tuiBox(0, 0, 4, 4, 1)) == 4);
	REQUIRE(tuiBoxGetTileHeight(tuiBox(0, 0, -4, -4, 1)) == 4);
}

TEST_CASE("tuiBoxIsDegenerate")
{
	REQUIRE(tuiBoxIsDegenerate(tuiBox(0, 0, 0, 0, 0)));
	REQUIRE(tuiBoxIsDegenerate(tuiBox(0, 0, 1, 0, 1)));
	REQUIRE(tuiBoxIsDegenerate(tuiBox(0, 0, 0, 1, 1)));
	REQUIRE(!tuiBoxIsDegenerate(tuiBox(0, 0, 1, 1, 1)));
}

TEST_CASE("tuiBoxGetTopLeftCornerPoint2")
{
	{
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(0, 0, 10, 10, 1)).x == 0);
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(0, 0, 10, 10, 1)).y == 0);
	}

	{
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(10, 10, 10, 10, 1)).x == 10);
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(10, 10, 10, 10, 1)).y == 10);
	}

	{
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(10, 10, -10, -10, 1)).x == 10);
		REQUIRE(tuiBoxGetTopLeftCornerPoint2(tuiBox(10, 10, -10, -10, 1)).y == 10);
	}
}

TEST_CASE("tuiBoxGetTopRightCornerPoint2")
{
	{
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(0, 0, 10, 10, 1)).x == 9);
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(0, 0, 10, 10, 1)).y == 0);
	}

	{
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(10, 10, 10, 10, 1)).x == 19);
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(10, 10, 10, 10, 1)).y == 10);
	}

	{
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(10, 10, -10, -10, 1)).x == 19);
		REQUIRE(tuiBoxGetTopRightCornerPoint2(tuiBox(10, 10, -10, -10, 1)).y == 10);
	}
}

TEST_CASE("tuiBoxGetBottomLeftCornerPoint2")
{
	{
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(0, 0, 10, 10, 1)).x == 0);
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(0, 0, 10, 10, 1)).y == 9);
	}

	{
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(10, 10, 10, 10, 1)).x == 10);
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(10, 10, 10, 10, 1)).y == 19);
	}

	{
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(10, 10, -10, -10, 1)).x == 10);
		REQUIRE(tuiBoxGetBottomLeftCornerPoint2(tuiBox(10, 10, -10, -10, 1)).y == 19);
	}
}

TEST_CASE("tuiBoxGetBottomRightCornerPoint2")
{
	{
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(0, 0, 10, 10, 1)).x == 9);
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(0, 0, 10, 10, 1)).y == 9);
	}

	{
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(10, 10, 10, 10, 1)).x == 19);
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(10, 10, 10, 10, 1)).y == 19);
	}

	{
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(10, 10, -10, -10, 1)).x == 19);
		REQUIRE(tuiBoxGetBottomRightCornerPoint2(tuiBox(10, 10, -10, -10, 1)).y == 19);
	}
}

TEST_CASE("tuiBoxGetLeftBorderLine")
{
	{
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_y == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_y == 9);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_y == 1);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_y == 8);
	}

	{
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_y == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_y == 9);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_y == 1);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_x == 0);
		REQUIRE(tuiBoxGetLeftBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_y == 8);
	}
}

TEST_CASE("tuiBoxGetRightBorderLine")
{
	{
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_y == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_y == 0);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_y == 8);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_y == 1);
	}

	{
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_y == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_y == 0);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_y == 8);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_x == 9);
		REQUIRE(tuiBoxGetRightBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_y == 1);
	}
}

TEST_CASE("tuiBoxGetTopBorderLine")
{
	{
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_x == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_y == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_x == 9);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_y == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_x == 1);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_y == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_x == 8);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_y == 0);
	}

	{
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_x == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_y == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_x == 9);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_y == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_x == 1);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_y == 0);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_x == 8);
		REQUIRE(tuiBoxGetTopBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_y == 0);
	}
}

TEST_CASE("tuiBoxGetBottomBorderLine")
{
	{
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_x == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).start_y == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_x == 0);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_TRUE).end_y == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_x == 8);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).start_y == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_x == 1);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, 10, 10, 1), TUI_FALSE).end_y == 9);
	}

	{
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_x == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).start_y == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_x == 0);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_TRUE).end_y == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_x == 8);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).start_y == 9);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_x == 1);
		REQUIRE(tuiBoxGetBottomBorderLine(tuiBox(0, 0, -10, -10, 1), TUI_FALSE).end_y == 9);
	}
}

TEST_CASE("tuiBoxContainsPoint2")
{
	REQUIRE(!tuiBoxContainsPoint2(tuiBox(0, 0, 0, 0, 0), tuiPoint2(0, 0)));
	REQUIRE(!tuiBoxContainsPoint2(tuiBox(0, 0, 10, 10, 1), tuiPoint2(5, 5)));
	REQUIRE(tuiBoxContainsPoint2(tuiBox(0, 0, 10, 10, 1), tuiPoint2(0, 0)));
	REQUIRE(!tuiBoxContainsPoint2(tuiBox(-10, -10, 20, 20, 1), tuiPoint2(-25, 0)));
}

TEST_CASE("tuiBoxIntersectsLine")
{
	REQUIRE(!tuiBoxIntersectsLine(tuiBox(0, 0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiBoxIntersectsLine(tuiBox(0, 0, 10, 10, 1), tuiLine(2, 2, 11, 11)));
	REQUIRE(!tuiBoxIntersectsLine(tuiBox(-10, -10, 20, 20, 1), tuiLine(-25, 0, -23, 0)));
	REQUIRE(tuiBoxIntersectsLine(tuiBox(0, 0, 10, 10, 1), tuiLine(-2, -2, 6, 6)));
}

TEST_CASE("tuiBoxIntersectsBox")
{
	REQUIRE(!tuiBoxIntersectsBox(tuiBox(0, 0, 0, 0, 0), tuiBox(0, 0, 0, 0, 0)));
	REQUIRE(tuiBoxIntersectsBox(tuiBox(0, 0, 5, 5, 1), tuiBox(2, 2, 2, 3, 1)));
	REQUIRE(tuiBoxIntersectsBox(tuiBox(-10, -10, 20, 20, 1), tuiBox(0, 0, 5, 5, 1)));
	REQUIRE(!tuiBoxIntersectsBox(tuiBox(0, 0, 10 , 10, 1), tuiBox(-10, -10, 5, 5, 1)));
}