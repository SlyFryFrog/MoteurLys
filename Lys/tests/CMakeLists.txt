add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/googletest ${CMAKE_BINARY_DIR}/vendor/googletest)
file(GLOB_RECURSE TESTS ${CMAKE_CURRENT_SOURCE_DIR}/Lys/*.cpp)

# Adds test or each file
foreach(TEST_FILE ${TESTS})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE) # Get the filename without extension
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME}) # Set a unique name for each test suite
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE gtest gtest_main MoteurLys)
    LinkDependencies(${TEST_NAME})
    message("Added test " ${TEST_NAME})
endforeach()
