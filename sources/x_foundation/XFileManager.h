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

    virtual void SetProgramArguments(int argCount, const char** args)
    {}

    const std::string& GetProgramPath() 
    { return m_programAbsPath; }

    virtual bool TryGetResourceAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath) 
    { return false; }

    virtual XBinary* TryGetResourceBinary(const XString& dirRelPath, const XString& fileName) 
    { return NULL; }

    void JoinPath2(const XString& head, const XString& tail, std::string& outResult)
    {
        size_t capacity = sizeof(m_sep);
        capacity += head.GetSize();
        capacity += tail.GetSize();
        outResult.reserve(capacity);
        outResult.assign(head.GetChars(), head.GetSize());
        outResult += m_sep;
        outResult.append(tail.GetChars(), tail.GetSize());
    }

    std::shared_ptr<XBinary> LoadFileBinary(const XString& fileAbsPath)
    {
        std::shared_ptr<XFileStream> streamPtr = XPool<XFileStream>::NewObject();
        XFileStream& stream = *streamPtr;
        if (!stream.Open(fileAbsPath))
            return std::shared_ptr<XBinary>();

        size_t size = stream.GetSize();
        std::shared_ptr<XBuffer> bufPtr = XPool<XBuffer>::NewObject(size, size);
        if (!bufPtr)
            return std::shared_ptr<XBinary>();

        XBuffer& buf = *bufPtr;
        byte_t* bufBytes = buf.GetBytes();
        size_t bufSize = buf.GetSize();
        size_t readSize = stream.ReadBytes(bufSize, bufBytes);
        if (bufSize != readSize)
            return std::shared_ptr<XBinary>();

        return bufPtr; 
    }

    std::shared_ptr<XText> LoadFileText(const XString& fileAbsPath)
    {
        std::shared_ptr<XFileStream> streamPtr = XPool<XFileStream>::NewObject();
        XFileStream& stream = *streamPtr;
        if (!stream.Open(fileAbsPath))
            return std::shared_ptr<XText>();

        size_t size = stream.GetSize();
        std::shared_ptr<XText> textPtr = XPool<XText>::NewObject(size, size);
        if (!textPtr)
            return std::shared_ptr<XText>();

        XText& text = *textPtr;
        byte_t* textBytes = text.GetBytes();
        size_t textSize = text.GetSize();
        size_t readSize = stream.ReadBytes(textSize, textBytes);
        if (textSize != readSize)
            return std::shared_ptr<XText>();

        text.MakeEndChar();
        return textPtr; 
    }

protected:
    std::string m_programAbsPath;

private:
    char m_sep;
};

} // end_of_namespace:xf

#endif
