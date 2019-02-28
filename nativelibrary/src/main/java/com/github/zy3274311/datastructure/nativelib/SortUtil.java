package com.github.zy3274311.datastructure.nativelib;

public class SortUtil {
    static {
        System.loadLibrary("datastructure");
    }
    //冒泡排序
    public static native void bubbleSort(int[] array);
    //选择排序
    public static native void selectSort(int[] array);
    //插入排序
    public static native void insertSort(int[] array);
    //快速排序
    public static native void quickSort(int[] array);
    //堆排序
    public static native void heapSort(int[] array);
    //归并排序
    public static native void mergeSort(int[] array);
}
