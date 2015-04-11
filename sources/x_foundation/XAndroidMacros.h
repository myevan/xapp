#pragma once

#ifndef __X_ANDROID_MACROS__
#define __X_ANDROID_MACROS__

#include <x_foundation/XDefineMacros.h>

#define X_ANDROID_FUNCTION(name) X_UNDERSCORE_JOIN_DEFINE_4(Java, JNI_PACKAGE_NAME, JNI_CLASS_NAME, name)

#endif
