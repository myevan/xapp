#pragma once

#ifndef __X_POSIX_LOGGER__
#define __X_POSIX_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf {

class XPosixLogger : public ILogger
{
public:
    virtual ~XPosixLogger() {}

    void Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text);
};

} // end_of_namespace:xf

#endif
