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
#ifndef JOCL_CONVERSIONS_CL_HPP
#define JOCL_CONVERSIONS_CL_HPP

#include <jni.h>

#include <cstdint>
#include <cstring>

#include "JOCLCommon.hpp"
#include "JNIUtils.hpp"
#include "PointerUtils.hpp"

/**
 * Generic initialization of (primitive) data for data types with a
 * fixed size.
 *
 * This will allocate a native array of the same size as the given
 * Java array. If the 'fill' parameter is 'true', then this native
 * array will be filled with the data from the Java array. If the
 * given java array is nullptr, then the native pointer will be
 * set to nullptr as well.
 *
 * The JavaArrayType is assumed to be a  JNI array type (like jintArray).
 * The JavaType is assumed to be the matching element type (like jint).
 * The NativeType is assumed to be a type with the same size as the JavaType
 * (like int32_t)
 */
template <typename JavaArrayType, typename JavaType, typename NativeType>
bool initNativeGenericFixedSize(
    JNIEnv *env, JavaArrayType javaObject, NativeType* &nativeObject, bool fill)
{
    if (javaObject == nullptr)
    {
        nativeObject = nullptr;
        return true;
    }
    jsize length = env->GetArrayLength(javaObject);
    nativeObject = new NativeType[size_t(length)];
    if (nativeObject == nullptr)
    {
        ThrowByName(env, "java/lang/OutOfMemoryError",
            "Out of memory during array creation");
        return false;
    }
    if (fill)
    {
        JavaType *primitiveArray =
            (JavaType*)env->GetPrimitiveArrayCritical(javaObject, nullptr);
        if (primitiveArray == nullptr)
        {
            delete[] nativeObject;
            nativeObject = nullptr;
            return false;
        }
        std::memcpy(nativeObject, primitiveArray, length * sizeof(JavaType));
        env->ReleasePrimitiveArrayCritical(javaObject, primitiveArray, JNI_ABORT);
    }
    return true;
}

bool initNative(JNIEnv *env, jbyteArray javaObject, cl_char* &nativeObject, bool fill);
bool initNative(JNIEnv *env, jbyteArray javaObject, cl_uchar* &nativeObject, bool fill);

bool initNative(JNIEnv *env, jshortArray javaObject, cl_short* &nativeObject, bool fill);
bool initNative(JNIEnv *env, jshortArray javaObject, cl_ushort* &nativeObject, bool fill);

bool initNative(JNIEnv *env, jintArray javaObject, cl_int* &nativeObject, bool fill);
bool initNative(JNIEnv *env, jintArray javaObject, cl_uint* &nativeObject, bool fill);

bool initNative(JNIEnv *env, jlongArray javaObject, cl_long* &nativeObject, bool fill);
bool initNative(JNIEnv *env, jlongArray javaObject, cl_ulong* &nativeObject, bool fill);

bool initNative(JNIEnv *env, jfloatArray javaObject, cl_float* &nativeObject, bool fill);
bool initNative(JNIEnv *env, jdoubleArray javaObject, cl_double* &nativeObject, bool fill);



/**
 * Generic release of (primitive) data for data types with a 
 * fixed size. 
 *
 * This will delete[] the native array and set it to nullptr. If the
 * 'writeBack' parameter is 'true', then the data will be written 
 * from the given native array back into the Java array.
 *
 * The JavaArrayType is assumed to be a  JNI array type (like jintArray).
 * The JavaType is assumed to be the matching element type (like jint).
 * The NativeType is assumed to be a type with the same size as the JavaType
 * (like int32_t)
 */
template <typename JavaType, typename JavaArrayType, typename NativeType>
bool releaseNativeGenericFixedSize(
    JNIEnv *env, NativeType* &nativeObject, JavaArrayType javaObject, bool writeBack)
{
    if (javaObject == nullptr)
    {
        delete[] nativeObject;
        nativeObject = nullptr;
        return true;
    }
    if (writeBack)
    {
        jsize length = env->GetArrayLength(javaObject);
        JavaType *primitiveArray =
            (JavaType*)env->GetPrimitiveArrayCritical(javaObject, nullptr);
        if (primitiveArray == nullptr)
        {
            delete[] nativeObject;
            nativeObject = nullptr;
            return false;
        }
        std::memcpy(primitiveArray, nativeObject, length * sizeof(JavaType));
        env->ReleasePrimitiveArrayCritical(javaObject, primitiveArray, 0);
    }
    delete[] nativeObject;
    nativeObject = nullptr;
    return true;
}

bool releaseNative(JNIEnv *env, cl_char* &nativeObject, jbyteArray javaObject, bool writeBack);
bool releaseNative(JNIEnv *env, cl_uchar* &nativeObject, jbyteArray javaObject, bool writeBack);

bool releaseNative(JNIEnv *env, cl_short* &nativeObject, jshortArray javaObject, bool writeBack);
bool releaseNative(JNIEnv *env, cl_ushort* &nativeObject, jshortArray javaObject, bool writeBack);

bool releaseNative(JNIEnv *env, cl_int* &nativeObject, jintArray javaObject, bool writeBack);
bool releaseNative(JNIEnv *env, cl_uint* &nativeObject, jintArray javaObject, bool writeBack);

bool releaseNative(JNIEnv *env, cl_long* &nativeObject, jlongArray javaObject, bool writeBack);
bool releaseNative(JNIEnv *env, cl_ulong* &nativeObject, jlongArray javaObject, bool writeBack);

bool releaseNative(JNIEnv *env, cl_float* &nativeObject, jfloatArray javaObject, bool writeBack);
bool releaseNative(JNIEnv *env, cl_double* &nativeObject, jdoubleArray javaObject, bool writeBack);




/**
 * Generic initialization of arrays of OpenCL types from arrays of
 * Java objects.
 *
 * This will allocate a native array of the same size as the given
 * Java array. If the 'fill' parameter is 'true', then this native
 * array will be filled with the data from the Java array. If the
 * given java array is nullptr, then the native pointer will be
 * set to nullptr as well.
 *
 * The native array will be filled by fetching the 
 * NativePointerObject_nativePointer value from the
 * objects in the array. None of these objects may
 * be nullptr.
 */
template <typename NativeType>
bool initNativeGenericNativePointerObjectArray(
    JNIEnv *env, jobjectArray objects, NativeType* &objects_native, bool fill)
{
    if (objects == nullptr)
    {
        objects_native = nullptr;
        return true;
    }

    jsize length = env->GetArrayLength(objects);
    objects_native = new NativeType[size_t(length)];
    if (objects_native == NULL)
    {
        ThrowByName(env, "java/lang/OutOfMemoryError",
            "Out of memory during array creation");
        return false;
    }

    if (fill)
    {
        for (jsize i = 0; i < length; i++)
        {
            jobject object = env->GetObjectArrayElement(objects, i);
            if (env->ExceptionCheck())
            {
                delete[] objects_native;
                objects_native = nullptr;
                return false;
            }
            if (object == nullptr)
            {
                delete[] objects_native;
                objects_native = nullptr;
                ThrowByName(env, "java/lang/NullPointerException",
                    "Array contains 'null' elements");
                return false;
            }
            objects_native[i] =
                (NativeType)env->GetLongField(object, NativePointerObject_nativePointer);
        }
    }
    return true;
}


/**
 * Generic release of arrays of OpenCL types from arrays of
 * Java objects.
 *
 * This will delete the given native objects array.
 * If the 'writeBack' parameter is 'true', then these
 * native objects will be set as the 
 * NativePointerObject_nativePointer value of the corresponding
 * Java objects. 
 *
 * None of thes objects in the array may be nullptr.
 */
template <typename NativeType>
bool releaseNativeGenericNativePointerObjectArray(
    JNIEnv *env, NativeType* &objects_native, jobjectArray objects, bool writeBack)
{
    if (objects_native == nullptr)
    {
        return true;
    }
    if (objects == nullptr)
    {
        delete[] objects_native;
        objects_native = nullptr;
        ThrowByName(env, "java/lang/NullPointerException",
            "Trying to write to 'null' array");
        return false;
    }
    jsize length = env->GetArrayLength(objects);
    if (writeBack)
    {
        for (jsize i = 0; i < length; i++)
        {
            jobject object = env->GetObjectArrayElement(objects, i);
            if (env->ExceptionCheck())
            {
                delete[] objects_native;
                objects_native = nullptr;
                return false;
            }
            if (object == nullptr)
            {
                delete[] objects_native;
                objects_native = nullptr;
                ThrowByName(env, "java/lang/NullPointerException",
                    "Array contains 'null' elements");
                return false;
            }
            env->SetLongField(object, NativePointerObject_nativePointer, (jlong)objects_native[i]);
        }
    }
    delete[] objects_native;
    objects_native = nullptr;
    return true;
}

/**
 * Generic initialization of a native OpenCL object from a 
 * Java NativePointerObject.
 *
 * The OpenCL object is assumed to be an opaque pointer. 
 * If fillTarget==true, then it will be set to the long
 * value of the NativePointerObject_nativePointer field
 */
template <typename NativeType>
bool initNativeGenericNativePointerObject(JNIEnv *env, jobject &javaObject, NativeType &nativeObject, bool fillTarget)
{
    if (javaObject == nullptr)
    {
        nativeObject = nullptr;
        return true;
    }
    if (fillTarget)
    {
        nativeObject = (NativeType)env->GetLongField(javaObject, NativePointerObject_nativePointer);
    }
    return true;
}

/**
 * Generic release of a native OpenCL object that was created
 * from a Java NativePointerObject.
 *
 * The OpenCL object is assumed to be an opaque pointer. 
 * If writeBack==true, then it will be set as the long
 * value of the NativePointerObject_nativePointer field
 */
template <typename NativeType>
bool releaseNativeGenericNativePointerObject(JNIEnv *env, NativeType &nativeObject, jobject &javaObject, bool writeBack)
{
    if (writeBack && nativeObject != nullptr && javaObject != nullptr)
    {
        env->SetLongField(javaObject, NativePointerObject_nativePointer, (jlong)nativeObject);
    }
    nativeObject = nullptr;
    return true;
}


/**
 * Generic initialization of a native OpenCL object pointer
 * from a Java NativePointerObject.
 *
 * The OpenCL object is assumed to be an opaque pointer. 
 * If fillTarget==true, then it will be set to the long
 * value of the NativePointerObject_nativePointer field
 */
template <typename NativeType>
bool initNativeGenericNativePointerObjectPointer(JNIEnv *env, jobject &javaObject, NativeType* &nativeObject, bool fillTarget)
{
    if (javaObject == nullptr)
    {
        nativeObject = nullptr;
        return true;
    }
    nativeObject = new NativeType();
    if (fillTarget)
    {
        *nativeObject = (NativeType)env->GetLongField(javaObject, NativePointerObject_nativePointer);
    }
    return true;
}

/**
 * Generic release of a native OpenCL object that was created
 * from a Java NativePointerObject.
 *
 * The OpenCL object is assumed to be an opaque pointer. 
 * If writeBack==true, then it will be set as the long
 * value of the NativePointerObject_nativePointer field
 */
template <typename NativeType>
bool releaseNativeGenericNativePointerObjectPointer(JNIEnv *env, NativeType* &nativeObject, jobject &javaObject, bool writeBack)
{
    if (writeBack && nativeObject != nullptr && javaObject != nullptr)
    {
        env->SetLongField(javaObject, NativePointerObject_nativePointer, (jlong)nativeObject);
    }
    delete nativeObject;
    nativeObject = nullptr;
    return true;
}


// Single native cl_context and single Java cl_context object
bool initNative(JNIEnv *env, jobject &javaObject, cl_context& nativeObject, bool fillTarget);

// Single native cl_mem and single Java cl_mem object
bool initNative(JNIEnv *env, jobject &javaObject, cl_mem& nativeObject, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_mem &nativeObject, jobject &javaObject, bool writeBack);

jobject create(JNIEnv *env, cl_mem& mem_native);

// Single native cl_event and single Java cl_event object
bool initNative(JNIEnv *env, jobject &javaObject, cl_event& nativeObject, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_event &nativeObject, jobject &javaObject, bool writeBack);

// Single native cl_command_queue and single Java cl_command_queue object
bool initNative(JNIEnv *env, jobject &javaObject, cl_command_queue& nativeObject, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_command_queue &nativeObject, jobject &javaObject, bool writeBack);

// Single native cl_device_id and single Java cl_device_id object
bool initNative(JNIEnv *env, jobject &javaObject, cl_device_id& nativeObject, bool fillTarget);

// Native cl_command_queue pointer and single Java cl_command_queue object
bool initNative(JNIEnv *env, jobject &javaObject, cl_command_queue* &nativeObject, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_command_queue* &nativeObject, jobject &javaObject, bool writeBack);

// Native cl_command_queue pointer and Java cl_command_queue array
bool initNative(JNIEnv *env, jobjectArray &javaObjectArray, cl_command_queue* &nativeObjectArray, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_command_queue* &nativeObjectArray, jobjectArray &javaObjectArray, bool writeBack);

// Native cl_event pointer and single Java cl_event object
bool initNative(JNIEnv *env, jobject &javaObject, cl_event* &nativeObject, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_event* &nativeObject, jobject &javaObject, bool writeBack);

// Native cl_event pointer and Java cl_event array
bool initNative(JNIEnv *env, jobjectArray &javaObjectArray, cl_event* &nativeObjectArray, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_event* &nativeObjectArray, jobjectArray &javaObjectArray, bool writeBack);


bool initNative(JNIEnv *env, jfloatArray values, cl_float2& values_native, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_float2& values_native, jfloatArray values, bool writeBack);

bool initNative(JNIEnv *env, jdoubleArray values, cl_double2& values_native, bool fillTarget);
bool releaseNative(JNIEnv *env, cl_double2& values_native, jdoubleArray values, bool writeBack);

// Create a Java NativePointerObject from a native object
template <typename NativeType>
jobject create(JNIEnv *env, NativeType& nativeObject, jclass javaClass, jmethodID javaConstructor)
{
    if (nativeObject == nullptr)
    {
        return nullptr;
    }
    jobject javaObject = env->NewObject(javaClass, javaConstructor);
    if (env->ExceptionCheck())
    {
        return nullptr;
    }
    env->SetLongField(javaObject, NativePointerObject_nativePointer, (jlong)nativeObject);
    return javaObject;
}


#endif // JOCL_CONVERSIONS_CL_HPP

