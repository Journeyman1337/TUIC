#ifndef TUI_COMMON_TEST_H //header guard
#define TUI_COMMON_TEST_H

#define TEST_DIMENSIONS 256
#define TEST_TILE_SIZE 8
#include <TUIC/tuic.h>

extern const char* kOutDirectoryPath;

TuiAtlas test_CreateCodepageAtlas(TuiBlendMode blend_mode);
TuiBatch test_GetTestPatternBatch(TuiDetailMode detail_mode);
void test_BlendMode(TuiBlendMode blend_mode, TuiPanel panel);
void test_DetailMode(TuiDetailMode detail_mode, TuiPanel panel);
void test_Palette(int palette_channel_count, TuiPanel panel);

#endif //header guard