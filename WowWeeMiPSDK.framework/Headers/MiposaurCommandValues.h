//
//  MiposaurCommandValues.h
//  Miposaur
//
//  Created by Katy Pun on 13/3/15.
//  Copyright (c) 2015 WowWee Group Limited. All rights reserved.
//

//#import "MipCommandValues.h"
@import Foundation;

FOUNDATION_EXPORT NSUInteger const MIPOSAUR_BLUETOOTH_PRODUCT_ID;
FOUNDATION_EXPORT NSString *const MIPOSAUR_BLUETOOTH_CUSTOM_DATA_IDENTIFIER;

FOUNDATION_EXPORT NSUInteger const MIPOSAUR_BLUETOOTH_PRODUCT_DFU_ID;

typedef NS_OPTIONS(uint8_t, kMiposaurCommand) {
    kMiposaurPlayAnimation = 0x76,  //different
    kMiposaurGetStatus = 0x79,  //1 more byte
    kMiposaurClapDetectTiming = 0x20,   //not handle
    
    kMiposaurBallSituation1 = 0x09, //newly added
    kMiposaurBallSituation2 = 0x17,
    kMiposaurBallSituation3 = 0x15, //different
    
    kMiposaurSetHeadLed = 0x8A, //less 1 byte
    kMiposaurGetHeadLed = 0x8B, //less 1 byte
    
    
    kMiposaurGestureOrRadarMode = 0x0C,
    kMiposaurGetIRStatus = 0x0D,
    
    kMiposaurSetDetectionMode = 0x0E,
    kMiposaurGetDetectionMode = 0x0F,
    
    kMiposaurSetMood = 0x0B,
    kMiposaurGestureRadarDetect = 0x0A,
    
    kMiposaurShouldSleep = 0xFA,

    kMiposaurReboot = 0xFB,
    kMiposaurShouldDisconnectAppMode = 0xFE,
    
    
    
    
    kMiposaurCheckBootmode = 0xFF,

    
    // Checked from here above
    kMiposaurDrive_Continuous = 0x78, /*
                                  Fw:0x00(slow)~-0x1F(fast)
                                  OR Bw:0x20(slow)~0x3F(fast)
                                  OR right spin:0x40(slow)~0x5F(fast)
                                  OR Left spin:0x60(slow)~0x7F(fast)
                                  */
    kMiposaurDrive_FixedDistance = 0x70, /*
                                     Distance Drive	0x70	->MIP	4	Forward: 0X00 or Backward: 0X01
                                     Distance (cm): 0x00-0xFF
                                     Turn Clockwise: 0X00 or Anti-clockwise: 0X01
                                     Turn Angle: 0-180,0-180
                                     */
    kMiposaurDriveForwardWithTime = 0x71,
    kMiposaurDriveBackwardWithTime = 0x72,
    kMiposaurTurnLeftByAngle = 0x73,
    kMiposaurTurnRightByAngle = 0x74,
    
    kMiposaurPlaySound = 0x06, // kMipSoundFileValue
    
    kMiposaurShouldFallover = 0x08,
    
    kMiposaurShakeDetected = 0x1A,
    

    
    kMiposaurGetChestRGBLed = 0x83,
    kMiposaurSetChestRGBLed = 0x84,
    kMiposaurFlashChestRGBLed = 0x89,
    kMiposaurOtherMipDetected = 0x04,
    

    kMiposaurSetUserData = 0x12,
    kMiposaurGetUserData = 0x13,

    kMiposaurStop = 0x77,
    
    kMiposaurGetSoftwareVersion = 0x14,
    kMiposaurGetHardwareVersion = 0x19,

    kMiposaurTransmitIRCommand = 0x8C,

    
    kMiposaurReceiveIRCommand = 0x03,
    
    kMiposaurGetToyActivatedStatus = 0x21,
    kMiposaurSetToyActivatedStatus = 0x22,
    
    kMiposaurSetVolumeLevel = 0x18,
    kMiposaurGetVolumeLevel = 0x16,
};

typedef NS_OPTIONS(NSUInteger, kMiposaurActivationStatus) {
    kMiposaurActivation_FactoryDefault               = 0,        // => 00000000
    kMiposaurActivation_Activate                     = (1 << 0), // => 00000001
    kMiposaurActivation_ActivationSentToFlurry       = (1 << 1), // => 00000010
    kMiposaurActivation_HackerUartUsed               = (1 << 2), // => 00000100
    kMiposaurActivation_HackerUartUsedSentToFlurry   = (1 << 3), // => 00001000
};

typedef NS_OPTIONS(uint8_t, kMiposaurAnimationEnableSoundValue) {
    kMiposaurAnimationEnableSound = 0x00,
    kMiposaurAnimationDisableSound = 0x01
};

typedef NS_OPTIONS(uint8_t, kMiposaurMoodValue) {
    kMiposaurMoodAnnoyed = 0x00,
    kMiposaurMoodCurious = 0x01,
    kMiposaurMoodExcited = 0x02,
};
typedef NS_OPTIONS(uint8_t, kMiposaurHackerUartConnectedStatus) {
    kMiposaurHackerUartConnectedStatus_Connect = 0x00,
    kMiposaurHackerUartConnectedStatus_Disconnect = 0x01,
};
typedef NS_OPTIONS(uint8_t, kMiposaurBallModeSituation){
    kMiposaurBallDanceMode = 0x01,
    kMiposaurBallMeatMode = 0x02,
    kMiposaurBallTeddyBearMode = 0x03,
    kMiposaurBallMode = 0x04,
    kMiposaurBallLeashMode = 0x05,
    kMiposaurBallNestMode = 0x06
};

typedef NS_OPTIONS(uint8_t, kMiposaurBallModeShaking) {
    kMiposaurBallShakeAsStanding = 0x01,
    kMiposaurBallShakeAsSitting = 0x02
};

typedef NS_OPTIONS(uint8_t, kMiposaurBallModeBeam) {
    kMiposaurBallBeamOff = 0x01
};

typedef NS_OPTIONS(uint8_t, kMiposaurBallShortRange) {
    kMiposaurBallShortRangeAsStanding = 0x01,
    kMiposaurBallShortRangeAsSitting = 0x02
};

typedef NS_OPTIONS(uint8_t, kMiposaurBallSeeObject) {
    kMiposaurBallSeeObjectOnLeft = 0x01,
    kMiposaurBallSeeObjectOnCenter = 0x02,
    kMiposaurBallSeeObjectOnRight = 0x03
};

typedef NS_OPTIONS(uint8_t, kMiposaurRadarModeValue) {
    kMiposaurRadarMode_Off = 0x00,
    kMiposaurRadarMode_On = 0x04,
};

typedef NS_OPTIONS(uint8_t, kMiposaurSetGesture) {
    kMiposaurSetGestureOrRadarIdle = 0x00,
    kMiposaurDisableGestureRadar = 0x01,
    kMiposaurSetGestureEnable = 0x02,
    kMiposaurSetRadarEnable = 0x03
    
};
typedef NS_OPTIONS(uint8_t, kMiposaurHeadLedValue) {
    kMiposaurHeadLed_Off = 0x00,
    kMiposaurHeadLed_On = 0x01,
    kMiposaurHeadLed_BlinkSlow = 0x02,
    kMiposaurHeadLed_BlinkFast = 0x03,
    kMiposaurHeadLed_FadeIn = 0x04,
};
typedef NS_OPTIONS(uint8_t, kMiposaurGestureRadarDetectValue) {
    kMiposuarGestureDetectSwipeFrontLR = 0x01,
    kMiposuarGestureDetectSwipeFrontRL = 0x02,
    kMiposuarGestureDetectSwipeAroundLRB = 0x03,
    kMiposuarGestureDetectSwipeAroundRLB = 0x04,
    kMiposuarGestureDetectHoldFrontAndBack = 0x05,
    kMiposuarGestureDetectFrontTowards = 0x06,
    kMiposuarGestureDetectBackTowards = 0x07,
    kMiposuarGestureDetectPulled = 0x08,
    kMiposuarGestureDetectPushed = 0x09,
    kMiposuarGestureDetectSeatedBackward = 0x0A,
    kMiposuarGestureDetectSeatedLeft = 0x0B,
    kMiposuarGestureDetectSeatedRight = 0x0C,
    kMiposuarGestureDetectSeatedCenter = 0x0D
};

typedef NS_OPTIONS(uint8_t, kMiposaurResetMcu) {
    kMiposaurResetIntoBootloader = 0x01,
    kMiposaurResetIntoBootloaderWriteFlash = 0x02,
    //kMipResetMcu_ResetAndClearFlash = 0x03,
};

typedef NS_OPTIONS(uint8_t, kMiposaurPositionValue) {
    kMiposaurPositionOnFontCantGetup = 0x00,
    kMiposaurPositionOnFront = 0x01,
    kMiposaurPositionUpright = 0x02,
    kMiposaurPositionOnBack = 0x03,
    kMiposaurPositionSleepingPos = 0x09,
    kMiposaurPositionPickedUp = 0x07,
};
/*
 typedef NS_OPTIONS(uint8_t, kMipPositionValue) {
 kMipPositionOnBack = 0x00,
 kMipPositionFaceDown = 0x01,
 kMipPositionUpright = 0x02,
 kMipPositionPickedUp = 0x03,
 kMipPositionHandStand = 0x04,
 kMipPositionFaceDownTray = 0x05,
 kMipPositionBackWithKickstand = 0x06,
 };
 */


typedef NS_OPTIONS(uint8_t, kMiposaurBatteryType){
    kMiposaurBatteryNormal = 0x00,
    kMiposaurBatteryRechargeable = 0x01,
};

typedef NS_OPTIONS(uint8_t,kSnappetRebootMode) {

    kMiposaurRebootDFU = 0x02,
};

typedef NS_OPTIONS(uint8_t, kMiposaurDriveDirectionValue) {
    kMiposaurDrive_TurnDirectionClockwise = 0x00,
    kMiposaurDrive_TurnDirectionAnticlockwise = 0x01,
    kMiposaurDrive_DriveDirectionForward = 0x00,
    kMiposaurDrive_DriveDirectionBackward = 0x01,
};


typedef NS_OPTIONS(uint8_t, kMiposaurDriveContinuousValue) {
    kMiposaurDriveCont_FW_Speed1 = 0x00, // Slowest
    kMiposaurDriveCont_FW_Speed2,
    kMiposaurDriveCont_FW_Speed3,
    kMiposaurDriveCont_FW_Speed4,
    kMiposaurDriveCont_FW_Speed5,
    kMiposaurDriveCont_FW_Speed6,
    kMiposaurDriveCont_FW_Speed7,
    kMiposaurDriveCont_FW_Speed8,
    kMiposaurDriveCont_FW_Speed9,
    kMiposaurDriveCont_FW_Speed10,
    kMiposaurDriveCont_FW_Speed11,
    kMiposaurDriveCont_FW_Speed12,
    kMiposaurDriveCont_FW_Speed13,
    kMiposaurDriveCont_FW_Speed14,
    kMiposaurDriveCont_FW_Speed15,
    kMiposaurDriveCont_FW_Speed16,
    kMiposaurDriveCont_FW_Speed17,
    kMiposaurDriveCont_FW_Speed18,
    kMiposaurDriveCont_FW_Speed19,
    kMiposaurDriveCont_FW_Speed20,
    kMiposaurDriveCont_FW_Speed21,
    kMiposaurDriveCont_FW_Speed22,
    kMiposaurDriveCont_FW_Speed23,
    kMiposaurDriveCont_FW_Speed24,
    kMiposaurDriveCont_FW_Speed25,
    kMiposaurDriveCont_FW_Speed26,
    kMiposaurDriveCont_FW_Speed27,
    kMiposaurDriveCont_FW_Speed28,
    kMiposaurDriveCont_FW_Speed29,
    kMiposaurDriveCont_FW_Speed30,
    kMiposaurDriveCont_FW_Speed31,
    kMiposaurDriveCont_FW_Speed32, // Fastest
    
    kMiposaurDriveCont_BW_Speed1 = 0x20, // Slowest
    kMiposaurDriveCont_BW_Speed2,
    kMiposaurDriveCont_BW_Speed3,
    kMiposaurDriveCont_BW_Speed4,
    kMiposaurDriveCont_BW_Speed5,
    kMiposaurDriveCont_BW_Speed6,
    kMiposaurDriveCont_BW_Speed7,
    kMiposaurDriveCont_BW_Speed8,
    kMiposaurDriveCont_BW_Speed9,
    kMiposaurDriveCont_BW_Speed10,
    kMiposaurDriveCont_BW_Speed11,
    kMiposaurDriveCont_BW_Speed12,
    kMiposaurDriveCont_BW_Speed13,
    kMiposaurDriveCont_BW_Speed14,
    kMiposaurDriveCont_BW_Speed15,
    kMiposaurDriveCont_BW_Speed16,
    kMiposaurDriveCont_BW_Speed17,
    kMiposaurDriveCont_BW_Speed18,
    kMiposaurDriveCont_BW_Speed19,
    kMiposaurDriveCont_BW_Speed20,
    kMiposaurDriveCont_BW_Speed21,
    kMiposaurDriveCont_BW_Speed22,
    kMiposaurDriveCont_BW_Speed23,
    kMiposaurDriveCont_BW_Speed24,
    kMiposaurDriveCont_BW_Speed25,
    kMiposaurDriveCont_BW_Speed26,
    kMiposaurDriveCont_BW_Speed27,
    kMiposaurDriveCont_BW_Speed28,
    kMiposaurDriveCont_BW_Speed29,
    kMiposaurDriveCont_BW_Speed30,
    kMiposaurDriveCont_BW_Speed31,
    kMiposaurDriveCont_BW_Speed32, // Fastest
    
    kMiposaurDriveCont_Left_Speed1 = 0x60, // Slowest
    kMiposaurDriveCont_Left_Speed2,
    kMiposaurDriveCont_Left_Speed3,
    kMiposaurDriveCont_Left_Speed4,
    kMiposaurDriveCont_Left_Speed5,
    kMiposaurDriveCont_Left_Speed6,
    kMiposaurDriveCont_Left_Speed7,
    kMiposaurDriveCont_Left_Speed8,
    kMiposaurDriveCont_Left_Speed9,
    kMiposaurDriveCont_Left_Speed10,
    kMiposaurDriveCont_Left_Speed11,
    kMiposaurDriveCont_Left_Speed12,
    kMiposaurDriveCont_Left_Speed13,
    kMiposaurDriveCont_Left_Speed14,
    kMiposaurDriveCont_Left_Speed15,
    kMiposaurDriveCont_Left_Speed16,
    kMiposaurDriveCont_Left_Speed17,
    kMiposaurDriveCont_Left_Speed18,
    kMiposaurDriveCont_Left_Speed19,
    kMiposaurDriveCont_Left_Speed20,
    kMiposaurDriveCont_Left_Speed21,
    kMiposaurDriveCont_Left_Speed22,
    kMiposaurDriveCont_Left_Speed23,
    kMiposaurDriveCont_Left_Speed24,
    kMiposaurDriveCont_Left_Speed25,
    kMiposaurDriveCont_Left_Speed26,
    kMiposaurDriveCont_Left_Speed27,
    kMiposaurDriveCont_Left_Speed28,
    kMiposaurDriveCont_Left_Speed29,
    kMiposaurDriveCont_Left_Speed30,
    kMiposaurDriveCont_Left_Speed31,
    kMiposaurDriveCont_Left_Speed32, // Fastest
    /*
     OR right spin:0xE1(slow)~0xFF(fast)
     OR Left spin:0xC1(slow)~0xE0(fast
     */
    kMiposaurDriveCont_Right_Speed1 = 0x40, // Slowest
    kMiposaurDriveCont_Right_Speed2,
    kMiposaurDriveCont_Right_Speed3,
    kMiposaurDriveCont_Right_Speed4,
    kMiposaurDriveCont_Right_Speed5,
    kMiposaurDriveCont_Right_Speed6,
    kMiposaurDriveCont_Right_Speed7,
    kMiposaurDriveCont_Right_Speed8,
    kMiposaurDriveCont_Right_Speed9,
    kMiposaurDriveCont_Right_Speed10,
    kMiposaurDriveCont_Right_Speed11,
    kMiposaurDriveCont_Right_Speed12,
    kMiposaurDriveCont_Right_Speed13,
    kMiposaurDriveCont_Right_Speed14,
    kMiposaurDriveCont_Right_Speed15,
    kMiposaurDriveCont_Right_Speed16,
    kMiposaurDriveCont_Right_Speed17,
    kMiposaurDriveCont_Right_Speed18,
    kMiposaurDriveCont_Right_Speed19,
    kMiposaurDriveCont_Right_Speed20,
    kMiposaurDriveCont_Right_Speed21,
    kMiposaurDriveCont_Right_Speed22,
    kMiposaurDriveCont_Right_Speed23,
    kMiposaurDriveCont_Right_Speed24,
    kMiposaurDriveCont_Right_Speed25,
    kMiposaurDriveCont_Right_Speed26,
    kMiposaurDriveCont_Right_Speed27,
    kMiposaurDriveCont_Right_Speed28,
    kMiposaurDriveCont_Right_Speed29,
    kMiposaurDriveCont_Right_Speed30,
    kMiposaurDriveCont_Right_Speed31,
    kMiposaurDriveCont_Right_Speed32, // Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMiposaurDriveCont_CrazyFW_Speed1 = 0x80, // Crazy Forward Slowest
    kMiposaurDriveCont_CrazyFW_Speed2,
    kMiposaurDriveCont_CrazyFW_Speed3,
    kMiposaurDriveCont_CrazyFW_Speed4,
    kMiposaurDriveCont_CrazyFW_Speed5,
    kMiposaurDriveCont_CrazyFW_Speed6,
    kMiposaurDriveCont_CrazyFW_Speed7,
    kMiposaurDriveCont_CrazyFW_Speed8,
    kMiposaurDriveCont_CrazyFW_Speed9,
    kMiposaurDriveCont_CrazyFW_Speed10,
    kMiposaurDriveCont_CrazyFW_Speed11,
    kMiposaurDriveCont_CrazyFW_Speed12,
    kMiposaurDriveCont_CrazyFW_Speed13,
    kMiposaurDriveCont_CrazyFW_Speed14,
    kMiposaurDriveCont_CrazyFW_Speed15,
    kMiposaurDriveCont_CrazyFW_Speed16,
    kMiposaurDriveCont_CrazyFW_Speed17,
    kMiposaurDriveCont_CrazyFW_Speed18,
    kMiposaurDriveCont_CrazyFW_Speed19,
    kMiposaurDriveCont_CrazyFW_Speed20,
    kMiposaurDriveCont_CrazyFW_Speed21,
    kMiposaurDriveCont_CrazyFW_Speed22,
    kMiposaurDriveCont_CrazyFW_Speed23,
    kMiposaurDriveCont_CrazyFW_Speed24,
    kMiposaurDriveCont_CrazyFW_Speed25,
    kMiposaurDriveCont_CrazyFW_Speed26,
    kMiposaurDriveCont_CrazyFW_Speed27,
    kMiposaurDriveCont_CrazyFW_Speed28,
    kMiposaurDriveCont_CrazyFW_Speed29,
    kMiposaurDriveCont_CrazyFW_Speed30,
    kMiposaurDriveCont_CrazyFW_Speed31,
    kMiposaurDriveCont_CrazyFW_Speed32, // Crazy Forward Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMiposaurDriveCont_CrazyBW_Speed1 = 0xa0, // Crazy Backward Slowest
    kMiposaurDriveCont_CrazyBW_Speed2,
    kMiposaurDriveCont_CrazyBW_Speed3,
    kMiposaurDriveCont_CrazyBW_Speed4,
    kMiposaurDriveCont_CrazyBW_Speed5,
    kMiposaurDriveCont_CrazyBW_Speed6,
    kMiposaurDriveCont_CrazyBW_Speed7,
    kMiposaurDriveCont_CrazyBW_Speed8,
    kMiposaurDriveCont_CrazyBW_Speed9,
    kMiposaurDriveCont_CrazyBW_Speed10,
    kMiposaurDriveCont_CrazyBW_Speed11,
    kMiposaurDriveCont_CrazyBW_Speed12,
    kMiposaurDriveCont_CrazyBW_Speed13,
    kMiposaurDriveCont_CrazyBW_Speed14,
    kMiposaurDriveCont_CrazyBW_Speed15,
    kMiposaurDriveCont_CrazyBW_Speed16,
    kMiposaurDriveCont_CrazyBW_Speed17,
    kMiposaurDriveCont_CrazyBW_Speed18,
    kMiposaurDriveCont_CrazyBW_Speed19,
    kMiposaurDriveCont_CrazyBW_Speed20,
    kMiposaurDriveCont_CrazyBW_Speed21,
    kMiposaurDriveCont_CrazyBW_Speed22,
    kMiposaurDriveCont_CrazyBW_Speed23,
    kMiposaurDriveCont_CrazyBW_Speed24,
    kMiposaurDriveCont_CrazyBW_Speed25,
    kMiposaurDriveCont_CrazyBW_Speed26,
    kMiposaurDriveCont_CrazyBW_Speed27,
    kMiposaurDriveCont_CrazyBW_Speed28,
    kMiposaurDriveCont_CrazyBW_Speed29,
    kMiposaurDriveCont_CrazyBW_Speed30,
    kMiposaurDriveCont_CrazyBW_Speed31,
    kMiposaurDriveCont_CrazyBW_Speed32, // Crazy Backward Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMiposaurDriveCont_CrazyRight_Speed1 = 0xc0, // Slowest
    kMiposaurDriveCont_CrazyRight_Speed2,
    kMiposaurDriveCont_CrazyRight_Speed3,
    kMiposaurDriveCont_CrazyRight_Speed4,
    kMiposaurDriveCont_CrazyRight_Speed5,
    kMiposaurDriveCont_CrazyRight_Speed6,
    kMiposaurDriveCont_CrazyRight_Speed7,
    kMiposaurDriveCont_CrazyRight_Speed8,
    kMiposaurDriveCont_CrazyRight_Speed9,
    kMiposaurDriveCont_CrazyRight_Speed10,
    kMiposaurDriveCont_CrazyRight_Speed11,
    kMiposaurDriveCont_CrazyRight_Speed12,
    kMiposaurDriveCont_CrazyRight_Speed13,
    kMiposaurDriveCont_CrazyRight_Speed14,
    kMiposaurDriveCont_CrazyRight_Speed15,
    kMiposaurDriveCont_CrazyRight_Speed16,
    kMiposaurDriveCont_CrazyRight_Speed17,
    kMiposaurDriveCont_CrazyRight_Speed18,
    kMiposaurDriveCont_CrazyRight_Speed19,
    kMiposaurDriveCont_CrazyRight_Speed20,
    kMiposaurDriveCont_CrazyRight_Speed21,
    kMiposaurDriveCont_CrazyRight_Speed22,
    kMiposaurDriveCont_CrazyRight_Speed23,
    kMiposaurDriveCont_CrazyRight_Speed24,
    kMiposaurDriveCont_CrazyRight_Speed25,
    kMiposaurDriveCont_CrazyRight_Speed26,
    kMiposaurDriveCont_CrazyRight_Speed27,
    kMiposaurDriveCont_CrazyRight_Speed28,
    kMiposaurDriveCont_CrazyRight_Speed29,
    kMiposaurDriveCont_CrazyRight_Speed30,
    kMiposaurDriveCont_CrazyRight_Speed31,
    kMiposaurDriveCont_CrazyRight_Speed32, // Fastest
    
    /** Added in firmware 03-09-01 #02 post production **/
    kMiposaurDriveCont_CrazyLeft_Speed1 = 0xe0, // Slowest
    kMiposaurDriveCont_CrazyLeft_Speed2,
    kMiposaurDriveCont_CrazyLeft_Speed3,
    kMiposaurDriveCont_CrazyLeft_Speed4,
    kMiposaurDriveCont_CrazyLeft_Speed5,
    kMiposaurDriveCont_CrazyLeft_Speed6,
    kMiposaurDriveCont_CrazyLeft_Speed7,
    kMiposaurDriveCont_CrazyLeft_Speed8,
    kMiposaurDriveCont_CrazyLeft_Speed9,
    kMiposaurDriveCont_CrazyLeft_Speed10,
    kMiposaurDriveCont_CrazyLeft_Speed11,
    kMiposaurDriveCont_CrazyLeft_Speed12,
    kMiposaurDriveCont_CrazyLeft_Speed13,
    kMiposaurDriveCont_CrazyLeft_Speed14,
    kMiposaurDriveCont_CrazyLeft_Speed15,
    kMiposaurDriveCont_CrazyLeft_Speed16,
    kMiposaurDriveCont_CrazyLeft_Speed17,
    kMiposaurDriveCont_CrazyLeft_Speed18,
    kMiposaurDriveCont_CrazyLeft_Speed19,
    kMiposaurDriveCont_CrazyLeft_Speed20,
    kMiposaurDriveCont_CrazyLeft_Speed21,
    kMiposaurDriveCont_CrazyLeft_Speed22,
    kMiposaurDriveCont_CrazyLeft_Speed23,
    kMiposaurDriveCont_CrazyLeft_Speed24,
    kMiposaurDriveCont_CrazyLeft_Speed25,
    kMiposaurDriveCont_CrazyLeft_Speed26,
    kMiposaurDriveCont_CrazyLeft_Speed27,
    kMiposaurDriveCont_CrazyLeft_Speed28,
    kMiposaurDriveCont_CrazyLeft_Speed29,
    kMiposaurDriveCont_CrazyLeft_Speed30,
    kMiposaurDriveCont_CrazyLeft_Speed31,
    kMiposaurDriveCont_CrazyLeft_Speed32, // Fastest
};


typedef NS_OPTIONS(uint8_t, kMiposaurSoundFileValue) {
    kMiposaurSoundFile_A3400_34K_ONEKHZ_500MS_8K16BIT   = (1+0),
    kMiposaurSoundFile_A3400_34K_SHORT_MUTE_FOR_STOP    = (1+1),
    kMiposaurSoundFile_DINO_ANGRY_1_A34                 = (1+2),
    kMiposaurSoundFile_DINO_APPMODE_1                   = (1+3),
    kMiposaurSoundFile_DINO_BALL                        = (1+4),
    kMiposaurSoundFile_DINO_BALLSQUEAK_1                = (1+5),
    kMiposaurSoundFile_DINO_BALLSQUEAK_3                = (1+6),
    kMiposaurSoundFile_DINO_BARK_1                      = (1+7),
    kMiposaurSoundFile_DINO_BARK_2                      = (1+8),
    kMiposaurSoundFile_DINO_BATTLECRY_1                 = (1+9),
    kMiposaurSoundFile_DINO_BATTLECRY_2                 = (1+10),
    kMiposaurSoundFile_DINO_BEATBOX_1                   = (1+11),
    kMiposaurSoundFile_DINO_BEATBOX_6                   = (1+12),
    kMiposaurSoundFile_DINO_BIG_MOVEMENT_1              = (1+13),
    kMiposaurSoundFile_DINO_BOING_SITTING_2             = (1+14),
    kMiposaurSoundFile_DINO_BOOSTER_1                   = (1+15),
    kMiposaurSoundFile_DINO_BORED_1                     = (1+16),
    kMiposaurSoundFile_DINO_BURPING_1                   = (1+17),
    kMiposaurSoundFile_DINO_BURPING_2                   = (1+18),
    kMiposaurSoundFile_DINO_BYE_1                       = (1+19),
    kMiposaurSoundFile_DINO_CONFUSE_1                   = (1+20),
    kMiposaurSoundFile_DINO_CONFUSE_2                   = (1+21),
    kMiposaurSoundFile_DINO_CONVO_1                     = (1+22),
    kMiposaurSoundFile_DINO_CONVO_2                     = (1+23),
    kMiposaurSoundFile_DINO_COUGH_1                     = (1+24),
    kMiposaurSoundFile_DINO_CRANKY_1                    = (1+25),
    kMiposaurSoundFile_DINO_CRY_1                       = (1+26),
    kMiposaurSoundFile_DINO_CURIOUS_1                   = (1+27),
    kMiposaurSoundFile_DINO_DEMO                        = (1+28),
    kMiposaurSoundFile_DINO_DISSAPOINT_1                = (1+29),
    kMiposaurSoundFile_DINO_DIZZY_1                     = (1+30),
    kMiposaurSoundFile_DINO_EATING_1                    = (1+31),
    kMiposaurSoundFile_DINO_EATING_2                    = (1+32),
    kMiposaurSoundFile_DINO_ENERGETIC_1                 = (1+33),
    kMiposaurSoundFile_DINO_EXCITED_1                   = (1+34),
    kMiposaurSoundFile_DINO_EXCITED_WOOHOO_2            = (1+35),
    kMiposaurSoundFile_DINO_EXCITED_YIPPIE_1            = (1+36),
    kMiposaurSoundFile_DINO_FART_1                      = (1+37),
    kMiposaurSoundFile_DINO_GROWL_1                     = (1+38),
    kMiposaurSoundFile_DINO_GROWL_2                     = (1+39),
    kMiposaurSoundFile_DINO_GRUMPY_1                    = (1+40),
    kMiposaurSoundFile_DINO_GRUNT_1                     = (1+41),
    kMiposaurSoundFile_DINO_GRUNT_2                     = (1+42),
    kMiposaurSoundFile_DINO_GRUNT_3                     = (1+43),
    kMiposaurSoundFile_DINO_GULP_1                      = (1+44),
    kMiposaurSoundFile_DINO_GULP_2                      = (1+45),
    kMiposaurSoundFile_DINO_HAPPY_1                     = (1+46),
    kMiposaurSoundFile_DINO_HUM_1                       = (1+47),
    kMiposaurSoundFile_DINO_HUM_2                       = (1+48),
    kMiposaurSoundFile_DINO_HUNGRY_1                    = (1+49),
    kMiposaurSoundFile_DINO_IDEA_1                      = (1+50),
    kMiposaurSoundFile_DINO_INLOVE_1                    = (1+51),
    kMiposaurSoundFile_DINO_INLOVE_2                    = (1+52),
    kMiposaurSoundFile_DINO_LAUGH_1                     = (1+53),
    kMiposaurSoundFile_DINO_LAUGH_2                     = (1+54),
    kMiposaurSoundFile_DINO_LOVEYOU_1                   = (1+55),
    kMiposaurSoundFile_DINO_LOWBATTERY_1                = (1+56),
    kMiposaurSoundFile_DINO_MEAT                        = (1+57),
    kMiposaurSoundFile_DINO_MIPOSAUR_1                  = (1+58),
    kMiposaurSoundFile_DINO_MUFFLE_1                    = (1+59),
    kMiposaurSoundFile_DINO_MUSIC_1                     = (1+60),
    kMiposaurSoundFile_DINO_NICE_1                      = (1+61),
    kMiposaurSoundFile_DINO_OHOH_1                      = (1+62),
    kMiposaurSoundFile_DINO_OOPS_1                      = (1+63),
    kMiposaurSoundFile_DINO_PANT_1                      = (1+64),
    kMiposaurSoundFile_DINO_PANT_2                      = (1+65),
    kMiposaurSoundFile_DINO_PEWPEW_1                    = (1+66),
    kMiposaurSoundFile_DINO_PURR_1                      = (1+67),
    kMiposaurSoundFile_DINO_ROAR_1                      = (1+68),
    kMiposaurSoundFile_DINO_ROAR_2                      = (1+69),
    kMiposaurSoundFile_DINO_ROAR_3                      = (1+70),
    kMiposaurSoundFile_DINO_SNEEZE_1                    = (1+71),
    kMiposaurSoundFile_DINO_SNIFF_1                     = (1+72),
    kMiposaurSoundFile_DINO_SNIFF_2                     = (1+73),
    kMiposaurSoundFile_DINO_SNIGGER_1                   = (1+74),
    kMiposaurSoundFile_DINO_SNORE_1                     = (1+75),
    kMiposaurSoundFile_DINO_SULK_1                      = (1+76),
    kMiposaurSoundFile_DINO_SULK_2                      = (1+77),
    kMiposaurSoundFile_DINO_SWISH_1                     = (1+78),
    kMiposaurSoundFile_DINO_SWISH_2                     = (1+79),
    kMiposaurSoundFile_DINO_SWISH_SMALL_MOVEMENT_2      = (1+80),
    kMiposaurSoundFile_DINO_SWOOSH_1                    = (1+81),
    kMiposaurSoundFile_DINO_SWOOSH_2                    = (1+82),
    kMiposaurSoundFile_DINO_TEDDY                       = (1+83),
    kMiposaurSoundFile_DINO_UGHHHH_2                    = (1+84),
    kMiposaurSoundFile_DINO_VICTORY_1                   = (1+85),
    kMiposaurSoundFile_DINO_VICTORY_2                   = (1+86),
    kMiposaurSoundFile_DINO_VOMIT_1                     = (1+87),
    kMiposaurSoundFile_DINO_WHIMPER_1                   = (1+88),
    kMiposaurSoundFile_DINO_YAWN_1                      = (1+89),
    kMiposaurSoundFile_DINO_YUMMY_1                     = (1+90),
    kMiposaurSoundFile_DINO_AWW_1                       = (1+91),
    kMiposaurSoundFile_DINO_AWW_2                       = (1+92),
    
    ////Needed cross check datasheet
    kMiposaurSoundFile_SOUND_BOOST           = (1+100),
    kMiposaurSoundFile_SOUND_CAGE            = (1+101),
    kMiposaurSoundFile_SOUND_GUNS            = (1+102),
    kMiposaurSoundFile_SOUND_ZINGS           = (1+103),
    kMiposaurSoundFile_SHORT_MUTE_FOR_STOP   = (1+104),
    kMiposaurSoundFile_FREESTYLE_TRACKING_2  = (1+105),
};

typedef NS_OPTIONS(uint8_t, kMiposaurBroadcastDataKey) {
    kMiposaurBroadcastDataAvatarIcon = 0x00,
};

typedef NS_OPTIONS(uint8_t, kMiposaurPingResponse) {
    kMiposaurPingResponseNormalRomNoBootloader = 0x00,
    kMiposaurPingResponseNormalRomHasBootloader = 0x01,
    kMiposaurPingResponseBootloader = 0x02
};
@interface MiposaurCommandValues : NSObject

@end
