//
// Created by zhangying on 2019/2/15.
//

#include <cstdio>
#include <android/log.h>
#include "sort.h"


void Sort::swap(jint *array, int source, int target) {
//    LOGE("swap source %d  target %d: ",source, target);
    int temp = array[source];
    array[source] = array[target];
    array[target] = temp;
}


void Sort::quickSort(jint *array, int start, int end) {
    if(start>=end){
        return;
    }
    if(array[start]>array[end]){
        swap(array, start, end);
    }
    int m = (start+end)>>1;
    if(array[m]>array[end]){
        swap(array, m, end);
    }
    if(array[m]>array[start]){
        swap(array, m, start);
    }
    int st = array[start];
    int left = start;
    int right = end;
    while (right>left){
        while (right>left&&array[right]>=st) right--;

        while (right>left&&array[left]<=st) left++;

        if(right>left){
            //right 停止
            swap(array, left, right);
        }
    }

    if(right>start){
        swap(array, start, right);
    }

    if(right-1>start){
        quickSort(array, start, right-1);
    }
    if(right+1<end){
        quickSort(array, right+1, end);
    }
}

void Sort::bubbleSort(jint *array, int start, int end) {
    if(start<end){
        bool flag = true;
        for(int i = start; i<end&&flag; i++){
            flag = false;
            for(int j = end;j > i; j--){
                if(array[j]<array[j-1]){
                    swap(array, j, j-1);
                    flag = true;
                }
            }
        }
    }
}

void Sort::selectSort(jint *array, int start, int end) {
    if(start<end){
        int min;
        for(int i = start; i<end; i++){
            min = i;
            for(int j = end;j > i; j--){
                if(array[j]<array[min]){
                    min = j;
                }
            }
            if(min!=i){
                swap(array, i, min);
            }
        }
    }
}

void Sort::insertSort(jint *array, int start, int end) {
    if(start<end){
        for(int i = start+1;i<=end;i++){
            int index = start;
            for(int j = i-1;j>=start;j--){
                if(array[i]>=array[j]){
                    index = j+1;
                    break;
                }
            }
            if(index!=i){
                int temp = array[i];
                for(int k=i;k>index;k--){
                    array[k]=array[k-1];
                }
                array[index] = temp;
            }
        }
    }
}

void Sort::mergeSort(jint *array, int start, int end) {
    if(start <end){
        int mid = (start + end)>>1;
        mergeSort(array, start, mid);
        mergeSort(array, mid+1, end);
        merge(array,start, mid, end);
    }
}

void Sort::merge(jint *array, int start, int mid, int end) {
    int i = start;
    int j = mid+1;
    int len = end - start + 1;
    int temp[len];
    int k = 0;
    while (i<=mid&&j<=end) {
        temp[k++] = array[i] < array[j] ? array[i++] : array[j++];
    }
    while (i<=mid) {
        temp[k++] = array[i++];
    }
    while (j<=end) {
        temp[k++] = array[j++];
    }
    for(i=0;i<len;i++){
        array[start+i] = temp[i];
    }
}

void Sort::heapSort(jint *array, int start, int length) {
    int len = length + 1;
    int t[len];
    for(int i=1;i<len;i++){
        t[i] = array[i-1+start];
    }
    //最大堆调整 将堆的末端子节点作调整，使得子节点永远小于父节点
    for(int p=len>>1;p>=1;p--){
        adjustHeap(t, p, len);
    }

    for(int i = len;i>1;i--){
        swap(t, 1, i);
        adjustHeap(t, 1, i);
    }

    for(int i=1;i<len;i++){
        array[i-1+start] = t[i];
    }
}

void Sort::adjustHeap(jint *array, int s, int length) {
    int temp = array[s];
    for(int i = s<<1; i<length; i<<=1){
        if((i+1)<length&array[i]<array[i+1]){
            i++;
        }
        if(temp>array[i]){
            break;
        }
        array[s] = array[i];
        s = i;
    }
    array[s] = temp;
}


