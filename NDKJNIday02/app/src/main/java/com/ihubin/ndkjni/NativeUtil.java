package com.ihubin.ndkjni;

public class NativeUtil {

    static {
        System.loadLibrary("native-lib");
    }

    public native static void javaBooleanToNative(boolean value);

    public native static void javaByteToNative(byte value);

    public native static void javaCharToNative(char value);

    public native static void javaShortToNative(short value);

    public native static void javaIntToNative(int value);

    public native static void javaLongToNative(long value);

    public native static void javaFloatToNative(float value);

    public native static void javaDoubleToNative(double value);

    public native static boolean javaBooleanFromNative();

    public native static byte javaByteFromNative();

    public native static char javaCharFromNative();

    public native static short javaShortFromNative();

    public native static int javaIntFromNative();

    public native static long javaLongFromNative();

    public native static float javaFloatFromNative();

    public native static double javaDoubleFromNative();


    public native static String charConcatTest(char a, char b, char c);

    public native static int sumText(int i, int j);

    public native static int twoExpTest(int exp);

    public native static String calcMoneyTest(double v, double v1, double v2);
}
