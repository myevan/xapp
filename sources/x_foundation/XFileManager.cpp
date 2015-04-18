#include "StdAfx.h"
#include "XFileManager.h"

namespace xf { 

void XFileManager::SetProgramArguments(int argCount, const char** args)
{}

const std::string& XFileManager::GetProgramPath() 
{ return m_programAbsPath; }

void XFileManager::JoinPath2(const XString& head, const XString& tail, std::string& outResult)
{
    size_t capacity = sizeof(m_sep);
    capacity += head.GetSize();
    capacity += tail.GetSize();
    outResult.reserve(capacity);
    outResult.assign(head.GetChars(), head.GetSize());
    outResult += m_sep;
    outResult.append(tail.GetChars(), tail.GetSize());
}

std::shared_ptr<XBinary> XFileManager::LoadBinary(const XString& fileAbsPath)
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

std::shared_ptr<XText> XFileManager::LoadText(const XString& fileAbsPath)
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

    text.WriteEndChar();
    return textPtr; 
}

} // end_of_namespace:xf

