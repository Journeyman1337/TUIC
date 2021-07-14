# cmake function for adding an example project
function(add_example Name)
	# create the executable for the example
	add_executable(${Name}
		${Name}/main.c
	)
	# link the implementation library
	target_link_libraries(${Name}
		PRIVATE
			${PROJECT_NAME}
	)
	# grab the content file paths
	file(GLOB asset_files
		assets/*
	)
	# copy the content files to the executable output folder post build
	add_custom_command(TARGET ${Name} POST_BUILD    
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			${asset_files}
			$<TARGET_FILE_DIR:${Name}>
	)
	# tell visual studio to use the output folder as the working directory instead of the project folder
	set_property(TARGET ${Name} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${Name}>)
endfunction()

add_example(Example-01-Classic-Panel)
add_example(Example-XX-Multiple-Window)
