#pragma once

#ifndef __X_FILE_MANAGER__
#define __X_FILE_MANAGER__

#include <x_foundation/XPath.h>
#include <x_foundation/XText.h>
#include <x_foundation/XString.h>
#include <x_foundation/XStream.h>

#include <string>
#include <memory>

namespace xf { 

class XFileManager
{
public:
    XFileManager() 
    {}

    virtual ~XFileManager() 
    {}

public:
    virtual void SetProgramPath(const XString& programPath);

public:
    bool TryParseURI(const XString& uri, XString& outScheme, XString& outBody);

public:
    virtual std::shared_ptr<XStream> OpenStream(const XString& uri) = 0;

public:
    std::shared_ptr<XBinary>    LoadBinary(const XString& uri);
    std::shared_ptr<XText>      LoadText(const XString& uri);


protected:
    XPath m_appDirAbsPath;

};

} // end_of_namespace:xf

#endif
