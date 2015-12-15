//
//  MipRobot.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
// 

@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "MipRobotSound.h"
#import "BluetoothRobot.h"

@class MipEventManager;

@protocol MipRobotDelegate;

FOUNDATION_EXPORT NSString *const MIP_CONNECTED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const MIP_DISCONNECTED_NOTIFICATION_NAME;

typedef NS_ENUM(NSInteger, MIPLogLevel) {
    MIPLogLevelDebug,
    MIPLogLevelErrors,
    MipLogLevelNone
};

@interface MipRobot : BluetoothRobot

/** Event manager handles handling basic events which do not require app interaction **/
@property (nonatomic, strong) MipEventManager *eventManager;
@property (nonatomic, strong) NSDate *mipFirmwareVersionDate;
@property (nonatomic, assign) NSUInteger mipFirmwareVersionId;
@property (nonatomic, strong) NSNumber *mipVoiceFirmwareVersion;
@property (nonatomic, strong) NSNumber *mipHardwareVersion;
@property (nonatomic, assign) kMipPositionValue position;
@property (nonatomic, assign) NSInteger batteryLevel;
@property (nonatomic, readonly, assign) kMipPingResponse bootMode;
@property (nonatomic, readonly, assign) kMipActivationStatus toyActivationStatus;
@property (nonatomic, assign) NSInteger mipVolume;

@property (nonatomic, assign) bool disableReceivedCommandProcessing;

@property (nonatomic, assign) MIPLogLevel logLevel;

/** Delegate for receiving callbacks */
@property (nonatomic, weak) id<MipRobotDelegate> delegate;

#pragma mark - Mip Protocal Methods
#pragma mark Device Commands
-(void) getMipActivationStatus;
-(void) mipStop;
/** Toggle IR Remote on/off
 @param whether or not to enable the remote
 **/
-(void) setMipIRControlEnabled:(bool)enabled;
/** Gets the current IR remote status **/
-(void) getMipIRControlEnabled;
/** Completely powers off the MIP. This will disconnect the IOS device.
 Note: User must toggle power switch to power back on */
-(void) mipPowerOff;
/** Stops any current mip activities. */
-(void) mipSleep;
-(void) setMipVolumeLevel:(uint8_t)volumeLevel;
-(void) getMipVolumeLevel;
-(void) getMipSoftwareVersion;
-(void) getMipUserData;
-(void) setMipUserDataWithByteArray:(NSArray *)byteArray;
-(void) setMipUserDataWithByteCount:(unsigned int)byteCount bytes:(uint8_t)firstByte, ...;

-(void) readMipHardwareVersion;
-(void) readMipFirmwareVersion;

-(void) mipPing;
-(void) mipReboot;
-(void) mipRebootWriteFlash:(bool)forceBootloader writeIO:(bool)writeIO;

#pragma mark Sensor Controls
-(void) readMipSensorOdometer;
-(void) resetMipSensorOdometer;
-(void) readMipStatus;
-(void) readMipSensorWeightLevel;
-(void) setMipGestureMode:(kMipGestureModeValue)value;
-(void) getMipGestureMode;
-(void) setMipRadarMode:(kMipRadarModeValue)value;
-(void) getMipRadarMode;
-(void) setMipOtherMipDetectionModeOnUsingMipId:(u_int8_t)mipId powerDistanceCm:(uint8_t)powerDistanceCm;
-(void) setMipOtherMipDetectionModeOff;
-(void) getMipOtherMipDetectionModeStatus;

#pragma mark Gameplay Commands
/** Tells mip to falldown in a certain way
 @param falldownStyle specify which direction MIP should falldown
 **/
-(void) mipFalloverWithStyle:(kMipPositionValue)style;
-(void) mipPunchLeftWithSpeed:(uint8_t)speed;
-(void) mipPunchRightWithSpeed:(uint8_t)speed;

#pragma mark Sound Commands
- (void) mipPlaySoundWithEnum:(kMipSoundFileValue)soundValue;
- (void) mipPlaySound:(MipRobotSound *)sound;
- (void) mipPlaySoundQueue:(MipRobotSound *)sound, ... NS_REQUIRES_NIL_TERMINATION;
- (void) mipStopSound;

#pragma mark LED Commands
-(void) setMipChestRGBLedWithColor:(UIColor *)color;
-(void) setMipChestRGBLedWithColorRed:(uint8_t)red green:(uint8_t)green blue:(uint8_t)blue fadeInTime:(uint8_t)fadeIn;
-(void) setMipChestRGBLedFlashingWithColor:(UIColor *)color timeOn:(uint8_t)timeOn timeOff:(uint8_t)timeOff;
-(void) setMipChestRGBLedFlashingWithColorRed:(uint8_t)red green:(uint8_t)green blue:(uint8_t)blue timeOn:(uint8_t)timeOn timeOff:(uint8_t)timeOff;
-(void) getMipChestRGBLed;
-(void) setMipHeadLeds:(kMipHeadLedValue)led1 led2:(kMipHeadLedValue)led2 led3:(kMipHeadLedValue)led3 led4:(kMipHeadLedValue)led4;
-(void) getMipHeadLeds;

#pragma mark IR Transmitting Commands
-(void) mipTransmitIRGameDataWithGameType:(uint8_t)gameType mipId:(uint8_t)mipId gameData:(uint16_t)gameData powerDistanceCm:(uint8_t)powerDistanceCm;

#pragma mark Driving Commands
/** Drive MIP at speed and direction of given normalized vector.
 @param vector Normalized vector (-1 <= dx <= 1, -1 <= dy <= 1)
 */
- (void) mipDrive:(CGVector)vector;
 /** Added in firmware 03-09-01 #02 post production **/
- (void) mipCrazyDrive:(CGVector)vector;

/** Drive MIP a fixed distance and turn angle.
 @param distanceInCM Distance in centimeters (-55 <= distance <= 55). Giving a negitive distance makes MIP drive backwards.
 @param angleInDegrees Turn angle in degrees (65535 <= angle <= 65535). Negitive angle makes MIP turn left, Positive angle makes MIP turn right.
 */
- (void) mipDriveDistanceByCm:(int8_t)distanceInCM angleInDegrees:(int16_t)angleInDegrees;
/** Drive MIP a fixed distance straight.
 @param distanceInCM Distance in centimeters (-55 <= distance <= 55). Giving a negitive distance makes MIP drive backwards.
 */
- (void) mipDriveDistanceByCm:(int8_t)distanceInCM;
- (void) mipTurnLeftByDegrees:(uint16_t)degrees withSpeed: (uint8_t)speed;
- (void) mipTurnRightByDegrees:(uint16_t)degrees withSpeed: (uint8_t)speed;

- (void)mipDriveForwardForMilliseconds: (int)msecs withSpeed: (uint8_t)speed;
- (void)mipDriveBackwardForMilliseconds: (int)msecs withSpeed: (uint8_t)speed;

-(void) setMipProductActivated;


@end

#pragma mark - Delegate Callbacks
@protocol MipRobotDelegate <NSObject>
@optional
/** Connection Methods **/
-(void) MipDeviceReady:(MipRobot *)mip;
-(void) MipDeviceDisconnected:(MipRobot *)mip error:(NSError *)error;
-(void) MipDeviceFailedToConnect:(MipRobot *)mip error:(NSError *)error;
-(void) MipDeviceReconnecting:(MipRobot *)mip;
-(void) MipDeviceWentToSleep:(MipRobot *)mip batteryEmpty:(bool)batteryEmpty;

/** Commands Received **/
-(void) MipRobot:(MipRobot *)mip didReceiveSoftwareVersionDate:(NSDate *)softwareDate revisionNumber:(NSUInteger)revisionNumber;
-(void) MipRobot:(MipRobot *)mip didReceiveHardwareVersion:(NSNumber *)hardwareVersion voiceChipVersion:(NSNumber *)voiceChipVersion;
-(void) MipRobot:(MipRobot *)mip didReceiveVolumeLevel:(uint8_t)level;
-(void) MipRobot:(MipRobot *)mip didReceiveUserData:(NSArray *)userDataByteArray;
-(void) MipRobot:(MipRobot *)mip didReceiveIRRemoteEnabled:(bool)remoteEnabled;
-(void) didReceiveShakeWithMipRobot:(MipRobot *)mip;

-(void) MipRobot:(MipRobot *)mip didReceiveGameMode:(kMipGameModeValue)value;
-(void) MipRobot:(MipRobot *)mip didReceieveBatteryLevelReading:(NSUInteger)value;
-(void) MipRobot:(MipRobot *)mip didReceivePosition:(kMipPositionValue)value;
-(void) MipRobot:(MipRobot *)mip didReceiveWeightReading:(uint8_t)value learningForward:(bool)learningForward;

-(void) MipRobot:(MipRobot *)mip didReceiveOdometerReading:(unsigned int)value;
-(void) MipRobot:(MipRobot *)mip didReceiveChestRGBLedUpdateWithRed:(unsigned int)red green:(unsigned int)green blue:(unsigned int)blue fadeIn:(unsigned int)fadeIn;
-(void) MipRobot:(MipRobot *)mip didReceiveChestRGBLedUpdateWithRed:(unsigned int)red green:(unsigned int)green blue:(unsigned int)blue flashOn:(unsigned int)flashOn flashOff:(unsigned int)flashOff;
-(void) MipRobot:(MipRobot *)mip didRecieveHeadLedUpdateWithLed1:(kMipHeadLedValue)led1 led2:(kMipHeadLedValue)led2 led3:(kMipHeadLedValue)led3 led4:(kMipHeadLedValue)led4;

-(void) MipRobot:(MipRobot *)mip didReceiveGesture:(kMipGestureValue)value;
-(void) MipRobot:(MipRobot *)mip didReceiveGestureMode:(kMipGestureModeValue)value;

-(void) MipRobot:(MipRobot *)mip didReceiveRadarMode:(kMipRadarModeValue)mode;
-(void) MipRobot:(MipRobot *)mip didReceiveRadarResponse:(kMipRadarResponseValue)value;
-(void) MipRobot:(MipRobot *)mip didReceiveOtherMipDetectionModeOn:(bool)detectionOn;
-(void) MipRobot:(MipRobot *)mip didDetectOtherMip:(NSUInteger)mipId; // MipID current unused
-(void) MipRobot:(MipRobot *)mip isCurrentlyInBootloader:(bool)inBootloader;
-(void) MipRobot:(MipRobot *)mip didReceiveIRCommand:(NSArray *)irDataArray length:(NSUInteger)length;
-(void) MipRobot:(MipRobot *)mip didReceiveClapTimes:(uint8_t)clapTimes;

-(void) MipRobot:(MipRobot *)mip didReceiveNumberOfClaps:(NSUInteger)claptimes;
-(void) MipRobot:(MipRobot *)mip didReceiveClapDetectionStatusIsEnabled:(bool)isEnabled withMSTiming:(NSUInteger)milliseconds;
-(void) MipRobot:(MipRobot *)mip didReceiveHackerUartStatus:(kMipHackerUartConnectedStatus)status;

@end




