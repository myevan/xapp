#pragma once

#ifndef __X_LOG_MACROS__
#define __X_LOG_MACROS__

#include <x_foundation/XLogType.h>
#include <x_foundation/XLogger.h>

#define x_debugn(text) XLogger::GetInstance().Printn(X_LOG_DEBUG, __FILE__, __LINE__, __FUNCTION__, text)

#endif
