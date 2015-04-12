#include "StdAfx.h"

#include <x_foundation/XDefaultLogger.h>

#include <x_foundation/posix/XLogger.h>

namespace xf {

ILogger& XDefaultLogger::GetDefaultLogger()
{
    static posix::XLogger s_logger;
    return s_logger;
}

} // end_of_namespace:xf

