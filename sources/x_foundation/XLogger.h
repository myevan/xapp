#pragma once

#ifndef __X_LOGGER__
#define __X_LOGGER__

#include <x_foundation/XLogType.h>
#include <x_foundation/XString.h>

namespace xf {

class XLogger
{
public:
    virtual ~XLogger() {}

    virtual void Print(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName) = 0;
};

} // end_of_namespace:xf

#endif
