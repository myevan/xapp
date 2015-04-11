#include <x_foundation/XAndroidLogger.h>
#include <x_foundation/XPath.h>
#include <x_foundation/XString.h>
#include <x_foundation/XStringSizer.h>
#include <x_foundation/XStringBuilder.h>
#include <x_foundation/XInformation.h>

#include <android/log.h>

namespace xf {

static android_LogPriority X_LOG_TYPE_TO_ANDROID_LOG_PRIORITY[X_LOG_TYPE_COUNT] = 
{
    ANDROID_LOG_ERROR,
    ANDROID_LOG_WARN,
    ANDROID_LOG_INFO,
    ANDROID_LOG_VERBOSE,
    ANDROID_LOG_DEBUG,
};

void XAndroidLogger::Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text)
{
    android_LogPriority androidLogPriority = X_LOG_TYPE_TO_ANDROID_LOG_PRIORITY[logType];

    const XString& tag = XInformation::GetTitle();
    const char* tagPtr = tag.GetPtr();

    XString fileName = XPath::GetPathLeaf(filePath);
    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    const char* textPtr = text.GetPtr();

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

    __android_log_write(androidLogPriority, tagPtr, bufPtr);
}

} // end_of_namespace:xf
