cmake_minimum_required(VERSION 2.8)

project(hello)

set(SOURCES
    main.cpp)

set(LIBRARIES
    x_foundation)

include_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/include")
link_directories("${CMAKE_SOURCE_DIR}/../../__platforms/posix/lib/static")

add_executable(hello ${SOURCES})
set_target_properties(hello PROPERTIES OUTPUT_NAME hello_posix)
target_link_libraries(hello ${LIBRARIES})

install(TARGETS hello
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
