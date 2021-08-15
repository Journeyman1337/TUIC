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
#include "opengl33.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const uint8_t kTuiXtermPalette[768] = {
	0,0,0,
	128,0,0,
	0,128,0,
	128,128,0,
	0,0,128,
	128,0,128,
	0,128,128,
	192,192,192,
	128,128,128,
	255,0,0,
	0,255,0,
	255,255,0,
	0,0,255,
	255,0,255,
	0,255,255,
	255,255,255,
	0,0,0,
	0,0,95,
	0,0,135,
	0,0,175,
	0,0,215,
	0,0,255,
	0,95,0,
	0,95,95,
	0,95,135,
	0,95,175,
	0,95,215,
	0,95,255,
	0,135,0,
	0,135,95,
	0,135,135,
	0,135,175,
	0,135,215,
	0,135,255,
	0,175,0,
	0,175,95,
	0,175,135,
	0,175,175,
	0,175,215,
	0,175,255,
	0,215,0,
	0,215,95,
	0,215,135,
	0,215,175,
	0,215,215,
	0,215,255,
	0,255,0,
	0,255,95,
	0,255,135,
	0,255,175,
	0,255,215,
	0,255,255,
	95,0,0,
	95,0,95,
	95,0,135,
	95,0,175,
	95,0,215,
	95,0,255,
	95,95,0,
	95,95,95,
	95,95,135,
	95,95,175,
	95,95,215,
	95,95,255,
	95,135,0,
	95,135,95,
	95,135,135,
	95,135,175,
	95,135,215,
	95,135,255,
	95,175,0,
	95,175,95,
	95,175,135,
	95,175,175,
	95,175,215,
	95,175,255,
	95,215,0,
	95,215,95,
	95,215,135,
	95,215,175,
	95,215,215,
	95,215,255,
	95,255,0,
	95,255,95,
	95,255,135,
	95,255,175,
	95,255,215,
	95,255,255,
	135,0,0,
	135,0,95,
	135,0,135,
	135,0,175,
	135,0,215,
	135,0,255,
	135,95,0,
	135,95,95,
	135,95,135,
	135,95,175,
	135,95,215,
	135,95,255,
	135,135,0,
	135,135,95,
	135,135,135,
	135,135,175,
	135,135,215,
	135,135,255,
	135,175,0,
	135,175,95,
	135,175,135,
	135,175,175,
	135,175,215,
	135,175,255,
	135,215,0,
	135,215,95,
	135,215,135,
	135,215,175,
	135,215,215,
	135,215,255,
	135,255,0,
	135,255,95,
	135,255,135,
	135,255,175,
	135,255,215,
	135,255,255,
	175,0,0,
	175,0,95,
	175,0,135,
	175,0,175,
	175,0,215,
	175,0,255,
	175,95,0,
	175,95,95,
	175,95,135,
	175,95,175,
	175,95,215,
	175,95,255,
	175,135,0,
	175,135,95,
	175,135,135,
	175,135,175,
	175,135,215,
	175,135,255,
	175,175,0,
	175,175,95,
	175,175,135,
	175,175,175,
	175,175,215,
	175,175,255,
	175,215,0,
	175,215,95,
	175,215,135,
	175,215,175,
	175,215,215,
	175,215,255,
	175,255,0,
	175,255,95,
	175,255,135,
	175,255,175,
	175,255,215,
	175,255,255,
	215,0,0,
	215,0,95,
	215,0,135,
	215,0,175,
	215,0,215,
	215,0,255,
	215,95,0,
	215,95,95,
	215,95,135,
	215,95,175,
	215,95,215,
	215,95,255,
	215,135,0,
	215,135,95,
	215,135,135,
	215,135,175,
	215,135,215,
	215,135,255,
	215,175,0,
	215,175,95,
	215,175,135,
	215,175,175,
	215,175,215,
	215,175,255,
	215,215,0,
	215,215,95,
	215,215,135,
	215,215,175,
	215,215,215,
	215,215,255,
	215,255,0,
	215,255,95,
	215,255,135,
	215,255,175,
	215,255,215,
	215,255,255,
	255,0,0,
	255,0,95,
	255,0,135,
	255,0,175,
	255,0,215,
	255,0,255,
	255,95,0,
	255,95,95,
	255,95,135,
	255,95,175,
	255,95,215,
	255,95,255,
	255,135,0,
	255,135,95,
	255,135,135,
	255,135,175,
	255,135,215,
	255,135,255,
	255,175,0,
	255,175,95,
	255,175,135,
	255,175,175,
	255,175,215,
	255,175,255,
	255,215,0,
	255,215,95,
	255,215,135,
	255,215,175,
	255,215,215,
	255,215,255,
	255,255,0,
	255,255,95,
	255,255,135,
	255,255,175,
	255,255,215,
	255,255,255,
	8,8,8,
	18,18,18,
	28,28,28,
	38,38,38,
	48,48,48,
	58,58,58,
	68,68,68,
	78,78,78,
	88,88,88,
	98,98,98,
	108,108,108,
	118,118,118,
	128,128,128,
	138,138,138,
	148,148,148,
	158,158,158,
	168,168,168,
	178,178,178,
	188,188,188,
	198,198,198,
	208,208,208,
	218,218,218,
	228,228,228,
	238,238,238
};

static int sPaletteCount = 0;

TuiPalette tuiPaletteCreateColors(int channel_count, int color_count, const uint8_t* color_data)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (color_count <= 0 || color_count > 256)
	{
		tuiDebugError(TUI_ERROR_INVALID_PALETTE_COLOR_COUNT, __func__);
		return TUI_NULL;
	}
	if (channel_count != 3 && channel_count != 4)
	{
		tuiDebugError(TUI_ERROR_INVALID_CHANNEL_COUNT, __func__);
		return TUI_NULL;
	}
	if (color_data == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_COLORS, __func__);
		return TUI_NULL;
	}

	TuiPalette palette = tuiAllocate(sizeof(TuiPalette_s));
	palette->ChannelCount = channel_count;
	palette->ColorCount = (size_t)color_count;
	palette->ApiData = TUI_NULL;
	TuiErrorCode error_code = tuiPaletteCreate_Opengl33(palette, color_data);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiPaletteDestroy_Opengl33(palette);
		tuiFree(palette);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sPaletteCount++;
	return palette;
}

TuiPalette tuiPaletteCreateXterm(int color_count)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return TUI_NULL;
	}
	if (color_count <= 0 || color_count > 256)
	{
		tuiDebugError(TUI_ERROR_INVALID_PALETTE_COLOR_COUNT, __func__);
		return TUI_NULL;
	}

	TuiPalette palette = tuiAllocate(sizeof(TuiPalette_s));
	palette->ChannelCount = 3;
	palette->ColorCount = (size_t)color_count;
	palette->ApiData = TUI_NULL;
	TuiErrorCode error_code = tuiPaletteCreate_Opengl33(palette, &kTuiXtermPalette[0]);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiPaletteDestroy_Opengl33(palette);
		tuiFree(palette);
		tuiDebugError(error_code, __func__);
		return TUI_NULL;
	}
	sPaletteCount++;
	return palette;
}

void tuiPaletteDestroy(TuiPalette palette)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return;
	}
	if (palette == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PALETTE, __func__);
		return;
	}

	TuiErrorCode error_code = tuiPaletteDestroy_Opengl33(palette);
	if (error_code != TUI_ERROR_NONE)
	{
		tuiDebugError(error_code, __func__);
		return;
	}
	tuiFree(palette);
	sPaletteCount--;
}

int tuiGetPaletteCount()
{
	return sPaletteCount;
}

int tuiPaletteGetColorCount(TuiPalette palette)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	if (palette == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PALETTE, __func__);
		return 0;
	}

	return (int)palette->ColorCount;
}

int tuiPaletteGetChannelCount(TuiPalette palette)
{
	TuiSystem system = tui_get_system();
	if (system == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NOT_INITIALIZED, __func__);
		return 0;
	}
	if (palette == TUI_NULL)
	{
		tuiDebugError(TUI_ERROR_NULL_PALETTE, __func__);
		return 0;
	}

	return palette->ChannelCount;
}

uint8_t tuiClassicColorGetForeground(uint8_t fg_and_bg)
{
	return fg_and_bg % 16;
}

uint8_t tuiClassicColorGetBackground(uint8_t fg_and_bg)
{
	return fg_and_bg / 16;
}

uint8_t tuiClassicColorCombine(uint8_t fg, uint8_t bg)
{
	return fg + (bg * 16);
}