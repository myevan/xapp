#include <x_foundation/android/XSystem.h>

#include <jni.h>

#if defined(__arm__)
#   if defined(__ARM_ARCH_7A__)
#       if defined(__ARM_NEON__)
#           if defined(__ARM_PCS_VFP)
#               define ABI_NAME "armeabi-v7a/NEON (hard-float)";
#           else
#               define ABI_NAME "armeabi-v7a/NEON";
#           endif
#       else
#           if defined(__ARM_PCS_VFP)
#               define ABI_NAME "armeabi-v7a (hard-float)";
#           else
#               define ABI_NAME "armeabi-v7a";
#           endif
#       endif
#   else
#       define ABI_NAME "armeabi";
#   endif
#elif defined(__i386__)
#   define ABI_NAME "x86";
#elif defined(__x86_64__)
#   define ABI_NAME "x86_64";
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
#   define ABI_NAME "mips64";
#elif defined(__mips__)
#   define ABI_NAME "mips";
#elif defined(__aarch64__)
#   define ABI_NAME "arm64-v8a";
#else
#   define ABI_NAME "unknown";
#endif

namespace xf { namespace android {

const char* XSystem::GetABIName()
{
    return ABI_NAME
}

} } // end_of_namespace:xf.android
