#pragma once

#ifndef __X_LOG_MACROS__
#define __X_LOG_MACROS__

#include <x_foundation/XDefaultLogger.h>

#define x_assert(expr)          assert(expr)
#define x_abort(memo)           {assert(!memo);abort();}

#define x_debugn(text)          XDefaultLogger::GetDefaultLogger().Printn(X_LOG_DEBUG, text, __FILE__, __LINE__, __FUNCTION__)

#define x_verifyn(expr, memo)   {if (!(expr)) {x_abort(!memo);}}

#endif
