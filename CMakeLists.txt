cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(LilyPadEngine)

# Add all cpp and hpp files to the library
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    message("Found package GLEW")
else()
    message("Could not find GLEW.")
endif()

if (WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw-3.4)
else()
    find_package(glfw3 REQUIRED)
endif()

add_executable(LilyPadEngine ${SOURCES} ${HEADERS})

target_link_libraries(LilyPadEngine PRIVATE
    GLEW::GLEW
    OpenGL::GL
    glfw
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)