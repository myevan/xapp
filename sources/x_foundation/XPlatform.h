#pragma once

#ifndef __X_PLATFORM__
#define __X_PLATFORM__

#include <x_foundation/ILogger.h>
#include <x_foundation/XSystem.h>

namespace xf {

class XPlatform
{
public:
    static ILogger& GetLogger();
    static XSystem& GetSystem();
};

} // end_of_namespace:xf

#endif
