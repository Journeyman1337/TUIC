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


static inline TuiBoolean _PointOutOfBatchFree(TuiBatchFree_s* batch_free, int x, int y)
{
	return (x < -batch_free->TilePixelWidth || y < -batch_free->TilePixelHeight || x >= batch_free->DrawViewportWidth || y >= batch_free->DrawViewportHeight);
}

static inline TuiBoolean _BatchFreeTileOverflow(TuiBatchFree_s* batch_free)
{
	return batch_free->TileCount == batch_free->MaxTileCount;
}
static inline size_t _BatchFreeGetDataIndex(TuiBatchFree_s* batch_free)
{
	size_t data_index = batch_free->TileCount * batch_free->BytesPerTile;
	batch_free->TileCount++;
	return data_index;
}

static inline void _BatchFreeSetPosition(TuiBatchFree_s* batch_free, size_t* data_index, int pixel_x, int pixel_y)
{
	unsigned int unsigned_pixel_x = (unsigned int)(pixel_x + batch_free->TilePixelWidth);
	unsigned int unsigned_pixel_y = (unsigned int)(pixel_y + batch_free->TilePixelHeight);
	batch_free->Data[(*data_index)++] = unsigned_pixel_x & 0xff; // first 8 bits of x
	batch_free->Data[(*data_index)++] = (unsigned_pixel_x >> 8) & 0xff; // second 8 bits of x
	batch_free->Data[(*data_index)++] = unsigned_pixel_y & 0xff; // first 8 bits of x
	batch_free->Data[(*data_index)++] = (unsigned_pixel_y >> 8) & 0xff; // second 8 bits of y
}

static inline void _BatchFreeSet_8(TuiBatchFree_s* batch_free, size_t* data_index, uint8_t value)
{
	batch_free->Data[(*data_index)++] = value;
}

static inline void _BatchFreeSet_16(TuiBatchFree_s* batch_free, size_t* data_index, uint16_t value)
{
	batch_free->Data[(*data_index)++] = (value) & 0xff; // first 8 bits
	batch_free->Data[(*data_index)++] = (value >> 8) & 0xff; // second 8 bits
}

static inline void _BatchFreeSet_C24(TuiBatchFree_s* batch_free, size_t* data_index, uint8_t r, uint8_t g, uint8_t b)
{
	batch_free->Data[(*data_index)++] = r;
	batch_free->Data[(*data_index)++] = g;
	batch_free->Data[(*data_index)++] = b;
}

static inline void _BatchFreeSet_C32(TuiBatchFree_s* batch_free, size_t* data_index, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	batch_free->Data[(*data_index)++] = r;
	batch_free->Data[(*data_index)++] = g;
	batch_free->Data[(*data_index)++] = b;
	batch_free->Data[(*data_index)++] = a;
}

void tuiBatchSetTile_G0_C8NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C8NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, fg);
}

void tuiBatchSetTile_G0_C24NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C24NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_C24(batch_free, &data_index, fg_r, fg_g, fg_b);
}

void tuiBatchSetTile_G0_C32NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G0_C32NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_C32(batch_free, &data_index, fg_r, fg_g, fg_b, fg_a);
}

void tuiBatchSetTile_G8_C0_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C0_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
}

void tuiBatchSetTile_G8_C4_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t colors)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C4_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, colors);
}

void tuiBatchSetTile_G8_C8_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t fg, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, fg);
	_BatchFreeSet_8(batch_free, &data_index, bg);
}

void tuiBatchSetTile_G8_C8NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, fg);
}

void tuiBatchSetTile_G8_C8NFG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C8NFG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, bg);
}

void tuiBatchSetTile_G8_C24_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_C24(batch_free, &data_index, fg_r, fg_g, fg_b);
	_BatchFreeSet_C24(batch_free, &data_index, bg_r, bg_g, bg_b);
}

void tuiBatchSetTile_G8_C24NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_C24(batch_free, &data_index, fg_r, fg_g, fg_b);
}

void tuiBatchSetTile_G8_C24NFG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C24NFG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_C24(batch_free, &data_index, bg_r, bg_g, bg_b);
}

void tuiBatchSetTile_G8_C32_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_C32(batch_free, &data_index, fg_r, fg_g, fg_b, fg_a);
	_BatchFreeSet_C32(batch_free, &data_index, bg_r, bg_g, bg_b, bg_a);
}

void tuiBatchSetTile_G8_C32NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_C32(batch_free, &data_index, fg_r, fg_g, fg_b, fg_a);
}

void tuiBatchSetTile_G8_C32NFG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint8_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G8_C32NFG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_8(batch_free, &data_index, glyph);
	_BatchFreeSet_C32(batch_free, &data_index, bg_r, bg_g, bg_b, bg_a);
}

void tuiBatchSetTile_G16_C0_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C0_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
}

void tuiBatchSetTile_G16_C4_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t colors)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C4_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, colors);
}

void tuiBatchSetTile_G16_C8_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t fg, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, fg);
	_BatchFreeSet_8(batch_free, &data_index, bg);
}

void tuiBatchSetTile_G16_C8NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t fg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, fg);
}

void tuiBatchSetTile_G16_C8NFG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t bg)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C8NFG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_8(batch_free, &data_index, bg);
}

void tuiBatchSetTile_G16_C24_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_C24(batch_free, &data_index, fg_r, fg_g, fg_b);
	_BatchFreeSet_C24(batch_free, &data_index, bg_r, bg_g, bg_b);
}

void tuiBatchSetTile_G16_C24NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_C24(batch_free, &data_index, fg_r, fg_g, fg_b);
}

void tuiBatchSetTile_G16_C24NFG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C24NFG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_C24(batch_free, &data_index, bg_r, bg_g, bg_b);
}

void tuiBatchSetTile_G16_C32_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_C32(batch_free, &data_index, fg_r, fg_g, fg_b, fg_a);
	_BatchFreeSet_C32(batch_free, &data_index, bg_r, bg_g, bg_b, bg_a);
}

void tuiBatchSetTile_G16_C32NBG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t fg_r, uint8_t fg_g, uint8_t fg_b, uint8_t fg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32NBG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_C32(batch_free, &data_index, fg_r, fg_g, fg_b, fg_a);
}

void tuiBatchSetTile_G16_C32NFG_FREE(TuiBatch batch, int pixel_x, int pixel_y, uint16_t glyph, uint8_t bg_r, uint8_t bg_g, uint8_t bg_b, uint8_t bg_a)
{
	if (batch == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (batch->DetailMode != TUI_DETAIL_MODE_G16_C32NFG_FREE)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFree_s* batch_free = (TuiBatchFree_s*)batch;
	if (_BatchFreeTileOverflow(batch_free))
	{
		tuiDebugError(TUI_ERROR_BATCH_OVERFLOW, __func__);
		return;
	}
	if (_PointOutOfBatchFree(batch_free, (size_t)pixel_x, (size_t)pixel_y))
	{
		return;
	}

	size_t data_index = _BatchFreeGetDataIndex(batch_free);
	_BatchFreeSetPosition(batch_free, &data_index, (unsigned int)pixel_x, (unsigned int)pixel_y);
	_BatchFreeSet_16(batch_free, &data_index, glyph);
	_BatchFreeSet_C32(batch_free, &data_index, bg_r, bg_g, bg_b, bg_a);
}