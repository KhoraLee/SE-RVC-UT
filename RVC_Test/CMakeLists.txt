find_program(RUBY_EXECUTABLE "ruby")

if (NOT RUBY_EXECUTABLE)
    message(FATAL_ERROR "Ruby not found")
endif()

file(GLOB Test_Sources src/*.c)
add_executable(rvc_test ${Test_Sources})
target_include_directories(rvc_test PUBLIC include)
target_link_libraries(rvc_test PUBLIC CMock Unity RVC_SW)

# Update Unit test runner using Unity ruby script
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/test_runner.c
	COMMAND ${RUBY_EXECUTABLE} ${PROJECT_SOURCE_DIR}/external/Unity/auto/generate_test_runner.rb rvc_unit_test.c test_runner.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/rvc_unit_test.c)

# set_target_properties(rvc_test PROPERTIES OUTPUT_NAME RVC_TEST
# 	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
# 	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
# 	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
# )
add_test(test_rvc_sw rvc_test)
