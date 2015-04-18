#pragma once

#ifndef __X_FILE_MANAGER__
#define __X_FILE_MANAGER__

#include <x_foundation/XURI.h>
#include <x_foundation/XPool.h>
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

    void JoinPath2(const XString& head, const XString& tail, std::string& outResult);

public:
    std::shared_ptr<XBinary>    LoadBinary(const XString& fileAbsPath);
    std::shared_ptr<XText>      LoadText(const XString& fileAbsPath);

public:
    virtual bool TryGetResourceAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath) 
    { return false; }

    virtual XBinary* TryGetResourceBinary(const XString& dirRelPath, const XString& fileName) 
    { return NULL; }

protected:
    std::string m_programAbsPath;

private:
    char m_sep;
};

} // end_of_namespace:xf

#endif
