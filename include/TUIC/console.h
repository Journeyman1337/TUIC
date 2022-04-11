/*
	Copyright (c) 2021 Daniel Valcour
	
	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/*! \file console.h
 */
#ifndef TUIC_CONSOLE_H //header guard
#define TUIC_CONSOLE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <TUIC/boolean.h>

TuiConsole tuiConsoleCreateTileDimensions(const int tiles_wide, const int tiles_tall, const float pixel_scale, const int tile_width, const int tile_height);

TuiConsole tuiConsoleCreatePixelDimensions(const int pixel_width, const int pixel_height, const float pixel_scale, const int tile_width, const int tile_height, const TuiBoolean floor_pixels_to_tiles);

void tuiConsoleDestroy(TuiConsole console);

float tuiConsoleGetPixelScale(TuiConsole console);

void tuiConsoleGetTileGridDimensions(TuiConsole console, int* const tiles_wide, int* const tiles_tall);

void tuiConsoleGetPixelDimensions(TuiConsole console, int* const pixel_width, int* const pixel_height);

void tuiConsoleGetTilePixelDimensions(TuiConsole console, int* const tile_width, int* const tile_height);

void tuiConsoleResizeTileDimensions(TuiConsole console, const int tiles_wide, const int tiles_tall, const float pixel_scale, const int tile_width, const int tile_height);

void tuiConsoleResizePixelDimensions(TuiConsole console, const int pixel_width, const int pixel_height, const float pixel_scale, const int tile_width, const int tile_height, const TuiBoolean floor_pixels_to_tiles);

void tuiConsoleClearTileData(TuiConsole console);

size_t tuiConsoleGetTileCount(TuiConsole console);

void tuiConsolePushFillTile(TuiConsole console, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a);

void tuiConsolePushTileGrid(TuiConsole console, const int grid_x, const int grid_y, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a);

void tuiConsolePushTileGridSized(TuiConsole console, const int screen_pixel_x, const int screen_pixel_y, const int tile_pixel_width, const int tile_pixel_height, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a);

void tuiConsolePushTileFree(TuiConsole console, const int screen_pixel_x, const int screen_pixel_y, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a);

void tuiConsolePushTileFreeSized(TuiConsole console, const int screen_pixel_x, const int screen_pixel_y, const int tile_pixel_width, const int tile_pixel_height, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard