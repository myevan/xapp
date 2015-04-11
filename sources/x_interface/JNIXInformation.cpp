#include <x_foundation/XAndroidMacros.h>
#include <x_foundation/XInformation.h>

#include <jni.h>

using namespace xf;

extern "C" {
    JNIEXPORT jstring JNICALL X_ANDROID_FUNCTION(XInformationGetTitle)(JNIEnv* env, jobject thiz);
};

JNIEXPORT jstring JNICALL X_ANDROID_FUNCTION(XInformationGetTitle)(JNIEnv* env, jobject thiz)
{
    const char* title = XInformation::GetTitle();
    return (env)->NewStringUTF(title);
}
