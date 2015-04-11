#pragma once

#ifndef __X_LOG_TYPE__
#define __X_LOG_TYPE__

namespace xf {

enum XLogType
{
    X_LOG_ERROR,
    X_LOG_WARN,
    X_LOG_INFO,
    X_LOG_VERBOSE,
    X_LOG_DEBUG,
    X_LOG_TYPE_COUNT,
};

} // end_of_namespace:xf

#endif
