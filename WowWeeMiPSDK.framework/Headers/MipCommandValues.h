//
//  MIPCommands.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

FOUNDATION_EXPORT NSUInteger const MIP_BLUETOOTH_PRODUCT_ID;
FOUNDATION_EXPORT NSString *const MIP_BLUETOOTH_CUSTOM_DATA_IDENTIFIER;

typedef NS_OPTIONS(uint8_t, kMipCommand) {
    kMipSetIRRemoteEnabledDisabled = 0x10, // kMipSetIRRemoteValue
    kMipGetIRRemoteEnabledDisabled = 0x11,

    kMipSetRadarModeOrRadarResponse = 0x0C,
    kMipGetRadarMode = 0x0D,
    
    kMipSetDetectionModeOrDetectionResponse = 0x0E,
    kMipGetDetectionMode = 0x0F,
    
    kMipSetGestureModeOrGestureDetected = 0x0A,
    kMipGetGestureMode = 0x0B,
    
    kMipCheckBootmode = 0xFF,
    
    kMipShouldPowerOff = 0xFB,
    kMipReboot = 0xFB,
    kMipShouldSleep = 0xFA,
    kMipShouldDisconnectAppMode = 0xFE, // Let mip know we want to disconnect
    kMipShouldForceBLEDisconnect = 0xFC,
    
    kMipSetUserData = 0x12,
    kMipGetUserData = 0x13,
    
    kMipSetGameMode = 0x76,
    kMipGetGameMode = 0x78,
    
    kMipSetVolumeLevel = 0x15,
    kMipGetVolumeLevel = 0x16,
    
    kMipGetSoftwareVersion = 0x14,
    kMipGetHardwareVersion = 0x19,
    
    kMipShouldFallover = 0x08, // kMipShouldFalloverValue
    
    kMipPlaySound = 0x06, // kMipSoundFileValue
    
    kMipStop = 0x77,
    
    kMipShakeDetected = 0x1A,
    
    kMipGetOdometer = 0x85,
    kMipResetOdometer = 0x86,
    
    kMipGetStatus = 0x79,
    
    kMipGetWeightLevel = 0x81,
    
    kMipGetChestRGBLed = 0x83,
    kMipSetChestRGBLed = 0x84,
    kMipFlashChestRGBLed = 0x89,
    kMipSetHeadLed = 0x8A,
    kMipGetHeadLed = 0x8B,
    
    kMipTransmitIRCommand = 0x8C,
    kMipReceiveIRCommand = 0x03,
    
    // Checked from here above
    kMipDrive_Continuous = 0x78, /*
                                  Fw:0x00(slow)~-0x1F(fast)
                                  OR Bw:0x20(slow)~0x3F(fast)
                                  OR right spin:0x40(slow)~0x5F(fast)
                                  OR Left spin:0x60(slow)~0x7F(fast)
                                  */
    kMipDrive_FixedDistance = 0x70, /*
                                     Distance Drive	0x70	->MIP	4	Forward: 0X00 or Backward: 0X01
                                     Distance (cm): 0x00-0xFF
                                     Turn Clockwise: 0X00 or Anti-clockwise: 0X01
                                     Turn Angle: 0-180,0-180
                                     */
    kMipDriveForwardWithTime = 0x71,
    kMipDriveBackwardWithTime = 0x72,
    
    kTurnLeftByAngle = 0x73,
    kTurnRightByAngle = 0x74,
    
    kMipSetHackerUartMode = 0x01,
    kMipGetHackerUartMode = 0x02, // kMipHackerUartModeValue
    
    kMipSendWowWeeIRDongleCode = 0x8C,
    
    kMipClapsDetected = 0x1D,
    kMipGetClapDetectionStatus = 0x1E,
    kMipClapDetectionStatus = 0x1F,
    kMipSetClapDetectTiming = 0x20,
    
    kMipHackerUartConnectedStatusUpdated = 0x1C,
    kMipSetMipDetectionModeActivated = 0x0E,
    kMipGetMipDetectionMode = 0x0F,
    kMipOtherMipDetected = 0x04,
    
    kMipGetUpFromPosition = 0x23,
    
    kMipGetToyActivatedStatus = 0x21,
    kMipSetToyActivatedStatus = 0x22,
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMipGetLowPowerLevel = 0x27,
    kMipSetLowPowerLevel = 0x28,
    kMipPingOnOff = 0x24,
    kMipPingCommand = 0xF8,
    kMipiOSPingCommand = 0xF9,
    /** End firmware extras **/
};

typedef NS_OPTIONS(NSUInteger, kMipActivationStatus) {
    kMipActivation_FactoryDefault               = 0,        // => 00000000
    kMipActivation_Activate                     = (1 << 0), // => 00000001
    kMipActivation_ActivationSentToFlurry       = (1 << 1), // => 00000010
    kMipActivation_HackerUartUsed               = (1 << 2), // => 00000100
    kMipActivation_HackerUartUsedSentToFlurry   = (1 << 3), // => 00001000
};

typedef NS_OPTIONS(uint8_t, kMipResetMcu) {
    kMipResetMcu_NormalReset = 0x01,kMipResetMcu_ResetAndForceBootloader = 0x02,
    //kMipResetMcu_ResetAndClearFlash = 0x03,
};

typedef NS_OPTIONS(uint8_t, kMipHackerUartModeValue) {
    kMipHackerUartMode_BLEOnUartOff = 0x00,
    kMipHackerUartMode_BLEOnUartOn = 0x01,
    kMipHackerUartMode_BLEOffUartOn = 0x02
};

typedef NS_OPTIONS(uint8_t, kMipHackerUartConnectedStatus) {
    kMipHackerUartConnectedStatus_Connect = 0x00,
    kMipHackerUartConnectedStatus_Disconnect = 0x01,
};

typedef NS_OPTIONS(uint8_t, kMipRadarModeValue) {
    kMipRadarMode_Off = 0x00,
    kMipRadarMode_On = 0x04,
};

typedef NS_OPTIONS(uint8_t, kMipDetectionModeValue) {
    kMipDetectionMode_Off = 0x00,
};

typedef NS_OPTIONS(uint8_t, kMipRadarResponseValue) {
    kMipRadarResponseClear = 0x01,
    kMipRadarResponseObjectsIn30Cm = 0x02,
    kMipRadarResponseObjectsIn10Cm = 0x03,
};

typedef NS_OPTIONS(uint8_t, kMipGestureModeValue) {
    kMipGestureMode_Off = 0x00,
    kMipGestureMode_On = 0x02,
};

typedef NS_OPTIONS(uint8_t, kMipPunchStrengthValue) {
    kMipPunchStrength_1 = 0x01,
    kMipPunchStrength_2 = 0x02,
    kMipPunchStrength_3 = 0x03,
    kMipPunchStrength_4 = 0x04,
    kMipPunchStrength_5 = 0x05,
};

typedef NS_OPTIONS(uint8_t, kMipPositionValue) {
    kMipPositionOnBack = 0x00,
    kMipPositionFaceDown = 0x01,
    kMipPositionUpright = 0x02,
    kMipPositionPickedUp = 0x03,
    kMipPositionHandStand = 0x04,
    kMipPositionFaceDownTray = 0x05,
    kMipPositionBackWithKickstand = 0x06,
};

typedef NS_OPTIONS(uint8_t, kMipWeightLevelValue) {
    kMipWeightLevel_Min = 0x00,
    kMipWeightLevel_1 = 0x01,
    kMipWeightLevel_2 = 0x02,
    kMipWeightLevel_3 = 0x03,
    kMipWeightLevel_4 = 0x04,
    kMipWeightLevel_Max = 0x05
};

typedef NS_OPTIONS(uint8_t, kMipHeadLedValue) {
    kMipHeadLed_Off = 0x00,
    kMipHeadLed_On = 0x01,
    kMipHeadLed_BlinkSlow = 0x02,
    kMipHeadLed_BlinkFast = 0x03,
    kMipHeadLed_FadeIn = 0x04,
};

typedef NS_OPTIONS(uint8_t, kMipSetMipTrackObjectValue) {
    kMipSetMipTrackObject_Enabled = 0x00,
    kMipSetMipTrackObject_Disabled = 0x01,
};

typedef NS_OPTIONS(uint8_t, kMipSetIRRemoteValue) {
    kMipSetIRRemote_Enabled = 0x00,
    kMipSetIRRemote_Disabled = 0x01,
};

typedef NS_OPTIONS(uint8_t,kMipGameModeValue) {
    kMipGameMode_App = 0x00,
    kMipGameMode_Cage = 0x01,
    kMipGameMode_Tracking = 0x02,
    kMipGameMode_Dance = 0x03,
    kMipGameMode_DefaultMipMode = 0x04,
    kMipGameMode_Stack = 0x05,
    kMipGameMode_Trick = 0x06,
    kMipGameMode_RoamMode = 0x07,
};

// Checked above this line
typedef NS_OPTIONS(uint8_t, kMipDriveDirectionValue) {
    kMipDrive_TurnDirectionClockwise = 0x00,
    kMipDrive_TurnDirectionAnticlockwise = 0x01,
    kMipDrive_DriveDirectionForward = 0x00,
    kMipDrive_DriveDirectionBackward = 0x01,
};

typedef NS_OPTIONS(uint8_t, kMipGestureValue) {
    kMipGesture_Left = 0x0A,
    kMipGesture_Right = 0x0B,
    kMipGesture_SweepLeft = 0x0C,
    kMipGesture_SweepRight = 0x0D,
    kMipGesture_Hold = 0x0E
};

typedef NS_OPTIONS(uint8_t, kMipDriveContinuousValue) {
    kMipDriveCont_FW_Speed1 = 0x00, // Slowest
    kMipDriveCont_FW_Speed2,
    kMipDriveCont_FW_Speed3,
    kMipDriveCont_FW_Speed4,
    kMipDriveCont_FW_Speed5,
    kMipDriveCont_FW_Speed6,
    kMipDriveCont_FW_Speed7,
    kMipDriveCont_FW_Speed8,
    kMipDriveCont_FW_Speed9,
    kMipDriveCont_FW_Speed10,
    kMipDriveCont_FW_Speed11,
    kMipDriveCont_FW_Speed12,
    kMipDriveCont_FW_Speed13,
    kMipDriveCont_FW_Speed14,
    kMipDriveCont_FW_Speed15,
    kMipDriveCont_FW_Speed16,
    kMipDriveCont_FW_Speed17,
    kMipDriveCont_FW_Speed18,
    kMipDriveCont_FW_Speed19,
    kMipDriveCont_FW_Speed20,
    kMipDriveCont_FW_Speed21,
    kMipDriveCont_FW_Speed22,
    kMipDriveCont_FW_Speed23,
    kMipDriveCont_FW_Speed24,
    kMipDriveCont_FW_Speed25,
    kMipDriveCont_FW_Speed26,
    kMipDriveCont_FW_Speed27,
    kMipDriveCont_FW_Speed28,
    kMipDriveCont_FW_Speed29,
    kMipDriveCont_FW_Speed30,
    kMipDriveCont_FW_Speed31,
    kMipDriveCont_FW_Speed32, // Fastest
    
    kMipDriveCont_BW_Speed1 = 0x20, // Slowest
    kMipDriveCont_BW_Speed2,
    kMipDriveCont_BW_Speed3,
    kMipDriveCont_BW_Speed4,
    kMipDriveCont_BW_Speed5,
    kMipDriveCont_BW_Speed6,
    kMipDriveCont_BW_Speed7,
    kMipDriveCont_BW_Speed8,
    kMipDriveCont_BW_Speed9,
    kMipDriveCont_BW_Speed10,
    kMipDriveCont_BW_Speed11,
    kMipDriveCont_BW_Speed12,
    kMipDriveCont_BW_Speed13,
    kMipDriveCont_BW_Speed14,
    kMipDriveCont_BW_Speed15,
    kMipDriveCont_BW_Speed16,
    kMipDriveCont_BW_Speed17,
    kMipDriveCont_BW_Speed18,
    kMipDriveCont_BW_Speed19,
    kMipDriveCont_BW_Speed20,
    kMipDriveCont_BW_Speed21,
    kMipDriveCont_BW_Speed22,
    kMipDriveCont_BW_Speed23,
    kMipDriveCont_BW_Speed24,
    kMipDriveCont_BW_Speed25,
    kMipDriveCont_BW_Speed26,
    kMipDriveCont_BW_Speed27,
    kMipDriveCont_BW_Speed28,
    kMipDriveCont_BW_Speed29,
    kMipDriveCont_BW_Speed30,
    kMipDriveCont_BW_Speed31,
    kMipDriveCont_BW_Speed32, // Fastest
    
    kMipDriveCont_Left_Speed1 = 0x60, // Slowest
    kMipDriveCont_Left_Speed2,
    kMipDriveCont_Left_Speed3,
    kMipDriveCont_Left_Speed4,
    kMipDriveCont_Left_Speed5,
    kMipDriveCont_Left_Speed6,
    kMipDriveCont_Left_Speed7,
    kMipDriveCont_Left_Speed8,
    kMipDriveCont_Left_Speed9,
    kMipDriveCont_Left_Speed10,
    kMipDriveCont_Left_Speed11,
    kMipDriveCont_Left_Speed12,
    kMipDriveCont_Left_Speed13,
    kMipDriveCont_Left_Speed14,
    kMipDriveCont_Left_Speed15,
    kMipDriveCont_Left_Speed16,
    kMipDriveCont_Left_Speed17,
    kMipDriveCont_Left_Speed18,
    kMipDriveCont_Left_Speed19,
    kMipDriveCont_Left_Speed20,
    kMipDriveCont_Left_Speed21,
    kMipDriveCont_Left_Speed22,
    kMipDriveCont_Left_Speed23,
    kMipDriveCont_Left_Speed24,
    kMipDriveCont_Left_Speed25,
    kMipDriveCont_Left_Speed26,
    kMipDriveCont_Left_Speed27,
    kMipDriveCont_Left_Speed28,
    kMipDriveCont_Left_Speed29,
    kMipDriveCont_Left_Speed30,
    kMipDriveCont_Left_Speed31,
    kMipDriveCont_Left_Speed32, // Fastest
    /*
     OR right spin:0xE1(slow)~0xFF(fast)
     OR Left spin:0xC1(slow)~0xE0(fast
     */
    kMipDriveCont_Right_Speed1 = 0x40, // Slowest
    kMipDriveCont_Right_Speed2,
    kMipDriveCont_Right_Speed3,
    kMipDriveCont_Right_Speed4,
    kMipDriveCont_Right_Speed5,
    kMipDriveCont_Right_Speed6,
    kMipDriveCont_Right_Speed7,
    kMipDriveCont_Right_Speed8,
    kMipDriveCont_Right_Speed9,
    kMipDriveCont_Right_Speed10,
    kMipDriveCont_Right_Speed11,
    kMipDriveCont_Right_Speed12,
    kMipDriveCont_Right_Speed13,
    kMipDriveCont_Right_Speed14,
    kMipDriveCont_Right_Speed15,
    kMipDriveCont_Right_Speed16,
    kMipDriveCont_Right_Speed17,
    kMipDriveCont_Right_Speed18,
    kMipDriveCont_Right_Speed19,
    kMipDriveCont_Right_Speed20,
    kMipDriveCont_Right_Speed21,
    kMipDriveCont_Right_Speed22,
    kMipDriveCont_Right_Speed23,
    kMipDriveCont_Right_Speed24,
    kMipDriveCont_Right_Speed25,
    kMipDriveCont_Right_Speed26,
    kMipDriveCont_Right_Speed27,
    kMipDriveCont_Right_Speed28,
    kMipDriveCont_Right_Speed29,
    kMipDriveCont_Right_Speed30,
    kMipDriveCont_Right_Speed31,
    kMipDriveCont_Right_Speed32, // Fastest
    
     /** Added in firmware 03-09-01 #02 post production **/
    kMipDriveCont_CrazyFW_Speed1 = 0x80, // Crazy Forward Slowest
    kMipDriveCont_CrazyFW_Speed2,
    kMipDriveCont_CrazyFW_Speed3,
    kMipDriveCont_CrazyFW_Speed4,
    kMipDriveCont_CrazyFW_Speed5,
    kMipDriveCont_CrazyFW_Speed6,
    kMipDriveCont_CrazyFW_Speed7,
    kMipDriveCont_CrazyFW_Speed8,
    kMipDriveCont_CrazyFW_Speed9,
    kMipDriveCont_CrazyFW_Speed10,
    kMipDriveCont_CrazyFW_Speed11,
    kMipDriveCont_CrazyFW_Speed12,
    kMipDriveCont_CrazyFW_Speed13,
    kMipDriveCont_CrazyFW_Speed14,
    kMipDriveCont_CrazyFW_Speed15,
    kMipDriveCont_CrazyFW_Speed16,
    kMipDriveCont_CrazyFW_Speed17,
    kMipDriveCont_CrazyFW_Speed18,
    kMipDriveCont_CrazyFW_Speed19,
    kMipDriveCont_CrazyFW_Speed20,
    kMipDriveCont_CrazyFW_Speed21,
    kMipDriveCont_CrazyFW_Speed22,
    kMipDriveCont_CrazyFW_Speed23,
    kMipDriveCont_CrazyFW_Speed24,
    kMipDriveCont_CrazyFW_Speed25,
    kMipDriveCont_CrazyFW_Speed26,
    kMipDriveCont_CrazyFW_Speed27,
    kMipDriveCont_CrazyFW_Speed28,
    kMipDriveCont_CrazyFW_Speed29,
    kMipDriveCont_CrazyFW_Speed30,
    kMipDriveCont_CrazyFW_Speed31,
    kMipDriveCont_CrazyFW_Speed32, // Crazy Forward Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMipDriveCont_CrazyBW_Speed1 = 0xa0, // Crazy Backward Slowest
    kMipDriveCont_CrazyBW_Speed2,
    kMipDriveCont_CrazyBW_Speed3,
    kMipDriveCont_CrazyBW_Speed4,
    kMipDriveCont_CrazyBW_Speed5,
    kMipDriveCont_CrazyBW_Speed6,
    kMipDriveCont_CrazyBW_Speed7,
    kMipDriveCont_CrazyBW_Speed8,
    kMipDriveCont_CrazyBW_Speed9,
    kMipDriveCont_CrazyBW_Speed10,
    kMipDriveCont_CrazyBW_Speed11,
    kMipDriveCont_CrazyBW_Speed12,
    kMipDriveCont_CrazyBW_Speed13,
    kMipDriveCont_CrazyBW_Speed14,
    kMipDriveCont_CrazyBW_Speed15,
    kMipDriveCont_CrazyBW_Speed16,
    kMipDriveCont_CrazyBW_Speed17,
    kMipDriveCont_CrazyBW_Speed18,
    kMipDriveCont_CrazyBW_Speed19,
    kMipDriveCont_CrazyBW_Speed20,
    kMipDriveCont_CrazyBW_Speed21,
    kMipDriveCont_CrazyBW_Speed22,
    kMipDriveCont_CrazyBW_Speed23,
    kMipDriveCont_CrazyBW_Speed24,
    kMipDriveCont_CrazyBW_Speed25,
    kMipDriveCont_CrazyBW_Speed26,
    kMipDriveCont_CrazyBW_Speed27,
    kMipDriveCont_CrazyBW_Speed28,
    kMipDriveCont_CrazyBW_Speed29,
    kMipDriveCont_CrazyBW_Speed30,
    kMipDriveCont_CrazyBW_Speed31,
    kMipDriveCont_CrazyBW_Speed32, // Crazy Backward Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMipDriveCont_CrazyRight_Speed1 = 0xc0, // Slowest
    kMipDriveCont_CrazyRight_Speed2,
    kMipDriveCont_CrazyRight_Speed3,
    kMipDriveCont_CrazyRight_Speed4,
    kMipDriveCont_CrazyRight_Speed5,
    kMipDriveCont_CrazyRight_Speed6,
    kMipDriveCont_CrazyRight_Speed7,
    kMipDriveCont_CrazyRight_Speed8,
    kMipDriveCont_CrazyRight_Speed9,
    kMipDriveCont_CrazyRight_Speed10,
    kMipDriveCont_CrazyRight_Speed11,
    kMipDriveCont_CrazyRight_Speed12,
    kMipDriveCont_CrazyRight_Speed13,
    kMipDriveCont_CrazyRight_Speed14,
    kMipDriveCont_CrazyRight_Speed15,
    kMipDriveCont_CrazyRight_Speed16,
    kMipDriveCont_CrazyRight_Speed17,
    kMipDriveCont_CrazyRight_Speed18,
    kMipDriveCont_CrazyRight_Speed19,
    kMipDriveCont_CrazyRight_Speed20,
    kMipDriveCont_CrazyRight_Speed21,
    kMipDriveCont_CrazyRight_Speed22,
    kMipDriveCont_CrazyRight_Speed23,
    kMipDriveCont_CrazyRight_Speed24,
    kMipDriveCont_CrazyRight_Speed25,
    kMipDriveCont_CrazyRight_Speed26,
    kMipDriveCont_CrazyRight_Speed27,
    kMipDriveCont_CrazyRight_Speed28,
    kMipDriveCont_CrazyRight_Speed29,
    kMipDriveCont_CrazyRight_Speed30,
    kMipDriveCont_CrazyRight_Speed31,
    kMipDriveCont_CrazyRight_Speed32, // Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMipDriveCont_CrazyLeft_Speed1 = 0xe0, // Slowest
    kMipDriveCont_CrazyLeft_Speed2,
    kMipDriveCont_CrazyLeft_Speed3,
    kMipDriveCont_CrazyLeft_Speed4,
    kMipDriveCont_CrazyLeft_Speed5,
    kMipDriveCont_CrazyLeft_Speed6,
    kMipDriveCont_CrazyLeft_Speed7,
    kMipDriveCont_CrazyLeft_Speed8,
    kMipDriveCont_CrazyLeft_Speed9,
    kMipDriveCont_CrazyLeft_Speed10,
    kMipDriveCont_CrazyLeft_Speed11,
    kMipDriveCont_CrazyLeft_Speed12,
    kMipDriveCont_CrazyLeft_Speed13,
    kMipDriveCont_CrazyLeft_Speed14,
    kMipDriveCont_CrazyLeft_Speed15,
    kMipDriveCont_CrazyLeft_Speed16,
    kMipDriveCont_CrazyLeft_Speed17,
    kMipDriveCont_CrazyLeft_Speed18,
    kMipDriveCont_CrazyLeft_Speed19,
    kMipDriveCont_CrazyLeft_Speed20,
    kMipDriveCont_CrazyLeft_Speed21,
    kMipDriveCont_CrazyLeft_Speed22,
    kMipDriveCont_CrazyLeft_Speed23,
    kMipDriveCont_CrazyLeft_Speed24,
    kMipDriveCont_CrazyLeft_Speed25,
    kMipDriveCont_CrazyLeft_Speed26,
    kMipDriveCont_CrazyLeft_Speed27,
    kMipDriveCont_CrazyLeft_Speed28,
    kMipDriveCont_CrazyLeft_Speed29,
    kMipDriveCont_CrazyLeft_Speed30,
    kMipDriveCont_CrazyLeft_Speed31,
    kMipDriveCont_CrazyLeft_Speed32, // Fastest
};

// OLD DRIVING COMMANDS
/*
 0xE0~0xFF for Fw
 0xC0~0xDF for bw
 0xA0~0xBF for LT
 0x80~0x9F for RT
 */
typedef NS_OPTIONS(uint8_t, kMipOldDriveContOffset) {
    kMipOldDriveCont_FW_Offset = 0xDF,
    kMipOldDriveCont_BW_Offset = 0xBF,
    kMipOldDriveCont_Left_Offset = 0x9F,
    kMipOldDriveCont_Right_Offset = 0x7F,
};

typedef NS_OPTIONS(uint8_t, kMipSoundFileValue) {
    kMipSoundFile_ONEKHZ_500MS_8K16BIT  = (1+0),
    kMipSoundFile_ACTION_BURPING        = (1+1),
    kMipSoundFile_ACTION_DRINKING       = (1+2),
    kMipSoundFile_ACTION_EATING         = (1+3),
    kMipSoundFile_ACTION_FARTING_SHORT  = (1+4),
    kMipSoundFile_ACTION_OUT_OF_BREATH  = (1+5),
    kMipSoundFile_BOXING_PUNCHCONNECT_1 = (1+6),
    kMipSoundFile_BOXING_PUNCHCONNECT_2 = (1+7),
    kMipSoundFile_BOXING_PUNCHCONNECT_3 = (1+8),
    kMipSoundFile_FREESTYLE_TRACKING_1  = (1+9),
    kMipSoundFile_MIP_1                 = (1+10),
    kMipSoundFile_MIP_2                 = (1+11),
    kMipSoundFile_MIP_3                 = (1+12),
    kMipSoundFile_MIP_APP               = (1+13),
    kMipSoundFile_MIP_AWWW              = (1+14),
    kMipSoundFile_MIP_BIG_SHOT          = (1+15),
    kMipSoundFile_MIP_BLEH              = (1+16),
    kMipSoundFile_MIP_BOOM              = (1+17),
    kMipSoundFile_MIP_BYE               = (1+18),
    kMipSoundFile_MIP_CONVERSE_1        = (1+19),
    kMipSoundFile_MIP_CONVERSE_2        = (1+20),
    kMipSoundFile_MIP_DROP              = (1+21),
    kMipSoundFile_MIP_DUNNO             = (1+22),
    kMipSoundFile_MIP_FALL_OVER_1       = (1+23),
    kMipSoundFile_MIP_FALL_OVER_2       = (1+24),
    kMipSoundFile_MIP_FIGHT             = (1+25),
    kMipSoundFile_MIP_GAME              = (1+26),
    kMipSoundFile_MIP_GLOAT             = (1+27),
    kMipSoundFile_MIP_GO                = (1+28),
    kMipSoundFile_MIP_GOGOGO            = (1+29),
    kMipSoundFile_MIP_GRUNT_1           = (1+30),
    kMipSoundFile_MIP_GRUNT_2           = (1+31),
    kMipSoundFile_MIP_GRUNT_3           = (1+32),
    kMipSoundFile_MIP_HAHA_GOT_IT       = (1+33),
    kMipSoundFile_MIP_HI_CONFIDENT      = (1+34),
    kMipSoundFile_MIP_HI_NOT_SURE       = (1+35),
    kMipSoundFile_MIP_HI_SCARED         = (1+36),
    kMipSoundFile_MIP_HUH               = (1+37),
    kMipSoundFile_MIP_HUMMING_1         = (1+38),
    kMipSoundFile_MIP_HUMMING_2         = (1+39),
    kMipSoundFile_MIP_HURT              = (1+40),
    kMipSoundFile_MIP_HUUURGH           = (1+41),
    kMipSoundFile_MIP_IN_LOVE           = (1+42),
    kMipSoundFile_MIP_IT                = (1+43),
    kMipSoundFile_MIP_JOKE              = (1+44),
    kMipSoundFile_MIP_K                 = (1+45),
    kMipSoundFile_MIP_LOOP_1            = (1+46),
    kMipSoundFile_MIP_LOOP_2            = (1+47),
    kMipSoundFile_MIP_LOW_BATTERY       = (1+48),
    kMipSoundFile_MIP_MIPPEE            = (1+49),
    kMipSoundFile_MIP_MORE              = (1+50),
    kMipSoundFile_MIP_MUAH_HA           = (1+51),
    kMipSoundFile_MIP_MUSIC             = (1+52),
    kMipSoundFile_MIP_OBSTACLE          = (1+53),
    kMipSoundFile_MIP_OHOH              = (1+54),
    kMipSoundFile_MIP_OH_YEAH           = (1+55),
    kMipSoundFile_MIP_OOPSIE            = (1+56),
    kMipSoundFile_MIP_OUCH_1            = (1+57),
    kMipSoundFile_MIP_OUCH_2            = (1+58),
    kMipSoundFile_MIP_PLAY              = (1+59),
    kMipSoundFile_MIP_PUSH              = (1+60),
    kMipSoundFile_MIP_RUN               = (1+61),
    kMipSoundFile_MIP_SHAKE             = (1+62),
    kMipSoundFile_MIP_SIGH              = (1+63),
    kMipSoundFile_MIP_SINGING           = (1+64),
    kMipSoundFile_MIP_SNEEZE            = (1+65),
    kMipSoundFile_MIP_SNORE             = (1+66),
    kMipSoundFile_MIP_STACK             = (1+67),
    kMipSoundFile_MIP_SWIPE_1           = (1+68),
    kMipSoundFile_MIP_SWIPE_2           = (1+69),
    kMipSoundFile_MIP_TRICKS            = (1+70),
    kMipSoundFile_MIP_TRIIICK           = (1+71),
    kMipSoundFile_MIP_TRUMPET           = (1+72),
    kMipSoundFile_MIP_WAAAAA            = (1+73),
    kMipSoundFile_MIP_WAKEY             = (1+74),
    kMipSoundFile_MIP_WHEEE             = (1+75),
    kMipSoundFile_MIP_WHISTLING         = (1+76),
    kMipSoundFile_MIP_WHOAH             = (1+77),
    kMipSoundFile_MIP_WOO               = (1+78),
    kMipSoundFile_MIP_YEAH              = (1+79),
    kMipSoundFile_MIP_YEEESSS           = (1+80),
    kMipSoundFile_MIP_YO                = (1+81),
    kMipSoundFile_MIP_YUMMY             = (1+82),
    kMipSoundFile_MOOD_ACTIVATED        = (1+83),
    kMipSoundFile_MOOD_ANGRY            = (1+84),
    kMipSoundFile_MOOD_ANXIOUS          = (1+85),
    kMipSoundFile_MOOD_BORING           = (1+86),
    kMipSoundFile_MOOD_CRANKY           = (1+87),
    kMipSoundFile_MOOD_ENERGETIC        = (1+88),
    kMipSoundFile_MOOD_EXCITED          = (1+89),
    kMipSoundFile_MOOD_GIDDY            = (1+90),
    kMipSoundFile_MOOD_GRUMPY           = (1+91),
    kMipSoundFile_MOOD_HAPPY            = (1+92),
    kMipSoundFile_MOOD_IDEA             = (1+93),
    kMipSoundFile_MOOD_IMPATIENT        = (1+94),
    kMipSoundFile_MOOD_NICE             = (1+95),
    kMipSoundFile_MOOD_SAD              = (1+96),
    kMipSoundFile_MOOD_SHORT            = (1+97),
    kMipSoundFile_MOOD_SLEEPY           = (1+98),
    kMipSoundFile_MOOD_TIRED            = (1+99),
    kMipSoundFile_SOUND_BOOST           = (1+100),
    kMipSoundFile_SOUND_CAGE            = (1+101),
    kMipSoundFile_SOUND_GUNS            = (1+102),
    kMipSoundFile_SOUND_ZINGS           = (1+103),
    kMipSoundFile_SHORT_MUTE_FOR_STOP   = (1+104),
    kMipSoundFile_FREESTYLE_TRACKING_2  = (1+105),
};

typedef NS_OPTIONS(uint8_t, kMipPingResponse) {
    kMipPingResponseNormalRomNoBootloader = 0x00,
    kMipPingResponseNormalRomHasBootloader = 0x01,
    kMipPingResponseBootloader = 0x02
};

/**
 This is actually the custom data byte position starting from
 broadcast data byte 3. (First 2 bytes are product ID)
 */
typedef NS_OPTIONS(uint8_t, kMipBroadcastDataKey) {
    kMipBroadcastDataAvatarIcon = 0x00,
};

@interface MipCommandValues : NSObject

+(NSString *)batteryLevelChangedText:(int)value;
+(NSString *)positionChangedText:(kMipPositionValue)value;
+(NSString *)gestureText:(kMipGestureValue)value;
+(NSString *)headLedText:(kMipHeadLedValue)value;
+(NSString *)gameModeText:(kMipGameModeValue)value;

@end

