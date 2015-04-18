#include "StdAfx.h"

#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/android/XFileManager.h>

#include <android/asset_manager_jni.h> 

using namespace xf;

#if defined(__arm__)
#   if defined(__ARM_ARCH_7A__)
#       if defined(__ARM_NEON__)
#           if defined(__ARM_PCS_VFP)
#               define ABI_NAME "armeabi-v7a/NEON (hard-float)"
#           else
#               define ABI_NAME "armeabi-v7a/NEON"
#           endif
#       else
#           if defined(__ARM_PCS_VFP)
#               define ABI_NAME "armeabi-v7a (hard-float)"
#           else
#               define ABI_NAME "armeabi-v7a"
#           endif
#       endif
#   else
#       define ABI_NAME "armeabi"
#   endif
#elif defined(__i386__)
#   define ABI_NAME "x86"
#elif defined(__x86_64__)
#   define ABI_NAME "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
#   define ABI_NAME "mips64"
#elif defined(__mips__)
#   define ABI_NAME "mips"
#elif defined(__aarch64__)
#   define ABI_NAME "arm64-v8a"
#else
#   define ABI_NAME "unknown"
#endif

extern "C" {
    JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz);
    JNIEXPORT void JNICALL X_JNI_FUNCTION(XSystem, BindAssetManager)(JNIEnv* env, jobject thiz, jobject jAssetManager);
};

JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz)
{
    return (env)->NewStringUTF(ABI_NAME);
}

JNIEXPORT void JNICALL X_JNI_FUNCTION(XSystem, BindAssetManager)(JNIEnv* env, jobject thiz, jobject jAssetManager)
{
    AAssetManager* cAssetManager = AAssetManager_fromJava(env, jAssetManager);
    android::XFileManager::BindAssetManager(cAssetManager);
}

