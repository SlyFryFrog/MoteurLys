cmake_minimum_required(VERSION 3.28.3)
project(MoteurLys)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(VENDOR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../vendor)
set(IMGUI_PATH ${VENDOR_PATH}/imgui)

# Add ImGui source files
set(IMGUI_SRC
    ${IMGUI_PATH}/imgui.cpp
    ${IMGUI_PATH}/imgui_draw.cpp
    ${IMGUI_PATH}/imgui_demo.cpp
    ${IMGUI_PATH}/imgui_tables.cpp
    ${IMGUI_PATH}/imgui_widgets.cpp
    ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
)

# Set STATIC for Windows only
if (WIN32)
    set(LIBRARY_TYPE "STATIC")
else()
    set(LIBRARY_TYPE "SHARED")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -O1")
endif()


function(LinkDependencies Target)
    target_link_libraries(${Target} 
        PRIVATE
            stb_image
            GLEW::GLEW
            glm::glm
            glfw
            Jolt
            ${FREETYPE_LIBRARIES}
            OpenGL::GL
        PUBLIC
            imgui
    )
endfunction()


# Add all cpp and hpp files to the library
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)

find_package(glfw3 REQUIRED)
find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory(${VENDOR_PATH}/JoltPhysics/Build ${CMAKE_BINARY_DIR}/vendor/JoltPhysics)
add_subdirectory(${VENDOR_PATH}/glm ${CMAKE_BINARY_DIR}/vendor/glm)

# Include directories for Jolt
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/JoltPhysics/Jolt
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/JoltPhysics/Jolt/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/JoltPhysics/ThirdParty
)

add_library(MoteurLys ${LIBRARY_TYPE} ${SOURCES})
add_library(stb_image ${LIBRARY_TYPE} ${VENDOR_PATH}/stb_image.cpp)
add_library(imgui ${LIBRARY_TYPE} ${IMGUI_SRC})
target_include_directories(imgui PUBLIC ${IMGUI_PATH} ${IMGUI_PATH}/backends)


target_include_directories(
    MoteurLys
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${VENDOR_PATH}
        ${FREETYPE_INCLUDE_DIRS}
)

LinkDependencies(MoteurLys)

if (${RUN_TESTS})
    message("RUN_TESTS enabled")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
