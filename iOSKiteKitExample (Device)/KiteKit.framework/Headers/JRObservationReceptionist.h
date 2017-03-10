//
//  JRObservationReceptionist.h
//  Kite
//


#import <Foundation/Foundation.h>


@class JRObservationInfoCollection;


@interface JRObservationReceptionist : NSObject

+ (instancetype)sharedInstance;

- (void)observe:(id)object collection:(JRObservationInfoCollection*)collection;
- (void)unobserve:(id)observee collection:(JRObservationInfoCollection*)collection;
- (void)unobserve:(id)observee collections:(NSArray<JRObservationInfoCollection*>*)collections;

@end
