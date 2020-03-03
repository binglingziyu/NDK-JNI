package com.ihubin.ndkjni;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class NativeToJavaActivity extends AppCompatActivity {

    private TextView booleanText;
    private TextView byteText;
    private TextView charText;
    private TextView shortText;
    private TextView intText;
    private TextView longText;
    private TextView floatText;
    private TextView doubleText;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_native_to_java);
        setTitle("Native -> Java");

        booleanText = findViewById(R.id.boolean_text);
        byteText = findViewById(R.id.byte_text);
        charText = findViewById(R.id.char_text);
        shortText = findViewById(R.id.short_text);
        intText = findViewById(R.id.int_text);
        longText = findViewById(R.id.long_text);
        floatText = findViewById(R.id.float_text);
        doubleText = findViewById(R.id.double_text);
    }

    public void booleanTest(View view) {
        boolean value = NativeUtil.javaBooleanFromNative();
        booleanText.setText("value = " + value);
    }

    public void byteTest(View view) {
        byte value = NativeUtil.javaByteFromNative();
        byteText.setText("value = " + value);
    }

    public void charTest(View view) {
        char value = NativeUtil.javaCharFromNative();
        charText.setText("value = " + value);
    }

    public void shortTest(View view) {
        short value = NativeUtil.javaShortFromNative();
        shortText.setText("value = " + value);
    }

    public void intTest(View view) {
        int value = NativeUtil.javaIntFromNative();
        intText.setText("value = " + value);
    }

    public void longTest(View view) {
        long value = NativeUtil.javaLongFromNative();
        longText.setText("value = " + value);
    }

    public void floatTest(View view) {
        float value = NativeUtil.javaFloatFromNative();
        floatText.setText("value = " + value);
    }

    public void doubleTest(View view) {
        double value = NativeUtil.javaDoubleFromNative();
        doubleText.setText("value = " + value);
    }

}
