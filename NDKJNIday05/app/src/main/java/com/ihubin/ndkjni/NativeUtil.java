package com.ihubin.ndkjni;

import android.content.Context;

public class NativeUtil {

    static {
        System.loadLibrary("native-lib");
    }

    public static native String getSignature(Context context);

    public static native String checkSignature(Context context);
}
