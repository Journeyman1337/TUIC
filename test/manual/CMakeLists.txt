cmake_minimum_required(VERSION 3.19)
# cmake function for adding a manual test project
function(add_manual_test Name)
	# create the executable for the example
	set(TestProjName TUIC_MANUAL_TEST-${Name})
	add_executable(${TestProjName}
		${Name}.cpp
	)
	# link the implementation library
	target_link_libraries(${TestProjName}
		PRIVATE
			${PROJECT_NAME}
	)
	# grab the content file paths
	file(GLOB asset_files
		assets/*
	)
	# copy the content files to the executable output folder post build
	add_custom_command(TARGET ${TestProjName} POST_BUILD    
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			${asset_files}
			$<TARGET_FILE_DIR:${TestProjName}>
	)
	# tell visual studio to use the output folder as the working directory instead of the project folder
	set_property(TARGET ${TestProjName} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${TestProjName}>)
endfunction()

add_manual_test(atlas_creation)
add_manual_test(blend_mode_rendering)
add_manual_test(clipboard)
add_manual_test(cursor)
add_manual_test(desktop_events)
add_manual_test(detail_mode_rendering)
add_manual_test(error_codes)
add_manual_test(monitors)
add_manual_test(multiple_windows)
add_manual_test(palette_creation)
add_manual_test(palette_rendering)
add_manual_test(panel_drawing)
add_manual_test(panel_resizing)
add_manual_test(panel_screenshots)
add_manual_test(raw_mouse_motion)
add_manual_test(texture_creation)
add_manual_test(texture_updating)
add_manual_test(time)
add_manual_test(window_creation)
add_manual_test(window_decoration)
add_manual_test(window_drawing)
add_manual_test(window_resizing)
add_manual_test(window_screenshots)
add_manual_test(window_state)



