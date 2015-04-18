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

public:
    std::shared_ptr<XFileStream> OpenStream(const XString& uri) override;

private:
    NSBundle* m_mainBundle;
};

} } // end_of_namespace:xf.ns

#endif
