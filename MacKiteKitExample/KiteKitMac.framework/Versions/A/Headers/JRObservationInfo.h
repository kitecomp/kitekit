//
//  JRObservationInfo.h
//  Kite
//


#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>


typedef void (^JRObservationBlock)(_Nonnull id object, _Nullable id oldValue, _Nullable id newValue);


@class JRObservationInfoCollection;


@interface JRObservationInfo : NSObject
{
    @public
    JRObservationBlock _block;
}

@property (copy, nonatomic, readonly, nonnull) JRObservationBlock block;
@property (copy, nonatomic, readonly, nonnull) NSString *uuid;
@property (copy, nonatomic, readonly, nonnull) NSString *jsContextIdentifier;

- (nonnull instancetype)initWithCollection:(nonnull JRObservationInfoCollection*)collection block:(nonnull JRObservationBlock)block;
- (void)remove;

@end


// -------------------------------------------------------------------------------------------
    #pragma mark - Scripting Exports
// -------------------------------------------------------------------------------------------

@protocol JRObservationInfoScriptingExports <JSExport>

- (void)remove;

@end


@interface JRObservationInfo (Scripting) <JRObservationInfoScriptingExports>

@end
