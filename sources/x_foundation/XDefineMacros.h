#pragma once

#ifndef __X_DEFINE_MACROS__
#define __X_DEFINE_MACROS__

#define X_JOIN_DEFINE_7(a, b, c, d, e, f, g) a ## b ## c ## d  ## e ## f ## g
#define X_UNDERSCORE_JOIN_DEFINE_4(a, b, c, d) X_JOIN_DEFINE_7(a, _, b, _, c, _, d)

#endif
