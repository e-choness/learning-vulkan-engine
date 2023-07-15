#pragma once

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Float point types
typedef float f32;
typedef double f64;

// Boolean types
typedef int b32;
typedef char b8;

// Properly define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Data type size assertions, ensure all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u16 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u16 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected u16 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected u16 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected u8 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected u16 to be 8 bytes.");

#define TRUE 1
#define FALSE 0

// Platform detection
// Windows 32bit
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define KPLATFORM_WINDOWS 1
// Windows 64bit
#ifndef _WIN64
#error "64-bit is required for windows."
#endif
// Linux OS
#elif defined(__linux__) || defined(__gnu_linux__)
#define KPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define KPLATFORM_ANDROID 1
#endif
// Unix OS, catch anything not caught by linux conditions
#elif defined(__unix__)
#define KPLATFORM_UNIX 1
// Portable Operating System Interface
elif defined(_POSIX_VERSION)
#define KPLATFORM_POSIX 1
// Apple platfroms
#elif __APPLE__
#define KPLATFORM_APPLE 1
#include <TargetConditionals.h>
// IOS Simulator
#if TARGET_IPHONE_SIMULATOR
#define KPLATFORM_IOS 1
#define KPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define KPLATFORM_IOS 1
// IOS Device
#elif TARGET_OS_MAC
// Output message about other types of MAC OS
#else
#error "Unknown Apple platform."
#endif
#else
#error "Unknown platform."
#endif

// Exports
#ifdef KEXPORT
#ifdef _MSC_VER
#define KAPI __declspec(dllexport)
#else
#define KAPI __attribute__((visibility("default")))
#endif
// Imports
#else
#ifdef __MSC_VER
#define KAPI __declspec(dllimport)
#else
#define KAPI
#endif
#endif