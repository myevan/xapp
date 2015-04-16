set(PUBLIC_HEADERS
    XString.h
    XBinary.h
    XHeapBinary.h
    XFileBinary.h
    XURI.h
    XLogType.h
    XLogMacros.h
    ILogger.h
    XDefaultLogger.h
    XSystem.h
    XBaseConfig.h)

set(COMMON_SOURCES
    StdAfx.cpp
    XString.cpp
    XPath.cpp
    XBaseConfig.cpp)

if (FORCE_POSIX)
    set(PLATFORM_SOURCES 
        posix/XLogger.cpp
        posix/XDefaultLogger.cpp)
elseif (ANDROID)
    set(PLATFORM_SOURCES 
        android/XAssetBinary.cpp
        android/XSystem.cpp
        android/XLogger.cpp
        android/XDefaultLogger.cpp)
elseif (IOS OR MAC)
    set(PLATFORM_DIR ns)
    set(PLATFORM_HEADERS
        ns/NSString+XString.h)
    set(PLATFORM_SOURCES 
        ns/NSString+XString.mm
        ns/XSystem.mm
        ns/XLogger.mm
        ns/XDefaultLogger.mm)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(x_foundation STATIC ${COMMON_SOURCES} ${PLATFORM_SOURCES})
set_target_properties(x_foundation PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "StdAfx.h")
cotire(x_foundation)

if(IOS)
    install(
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/\$ENV{CONFIGURATION}\$ENV{EFFECTIVE_PLATFORM_NAME}/ 
        DESTINATION lib/static\$ENV{EFFECTIVE_PLATFORM_NAME}
        COMPONENT x_foundation 
        FILES_MATCHING PATTERN "*.a")
else()
    install(
        TARGETS x_foundation 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
endif()

install(
    FILES ${PUBLIC_HEADERS} 
    DESTINATION include/x_foundation)

install(
    FILES ${PLATFORM_HEADERS} 
    DESTINATION include/x_foundation/${PLATFORM_DIR})



