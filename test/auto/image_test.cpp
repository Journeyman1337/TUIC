#include <TUIC/tuic.h>
#include <iostream>
#include <catch2/catch.hpp>

uint8_t kRedPixels4x4RGB[4 * 4 * 3] =
{
	255, 0, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0,
	255, 0, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0,
	255, 0, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0,
	255, 0, 0, 255, 0, 0, 255, 0, 0, 255, 0, 0,
};

uint8_t kRedPixels4x4RGBA[4 * 4 * 4] =
{
	255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255,
	255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255,
	255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255,
	255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255
};

TEST_CASE("tuiImageEmplace") {
	TuiImage target = tuiImageCreate(10, 10, 3, TUI_NULL, TUI_FALSE);
	TuiImage to_emplace = tuiImageCreate(4, 4, 3, kRedPixels4x4RGB, TUI_TRUE);
	tuiImageEmplace(to_emplace, target, 0, 0);
	bool rgbEmplacePass = true;
	uint8_t* target_pixels = tuiImageGetPixels(target);
	for (size_t y = 0; y < 10; y++)
	{
		for (size_t x = 0; x < 10; x++)
		{
			for (size_t c = 0; c < 3; c++)
			{
				size_t pixel_i = (y * 10 * 3) + (x * 3) + c;
				if (x <= 3 && y <= 3)
				{
					if (
						(c == 0 && target_pixels[pixel_i] != 255) ||
						(c != 0 && target_pixels[pixel_i] != 0)
						)
					{
						rgbEmplacePass = false;
					}
				}
				else if (target_pixels[pixel_i] != 0)
				{
					rgbEmplacePass = false;
				}
			}
		}
	}
	REQUIRE(rgbEmplacePass == true);
	tuiImageDestroy(target);
	tuiImageDestroy(to_emplace);

	target = tuiImageCreate(10, 10, 4, TUI_NULL, TUI_FALSE);
	to_emplace = tuiImageCreate(4, 4, 4, kRedPixels4x4RGBA, TUI_TRUE);
	tuiImageEmplace(to_emplace, target, 0, 0);
	bool rgbaEmplacePass = true;
	target_pixels = tuiImageGetPixels(target);
	for (size_t y = 0; y < 10; y++)
	{
		for (size_t x = 0; x < 10; x++)
		{
			for (size_t c = 0; c < 4; c++)
			{
				size_t pixel_i = (y * 10 * 4) + (x * 4) + c;
				if (x <= 3 && y <= 3)
				{
					if (
						(c == 0 && target_pixels[pixel_i] != 255) ||
						(c == 3 && target_pixels[pixel_i] != 255) ||
						(c != 0 && c != 3 && target_pixels[pixel_i] != 0)
						)
					{
						rgbaEmplacePass = false;
					}
				}
				else if (target_pixels[pixel_i] != 0)
				{
					rgbaEmplacePass = false;
				}
			}
		}
	}
	REQUIRE(rgbaEmplacePass == true);
	tuiImageDestroy(target);
	tuiImageDestroy(to_emplace);
}
