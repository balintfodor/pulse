/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class pt_fraunhofer_pulse_NativeBind */

#ifndef _Included_pt_fraunhofer_pulse_NativeBind
#define _Included_pt_fraunhofer_pulse_NativeBind
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     pt_fraunhofer_pulse_NativeBind
 * Method:    _initialize
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_pt_fraunhofer_pulse_NativeBind__1initialize
  (JNIEnv *, jclass);

/*
 * Class:     pt_fraunhofer_pulse_NativeBind
 * Method:    _reset
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1reset
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     pt_fraunhofer_pulse_NativeBind
 * Method:    _addFrame
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1addFrame
  (JNIEnv *, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1getGraph
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     pt_fraunhofer_pulse_NativeBind
 * Method:    _calculateBpm
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_pt_fraunhofer_pulse_NativeBind__1calculateBpm
  (JNIEnv *, jclass, jlong);

/*
 * Class:     pt_fraunhofer_pulse_NativeBind
 * Method:    _destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_pt_fraunhofer_pulse_NativeBind__1destroy
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
