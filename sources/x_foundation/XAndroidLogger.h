#pragma once

#ifndef __X_ANDROID_LOGGER__
#define __X_ANDROID_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf {

class XAndroidLogger : public ILogger
{
public:
    void Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text) override;
};

} // end_of_namespace:xf

#endif
