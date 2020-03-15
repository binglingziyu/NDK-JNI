package com.ihubin.ndkjni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView md5Text;
    private TextView sha1Text;
    private TextView sha256Text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        md5Text = findViewById(R.id.md5_text);
        sha1Text = findViewById(R.id.sha1_text);
        sha256Text = findViewById(R.id.sha256_text);
    }

    public void md5(View view) {
        String javaMD5 = HashUtil.md5("Hello,World!");
        String nativeMD5 = NativeUtil.md5("Hello,World!");
        md5Text.setText(String.format("Java 实现: %s\n\nNative 实现：%s", javaMD5, nativeMD5));
    }

    public void sha1(View view) {
        String javaSHA1 = HashUtil.sha1("Hello,World!");
        String nativeSHA1 = NativeUtil.sha1("Hello,World!");
        sha1Text.setText(String.format("Java 实现: %s\n\nNative 实现：%s", javaSHA1, nativeSHA1));
    }

    public void sha256(View view) {
        String javaSHA256 = HashUtil.sha256("Hello,World!");
        String nativeSHA256 = NativeUtil.sha256("Hello,World!");
        sha256Text.setText(String.format("Java 实现: %s\n\nNative 实现：%s", javaSHA256, nativeSHA256));
    }

}
