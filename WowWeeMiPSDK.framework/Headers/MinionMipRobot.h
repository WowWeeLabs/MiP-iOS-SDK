//
//  MinionMipRobot.h
//  minionmip-cocos2d
//
//  Created by Alex Lam on 15/2/2017.
//
//

#import "MipRobot.h"
#import "MinionMipCommandValues.h"

@protocol MinionMipRobotDelegate;
@class MinionMipRobot;

@protocol MinionMipRobotDelegate <MipRobotDelegate>
@optional

@end


@interface MinionMipRobot : MipRobot

@property (nonatomic, weak) id<MinionMipRobotDelegate> delegate;

/**
 Use this function to play sound on TurboDave instead of mipPlaySound in MipRobot class
 */
- (void) minionPlaySoundWithEnum:(kMinionMipSoundFileValue)soundValue;

@end
