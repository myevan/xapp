#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/XLoggerManager.h>

using namespace xf;

extern "C" {
    JNIEXPORT void JNICALL X_JNI_FUNCTION(XDefaultLogger, Debugn)(JNIEnv* env, jobject thiz, jstring jFilePath, jint jFileLineNum, jstring jFuncName, jstring jText);
};

JNIEXPORT void JNICALL X_JNI_FUNCTION(XDefaultLogger, Debugn)(JNIEnv* env, jobject thiz, jstring jFilePath, jint jFileLineNum, jstring jFuncName, jstring jText)
{
    const char* cFilePathPtr = env->GetStringUTFChars(jFilePath, NULL);
    const char* cFuncNamePtr = env->GetStringUTFChars(jFuncName, NULL);
    const char* cTextPtr = env->GetStringUTFChars(jText, NULL);
    XLoggerManager::GetDefaultLogger().Printn(X_LOG_DEBUG, cFilePathPtr, jFileLineNum, cFuncNamePtr, cTextPtr);
    env->ReleaseStringUTFChars(jText, cTextPtr);
    env->ReleaseStringUTFChars(jText, cFuncNamePtr);
    env->ReleaseStringUTFChars(jText, cFilePathPtr);
}
