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


static inline TuiBoolean _PointOutOfBatchFull(TuiBatchFull_s* batch_full, size_t x, size_t y)
{
	return (x < 0 || y < 0 || x >= batch_full->TilesWide || y >= batch_full->TilesTall);
}

static inline size_t _BatchFullGetDataIndex(TuiBatchFull_s* batch_full, size_t x, size_t y)
{
	return (size_t)y * batch_full->TilesWide * batch_full->BytesPerTile
		+ (size_t)x * batch_full->BytesPerTile;
}

static inline void _BatchFullSet_8(TuiBatchFull_s* batch_full, size_t* data_index, uint8_t value)
{
	batch_full->Data[(*data_index)++] = value;
}

static inline void _BatchFullSet_16(TuiBatchFull_s* batch_full, size_t* data_index, uint16_t value)
{
	batch_full->Data[(*data_index)++] = (value) & 0xff; // first 8 bits
	batch_full->Data[(*data_index)++] = (value >> 8) & 0xff; // second 8 bits
}

static inline void _BatchFullSet_C24(TuiBatchFull_s* batch_full, size_t* data_index, uint8_t r, uint8_t g, uint8_t b)
{
	batch_full->Data[(*data_index)++] = r;
	batch_full->Data[(*data_index)++] = g;
	batch_full->Data[(*data_index)++] = b;
}

static inline void _BatchFullSet_C32(TuiBatchFull_s* batch_full, size_t* data_index, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	batch_full->Data[(*data_index)++] = r;
	batch_full->Data[(*data_index)++] = g;
	batch_full->Data[(*data_index)++] = b;
	batch_full->Data[(*data_index)++] = a;
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, fg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_C24(batch_full, &data_index, fg_r, fg_g, fg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_C32(batch_full, &data_index, fg_r, fg_g, fg_b, fg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, colors);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, fg);
	_BatchFullSet_8(batch_full, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, fg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_C24(batch_full, &data_index, fg_r, fg_g, fg_b);
	_BatchFullSet_C24(batch_full, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_C24(batch_full, &data_index, fg_r, fg_g, fg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_C24(batch_full, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_C32(batch_full, &data_index, fg_r, fg_g, fg_b, fg_a);
	_BatchFullSet_C32(batch_full, &data_index, bg_r, bg_g, bg_b, bg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_C32(batch_full, &data_index, fg_r, fg_g, fg_b, fg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_8(batch_full, &data_index, glyph);
	_BatchFullSet_C32(batch_full, &data_index, bg_r, bg_g, bg_b, bg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, colors);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, fg);
	_BatchFullSet_8(batch_full, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, fg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_8(batch_full, &data_index, bg);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_C24(batch_full, &data_index, fg_r, fg_g, fg_b);
	_BatchFullSet_C24(batch_full, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_C24(batch_full, &data_index, fg_r, fg_g, fg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_C24(batch_full, &data_index, bg_r, bg_g, bg_b);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_C32(batch_full, &data_index, fg_r, fg_g, fg_b, fg_a);
	_BatchFullSet_C32(batch_full, &data_index, bg_r, bg_g, bg_b, bg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_C32(batch_full, &data_index, fg_r, fg_g, fg_b, fg_a);
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
		tuiDebugError(TUI_ERROR_INVALID_BATCH_FUNCTION, __func__);
		return;
	}
	TuiBatchFull_s* batch_full = (TuiBatchFull_s*)batch;
	if (_PointOutOfBatchFull(batch_full, (size_t)x, (size_t)y))
	{
		return;
	}

	size_t data_index = _BatchFullGetDataIndex(batch_full, (size_t)x, (size_t)y);
	_BatchFullSet_16(batch_full, &data_index, glyph);
	_BatchFullSet_C32(batch_full, &data_index, bg_r, bg_g, bg_b, bg_a);
}