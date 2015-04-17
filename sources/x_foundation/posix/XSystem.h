#pragma once

#ifndef __POSIX_X_SYSTEM__
#define __POSIX_X_SYSTEM__

#include <x_foundation/XSystem.h>

namespace xf { namespace posix {

class XSystem : public xf::XSystem
{
public:
    virtual ~XSystem() {}

public:
    XSystem();

};

} } // end_of_namespace:xf.ns

#endif
