cmake_minimum_required(VERSION 3.26.4)

project(op_v1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify the optimization level
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_executable(op_v1.0 main.cpp darb_su_fail.cpp generavimas.cpp ivest_tikrinimai.cpp prad_duom.cpp stdnt.cpp)

# copy txt files to build directory
add_custom_command(TARGET op_v1.0 POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:op_v1.0>/txt_failai
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/txt_failai $<TARGET_FILE_DIR:op_v1.0>/txt_failai)