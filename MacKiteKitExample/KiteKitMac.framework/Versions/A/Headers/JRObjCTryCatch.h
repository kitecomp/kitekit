//
//  JRObjCTryCatch.h
//  KiteKit
//


#import <Foundation/Foundation.h>


typedef void (^JRTryBlock)(void);
typedef void (^JRCatchBlock)(NSException *exception);
typedef void (^JRFinallyBlock)(void);


@interface JRTryCatch : NSObject

+ (void)doTry:(JRTryBlock)tryBlock catch:(JRCatchBlock)catchBlock;
+ (void)doTry:(JRTryBlock)tryBlock catch:(JRCatchBlock)catchBlock finally:(JRFinallyBlock)finallyBlock;

@end
