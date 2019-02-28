#include <jni.h>
#include "sort.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SortUtil_quickSort(JNIEnv *env, jclass type,
                                                          jintArray array_) {
    if(array_ == NULL){
        return;
    }
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO
    int length = env->GetArrayLength(array_);
    Sort().quickSort(array, 0, length-1);

    env->ReleaseIntArrayElements(array_, array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SortUtil_heapSort(JNIEnv *env, jclass type,
                                                         jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO
    int length = env->GetArrayLength(array_);
    Sort().heapSort(array, 0, length);

    env->ReleaseIntArrayElements(array_, array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SortUtil_bubbleSort(JNIEnv *env, jclass type,
                                                           jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO
    int length = env->GetArrayLength(array_);
    Sort().bubbleSort(array, 0, length-1);

    env->ReleaseIntArrayElements(array_, array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SortUtil_selectSort(JNIEnv *env, jclass type,
                                                           jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO
    int length = env->GetArrayLength(array_);
    Sort().selectSort(array, 0, length-1);
    env->ReleaseIntArrayElements(array_, array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SortUtil_insertSort(JNIEnv *env, jclass type,
                                                           jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO
    int length = env->GetArrayLength(array_);
    Sort().insertSort(array, 0, length-1);
    env->ReleaseIntArrayElements(array_, array, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SortUtil_mergeSort(JNIEnv *env, jclass type,
                                                          jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO
    int length = env->GetArrayLength(array_);
    Sort().mergeSort(array, 0, length-1);
    env->ReleaseIntArrayElements(array_, array, 0);
}