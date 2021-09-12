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


static inline TuiBoolean _PointOutOfBatchSparse(TuiBatchSparse_s* batch_sparse, size_t x, size_t y)
{
	return (x < 0 || y < 0 || x >= batch_sparse->TilesWide || y >= batch_sparse->TilesTall);
}

static inline TuiBoolean _BatchSparseTileOverflow(TuiBatchSparse_s* batch_sparse)
{
	if (!batch_sparse->UseStencil && batch_sparse->TileCount == batch_sparse->MaxTileCount)
	{
		return TUI_TRUE;
	}
	return TUI_FALSE;
}

static inline size_t _BatchSparseGetDataIndex(TuiBatchSparse_s* batch_sparse, size_t x, size_t y)
{
	size_t data_index;
	if (batch_sparse->UseStencil)
	{
		size_t stencil_index = ((size_t)batch_sparse->TilesWide * y) + x;
		if (batch_sparse->StencilData[stencil_index] != 0)
		{
			data_index = batch_sparse->StencilData[stencil_index] - 1; // subtract 1 because added 1 when it was stored
			batch_sparse->TileCount++;
		}
		else //if (batch_sparse->StencilData[stencil_index] == 0)
		{
			data_index = batch_sparse->TileCount * batch_sparse->BytesPerTile;
			batch_sparse->StencilData[stencil_index] = data_index + 1; // value of 0 means no stencil, so add one so first tile is not 0
			batch_sparse->TileCount++;
		}
	}
	else //if (!batch_sparse->UseStencil)
	{
		data_index = batch_sparse->TileCount * batch_sparse->BytesPerTile;
		batch_sparse->TileCount++;
	}
	return data_index;
}

static inline void _BatchSparseSetCoordinate(TuiBatchSparse_s* batch_sparse, size_t* data_index, unsigned int x, unsigned int y)
{
	batch_sparse->Data[(*data_index)++] = x & 0xff; // first 8 bits
	if (batch_sparse->HasLargeXCoordinate)
	{
		batch_sparse->Data[(*data_index)++] = (x >> 8) & 0xff; // second 8 bits if large x coordinate
	}
	batch_sparse->Data[(*data_index)++] = y & 0xff; // first 8 bits
	if (batch_sparse->HasLargeYCoordinate)
	{
		batch_sparse->Data[(*data_index)++] = (y >> 8) & 0xff; // second 8 bits if large y coordinate
	}
}

static inline void _BatchSparseSet_8(TuiBatchSparse_s* batch_sparse, size_t* data_index, uint8_t value)
{
	batch_sparse->Data[(*data_index)++] = value;
}

static inline void _BatchSparseSet_16(TuiBatchSparse_s* batch_sparse, size_t* data_index, uint16_t value)
{
	batch_sparse->Data[(*data_index)++] = (value) & 0xff; // first 8 bits
	batch_sparse->Data[(*data_index)++] = (value >> 8) & 0xff; // second 8 bits
}

static inline void _BatchSparseSet_C24(TuiBatchSparse_s* batch_sparse, size_t* data_index, uint8_t r, uint8_t g, uint8_t b)
{
	batch_sparse->Data[(*data_index)++] = r;
	batch_sparse->Data[(*data_index)++] = g;
	batch_sparse->Data[(*data_index)++] = b;
}

static inline void _BatchSparseSet_C32(TuiBatchSparse_s* batch_sparse, size_t* data_index, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	batch_sparse->Data[(*data_index)++] = r;
	batch_sparse->Data[(*data_index)++] = g;
	batch_sparse->Data[(*data_index)++] = b;
	batch_sparse->Data[(*data_index)++] = a;
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, fg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_C24(batch_sparse, &data_index, fg_r, fg_g, fg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_C32(batch_sparse, &data_index, fg_r, fg_g, fg_b, fg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_8(batch_sparse, &data_index, colors);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_8(batch_sparse, &data_index, fg);
	_BatchSparseSet_8(batch_sparse, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_8(batch_sparse, &data_index, fg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_8(batch_sparse, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C24(batch_sparse, &data_index, fg_r, fg_g, fg_b);
	_BatchSparseSet_C24(batch_sparse, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C24(batch_sparse, &data_index, fg_r, fg_g, fg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C24(batch_sparse, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C32(batch_sparse, &data_index, fg_r, fg_g, fg_b, fg_a);
	_BatchSparseSet_C32(batch_sparse, &data_index, bg_r, bg_g, bg_b, bg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C32(batch_sparse, &data_index, fg_r, fg_g, fg_b, fg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_8(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C32(batch_sparse, &data_index, bg_r, bg_g, bg_b, bg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_16(batch_sparse, &data_index, colors);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_16(batch_sparse, &data_index, fg);
	_BatchSparseSet_16(batch_sparse, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_16(batch_sparse, &data_index, fg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_16(batch_sparse, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C24(batch_sparse, &data_index, fg_r, fg_g, fg_b);
	_BatchSparseSet_C24(batch_sparse, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C24(batch_sparse, &data_index, fg_r, fg_g, fg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C24(batch_sparse, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C32(batch_sparse, &data_index, fg_r, fg_g, fg_b, fg_a);
	_BatchSparseSet_C32(batch_sparse, &data_index, bg_r, bg_g, bg_b, bg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C32(batch_sparse, &data_index, fg_r, fg_g, fg_b, fg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchSparse_s* batch_sparse = (TuiBatchSparse_s*)batch;
	if (_BatchSparseTileOverflow(batch_sparse))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchSparse(batch_sparse, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchSparseGetDataIndex(batch_sparse, (size_t)x, (size_t)y);
	_BatchSparseSetCoordinate(batch_sparse, &data_index, (unsigned int)x, (unsigned int)y);
	_BatchSparseSet_16(batch_sparse, &data_index, glyph);
	_BatchSparseSet_C32(batch_sparse, &data_index, bg_r, bg_g, bg_b, bg_a);
}