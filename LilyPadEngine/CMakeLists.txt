cmake_minimum_required(VERSION 3.28.3)
project(LilyPadEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

option(RUN_TESTS "Build tests" OFF)

function (LinkDependencies Target)
    target_link_libraries(${Target} 
        PRIVATE
            glm::glm
            OpenGL::GL
            stb_image
            GLEW::GLEW
            glfw
            ${FREETYPE_LIBRARIES}
    )
endfunction()

# Set STATIC for Windows only
if (WIN32)
    set(LIBRARY_TYPE "STATIC")
else()
    set(LIBRARY_TYPE "SHARED")
endif()

# Add all cpp and hpp files to the library
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

foreach(TEXTURE_FILE ${TEXTURE_FILES})
    file(COPY ${TEXTURE_FILE} DESTINATION ${CMAKE_BINARY_DIR}/rsc/textures)
endforeach()

if (WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw-3.4)
else()
    find_package(glfw3 REQUIRED)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm)
find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
message(STATUS "FreeType Include Dirs: ${FREETYPE_INCLUDE_DIRS}")
message(STATUS "FreeType Libraries: ${FREETYPE_LIBRARIES}")

add_library(LilyPadEngine ${LIBRARY_TYPE} ${SOURCES} )
add_library(stb_image ${LIBRARY_TYPE} "vendor/stb_image.cpp")

target_include_directories(
    LilyPadEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor
        ${FREETYPE_INCLUDE_DIRS}
)

LinkDependencies(LilyPadEngine)

if (${RUN_TESTS})
    message("RUN_TESTS enabled")
    enable_testing()
    include(CTest)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
