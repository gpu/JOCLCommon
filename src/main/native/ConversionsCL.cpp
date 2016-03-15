/*
* JOCL - Java bindings for OpenCL
*
* Copyright (c) 2009-2016 Marco Hutter - http://www.jocl.org
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
#include "ConversionsCL.hpp"

#include <jni.h>
#include <cstdint>
#include <cstring>

#include "JNIUtils.hpp"
#include "CLJNIUtils.hpp"
#include "PointerUtils.hpp"

bool initNative(JNIEnv *env, jbyteArray javaObject, cl_char* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jbyteArray, jbyte, cl_char>(env, javaObject, nativeObject, fill);
}

bool initNative(JNIEnv *env, jbyteArray javaObject, cl_uchar* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jbyteArray, jbyte, cl_uchar>(env, javaObject, nativeObject, fill);
}



bool initNative(JNIEnv *env, jshortArray javaObject, cl_short* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jshortArray, jshort, cl_short>(env, javaObject, nativeObject, fill);
}

bool initNative(JNIEnv *env, jshortArray javaObject, cl_ushort* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jshortArray, jshort, cl_ushort>(env, javaObject, nativeObject, fill);
}



bool initNative(JNIEnv *env, jintArray javaObject, cl_int* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jintArray, jint, cl_int>(env, javaObject, nativeObject, fill);
}

bool initNative(JNIEnv *env, jintArray javaObject, cl_uint* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jintArray, jint, cl_uint>(env, javaObject, nativeObject, fill);
}



bool initNative(JNIEnv *env, jlongArray javaObject, cl_long* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jlongArray, jlong, cl_long>(env, javaObject, nativeObject, fill);
}

bool initNative(JNIEnv *env, jlongArray javaObject, cl_ulong* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jlongArray, jlong, cl_ulong>(env, javaObject, nativeObject, fill);
}



bool initNative(JNIEnv *env, jfloatArray javaObject, cl_float* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jfloatArray, jfloat, cl_float>(env, javaObject, nativeObject, fill);
}

bool initNative(JNIEnv *env, jdoubleArray javaObject, cl_double* &nativeObject, bool fill)
{
    return initNativeGenericFixedSize<jdoubleArray, jdouble, cl_double>(env, javaObject, nativeObject, fill);
}



bool releaseNative(JNIEnv *env, cl_char* &nativeObject, jbyteArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jbyte, jbyteArray, cl_char>(env, nativeObject, javaObject, writeBack);
}

bool releaseNative(JNIEnv *env, cl_uchar* &nativeObject, jbyteArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jbyte, jbyteArray, cl_uchar>(env, nativeObject, javaObject, writeBack);
}



bool releaseNative(JNIEnv *env, cl_short* &nativeObject, jshortArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jshort, jshortArray, cl_short>(env, nativeObject, javaObject, writeBack);
}

bool releaseNative(JNIEnv *env, cl_ushort* &nativeObject, jshortArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jshort, jshortArray, cl_ushort>(env, nativeObject, javaObject, writeBack);
}



bool releaseNative(JNIEnv *env, cl_int* &nativeObject, jintArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jint, jintArray, cl_int>(env, nativeObject, javaObject, writeBack);
}

bool releaseNative(JNIEnv *env, cl_uint* &nativeObject, jintArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jint, jintArray, cl_uint>(env, nativeObject, javaObject, writeBack);
}



bool releaseNative(JNIEnv *env, cl_long* &nativeObject, jlongArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jlong, jlongArray, cl_long>(env, nativeObject, javaObject, writeBack);
}

bool releaseNative(JNIEnv *env, cl_ulong* &nativeObject, jlongArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jlong, jlongArray, cl_ulong>(env, nativeObject, javaObject, writeBack);
}



bool releaseNative(JNIEnv *env, cl_float* &nativeObject, jfloatArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jfloat, jfloatArray, cl_float>(env, nativeObject, javaObject, writeBack);
}

bool releaseNative(JNIEnv *env, cl_double* &nativeObject, jdoubleArray javaObject, bool writeBack)
{
    return releaseNativeGenericFixedSize<jdouble, jdoubleArray, cl_double>(env, nativeObject, javaObject, writeBack);
}




bool initNative(JNIEnv *env, jobject context, cl_context& context_native, bool fillTarget)
{
    if (context != nullptr)
    {
        context_native = (cl_context)env->GetLongField(context, NativePointerObject_nativePointer);
    }
    else
    {
        context_native = nullptr;
    }
    return true;
}


bool initNative(JNIEnv *env, jobject mem, cl_mem& mem_native, bool fillTarget)
{
    if (mem != nullptr)
    {
        mem_native = (cl_mem)env->GetLongField(mem, NativePointerObject_nativePointer);
    }
    else
    {
        mem_native = nullptr;
    }
    return true;
}


jobject create(JNIEnv *env, cl_mem& mem_native)
{
    if (mem_native == nullptr)
    {
        return nullptr;
    }
    jobject mem = env->NewObject(cl_mem_Class, cl_mem_Constructor);
    if (env->ExceptionCheck())
    {
        return nullptr;
    }
    env->SetLongField(mem, NativePointerObject_nativePointer, (jlong)mem_native);
    return mem;
}


bool initNative(JNIEnv *env, jobject commandQueue, cl_command_queue& commandQueue_native, bool fillTarget)
{
    if (commandQueue != nullptr)
    {
        commandQueue_native = (cl_command_queue)env->GetLongField(commandQueue, NativePointerObject_nativePointer);
    }
    else
    {
        commandQueue_native = nullptr;
    }
    return true;
}

bool releaseNative(JNIEnv *env, cl_event* &event_native, jobject event, bool writeBack)
{
    if (writeBack)
    {
        if (event_native != nullptr)
        {
            if (event == nullptr)
            {
                ThrowByName(env, "java/lang/NullPointerException",
                    "Trying to write to 'null' object");
                return false;
            }
            env->SetLongField(event, NativePointerObject_nativePointer, (jlong)event_native);
        }
    }
    return true;
}



bool initNative(JNIEnv *env, jobjectArray commandQueues, cl_command_queue* &commandQueues_native, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_command_queue>(env, commandQueues, commandQueues_native, fillTarget);
}

bool releaseNative(JNIEnv *env, cl_command_queue* &commandQueues_native, jobjectArray commandQueues, bool writeBack)
{
    return releaseNativeGenericNativePointerObject<cl_command_queue>(env, commandQueues_native, commandQueues, writeBack);
}


bool initNative(JNIEnv *env, jobjectArray events, cl_event* &events_native, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_event>(env, events, events_native, fillTarget);
}

bool releaseNative(JNIEnv *env, cl_event* &events_native, jobjectArray events, bool writeBack)
{
    return releaseNativeGenericNativePointerObject<cl_event>(env, events_native, events, writeBack);
}




bool initNative(JNIEnv *env, jfloatArray values, cl_float2& values_native, bool fillTarget)
{
    if (fillTarget)
    {
        jsize length = env->GetArrayLength(values);
        if (length < 2)
        {
            ThrowByName(env, "java/lang/ArrayIndexOutOfBoundsException",
                "Array length must be at least 2");
        }
        jfloat localValues[2];
        env->GetFloatArrayRegion(values, 0, 2, localValues);
        values_native.x = (cl_float)localValues[0];
        values_native.y = (cl_float)localValues[1];
    }
    return true;
}

bool releaseNative(JNIEnv *env, cl_float2& values_native, jfloatArray values, bool writeBack)
{
    if (writeBack)
    {
        jsize length = env->GetArrayLength(values);
        if (length < 2)
        {
            ThrowByName(env, "java/lang/ArrayIndexOutOfBoundsException",
                "Array length must be at least 2");
        }
        jfloat localValues[2];
        localValues[0] = (jfloat)values_native.x;
        localValues[1] = (jfloat)values_native.y;
        env->SetFloatArrayRegion(values, 0, 2, localValues);
    }
    return true;
}


bool initNative(JNIEnv *env, jdoubleArray values, cl_double2& values_native, bool fillTarget)
{
    if (fillTarget)
    {
        jsize length = env->GetArrayLength(values);
        if (length < 2)
        {
            ThrowByName(env, "java/lang/ArrayIndexOutOfBoundsException",
                "Array length must be at least 2");
        }
        jdouble localValues[2];
        env->GetDoubleArrayRegion(values, 0, 2, localValues);
        values_native.x = (cl_double)localValues[0];
        values_native.y = (cl_double)localValues[1];
    }
    return true;
}

bool releaseNative(JNIEnv *env, cl_double2& values_native, jdoubleArray values, bool writeBack)
{
    if (writeBack)
    {
        jsize length = env->GetArrayLength(values);
        if (length < 2)
        {
            ThrowByName(env, "java/lang/ArrayIndexOutOfBoundsException",
                "Array length must be at least 2");
        }
        jdouble localValues[2];
        localValues[0] = (jdouble)values_native.x;
        localValues[1] = (jdouble)values_native.y;
        env->SetDoubleArrayRegion(values, 0, 2, localValues);
    }
    return true;
}


