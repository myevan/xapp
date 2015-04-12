#pragma once

#ifndef __X_LOGGER__
#define __X_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf {

class XLogger
{
public:
    static ILogger& GetInstance();
};

} // end_of_namespace:xf

#endif
