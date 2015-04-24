#pragma once
#ifndef __STD_AFX__
#define __STD_AFX__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <string>

#include <x_foundation/XOSDefine.h>

#ifdef __OBJC__
#   if X_TARGET_OS_GROUP == X_OS_IOS_GROUP
#       import <Foundation/Foundation.h>
#   elif X_TARGET_OS_GROUP == X_OS_OSX_GROUP
#       import <Cocoa/Cocoa.h>
#   endif
#endif

#endif
