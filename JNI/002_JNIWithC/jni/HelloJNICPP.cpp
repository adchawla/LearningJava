#include <jni.h>
#include <iostream>
#include <string>
#include "HelloJNI.h"
using namespace std;

JNIEXPORT jstring JNICALL Java_HelloJNI_sayHello3(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
   // Step 1: Convert the JNI String (jstring) into C-String (char*)
   const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);
   if (NULL == inCStr) return NULL;

   // Step 2: Perform its intended operations
   cout << "In C++, the received string is: " << inCStr << endl;
   env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources

   // Prompt user for a C-string
   string outCppStr;
   outCppStr.append("Hello from C++ side");


   // Step 3: Convert the C++ string to C-string, then to JNI String (jstring) and return
   return env->NewStringUTF(outCppStr.c_str());
}

JNIEXPORT jdoubleArray JNICALL Java_HelloJNI_sumAndAverage(JNIEnv * env, jobject thisObj, jintArray array) {
	// Step 1: Convert jint array into native int array
	jint * CIntArray = env->GetIntArrayElements(array, NULL);
	if (NULL == CIntArray) return NULL;
	jsize nElements = env->GetArrayLength(array);
	jdouble sum = 0.0, average = 0.0;

	for (jsize i = 0; i < nElements; ++i) {
		sum += CIntArray[i];
	}
	env->ReleaseIntArrayElements(array, CIntArray, 0);
	average = sum/nElements;
	jdouble dArray[] = { sum, average };
	jdoubleArray outJNIArray = env->NewDoubleArray(2);
	if (NULL == outJNIArray) return NULL;
	env->SetDoubleArrayRegion(outJNIArray, 0, 2, dArray);
	return outJNIArray;
}
