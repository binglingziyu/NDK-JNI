#include <jni.h>
#include <string>
#include <android/log.h>
#include <math.h>

#define LOG_TAG  "C_TAG"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

//LOGD("hello.length=%d",helloLen);

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaBooleanToNative(JNIEnv *env, jclass clazz, jboolean value) {
    LOGD("Java Boolean: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaByteToNative(JNIEnv *env, jclass clazz, jbyte value) {
    LOGD("Java Byte: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaCharToNative(JNIEnv *env, jclass clazz, jchar value) {
    LOGD("Java Char: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaShortToNative(JNIEnv *env, jclass clazz, jshort value) {
    LOGD("Java Short: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaIntToNative(JNIEnv *env, jclass clazz, jint value) {
    LOGD("Java Int: %d", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaLongToNative(JNIEnv *env, jclass clazz, jlong value) {
    LOGD("Java Long: %lld", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaFloatToNative(JNIEnv *env, jclass clazz, jfloat value) {
    LOGD("Java Float: %f", value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaDoubleToNative(JNIEnv *env, jclass clazz, jdouble value) {
    LOGD("Java Double: %lf", value);
}


extern "C"
JNIEXPORT jboolean JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaBooleanFromNative(JNIEnv *env, jclass clazz) {
    return JNI_TRUE;
}

extern "C"
JNIEXPORT jbyte JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaByteFromNative(JNIEnv *env, jclass clazz) {
    return 123;
}

extern "C"
JNIEXPORT jchar JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaCharFromNative(JNIEnv *env, jclass clazz) {
    return 'A';
}

extern "C"
JNIEXPORT jshort JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaShortFromNative(JNIEnv *env, jclass clazz) {
    return 999;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaIntFromNative(JNIEnv *env, jclass clazz) {
    return 999999;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaLongFromNative(JNIEnv *env, jclass clazz) {
    return 999999999;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaFloatFromNative(JNIEnv *env, jclass clazz) {
    return 999999.8;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaDoubleFromNative(JNIEnv *env, jclass clazz) {
    return 999999999.8;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_charConcatTest(JNIEnv *env, jclass clazz, jchar a, jchar b,
                                                 jchar c) {
    char charArray[4];
    charArray[0] = a;
    charArray[1] = b;
    charArray[2] = c;
    charArray[3] = '\0';
    return env->NewStringUTF(charArray);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ihubin_ndkjni_NativeUtil_sumText(JNIEnv *env, jclass clazz, jint i, jint j) {
    return i + j;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ihubin_ndkjni_NativeUtil_twoExpTest(JNIEnv *env, jclass clazz, jint exp) {
    return pow(2, exp);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_calcMoneyTest(JNIEnv *env, jclass clazz, jdouble v, jdouble v1,
                                                jdouble v2) {
    double totalMoney = v + v1 + v2;
    char *resultStr = new char();
    sprintf(resultStr, "总计：%f", totalMoney);
    return env->NewStringUTF(resultStr);
}