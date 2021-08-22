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
#include <TUIC/tuic.h>
#include "objects.h"
#include <string.h>

TuiBatch tuiBatchCreateFull(TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t minimum_reserved_data_size)
{
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return TUI_NULL;
	}
	if (tuiDetailGetLayoutFlag(detail_mode) != TUI_DETAIL_FLAG_LAYOUT_FULL)
	{
		// TODO TUI_ERROR_INVALID_BATCH_CREATION
		return TUI_NULL;
	}

	TuiBatchFull_s* batch = tuiAllocate(sizeof(TuiBatchFull_s));

	batch->DetailMode = detail_mode;
	batch->TilesWide = tiles_wide;
	batch->TilesTall = tiles_tall;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->UsedDataSize = batch->BytesPerTile * batch->TilesWide * batch->TilesTall * sizeof(uint8_t);
	if (batch->UsedDataSize > minimum_reserved_data_size)
	{
		minimum_reserved_data_size = batch->UsedDataSize;
	}
	batch->ReservedDataSize = minimum_reserved_data_size;
	batch->Data = tuiAllocate(batch->ReservedDataSize);
	batch->TileCount = batch->TilesWide * batch->TilesTall;

	return batch;
}

TuiBatch tuiBatchCreateSparse(TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, TuiBoolean use_stencil, size_t minimum_reserved_data_size)
{
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return TUI_NULL;
	}
	if (tuiDetailGetLayoutFlag(detail_mode) != TUI_DETAIL_FLAG_LAYOUT_SPARSE)
	{
		// TODO TUI_ERROR_INVALID_BATCH_CREATION
		return TUI_NULL;
	}

	TuiBatchSparse_s* batch = tuiAllocate(sizeof(TuiBatchSparse_s));

	batch->DetailMode = detail_mode;
	batch->TilesWide = tiles_wide;
	batch->TilesTall = tiles_tall;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->TileCount = 0;
	batch->HasLargeXCoordinate = TUI_FALSE;
	batch->HasLargeYCoordinate = TUI_FALSE;
	batch->UseStencil = use_stencil;
	batch->StencilData = TUI_NULL;
	batch->StencilDataSize = 0;
	if (use_stencil == TUI_TRUE)
	{
		batch->StencilDataSize = batch->TilesWide * batch->TilesTall * sizeof(size_t);
		batch->StencilData = (size_t*)tuiAllocate(batch->StencilDataSize);
	}
	batch->BytesPerTile += 2; //Sparse batches have at least two extra bytes per tile for the coordinates of each tile
	if (tiles_wide > 256) //if the width or the height is greater than 256, two bytes are needed for each respective coordinate to store values large enough
	{
		batch->HasLargeXCoordinate = TUI_TRUE;
		batch->BytesPerTile++;
	}
	if (tiles_tall > 256)
	{
		batch->HasLargeYCoordinate = TUI_TRUE;
		batch->BytesPerTile++;
	}
	batch->ReservedDataSize = batch->BytesPerTile * batch->TilesWide * batch->TilesTall * sizeof(uint8_t);
	if (batch->ReservedDataSize > minimum_reserved_data_size)
	{
		batch->ReservedDataSize = minimum_reserved_data_size;
	}
	batch->Data = tuiAllocate(batch->ReservedDataSize);

	return batch;
}

TuiBatch tuiBatchCreateFree(TuiDetailMode detail_mode, int tile_pixel_width, int tile_pixel_height, int reserved_tile_count, float pixel_scale, size_t minimum_reserved_data_size)
{
	if (tile_pixel_width <= 0 || tile_pixel_height <= 0)
	{
		// TODO TUI_ERROR_INVALID_BATCH_TILE_PIXEL_DIMENSIONS
		return TUI_NULL;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{ 
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return TUI_NULL;
	}
	if (tuiDetailGetLayoutFlag(detail_mode) != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		// TODO TUI_ERROR_INVALID_BATCH_CREATION
		return TUI_NULL;
	}

	TuiBatchFree_s* batch = tuiAllocate(sizeof(TuiBatchFree_s));

	batch->DetailMode = detail_mode;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->BytesPerTile += 4; //Free batches have 2 uint16_t for the x and y positions of each tile.
	size_t TilePixelWidth;

	size_t TilePixelHeight;

	float TilePixelScale;

	size_t MaxTileCount;
}

void tuiBatchDestroy(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}

	if (batch->SparseUsedIndices != TUI_NULL)
	{
		tuiFree(batch->SparseUsedIndices);
	}
	tuiFree(batch->Data);
	tuiFree(batch);
}

TuiDetailMode tuiBatchGetDetail(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	
	return batch->DetailMode;
}

void tuiBatchSetTileDimensions(TuiBatch batch, int tiles_wide, int tiles_tall, TuiBoolean reserve_extra)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DIMENSIONS, __func__);
		return;
	}

	batch->TilesWide = (size_t)tiles_wide;
	batch->TilesTall = (size_t)tiles_tall;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(batch->DetailMode), tuiDetailGetColorFlag(batch->DetailMode));
	batch->IsLargeSparseWide = TUI_FALSE;
	batch->IsLargeSparseTall = TUI_FALSE;
	batch->SparseUsedIndices = TUI_NULL;
	batch->SparseUsedIndicesSize = 0;
	if (tuiDetailHasFlag(batch->DetailMode, TUI_DETAIL_FLAG_LAYOUT_SPARSE) == TUI_TRUE)
	{
		batch->TileCount = 0;
		batch->BytesPerTile += 2;
		if (tiles_wide > 256)
		{
			batch->IsLargeSparseWide = TUI_TRUE;
			batch->BytesPerTile++;
		}
		if (tiles_tall > 256)
		{
			batch->IsLargeSparseTall = TUI_TRUE;
			batch->BytesPerTile++;
		}
		batch->SparseUsedIndicesSize = batch->TilesWide * batch->TilesTall * sizeof(size_t);
		batch->SparseUsedIndices = tuiReallocate(batch->SparseUsedIndices, batch->SparseUsedIndicesSize);
	}
	else
	{
		batch->TileCount = batch->TilesWide * batch->TilesTall;
	}
	batch->UsedDataSize = batch->BytesPerTile * batch->TilesWide * batch->TilesTall * sizeof(uint8_t);
	if (reserve_extra == TUI_FALSE || batch->UsedDataSize > batch->ReservedDataSize)
	{
		batch->ReservedDataSize = batch->UsedDataSize;
		batch->Data = tuiReallocate(batch->Data, batch->ReservedDataSize);
	}
}

void tuiBatchGetTileDimensions(TuiBatch batch, int* tiles_wide, int* tiles_tall)
{	
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}

	if(tiles_wide != TUI_NULL)
	{
		*tiles_wide = batch->TilesWide;
	}
	if (tiles_tall != TUI_NULL)
	{
		*tiles_tall = batch->TilesTall;
	}
}

int tuiBatchGetTilesWide(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	return batch->TilesWide;
}

int tuiBatchGetTilesTall(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	return batch->TilesTall;
}

int tuiBatchGetDataSize(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	return batch->UsedDataSize;
}

int tuiBatchGetReservedSize(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	return batch->ReservedDataSize;
}

int tuiBatchGetTileCount(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	return batch->TileCount;
}

const uint8_t* tuiBatchGetData(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return TUI_NULL;
	}

	return batch->Data;
}

void tuiBatchClear(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	
	if (tuiDetailHasFlag(batch->DetailMode, TUI_DETAIL_FLAG_LAYOUT_SPARSE))
	{
		batch->TileCount = 0;
		memset(batch->SparseUsedIndices, 0, batch->SparseUsedIndicesSize);
	}
	else
	{
		memset(batch->Data, 0, batch->UsedDataSize);
	}
}

void tuiBatchSetTile_G0_C8NBG_FULL(TuiBatch batch, int x, int y, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C8NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G0_C8NBG_Size
		+ (size_t)x * kTui_Detail_G0_C8NBG_Size;
	batch->Data[tile_index] = fg;
}

void tuiBatchSetTile_G0_C24NBG_FULL(TuiBatch batch, int x, int y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C24NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G0_C24NBG_Size
		+ (size_t)x * kTui_Detail_G0_C24NBG_Size;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index] = fg_b;
}

void tuiBatchSetTile_G0_C32NBG_FULL(TuiBatch batch, int x, int y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C32NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G0_C32NBG_Size
		+ (size_t)x * kTui_Detail_G0_C32NBG_Size;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index] = fg_a;
}

void tuiBatchSetTile_G8_C0_FULL(TuiBatch batch, int x, int y, uint8_t glyph)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C0_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C0_Size
		+ (size_t)x * kTui_Detail_G8_C0_Size;
	batch->Data[tile_index] = glyph;
}

void tuiBatchSetTile_G8_C4_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t colors)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C4_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C4_Size + (size_t)x * kTui_Detail_G8_C4_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index] = colors;
}

void tuiBatchSetTile_G8_C8_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C8_Size + (size_t)x * kTui_Detail_G8_C8_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G8_C8NBG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C8NBG_Size + (size_t)x * kTui_Detail_G8_C8NBG_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index] = fg;
}

void tuiBatchSetTile_G8_C8NFG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8NFG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	} 
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C8NFG_Size + (size_t)x * kTui_Detail_G8_C8NFG_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G8_C24_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C24_Size + (size_t)x * kTui_Detail_G8_C24_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;	
}

void tuiBatchSetTile_G8_C24NBG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C24NBG_Size + (size_t)x * kTui_Detail_G8_C24NBG_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index] = fg_b;
}

void tuiBatchSetTile_G8_C24NFG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24NFG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C24NFG_Size + (size_t)x * kTui_Detail_G8_C24NFG_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;
}


void tuiBatchSetTile_G8_C32_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C32_Size + (size_t)x * kTui_Detail_G8_C32_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = fg_a;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G8_C32NBG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C32NBG_Size + (size_t)x * kTui_Detail_G8_C32NBG_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index] = fg_a;
}

void tuiBatchSetTile_G8_C32NFG_FULL(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32NFG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G8_C32NFG_Size + (size_t)x * kTui_Detail_G8_C32NFG_Size;
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G16_C0_FULL(TuiBatch batch, int x, int y, uint16_t glyph)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C0_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C0_Size + (size_t)x * kTui_Detail_G16_C0_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index] = (glyph >> 8) & 0xff;
}

void tuiBatchSetTile_G16_C4_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t colors)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C4_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C4_Size + (size_t)x * kTui_Detail_G16_C4_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index] = colors;
}

void tuiBatchSetTile_G16_C8_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x >= batch->TilesWide || y >= batch->TilesTall || x < 0 || y < 0)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C8_Size + (size_t)x * kTui_Detail_G16_C8_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G16_C8NBG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C8NBG_Size + (size_t)x * kTui_Detail_G16_C8NBG_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index] = fg;
}

void tuiBatchSetTile_G16_C8NFG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8NFG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C8NFG_Size + (size_t)x * kTui_Detail_G16_C8NFG_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G16_C24_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C24_Size + (size_t)x * kTui_Detail_G16_C24_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;	
}

void tuiBatchSetTile_G16_C24NBG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C24NBG_Size + (size_t)x * kTui_Detail_G16_C24NBG_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index] = fg_b;
}

void tuiBatchSetTile_G16_C24NFG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24NFG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C24NFG_Size + (size_t)x * kTui_Detail_G16_C24NFG_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;
}

void tuiBatchSetTile_G16_C32_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C32_Size + (size_t)x * kTui_Detail_G16_C32_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = fg_a;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G16_C32NBG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32NBG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C32NBG_Size + (size_t)x * kTui_Detail_G16_C32NBG_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index] = fg_a;
}

void tuiBatchSetTile_G16_C32NFG_FULL(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32NFG_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch->TilesWide * kTui_Detail_G16_C32NFG_Size + (size_t)x * kTui_Detail_G16_C32NFG_Size;
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b; 
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G0_C8NBG_SPARSE(TuiBatch batch, int x, int y, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C8NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
		batch->TileCount++;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index] = fg;
}

void tuiBatchSetTile_G0_C24NBG_SPARSE(TuiBatch batch, int x, int y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C24NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
		batch->TileCount++;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index] = fg_b;
}

void tuiBatchSetTile_G0_C32NBG_SPARSE(TuiBatch batch, int x, int y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C32NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
		batch->TileCount++;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index] = fg_a;
}

void tuiBatchSetTile_G8_C0_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C0_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
		batch->TileCount++;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index] = glyph;
}

void tuiBatchSetTile_G8_C4_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t colors)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C4_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesWide * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0) // if the tile already is already set
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1; // override previously set index
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile; //create a new tile and increment the total tile count since last clear
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide) // if two bytes for x or y coordinate, store extra data
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index] = colors;
}

void tuiBatchSetTile_G8_C8_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G8_C8NBG_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index] = fg;
}

void tuiBatchSetTile_G8_C8NFG_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8NFG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G8_C24_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;
}

void tuiBatchSetTile_G8_C24NBG_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index] = fg_b;
}

void tuiBatchSetTile_G8_C24NFG_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24NFG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;
}

void tuiBatchSetTile_G8_C32_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = fg_a;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G8_C32NBG_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index] = fg_a;
}

void tuiBatchSetTile_G8_C32NFG_SPARSE(TuiBatch batch, int x, int y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32NFG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = glyph;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G16_C0_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C0_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index] = (glyph >> 8) & 0xff;
}

void tuiBatchSetTile_G16_C4_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t colors)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C4_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index] = colors;
}

void tuiBatchSetTile_G16_C8_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G16_C8NBG_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index] = fg;
}

void tuiBatchSetTile_G16_C8NFG_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8NFG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index] = bg;
}

void tuiBatchSetTile_G16_C24_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;
}

void tuiBatchSetTile_G16_C24NBG_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index] = fg_b;
}

void tuiBatchSetTile_G16_C24NFG_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24NFG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}
	
	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index] = bg_b;
}

void tuiBatchSetTile_G16_C32_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index++] = fg_a;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}

void tuiBatchSetTile_G16_C32NBG_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32NBG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = fg_r;
	batch->Data[tile_index++] = fg_g;
	batch->Data[tile_index++] = fg_b;
	batch->Data[tile_index] = fg_a;
}

void tuiBatchSetTile_G16_C32NFG_SPARSE(TuiBatch batch, int x, int y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32NFG_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_SETTER, __func__);
		return;
	}
	if (x < 0 || y < 0 || (size_t)x >= batch->TilesWide || (size_t)y >= batch->TilesTall)
	{
		return;
	}

	size_t tile_index;
	size_t used_tile_index = ((size_t)batch->TilesTall * (size_t)y) + (size_t)x;
	if (batch->SparseUsedIndices[used_tile_index] != 0)
	{
		tile_index = batch->SparseUsedIndices[used_tile_index] - 1;
	}
	else
	{
		tile_index = batch->TileCount * batch->BytesPerTile;
		batch->SparseUsedIndices[used_tile_index] = tile_index + 1;
		batch->TileCount++;
	}
	batch->Data[tile_index++] = ((unsigned int)x) & 0xff;
	if (batch->IsLargeSparseWide)
	{
		batch->Data[tile_index++] = ((unsigned int)x >> 8) & 0xff;
	}
	batch->Data[tile_index++] = ((unsigned int)y) & 0xff;
	if (batch->IsLargeSparseTall)
	{
		batch->Data[tile_index++] = ((unsigned int)y >> 8) & 0xff;
	}
	batch->Data[tile_index++] = (glyph) & 0xff;
	batch->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch->Data[tile_index++] = bg_r;
	batch->Data[tile_index++] = bg_g;
	batch->Data[tile_index++] = bg_b;
	batch->Data[tile_index] = bg_a;
}