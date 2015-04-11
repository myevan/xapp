#include <x_foundation/XNSLogger.h>
#include <x_foundation/XPath.h>

#import "Foundation/Foundation.h"

namespace xf {

void XNSLogger::Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text)
{
    XString fileName = XPath::GetPathLeaf(filePath);
    const char* fileNamePtr = fileName.GetTextPtr();
    const char* funcNamePtr = funcName.GetTextPtr();
    const char* textPtr = text.GetTextPtr();
    NSLog(@"(%s:%d) %s:%s" , fileNamePtr, fileLineNum, funcNamePtr, textPtr);
}

} // end_of_namespace:xf
