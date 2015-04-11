#include <x_foundation/XAndroidMacros.h>
#include <x_foundation/XAndroidSystem.h>
#include <x_foundation/XLogMacros.h>

#include <jni.h>

using namespace xf;

extern "C" {
    JNIEXPORT jstring JNICALL X_ANDROID_FUNCTION(XAndroidSystemGetABIName)(JNIEnv* env, jobject thiz);
};

JNIEXPORT jstring JNICALL X_ANDROID_FUNCTION(XAndroidSystemGetABIName)(JNIEnv* env, jobject thiz)
{
    x_debugn("test");
    const char* abiName = XAndroidSystem::GetABIName();
    return (env)->NewStringUTF(abiName);
}
