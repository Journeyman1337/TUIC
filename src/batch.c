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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_TILE_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return TUI_NULL;
	}
	if (tuiDetailGetLayoutFlag(detail_mode) != TUI_DETAIL_FLAG_LAYOUT_FULL)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return TUI_NULL;
	}

	TuiBatchFull_s* batch = tuiAllocate(sizeof(TuiBatchFull_s));

	batch->DetailMode = detail_mode;
	batch->TilesWide = tiles_wide;
	batch->TilesTall = tiles_tall;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->UsedDataSize = batch->BytesPerTile * batch->TilesWide * batch->TilesTall;
	batch->ReservedDataSize = batch->UsedDataSize;
	if (batch->UsedDataSize < minimum_reserved_data_size)
	{
		batch->ReservedDataSize = minimum_reserved_data_size;
	}
	batch->Data = tuiAllocate(batch->ReservedDataSize);
	memset(batch->Data, 0, batch->ReservedDataSize);
	batch->TileCount = batch->TilesWide * batch->TilesTall;

	return (TuiBatch)batch;
}

TuiBatch tuiBatchCreateSparse(TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, TuiBoolean use_stencil, size_t minimum_reserved_data_size)
{
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_TILE_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return TUI_NULL;
	}
	if (tuiDetailGetLayoutFlag(detail_mode) != TUI_DETAIL_FLAG_LAYOUT_SPARSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return TUI_NULL;
	}

	TuiBatchSparse_s* batch = tuiAllocate(sizeof(TuiBatchSparse_s));

	batch->DetailMode = detail_mode;
	batch->TilesWide = tiles_wide;
	batch->TilesTall = tiles_tall;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->TileCount = 0;
	batch->MaxTileCount = 0;
	batch->HasLargeXCoordinate = TUI_FALSE;
	batch->HasLargeYCoordinate = TUI_FALSE;
	batch->UseStencil = use_stencil;
	batch->StencilData = TUI_NULL;
	batch->StencilDataSize = 0;
	if (use_stencil)
	{
		batch->StencilDataSize = batch->TilesWide * batch->TilesTall * sizeof(size_t);
		batch->StencilData = (size_t*)tuiAllocate(batch->StencilDataSize);
		memset(batch->StencilData, 0, batch->StencilDataSize);
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
	batch->MaxTileCount = batch->TilesWide * batch->TilesTall;
	batch->UsedDataSize = batch->BytesPerTile * batch->MaxTileCount;
	batch->ReservedDataSize = batch->UsedDataSize;
	if (batch->UsedDataSize < minimum_reserved_data_size)
	{
		batch->ReservedDataSize = minimum_reserved_data_size;
	}
	batch->Data = tuiAllocate(batch->ReservedDataSize);
	memset(batch->Data, 0, batch->ReservedDataSize);

	return (TuiBatch)batch;
}

TuiBatch tuiBatchCreateFree(TuiDetailMode detail_mode, int tile_pixel_width, int tile_pixel_height, int draw_viewport_width, int draw_viewport_height, int maximum_tile_count, size_t minimum_reserved_data_size)
{
	if (tile_pixel_width <= 0 || tile_pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_GLYPH_PIXEL_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (draw_viewport_width <= 0 || draw_viewport_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_VIEWPORT_PIXEL_DIMENSIONS, __func__);
		return TUI_NULL;
	}
	if (maximum_tile_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_MAX_TILE_COUNT, __func__);
		return TUI_NULL;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{ 
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return TUI_NULL;
	}
	if (tuiDetailGetLayoutFlag(detail_mode) != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return TUI_NULL;
	}

	TuiBatchFree_s* batch = tuiAllocate(sizeof(TuiBatchFree_s));

	batch->DetailMode = detail_mode;
	batch->BytesPerTile = tuiDetailGetTileByteSize(tuiDetailGetGlyphFlag(detail_mode), tuiDetailGetColorFlag(detail_mode));
	batch->BytesPerTile += 4; //Free batches have 2 uint16_t for the x and y positions of each tile. Unlike with sparse batches, coordinates are never optimized to 1 bytes.
	batch->TilePixelWidth = tile_pixel_width;
	batch->TilePixelHeight = tile_pixel_height;
	batch->TileCount = 0;
	batch->DrawViewportWidth = draw_viewport_width;
	batch->DrawViewportHeight = draw_viewport_height;
	batch->MaxTileCount = maximum_tile_count;
	batch->UsedDataSize = batch->BytesPerTile * batch->MaxTileCount;
	batch->ReservedDataSize = batch->UsedDataSize;
	if (batch->UsedDataSize < minimum_reserved_data_size)
	{
		batch->ReservedDataSize = minimum_reserved_data_size;
	}
	batch->Data = tuiAllocate(batch->ReservedDataSize);
	memset(batch->Data, 0, batch->ReservedDataSize);

	return (TuiBatch)batch;
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
	default:
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

void tuiBatchPushTileDimensions(TuiBatch batch, int tiles_wide, int tiles_tall, TuiBoolean reserve_extra)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_TILE_DIMENSIONS, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag == TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
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
	default:
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
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
	default:
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
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
	default:
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
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
	default:
		break;
	}
	return 0;
}

void tuiBatchSetViewportPixelDimensions(TuiBatch batch, int pixel_width, int pixel_height)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_VIEWPORT_PIXEL_DIMENSIONS, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	batch_free->DrawViewportWidth = pixel_width;
	batch_free->DrawViewportHeight = pixel_height;
	batch_free->TileCount = 0;
}

void tuiBatchGetViewportPixelDimensions(TuiBatch batch, int* pixel_width, int* pixel_height)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (pixel_width != TUI_NULL)
	{
		*pixel_width = batch_free->DrawViewportWidth;
	}
	if (pixel_height != TUI_NULL)
	{
		*pixel_height = batch_free->DrawViewportHeight;
	}
}

int tuiBatchGetViewportPixelWidth(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	return batch_free->DrawViewportWidth;
}

int tuiBatchGetViewportPixelHeight(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	return batch_free->DrawViewportHeight;
}

void tuiBatchSetGlyphPixelDimensions(TuiBatch batch, int pixel_width, int pixel_height)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_GLYPH_PIXEL_DIMENSIONS, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	batch_free->TilePixelWidth = pixel_width;
	batch_free->TilePixelHeight = pixel_height;
	batch_free->TileCount = 0;
}

void tuiBatchGetGlyphPixelDimensions(TuiBatch batch, int* pixel_width, int* pixel_height)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (pixel_width != TUI_NULL)
	{
		*pixel_width = batch_free->TilePixelWidth;
	}
	if (pixel_height != TUI_NULL)
	{
		*pixel_height = batch_free->TilePixelHeight;
	}
}

int tuiBatchGetGlyphPixelWidth(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	return batch_free->TilePixelWidth;
}

int tuiBatchGetGlyphPixelHeight(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	return batch_free->TilePixelHeight;
}

void tuiBatchSetMaxTileCount(TuiBatch batch, int max_tile_count, TuiBoolean reserve_extra)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (max_tile_count <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_MAX_TILE_COUNT, __func__);
		return;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	batch_free->TileCount = 0;
	if ((size_t)max_tile_count != batch_free->MaxTileCount)
	{
		batch_free->MaxTileCount = (size_t)max_tile_count;
		batch_free->UsedDataSize = max_tile_count * batch_free->BytesPerTile;
		if (!reserve_extra || batch_free->ReservedDataSize < batch_free->UsedDataSize)
		{
			batch_free->Data = (uint8_t*)tuiReallocate(batch_free->Data, batch_free->UsedDataSize);
			batch_free->ReservedDataSize = batch_free->UsedDataSize;
			batch_free->UsedDataSize = batch_free->UsedDataSize;
		}
		
	}
}

int tuiBatchGetMaxTileCount(TuiBatch batch)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return 0;
	}
	TuiDetailFlag layout_flag = tuiDetailGetLayoutFlag(batch->DetailMode);
	if (layout_flag != TUI_DETAIL_FLAG_LAYOUT_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return 0;
	}

	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	return batch_free->MaxTileCount;
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
	return TUI_NULL;

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
	return;
}
