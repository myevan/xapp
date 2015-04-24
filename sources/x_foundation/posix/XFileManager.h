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

    void SetProgramPath(const XString& programPath) override;
    std::shared_ptr<XStream> OpenStream(const XString& uri) override;

private:
    std::shared_ptr<XStream> OpenFileStream(const XPath& branchAbsPath, const XString& leaf);
};

} } // end_of_namespace:xf.ns

#endif
