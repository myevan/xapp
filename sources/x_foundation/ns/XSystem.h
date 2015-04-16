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

    bool TryGetResourceAbsPath(const XString& dirPath, const XString& fileName, std::string& outAbsPath) override;

    virtual XBinary* TryGetResourceBinary(const XString& dirRelPath, const XString& fileName) override;

public:
    NSString* NSGetResourceAbsPath(const XString& dirPath, const XString& fileName);

private:
    NSBundle* m_mainBundle;
};

} } // end_of_namespace:xf.ns

#endif
