#pragma once

#ifndef __X_LOG_MACROS__
#define __X_LOG_MACROS__

#include <x_foundation/XDefaultLogger.h>

#define x_debugn(text) XDefaultLogger::GetDefaultLogger().Printn(X_LOG_DEBUG, text, __FILE__, __LINE__, __FUNCTION__)

#endif
