set(PUBLIC_HEADERS
    XString.h
    XLogType.h
    ILogger.h
    XLogger.h
    XLogMacros.h
    XBaseConfig.h)

set(COMMON_SOURCES
    XString.cpp
    XPath.cpp
    XPosixLogger.cpp
    XLoggerManager.cpp
    XBaseConfig.cpp)

if (ANDROID)
    set(PLATFORM_SOURCES 
        XAndroidLogger.cpp
        XAndroidSystem.cpp)
endif()

if (IOS OR MAC)
    set(PLATFORM_SOURCES 
        XNSLogger.mm)
endif()

add_library(x_foundation STATIC ${COMMON_SOURCES} ${PLATFORM_SOURCES})

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


