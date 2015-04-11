#pragma once

#ifndef __X_NS_LOGGER__
#define __X_NS_LOGGER__

#include <x_foundation/ILogger.h>

namespace xf {

class XNSLogger : public ILogger
{
public:
    void Printn(XLogType logType, const XString& filePath, int fileLineNum, const XString& funcName, const XString& text) override;
};

} // end_of_namespace:xf

#endif
