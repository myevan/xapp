#include <x_foundation/XAndroidLogger.h>
#include <x_foundation/XPath.h>
#include <x_foundation/XString.h>
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
    const XString& tag = XInformation::GetTitle();

    XString fileName = XPath::GetPathLeaf(filePath);
    const char* fileNamePtr = fileName.GetPtr();
    const char* funcNamePtr = funcName.GetPtr();
    const char* textPtr = text.GetPtr();
    const char* tagPtr = tag.GetPtr();

    android_LogPriority androidLogPriority = X_LOG_TYPE_TO_ANDROID_LOG_PRIORITY[logType];
    __android_log_write(androidLogPriority, tagPtr, textPtr);
}

} // end_of_namespace:xf
