#include "pch.h"
#include "JNIdemo.h"
#include "CplusDemo.h"
#include <iostream>
#include <stdio.h>


	JNIEXPORT void JNICALL Java_JNIdemo_testHello
	(JNIEnv*, jobject) {
		std::cout << "hello world" << std::endl;
	}

	/*
	 * Class:     JNIdemo
	 * Method:    testPrint
	 * Signature: (I)I
	 */
	JNIEXPORT jint JNICALL Java_JNIdemo_testPrint
	(JNIEnv*, jobject, jint num) {
		std::cout << num << std::endl;
		return num;
	}

	/*
	 * Class:     JNIdemo
	 * Method:    createNativeObject
	 * Signature: ()J
	 */

	extern "C"
	JNIEXPORT jlong JNICALL Java_JNIdemo_createNativeObject
	(JNIEnv*, jobject) {
		jlong res = NULL;
		res = (jlong)new CplusDemo();
		return res;
	}

	/*
	 * Class:     JNIdemo
	 * Method:    nativeSetAge
	 * Signature: (JI)V
	 */
	JNIEXPORT void JNICALL Java_JNIdemo_nativeSetAge
	(JNIEnv*, jobject, jlong addr, jint age) {
		((CplusDemo*)addr)->setAge(age);
	}

	/*
	 * Class:     JNIdemo
	 * Method:    nativeGetAge
	 * Signature: ()I
	 */
	JNIEXPORT jint JNICALL Java_JNIdemo_nativeGetAge
	(JNIEnv*, jobject, jlong addr) {
		return ((CplusDemo*)addr)->getAge();
	}
