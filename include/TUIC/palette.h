/*! \file palette.h
 */
#ifndef TUIC_PALETTE_H //header guard
#define TUIC_PALETTE_H
#ifdef __cplusplus //extern C guard
extern "C" {
#endif
#include <TUIC/types.h>
#include <stdint.h>

extern const uint8_t kTuiXtermPalette[768];

TuiPalette tuiPaletteCreate(int channel_count, int color_count, const uint8_t* color_data);

TuiPalette tuiPaletteCreateXterm(int tui_palette_size);

void tuiPaletteDestroy(TuiPalette palette);

int tuiGetPaletteCount();

int tuiPaletteGetColorCount(TuiPalette palette);

int tuiPaletteGetChannelCount(TuiPalette palette);

uint8_t tuiClassicColorGetForeground(uint8_t fg_and_bg);

uint8_t tuiClassicColorGetBackground(uint8_t fg_and_bg);

uint8_t tuiClassicColorCombine(uint8_t fg, uint8_t bg);

#ifdef __cplusplus //extern C guard
}
#endif
#endif //header guard