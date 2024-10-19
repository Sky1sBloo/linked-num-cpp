add_library(linked-int-lib LinkedInt.cpp LinkedIntNode.cpp)
target_include_directories(linked-int-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
