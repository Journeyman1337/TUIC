cmake_minimum_required(VERSION 3.19)
find_package(Catch2 REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
add_executable(TUIC_TESTS_AUTO
	constants_test.hpp
	debug_test.hpp
	image_test.hpp
	palette_test.hpp
	test.cpp
)
target_link_libraries(TUIC_TESTS_AUTO 
	PUBLIC
		Catch2::Catch2
		${PROJECT_NAME}
		glfw
		GLEW::GLEW
)

include(CTest)
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(TUIC_TESTS_AUTO)