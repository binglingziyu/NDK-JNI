package com.ihubin.ndkjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView javaSignatureText;
    private TextView nativeSignatureText;
    private TextView checkSignatureText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        javaSignatureText = findViewById(R.id.java_signature_text);
        nativeSignatureText = findViewById(R.id.native_signature_text);
        checkSignatureText = findViewById(R.id.check_signature_text);

    }

    public void javaGetSignature(View view) {
        String javaSignature = SignatureUtil.getSignatureStr(getApplicationContext());
        javaSignatureText.setText(javaSignature);
    }

    public void nativeGetSignature(View view) {
        String nativeSignature = NativeUtil.getSignature(getApplicationContext());
        nativeSignatureText.setText(nativeSignature);
    }

    public void checkSignature(View view) {
        String checkResult = NativeUtil.checkSignature(getApplicationContext());
        checkSignatureText.setText(checkResult);
    }

}
