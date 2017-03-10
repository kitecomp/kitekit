//
//  JRObservationInfoCollection.h
//  Kite
//


#import <Foundation/Foundation.h>
#import "JRObservationInfo.h"


@class JRObservationController;


@interface JRObservationInfoCollection : NSObject
{
    @public
    NSMutableSet *_infos;
}

@property (copy, nonatomic, readonly) NSString *keyPath;
@property (assign, nonatomic, readonly) NSKeyValueObservingOptions options;
@property (weak, nonatomic, readonly) JRObservationController *observationController;
@property (weak, nonatomic, readonly) id observee;


- (instancetype)initWithController:(JRObservationController*)controller observee:(id)observee keyPath:(NSString*)keyPath options:(NSKeyValueObservingOptions)options;

- (JRObservationInfo*)addObservationBlock:(JRObservationBlock)block;
- (void)removeObservation:(JRObservationInfo*)observationInfo;

@end


// -------------------------------------------------------------------------------------------
    #pragma mark - Scripting
// -------------------------------------------------------------------------------------------


@protocol JRObservationInfoCollectionScriptingExports <JSExport>

@property (strong, nonatomic, readonly) NSArray *observationInfos;

@end


@interface JRObservationInfoCollection (Scripting) <JRObservationInfoCollectionScriptingExports>

@end
