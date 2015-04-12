#include <x_foundation/posix/XLogger.h>

#include <x_foundation/XPath.h>

#include <stdio.h>

namespace xf { namespace posix {

void XLogger::Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text)
{
    XString fileName = XPath::GetPathLeaf(filePath);

    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    const char* textPtr = text.GetPtr();
    fprintf(stdout, "%s in %s(%d):%s\n", textPtr, fileNamePtr, fileLineNum, funcNamePtr);
}

} } // end_of_namespace:xf.posix
