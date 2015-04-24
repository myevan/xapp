#include "StdAfx.h"

#include <x_foundation/ns/XLogger.h>

#include <x_foundation/XPath.h>

namespace xf { namespace ns {

void XLogger::Print(XLogType logType, const XString& xText, const XString& xFilePath, int fileLineNum, const XString& xFuncName)
{
    XString xFileName = xFilePath.GetLeaf('/');

    const char* cText = xText;
    const char* cFileName = xFileName;
    const char* cFuncName = xFuncName;
    NSLog(@"%s in (%s:%d) %s", cText, cFileName, fileLineNum, cFuncName);
}

} } // end_of_namespace:xf.ns
