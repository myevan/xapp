cmake_minimum_required(VERSION 3.0)

project(framework)

option(FORCE_POSIX "Force to build on POSIX mode" OFF)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmakes")

include(cotire)

include_directories("${CMAKE_SOURCE_DIR}/sources")

if (FORCE_POSIX)
    add_definitions("-DPOSIX=1")
elseif (ANDROID)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(ANDROID_PROJECT_DIR "${CMAKE_BINARY_DIR}/${ANDROID_PROJECT_DIR}")
endif()

add_subdirectory(sources/x_foundation)
add_subdirectory(sources/x_interface)

