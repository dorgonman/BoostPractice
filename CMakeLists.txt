cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT (BoostPractice CXX)


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_subdirectory(testbed)
add_subdirectory(LibCommonUtil)