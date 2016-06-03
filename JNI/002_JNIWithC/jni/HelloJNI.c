#include <jni.h>
#include <stdio.h>
#include "HelloJNI.h"

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   printf("Hello World!\n");
   return;
}

JNIEXPORT jdouble JNICALL Java_HelloJNI_average(JNIEnv * env, jobject thisObj, jint n1, jint n2) {
	jdouble result;
	   printf("In C, the numbers are %d and %d\n", n1, n2);
	   result = ((jdouble)n1 + n2) / 2.0;
	   // jint is mapped to int, jdouble is mapped to double
	   return result;
}

JNIEXPORT jstring JNICALL Java_HelloJNI_sayHello2(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
   // Step 1: Convert the JNI String (jstring) into C-String (char*)
   const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
   if (NULL == inCStr) return NULL;

   // Step 2: Perform its intended operations
   printf("In C, the received string is: %s\n", inCStr);
   (*env)->ReleaseStringUTFChars(env, inJNIStr, inCStr);  // release resources

   // Prompt user for a C-string
   char * newStr = "Hello from C side";
   // not more than 127 characters

   // Step 3: Convert the C-string (char*) into JNI String (jstring) and return
   return (*env)->NewStringUTF(env, newStr);
}

JNIEXPORT jstring JNICALL Java_HelloJNI_sayHello5(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
	  // Step 1: Convert the JNI String (jstring) into C-String (char*)
	   const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	   if (NULL == inCStr) return NULL;

	   // Step 2: Perform its intended operations
	   printf("In C, the received string is: %s\n", inCStr);
	   (*env)->ReleaseStringUTFChars(env, inJNIStr, inCStr);  // release resources

	   // Prompt user for a C-string
	   char * newStr = "Hello from C2 side";
	   // not more than 127 characters

	   // Step 3: Convert the C-string (char*) into JNI String (jstring) and return
	   return (*env)->NewStringUTF(env, newStr);
}
