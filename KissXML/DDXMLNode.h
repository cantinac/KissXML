
#import <Foundation/Foundation.h>

@class DDXMLDocument;

/**
 * Welcome to KissXML.
 *
 * The project page has documentation if you have questions.
 * https://github.com/robbiehanson/KissXML
 *
 * If you're new to the project you may wish to read the "Getting Started" wiki.
 * https://github.com/robbiehanson/KissXML/wiki/GettingStarted
 *
 * KissXML provides a drop-in replacement for Apple's NSXML class cluster.
 * The goal is to get the exact same behavior as the NSXML classes.
 *
 * For API Reference, see Apple's excellent documentation,
 * either via Xcode's Mac OS X documentation, or via the web:
 *
 * https://github.com/robbiehanson/KissXML/wiki/Reference
**/

typedef NSUInteger DDXMLNodeKind;

DDXMLNodeKind const DDXMLInvalidKind;
DDXMLNodeKind const DDXMLDocumentKind;
DDXMLNodeKind const DDXMLElementKind;
DDXMLNodeKind const DDXMLAttributeKind;
DDXMLNodeKind const DDXMLNamespaceKind;
DDXMLNodeKind const DDXMLProcessingInstructionKind;
DDXMLNodeKind const DDXMLCommentKind;
DDXMLNodeKind const DDXMLTextKind;
DDXMLNodeKind const DDXMLDTDKind;
DDXMLNodeKind const DDXMLEntityDeclarationKind;
DDXMLNodeKind const DDXMLAttributeDeclarationKind;
DDXMLNodeKind const DDXMLElementDeclarationKind;
DDXMLNodeKind const DDXMLNotationDeclarationKind;
DDXMLNodeKind const DDXMLCdataSectionKind;

enum {
	DDXMLNodeOptionsNone            = 0,
	DDXMLNodeExpandEmptyElement     = 1 << 1,
	DDXMLNodeCompactEmptyElement    = 1 << 2,
	DDXMLNodePrettyPrint            = 1 << 17,
};

@interface DDXMLNode : NSObject <NSCopying>
{
	// Every DDXML object is simply a wrapper around an underlying libxml node
	struct _xmlKind *genericPtr;

	// Every libxml node resides somewhere within an xml tree heirarchy.
	// We cannot free the tree heirarchy until all referencing nodes have been released.
	// So all nodes retain a reference to the node that created them,
	// and when the last reference is released the tree gets freed.
	DDXMLNode *owner;
}

//- (id)initWithKind:(DDXMLNodeKind)kind;

//- (id)initWithKind:(DDXMLNodeKind)kind options:(NSUInteger)options;

//+ (id)document;

//+ (id)documentWithRootElement:(DDXMLElement *)element;

+ (id)elementWithName:(NSString *)name;

+ (id)elementWithName:(NSString *)name URI:(NSString *)URI;

+ (id)elementWithName:(NSString *)name stringValue:(NSString *)string;

+ (id)elementWithName:(NSString *)name children:(NSArray *)children attributes:(NSArray *)attributes;

+ (id)attributeWithName:(NSString *)name stringValue:(NSString *)stringValue;

+ (id)attributeWithName:(NSString *)name URI:(NSString *)URI stringValue:(NSString *)stringValue;

+ (id)namespaceWithName:(NSString *)name stringValue:(NSString *)stringValue;

+ (id)processingInstructionWithName:(NSString *)name stringValue:(NSString *)stringValue;

+ (id)commentWithStringValue:(NSString *)stringValue;

+ (id)textWithStringValue:(NSString *)stringValue;

//+ (id)DTDNodeWithXMLString:(NSString *)string;

#pragma mark --- Properties ---

- (DDXMLNodeKind)kind;

- (void)setName:(NSString *)name;
- (NSString *)name;

//- (void)setObjectValue:(id)value;
//- (id)objectValue;

- (void)setStringValue:(NSString *)string;
//- (void)setStringValue:(NSString *)string resolvingEntities:(BOOL)resolve;
- (NSString *)stringValue;

#pragma mark --- Tree Navigation ---

- (NSUInteger)index;

- (NSUInteger)level;

- (DDXMLDocument *)rootDocument;

- (DDXMLNode *)parent;
- (NSUInteger)childCount;
- (NSArray *)children;
- (DDXMLNode *)childAtIndex:(NSUInteger)index;

- (DDXMLNode *)previousSibling;
- (DDXMLNode *)nextSibling;

- (DDXMLNode *)previousNode;
- (DDXMLNode *)nextNode;

- (void)detach;

- (NSString *)XPath;

#pragma mark --- QNames ---

- (NSString *)localName;
- (NSString *)prefix;

- (void)setURI:(NSString *)URI;
- (NSString *)URI;

+ (NSString *)localNameForName:(NSString *)name;
+ (NSString *)prefixForName:(NSString *)name;
//+ (DDXMLNode *)predefinedNamespaceForPrefix:(NSString *)name;

#pragma mark --- Output ---

- (NSString *)description;
- (NSString *)XMLString;
- (NSString *)XMLStringWithOptions:(NSUInteger)options;
//- (NSString *)canonicalXMLStringPreservingComments:(BOOL)comments;

#pragma mark --- XPath/XQuery ---

- (NSArray *)nodesForXPath:(NSString *)xpath error:(NSError **)error;
//- (NSArray *)objectsForXQuery:(NSString *)xquery constants:(NSDictionary *)constants error:(NSError **)error;
//- (NSArray *)objectsForXQuery:(NSString *)xquery error:(NSError **)error;

@end
