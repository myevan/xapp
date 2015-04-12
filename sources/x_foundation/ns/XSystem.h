#pragma once

#ifndef __NS_X_SYSTEM__
#define __NS_X_SYSTEM__

#include <x_foundation/XSystem.h>

namespace xf { namespace ns {

class XSystem : public xf::XSystem
{
public:
    virtual ~XSystem() {}

public:
    XSystem();

    bool TryGetResourceFileAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath);

private:
    NSBundle* m_mainBundle;
};

} } // end_of_namespace:xf.ns

#endif
