#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/XBaseConfig.h>

using namespace xf;

extern "C" {
    JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XBaseConfig, GetTitle)(JNIEnv* env, jobject thiz);
};

JNIEXPORT jstring JNICALL X_JNI_FUNCTION(XBaseConfig, GetTitle)(JNIEnv* env, jobject thiz)
{
    const XBaseConfig& baseConfig = XBaseConfig::GetBaseConfig();
    const XString& title = baseConfig.GetTitle();
    return (env)->NewStringUTF(title.GetPtr());
}
