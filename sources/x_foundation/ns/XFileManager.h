#pragma once

#ifndef __NS_X_FILE_MANAGER__
#define __NS_X_FILE_MANAGER__

#include <x_foundation/XFileManager.h>

namespace xf { namespace ns {

class XFileManager : public xf::XFileManager
{
public:
    virtual ~XFileManager() {}

public:
    XFileManager();

    bool TryGetResourceAbsPath(const XString& dirPath, const XString& fileName, std::string& outAbsPath) override;

    virtual XBinary* TryGetResourceBinary(const XString& dirPath, const XString& fileName) override;

public:
    NSString* NSGetResourceAbsPath(const XString& dirPath, const XString& fileName);

private:
    NSBundle* m_mainBundle;
};

} } // end_of_namespace:xf.ns

#endif
