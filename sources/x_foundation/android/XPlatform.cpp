#include "StdAfx.h"

#include <x_foundation/XDefaultLogger.h>

#include <x_foundation/android/XLogger.h>

namespace xf {

ILogger& XDefaultLogger::GetDefaultLogger()
{
    static android::XLogger s_logger;
    return s_logger;
}

} // end_of_namespace:xf

