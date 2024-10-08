cmake_minimum_required(VERSION 3.28.3)
project(Demo)


enable_testing()
include(CTest)

add_definitions(-DOPENGL)
add_definitions(-DBUILD_TESTS)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Lys)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/demo)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Fleur)