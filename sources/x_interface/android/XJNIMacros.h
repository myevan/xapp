#pragma once

#ifndef __X_JNI_MACROS__
#define __X_JNI_MACROS__

#include <x_foundation/XDefineMacros.h>

#include <jni.h>

#define X_JNI_FUNCTION(class_name, method_name) X_UNDERSCORE_JOIN_DEFINE_4(Java, JNI_PACKAGE_NAME, class_name, method_name)

#endif
