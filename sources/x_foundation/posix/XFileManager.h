#pragma once

#ifndef __POSIX_X_SYSTEM__
#define __POSIX_X_SYSTEM__

#include <x_foundation/XFileManager.h>

namespace xf { namespace posix {

class XFileManager : public xf::XFileManager
{
public:
    virtual ~XFileManager() {}

public:
    XFileManager();

    void SetProgramArguments(int argCount, const char** args) override;
};

} } // end_of_namespace:xf.ns

#endif
