#include "StdAfx.h"

#include "XFileManager.h"

#include "../XPool.h"
#include "../XFileStream.h"
#include "../XDebugMacros.h"

using namespace xf;

namespace xf { namespace posix {

XFileManager::XFileManager()
{
}

void XFileManager::SetProgramPath(const XString& programPath) 
{
    char programAbsPathChars[PATH_MAX];
    x_verify(realpath(programPath.GetChars(), programAbsPathChars), "CHECK_PROGRAM_REL_PATH");

    xf::XFileManager::SetProgramPath(programAbsPathChars);
}

std::shared_ptr<XStream> XFileManager::OpenStream(const XString& uri)
{
    XString uriBody;
    XString uriScheme;
    if (TryParseURI(uri, uriScheme, uriBody))
    {
        if (uriScheme.Equals("app"))
        {
            return OpenFileStream(m_appDirAbsPath, uriBody);
        }
    }
    return std::shared_ptr<XStream>();
}

std::shared_ptr<XStream> XFileManager::OpenFileStream(const XPath& branchAbsPath, const XString& leaf)
{
    XPath fileAbsPath(branchAbsPath);
    if (!fileAbsPath.TryAppendXStr(leaf))
        return std::shared_ptr<XFileStream>();

    x_debug(fileAbsPath.GetChars());
    std::shared_ptr<XFileStream> streamp = XPool<XFileStream>::NewObject();
    XFileStream& stream = *streamp;
    if (!stream.Open(fileAbsPath))
        return std::shared_ptr<XFileStream>();

    return streamp;
}

} } // end_of_namespace:xf.ns
