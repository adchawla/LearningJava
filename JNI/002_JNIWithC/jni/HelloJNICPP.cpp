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

JNIEXPORT void JNICALL Java_HelloJNI_modifyInstanceVariables(JNIEnv * env, jobject thisObj) {
	// Get the class reference of the object
	jclass kclass = env->GetObjectClass(thisObj);

	// Get the field ID of the member variable (int number)
	jfieldID numberID = env->GetFieldID(kclass, "number", "I");
	if (NULL == numberID) {
		std::cerr<<"Could not get the field id of the member variable number of type int";
		return;
	}

	// Get the value of the number member variable
	jint numberValue = env->GetIntField(thisObj, numberID);
	cout<<"C++: The value of the number field is "<<numberValue<<"\n";

	// change the value of the number member variable
	env->SetIntField(thisObj, numberID, 100);

	// Get the field ID of the member variable (String message)
	jfieldID messageID = env->GetFieldID(kclass, "message", "Ljava/lang/String;");
	if (NULL == messageID) {
		std::cerr<<"Could not get the field id of the member variable message of type String";
		return;
	}

	// Get the jojbect and then type case to jstring first from the object
	jstring message = (jstring)env->GetObjectField(thisObj, messageID);

	// Create a C String from the jstring
	const char * cMessage = env->GetStringUTFChars(message, NULL);
	std::cout<<"C++: The value of the message field is \""<<cMessage<<"\"\n";
	env->ReleaseStringUTFChars(message, cMessage);

	// Create a new jstring from the env
	jstring newMessage = env->NewStringUTF("Haha! The message has been modified");
	env->SetObjectField(thisObj, messageID, newMessage);
}

JNIEXPORT void JNICALL Java_HelloJNI_modifyStaticVariable(JNIEnv * env, jobject thisObj) {
	// Get the class reference
	jclass klass = env->GetObjectClass(thisObj);

	// Get the fieldID of the static variable
	jfieldID dNumberID = env->GetStaticFieldID(klass, "dNumber", "D");
	if (NULL == dNumberID) {
		std::cerr<<"Could not get the field if of the static member variable dNumber of type double";
		return;
	}

	// Get the value of the static member field
	jdouble dNumberValue = env->GetStaticDoubleField(klass, dNumberID);
	std::cout<<"C++: The value of the dNumber is "<<dNumberValue<<"\n";

	// Change the value of the static member field
	dNumberValue = 0.0;
	env->SetStaticDoubleField(klass, dNumberID, dNumberValue);
}

JNIEXPORT void JNICALL Java_HelloJNI_sModifyStaticVariable(JNIEnv * env, jclass klass) {
	// Get the fieldID of the static variable
		jfieldID dNumberID = env->GetStaticFieldID(klass, "dNumber", "D");
		if (NULL == dNumberID) {
			std::cerr<<"Could not get the field if of the static member variable dNumber of type double";
			return;
		}

		// Get the value of the static member field
		jdouble dNumberValue = env->GetStaticDoubleField(klass, dNumberID);
		std::cout<<"C++: The value of the dNumber is "<<dNumberValue<<"\n";

		// Change the value of the static member field
		dNumberValue = 100.0;
		env->SetStaticDoubleField(klass, dNumberID, dNumberValue);
}
