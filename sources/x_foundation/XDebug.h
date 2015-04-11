#pragma once

#ifndef __X_DEBUG__
#define __X_DEBUG__

#include <x_foundation/XLogger.h>

#define x_debug(text) XLogger::Instance().Printn(text)

#endif
