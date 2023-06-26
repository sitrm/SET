cmake_minimum_required(VERSION 3.24.2)
# set the project name
project(TestLib VERSION 0.1)
set(SOURCE_EXE main.cpp)
set(SOURCE_EXE1 test.cpp)

set(SOURCE_LIB set.cpp set.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(Set STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})
add_executable(test ${SOURCE_EXE1})

add_subdirectory(googletest)
include_directories(googletest)

target_link_libraries(main Set)
target_link_libraries(test Set gtest gtest_main)