#include "StdAfx.h"

#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/android/XSystem.h>
#include <x_foundation/android/XAssetBinary.h>

#include <android/asset_manager_jni.h> 

using namespace xf;

extern "C" {
    JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz);
    JNIEXPORT void JNICALL X_JNI_FUNCTION(XSystem, BindAssetManager)(JNIEnv* env, jobject thiz, jobject jAssetManager);
};

JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz)
{
    const char* abiName = android::XSystem::GetABIName();
    return (env)->NewStringUTF(abiName);
}

JNIEXPORT void JNICALL X_JNI_FUNCTION(XSystem, BindAssetManager)(JNIEnv* env, jobject thiz, jobject jAssetManager)
{
    AAssetManager* cAssetManager = AAssetManager_fromJava(env, jAssetManager);
    android::XAssetBinary::BindAssetManager(cAssetManager);
}

