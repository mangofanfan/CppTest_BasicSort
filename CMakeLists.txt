cmake_minimum_required(VERSION 3.10.0)
project(CppTest1 VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE Sortlib_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/sortlib/*.cxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/sortlib/*.h"
)

add_library(sortlib STATIC ${Sortlib_SRC})

add_executable(CppTest1_cmd main.cxx)
add_executable(CppTest1_word word.cxx)

target_include_directories(CppTest1_cmd PRIVATE sortlib)
target_include_directories(CppTest1_word PRIVATE sortlib)

target_link_libraries(CppTest1_cmd PRIVATE sortlib)
target_link_libraries(CppTest1_word PRIVATE sortlib)


