#include <x_foundation/ns/XLogger.h>

#include <x_foundation/XPath.h>

#import "Foundation/Foundation.h"

namespace xf { namespace ns {

void XLogger::Printn(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName)
{
    XString fileName = XPath::GetPathLeaf(filePath);

    const char* textPtr = text.GetPtr();
    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    NSLog(@"%s in (%s:%d) %s", textPtr, fileNamePtr, fileLineNum, funcNamePtr);
}

} } // end_of_namespace:xf.ns
