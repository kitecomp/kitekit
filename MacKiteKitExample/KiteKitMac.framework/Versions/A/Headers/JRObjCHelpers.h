//
//  JRObjCHelpers.h
//  KiteKit
//


#import <Foundation/Foundation.h>


@interface JRObjCHelpers : NSObject

@end


#if ! TARGET_OS_IPHONE
    CG_EXTERN CGEventRef __nullable JREventCreateScrollWheelEvent(CGEventSourceRef __nullable source,
                                                                  CGScrollEventUnit units,
                                                                  uint32_t wheelCount,
                                                                  int32_t wheel1,
                                                                  int32_t wheel2);
#endif
