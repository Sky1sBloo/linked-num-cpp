cmake_minimum_required(VERSION 3.10)

project(linked-int-cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(src)
add_executable(linked-int-cpp main.cpp)
target_link_libraries(linked-int-cpp PRIVATE linked-int-lib)
