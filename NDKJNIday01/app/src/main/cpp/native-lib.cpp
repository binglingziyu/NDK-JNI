#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
//    std::string hello = "Hello from C++";
    std::string hello = "NDK-JNI-day01";
    return env->NewStringUTF(hello.c_str());
}
