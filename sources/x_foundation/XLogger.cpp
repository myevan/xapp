#include <x_foundation/XLogger.h>
#include <x_foundation/XOSDefine.h>

#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
#   include <x_foundation/XNSLogger.h>
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
#   include <x_foundation/XNSLogger.h>
#elif X_TARGET_OS_GROUP == X_OS_ANDROID_GROUP
#   include <x_foundation/XAndroidLogger.h>
#else
#   include <x_foundation/XPosixLogger.h>
#endif

namespace xf {

ILogger& XLogger::GetInstance()
{
#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
    static XNSLogger s_logger;
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
    static XNSLogger s_logger;
#elif X_TARGET_OS_GROUP == X_OS_ANDROID_GROUP
    static XAndroidLogger s_logger;
#else
    static XPosixLogger s_logger;
#endif
    return s_logger;
}

} // end_of_namespace:xf
