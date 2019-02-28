//
// Created by zhangying on 2019/2/25.
//

#include "select.h"

int select::harf_select(jint *array, int start, int end, int target) {
    if(start<end){
        int mid = (start + end) >> 1;
        if(array[mid] < target){
            harf_select(array, mid + 1, end, target);
        } else if(array[mid] > target) {
            harf_select(array, start, mid - 1, target);
        } else {
            return mid;
        }
    }
    return -1;
}
