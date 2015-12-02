//
//  MiposaurRobotSound.h
//  BobiMiposaurTester
//
//  Created by Andy on 28/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

#import "MiposaurCommandValues.h"


@class RobotCommand;

@interface MiposaurRobotSound : NSObject

@property (nonatomic, assign) int8_t soundVolume;
@property (nonatomic, assign) uint8_t soundDelay;
@property (nonatomic, assign) kMiposaurSoundFileValue soundFile;
@property (nonatomic, assign) uint8_t commandSize;

+(MiposaurRobotSound *) miposaurRobotSoundWithFile:(kMiposaurSoundFileValue)file;
+(MiposaurRobotSound *) miposaurRobotSoundWithFile:(kMiposaurSoundFileValue)file withDelay:(uint8_t)delay;
+(MiposaurRobotSound *) miposaurRobotSoundWithFile:(kMiposaurSoundFileValue)file withDelay:(uint8_t)delay withVolume:(uint8_t)volume;

-(id) initMiposaurRobotSoundWithFile:(kMiposaurSoundFileValue)file;
-(id) initMiposaurRobotSoundWithFile:(kMiposaurSoundFileValue)file withDelay:(uint8_t)delay;
-(id) initMiposaurRobotSoundWithFile:(kMiposaurSoundFileValue)file withDelay:(uint8_t)delay withVolume:(uint8_t)volume;
-(NSString *)description;
-(RobotCommand *) robotCommand;
-(NSArray *) byteArray;

@end
