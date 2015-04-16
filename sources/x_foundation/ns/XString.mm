#include "StdAfx.h"

#include <x_foundation/ns/XString.h>

@implementation NSString (stringWithBytes)

+ (NSString*)stringWithBytes:(const void *)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding {
    return [[[NSString alloc] initWithBytes:bytes length:length encoding:encoding] autorelease];
}

+ (NSString*)stringWithUTF8String:(const char *)chars length:(NSUInteger)length {
    return [[[NSString alloc] initWithBytes:chars length:length encoding:NSUTF8StringEncoding] autorelease];
}

@end

