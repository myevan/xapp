#pragma once

#ifndef __I_LOGGER__
#define __I_LOGGER__

#include <x_foundation/XLogType.h>
#include <x_foundation/XString.h>

namespace xf {

class ILogger
{
public:
    virtual ~ILogger() {}

    virtual void Print(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName) = 0;
};

} // end_of_namespace:xf

#endif
