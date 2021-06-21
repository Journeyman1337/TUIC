#ifndef TUI_OPENGL33_TEST_H //header guard
#define TUI_OPENGL33_TEST_H

#include <TUIC/tuic.h>
#include <GLFW/glfw3.h>

TuiInstance test_Opengl33Initialize(size_t window_width, size_t window_height, GLFWwindow** window);
TuiInstance test_Opengl33Terminate(TuiInstance instance);

#endif //header guard