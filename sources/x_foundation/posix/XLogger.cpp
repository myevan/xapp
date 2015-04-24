#include <x_foundation/posix/XLogger.h>

#include <stdio.h>

namespace xf { namespace posix {

void XLogger::Print(XLogType logType, const XString& xText, const XString& xFilePath, int fileLineNum, const XString& xFuncName)
{
    XString xFileName = xFilePath.GetLeaf("/\\");

    const char* cText = xText;
    const char* cFileName = xFileName;
    const char* cFuncName = xFuncName;
    fprintf(stdout, "%s in %s(%d):%s\n", cText, cFileName, fileLineNum, cFuncName);
}

} } // end_of_namespace:xf.posix
