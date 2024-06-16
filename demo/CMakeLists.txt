cmake_minimum_required(VERSION 3.22)
project(Demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Add all cpp and hpp files to the library
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

file(GLOB_RECURSE SHADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/rsc/shaders/*.glsl)
file(GLOB_RECURSE TEXTURE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/rsc/textures/*)

foreach(SHADER_FILE ${SHADER_FILES})
    file(COPY ${SHADER_FILE} DESTINATION ${CMAKE_BINARY_DIR}/demo/rsc/shaders)
endforeach()

foreach(TEXTURE_FILE ${TEXTURE_FILES})
    file(COPY ${TEXTURE_FILE} DESTINATION ${CMAKE_BINARY_DIR}/demo/rsc/textures)
endforeach()

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
    GLEW::GLEW
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/rsc)