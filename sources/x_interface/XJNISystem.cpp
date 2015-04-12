#include <x_interface/XJNIMacros.h>
#include <x_foundation/XLogMacros.h>
#include <x_foundation/android/XSystem.h>

#include <jni.h>

using namespace xf;

extern "C" {
    JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz);
};

JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz)
{
    x_debugn("test");
    const char* abiName = android::XSystem::GetABIName();
    return (env)->NewStringUTF(abiName);
}
