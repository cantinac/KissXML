//
//  KissXML.h
//  KissXML
//
//  Created by Armando Di Cianno on 7/31/15.
//
//

#import <Foundation/Foundation.h>

//! Project version number for KissXML.
FOUNDATION_EXPORT double KissXMLVersionNumber;

//! Project version string for KissXML.
FOUNDATION_EXPORT const unsigned char KissXMLVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <KissXML/PublicHeader.h>

#import "DDXML.h"
#import "DDXMLNode.h"
#import "DDXMLElement.h"
#import "DDXMLDocument.h"
#import "DDXMLElementAdditions.h"
#import "NSString+DDXML.h"

#if TARGET_OS_IPHONE
#if KISSXML_AS_NSXML
// Disabled by default

// Since KissXML is a drop in replacement for NSXML,
// it may be desireable (when writing cross-platform code to be used on both Mac OS X and iOS)
// to use the NSXML prefixes instead of the DDXML prefix.
//
// This way, on Mac OS X it uses NSXML, and on iOS it uses KissXML.

#ifndef NSXMLNode
    #define NSXMLNode DDXMLNode
#endif

#ifndef NSXMLElement
    #define NSXMLElement DDXMLElement
#endif

#ifndef NSXMLDocument
    #define NSXMLDocument DDXMLDocument
#endif

#ifndef NSXMLInvalidKind
    #define NSXMLInvalidKind DDXMLInvalidKind
#endif

#ifndef NSXMLDocumentKind
    #define NSXMLDocumentKind DDXMLDocumentKind
#endif

#ifndef NSXMLElementKind
    #define NSXMLElementKind DDXMLElementKind
#endif

#ifndef NSXMLAttributeKind
    #define NSXMLAttributeKind DDXMLAttributeKind
#endif

#ifndef NSXMLNamespaceKind
    #define NSXMLNamespaceKind DDXMLNamespaceKind
#endif

#ifndef NSXMLProcessingInstructionKind
    #define NSXMLProcessingInstructionKind DDXMLProcessingInstructionKind
#endif

#ifndef NSXMLCommentKind
    #define NSXMLCommentKind DDXMLCommentKind
#endif

#ifndef NSXMLTextKind
    #define NSXMLTextKind DDXMLTextKind
#endif

#ifndef NSXMLDTDKind
    #define NSXMLDTDKind DDXMLDTDKind
#endif

#ifndef NSXMLEntityDeclarationKind
    #define NSXMLEntityDeclarationKind DDXMLEntityDeclarationKind
#endif

#ifndef NSXMLAttributeDeclarationKind
    #define NSXMLAttributeDeclarationKind DDXMLAttributeDeclarationKind
#endif

#ifndef NSXMLElementDeclarationKind
    #define NSXMLElementDeclarationKind DDXMLElementDeclarationKind
#endif

#ifndef NSXMLNotationDeclarationKind
    #define NSXMLNotationDeclarationKind DDXMLNotationDeclarationKind
#endif

#ifndef NSXMLNodeOptionsNone
    #define NSXMLNodeOptionsNone DDXMLNodeOptionsNone
#endif

#ifndef NSXMLNodeExpandEmptyElement
    #define NSXMLNodeExpandEmptyElement DDXMLNodeExpandEmptyElement
#endif

#ifndef NSXMLNodeCompactEmptyElement
    #define NSXMLNodeCompactEmptyElement DDXMLNodeCompactEmptyElement
#endif

#ifndef NSXMLNodePrettyPrint
    #define NSXMLNodePrettyPrint DDXMLNodePrettyPrint
#endif

#endif // #if KISSXML_AS_NSXML
#endif // #if TARGET_OS_IPHONE
