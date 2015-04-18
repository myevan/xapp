#pragma once

#ifndef __NS_X_LOGGER__
#define __NS_X_LOGGER__

#include <x_foundation/XLogger.h>

namespace xf { namespace ns {

class XLogger : public xf::XLogger
{
public:
    virtual ~XLogger() {}

    void Print(XLogType logType, const XString& xText, const XString& xFilePath, int fileLineNum, const XString& xFuncName);
};

} } // end_of_namespace:xf.ns

#endif
