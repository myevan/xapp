cmake_minimum_required(VERSION 2.8)

project(text)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmakes")

set(DATA_DIR "${CMAKE_SOURCE_DIR}/../hello_data")

set(DATA_FILES 
    "${DATA_DIR}/test.txt")

set(SOURCES
    StdAfx.cpp
    Main.cpp)

set(LIBRARIES
    x_foundation)

include_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/include")
link_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/lib/static")

add_executable(text ${SOURCES})
set_target_properties(text PROPERTIES OUTPUT_NAME text_posix)
set_target_properties(text PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "StdAfx.h")
target_link_libraries(text ${LIBRARIES})

include(cotire)
cotire(text)

install(TARGETS text RUNTIME DESTINATION bin)

file(COPY ${DATA_FILES} DESTINATION "${CMAKE_SOURCE_DIR}/../../__platforms/posix/bin")
