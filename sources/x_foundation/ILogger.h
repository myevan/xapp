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

    virtual void Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text) = 0;
};

} // end_of_namespace:xf

#endif
