add_library(RVC_SW STATIC src/rvc.c)
target_include_directories(RVC_SW PUBLIC include ../RVC_HW/include)
