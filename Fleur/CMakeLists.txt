project(EditeurFleur)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_executable(EditeurFleur ${SOURCES} ${HEADERS})

target_link_libraries(EditeurFleur 
    MoteurLys
)