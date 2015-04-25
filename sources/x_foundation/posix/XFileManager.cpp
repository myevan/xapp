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

void XFileManager::SetExecFilePath(const XPath& execFilePath) 
{
    char execFileAbsPathChars[PATH_MAX];
    x_verify(realpath(execFilePath.GetChars(), execFileAbsPathChars), "CHECK_EXEC_PATH"); // TODO: x_vertifyf
    m_execFileAbsPath.AssignXStr(execFileAbsPathChars);
    m_execFileAbsPath.SplitBranchAndLeaf(m_execDirAbsPath, m_execFileName);
}

void XFileManager::SetDataDirPath(const XPath& dataDirPath) 
{
    if (dataDirPath.IsRelPath())
    {
        size_t relNodeCount;
        XPath leafPath;
        dataDirPath.GetLeafExceptRelNodes(relNodeCount, leafPath);
        m_execDirAbsPath.GetBranchExceptLeafs(relNodeCount, m_dataDirAbsPath);
        m_dataDirAbsPath.AppendPath(leafPath);
    }
    else
    {
        m_dataDirAbsPath.AssignPath(m_execDirAbsPath);
        m_dataDirAbsPath.AppendPath(dataDirPath);
    }
}

std::shared_ptr<XStream> XFileManager::OpenStream(const XString& uri)
{
    XString uriBody;
    XString uriScheme;
    if (TryParseURI(uri, uriScheme, uriBody))
    {
        if (uriScheme.Equals("data"))
        {
            return OpenFileStream(m_dataDirAbsPath, uriBody);
        }
    }
    return std::shared_ptr<XStream>();
}

std::shared_ptr<XStream> XFileManager::OpenFileStream(const XPath& branchAbsPath, const XString& leaf)
{
    XPath fileAbsPath(branchAbsPath);
    fileAbsPath.AppendXStr(leaf);
    x_debug(fileAbsPath.ToXStr());

    x_debug(fileAbsPath.GetChars());
    std::shared_ptr<XFileStream> streamp = XPool<XFileStream>::NewObject();
    XFileStream& stream = *streamp;
    if (!stream.Open(fileAbsPath))
        return std::shared_ptr<XFileStream>();

    return streamp;
}

} } // end_of_namespace:xf.ns
