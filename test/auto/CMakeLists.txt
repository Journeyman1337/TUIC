cmake_minimum_required(VERSION 3.19)
find_package(Catch2 CONFIG REQUIRED)
add_executable(TUIC_TESTS_AUTO
	constants_test.cpp
	debug_test.cpp
	image_test.cpp
	palette_test.cpp
	test.cpp
)
target_link_libraries(TUIC_TESTS_AUTO 
	PRIVATE
		Catch2::Catch2
		${PROJECT_NAME}
)
include(CTest)
include(Catch)
catch_discover_tests(
  TUIC_TESTS_AUTO
  TEST_PREFIX "unittests."
  REPORTER junit
  OUTPUT_DIR ${CMAKE_SOURCE_DIR}
  OUTPUT_PREFIX "unittests."
  OUTPUT_SUFFIX .xml
)
