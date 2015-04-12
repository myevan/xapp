cmake_minimum_required(VERSION 2.8)

project(framework)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmakes")

include(cotire)

include_directories("${CMAKE_SOURCE_DIR}/sources")

if (POSIX)
    add_definitions("-DPOSIX=1")
elseif (ANDROID)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

add_subdirectory(sources/x_foundation)
add_subdirectory(sources/x_interface)

