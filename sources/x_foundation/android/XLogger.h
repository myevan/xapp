#pragma once

#ifndef __ANDROID_X_LOGGER__
#define __ANDROID_X_LOGGER__

#include <x_foundation/XLogger.h>

namespace xf { namespace android {

class XLogger : public xf::XLogger
{
public:
    void Printn(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName) override;
};

} } // end_of_namespace:xf.android

#endif
