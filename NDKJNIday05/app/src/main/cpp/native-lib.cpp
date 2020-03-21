#include <jni.h>
#include <string>
#include <android/log.h>
#include <iostream>
#include "md5.h"
#include "sha1.h"
#include "sha256.h"

#define LOG_TAG  "C_TAG"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
//LOGD("hello.length=%d",helloLen);

// 真实 APK 的签名
#define APK_SIGN_MD5 "DB:D8:77:7D:09:39:03:8C:72:A8:FF:3D:00:2B:A4:FF"

// 使用到的 HASH 算法代码
// https://github.com/stbrumme/hash-library

// HASH 算法枚举
enum HASH {
    HASH_MD5, HASH_SHA1, HASH_SHA256
};

jbyteArray getSignatureByte(JNIEnv *env, jobject context);
void hashByteArray(HASH type, const void* data, size_t numBytes, char* resultData);
void formatSignature(char* data, char* resultData);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_getSignature(JNIEnv *env, jclass clazz, jobject context) {
    jbyteArray cert_byteArray = getSignatureByte(env, context);
    jsize size = env->GetArrayLength(cert_byteArray);
    jbyte* jbyteArray = new jbyte[size];
    env->GetByteArrayRegion(cert_byteArray, 0, size, jbyteArray);

    char certMD5[128] = {0};
    hashByteArray(HASH_MD5, jbyteArray, size, certMD5);
    char certSHA1[128] = {0};
    hashByteArray(HASH_SHA1, jbyteArray, size, certSHA1);
    char certSHA256[128] = {0};
    hashByteArray(HASH_SHA256, jbyteArray, size, certSHA256);
    LOGD("MD5: %s", certMD5);
    LOGD("SHA1: %s", certSHA1);
    LOGD("SHA256: %s", certSHA256);

    char resultStr[1000] = {0};
    strcat(resultStr, "MD5: ");
    strcat(resultStr, certMD5);
    strcat(resultStr, "\n\nSHA1: ");
    strcat(resultStr, certSHA1);
    strcat(resultStr, "\n\nSHA256: ");
    strcat(resultStr, certSHA256);

    return env->NewStringUTF(resultStr);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ihubin_ndkjni_NativeUtil_checkSignature(JNIEnv *env, jclass clazz, jobject context) {
    jbyteArray cert_byteArray = getSignatureByte(env, context);
    jsize size = env->GetArrayLength(cert_byteArray);
    jbyte* jbyteArray = new jbyte[size];
    env->GetByteArrayRegion(cert_byteArray, 0, size, jbyteArray);

    char certMD5[128] = {0};
    hashByteArray(HASH_MD5, jbyteArray, size, certMD5);

    // strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
    int cmpResult = strcmp(certMD5, APK_SIGN_MD5);

    char resultStr[1000] = {0};
    strcat(resultStr, "真实签名：");
    strcat(resultStr, APK_SIGN_MD5);
    strcat(resultStr, "\n\n获取到的签名：");
    strcat(resultStr, certMD5);
    strcat(resultStr, "\n\n检查结果：");
    if(cmpResult == 0) {
        strcat(resultStr, "正常（√）");
    } else {
        strcat(resultStr, "异常（×）");
    }
    return env->NewStringUTF(resultStr);
}

// Native 从 Context 中获取签名
jbyteArray getSignatureByte(JNIEnv *env, jobject context) {
    // Context 的类
    jclass context_clazz = env->GetObjectClass(context);

    // 得到 getPackageManager 方法的 ID
    jmethodID methodID_getPackageManager = env->GetMethodID(context_clazz, "getPackageManager", "()Landroid/content/pm/PackageManager;");

    // 获得 PackageManager 对象
    jobject packageManager = env->CallObjectMethod(context, methodID_getPackageManager);

    // 获得 PackageManager 类
    jclass packageManager_clazz=env->GetObjectClass(packageManager);

    // 得到 getPackageInfo 方法的 ID
    jmethodID methodID_getPackageInfo=env->GetMethodID(packageManager_clazz,"getPackageInfo", "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");

    // 得到 getPackageName 方法的 ID
    jmethodID methodID_getPackageName = env->GetMethodID(context_clazz,"getPackageName", "()Ljava/lang/String;");

    // 获得当前应用的包名
    jobject application_package_obj = env->CallObjectMethod(context, methodID_getPackageName);
    jstring application_package = static_cast<jstring>(application_package_obj);
    const char* package_name = env->GetStringUTFChars(application_package, 0);
    LOGD("packageName: %s", package_name);

    // 获得 PackageInfo
    jobject packageInfo = env->CallObjectMethod(packageManager, methodID_getPackageInfo, application_package, 64);
    jclass packageinfo_clazz = env->GetObjectClass(packageInfo);

    // 获取签名
    jfieldID fieldID_signatures = env->GetFieldID(packageinfo_clazz, "signatures", "[Landroid/content/pm/Signature;");
    jobjectArray signature_arr = (jobjectArray)env->GetObjectField(packageInfo, fieldID_signatures);

    // Signature 数组中取出第一个元素
    jobject signature = env->GetObjectArrayElement(signature_arr, 0);

    // 读 signature 的 ByteArray
    jclass signature_clazz = env->GetObjectClass(signature);
    jmethodID methodID_byteArray = env->GetMethodID(signature_clazz, "toByteArray", "()[B");
    jobject cert_obj = env->CallObjectMethod(signature, methodID_byteArray);
    jbyteArray cert_byteArray = static_cast<jbyteArray>(cert_obj);

    return cert_byteArray;
}

// 获得签名的 MD5 SHA1 SHA256
void hashByteArray(HASH type, const void* data, size_t numBytes, char* resultData){
    if(type == HASH_MD5) {
        MD5 md5;
        std::string md5String = md5(data, numBytes);
        char * tabStr = new char [md5String.length()+1];
        strcpy(tabStr, md5String.c_str());
        formatSignature(tabStr, resultData);
    } else if(type == HASH_SHA1) {
        SHA1 sha1;
        std::string sha1String = sha1(data, numBytes);
        char * tabStr = new char [sha1String.length()+1];
        strcpy(tabStr, sha1String.c_str());
        formatSignature(tabStr, resultData);
    } else if(type == HASH_SHA256) {
        SHA256 sha256;
        std::string sha256String = sha256(data, numBytes);
        char * tabStr = new char [sha256String.length()+1];
        strcpy(tabStr, sha256String.c_str());
        formatSignature(tabStr, resultData);
    }
}

// 格式化输出
void formatSignature(char* data, char* resultData) {
    int resultIndex = 0;
    int length = strlen(data);
    for(int i = 0; i < length; i++) {
        resultData[resultIndex] = static_cast<char>(toupper(data[i]));
        if(i % 2 == 1 && i != length -1) {
            resultData[resultIndex+1] = ':';
            resultIndex+=2;
        } else {
            resultIndex++;
        }
    }
}


