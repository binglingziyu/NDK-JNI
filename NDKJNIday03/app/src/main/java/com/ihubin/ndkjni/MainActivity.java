package com.ihubin.ndkjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import org.json.JSONObject;

public class MainActivity extends AppCompatActivity {

   private TextView getNativeArrayText;
   private TextView formatArrayText;
   private TextView calcScorePassText;
   private TextView calcTotalMoneyText;
   private TextView nativeJavaObjectText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        getNativeArrayText = findViewById(R.id.get_native_array_text);
        formatArrayText = findViewById(R.id.format_array_text);
        calcScorePassText = findViewById(R.id.calc_score_pass_text);
        calcTotalMoneyText = findViewById(R.id.calc_total_money_text);
        nativeJavaObjectText = findViewById(R.id.native_java_object_text);
    }

    /**
     * 从 Native 获取数组，Java 进行格式化
     * @param view
     */
    public void getNativeArray(View view) {
        boolean[] nativeArray = NativeUtil.getNativeArray();
        StringBuilder stringBuilder = new StringBuilder("[");
        for(int i = 0; i < nativeArray.length; i++) {
            stringBuilder.append(nativeArray[i]);
            if(i != nativeArray.length -1) {
                stringBuilder.append(", ");
            }
        }
        stringBuilder.append("]");
        getNativeArrayText.setText(stringBuilder.toString());
    }

    /**
     * 将 Java 数组传入 Native，Native 格式化
     * @param view
     */
    public void formatArray(View view) {
        int[] intArray = {11, 22, 33, 44, 55};
        String formatArrayStr = NativeUtil.formatArray(intArray);
        formatArrayText.setText(formatArrayStr);
    }

    /**
     * 计算各科成绩是否通过
     * @param view
     */
    public void calcScorePass(View view) {
        float[] yourScore = {59.0F, 88.0F, 76.5F, 45.0F, 98.0F};
        String[] yourScoreResult = NativeUtil.calcScorePass(yourScore);
        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder.append("[");
        for(int i = 0; i < yourScore.length; i++) {
            stringBuilder.append(yourScore[i]);
            if(i != yourScore.length - 1) {
                stringBuilder.append(", ");
            }
        }
        stringBuilder.append("]");

        stringBuilder.append("\n");

        stringBuilder.append("[");
        for(int i = 0; i < yourScoreResult.length; i++) {
            stringBuilder.append(yourScoreResult[i]);
            if(i != yourScoreResult.length - 1) {
                stringBuilder.append(", ");
            }
        }
        stringBuilder.append("]");

        calcScorePassText.setText(stringBuilder.toString());
    }

    /**
     * Native 计算商品总价
     * @param view
     */
    public void calcTotalMoney(View view) {
        double[] price = {5.5, 6.6, 7.7, 8.8, 9.9};
        String resultStr = NativeUtil.calcTotalMoney(price);
        calcTotalMoneyText.setText(resultStr);
    }


    public void javaClassTest(View view) {
        User userFromNative = NativeUtil.javaClassTest();
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("{\n");
        stringBuilder.append(String.format("\t\"name\": \"%s\",\n", userFromNative.getName()));
        stringBuilder.append(String.format("\t\"age\": %d\n", userFromNative.getAge()));
        stringBuilder.append("}");
        nativeJavaObjectText.setText(stringBuilder.toString());
    }
}
