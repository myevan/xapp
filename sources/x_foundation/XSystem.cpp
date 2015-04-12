#include "StdAfx.h"

#include <x_foundation/XSystem.h>

#include <x_foundation/XOSDefine.h>

#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
//#   include <x_foundation/ns/XSystem.h>
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
//#   include <x_foundation/ns/XSystem.h>
#endif

namespace xf {

XSystem& XSystem::GetSystem()
{
#if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
//    static ns::XSystem s_system;
#elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
//    static ns::XSystem s_system;
#else
#endif
    static XSystem s_system;
    return s_system;
}

} // end_of_namespace:xf
