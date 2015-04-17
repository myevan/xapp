#pragma once

#ifndef __X_SYSTEM__
#define __X_SYSTEM__

#include <x_foundation/XURI.h>
#include <x_foundation/XPool.h>
#include <x_foundation/XText.h>
#include <x_foundation/XString.h>
#include <x_foundation/XFileStream.h>

#include <string>
#include <memory>

namespace xf { 

class XSystem
{
public:
    static XSystem& GetSystem();

public:
    virtual ~XSystem() {}

public:
    virtual bool TryGetResourceAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath) { return false; }

    virtual XBinary* TryGetResourceBinary(const XString& dirRelPath, const XString& fileName) { return NULL; }


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
};

} // end_of_namespace:xf

#endif
