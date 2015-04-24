#include "StdAfx.h"
#include "XFileManager.h"
#include "XFileStream.h"
#include "XDebugMacros.h"
#include "XPool.h"

namespace xf { 

void XFileManager::SetProgramPath(const XString& programPath)
{
    x_verify(m_appDirAbsPath.TryAssignXStrBranch(programPath), "TOO_LONG_PROGRAM_PATH_BRANCH");

    x_verify(m_appDirAbsPath.TryAppendSep(), "TOO_LONG_APP_DIR_ABS_PATH");
}

bool XFileManager::TryParseURI(const XString& uri, XString& outScheme, XString& outBody)
{
    size_t schemeSepIndex;
    if (!uri.TryGetFirstIndexOf(':', schemeSepIndex))
        return false;

    outScheme = uri.GetSliceLeft(schemeSepIndex);
    outBody = uri.GetSliceRight(schemeSepIndex + 1);
    return true;
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

