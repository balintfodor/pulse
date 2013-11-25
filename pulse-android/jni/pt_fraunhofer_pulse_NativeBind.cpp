#include <pt_fraunhofer_pulse_NativeBind.h>
#include <string>
#include <opencv2/core/core.hpp>

#include "Pulse.hpp"

#include <android/log.h>
#define LOG_TAG "Pulse::Pulse"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

using std::string;
using cv::Mat;

JNIEXPORT jlong JNICALL Java_pt_fraunhofer_pulse_NativeBind__1initialize
	(JNIEnv *jenv, jclass)
{
	jlong result = 0;
	return result;
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1reset
	(JNIEnv *jenv, jclass, jlong self, jint width, jint height)
{
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1addFrame
	(JNIEnv *jenv, jclass, jlong self, jlong frame)
{
}

JNIEXPORT jdouble JNICALL Java_pt_fraunhofer_pulse_NativeBind__1calculateBpm
	(JNIEnv *jenv, jclass, jlong self)
{
	return 32.0;
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1destroy
	(JNIEnv *jenv, jclass, jlong self)
{
}

