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



// Single native cl_context and single Java cl_context object
bool initNative(JNIEnv *env, jobject &javaObject, cl_context& nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_context>(env, javaObject, nativeObject, fillTarget);
}

// Single native cl_mem and single Java cl_mem object
bool initNative(JNIEnv *env, jobject &javaObject, cl_mem& nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_mem>(env, javaObject, nativeObject, fillTarget);
}
bool releaseNative(JNIEnv *env, cl_mem &nativeObject, jobject &javaObject, bool writeBack)
{
    return releaseNativeGenericNativePointerObject<cl_mem>(env, nativeObject, javaObject, writeBack);
}

// Create a Java cl_mem from a native cl_mem
jobject create(JNIEnv *env, cl_mem& nativeObject)
{
    return create<cl_mem>(env, nativeObject, cl_mem_Class, cl_mem_Constructor);
}


// Single native cl_event and single Java cl_event object
bool initNative(JNIEnv *env, jobject &javaObject, cl_event& nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_event>(env, javaObject, nativeObject, fillTarget);
}
bool releaseNative(JNIEnv *env, cl_event &nativeObject, jobject &javaObject, bool writeBack)
{
    return releaseNativeGenericNativePointerObject<cl_event>(env, nativeObject, javaObject, writeBack);
}


// Single native cl_device_id and single Java cl_device_id object
bool initNative(JNIEnv *env, jobject &javaObject, cl_device_id& nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_device_id>(env, javaObject, nativeObject, fillTarget);
}


// Single native cl_command_queue and single Java cl_command_queue object
bool initNative(JNIEnv *env, jobject &javaObject, cl_command_queue& nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObject<cl_command_queue>(env, javaObject, nativeObject, fillTarget);
}
bool releaseNative(JNIEnv *env, cl_command_queue &nativeObject, jobject &javaObject, bool writeBack)
{
    return releaseNativeGenericNativePointerObject<cl_command_queue>(env, nativeObject, javaObject, writeBack);
}


// Native cl_command_queue pointer and single Java cl_command_queue object
bool initNative(JNIEnv *env, jobject &javaObject, cl_command_queue* &nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObjectPointer<cl_command_queue>(env, javaObject, nativeObject, fillTarget);
}

bool releaseNative(JNIEnv *env, cl_command_queue* &nativeObject, jobject &javaObject, bool writeBack)
{
    return releaseNativeGenericNativePointerObjectPointer<cl_command_queue>(env, nativeObject, javaObject, writeBack);
}



// Native cl_command_queue pointer and Java cl_command_queue array
bool initNative(JNIEnv *env, jobjectArray &javaObjectArray, cl_command_queue* &nativeObjectArray, bool fillTarget)
{
    return initNativeGenericNativePointerObjectArray<cl_command_queue>(env, javaObjectArray, nativeObjectArray, fillTarget);
}

bool releaseNative(JNIEnv *env, cl_command_queue* &nativeObjectArray, jobjectArray &javaObjectArray, bool writeBack)
{
    return releaseNativeGenericNativePointerObjectArray<cl_command_queue>(env, nativeObjectArray, javaObjectArray, writeBack);
}



// Native cl_event pointer and single Java cl_event object
bool initNative(JNIEnv *env, jobject &javaObject, cl_event* &nativeObject, bool fillTarget)
{
    return initNativeGenericNativePointerObjectPointer<cl_event>(env, javaObject, nativeObject, fillTarget);
}
bool releaseNative(JNIEnv *env, cl_event* &nativeObject, jobject &javaObject, bool writeBack)
{
    return releaseNativeGenericNativePointerObjectPointer<cl_event>(env, nativeObject, javaObject, writeBack);
}


// Native cl_event pointer and Java cl_event array
bool initNative(JNIEnv *env, jobjectArray &javaObjectArray, cl_event* &nativeObjectArray, bool fillTarget)
{
    return initNativeGenericNativePointerObjectArray<cl_event>(env, javaObjectArray, nativeObjectArray, fillTarget);
}

bool releaseNative(JNIEnv *env, cl_event* &nativeObjectArray, jobjectArray &javaObjectArray, bool writeBack)
{
    return releaseNativeGenericNativePointerObjectArray<cl_event>(env, nativeObjectArray, javaObjectArray, writeBack);
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

bool initNative(JNIEnv *env, jfloatArray values, cl_float2*& values_native, bool fillTarget)
{
    if (values == nullptr)
    {
        values_native = nullptr;
        return true;
    }
    if (fillTarget)
    {
        jsize length = env->GetArrayLength(values);
        if ((length & 1) == 1)
        {
            ThrowByName(env, "java/lang/IllegalArgumentException",
                "Array length must be divisible by 2");
        }
        jsize numElements = length / 2;
        values_native = new cl_float2[(size_t)numElements];
        env->GetFloatArrayRegion(values, 0, length, (float*)values_native);
    }
    return true;
}

bool releaseNative(JNIEnv *env, cl_float2*& values_native, jfloatArray values, bool writeBack)
{
    if (values_native == nullptr)
    {
        values = nullptr;
        return true;
    }
    if (values == nullptr)
    {
        delete[] values_native;
        return true;
    }
    if (writeBack)
    {
        jsize length = env->GetArrayLength(values);
        if ((length & 1) == 1)
        {
            ThrowByName(env, "java/lang/IllegalArgumentException",
                "Array length must be divisible by 2");
        }
        env->SetFloatArrayRegion(values, 0, length, (float*)values_native);
    }
    delete[] values_native;
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

bool initNative(JNIEnv *env, jdoubleArray values, cl_double2*& values_native, bool fillTarget)
{
    if (values == nullptr)
    {
        values_native = nullptr;
        return true;
    }
    if (fillTarget)
    {
        jsize length = env->GetArrayLength(values);
        if ((length & 1) == 1)
        {
            ThrowByName(env, "java/lang/IllegalArgumentException",
                "Array length must be divisible by 2");
        }
        jsize numElements = length / 2;
        values_native = new cl_double2[(size_t)numElements];
        env->GetDoubleArrayRegion(values, 0, length, (double*)values_native);
    }
    return true;
}

bool releaseNative(JNIEnv *env, cl_double2*& values_native, jdoubleArray values, bool writeBack)
{
    if (values_native == nullptr)
    {
        values = nullptr;
        return true;
    }
    if (values == nullptr)
    {
        delete[] values_native;
        return true;
    }
    if (writeBack)
    {
        jsize length = env->GetArrayLength(values);
        if ((length & 1) == 1)
        {
            ThrowByName(env, "java/lang/IllegalArgumentException",
                "Array length must be divisible by 2");
        }
        env->SetDoubleArrayRegion(values, 0, length, (double*)values_native);
    }
    delete[] values_native;
    return true;
}

