//
//  MiposaurRobot.h
//  Miposaur
//
//  Created by Forrest Chan on 2/1/15.
//  Copyright (c) 2015 WowWee Group Limited. All rights reserved.
//
@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "MiposaurRobotSound.h"
#import "BluetoothRobot.h"

static int ddLogLevel;

@class MiposaurEventManager;

@protocol MiposaurRobotDelegate;

FOUNDATION_EXPORT NSString *const MIPOSAUR_CONNECTED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const MIPOSAUR_DISCONNECTED_NOTIFICATION_NAME;

typedef NS_ENUM(NSInteger, MIPOSAURLogLevel) {
    MIPOSAURLogLevelDebug,
    MIPOSAURLogLevelErrors,
    MIPOSAURLogLevelNone
};



@interface MiposaurRobot : BluetoothRobot

@property (nonatomic, strong) MiposaurEventManager *eventManager;
@property (nonatomic, weak) id<MiposaurRobotDelegate> delegate;
@property (nonatomic, assign) kMiposaurMoodValue moodValue;
@property (nonatomic, readonly, assign) kMiposaurPingResponse bootMode;
@property (nonatomic, strong) NSDate *miposaurFirmwareVersionDate;
@property (nonatomic, assign) NSUInteger miposaurFirmwareVersionId;
@property (nonatomic, strong) NSNumber *miposaurVoiceFirmwareVersion;
@property (nonatomic, strong) NSNumber *miposaurHardwareVersion;
@property (nonatomic, assign) kMiposaurPositionValue position;
@property (nonatomic, assign) NSInteger batteryLevel;
@property (nonatomic, readonly, assign) kMiposaurActivationStatus toyActivationStatus;
@property (nonatomic, assign) NSInteger miposaurVolume;
@property (nonatomic, assign) bool disableReceivedCommandProcessing;
@property (nonatomic, assign) MIPOSAURLogLevel logLevel;

- (void)setPlayAnimation:(uint8_t)animationId soundValue:(kMiposaurAnimationEnableSoundValue)enableSound;
- (void)getDetectionMode;
- (void)setMiposaurMoodValue:(kMiposaurMoodValue)moodValue;

#pragma mark - Mipossur Protocal Methods
#pragma mark Device Commands
-(void) getMiposaurActivationStatus;
-(void) miposaurStop;
-(void) miposaurSleep;
-(void) setMiposaurVolumeLevel:(uint8_t)volumeLevel;
-(void) getMiposaurVolumeLevel;
-(void) readMiposaurHardwareVersion;
-(void) readMiposaurFirmwareVersion;


#pragma mark Sensor Controls

-(void) readMiposaurStatus;

#pragma mark Gameplay Commands
-(void) miposaurFalloverWithStyle:(kMiposaurPositionValue)position;

#pragma mark Sound Commands
- (void) miposaurPlaySound:(MiposaurRobotSound *)sound;


#pragma mark LED Commands
-(void) setMiposaurChestRGBLedWithColor:(UIColor *)color;
-(void) setMiposaurChestRGBLedWithColorRed:(uint8_t)red green:(uint8_t)green blue:(uint8_t)blue fadeInTime:(uint8_t)fadeIn;
-(void) setMiposaurChestRGBLedFlashingWithColor:(UIColor *)color timeOn:(uint8_t)timeOn timeOff:(uint8_t)timeOff;
-(void) setMiposaurChestRGBLedFlashingWithColorRed:(uint8_t)red green:(uint8_t)green blue:(uint8_t)blue timeOn:(uint8_t)timeOn timeOff:(uint8_t)timeOff;


#pragma mark IR Transmitting Commands
-(void) mipTransmitIRGameDataWithGameType:(uint8_t)gameType mipId:(uint8_t)mipId gameData:(uint16_t)gameData powerDistanceCm:(uint8_t)powerDistanceCm;

#pragma mark Driving Commands
- (void) miposaurDrive:(CGVector)vector;
- (void) miposaurDriveDistanceByCm:(int8_t)distanceInCM angleInDegrees:(int16_t)angleInDegrees;
- (void) miposaurDriveDistanceByCm:(int8_t)distanceInCM;
- (void) miposaurTurnLeftByDegrees:(uint16_t)degrees withSpeed: (uint8_t)speed;
- (void) miposaurTurnRightByDegrees:(uint16_t)degrees withSpeed: (uint8_t)speed;
- (void) miposaurDriveForwardForMilliseconds: (int)msecs withSpeed: (uint8_t)speed;
- (void) miposaurDriveBackwardForMilliseconds: (int)msecs withSpeed: (uint8_t)speed;
- (void) setMiposaurProductActivated;

#pragma mark Private Api Calls
#if defined(ENABLE_PRIVATE_API_CALLS) && ENABLE_PRIVATE_API_CALLS == 1
-(void) resetMiposaurActivation;
-(void) setMiposaurActivationHackerUploaded;
-(void) setMiposaurActivationProductUploaded;
-(void) miposaurDisconnectAppMode;
#endif

@end

@protocol MiposaurRobotDelegate <NSObject>
@optional
/** Connection Methods **/
-(void) MiposaurDeviceReady:(MiposaurRobot *)miposaur;
-(void) MiposaurDeviceDisconnected:(MiposaurRobot *)miposaur error:(NSError *)error;
-(void) MiposaurDeviceFailedToConnect:(MiposaurRobot *)miposaur error:(NSError *)error;
-(void) MiposaurDeviceReconnecting:(MiposaurRobot *)miposaur;
-(void) MiposaurDeviceWentToSleep:(MiposaurRobot *)miposaur batteryEmpty:(bool)batteryEmpty;

- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceivePlayAnaimation:(uint8_t)value;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveMoodValue:(kMiposaurMoodValue)moodValue;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveBatteryType:(kMiposaurBatteryType)moodValue;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveBallSituation1:(kMiposaurBallModeSituation)ballMode shaking:(kMiposaurBallModeShaking)shakingValue beam:(kMiposaurBallModeBeam)beamValue ballShort:(kMiposaurBallShortRange)ballShortValue clapTimes:(uint8_t)clapTimes ballSee:(kMiposaurBallSeeObject)ballSeeValue;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveBallSituation2:(uint8_t)range;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveBallSituation3:(uint8_t)range angleByZero:(uint8_t)angle angle:(uint8_t)angle;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didRecieveHeadLedWithEyeOn:(uint8_t)eyeOnTime eyeOff:(uint8_t)eyeOffTime eyeFlash:(uint8_t)eyeFlashTime;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveIRStatus:(kMiposaurSetGesture)value;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveDetectionModeWithIdValue:(uint8_t)idValue txPower:(uint8_t)txPower;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur didReceiveGestureRadarDetect:(kMiposaurGestureRadarDetectValue)value;
- (void) MiposaurRobot: (MiposaurRobot *)miposaur isCurrentlyInBootloader:(bool)inBootloader;


-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveSoftwareVersionDate:(NSDate *)softwareDate revisionNumber:(NSUInteger)revisionNumber;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveHardwareVersion:(NSNumber *)hardwareVersion voiceChipVersion:(NSNumber *)voiceChipVersion;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveVolumeLevel:(uint8_t)level;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveUserData:(NSArray *)userDataByteArray;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveIRRemoteEnabled:(bool)remoteEnabled;
-(void) didReceiveShakeWithMiposaurRobot:(MiposaurRobot *)miposaur;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceieveBatteryLevelReading:(NSUInteger)value;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceivePosition:(kMiposaurPositionValue)value;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveChestRGBLedUpdateWithRed:(unsigned int)red green:(unsigned int)green blue:(unsigned int)blue fadeIn:(unsigned int)fadeIn;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveChestRGBLedUpdateWithRed:(unsigned int)red green:(unsigned int)green blue:(unsigned int)blue flashOn:(unsigned int)flashOn flashOff:(unsigned int)flashOff;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveOtherMipDetectionModeOn:(bool)detectionOn;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didDetectOtherMip:(NSUInteger)mipId; // MipID current unused

-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveIRCommand:(NSArray *)irDataArray length:(NSUInteger)length;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveClapTimes:(uint8_t)clapTimes;

-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveNumberOfClaps:(NSUInteger)claptimes;
-(void) MiposaurRobot:(MiposaurRobot *)miposaur didReceiveHackerUartStatus:(kMiposaurHackerUartConnectedStatus)status;

@end