cmake_minimum_required(VERSION 3.22)
project(Demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Add all cpp and hpp files to the library
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

add_executable(Demo ${SOURCES} ${HEADERS})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if (WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw-3.4)
else()
    find_package(glfw3 REQUIRED)
endif()

target_link_libraries(Demo PRIVATE
    LilyPadEngine
    glfw
    OpenGL::GL
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)