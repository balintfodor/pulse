#include <pt_fraunhofer_pulse_NativeBind.h>
#include <string>
#include <opencv2/core/core.hpp>

#include "core.h"

#include <android/log.h>
#define LOG_TAG "Pulse::Pulse"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

#define BEGIN_SAFE_CALL \
	LOGD("%s %s",__func__,"enter"); try {
#define END_SAFE_CALL \
	} catch(cv::Exception& e) { \
        jclass je = jenv->FindClass("org/opencv/core/CvException"); \
        if(!je) je = jenv->FindClass("java/lang/Exception"); \
        jenv->ThrowNew(je, e.what()); \
    } catch (...) { \
        jclass je = jenv->FindClass("java/lang/Exception"); \
        jenv->ThrowNew(je, "Unknown exception in JNI code."); \
    } \
    LOGD("%s %s",__func__,"exit");

using std::string;
using cv::Mat;

JNIEXPORT jlong JNICALL Java_pt_fraunhofer_pulse_NativeBind__1initialize
	(JNIEnv *jenv, jclass)
{
	jlong result = 0;
	BEGIN_SAFE_CALL
	
	result = (jlong)new CoreFunctions;
	
    END_SAFE_CALL
    return result;
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1reset
	(JNIEnv *jenv, jclass, jlong self, jint width, jint height)
{
	BEGIN_SAFE_CALL
	
	if (self)
		((CoreFunctions*)self)->reset(width, height);
            
    END_SAFE_CALL
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1addFrame
	(JNIEnv *jenv, jclass, jlong self, jlong frame)
{
	BEGIN_SAFE_CALL
	
	if (self)
		((CoreFunctions*)self)->addFrame(*((Mat*)frame));

    END_SAFE_CALL
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1getGraph
  (JNIEnv *jenv, jclass, jlong self, jlong graph)
{
	BEGIN_SAFE_CALL
	
	if (self)
		((CoreFunctions*)self)->getGraph(*((Mat*)graph));

    END_SAFE_CALL
}

JNIEXPORT jdouble JNICALL Java_pt_fraunhofer_pulse_NativeBind__1calculateBpm
	(JNIEnv *jenv, jclass, jlong self)
{
	jdouble res = 0;
	BEGIN_SAFE_CALL
	
	if (self)
		res = ((CoreFunctions*)self)->calculateBpm();

    END_SAFE_CALL
	
	return res;
}

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1destroy
	(JNIEnv *jenv, jclass, jlong self)
{
	BEGIN_SAFE_CALL
	
	if (self)
		delete (CoreFunctions*)self;

    END_SAFE_CALL
}

