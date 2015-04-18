#include "StdAfx.h"

#include <x_foundation/XDefaultLogger.h>

#include <x_foundation/ns/XLogger.h>
#include <x_foundation/ns/XSystem.h>

namespace xf {

ILogger& XPlatform::GetLogger()
{
    static ns::XLogger s_logger;
    return s_logger;
}

XSystem& XPlatform::GetSystem()
{
    static ns::XSystem s_system;
    return s_system;
}

} // end_of_namespace:xf

