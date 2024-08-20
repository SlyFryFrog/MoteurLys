cmake_minimum_required(VERSION 3.28.3)
project(Demo)

option(RUN_TESTS "Build tests" ON)

enable_testing()
include(CTest)

add_definitions(-DOpenGL)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Lys)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/demo)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Fleur)