#include "StdAfx.h"
#include "XLogger.h"
#include "XFileManager.h"

#include <x_foundation/XPlatform.h>

namespace xf {

XLogger& XPlatform::GetLogger()
{
    static android::XLogger s_logger;
    return s_logger;
}

XFileManager& XPlatform::GetFileManager()
{
    static android::XFileManager s_fileManager;
    return s_fileManager;
}

} // end_of_namespace:xf

