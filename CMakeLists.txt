cmake_minimum_required(VERSION 3.10)

project(linked-int-cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(src)
add_executable(linked-int-cpp main.cpp)
target_link_libraries(linked-int-cpp PRIVATE linked-int-lib)
