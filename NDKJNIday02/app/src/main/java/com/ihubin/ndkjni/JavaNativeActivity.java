package com.ihubin.ndkjni;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class JavaNativeActivity extends AppCompatActivity {

    private TextView charConcatText;
    private TextView sumText;
    private TextView twoExpText;
    private TextView calcMoneyText;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_java_native);
        setTitle("Java <-> Native");

        charConcatText = findViewById(R.id.char_concat_text);
        sumText = findViewById(R.id.sum_text);
        twoExpText = findViewById(R.id.two_exp_text);
        calcMoneyText = findViewById(R.id.calc_money_text);
    }


    public void charConcatTest(View view) {
        String value = NativeUtil.charConcatTest('A', 'B', 'C');
        charConcatText.setText("A+B+C=" + value);
    }

    public void sumTest(View view) {
        int numOne = 123;
        int numTwo = 456;
        int value = NativeUtil.sumText(numOne, numTwo);
        sumText.setText(numOne + "+" + numTwo + "=" + value);
    }

    public void twoExpTest(View view) {
        int value = NativeUtil.twoExpTest(10);
        twoExpText.setText("2^10=" + value);
    }

    public void calcMoneyTest(View view) {
        double apple = 12.4;
        double banana = 99.8;
        double orange = 101.1;
        String value = NativeUtil.calcMoneyTest(apple, banana, orange);
        calcMoneyText.setText(value);
    }

}
