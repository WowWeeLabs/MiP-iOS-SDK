//
//  MipRobotSound.h
//  BobiMipTester
//
//  Created by Andy on 28/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

#import "MipCommandValues.h"

@class RobotCommand;

@interface MipRobotSound : NSObject

@property (nonatomic, assign) int8_t soundVolume;
@property (nonatomic, assign) uint8_t soundDelay;
@property (nonatomic, assign) kMipSoundFileValue soundFile;
@property (nonatomic, assign) uint8_t commandSize;

+(MipRobotSound *) mipRobotSoundWithFile:(kMipSoundFileValue)file;
+(MipRobotSound *) mipRobotSoundWithFile:(kMipSoundFileValue)file withDelay:(uint8_t)delay;
+(MipRobotSound *) mipRobotSoundWithFile:(kMipSoundFileValue)file withDelay:(uint8_t)delay withVolume:(uint8_t)volume;

-(id) initMipRobotSoundWithFile:(kMipSoundFileValue)file;
-(id) initMipRobotSoundWithFile:(kMipSoundFileValue)file withDelay:(uint8_t)delay;
-(id) initMipRobotSoundWithFile:(kMipSoundFileValue)file withDelay:(uint8_t)delay withVolume:(uint8_t)volume;
-(NSString *)description;
-(RobotCommand *) robotCommand;
-(NSArray *) byteArray;

@end
