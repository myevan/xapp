#pragma once

#ifndef __POSIX_X_LOGGER__
#define __POSIX_X_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf { namespace posix {

class XLogger : public ILogger
{
public:
    virtual ~XLogger() {}

    void Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text);
};

} } // end_of_namespace:xf.posix

#endif
