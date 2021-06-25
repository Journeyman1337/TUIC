/*
	This example is compiles into a static library, and is a dependency of all the other examples. It contains implementations for the third party stb headers and the implentation of the TUIC library backend 
	used by the other examples.	For TUIC to work, a backend header must be implemented somewhere. It is good practice to implement your backend headers in a seperate file from any of your code, to prevent the 
	TUI opaque objects from appearing in your intellisense. You are not meant to edit the properties within opaque objects directly, as this can cause undefined behaviour. Instead, you are meant to pass these
	objects into the various functions declared in the tuic.h header file. 
	
	Currently, only an Opengl33 backend header ships with the library, but as more are added this file will be edited. The Opengl33 backend needs an include before it that includes all Opengl 
	functions. You can use any library that does this, such as GLAD, GLEW, or GLUT. For these examples, GLEW is included. The Opengl33 backend that ships with TUI includes a header only Opengl
	debugging library provided by glDebug.h. This debugging library can have a huge impact on performace, but will only run if NDEBUG macro is not set, so if you are using CMAKE it should only
	be used if you run your project in debug configuration. If you don't even want to run these macros in debug configuration, you can define the macro GLD_ACTIVE as 0 before including the backend.
*/

#include <GL/glew.h> //You need to include opengl bindings before implementing the opengl33 backend. You can use any Opengl loading library that you prefeer.
#define TUIC_OPENGL33_LOAD_GLEW //specify that glew is the library being used.
//#define TUIC_OPENGL33_LOAD_GLAD //specify this instead of previous macro to use GLAD instead of GLEW.
//#define TUIC_OPENGL33_LOAD_NONE //specify this to use no loading library. This will cause @ref tuiOpengl33InstanceCreateNewContext to return NULL.
#define TUIC_OPENGL33_IMPLEMENTATION // Including this before the header tells the compiler to implement the opengl33 backend.
//#define GLD_ACTIVE 0 //disable glDebug debugging library (increases performance in debug configuration builds for opengl33 backend)
#include <TUIC/backends/opengl33_implementation.h> //This header is for the implementation. Use tuic/backends/opengl33.h for includes everywhere else.
