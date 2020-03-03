package com.ihubin.ndkjni;

import android.os.Bundle;
import android.view.View;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class JavaToNativeActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_java_to_native);
        setTitle("Java -> Native");
    }

    public void booleanTest(View view) {
        NativeUtil.javaBooleanToNative(true);
        NativeUtil.javaBooleanToNative(false);
    }

    public void byteTest(View view) {
        NativeUtil.javaByteToNative(Byte.MIN_VALUE);
        NativeUtil.javaByteToNative(Byte.MAX_VALUE);
        NativeUtil.javaByteToNative(Byte.parseByte("123"));
    }


    public void charTest(View view) {
        NativeUtil.javaCharToNative(Character.MIN_VALUE);
        NativeUtil.javaCharToNative(Character.MAX_VALUE);
        NativeUtil.javaCharToNative('A');
        NativeUtil.javaCharToNative('B');
        NativeUtil.javaCharToNative('C');
    }

    public void shortTest(View view) {
        NativeUtil.javaShortToNative(Short.MIN_VALUE);
        NativeUtil.javaShortToNative(Short.MAX_VALUE);
        NativeUtil.javaShortToNative(Short.parseShort("999"));
    }

    public void intTest(View view) {
        NativeUtil.javaIntToNative(Integer.MIN_VALUE);
        NativeUtil.javaIntToNative(Integer.MAX_VALUE);
        NativeUtil.javaIntToNative(Integer.parseInt("999999"));
    }

    public void longTest(View view) {
        NativeUtil.javaLongToNative(Long.MIN_VALUE);
        NativeUtil.javaLongToNative(Long.MAX_VALUE);
        NativeUtil.javaLongToNative(Long.parseLong("999999999"));
    }

    public void floatTest(View view) {
        NativeUtil.javaFloatToNative(Float.MIN_VALUE);
        NativeUtil.javaFloatToNative(Float.MAX_VALUE);
        NativeUtil.javaFloatToNative(999999.8F);
    }

    public void doubleTest(View view) {
        NativeUtil.javaDoubleToNative(Double.MIN_NORMAL);
        NativeUtil.javaDoubleToNative(Double.MAX_VALUE);
        NativeUtil.javaDoubleToNative(999999999.8);
    }


}
