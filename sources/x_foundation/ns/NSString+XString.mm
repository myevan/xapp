#include "StdAfx.h"

#import "x_foundation/ns/NSString+XString.h"

@implementation NSString (XString)

+ (NSString*)stringWithBytes:(const void *)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding 
{
    return [[[NSString alloc] initWithBytes:bytes length:length encoding:encoding] autorelease];
}

+ (NSString*)stringWithUTF8String:(const char *)chars length:(NSUInteger)length 
{
    return [[[NSString alloc] initWithBytes:chars length:length encoding:NSUTF8StringEncoding] autorelease];
}

+ (NSString*)stringWithXString:(const xf::XString&)xStr 
{
    return [[[NSString alloc] initWithBytes:xStr.GetChars() length:xStr.GetSize() encoding:NSUTF8StringEncoding] autorelease];
}

@end

