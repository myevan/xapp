#pragma once

#ifndef __X_LOGGER__
#define __X_LOGGER__

namespace xf {

class ILogger;

class XLogger
{
public:
    static ILogger& GetInstance();
};

} // end_of_namespace:xf

#endif
