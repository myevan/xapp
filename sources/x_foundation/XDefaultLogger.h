#pragma once

#ifndef __X_LOGGER_MANAGER__
#define __X_LOGGER_MANAGER__

#include <x_foundation/ILogger.h>

namespace xf {

class XLoggerManager
{
public:
    static ILogger& GetDefaultLogger();
};

} // end_of_namespace:xf

#endif
