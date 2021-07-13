#include <TUIC/tuic.h>
#include "objects.h"
#include "image_inline.h"
#include "opengl33.h"

static int sPanelCount = 0;

TuiPanel tuiPanelCreate(TuiWindow window, int pixel_width, int pixel_height)
{
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return NULL;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PANEL_DIMENSIONS, __func__);
		return NULL;
	}

	TuiPanel panel = tuiAllocate(sizeof(TuiPanel_s));
	panel->Window = window;
	panel->FramebufferWidth = (size_t)pixel_width;
	panel->FramebufferHeight = (size_t)pixel_height;
	panel->ApiData = NULL;
	tuiPanelCreate_Opengl33(panel);
	sPanelCount++;
	return panel;
}

void tuiPanelDestroy(TuiPanel panel)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}

	tuiPanelDestroy_Opengl33(panel);
	sPanelCount--;
	tuiFree(panel);
}

int tuiGetPanelCount()
{
	return sPanelCount;
}

TuiImage tuiPanelGetImage(TuiPanel panel)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return NULL;
	}

	size_t p_width = 0;
	size_t p_height = 0;
	uint8_t* pixel_data = tuiPanelGetPixels_Opengl33(panel, &p_width, &p_height, NULL);
	TuiImage image = _CreateImage(p_width, p_height, 4, pixel_data, TUI_FALSE, __func__);
	return image;
}

void tuiPanelWriteImage(TuiPanel panel, TuiImage image)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (image == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_IMAGE, __func__);
		return;
	}

	image->PixelData = tuiPanelGetPixels_Opengl33(panel, &image->PixelWidth, &image->PixelHeight, image->PixelData);
}

uint8_t* tuiPanelGetPixels(TuiPanel panel, int* pixel_width, int* pixel_height, uint8_t* fill_pixels)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return NULL;
	}

	size_t o_width, o_height;
	fill_pixels = tuiPanelGetPixels_Opengl33(panel, &o_width, &o_height, fill_pixels);
	*pixel_width = (int)o_width;
	*pixel_height = (int)o_height;
	return fill_pixels;
} 

void tuiPanelClearColor(TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	
	tuiPanelClearColor_Opengl33(panel, r, g, b, a);
}

void tuiPanelSetPixelDimensions(TuiPanel panel, int pixel_width, int pixel_height)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PANEL_DIMENSIONS, __func__);
		return;
	}

	tuiPanelSetSize_Opengl33(panel, (size_t)pixel_width, (size_t)pixel_height);
}

void tuiPanelGetPixelDimensions(TuiPanel panel, int* pixel_width, int* pixel_height)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}

	if (pixel_width != NULL)
	{
		*pixel_width = (int)panel->FramebufferWidth;
	}
	if (pixel_height != NULL)
	{
		*pixel_height = (int)panel->FramebufferHeight;
	}
}

int tuiPanelGetPixelWidth(TuiPanel panel)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return 0;
	}

	return panel->FramebufferWidth;
}

int tuiPanelGetPixelHeight(TuiPanel panel)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return 0;
	}

	return panel->FramebufferHeight;
}


void tuiPanelDrawBatch(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiBatch batch)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
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
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	tuiPanelDrawBatchData_Opengl33(panel, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, 0, panel->FramebufferWidth, 0, panel->FramebufferHeight);
}

void tuiPanelDrawBatchData(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
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
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	tuiPanelDrawBatchData_Opengl33(panel, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, sparse_index, batch_data, 0, panel->FramebufferWidth, 0, panel->FramebufferHeight);
}

void tuiPanelDrawBatchTransformed(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiBatch batch, int left_x, int right_x, int top_y, int bottom_y)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
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
	if (tuiDetailHasFlag(batch->DetailMode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && batch->TileCount == 0)
	{
		return;
	}

	tuiPanelDrawBatchData_Opengl33(panel, atlas, palette, batch->DetailMode, batch->TilesWide, batch->TilesTall, batch->TileCount, batch->Data, left_x, right_x, top_y, bottom_y);
}

void tuiPanelDrawBatchDataTransformed(TuiPanel panel, TuiAtlas atlas, TuiPalette palette, TuiDetailMode detail_mode, int tiles_wide, int tiles_tall, size_t sparse_index, uint8_t* batch_data, int left_x, int right_x, int top_y, int bottom_y)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (batch_data == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_BATCH_DATA, __func__);
		return;
	}
	if (tiles_wide <= 0 || tiles_tall <= 0)
	{
		tuiDebugError(TUI_ERROR_INVALID_PANEL_DIMENSIONS, __func__);
		return;
	}
	if (tuiDetailHasFlag(detail_mode, TUI_LAYOUT_FLAG_SPARSE) == TUI_TRUE && sparse_index == 0)
	{
		return;
	}

	tuiPanelDrawBatchData_Opengl33(panel, atlas, palette, (size_t)detail_mode, (size_t)tiles_wide, (size_t)tiles_tall, sparse_index, batch_data, left_x, right_x, top_y, bottom_y);
}

void tuiPanelDrawPanel(TuiPanel panel, TuiPanel subject_panel)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (subject_panel == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_SUBJECT_PANEL, __func__);
		return;
	}

	tuiPanelDrawPanel_Opengl33(panel, subject_panel, 0, (int)panel->FramebufferWidth, 0, (int)panel->FramebufferHeight);
}

void tuiPanelDrawPanelTransformed(TuiPanel panel, TuiPanel subject_panel, int left_x, int right_x, int top_y, int bottom_y)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (subject_panel == NULL)
	{
		// TODO tuiDebugError(TUI_ERROR_NULL_SUBJECT_PANEL, __func__);
		return;
	}

	tuiPanelDrawPanel_Opengl33(panel, subject_panel, left_x, right_x, top_y, bottom_y);
}

void tuiPanelDrawTexture(TuiPanel panel, TuiTexture texture)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (texture == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiPanelDrawTexture_Opengl33(panel, texture, 0, (int)panel->FramebufferWidth, 0, (int)panel->FramebufferHeight);
}

void tuiPanelDrawTextureTransformed(TuiPanel panel, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (texture == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_TEXTURE, __func__);
		return;
	}

	tuiPanelDrawTexture_Opengl33(panel, texture, left_x, right_x, top_y, bottom_y);
}

void tuiPanelDrawAtlas(TuiPanel panel, TuiAtlas atlas)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return;
	}

	tuiPanelDrawAtlas_Opengl33(panel, atlas, 0, (int)panel->FramebufferWidth, 0, (int)panel->FramebufferHeight);
}

void tuiPanelDrawAtlasTransformed(TuiPanel panel, TuiAtlas atlas, int left_x, int right_x, int top_y, int bottom_y)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (atlas == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_ATLAS, __func__);
		return;
	}

	tuiPanelDrawAtlas_Opengl33(panel, atlas, left_x, right_x, top_y, bottom_y);
}

void tuiPanelDrawWindow(TuiPanel panel, TuiWindow window)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiPanelDrawAtlas_Opengl33(panel, window, 0, (int)panel->FramebufferWidth, 0, (int)panel->FramebufferHeight);
}

void tuiPanelDrawWindowTransformed(TuiPanel panel, TuiWindow window, int left_x, int right_x, int top_y, int bottom_y)
{
	if (panel == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PANEL, __func__);
		return;
	}
	if (window == NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_WINDOW, __func__);
		return;
	}

	tuiPanelDrawAtlas_Opengl33(panel, window, left_x, right_x, top_y, bottom_y);
}