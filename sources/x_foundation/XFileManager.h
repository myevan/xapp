#pragma once

#ifndef __X_FILE_MANAGER__
#define __X_FILE_MANAGER__

#include <x_foundation/XText.h>
#include <x_foundation/XString.h>
#include <x_foundation/XFileStream.h>

#include <string>
#include <memory>

namespace xf { 

class XFileManager
{
public:
    XFileManager() 
    : m_sep('/')
    {}

    virtual ~XFileManager() 
    {}

public:
    virtual void SetProgramArguments(int argCount, const char** args);

    const std::string& GetProgramPath();

public:
    bool TryParseURI(const XString& uri, XString& outScheme, XString& outBody);
    bool TrySplitPath(const XString& path, XString& outBranch, XString& outLeaf);
    void SplitPath(const XString& path, XString& outBranch, XString& outLeaf);

    void JoinPath2(const XString& head, const XString& tail, std::string& outResult);

public:
    virtual std::shared_ptr<XFileStream> OpenStream(const XString& uri);

public:
    std::shared_ptr<XBinary>    LoadBinary(const XString& uri);
    std::shared_ptr<XText>      LoadText(const XString& uri);

protected:
    std::string m_programAbsPath;

private:
    char m_sep;
};

} // end_of_namespace:xf

#endif
