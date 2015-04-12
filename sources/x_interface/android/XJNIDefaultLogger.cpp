#include <x_interface/android/XJNIMacros.h>

#include <x_foundation/XLoggerManager.h>

using namespace xf;

extern "C" {
    JNIEXPORT void JNICALL X_JNI_FUNCTION(XDefaultLogger, Debugn)(JNIEnv* env, jobject thiz, jstring jText, jstring jFilePath, jint jFileLineNum, jstring jFuncName);
};

JNIEXPORT void JNICALL X_JNI_FUNCTION(XDefaultLogger, Debugn)(JNIEnv* env, jobject thiz, jstring jText, jstring jFilePath, jint jFileLineNum, jstring jFuncName)
{
    const char* cTextPtr = env->GetStringUTFChars(jText, NULL);
    const char* cFilePathPtr = env->GetStringUTFChars(jFilePath, NULL);
    const char* cFuncNamePtr = env->GetStringUTFChars(jFuncName, NULL);
    XLoggerManager::GetDefaultLogger().Printn(X_LOG_DEBUG, cTextPtr, cFilePathPtr, jFileLineNum, cFuncNamePtr);
    env->ReleaseStringUTFChars(jText, cFuncNamePtr);
    env->ReleaseStringUTFChars(jText, cFilePathPtr);
    env->ReleaseStringUTFChars(jText, cTextPtr);
}
