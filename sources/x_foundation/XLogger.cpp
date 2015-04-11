#include <x_foundation/XLogger.h>
#include <x_foundation/XNSLogger.h>
#include <x_foundation/XOSDefine.h>

namespace xf {

ILogger& XLogger::GetInstance()
{

#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
    static XNSLogger s_logger;
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
    static XNSLogger s_logger;
#endif
    return s_logger;
}

} // end_of_namespace:xf
