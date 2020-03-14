#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG  "C_TAG"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
//LOGD("hello.length=%d",helloLen);

extern "C"
JNIEXPORT jbooleanArray JNICALL
Java_com_ihubin_ndkjni_NativeUtil_getNativeArray(JNIEnv *env, jclass clazz) {
    jboolean* jb = new jboolean[5];
    jb[0] = JNI_TRUE;
    jb[1] = JNI_FALSE;
    jb[2] = JNI_TRUE;
    jb[3] = JNI_FALSE;
    jb[4] = JNI_TRUE;

    jbooleanArray jba = env->NewBooleanArray(5);
    env->SetBooleanArrayRegion(jba, 0, 5, jb);

    return jba;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_formatArray(JNIEnv *env, jclass clazz, jintArray int_array) {
    jint array[5];
    env->GetIntArrayRegion(int_array, 0, 5, array);
    jsize size = env->GetArrayLength(int_array);
    char resutStr[100] = {0};
    char str[10] = {0};
    strcat(resutStr, "[");
    for(int i = 0; i < size; i++) {
        sprintf(str, "%d", array[i]);
        strcat(resutStr, str);
        if(i != size - 1) {
            strcat(resutStr, ", ");
        }
    }
    strcat(resutStr, "]");
    return env->NewStringUTF(resutStr);
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_ihubin_ndkjni_NativeUtil_calcScorePass(JNIEnv *env, jclass clazz, jfloatArray your_score) {
    jfloat array[5];
    env->GetFloatArrayRegion(your_score, 0, 5, array);
    jsize size = env->GetArrayLength(your_score);

    jclass objClass = env->FindClass("java/lang/String");
    jobjectArray objArray = env->NewObjectArray(5, objClass, 0);
    jstring  jstr;
    for(int i = 0; i < size; i++) {
        if(array[i] >= 60.0) {
            jstr = env->NewStringUTF("√");
        } else {
            jstr = env->NewStringUTF("×");
        }
        env->SetObjectArrayElement(objArray, i, jstr);
    }

    return objArray;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_calcTotalMoney(JNIEnv *env, jclass clazz, jdoubleArray price) {
    jdouble array[5];
    env->GetDoubleArrayRegion(price, 0, 5, array);
    jsize size = env->GetArrayLength(price);

    char resutStr[255] = {0};
    char str[20] = {0};
    strcat(resutStr, "sum(");
    jdouble totalMoney = 0.0;
    for(int i = 0; i < size; i++) {
        sprintf(str, "%.1f", array[i]);
        strcat(resutStr, str);
        if(i != size - 1) {
            strcat(resutStr, ", ");
        }
        totalMoney += array[i];
    }
    strcat(resutStr, ")");
    strcat(resutStr, "\n=");
    sprintf(str, "%.1f", totalMoney);
    strcat(resutStr, str);
    return env->NewStringUTF(resutStr);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_ihubin_ndkjni_NativeUtil_javaClassTest(JNIEnv *env, jclass clazz) {

    jclass userClass = env->FindClass("com/ihubin/ndkjni/User");

    jfieldID normalField = env->GetFieldID(userClass, "normalField", "I");
    jfieldID staticField = env->GetStaticFieldID(userClass, "staticField", "I");

    jmethodID normalMethod = env->GetMethodID(userClass, "getNormalUserInfo", "()Ljava/lang/String;");
    jmethodID staticMethod = env->GetStaticMethodID(userClass, "getStaticUserInfo", "()Ljava/lang/String;");

    jmethodID voidInitMethod = env->GetMethodID(userClass, "<init>", "()V");
    jmethodID paramInitMethod = env->GetMethodID(userClass, "<init>", "(Ljava/lang/String;I)V");

    jmethodID getFormatInfoMethod = env->GetMethodID(userClass, "getFormatInfo", "()Ljava/lang/String;");


    jobject userOne = env->NewObject(userClass, voidInitMethod);

    jstring name = env->NewStringUTF("HUBIN");
    jint age = 8;
    jobject userTwo = env->NewObject(userClass, paramInitMethod, name, age);

    jobject userThree = env->AllocObject(userClass);


    jint normalFieldValue = env->GetIntField(userOne, normalField);
    LOGD("normalField: %d", normalFieldValue);

    jint staticFieldValue = env->GetStaticIntField(userClass, staticField);
    LOGD("staticField: %d", staticFieldValue);

    jobject normalMethodResultObj = env->CallObjectMethod(userOne, normalMethod);
    jstring normalMethodResult = static_cast<jstring>(normalMethodResultObj);
    const char *normalMethodResultNativeString = env->GetStringUTFChars(normalMethodResult, 0);
    LOGD("normalMethodResult: %s", normalMethodResultNativeString);

    jobject staticMethodResultObj = env->CallStaticObjectMethod(userClass, staticMethod);
    jstring staticMethodResult = static_cast<jstring>(staticMethodResultObj);
    const char *staticMethodResultNativeString = env->GetStringUTFChars(staticMethodResult, 0);
    LOGD("staticMethodResult: %s", staticMethodResultNativeString);

    jobject getFormatInfoMethodResultObj = env->CallObjectMethod(userTwo, getFormatInfoMethod);
    jstring getFormatInfoMethodResult = static_cast<jstring>(getFormatInfoMethodResultObj);
    const char *getFormatInfoMethodResultNativeString = env->GetStringUTFChars(getFormatInfoMethodResult, 0);
    LOGD("getFormatInfoMethodResult: %s", getFormatInfoMethodResultNativeString);

    jobject userThreeMethodResultObj = env->CallObjectMethod(userThree, normalMethod);
    jstring userThreeMethodResult = static_cast<jstring>(userThreeMethodResultObj);
    const char *userThreeMethodResultNativeString = env->GetStringUTFChars(userThreeMethodResult, 0);
    LOGD("userThreeMethodResult: %s", userThreeMethodResultNativeString);


    jstring ygName = env->NewStringUTF("老妖怪");
    jint ygAge = 999;
    jobject userYG = env->NewObject(userClass, paramInitMethod, ygName, ygAge);
    return userYG;

}