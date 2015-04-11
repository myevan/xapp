cmake_minimum_required(VERSION 2.8)

project(framework)

include_directories("${PROJECT_SOURCE_DIR}/sources")

if (ANDROID)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

add_subdirectory(sources/x_foundation)
add_subdirectory(sources/x_interface)

