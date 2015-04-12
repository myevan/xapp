#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/android/XSystem.h>

using namespace xf;

extern "C" {
    JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz);
};

JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XSystem, GetABIName)(JNIEnv* env, jobject thiz)
{
    const char* abiName = android::XSystem::GetABIName();
    return (env)->NewStringUTF(abiName);
}
