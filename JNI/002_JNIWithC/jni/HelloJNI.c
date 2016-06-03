#include <jni.h>
#include <stdio.h>
#include "HelloJNI.h"

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   printf("Hello World!\n");
   return;
}

JNIEXPORT jdouble JNICALL Java_HelloJNI_average(JNIEnv *, jobject, jint n1, jint n2) {
	jdouble result;
	   printf("In C, the numbers are %d and %d\n", n1, n2);
	   result = ((jdouble)n1 + n2) / 2.0;
	   // jint is mapped to int, jdouble is mapped to double
	   return result;
}
