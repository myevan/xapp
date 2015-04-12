if (ANDROID)
    set(PLATFORM_SOURCES 
        android/XJNIDefaultLogger.cpp
        android/XJNIBaseConfig.cpp
        android/XJNISystem.cpp)

    add_definitions(
        -DJNI_PACKAGE_NAME=${JNI_PACKAGE_NAME} 
        -DJNI_CLASS_NAME=${JNI_CLASS_NAME})

    add_library(x_interface SHARED ${COMMON_SOURCES} ${PLATFORM_SOURCES})

    target_link_libraries(x_interface x_foundation log)

    install(TARGETS x_interface 
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib/static)
endif()

