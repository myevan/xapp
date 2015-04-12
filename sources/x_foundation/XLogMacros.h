#pragma once

#ifndef __X_LOG_MACROS__
#define __X_LOG_MACROS__

#include <x_foundation/XLoggerManager.h>

#define x_debugn(text) XLoggerManager::GetDefaultLogger().Printn(X_LOG_DEBUG, __FILE__, __LINE__, __FUNCTION__, text)

#endif
