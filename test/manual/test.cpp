#include "common_test.hpp"

#include <TUIC/tuic.h>

#include <stdio.h>

static int sNextFrame = TUI_FALSE;

void TuiMessageCallback(TuiErrorCode error_code, const char* msg)
{
	if (error_code == TUI_ERROR_GRAPHICS_BACKEND_SPECIFIC)
	{
		printf("%s : %s backend message: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
	}
	else
	{
		printf("%s : %s location: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
	}
}


void frame(TuiWindow window, TuiPanel last_test)
{
	tuiWindowFrame(window);
	tuiPollEvents();
	sNextFrame = TUI_FALSE;
	while(sNextFrame == TUI_FALSE)
	{
		tuiWindowDrawPanel(window, last_test);
		tuiWindowFrame(window);
		tuiPollEvents();
	}
}

void key_callback(TuiWindow window, TuiKeyboardKey key, int scancode, TuiButtonState button_state, TuiKeyboardMod mods)
{
	if (key == TUIK_SPACE)
	{
		sNextFrame = TUI_TRUE;
	}
}

int main()
{
	if (tuiInit() == TUI_FALSE)
	{
		printf("Failed to initialize TUIC.");
		return -1;
	}

	tuiSetDebugErrorCallback(TuiMessageCallback);
	TuiWindow window = tuiWindowCreate(TEST_DIMENSIONS * TEST_TILE_SIZE, TEST_DIMENSIONS * TEST_TILE_SIZE, "TUIC TESTS", TUI_NULL);
	tuiWindowSetKeyboardKeyCallback(window, key_callback);

	printf("Running tests. Verify that the output is correct for each test, and then press spacebar to run the next one.\n");

	TuiPanel panel = tuiPanelCreate(TEST_TILE_SIZE * TEST_DIMENSIONS, TEST_TILE_SIZE * TEST_DIMENSIONS);

	test_Palette(3, panel); frame(window, panel);
	test_Palette(4, panel); frame(window, panel);

	test_BlendMode(TUI_BLEND_NORMAL, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_BG_RED, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_BG_GREEN, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_BG_BLUE, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_BG_ALPHA, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_FG_RED, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_FG_GREEN, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_FG_BLUE, panel); frame(window, panel);
	test_BlendMode(TUI_BLEND_FG_ALPHA, panel); frame(window, panel);

	test_DetailMode(TUI_DETAIL_MODE_G8_C4_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C8_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C8NBG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C8NFG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C24_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C24NBG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C24NFG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C32_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C32NBG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C32NFG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C4_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C8_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C8NBG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C8NFG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C24_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C24NBG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C24NFG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C32_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C32NBG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C32NFG_FULL, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C4_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C8_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C8NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C8NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C24_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C24NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C24NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C32_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C32NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G8_C32NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C4_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C8_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C8NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C8NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C24_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C24NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C24NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C32_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C32NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(TUI_DETAIL_MODE_G16_C32NFG_SPARSE, panel); frame(window, panel);

	tuiPanelDestroy(panel);
	printf("Opengl33 tests complete.\n");

	tuiWindowDestroy(window);
	tuiTerminate();
	
	printf("All tests complete.\n");
	return 0;
}