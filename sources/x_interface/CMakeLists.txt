if (ANDROID)
    set(PLATFORM_SOURCES 
        StdAfx.cpp
        android/XJNIDefaultLogger.cpp
        android/XJNIBaseConfig.cpp
        android/XJNISystem.cpp)

    include_directories(${CMAKE_CURRENT_SOURCE_DIR})

    add_definitions(
        -DJNI_PACKAGE_NAME=${JNI_PACKAGE_NAME} 
        -DJNI_CLASS_NAME=${JNI_CLASS_NAME})

    add_library(x_interface SHARED ${COMMON_SOURCES} ${PLATFORM_SOURCES})

    target_link_libraries(x_interface x_foundation log android)
    set_target_properties(x_interface PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "StdAfx.h")
    cotire(x_interface)

    install(TARGETS x_interface 
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib/static)
endif()

