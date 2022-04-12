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
#include "image_inline.h"
#include "opengl33.h"
#include "glfw_error_check.h"

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

static size_t sPanelCount = 0;

TuiResult tuiPanelCreate(TuiPanel* panel, int pixel_width, int pixel_height)
{
	assert(panel != NULL);
	TuiSystem system = tui_get_system();
	if (system == NULL)
	{
		return TUI_RESULT_ERROR_NOT_INITIALIZED;
	}
	if (pixel_width <= 0 || pixel_height <= 0)
	{
		return TUI_RESULT_ERROR_INVALID_VALUE;
	}
	*panel = (TuiPanel)tuiAllocate(sizeof(TuiPanel_s));
	memset(*panel, 0, sizeof(TuiPanel_s));
	(*panel)->PixelWidth = pixel_width;
	(*panel)->PixelHeight = pixel_height;
	TuiResult result = tuiPanelCreate_Opengl33((*panel), pixel_width, pixel_height);
	if (result != TUI_RESULT_OK)
	{
		tuiFree(*panel);
		*panel = NULL;
		return result;
	}
	sPanelCount++;
	return TUI_RESULT_OK;
}

void tuiPanelDestroy(TuiPanel panel)
{
	assert(panel != NULL);
	tuiPanelDestroy_Opengl33(panel);
	tuiFree(panel);
	sPanelCount--;
}

TuiResult tuiPanelGetPixels(TuiPanel panel, uint8_t** pixels, int* pixel_width, int* pixel_height)
{
	assert(panel != NULL);
	assert(pixels != NULL);
	
	return tuPanelGetPixels_Opengl33(panel, pixels, pixel_width, pixel_height);
}

TuiResult tuiPanelClearColor(TuiPanel panel, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	assert(panel != NULL);
	
	return tuiPanelClearColor_Opengl33(panel, r, g, b, a);
}

TuiResult tuiPanelSetPixelDimensions(TuiPanel panel, int pixel_width, int pixel_height)
{
	assert(panel != NULL);
	
	return tuiPanelSetPixelDimensions_Opengl33(panel, pixel_width, pixel_height);
}

void tuiPanelGetPixelDimensions(TuiPanel panel, int* pixel_width, int* pixel_height)
{
	assert(panel != NULL);
	
	if (pixel_width != NULL)
	{
		*pixel_width = panel->PixelWidth;
	}
	if (pixel_height != NULL)
	{
		*pixel_height = panel->PixelHeight;
	}
}

TuiResult tuiPanelDrawConsole(TuiPanel panel, TuiAtlas atlas, TuiConsole console)
{
	assert(panel != NULL);
	assert(atlas != NULL);
	assert(console != NULL);
	
	return tuiPanelDrawConsole_Opengl33(panel, atlas, console, 0, panel->PixelWidth, 0, panel->PixelHeight);
}

TuiResult tuiPanelDrawConsoleTransformed(TuiPanel panel, TuiAtlas atlas, TuiConsole console, int left_x, int right_x, int top_y, int bottom_y)
{
	assert(panel != NULL);
	assert(atlas != NULL);
	assert(console != NULL);
	
	return tuiPanelDrawConsole_Opengl33(panel, atlas, console, left_x, right_x, top_y, bottom_y);
}

TuiResult tuiPanelDrawPanel(TuiPanel panel, TuiPanel subject_panel)
{
	assert(panel != NULL);
	assert(subject_panel != NULL);
	
	return tuiPanelDrawPanel_Opengl33(panel, subject_panel, 0, panel->PixelWidth, 0, panel->PixelHeight);
}

TuiResult tuiPanelDrawPanelTransformed(TuiPanel panel, TuiPanel subject_panel, int left_x, int right_x, int top_y, int bottom_y)
{
	assert(panel != NULL);
	assert(subject_panel != NULL);
	
	return tuiPanelDrawPanel_Opengl33(panel, subject_panel, left_x, right_x, top_y, bottom_y);
}

TuiResult tuiPanelDrawTexture(TuiPanel panel, TuiTexture texture)
{
	assert(panel != NULL);
	assert(texture != NULL);
	
	return tuiPanelDrawTexture_Opengl33(panel, texture, 0, panel->PixelWidth, 0, panel->PixelHeight);
}

TuiResult tuiPanelDrawTextureTransformed(TuiPanel panel, TuiTexture texture, int left_x, int right_x, int top_y, int bottom_y)
{
	assert(panel != NULL);
	assert(texture != NULL);
	
	return tuiPanelDrawTexture_Opengl33(panel, texture, left_x, right_x, top_y, bottom_y);
}

TuiResult tuiPanelDrawWindow(TuiPanel panel, TuiWindow window)
{
	assert(panel != NULL);
	assert(window != NULL);
	
	return tuiPanelDrawWindow_Opengl33(panel, window, 0, panel->PixelWidth, 0, panel->PixelHeight);
}

TuiResult tuiPanelDrawWindowTransformed(TuiPanel panel, TuiWindow window, int left_x, int right_x, int top_y, int bottom_y)
{
	assert(panel != NULL);
	assert(window != NULL);
	
	return tuiPanelDrawWindow_Opengl33(panel, window, left_x, right_x, top_y, bottom_y);
}

size_t tuiGetPanelCount()
{
	return sPanelCount;
}