
#import <Foundation/Foundation.h>

#import "NSString+DDXML.h"

#if ! __has_feature(objc_arc)
#warning This file must be compiled with ARC. Use -fobjc-arc flag (or convert project to ARC).
#endif

#if __has_feature(modules) && \
(  (TARGET_OS_IPHONE && __IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) \
|| (__MAC_OS_X_VERSION_MIN_REQUIRED >= 1090) )
@import xml;
#else
#import <libxml/tree.h>
#endif

@implementation NSString (DDXML)

- (const xmlChar *)xmlChar
{
	return (const xmlChar *)[self UTF8String];
}

#ifdef GNUSTEP
- (NSString *)stringByTrimming
{
	return [self stringByTrimmingSpaces];
}
#else
- (NSString *)stringByTrimming
{
	NSMutableString *mStr = [self mutableCopy];
	CFStringTrimWhitespace((__bridge CFMutableStringRef)mStr);

	NSString *result = [mStr copy];

	return result;
}
#endif

@end
