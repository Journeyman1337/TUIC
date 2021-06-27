#include <TUIC/tuic.h>
#include <TUIC/backends/objects.h>

void tuiInstanceDestroy(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	int dangling = TUI_FALSE;
	if (instance->PanelCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PANEL, __func__);
		dangling = TUI_TRUE;
	}
	if (instance->GlyphAtlasCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_GLYPH_ATLAS, __func__);
		dangling = TUI_TRUE;
	}
	if (instance->PaletteCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_PALETTE, __func__);
		dangling = TUI_TRUE;
	}
	if (instance->TextureCount > 0)
	{
		tuiDebugError(TUI_ERROR_DANGLING_TEXTURE, __func__);
		dangling = TUI_TRUE;
	}
	if (dangling == TUI_TRUE)
	{
		return;
	}

	instance->InstanceDestroy(instance);
	tuiFree(instance);
}

void tuiInstanceClearColor(TuiInstance instance, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}

	instance->InstanceClearColor(instance, r, g, b, a);
}

void tuiInstanceSetDamaged(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}

	instance->IsDamaged = TUI_TRUE;
}

int tuiInstanceGetDamaged(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return TUI_FALSE;
	}

	return instance->IsDamaged;
}

void tuiInstanceResizeScreen(TuiInstance instance, int screen_width, int screen_height)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (screen_width <= 0 || screen_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_INSTANCE_DIMENSIONS, __func__);
		return;
	}

	instance->PixelWidth = (int)screen_width;
	instance->PixelHeight = (int)screen_height;
	instance->InstanceResizeScreen(instance, screen_width, screen_height);
}

int tuiInstanceGetPixelWidth(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return 0;
	}

	return (size_t)instance->PixelWidth;
}

int tuiInstanceGetPixelHeight(TuiInstance instance)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return 0;
	}

	return (size_t)instance->PixelHeight;
}

void tuiInstanceGetPixelDimensons(TuiInstance instance, int* width, int* height)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}

	if (width != NULL)
	{
		*width = instance->PixelWidth;
	}
	if (height != NULL)
	{
		*height = instance->PixelHeight;
	}
}

void tuiInstanceDrawBatch(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}
	if (batch == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (tuiDetailHasPalette(batch->DetailMode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, 0, instance->PixelWidth, 0, instance->PixelHeight);
}

void tuiInstanceDrawBatchData(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, int detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH_DATA, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS, __func__);
		return;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return;
	}
	if (tuiDetailHasPalette(detail_mode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, (size_t)sparse_index, batch_data, 0, instance->PixelWidth, 0, instance->PixelHeight);

}

void tuiInstanceDrawBatchTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_GLYPH_ATLAS, __func__);
		return;
	}
	if (batch == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH, __func__);
		return;
	}
	if (tuiDetailHasPalette(batch->DetailMode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, left_x, right_x, top_y, bottom_y);
}

void tuiInstanceDrawBatchDataTransformed(TuiInstance instance, TuiGlyphAtlas atlas, TuiPalette palette, int detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y)
{
	if (instance == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_INSTANCE, __func__);
		return;
	}
	if (instance->IsDamaged == TUI_TRUE)
	{
		tuiDebugError(TUI_ERROR_DAMAGED_INSTANCE, __func__);
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH_DATA, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_BATCH_DATA_DIMENSIONS, __func__);
		return;
	}
	if (tuiDetailIsValid(detail_mode) == TUI_FALSE)
	{
		tuiDebugError(TUI_ERROR_INVALID_DETAIL_MODE, __func__);
		return;
	}
	if (tuiDetailHasPalette(detail_mode) == TUI_TRUE && palette == NULL)
	{
		tuiDebugError(TUI_ERROR_PALETTE_REQUIRED, __func__);
		return;
	}
	if (atlas->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_ATLAS_INSTANCE, __func__);
		return;
	}
	if (palette != NULL && palette->Instance != instance)
	{
		tuiDebugError(TUI_ERROR_UNMATCHING_PALETTE_INSTANCE, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	instance->InstanceDrawBatchData(instance, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, sparse_index, batch_data, left_x, right_x, top_y, bottom_y);
}