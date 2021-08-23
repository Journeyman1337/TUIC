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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return TUI_NULL;
	}

	TuiBatchFull_s* batch = tuiAllocate(sizeof(TuiBatchFull_s));

	batch->DetailMode = detail_mode;
	batch->TilesWide = tiles_wide;
	batch->TilesTall = tiles_tall;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->UsedDataSize = batch->BytesPerTile * batch->TilesWide * batch->TilesTall;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
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
	batch->UsedDataSize = batch->BytesPerTile * batch->TilesWide * batch->TilesTall;
	batch->ReservedDataSize = batch->UsedDataSize;
	if (batch->UsedDataSize > minimum_reserved_data_size)
	{
		batch->ReservedDataSize = minimum_reserved_data_size;
	}
	batch->Data = tuiAllocate(batch->ReservedDataSize);

	return batch;
}

TuiBatch tuiBatchCreateFree(TuiDetailMode detail_mode, int tile_pixel_width, int tile_pixel_height, int draw_viewport_width, int draw_viewport_height, int maximum_tile_count, size_t minimum_reserved_data_size)
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return TUI_NULL;
	}

	TuiBatchFree_s* batch = tuiAllocate(sizeof(TuiBatchFree_s));

	batch->DetailMode = detail_mode;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->BytesPerTile += 4; //Free batches have 2 uint16_t for the x and y positions of each tile. Unlike with sparse batches, coordinates are never optimized to 1 bytes.
	batch->TilePixelWidth = tile_pixel_width;
	batch->TilePixelHeight = tile_pixel_height;
	batch->DrawViewportWidth = draw_viewport_width;
	batch->DrawViewportHeight = draw_viewport_height;
	batch->MaxTileCount = maximum_tile_count;
	batch->UsedDataSize = batch->BytesPerTile * batch->MaxTileCount;
	batch->ReservedDataSize = batch->UsedDataSize;
	if (batch->UsedDataSize > minimum_reserved_data_size)
	{
		batch->ReservedDataSize = minimum_reserved_data_size;
	}
	batch->Data = tuiAllocate(batch->ReservedDataSize);

	return batch;
}

void tuiBatchDestroy(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}

	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);

	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		{
			TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
			tuiFree(batch_full->Data);
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		{
			TuiBatchSparse_s * batch_sparse = (TuiBatchSparse_s*)batch;
			if (batch_sparse->StencilData != TUI_NULL)
			{
				tuiFree(batch_sparse->StencilData);
			}
			tuiFree(batch_sparse->Data);
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
		{
			TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
			tuiFree(batch_free->Data);
		}
		break;
	}

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
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag == TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}

	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		{
			TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
			batch_full->TilesWide = (size_t)tiles_wide;
			batch_full->TilesTall = (size_t)tiles_tall;
			batch_full->TileCount = batch_full->TilesWide * batch_full->TilesTall;
			batch_full->UsedDataSize = batch_full->BytesPerTile * batch_full->TileCount;
			if (reserve_extra == TUI_FALSE || batch_full->UsedDataSize > batch_full->ReservedDataSize)
			{
				batch_full->ReservedDataSize = batch_full->UsedDataSize;
				batch_full->Data = tuiReallocate(batch_full->Data, batch_full->ReservedDataSize);
			}
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		{
			TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
			batch_sparse->TilesWide = (size_t)tiles_wide;
			batch_sparse->TilesTall = (size_t)tiles_tall;
			batch_sparse->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(batch->DetailMode), tuiDetailGetColorFlag(batch->DetailMode));
			batch_sparse->HasLargeXCoordinate = TUI_FALSE;
			batch_sparse->HasLargeYCoordinate = TUI_FALSE;
			batch_sparse->TileCount = 0;
			batch_sparse->BytesPerTile += 2;
			if (tiles_wide > 256)
			{
				batch_sparse->HasLargeXCoordinate = TUI_TRUE;
				batch_sparse->BytesPerTile++;
			}
			if (tiles_tall > 256)
			{
				batch_sparse->HasLargeYCoordinate = TUI_TRUE;
				batch_sparse->BytesPerTile++;
			}
			if (batch_sparse->UseStencil)
			{
				batch_sparse->StencilDataSize = batch_sparse->TilesWide * batch_sparse->TilesTall * sizeof(size_t);
				tuiReallocate(batch_sparse->StencilData, batch_sparse->StencilDataSize);
			}
			batch_sparse->UsedDataSize = batch_sparse->BytesPerTile * batch_sparse->TilesWide * batch_sparse->TilesTall;
			if (reserve_extra == TUI_FALSE || batch_sparse->UsedDataSize > batch_sparse->ReservedDataSize)
			{
				batch_sparse->ReservedDataSize = batch_sparse->UsedDataSize;
				batch_sparse->Data = tuiReallocate(batch_sparse->Data, batch_sparse->ReservedDataSize);
			}
		}
		break;
	}
}

void tuiBatchGetTileDimensions(TuiBatch batch, int* tiles_wide, int* tiles_tall)
{	
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag == TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}

	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		{
			TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
			if (tiles_wide != TUI_NULL)
			{
				*tiles_wide = batch_full->TilesWide;
			}
			if (tiles_tall != TUI_NULL)
			{
				*tiles_tall = batch_full->TilesTall;
			}
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		{
			TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
			if (tiles_wide != TUI_NULL)
			{
				*tiles_wide = batch_sparse->TilesWide;
			}
			if (tiles_tall != TUI_NULL)
			{
				*tiles_tall = batch_sparse->TilesTall;
			}
		}
		break;
	}
}

int tuiBatchGetTilesWide(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag == TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}

	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		{
			TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
			return batch_full->TilesWide;
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		{
			TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
			return batch_sparse->TilesWide;
		}
		break;
	}
	return 0;
}

int tuiBatchGetTilesTall(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag == TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}

	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		{
			TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
			return batch_full->TilesTall;
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		{
			TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
			return batch_sparse->TilesTall;
		}
		break;
	}
	return 0;
}

int tuiBatchGetDataSize(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
		{
			TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
			return batch_full->UsedDataSize;
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
		{
			TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
			return batch_sparse->UsedDataSize;
		}
		break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
		{
			TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
			return batch_free->UsedDataSize;
		}
		break;
	}
	return 0;
}

int tuiBatchGetReservedSize(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
	{
		TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
		return batch_full->ReservedDataSize;
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
	{
		TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
		return batch_sparse->ReservedDataSize;
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
	{
		TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
		return batch_free->ReservedDataSize;
	}
	break;
	}
	return 0;
}

int tuiBatchGetTileCount(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}

	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
	{
		TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
		return batch_full->TileCount;
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
	{
		TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
		return batch_sparse->TileCount;
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
	{
		TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
		return batch_free->TileCount;
	}
	break;
	}
	return 0;
}

const uint8_t* tuiBatchGetData(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return TUI_NULL;
	}

	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
	{
		TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
		return batch_full->Data;
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
	{
		TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
		return batch_sparse->Data;
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
	{
		TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
		return batch_free->Data;
	}
	break;
	}
	return 0;

}

void tuiBatchClear(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	switch (layout_flag)
	{
	case TUI_DETAIL_FLAG_LAYOUT_FULL:
	{
		TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
		memset(batch_full->Data, 0, batch_full->UsedDataSize);
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_SPARSE:
	{
		TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
		batch_sparse->TileCount = 0;
		if (batch_sparse->UseStencil)
		{
			memset(batch_sparse->StencilData, 0, batch_sparse->StencilDataSize);
		}
	}
	break;
	case TUI_DETAIL_FLAG_LAYOUT_FREE:
	{
		TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
		batch_free->TileCount = 0;
	}
	break;
	}
	return 0;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G0_C8NBG_Size
		+ (size_t)x * kTui_Detail_G0_C8NBG_Size;
	batch_full->Data[tile_index] = fg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G0_C24NBG_Size
		+ (size_t)x * kTui_Detail_G0_C24NBG_Size;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index] = fg_b;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G0_C32NBG_Size
		+ (size_t)x * kTui_Detail_G0_C32NBG_Size;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index] = fg_a;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C0_Size
		+ (size_t)x * kTui_Detail_G8_C0_Size;
	batch_full->Data[tile_index] = glyph;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C4_Size + (size_t)x * kTui_Detail_G8_C4_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index] = colors;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C8_Size + (size_t)x * kTui_Detail_G8_C8_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = fg;
	batch_full->Data[tile_index] = bg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C8NBG_Size + (size_t)x * kTui_Detail_G8_C8NBG_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index] = fg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	} 
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C8NFG_Size + (size_t)x * kTui_Detail_G8_C8NFG_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index] = bg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C24_Size + (size_t)x * kTui_Detail_G8_C24_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index] = bg_b;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C24NBG_Size + (size_t)x * kTui_Detail_G8_C24NBG_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index] = fg_b;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C24NFG_Size + (size_t)x * kTui_Detail_G8_C24NFG_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index] = bg_b;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C32_Size + (size_t)x * kTui_Detail_G8_C32_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index++] = fg_a;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index++] = bg_b;
	batch_full->Data[tile_index] = bg_a;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C32NBG_Size + (size_t)x * kTui_Detail_G8_C32NBG_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index] = fg_a;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G8_C32NFG_Size + (size_t)x * kTui_Detail_G8_C32NFG_Size;
	batch_full->Data[tile_index++] = glyph;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index++] = bg_b;
	batch_full->Data[tile_index] = bg_a;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C0_Size + (size_t)x * kTui_Detail_G16_C0_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index] = (glyph >> 8) & 0xff;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C4_Size + (size_t)x * kTui_Detail_G16_C4_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index] = colors;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x >= batch_full->TilesWide || y >= batch_full->TilesTall || x < 0 || y < 0)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C8_Size + (size_t)x * kTui_Detail_G16_C8_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = fg;
	batch_full->Data[tile_index] = bg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C8NBG_Size + (size_t)x * kTui_Detail_G16_C8NBG_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index] = fg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C8NFG_Size + (size_t)x * kTui_Detail_G16_C8NFG_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index] = bg;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C24_Size + (size_t)x * kTui_Detail_G16_C24_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index] = bg_b;	
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C24NBG_Size + (size_t)x * kTui_Detail_G16_C24NBG_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index] = fg_b;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}
	
	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C24NFG_Size + (size_t)x * kTui_Detail_G16_C24NFG_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index] = bg_b;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C32_Size + (size_t)x * kTui_Detail_G16_C32_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index++] = fg_a;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index++] = bg_b;
	batch_full->Data[tile_index] = bg_a;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C32NBG_Size + (size_t)x * kTui_Detail_G16_C32NBG_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = fg_r;
	batch_full->Data[tile_index++] = fg_g;
	batch_full->Data[tile_index++] = fg_b;
	batch_full->Data[tile_index] = fg_a;
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
		// TODO TUI_ERROR_INVALID_BATCH_FUNCTION
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (x < 0 || y < 0 || (size_t)x >= batch_full->TilesWide || (size_t)y >= batch_full->TilesTall)
	{
		return;
	}

	size_t tile_index = (size_t)y * batch_full->TilesWide * kTui_Detail_G16_C32NFG_Size + (size_t)x * kTui_Detail_G16_C32NFG_Size;
	batch_full->Data[tile_index++] = (glyph) & 0xff;
	batch_full->Data[tile_index++] = (glyph >> 8) & 0xff;
	batch_full->Data[tile_index++] = bg_r;
	batch_full->Data[tile_index++] = bg_g;
	batch_full->Data[tile_index++] = bg_b; 
	batch_full->Data[tile_index] = bg_a;
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