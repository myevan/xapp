#pragma once

#ifndef __NS_STRING_X_STRING__
#define __NS_STRING_X_STRING__

#include <x_foundation/XString.h>

@interface NSString (XString)

+ (NSString*)stringWithBytes:(const void *)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding;
+ (NSString*)stringWithUTF8String:(const char *)chars length:(NSUInteger)length;
+ (NSString*)stringWithXString:(const xf::XString&)xStr;
@end

#endif
