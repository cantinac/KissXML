
#import <Foundation/Foundation.h>

typedef unsigned char ddXmlChar;

@interface NSString (DDXML)

/**
 * xmlChar - A basic replacement for char, a byte in a UTF-8 encoded string.
**/
- (const ddXmlChar *)xmlChar;

- (NSString *)stringByTrimming;

@end
