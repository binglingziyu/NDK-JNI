package com.ihubin.ndkjni;

public class NativeUtil {

    static {
        System.loadLibrary("native-lib");
    }

    public static native String md5(String plaintext);
    public static native String sha1(String plaintext);
    public static native String sha256(String plaintext);

}
