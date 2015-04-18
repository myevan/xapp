#pragma once

#ifndef __X_DEBUG_MACROS__
#define __X_DEBUG_MACROS__

#include <x_foundation/XPlatform.h>

#include <assert.h>

#define x_assert(expr)          assert(expr)
#define x_abort(memo)           {assert(!memo);abort();}

#define x_debug(text)           xf::XPlatform::GetLogger().Print(xf::X_LOG_DEBUG, text, __FILE__, __LINE__, __FUNCTION__)

#define x_verify(expr, memo)    {if (!(expr)) {x_abort(!memo);}}

#endif
