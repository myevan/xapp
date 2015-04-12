#include "StdAfx.h"

#include <x_foundation/XDefaultLogger.h>

#include <x_foundation/ns/XLogger.h>

namespace xf {

ILogger& XDefaultLogger::GetDefaultLogger()
{
    static ns::XLogger s_logger;
    return s_logger;
}

} // end_of_namespace:xf

