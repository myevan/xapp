#include <x_foundation/posix/XLogger.h>

#include <x_foundation/XPath.h>

#include <stdio.h>

namespace xf {

ILogger& XDefaultLogger::GetDefaultLogger()
{
    static posix::XLogger s_logger;
    return s_logger;
}

} // end_of_namespace:xf

namespace xf { namespace posix {

void XLogger::Printn(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName)
{
    XString fileName = XPath::GetPathLeaf(filePath);

    const char* textPtr = text.GetPtr();
    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    fprintf(stdout, "%s in %s(%d):%s\n", textPtr, fileNamePtr, fileLineNum, funcNamePtr);
}

} } // end_of_namespace:xf.posix
