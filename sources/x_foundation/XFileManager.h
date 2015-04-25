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
    virtual void SetExecFilePath(const XPath& execFilePath) = 0;
    virtual void SetDataDirPath(const XPath& dataDirPath) = 0;

public:
    const XPath& GetExecFileName()
    { return m_execFileName; }

public:
    virtual std::shared_ptr<XStream> OpenStream(const XString& uri) = 0;

public:
    std::shared_ptr<XBinary>    LoadBinary(const XString& uri);
    std::shared_ptr<XText>      LoadText(const XString& uri);

protected:
    bool TryParseURI(const XString& uri, XString& outScheme, XString& outBody);

protected:
    XPath m_execFileName;
    XPath m_execFileAbsPath;
    XPath m_execDirAbsPath;
    XPath m_dataDirAbsPath;

};

} // end_of_namespace:xf

#endif
