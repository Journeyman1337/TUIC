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

#include <stddef.h>
#include <stdint.h>

typedef TuiConsole_s* TuiConsole;
typedef enum TuiResult_e TuiResult;
typedef uint8_t TuiBoolean;
typedef uint16_t TuiGlyph;

extern const size_t TUIC_CONSOLE_DATA_BYTES_PER_TILE;

extern const size_t TUI_CONSOLE_DATA_TILE_POSITION_OFFSET;

extern const size_t TUI_CONSOLE_MAX_TILE_DIMENSIONS;

TuiResult tuiConsoleCreateTileDimensions(TuiConsole* console, int tiles_wide, int tiles_tall, float pixel_scale, int tile_width, int tile_height);

TuiResult tuiConsoleCreatePixelDimensions(TuiConsole* console, int pixel_width, int pixel_height, float pixel_scale, int tile_width, int tile_height, TuiBoolean floor_pixels_to_tiles);

void tuiConsoleDestroy(TuiConsole console);

float tuiConsoleGetPixelScale(TuiConsole console);

void tuiConsoleGetTileGridDimensions(TuiConsole console, int* tiles_wide, int* tiles_tall);

void tuiConsoleGetPixelDimensions(TuiConsole console, int* pixel_width, int* pixel_height);

void tuiConsoleGetTilePixelDimensions(TuiConsole console, int* tile_width, int* tile_height);

TuiResult tuiConsoleResizeTileDimensions(TuiConsole console, int tiles_wide, int tiles_tall, float pixel_scale, int tile_width, int tile_height);

TuiResult tuiConsoleResizePixelDimensions(TuiConsole console, int pixel_width, int pixel_height, float pixel_scale, int tile_width, int tile_height, TuiBoolean floor_pixels_to_tiles);

void tuiConsoleClearTileData(TuiConsole console);

size_t tuiConsoleGetTileCount(TuiConsole console);

TuiResult tuiConsolePushFillTile(TuiConsole console, TuiGlyph glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);

TuiResult tuiConsolePushTileGrid(TuiConsole console, TuiGlyph glyph, int grid_x, int grid_y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);

TuiResult tuiConsolePushTileGridSized(TuiConsole console, TuiGlyph glyph, int grid_x, int grid_y, int tile_pixel_width, int tile_pixel_height, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);

TuiResult tuiConsolePushTileFree(TuiConsole console, TuiGlyph glyph, int screen_pixel_x, int screen_pixel_y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);

TuiResult tuiConsolePushTileFreeSized(TuiConsole console, TuiGlyph glyph, int screen_pixel_x, int screen_pixel_y, int tile_pixel_width, int tile_pixel_height, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a);

size_t tuiGetConsoleCount();

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard