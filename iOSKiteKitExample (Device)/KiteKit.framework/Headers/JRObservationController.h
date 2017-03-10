//
//  JRObservationController.h
//  Kite
//


#import <Foundation/Foundation.h>
#import "JRObservationInfo.h"


@interface JRObservationController : NSObject

@property (weak, nonatomic, readonly) id observer;

- (JRObservationInfo*)observe:(id)object keyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options block:(JRObservationBlock)block;
- (void)removeObservationCollection:(JRObservationInfoCollection*)observationCollection;
- (void)removeAllObservations;

@end


// -------------------------------------------------------------------------------------------
    #pragma mark - Scripting
// -------------------------------------------------------------------------------------------


@protocol JRObservationControllerScriptingExports <JSExport>

@property (strong, nonatomic, readonly) NSArray *observationCollections;

@end


@interface JRObservationController (Scripting) <JRObservationControllerScriptingExports>

@end
