#include "StdAfx.h"
#include "XFileManager.h"
#include "XFileStream.h"
#include "XPool.h"

namespace xf { 

void XFileManager::SetProgramArguments(int argCount, const char** args)
{}

const std::string& XFileManager::GetProgramPath() 
{ return m_programAbsPath; }

bool XFileManager::TryParseURI(const XString& uri, XString& outScheme, XString& outBody)
{
    size_t schemeSepIndex;
    if (!uri.TryGetFirstIndexOf(':', schemeSepIndex))
        return false;

    outScheme = uri.GetSliceLeft(schemeSepIndex);
    outBody = uri.GetSliceRight(schemeSepIndex + 1);
    return true;
}

bool XFileManager::TrySplitPath(const XString& path, XString& outBranch, XString& outLeaf)
{
    size_t lastSlashIndex;
    if (!path.TryGetLastIndexOf('/', lastSlashIndex))
        return false;

    outLeaf = path.GetSliceRight(lastSlashIndex + 1);
    outBranch = path.GetSliceLeft(lastSlashIndex);
    return true;
}

void XFileManager::SplitPath(const XString& path, XString& outBranch, XString& outLeaf)
{
    if (!TrySplitPath(path, outBranch, outLeaf))
    {
        outLeaf = path;
        outBranch = XString::EMPTY;
    }
}

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

std::shared_ptr<XStream> XFileManager::OpenStream(const XString& uri)
{
    std::shared_ptr<XFileStream> streamp = XPool<XFileStream>::NewObject();
    XFileStream& stream = *streamp;
    if (!stream.Open(uri))
        return std::shared_ptr<XFileStream>();

    return streamp;
}

std::shared_ptr<XBinary> XFileManager::LoadBinary(const XString& uri)
{
    std::shared_ptr<XStream> streamp = OpenStream(uri);
    if (!streamp)
        return std::shared_ptr<XBinary>();

    XStream& stream = *streamp;
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

std::shared_ptr<XText> XFileManager::LoadText(const XString& uri)
{
    std::shared_ptr<XStream> streamp = OpenStream(uri);
    if (!streamp)
        return std::shared_ptr<XText>();

    XStream& stream = *streamp;
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

