cmake_minimum_required(VERSION 2.8)

# Overriding the CMake flags to use static runtime libraries
# See http://www.cmake.org/Wiki/CMake_FAQ#
#     How_can_I_build_my_MSVC_application_with_a_static_runtime.3F
set(CMAKE_USER_MAKE_RULES_OVERRIDE
   ${CMAKE_CURRENT_SOURCE_DIR}/CMake_c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX
   ${CMAKE_CURRENT_SOURCE_DIR}/CMake_cxx_flag_overrides.cmake)
   
project(JOCLCommon)

find_package(JNI REQUIRED)

if(MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /wd4514 /wd4820 /wd4710 /wd4711 /wd4350 /wd4668")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${PROJECT_SOURCE_DIR}/nativeLibs/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/nativeLibs)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY         ${PROJECT_SOURCE_DIR}/nativeLibs)

include_directories(
  src/main/native
  src/main/include/
  ${JNI_INCLUDE_DIRS}
)
  
add_library(JOCLCommon
  src/main/native/Logger.cpp 
  src/main/native/CLJNIUtils.cpp 
  src/main/native/JNIUtils.cpp 
  src/main/native/PointerUtils.cpp
)
