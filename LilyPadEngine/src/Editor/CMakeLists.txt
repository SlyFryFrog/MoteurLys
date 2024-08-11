project(LilyPadEditor)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_executable(LilyPadEditor ${SOURCES} ${HEADERS} ${IMGUI_SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(LilyPadEditor 
    LilyPadEngine
    OpenGL::GL
)