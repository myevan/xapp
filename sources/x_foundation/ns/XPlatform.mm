#include "StdAfx.h"

#include <x_foundation/XPlatform.h>

#include <x_foundation/ns/XLogger.h>
#include <x_foundation/ns/XFileManager.h>

namespace xf {

XLogger& XPlatform::GetLogger()
{
    static ns::XLogger s_logger;
    return s_logger;
}

XFileManager& XPlatform::GetFileManager()
{
    static ns::XFileManager s_fileManager;
    return s_fileManager;
}

} // end_of_namespace:xf

