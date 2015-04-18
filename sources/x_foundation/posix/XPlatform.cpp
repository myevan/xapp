#include "StdAfx.h"

#include <x_foundation/XPlatform.h>

#include <x_foundation/posix/XLogger.h>
#include <x_foundation/posix/XSystem.h>

namespace xf {

ILogger& XPlatform::GetLogger()
{
    static posix::XLogger s_logger;
    return s_logger;
}

XSystem& XPlatform::GetSystem()
{
    static posix::XSystem s_system;
    return s_system;
}

} // end_of_namespace:xf

