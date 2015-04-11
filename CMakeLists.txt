cmake_minimum_required(VERSION 2.8)

project(framework)

include_directories("${PROJECT_SOURCE_DIR}/sources")

add_subdirectory(sources/x_foundation)
add_subdirectory(sources/x_interface)

