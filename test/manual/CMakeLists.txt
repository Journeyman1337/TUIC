cmake_minimum_required(VERSION 3.19)
add_executable(TUIC_TESTS_MANUAL
	common_test.cpp
	common_test.hpp
	opengl33_test.cpp
	opengl33_test.hpp
	test.cpp
	test_impl.cpp
)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
target_link_libraries(TUIC_TESTS_MANUAL
	PUBLIC
		${PROJECT_NAME}
		glfw
		GLEW::GLEW
)
file(GLOB asset_files
	assets/*
)
# copy the content files to the executable output folder post build
add_custom_command(TARGET TUIC_TESTS_MANUAL POST_BUILD    
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${asset_files}
		$<TARGET_FILE_DIR:TUIC_TESTS_MANUAL>
)
# tell visual studio to use the output folder as the working directory instead of the project folder
set_property(TARGET TUIC_TESTS_MANUAL PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:TUIC_TESTS_MANUAL>)