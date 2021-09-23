cmake_minimum_required(VERSION 3.19)
find_package(Catch2 CONFIG REQUIRED)
add_executable(TUIC_TESTS_AUTO
	atlas_type_test.cpp
	blend_mode_test.cpp
	box_part_test.cpp
	button_state_test.cpp
	circle_test.cpp
	cursor_mode_test.cpp
	cursor_shape_test.cpp
	detail_flag_test.cpp
	detail_mode_test.cpp
	error_code_test.cpp
	filter_mode_test.cpp
	image_test.cpp
	keyboard_key_test.cpp
	keyboard_mod_test.cpp
	line_test.cpp
	mouse_button_test.cpp
	palette_test.cpp
	point2_test.cpp
	rect_test.cpp
	ring_test.cpp
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
