//
//  Joystick.h
//  MIP
//
//  Created by Josh Savage on 9/9/13.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol JoystickViewDelegate;

@interface JoystickView : UIView

/** Delegate to report joystick updates to */
@property (strong, nonatomic) id<JoystickViewDelegate>delegate;

/** Joystick center image view */
@property (strong, nonatomic) UIImageView *joystickCenter;

/** Joystick center image scale  */
@property (nonatomic) float joystickCenterScale;

/** Joystick frame image view. Note this will be resized to the Joystick views frame  */
@property (strong, nonatomic) UIImageView *joystickFrame;

/** Touch point that is currently being tracked */
@property (weak, nonatomic) UITouch *touchToTrack;

/** Whether or not to lock the joystick to vertical movement only */
@property (nonatomic) BOOL lockToVerticalAxis;

/** Whether or not to lock the joystick to horizontal movement only */
@property (nonatomic) BOOL lockToHorizontalAxis;

/** Init with frame */
- (id)initWithFrame:(CGRect)frame;

/** Sets Joystick center and frame images.
 
 Note: The frame is resized into the JoystickView frame size. Images need to be included into main bundle.
 
 @param joystickCenter Image for Joystick center e.g. Joy_Center.png
 
 @param frameImage Image for Joystick frame e.g. Joy_Frame.png
 
 */
- (void)setJoystickCenterImage: (NSString *)joystickCenter frameImage: (NSString *)joystickFrame;

/** Returns current position of Joystick center as a vector. 
 
 @return Joystick position as a vector
 */
- (CGVector)joystickVector;

/** Resets joystick */
- (void)reset;

@end

/** Delegate for joystick updates */
@protocol JoystickViewDelegate <NSObject>

@optional
/** Is called when the joystick is moved */
- (void)joystickUpdate: (JoystickView *)joystick vector: (CGVector)vector;
/** Is called when the joystick becomes active with a touch */
- (void)joystickActive: (JoystickView *)joystick;
/** Is called when the joystick becomes inactive because the user has lifted their finger */
- (void)joystickInactive: (JoystickView *)joystick;

@end