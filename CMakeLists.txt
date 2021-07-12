cmake_minimum_required(VERSION 3.19)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the source directory and call cmake from there. Reccomendation: build with command \'cmake -S . -B ./build/\'")
endif()
project(TUIC
	VERSION 1.1
	DESCRIPTION "Text user interface rendering library in C."
	LANGUAGES C CXX
)
option(TUIC_BUILD_EXAMPLES "Build the example projects." OFF)
option(TUIC_BUILD_DOCS "Build documentation using Doxygen." OFF)
option(TUIC_BUILD_MANUAL_TESTS "Build manual test framework." OFF)
option(TUIC_BUILD_AUTO_TESTS "Build automatic test framework." OFF)
option(TUIC_OPENGL33_BACKEND "Include the Opengl33 backend." ON)

set(TUIC_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TUIC_CONFIGURE_HEADER_TEXT "")

set(TUIC_SOURCES
	# Source files
	${CMAKE_CURRENT_SOURCE_DIR}/src/atlas.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/atlas_type.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/batch.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/blend_mode.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/button_state.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/cursor.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/cursor_mode.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/cursor_shape.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/debug.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/detail_flag.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/detail_mode.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/error_code.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/events.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/filter_mode.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/glfw_error_check.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/heap.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/image.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/image_inline.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/joystick.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/joystick_hat_state.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/joystick_id.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/key.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/key_mod.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/monitor.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/mouse_button.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/palette.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/panel.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/system.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/texture.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/objects.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/time.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/window.c
	# Vendor Source Files
	${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/glDebug.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/stb_impl.c
	# Include Files
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/atlas.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/atlas_type.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/batch.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/blend_mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/boolean.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/button_state.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/cursor.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/cursor_mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/cursor_shape.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/debug.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/desktop_callback.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/detail_flag.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/detail_mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/error_code.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/events.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/filter_mode.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/heap.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/image.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/joystick.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/joystick_hat_state.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/joystick_id.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/key.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/key_mod.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/monitor.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/mouse_button.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/palette.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/panel.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/system.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/texture.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/time.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/tuic.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/types.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/window.h
)

set(TUIC_LINK_LIBRARIES
	""
)

if (TUIC_OPENGL33_BACKEND)
	find_package(glad CONFIG REQUIRED)
	add_subdirectory(shaders/Opengl33)
	set(TUIC_SOURCES ${TUIC_SOURCES} 
		${CMAKE_CURRENT_SOURCE_DIR}/src/opengl33.c
		${CMAKE_CURRENT_SOURCE_DIR}/src/opengl33.h
	)
	find_package(glfw3 CONFIG REQUIRED)
	find_package(glad CONFIG REQUIRED)
	set(TUIC_LINK_LIBRARIES ${TUIC_LINK_LIBRARIES}
		glfw
		glad::glad
	)
endif()

if (UNIX)
    set(TUIC_LINK_LIBRARIES ${TUIC_LINK_LIBRARIES}
		m
	)
endif()

add_library(${PROJECT_NAME}
	${TUIC_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
	${TUIC_LINK_LIBRARIES}
)

find_path(STB_INCLUDE_DIRS "stb.h")
target_include_directories(${PROJECT_NAME}
	PRIVATE
		${STB_INCLUDE_DIRS}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(TUIC_BUILD_DOCS)
	add_subdirectory(docs)
endif()
if(TUIC_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()
if(TUIC_BUILD_MANUAL_TESTS)
	add_subdirectory(test/manual/)
endif()
if(TUIC_BUILD_AUTO_TESTS)
	add_subdirectory(test/auto/)
endif()
