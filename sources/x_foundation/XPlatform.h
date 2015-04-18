#pragma once

#ifndef __X_PLATFORM__
#define __X_PLATFORM__

#include <x_foundation/ILogger.h>
#include <x_foundation/XFileManager.h>

namespace xf {

class XPlatform
{
public:
    static ILogger& GetLogger();
    static XFileManager& GetFileManager();
};

} // end_of_namespace:xf

#endif
