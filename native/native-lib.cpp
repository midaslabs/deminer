#include <jni.h>
#include <string>
#include "xmrig/App.h"

extern "C" JNIEXPORT jboolean JNICALL
Java_com_4mlabs_xmrapp_NativeMiner_startMining(JNIEnv* env, jobject, jstring poolUrl, jint threads) {
    const char* poolUrlStr = env->GetStringUTFChars(poolUrl, nullptr);
    App::instance()->start(poolUrlStr, threads);
    env->ReleaseStringUTFChars(poolUrl, poolUrlStr);
    return true;
}

extern "C" JNIEXPORT void JNICALL
Java_com_4mlabs_xmrapp_NativeMiner_stopMining(JNIEnv*, jobject) {
    App::instance()->stop();
}

extern "C" JNIEXPORT jobject JNICALL
Java_com_4mlabs_xmrapp_NativeMiner_getStats(JNIEnv* env, jobject) {
    jclass statsClass = env->FindClass("com/4mlabs/xmrapp/NativeMiner$Stats");
    jmethodID constructor = env->GetMethodID(statsClass, "<init>", "(D)V");
    return env->NewObject(statsClass, constructor, App::instance()->hashrate());
}
