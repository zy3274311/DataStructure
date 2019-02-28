//
// Created by zhangying on 2019/2/25.
//

#include <jni.h>

extern "C"
JNIEXPORT jint JNICALL
Java_com_github_zy3274311_datastructure_nativelib_SelectUtil_halfSelect(JNIEnv *env, jobject instance,
                                                             jintArray array_, jint target) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    // TODO

    env->ReleaseIntArrayElements(array_, array, 0);
}
