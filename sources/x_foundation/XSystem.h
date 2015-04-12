#pragma once

#ifndef __X_SYSTEM__
#define __X_SYSTEM__

#include <x_foundation/XString.h>

namespace xf { 

class XSystem
{
public:
    static XSystem& GetSystem();

public:
    virtual ~XSystem() {}

public:
    virtual bool TryGetResourceFileAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath) { return false; }
};

} // end_of_namespace:xf

#endif
