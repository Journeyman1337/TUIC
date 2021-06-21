#include "common_test.hpp"
#include "opengl33_test.hpp"

#include <TUIC/tuic.h>

#include <stdio.h>

static int sNextFrame = TUI_FALSE;

void TuiMessageCallback(int error_code, const char* msg)
{
	if (error_code == TUI_ERROR_BACKEND_SPECIFIC)
	{
		printf("%s : %s backend message: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
	}
	else
	{
		printf("%s : %s location: %s\n", tuiErrorCodeToString(error_code), tuiErrorCodeGetDescription(error_code), msg);
	}

}

void frame(GLFWwindow* window, TuiPanel last_test)
{
	glfwSwapBuffers(window);
	glfwPollEvents();
	sNextFrame = TUI_FALSE;
	while(sNextFrame == TUI_FALSE)
	{
		tuiPanelRender(last_test);
		glfwSwapBuffers(window);
		glfwPollEvents();		
	}
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE)
	{
		sNextFrame = TUI_TRUE;
	}
}

int main()
{

	tuiSetDebugErrorCallback(TuiMessageCallback);	
	printf("Running tests. Verify that the output is correct for each test, and then press spacebar to run the next one.\n");
	GLFWwindow* window = NULL;
	printf("Starting opengl33 tests.\n");
	TuiInstance instance = test_Opengl33Initialize(TEST_TILE_SIZE * TEST_DIMENSIONS, TEST_TILE_SIZE * TEST_DIMENSIONS, &window);
	glfwSetKeyCallback(window, glfwKeyCallback);
	TuiPanel panel = tuiPanelCreate(instance, TEST_TILE_SIZE * TEST_DIMENSIONS, TEST_TILE_SIZE * TEST_DIMENSIONS);

	test_PaletteType(instance, 3, panel); frame(window, panel);
	test_PaletteType(instance, 4, panel); frame(window, panel);

	test_BlendMode(instance, TUI_BLEND_NORMAL, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_BG_RED, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_BG_GREEN, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_BG_BLUE, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_BG_ALPHA, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_FG_RED, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_FG_GREEN, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_FG_BLUE, panel); frame(window, panel);
	test_BlendMode(instance, TUI_BLEND_FG_ALPHA, panel); frame(window, panel);

	test_DetailMode(instance, TUI_DETAIL_G8_C4_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C8_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C8NBG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C8NFG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C24_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C24NBG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C24NFG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C32_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C32NBG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C32NFG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C4_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C8_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C8NBG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C8NFG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C24_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C24NBG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C24NFG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C32_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C32NBG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C32NFG_FULL, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C4_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C8_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C8NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C8NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C24_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C24NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C24NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C32_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C32NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G8_C32NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C4_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C8_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C8NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C8NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C24_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C24NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C24NFG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C32_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C32NBG_SPARSE, panel); frame(window, panel);
	test_DetailMode(instance, TUI_DETAIL_G16_C32NFG_SPARSE, panel); frame(window, panel);

	tuiPanelDestroy(panel);
	instance = test_Opengl33Terminate(instance);
	printf("Opengl33 tests complete.\n");
	
	printf("All tests complete.\n");
	return 0;
}