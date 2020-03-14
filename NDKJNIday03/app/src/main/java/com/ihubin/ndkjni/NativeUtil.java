package com.ihubin.ndkjni;

public class NativeUtil {

    static {
        System.loadLibrary("native-lib");
    }

    public native static boolean[] getNativeArray();

    public native static String formatArray(int[] intArray);

    public native static String[] calcScorePass(float[] yourScore);

    public native static String calcTotalMoney(double[] price);

    public native static User javaClassTest();
}
