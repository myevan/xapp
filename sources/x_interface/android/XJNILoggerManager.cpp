#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/XLoggerManager.h>

using namespace xf;

extern "C" {
    JNIEXPORT void JNICALL X_JNI_FUNCTION(XLoggerManager, Printn)(JNIEnv* env, jobject thiz, jstring jtext);
};

JNIEXPORT void JNICALL X_JNI_FUNCTION(XLoggerManager, Printn)(JNIEnv* env, jobject thiz, jstring jText)
{
    const char* cTextPtr = env->GetStringUTFChars(jText, NULL);
    XLoggerManager::GetDefaultLogger().Printn(X_LOG_DEBUG, __FILE__, __LINE__, __FUNCTION__, cTextPtr);
    env->ReleaseStringUTFChars(jText, cTextPtr);
}
