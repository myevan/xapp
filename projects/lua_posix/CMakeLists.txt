cmake_minimum_required(VERSION 2.8)

project(lua)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmakes")

set(DATA_DIR "${CMAKE_SOURCE_DIR}/../lua_data")

set(DATA_FILES 
    "${DATA_DIR}/main.lua")

set(SOURCES
    StdAfx.cpp
    Main.cpp)

set(LIBRARIES
    x_foundation
    lua_static
    lua_tinker_static)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

include_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/include")
include_directories("${CMAKE_SOURCE_DIR}/../../__prebuilts/posix/lua-5.1.5/include")
include_directories("${CMAKE_SOURCE_DIR}/../../__prebuilts/posix/lua_tinker-143aa248081/include")
link_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/lib/static")
link_directories("${CMAKE_SOURCE_DIR}/../../__prebuilts/posix/lua-5.1.5/lib")
link_directories("${CMAKE_SOURCE_DIR}/../../__prebuilts/posix/lua_tinker-143aa248081/lib")

add_executable(lua ${SOURCES})
set_target_properties(lua PROPERTIES OUTPUT_NAME lua_posix)
set_target_properties(lua PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "StdAfx.h")
target_link_libraries(lua ${LIBRARIES})

include(cotire)
cotire(lua)

install(TARGETS lua RUNTIME DESTINATION bin)

file(COPY ${DATA_FILES} DESTINATION "${CMAKE_SOURCE_DIR}/../../__platforms/posix/bin")
