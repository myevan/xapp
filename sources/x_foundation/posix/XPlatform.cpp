#include "StdAfx.h"

#include <x_foundation/XPlatform.h>

#include <x_foundation/posix/XLogger.h>
#include <x_foundation/posix/XFileManager.h>

namespace xf {

XLogger& XPlatform::GetLogger()
{
    static posix::XLogger s_logger;
    return s_logger;
}

XFileManager& XPlatform::GetFileManager()
{
    static posix::XFileManager s_fileManager;
    return s_fileManager;
}

} // end_of_namespace:xf

