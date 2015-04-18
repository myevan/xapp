#pragma once

#ifndef __POSIX_X_LOGGER__
#define __POSIX_X_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf { namespace posix {

class XLogger : public ILogger
{
public:
    virtual ~XLogger() {}

    void Print(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName);
};

} } // end_of_namespace:xf.posix

#endif
