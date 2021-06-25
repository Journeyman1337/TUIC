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
	${CMAKE_CURRENT_SOURCE_DIR}/src/batch.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/enums.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/glyph_atlas.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/heap.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/image.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/impl.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/palette.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/panel.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/instance.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/debug.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/image_inline.h
	# Include files
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/batch.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/enums.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/debug.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/glyph_atlas.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/heap.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/image.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/instance.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/palette.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/panel.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/tuic.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/types.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/backends/objects.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/vendor/glDebug.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/vendor/stb_image.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/vendor/stb_image_resize.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/vendor/stb_image_write.h
)

if (TUIC_OPENGL33_BACKEND)
	add_subdirectory(shaders/Opengl33)
	set(TUIC_SOURCES ${TUIC_SOURCES} 
		${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/backends/opengl33.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/TUIC/backends/opengl33_implementation.h
	)
endif()

add_library(${PROJECT_NAME}
	${TUIC_SOURCES}
)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} 
        PUBLIC
            m
    )
endif()

target_include_directories(${PROJECT_NAME}
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
