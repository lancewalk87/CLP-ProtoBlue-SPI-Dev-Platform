//
//  CLPDevice.h
//  CLP
//
//  Created by Lance T. Walker on 10/19/18.
//  Copyright © 2018 CodeLife-Productions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// *** CLPDevice Main Client Interface *** //
#pragma mark - CLPDevice Properties
extern NSString *const CLPDeviceTarget_IPAddress;
extern NSString *const CLPDeviceClient_IPAddress;

typedef NS_ENUM(NSInteger, CLPDeviceConnectionState) {
    CLPDeviceConnectionStateNone,
    CLPDeviceConnectionStateConnected,          // CLPDevice Connected, sync enabled
    CLPDeviceConnectionStateDisconnected,       // CLPDevice Disconnected, sync disabled
    CLPDeviceConnectionStateIntializeSync,      // CLPDevice Connection Attempt, sync enabled
    CLPDeviceConnectionStateDeinitializeSync    // CLPDevice Connection Terminating, sync disabled
} __WIRED_PROHIBITED;

typedef NS_ENUM(NSInteger, CLPDeviceBatteryState) {
    CLPDeviceBatteryStateNone,
    CLPDeviceBatteryStateUnplugged,     // CLPDevice Battery Discharging, USB unplugged
    CLPDeviceBatteryStateCharging,      // CLPDevice Battery Charging,  USB plugged in, charge < 100%
    CLPDeviceBatteryStateFull           // CLPDeivce Battery Full, USB plugged in, charge = 100%
};

#pragma mark - Connection State Checks
static inline BOOL CLPDeviceConnectionIsActive(CLPDeviceConnectionState state) {
    return ((state) == CLPDeviceConnectionStateDisconnected || (state) == CLPDeviceConnectionStateConnected);
}

static inline BOOL CLPDeviceBatteyIsDischarging(CLPDeviceBatteryState state) {
    return ((state) == CLPDeviceBatteryStateCharging || (state) == CLPDeviceBatteryStateUnplugged);
}

@class CLPDeviceMetaData;
@class CLPDeviceProvisions;
@protocol CLPDeviceDelegate;
@class CLPDevicePing;

@interface CLPDevice : NSObject
#if CLP_IS_SINGULAR
@property (class, nonatomic, readonly) CLPDevice * currentCLPDevice;
#else
+(CLPDevice *) currentDevice;
#endif

// CLP Head Properties
@property (nonatomic, strong, readonly) NSString * name;        // CLPDevice title: e.g: "ProtoBlue"
@property (nonatomic, strong, readonly) NSString * system;      // CLPDevice os: e.g: CLP_Debug
@property (nonatomic, strong, readonly) NSString * version;     // CLPDevice version: e.g: 1.1.0
@property (nonatomic, strong, readonly) NSString * address;     // CLPDevie ip address: e.g: 199.108.204

@end
NS_ASSUME_NONNULL_END
