#include <x_foundation/XNSLogger.h>
#include <x_foundation/XPath.h>
//#include <x_foundation/XStringSizer.h>
//#include <x_foundation/XStringBuilder.h>

#import "Foundation/Foundation.h"

namespace xf {

void XNSLogger::Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text)
{
    XString fileName = XPath::GetPathLeaf(filePath);
    const char* fileNamePtr = fileName.GetTextPtr();
    const char* funcNamePtr = funcName.GetTextPtr();
    const char* textPtr = text.GetTextPtr();
/*
    XStringSizer strSizer(bufPtr, bufMaxLen);
    strSizer.AppendChar('(');
    strSizer.AppendXString(fileName);
    strSizer.AppendChar(':');
    strSizer.AppendIntf(16, "%d", fileLineNum);
    strSizer.AppendChar(')');
    strSizer.AppendChar(' ');
    strSizer.AppendXStr(funcName);
    strSizer.AppendChar(':');
    strSizer.AppendXStr(text);

    size_t bufMaxLen = strSizer.GetLen();
    char* bufPtr = alloca(bufMaxLen);
    XStringBuilder strBuilder(bufPtr, bufMaxLen);
    strBuilder.AppendChar('(');
    strBuilder.AppendXString(fileName);
    strBuilder.AppendChar(':');
    strBuilder.AppendIntf(16, "%d", fileLineNum);
    strBuilder.AppendChar(')');
    strBuilder.AppendChar(' ');
    strBuilder.AppendXStr(funcName);
    strBuilder.AppendChar(':');
    strBuilder.AppendXStr(text);
    NSLog(@"%s", bufPtr);
*/
    NSLog(@"(%s:%d) %s:%s", fileNamePtr, fileLineNum, funcNamePtr, textPtr);
}

} // end_of_namespace:xf
