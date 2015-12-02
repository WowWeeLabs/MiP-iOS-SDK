//
//  EventManager.h
//  MIP
//
//  Created by Andy on 7/3/14.
//  Copyright (c) 2014 WowWee Group Limited. All rights reserved.
//

@import Foundation;
#import "MiposaurRobot.h"

@interface MiposaurEventManager : NSObject <MiposaurRobotDelegate>
@property (nonatomic, assign) bool logging;

@property (nonatomic, assign) bool eventShakeSoundEnabled;
@property (nonatomic, strong) NSArray *eventShakeMiposaurSounds;
@property (nonatomic, strong) NSArray *eventShakeDeviceSounds;

@property (nonatomic, assign) bool eventFalloverSoundEnabled;
@property (nonatomic, strong) NSArray *eventFalloverMiposaurSounds;
@property (nonatomic, strong) NSArray *eventFalloverDeviceSounds;

@property (nonatomic, assign) bool eventHandStandSoundEnabled;
@property (nonatomic, strong) NSArray *eventHandStandMiposaurSounds;
@property (nonatomic, strong) NSArray *eventHandStandDeviceSounds;

@property (nonatomic, assign) bool eventDizzySoundEnabled;
@property (nonatomic, strong) NSArray *eventDizzyMiposaurSounds;
@property (nonatomic, strong) NSArray *eventDizzyDeviceSounds;

@property (nonatomic, assign) bool eventClapSoundEnabled;
@property (nonatomic, assign) uint8_t eventClapDetectNumber;
@property (nonatomic, strong) NSArray *eventClapMiposaurSounds;
@property (nonatomic, strong) NSArray *eventClapDeviceSounds;

@property (nonatomic, assign) bool eventConnectSoundEnabled;
@property (nonatomic, strong) NSArray *eventConnectMiposaurSounds;
@property (nonatomic, strong) NSArray *eventConnectDeviceSounds;

@property (nonatomic, assign) bool idleTimerEnabled;
@property (nonatomic, assign) NSTimeInterval idleTimeout;
@property (nonatomic, strong) NSArray *idleMiposaurSounds;
@property (nonatomic, strong) NSArray *idleDeviceSounds;

@property (nonatomic, assign) bool sleepTimerEnabled;
@property (nonatomic, assign) NSTimeInterval sleepTimeout;
@property (nonatomic, strong) NSArray *sleepMiposaurSounds;
@property (nonatomic, strong) NSArray *sleepDeviceSounds;

@property (nonatomic, assign) bool eventEyesBlinkEnabled;
@property (nonatomic, assign) NSTimeInterval eventEyesBlinkSpeed;

-(id) initWithMiposaur:(MiposaurRobot *)miposaur;
-(void) setAllEventsEnabled:(bool)value;
-(void) touchEvent;

@end
