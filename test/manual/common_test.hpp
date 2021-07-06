#ifndef TUI_COMMON_TEST_H //header guard
#define TUI_COMMON_TEST_H

#define TEST_DIMENSIONS 256
#define TEST_TILE_SIZE 8
#include <TUIC/tuic.h>

extern const char* kOutDirectoryPath;

TuiAtlas test_CreateCodepageAtlas(TuiInstance instance, int blend_mode);
TuiBatch test_GetTestPatternBatch(int detail_mode);
void test_BlendMode(TuiInstance instance, int blend_mode, TuiPanel panel);
void test_DetailMode(TuiInstance instance, int detail_mode, TuiPanel panel);
void test_PaletteType(TuiInstance instance, int palette_channel_count, TuiPanel panel);

#endif //header guard