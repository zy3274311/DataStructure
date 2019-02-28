package com.github.zy3274311.datastructure;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

import com.github.zy3274311.datastructure.nativelib.SortUtil;

public class SortActivity extends AppCompatActivity {
    private static final String TAG = "SortActivity";

    private EditText array_length_et;
    private TextView gen_array_tv;
    private TextView sort_array_tv;
    private TextView gen_time_tv;
    private TextView sort_time_tv;

    private RadioGroup sort_rbs;

    private int[] array;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sort);
        array_length_et = findViewById(R.id.array_length_et);
        array_length_et.setSelection(array_length_et.getText().length());
        gen_array_tv = findViewById(R.id.gen_array_tv);
        sort_array_tv = findViewById(R.id.sort_array_tv);
        gen_time_tv = findViewById(R.id.gen_time_tv);
        sort_time_tv = findViewById(R.id.sort_time_tv);
        sort_rbs = findViewById(R.id.sort_rbs);
        findViewById(R.id.array_gen_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        long startTime = System.currentTimeMillis();
                        Log.e(TAG, "startTime: "+startTime);
                        array = generateArray();
                        long endTime = System.currentTimeMillis();
                        Log.e(TAG, "endTime: "+endTime);
                        final long dTime = endTime - startTime;
                        Log.e(TAG, "dTime: "+dTime);
                        final String arrayStr = arrayToStr(array);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                gen_array_tv.setText(arrayStr);
                                gen_time_tv.setText(getString(R.string.gen_array_time, dTime));
                            }
                        });
                    }
                }).start();

            }
        });

        findViewById(R.id.start_sort_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        long startTime = System.currentTimeMillis();
                        Log.e(TAG, "startTime: "+startTime);
                        sortArray(array);
                        long endTime = System.currentTimeMillis();
                        Log.e(TAG, "endTime: "+endTime);
                        final long dTime = endTime - startTime;
                        Log.e(TAG, "dTime: "+dTime);
                        final String arrayStr = arrayToStr(array);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                sort_array_tv.setText(arrayStr);
                                sort_time_tv.setText(getString(R.string.sort_time, dTime));
                            }
                        });
                    }
                }).start();

            }
        });

    }

    private int[] generateArray() {
        String numStr = array_length_et.getText().toString();
        int num = Integer.parseInt(numStr);
        int[] array = new int[num];
        for(int i=0;i<num;i++){
            array[i] = (int) (Math.random()*10000);
        }
        return array;
    }

    private void sortArray(int[] array){
        int id = sort_rbs.getCheckedRadioButtonId();
        switch (id){
            case R.id.quick_sort_rb:
                SortUtil.quickSort(array);
                break;
            case R.id.bubble_sort_rb:
                SortUtil.bubbleSort(array);
                break;
            case R.id.select_sort_rb:
                SortUtil.selectSort(array);
                break;
            case R.id.insert_sort_rb:
                SortUtil.insertSort(array);
                break;
            case R.id.merge_sort_rb:
                SortUtil.mergeSort(array);
                break;
            case R.id.heap_sort_rb:
                SortUtil.heapSort(array);
                break;
        }

    }

    //数组str输出不超过100个，否则严重影响TextView渲染性能
    private String arrayToStr(int [] array){
        StringBuilder buffer = new StringBuilder();
        buffer.append("[");
        for(int i=0;i<array.length&&i<200;i++){
            int arg = array[i];
            buffer.append(arg);
            buffer.append(",");
        }
        buffer.deleteCharAt(buffer.length()-1);
        buffer.append("]");
        return buffer.toString();
    }
}
