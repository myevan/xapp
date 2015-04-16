#pragma once

#ifndef __X_SYSTEM__
#define __X_SYSTEM__

#include <x_foundation/XURI.h>
#include <x_foundation/XString.h>
#include <x_foundation/XBinary.h>

#include <string>

namespace xf { 

class XSystem
{
public:
    static XSystem& GetSystem();

public:
    virtual ~XSystem() {}

public:
    virtual bool TryGetResourceAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath) { return false; }
};

} // end_of_namespace:xf

#endif
