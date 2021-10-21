#include <TUIC/tuic.h>
#include <string>
#include <catch2/catch.hpp>


TEST_CASE("tuiCropBoxGetBoxFarX")
{
	REQUIRE(tuiCropBoxGetBoxFarX(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetBoxFarX(tuiCropBox(0, 0, 100, 100, 1, 0, 0, 100, 100)) == 99);
	REQUIRE(tuiCropBoxGetBoxFarX(tuiCropBox(10, 10, 100, 100, 1,99, 99, 4, 4)) == 109);
	REQUIRE(tuiCropBoxGetBoxFarX(tuiCropBox(-5, -5, -100, -100, 1,4,5,6,6)) == 94);
}

TEST_CASE("tuiCropBoxGetBoxFarY")
{
	REQUIRE(tuiCropBoxGetBoxFarY(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetBoxFarY(tuiCropBox(0, 0, 100, 100, 1, 0, 0, 100, 100)) == 99);
	REQUIRE(tuiCropBoxGetBoxFarY(tuiCropBox(10, 10, 100, 100, 1, 99, 99, 4, 4)) == 109);
	REQUIRE(tuiCropBoxGetBoxFarY(tuiCropBox(-5, -5, -100, -100, 1, 4, 5, 6, 6)) == 94);
}

TEST_CASE("tuiCropBoxGetBoxTileWidth")
{
	REQUIRE(tuiCropBoxGetBoxTileWidth(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetBoxTileWidth(tuiCropBox(0, 0, 4, 4, 1, 0, 0, 0, 0)) == 4);
	REQUIRE(tuiCropBoxGetBoxTileWidth(tuiCropBox(0, 0, -4, -4, 1, 10, 5, 0, -10)) == 4);
}

TEST_CASE("tuiCropBoxGetBoxTileHeight")
{
	REQUIRE(tuiCropBoxGetBoxTileHeight(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetBoxTileHeight(tuiCropBox(0, 0, 4, 4, 1, 0, 0, 0, 0)) == 4);
	REQUIRE(tuiCropBoxGetBoxTileHeight(tuiCropBox(0, 0, -4, -4, 1, 10, 5, 0, -10)) == 4);
}

TEST_CASE("tuiCropBoxGetLeftX")
{
	REQUIRE(tuiCropBoxGetLeftX(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetLeftX(tuiCropBox(0, 0, 10, 10, 2, 0, 0, 10, 10)) == 0);
	REQUIRE(tuiCropBoxGetLeftX(tuiCropBox(0, 0, 10, 10, 4, 4, 4, 10, 10)) == 4);
	REQUIRE(tuiCropBoxGetLeftX(tuiCropBox(-4, -4, 4, 4, 3, -10, -10, 2, 2)) == -9);
}

TEST_CASE("tuiCropBoxGetTopY")
{
	REQUIRE(tuiCropBoxGetTopY(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetTopY(tuiCropBox(0, 0, 10, 10, 2, 0, 0, 10, 10)) == 0);
	REQUIRE(tuiCropBoxGetTopY(tuiCropBox(0, 0, 10, 10, 4, 4, 4, 10, 10)) == 4);
	REQUIRE(tuiCropBoxGetTopY(tuiCropBox(-4, -4, 4, 4, 3, -10, -10, 2, 2)) == -9);
}

TEST_CASE("tuiCropBoxGetRightX")
{
	REQUIRE(tuiCropBoxGetRightX(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetRightX(tuiCropBox(0, 0, 10, 10, 2, 0, 0, 10, 10)) == 9);
	REQUIRE(tuiCropBoxGetRightX(tuiCropBox(0, 0, 10, 10, 4, 0, 0, 5, 5)) == 4);
	REQUIRE(tuiCropBoxGetRightX(tuiCropBox(-4, -4, 4, 4, 3, -10, -10, 2, 2)) == -9);
}


TEST_CASE("tuiCropBoxGetBottomY")
{
	REQUIRE(tuiCropBoxGetBottomY(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetBottomY(tuiCropBox(0, 0, 10, 10, 2, 0, 0, 10, 10)) == 9);
	REQUIRE(tuiCropBoxGetBottomY(tuiCropBox(0, 0, 10, 10, 4, 0, 0, 5, 5)) == 4);
	REQUIRE(tuiCropBoxGetBottomY(tuiCropBox(-4, -4, 4, 4, 3, -10, -10, 2, 2)) == -9);
}

TEST_CASE("tuiCropBoxIsFlippedWide")
{
	REQUIRE(!tuiCropBoxIsFlippedWide(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)));
	REQUIRE(tuiCropBoxIsFlippedWide(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 5, 5)));
	REQUIRE(!tuiCropBoxIsFlippedWide(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 5, 5)));
}

TEST_CASE("tuiCropBoxIsFlippedTall")
{
	REQUIRE(!tuiCropBoxIsFlippedTall(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)));
	REQUIRE(tuiCropBoxIsFlippedTall(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 5, 5)));
	REQUIRE(!tuiCropBoxIsFlippedTall(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 5, 5)));
}

TEST_CASE("tuiCropBoxIsDegenerate")
{
	REQUIRE(tuiCropBoxIsDegenerate(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)));
	REQUIRE(tuiCropBoxIsDegenerate(tuiCropBox(0, 0, 0, 0, 2, 0, 0, 5, 5)));
	REQUIRE(tuiCropBoxIsDegenerate(tuiCropBox(0, 0, 2, 2, 0, 0, 0, 5, 5)));
	REQUIRE(tuiCropBoxIsDegenerate(tuiCropBox(0, 0, 2, 2, 2, 0, 0, 0, 0)));
	REQUIRE(!tuiCropBoxIsDegenerate(tuiCropBox(0, 0, 5, 5, 2, 0, 0, 5, 5)));
}

TEST_CASE("tuiCropBoxGetBoundingRect")
{
	{
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).width == 1);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).height == 1);
	}

	{
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).x == 0);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).y == 0);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).width == 10);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).height == 10);
	}

	{
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).x == 2);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).y == 2);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).width == 4);
		REQUIRE(tuiCropBoxGetBoundingRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).height == 4);
	}
}

TEST_CASE("tuiCropBoxGetCropRect")
{
	{
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).y == 0);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).width == 0);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).height == 0);
	}

	{
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).x == -1);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).y == -1);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).width == 12);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)).height == 12);
	}

	{
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).x == 2);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).y == 2);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).width == 4);
		REQUIRE(tuiCropBoxGetCropRect(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)).height == 4);
	}
}

TEST_CASE("tuiCropBoxGetCropFarX")
{
	REQUIRE(tuiCropBoxGetCropFarX(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetCropFarX(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)) == 10);
	REQUIRE(tuiCropBoxGetCropFarX(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)) == 5);
}

TEST_CASE("tuiCropBoxGetCropFarY")
{
	REQUIRE(tuiCropBoxGetCropFarY(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)) == 0);
	REQUIRE(tuiCropBoxGetCropFarY(tuiCropBox(0, 0, 10, 10, 2, -1, -1, 12, 12)) == 10);
	REQUIRE(tuiCropBoxGetCropFarY(tuiCropBox(0, 0, 10, 10, 2, 2, 2, 4, 4)) == 5);
}

TEST_CASE("tuiCropBoxGetBoxTopLeftCornerPoint2")
{
	{
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).x == 10);
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).y == 10);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).x == 10);
		REQUIRE(tuiCropBoxGetBoxTopLeftCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).y == 10);
	}
}

TEST_CASE("tuiCropBoxGetBoxTopRightCornerPoint2")
{
	{
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).x == 9);
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).x == 19);
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).y == 10);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).x == 19);
		REQUIRE(tuiCropBoxGetBoxTopRightCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).y == 10);
	}
}

TEST_CASE("tuiCropBoxGetBoxBottomLeftCornerPoint2")
{
	{
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).y == 9);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).x == 10);
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).y == 19);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).x == 10);
		REQUIRE(tuiCropBoxGetBoxBottomLeftCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).y == 19);
	}
}

TEST_CASE("tuiCropBoxGetBoxBottomRightCornerPoint2")
{
	{
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).x == 0);
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)).y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).x == 9);
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0)).y == 9);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).x == 19);
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(10, 10, 10, 10, 1, 0, 0, 0, 0)).y == 19);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).x == 19);
		REQUIRE(tuiCropBoxGetBoxBottomRightCornerPoint2(tuiCropBox(10, 10, -10, -10, 1, 0, 0, 0, 0)).y == 19);
	}
}

TEST_CASE("tuiCropBoxGetBoxLeftBorderLine")
{
	{
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 9);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 1);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 8);
	}

	{
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 9);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 1);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 0);
		REQUIRE(tuiCropBoxGetBoxLeftBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 8);
	}
}

TEST_CASE("tuiCropBoxGetBoxRightBorderLine")
{
	{
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 0);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 8);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 1);
	}

	{
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 0);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 8);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 9);
		REQUIRE(tuiCropBoxGetBoxRightBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 1);
	}
}

TEST_CASE("tuiCropBoxGetBoxTopBorderLine")
{
	{
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 9);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 1);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 8);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 0);
	}

	{
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 9);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 1);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 0);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 8);
		REQUIRE(tuiCropBoxGetBoxTopBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 0);
	}
}

TEST_CASE("tuiCropBoxGetBoxBottomBorderLine")
{
	{
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 0);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 8);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 1);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 9);
	}

	{
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_x == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).start_y == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_x == 0);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_TRUE).end_y == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_x == 8);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).start_y == 9);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_x == 1);
		REQUIRE(tuiCropBoxGetBoxBottomBorderLine(tuiCropBox(0, 0, -10, -10, 1, 0, 0, 0, 0), TUI_FALSE).end_y == 9);
	}
}

TEST_CASE("tuiCropBoxContainsPoint2")
{
	REQUIRE(!tuiCropBoxContainsPoint2(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiPoint2(0, 0)));
	REQUIRE(tuiCropBoxContainsPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiPoint2(0, 0)));
	REQUIRE(!tuiCropBoxContainsPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiPoint2(5, 5)));
	REQUIRE(!tuiCropBoxContainsPoint2(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiPoint2(-5, -5)));
}

TEST_CASE("tuiCropBoxIntersectsLine")
{
	REQUIRE(!tuiCropBoxIntersectsLine(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiLine(0, 0, 0, 0)));
	REQUIRE(tuiCropBoxIntersectsLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiLine(0, 0, 5, 5)));
	REQUIRE(!tuiCropBoxIntersectsLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiLine(2, 2, 5, 5)));
	REQUIRE(!tuiCropBoxIntersectsLine(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiLine(-5, -5, -1, -1)));
}

TEST_CASE("tuiCropBoxIntersectsRect")
{
	REQUIRE(!tuiCropBoxIntersectsRect(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiRect(0,0,0,0)));
	REQUIRE(tuiCropBoxIntersectsRect(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiRect(0,0,5,5)));
	REQUIRE(!tuiCropBoxIntersectsRect(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiRect(2, 2, 5, 5)));
	REQUIRE(!tuiCropBoxIntersectsRect(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiRect(-5, -5, -1, -1)));
}

TEST_CASE("tuiCropBoxIntersectsBox")
{
	REQUIRE(!tuiCropBoxIntersectsBox(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiBox(0, 0, 0, 0, 0)));
	REQUIRE(tuiCropBoxIntersectsBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiBox(0, 0, 5, 5, 1)));
	REQUIRE(!tuiCropBoxIntersectsBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiBox(2, 2, 5, 5, 1)));
	REQUIRE(!tuiCropBoxIntersectsBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiBox(-5, -5, -1, -1, 1)));
	REQUIRE(!tuiCropBoxIntersectsBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiBox(-2, -2, 16, 16, 1)));
}

TEST_CASE("tuiCropBoxIntersectsCropBox")
{
	REQUIRE(!tuiCropBoxIntersectsCropBox(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0)));
	REQUIRE(tuiCropBoxIntersectsCropBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiCropBox(0, 0, 5, 5, 1, 0, 0, 5, 5)));
	REQUIRE(!tuiCropBoxIntersectsCropBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiCropBox(0, 0, 5, 5, 1, -10, -10, 5, 5)));
	REQUIRE(!tuiCropBoxIntersectsCropBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiCropBox(2, 2, 5, 5, 1, 2, 2, 5, 5)));
	REQUIRE(!tuiCropBoxIntersectsCropBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiCropBox(-5, -5, -1, -1, 1, -5, -5, -1, 1)));
	REQUIRE(!tuiCropBoxIntersectsCropBox(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 10, 10), tuiCropBox(-2, -2, 16, 16, 1, -2, -2, 16, 16)));

}

TEST_CASE("tuiCropBoxIntersectsCircle")
{
	REQUIRE(!tuiCropBoxIntersectsCircle(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiCircle(0, 0, 0.0f)));
	REQUIRE(tuiCropBoxIntersectsCircle(tuiCropBox(0, 0, 10, 10, 3, 0, 0, 5, 5), tuiCircle(0, 0, 4.0f)));
	REQUIRE(!tuiCropBoxIntersectsCircle(tuiCropBox(0, 0, 10, 10, 1, 5, 5, 5, 5), tuiCircle(0, 0, 4.0f)));
	REQUIRE(!tuiCropBoxIntersectsCircle(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 5, 5), tuiCircle(-10, -10, 4.0f)));
}

TEST_CASE("tuiCropBoxIntersectsRing")
{
	REQUIRE(!tuiCropBoxIntersectsRing(tuiCropBox(0, 0, 0, 0, 0, 0, 0, 0, 0), tuiRing(0, 0, 0.0f, 0.0f)));
	REQUIRE(tuiCropBoxIntersectsRing(tuiCropBox(0, 0, 10, 10, 3, 0, 0, 5, 5), tuiRing(0, 0, 4.0f, 2.0f)));
	REQUIRE(!tuiCropBoxIntersectsRing(tuiCropBox(0, 0, 10, 10, 1, 5, 5, 5, 5), tuiRing(0, 0, 4.0f, 2.0f)));
	REQUIRE(!tuiCropBoxIntersectsRing(tuiCropBox(0, 0, 10, 10, 1, 0, 0, 5, 5), tuiRing(-10, -10, 4.0f, 2.0f)));
}