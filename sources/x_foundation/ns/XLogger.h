#pragma once

#ifndef __NS_X_LOGGER__
#define __NS_X_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf { namespace ns {

class XLogger : public ILogger
{
public:
    virtual ~XLogger() {}

    void Printn(XLogType logType, const XString& text, const XString& filePath, int fileLineNum, const XString& funcName);
};

} } // end_of_namespace:xf.ns

#endif
