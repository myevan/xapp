#include "StdAfx.h"

#include <x_foundation/XLoggerManager.h>
#include <x_foundation/XOSDefine.h>

#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
#   include <x_foundation/ns/XLogger.h>
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
#   include <x_foundation/ns/XLogger.h>
#elif X_TARGET_OS_GROUP == X_OS_ANDROID_GROUP
#   include <x_foundation/android/XLogger.h>
#else
#   include <x_foundation/posix/XLogger.h>
#endif

namespace xf {

ILogger& XLoggerManager::GetDefaultLogger()
{
#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
    static ns::XLogger s_logger;
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
    static ns::XLogger s_logger;
#elif X_TARGET_OS_GROUP == X_OS_ANDROID_GROUP
    static android::XLogger s_logger;
#else
    static posix::XLogger s_logger;
#endif
    return s_logger;
}

} // end_of_namespace:xf
