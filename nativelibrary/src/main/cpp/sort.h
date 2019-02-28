//
// Created by zhangying on 2019/2/15.
//

#ifndef COMMONLIB_QUICK_SORT_H
#define COMMONLIB_QUICK_SORT_H


#include <jni.h>

#define TAG "libsort" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

class Sort {
public:
    void bubbleSort(jint *array, int start, int end);

    void selectSort(jint *array, int start, int end);

    void quickSort(jint *array, int start, int end);

    void insertSort(jint *array, int start, int end);

    void mergeSort(jint *array, int start, int end);

    void heapSort(jint *array, int start, int length);

private:
    void swap(jint *array, int source, int index);

    void merge(jint *array, int start, int mid, int end);

    void adjustHeap(jint *array, int start, int length);
};


#endif //COMMONLIB_QUICK_SORT_H
