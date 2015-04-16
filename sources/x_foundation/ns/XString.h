#pragma once

#ifndef __NS_X_STRING__
#define __NS_X_STRING__

@interface NSString (stringWithBytes)

+ (NSString*)stringWithBytes:(const void *)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding;
+ (NSString*)stringWithUTF8String:(const char *)chars length:(NSUInteger)length;

@end

#endif
