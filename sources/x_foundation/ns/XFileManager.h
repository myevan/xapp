#pragma once

#ifndef __NS_X_FILE_MANAGER__
#define __NS_X_FILE_MANAGER__

#include <x_foundation/XFileManager.h>

namespace xf { namespace ns {

class XFileManager : public xf::XFileManager
{
public:
    XFileManager();

public:
    virtual ~XFileManager() {}

    void SetExecFilePath(const XPath& execFilePath)
    {}

    void SetDataDirPath(const XPath& dataDirPath)
    {}

public:
    std::shared_ptr<XStream> OpenStream(const XString& uri) override;

private:
    NSBundle* m_mainBundle;
};

} } // end_of_namespace:xf.ns

#endif
