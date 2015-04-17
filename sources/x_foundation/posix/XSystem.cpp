#include "StdAfx.h"

#include <x_foundation/posix/XSystem.h>

using namespace xf;

namespace xf {

XSystem& XSystem::GetSystem()
{
    static posix::XSystem s_system;
    return s_system;
}

} // end_of_namespace:xf

namespace xf { namespace posix {

XSystem::XSystem()
{
}

} } // end_of_namespace:xf.ns
