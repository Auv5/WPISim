cmake_minimum_required (VERSION 2.6)
project (wpisim_example)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (example_SRCS
    ${PROJECT_SOURCE_DIR}/ExampleBot.cpp
    ${PROJECT_SOURCE_DIR}/EDigitalInput.cpp)

# Compiler options
add_definitions (
    -std=c++11)

include_directories ("${wpisim_INCLUDE_DIRS}")

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_INCLUDE_DIR}")

add_executable (${PROJECT_NAME} ${example_SRCS})

target_link_libraries(${PROJECT_NAME} wpisim)
