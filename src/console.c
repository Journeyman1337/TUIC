#include <TUIC/tuic.h>
#include "objects.h"

#include <string.h>
#include <stddef.h>
#include <assert.h>

const size_t TUIC_DATA_BYTES_PER_TILE = 18;

const size_t TUI_TILE_POSITION_OFFSET = 16384;

const size_t TUI_MAX_TILE_SIZE = 65565;

static size_t sConsoleCount = 0;

TuiResult tuiConsoleCreateTileDimensions(TuiConsole* console, int tiles_wide, int tiles_tall, float pixel_scale, int tile_width, int tile_height)
{
	assert(console != NULL);
	if (tiles_wide <= 0 || tiles_tall <= 0 || pixel_scale <= 0.0f || tile_width <= 0 || tile_height <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
	const int pixel_width = tiles_wide * tile_width * pixel_scale;
	const int pixel_height = tiles_tall * tile_height * pixel_scale;
	return tuiConsoleCreatePixelDimensions(console, pixel_width, pixel_height, pixel_scale, tile_width, tile_height, TUI_FALSE);
}

TuiResult tuiConsoleCreatePixelDimensions(TuiConsole* console, int pixel_width, int pixel_height, float pixel_scale, int tile_width, int tile_height, TuiBoolean floor_pixels_to_tiles)
{
	assert(console != NULL);
	if (pixel_width <= 0 pixel_height <= 0 || pixel_scale <= 0.0f || tile_width <= 0 || tile_height <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE
	}
    *console = (TuiConsole)tuiAllocate(sizeof(TuiConsole_s));
	if (*console == NULL)
	{
		return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	}
    memset(*console, 0, sizeof(TuiConsole_s));
    (*console)->PixelScale = pixel_scale;
    (*console)->TilesWide = (size_t)pixel_width / ((size_t)tile_width * pixel_scale);
    (*console)->TilesTall = (size_t)pixel_height / ((size_t)tile_height * pixel_scale);
    (*console)->TileWidth = (size_t)tile_width;
    (*console)->TileHeight = (size_t)tile_height;
    if (floor_pixels_to_tiles)
    {
         (*console)->PixelWidth =  (*console)->TilesWide *  (*console)->TileWidth * pixel_scale;
         (*console)->PixelHeight =  (*console)->TilesTall *  (*console)->TileHeight * pixel_scale;
    }
    else
    {
         (*console)->PixelWidth = (size_t)pixel_width;
         (*console)->PixelHeight = (size_t)pixel_height;
    }
    (*console)->TileDataCapacity =  (*console)->TilesWide *  (*console)->TilesTall;
    (*console) size_t reserved_data_size = sizeof(uint8_t) *  (*console)->TileDataCapacity * TUIC_DATA_BYTES_PER_TILE;
    (*console)->TileData = (TuiConsole)tuiAllocate(sizeof(TuiConsole_s));
	if ((*console)->TileData == NULL)
	{
		tuiFree(*console);
		*console = NULL;
		return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	}
	sConsoleCount++;
	return TUI_RESULT_OK;
}

void tuiConsoleDestroy(TuiConsole console)
{
	assert(console != NULL);
	tuiFree(console->TileData);
	tuiFree(console);
	sConsoleCount--;
}

float tuiConsoleGetPixelScale(TuiConsole console)
{
	assert(console != NULL);
    return console->PixelScale;
}

void tuiConsoleGetTileGridDimensions(TuiConsole console, int* const tiles_wide, int* const tiles_tall)
{
	assert(console != NULL);
    if (tiles_wide != NULL)
    {
        *tiles_wide = (int)console->TilesWide;
    }
    if (tiles_tall != NULL)
    {
        *tiles_tall = (int)console->TilesTall;
    }
}

void tuiConsoleGetPixelDimensions(TuiConsole console, int* const pixel_width, int* const pixel_height)
{
	assert(console != NULL);
    if (pixel_width != NULL)
    {
        *pixel_width = (int)console->PixelWidth;
    }
    if (pixel_height != NULL)
    {
        *pixel_height = (int)console->PixelHeight;
    }
}

void tuiConsoleGetTilePixelDimensions(TuiConsole console, int* const tile_width, int* const tile_height)
{
	assert(console != NULL);
    if (tile_width != NULL)
    {
        *tile_width = (int)console->TileWidth;
    }
    if (tile_height != NULL)
    {
        *tile_height = (int)console->TileHeight;
    }
}

void tuiConsoleResizeTileDimensions(TuiConsole console, const int tiles_wide, const int tiles_tall, const float pixel_scale, const int tile_width, const int tile_height)
{
	assert(console != NULL);
	if (tiles_wide <= 0 || tiles_tall <= 0 || pixel_scale <= 0.0f || tile_width <= 0 || tile_height <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
    const int pixel_width = tiles_wide * tile_width * pixel_scale;
    const int pixel_height = tiles_tall * tile_height * pixel_scale;

    tuiConsoleResizePixelDimensions(console, pixel_width, pixel_height, pixel_scale, tile_width, tile_height, TUI_FALSE);
}

void tuiConsoleResizePixelDimensions(TuiConsole console, const int pixel_width, const int pixel_height, const float pixel_scale, const int tile_width, const int tile_height, const TuiBoolean floor_pixels_to_tiles)
{
	assert(console != NULL);
	if (pixel_width <= 0 pixel_height <= 0 || pixel_scale <= 0.0f || tile_width <= 0 || tile_height <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE
	}
    console->PixelScale = pixel_scale;
    console->TilesWide = (size_t)pixel_width / ((size_t)tile_width * pixel_scale);
    console->TilesTall = (size_t)pixel_height / ((size_t)tile_height * pixel_scale);
    console->TileWidth = (size_t)tile_width;
    console->TileHeight = (size_t)tile_height;
    if (floor_pixels_to_tiles)
    {
        console->PixelWidth = console->TilesWide * console->TileWidth * pixel_scale;
        console->PixelHeight = console->TilesTall * console->TileHeight * pixel_scale;
    }
    else
    {
        console->PixelWidth = (size_t)pixel_width;
        console->PixelHeight = (size_t)pixel_height;
    }
    console->TileDataCount = 0;
}

void tuiConsoleClearTileData(TuiConsole console)
{
	assert(console != NULL);
    console->TileDataCount = 0;
}

size_t tuiConsoleGetTileCount(TuiConsole console)
{
	assert(console != NULL);
    return console->TileDataCount;
}

static inline TuiBoolean _tuiConsoleTryReserve(TuiConsole console)
{
    if (console->TileDataCount == console->TileDataCapacity)
    {
        size_t new_capacity = console->TileDataCapacity * 2;
        uint8_t* new_data_ptr = (uint8_t*)realloc(console->TileData, new_capacity * TUIC_DATA_BYTES_PER_TILE);
        if (new_data_ptr == NULL)
        {
            return TUI_FALSE; //out of memory
        }
        console->TileData = new_data_ptr;
        console->TileDataCapacity = new_capacity;
    }
    return TUI_TRUE;
}

static inline void _tuiConsolePushTile(TuiConsole console, const int pixel_x, const int pixel_y, const int pixel_w, const int pixel_h, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a)
{
    const unsigned int offset_pixel_x = (unsigned int)(pixel_x + TUI_TILE_POSITION_OFFSET);
    const unsigned int offset_pixel_y = (unsigned int)(pixel_y + TUI_TILE_POSITION_OFFSET);
    size_t index = console->TileDataCount * TUIC_DATA_BYTES_PER_TILE;
    console->TileData[index++] = offset_pixel_x & 0xff;
    console->TileData[index++] = (offset_pixel_x >> 8) & 0xff;
    console->TileData[index++] = offset_pixel_y & 0xff;
    console->TileData[index++] = (offset_pixel_y >> 8) & 0xff;
    console->TileData[index++] = pixel_w & 0xff;
    console->TileData[index++] = (pixel_w >> 8) & 0xff;
    console->TileData[index++] = pixel_h & 0xff;
    console->TileData[index++] = (pixel_h >> 8) & 0xff;
    console->TileData[index++] = (glyph) & 0xff;
    console->TileData[index++] = (glyph >> 8) & 0xff;
    console->TileData[index++] = fg_r;
    console->TileData[index++] = fg_g;
    console->TileData[index++] = fg_b;
    console->TileData[index++] = fg_a;
    console->TileData[index++] = bg_r;
    console->TileData[index++] = bg_g;
    console->TileData[index++] = bg_b;
    console->TileData[index++] = bg_a;
    console->TileDataCount++;
}

TuiResult tuiConsolePushFillTile(TuiConsole console, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a)
{
	assert(console != NULL);
	if (!_tuiConsoleTryReserve(console)) return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	_tuiConsolePushTile(console, 0, 0, console->PixelWidth, console->PixelHeight, glyph, fg_r, fg_g, fg_b, fg_a, bg_r, bg_g, bg_b, bg_a);
	return TUI_RESULT_OK;
}

TuiResult tuiConsolePushTileGrid(TuiConsole console, const int grid_x, const int grid_y, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a)
{
	assert(console != NULL);
	if (grid_x < 0 || grid_y < 0 || grid_x > console->TilesWide || grid_y > console->TilesTall) return TUI_RESULT_TILE_OUT_OF_CONSOLE;
	if (!_tuiConsoleTryReserve(console)) return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	const int pixel_x = grid_x * console->TileWidth;
    const int pixel_y = grid_y * console->TileHeight;
	_tuiConsolePushTile(console, pixel_x, pixel_y, console->TileWidth, console->TileHeight, glyph, fg_r, fg_g, fg_b, fg_a, bg_r, bg_g, bg_b, bg_a);
	return TUI_RESULT_OK;
}

TuiResult tuiConsolePushTileGridSized(TuiConsole console, const int grid_x, const int grid_y, const int tile_pixel_width, const int tile_pixel_height, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a)
{
	assert(console != NULL);
	if (grid_x < 0 || grid_y < 0 || grid_x > console->TilesWide || grid_y > console->TilesTall || tile_pixel_width <= 0 || tile_pixel_height <= 0 || tile_pixel_width > TUI_MAX_TILE_SIZE || tile_pixel_height > TUI_MAX_TILE_SIZE) return TUI_RESULT_TILE_OUT_OF_CONSOLE;
	if (!_tuiConsoleTryReserve(console)) return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	const unsigned int pixel_x = (unsigned int)grid_x * console->TileWidth;
    const unsigned int pixel_y = (unsigned int)grid_y * console->TileHeight;
    const unsigned int pixel_w_u = (unsigned int)tile_pixel_width;
    const unsigned int pixel_h_u = (unsigned int)tile_pixel_height;
	_tuiConsolePushTile(console, pixel_x, pixel_y, console->TileWidth, console->TileHeight, glyph, fg_r, fg_g, fg_b, fg_a, bg_r, bg_g, bg_b, bg_a);
	return TUI_RESULT_OK;
}

TuiResult tuiConsolePushTileFree(TuiConsole console, const int screen_pixel_x, const int screen_pixel_y, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a)
{
	assert(console != NULL);
	const int negative_default_width = -(int)console->TileWidth;
    const int negative_default_height = -(int)console->TileHeight;
	if (screen_pixel_x < negative_default_width || screen_pixel_y < negative_default_height || screen_pixel_x > (int)console->TileWidth || screen_pixel_y > (int)console->TileHeight) return TUI_RESULT_TILE_OUT_OF_CONSOLE;
	if (!_tuiConsoleTryReserve(console)) return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	_tuiConsolePushTile(console, (unsigned int)screen_pixel_x, (unsigned int)screen_pixel_y, console->TileWidth, console->TileHeight, glyph, fg_r, fg_g, fg_b, fg_a, bg_r, bg_g, bg_b, bg_a);
	return TUI_RESULT_OK;
}

TuiResult tuiConsolePushTileFreeSized(TuiConsole console, const int screen_pixel_x, const int screen_pixel_y, const int tile_pixel_width, const int tile_pixel_height, const uint16_t glyph, const uint8_t fg_r, const uint8_t fg_g, const uint8_t fg_b, const uint8_t fg_a, const uint8_t bg_r, const uint8_t bg_g, const uint8_t bg_b, const uint8_t bg_a)
{
	assert(console != NULL);
	if (screen_pixel_x < -tile_pixel_width || screen_pixel_y < -tile_pixel_height || screen_pixel_x > (int)console->PixelWidth || screen_pixel_y > (int)console->PixelHeight || tile_pixel_width <= 0 || tile_pixel_height <= 0 || tile_pixel_width > TUI_MAX_TILE_SIZE || tile_pixel_height > TUI_MAX_TILE_SIZE) return TUI_RESULT_TILE_OUT_OF_CONSOLE;
	if (!_tuiConsoleTryReserve(console)) return TUI_RESULT_ERROR_OUT_OF_MEMORY;
	_tuiConsolePushTile(console, (unsigned int)screen_pixel_x, (unsigned int)screen_pixel_y, console->TileWidth, console->TileHeight, glyph, fg_r, fg_g, fg_b, fg_a, bg_r, bg_g, bg_b, bg_a);
	return TUI_RESULT_OK;
}

size_t tuiGetConsoleCount()
{
	return sConsoleCount;
}