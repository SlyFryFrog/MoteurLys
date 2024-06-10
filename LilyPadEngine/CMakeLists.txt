cmake_minimum_required(VERSION 3.22)
project(LilyPadEngine)

# Add all cpp and hpp files to the library
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

file(GLOB_RECURSE SHADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/rsc/shaders/*.glsl)
file(GLOB_RECURSE TEXTURE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/rsc/textures/*)

foreach(SHADER_FILE ${SHADER_FILES})
    file(COPY ${SHADER_FILE} DESTINATION ${CMAKE_BINARY_DIR}/rsc/shaders)
endforeach()

foreach(TEXTURE_FILE ${TEXTURE_FILES})
    file(COPY ${TEXTURE_FILE} DESTINATION ${CMAKE_BINARY_DIR}/rsc/textures)
endforeach()

if (WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw-3.4)
else()
    find_package(glfw3 REQUIRED)
endif()

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_library(LilyPadEngine SHARED ${SOURCES})

add_library(stb_image SHARED "vendor/stb_image.cpp")
target_link_libraries(LilyPadEngine PRIVATE
    glfw
    OpenGL::GL
    stb_image
    GLEW::GLEW
)

target_include_directories(
    LilyPadEngine
    PUBLIC  # Can be used by other libraries
        ${CMAKE_CURRENT_SOURCE_DIR}/rsc
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor
    PRIVATE # For internal use only
        ${CMAKE_CURRENT_SOURCE_DIR}/src 
)
