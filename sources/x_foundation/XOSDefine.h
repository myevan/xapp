#pragma once

#ifndef __X_OS_DEFINE__
#define __X_OS_DEFINE__

#define X_OS_POSIX_GROUP        0x1000
#define X_OS_POSIX_WIN_32       0x1011
#define X_OS_POSIX_OSX          0x1020
#define X_OS_POSIX_UNKNOWN      0x10FF
#define X_OS_WIN_GROUP          0x1100
#define X_OS_WIN_32             0x1101
#define X_OS_WIN_64             0x1102
#define X_OS_NS_GROUP           0x1200
#define X_OS_OSX_GROUP          0x1210
#define X_OS_OSX_REGULAR        0x1211
#define X_OS_OSX_UNKNOWN        0x121F
#define X_OS_IOS_GROUP          0x1220
#define X_OS_IOS_DEV            0x1221
#define X_OS_IOS_SIM            0x1222
#define X_OS_LINUX_GROUP        0x1300
#define X_OS_LINUX_UNKNOWN      0x13FF
#define X_OS_ANDROID_GROUP      0x1310
#define X_OS_ANDROID_UNKNOWN    0x131F
#define X_OS_UNIX_GROUP         0x1400
#define X_OS_UNIX_UNKNOWN       0x14FF

#if POSIX
#   if defined(_WIN32)
#       define X_TARGET_OS_GROUP        X_OS_POSIX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_POSIX_WIN_32
#   elif defined(_WIN64)
#       define X_TARGET_OS_GROUP        X_OS_POSIX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_POSIX_WIN_64
#   elif defined(__APPLE__)
#       define X_TARGET_OS_GROUP        X_OS_POSIX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_POSIX_OSX
#   else
#       define X_TARGET_OS_GROUP        X_OS_POSIX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_POSIX_UNKNOWN
#   endif
#elif _WIN32
#   ifdef _WIN64
#       define X_TARGET_OS_GROUP        X_OS_WIN_GROUP
#       define X_TARGET_OS_TYPE         X_OS_WIN_64
#   else 
#       define X_TARGET_OS_GROUP        X_OS_WIN_GROUP
#       define X_TARGET_OS_TYPE         X_OS_WIN_32
#   endif
#elif __APPLE__
#   include <TargetConditionals.h>
#   if TARGET_IPHONE_SIMULATOR
#       define X_TARGET_OS_GROUP        X_OS_IOS_GROUP
#       define X_TARGET_OS_TYPE         X_OS_IOS_SIM
#   elif TARGET_OS_IPHONE
#       define X_TARGET_OS_GROUP        X_OS_IOS_GROUP
#       define X_TARGET_OS_TYPE         X_OS_IOS_DEV
#   elif TARGET_OS_MAC 
#       define X_TARGET_OS_GROUP        X_OS_OSX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_OSX_REGULAR
#   else
#       define X_TARGET_OS_GROUP        X_OS_OSX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_OSX_UNKNOWN
#   endif
#elif __ANDROID_API__ | ANDROID
#       define X_TARGET_OS_GROUP        X_OS_ANDROID_GROUP
#       define X_TARGET_OS_TYPE         X_OS_ANDROID_COMMON
#elif __linux
#       define X_TARGET_OS_GROUP        X_OS_LINUX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_LINUX_COMMON
#elif __unix 
#       define X_TARGET_OS_GROUP        X_OS_UNIX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_UNIX_UNKNOWN
#elif __posix
#       define X_TARGET_OS_GROUP        X_OS_POSIX_GROUP
#       define X_TARGET_OS_TYPE         X_OS_POSIX_UNKNOWN
#endif

#endif

