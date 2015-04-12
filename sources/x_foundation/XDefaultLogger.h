#pragma once

#ifndef __X_DEFAULT_LOGGER__
#define __X_DEFAULT_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf {

class XDefaultLogger
{
public:
    static ILogger& GetDefaultLogger();
};

} // end_of_namespace:xf

#endif
