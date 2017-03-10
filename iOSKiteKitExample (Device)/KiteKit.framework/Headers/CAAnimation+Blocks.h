//
//  CAAnimation+Blocks.h
//  CAAnimationBlocks
//


#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>


// -------------------------------------------------------------------------------------------
    #pragma mark - JRAnimationDelegate
// -------------------------------------------------------------------------------------------

@interface JRAnimationDelegate : NSObject

@property (copy, nonatomic, readonly) NSString *jsContextIdentifier;

@end


// -------------------------------------------------------------------------------------------
    #pragma mark -
// -------------------------------------------------------------------------------------------

@interface CAAnimation (BlocksAddition)

@property (nonatomic, copy) void (^completion)(BOOL finished);
@property (nonatomic, copy) void (^start)(void);

- (void)setCompletion:(void (^)(BOOL finished))completion;

@end
