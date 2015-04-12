cmake_minimum_required(VERSION 2.8)

project(hello)

set(SOURCES
    StdAfx.cpp
    Main.cpp)

set(LIBRARIES
    x_foundation)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmakes")

include_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/include")
link_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/lib/static")

add_executable(hello ${SOURCES})
set_target_properties(hello PROPERTIES OUTPUT_NAME hello_posix)
set_target_properties(hello PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "StdAfx.h")
target_link_libraries(hello ${LIBRARIES})

include(cotire)
cotire(hello)

install(TARGETS hello
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
