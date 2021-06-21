#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <TUIC/tuic.h>
#include <TUIC/backends/opengl33.h>

#include <stdio.h>

TuiInstance test_Opengl33Initialize(size_t window_width, size_t window_height, GLFWwindow** window)
{
	/* GLFW and GLEW Initialization */
    if (!glfwInit())
    {
        printf("GLFW failed to initialize.\n");
        return NULL;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    *window = glfwCreateWindow(window_width, window_height, "TEST WINDOW", NULL, NULL);
    if (*window == NULL)
    {
        printf("Failed to create GLFW window.\n");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(*window);
	TuiInstance instance = tuiOpengl33InstanceCreate(window_width, window_height, ((void*)glfwGetProcAddress));
	return instance;
}

TuiInstance test_Opengl33Terminate(TuiInstance instance)
{
	tuiInstanceDestroy(instance);
	glfwTerminate();	
	return NULL;
}
