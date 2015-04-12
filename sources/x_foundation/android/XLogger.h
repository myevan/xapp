#pragma once

#ifndef __ANDROID_X_LOGGER__
#define __ANDROID_X_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf { namespace android {

class XLogger : public ILogger
{
public:
    void Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text) override;
};

} } // end_of_namespace:xf.android

#endif
