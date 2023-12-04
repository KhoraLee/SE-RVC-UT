add_executable(rvc_test src/test_rvc.c src/Mock_hw_interface.c)
target_include_directories(rvc_test PUBLIC include)
target_link_libraries(rvc_test PUBLIC CMock Unity RVC_SW)

add_test(test_rvc_sw rvc_test)
