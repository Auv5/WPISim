cmake_minimum_required (VERSION 2.6)
project (wpisim)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (WPISim_SRCS
    ${PROJECT_SOURCE_DIR}/Compressor.cpp
    ${PROJECT_SOURCE_DIR}/Main.cpp
    ${PROJECT_SOURCE_DIR}/DigitalInput.cpp
    ${PROJECT_SOURCE_DIR}/MotorController.cpp
    ${PROJECT_SOURCE_DIR}/SimpleRobot.cpp)

# Compiler options
add_definitions (
    -std=c++11)


include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_INCLUDE_DIR}")

find_package (Threads)

add_library (${PROJECT_NAME} STATIC ${WPISim_SRCS})
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

set (${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_INCLUDE_DIR} CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)
