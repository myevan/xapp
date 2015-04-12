#include <x_foundation/XPosixLogger.h>
#include <x_foundation/XPath.h>

#include <stdio.h>

namespace xf {

void XPosixLogger::Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text)
{
    XString fileName = XPath::GetPathLeaf(filePath);

    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    const char* textPtr = text.GetPtr();
    fprintf(stdout, "%s(%d):%s:%s\n", fileNamePtr, fileLineNum, funcNamePtr, textPtr);
}

} // end_of_namespace:xf
