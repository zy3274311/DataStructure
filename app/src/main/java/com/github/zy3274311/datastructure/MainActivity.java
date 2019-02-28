package com.github.zy3274311.datastructure;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.sort_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //加密模块功能测试
                startActivity(new Intent(getApplicationContext(), SortActivity.class));
            }
        });
    }
}
