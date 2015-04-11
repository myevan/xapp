#include <x_foundation/XNSLogger.h>
#include <x_foundation/XPath.h>

#import "Foundation/Foundation.h"

namespace xf {

void XNSLogger::Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text)
{
    XString fileName = XPath::GetPathLeaf(filePath);

    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    const char* textPtr = text.GetPtr();
    NSLog(@"(%s:%d) %s:%s", fileNamePtr, fileLineNum, funcNamePtr, textPtr);
}

} // end_of_namespace:xf
