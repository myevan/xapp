set(PUBLIC_HEADERS
    XLua.h)

set(COMMON_SOURCES
    XLua.cpp
    StdAfx.cpp)

set(COMMON_LIBRARIES
    x_foundation)

macro(ndk_gdb_debuggable TARGET_NAME)
    set(TARGET_LOCATION $<TARGET_FILE:${TARGET_NAME}>)

    # create custom target that depends on the real target so it gets executed afterwards
    add_custom_target(NDK_GDB ALL) 
    add_dependencies(NDK_GDB ${TARGET_NAME})

    set(GDB_SOLIB_PATH ${ANDROID_PROJECT_DIR}/obj/local/${ANDROID_NDK_ABI_NAME}/)
    
    # 1. generate essential Android Makefiles
    file(WRITE ${ANDROID_PROJECT_DIR}/jni/Android.mk "APP_ABI := ${ANDROID_NDK_ABI_NAME}\n")
    file(WRITE ${ANDROID_PROJECT_DIR}/jni/Application.mk "APP_ABI := ${ANDROID_NDK_ABI_NAME}\n")

    # 2. generate gdb.setup
    get_directory_property(PROJECT_INCLUDES DIRECTORY ${PROJECT_SOURCE_DIR} INCLUDE_DIRECTORIES)
    string(REGEX REPLACE ";" " " PROJECT_INCLUDES "${PROJECT_INCLUDES}")
    file(WRITE ${ANDROID_PROJECT_DIR}/libs/${ANDROID_NDK_ABI_NAME}/gdb.setup "set solib-search-path ${GDB_SOLIB_PATH}\n")
    file(APPEND ${ANDROID_PROJECT_DIR}/libs/${ANDROID_NDK_ABI_NAME}/gdb.setup "directory ${PROJECT_INCLUDES}\n")

    # 3. copy gdbserver executable
    file(COPY ${ANDROID_NDK}/prebuilt/android-arm/gdbserver/gdbserver DESTINATION ${ANDROID_PROJECT_DIR}/libs/${ANDROID_NDK_ABI_NAME}/)

    # 4. copy lib to obj
    add_custom_command(TARGET NDK_GDB POST_BUILD COMMAND mkdir -p ${GDB_SOLIB_PATH})
    add_custom_command(TARGET NDK_GDB POST_BUILD COMMAND cp ${TARGET_LOCATION} ${GDB_SOLIB_PATH})

    # 5. strip symbols
    add_custom_command(TARGET NDK_GDB POST_BUILD COMMAND ${CMAKE_STRIP} ${TARGET_LOCATION})
endmacro()

if (FORCE_POSIX)
    set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
elseif (ANDROID)
    set(PLATFORM_SOURCES 
        StdAfx.cpp
        android/XJNIDefaultLogger.cpp
        android/XJNIBaseConfig.cpp
        android/XJNISystem.cpp)

    set(PLATFORM_LIBRARIES
        log
        android)

    add_definitions(
        -DJNI_PACKAGE_NAME=${JNI_PACKAGE_NAME} 
        -DJNI_CLASS_NAME=${JNI_CLASS_NAME})

endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories("${PROJECT_SOURCE_DIR}/__prebuilts/posix/lua-5.1.5/include")
include_directories("${PROJECT_SOURCE_DIR}/__prebuilts/posix/lua_tinker-143aa248081/include")
link_directories("${PROJECT_SOURCE_DIR}/__prebuilts/posix/lua-5.1.5/lib")
link_directories("${PROJECT_SOURCE_DIR}/__prebuilts/posix/lua_tinker-143aa248081/lib")

if (ANDROID)
    add_library(x_interface SHARED ${COMMON_SOURCES} ${PLATFORM_SOURCES})
else()
    add_library(x_interface STATIC ${COMMON_SOURCES} ${PLATFORM_SOURCES})
endif()

target_link_libraries(x_interface ${COMMON_LIBRARIES} ${PLATFORM_LIBRARIES})
set_target_properties(x_interface PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "StdAfx.h")
cotire(x_interface)

if (ANDROID)
    ndk_gdb_debuggable(x_interface)
endif()

install(
    FILES ${PUBLIC_HEADERS} 
    DESTINATION include/x_interface)

install(TARGETS x_interface 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
