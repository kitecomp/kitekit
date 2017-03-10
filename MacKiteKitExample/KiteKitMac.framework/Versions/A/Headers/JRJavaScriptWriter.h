//
//  JRJavaScriptWriter.h
//  Kite
//


#import <Foundation/Foundation.h>


@interface JRJavaScriptWriter : NSObject

@property (copy, nonatomic, readonly) NSString *scriptString;

- (void)writeMappedFunctions:(NSDictionary*)mappedFunctions forScriptObjectNamed:(NSString*)scriptObjectName;
- (void)writeMappedProperties:(NSDictionary*)mappedProperties forScriptObjectNamed:(NSString*)scriptObjectName;
- (void)writeCopiedProperties:(NSArray*)propertiesToCopy fromScriptObjectNamed:(NSString*)sourceScriptObject toScriptObjectNamed:(NSString*)destinationScriptObject;
- (void)clonePropertiesFromScriptObjectNamed:(NSString *)sourceScriptObject toScriptObjectNamed:(NSString *)destinationScriptObject;

@end
