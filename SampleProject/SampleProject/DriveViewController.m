//
//  DriveViewController.m
//  MiPSampleProject
//
//  Created by Forrest Chan on 20/10/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <WowWeeMiPSDK/WowWeeMiPSDK.h>
#import "DriveViewController.h"

@interface DriveViewController ()

@property (nonatomic, strong) NSTimer *joystickTimer;
@property (nonatomic) CGVector movementVector;
@property (strong, nonatomic) MipRobot *mip;

@end

@implementation DriveViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Configure joysticks
    [self.leftJoystick setHidden: true];
    [self.leftJoystick setJoystickCenterImage:@"joy_fw_bk.png" frameImage: @"joy_outerring.png"];
    [self.leftJoystick setJoystickCenterScale: 0.5];
    [self.leftJoystick setDelegate: self];
    
    [self.rightJoystick setHidden: true];
    [self.rightJoystick setJoystickCenterImage:@"joy_l_r.png" frameImage: @"joy_outerring.png"];
    [self.rightJoystick setJoystickCenterScale: 0.5];
    [self.rightJoystick setDelegate: self];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // Get first connected mip
    self.mip = [[MipRobotFinder sharedInstance] firstConnectedMip];
    
    // Joystick timer
    self.joystickTimer = [NSTimer scheduledTimerWithTimeInterval:0.05 target:self selector:@selector(joystickTimerCallback) userInfo:nil repeats: true];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
    // Reset timer
    [self.joystickTimer invalidate];
    self.joystickTimer = nil;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Timer Callback
- (void)joystickTimerCallback {
    if(self.movementVector.dx != 0 || self.movementVector.dy != 0){
        [self.mip mipDrive:self.movementVector];
    }
}

#pragma mark - JoystickViewDelegate
- (void)joystickUpdate:(JoystickView *)joystick vector:(CGVector)vector {
    self.movementVector = CGVectorMake([self.rightJoystick joystickVector].dx, [self.leftJoystick joystickVector].dy);
}

#pragma mark - Button Actions
- (IBAction)backAction:(id)sender {
    [self dismissViewControllerAnimated:YES completion:NULL];
}

#pragma mark - Touches
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        CGPoint location = [touch locationInView: self.view];
        if(location.x < self.view.frame.size.width / 2) {
            // left side
            if(!self.leftJoystick.touchToTrack){
                [self.leftJoystick setHidden: false];
                [self.leftJoystick setCenter: location];
                [self.leftJoystick setTouchToTrack: touch];
            }
        }
        else {
            // right side
            if(!self.rightJoystick.touchToTrack){
                [self.rightJoystick setHidden: false];
                [self.rightJoystick setCenter: location];
                [self.rightJoystick setTouchToTrack: touch];
            }
        }
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(touch == self.leftJoystick.touchToTrack) {
            [self.leftJoystick touchesMoved: [[NSSet alloc] initWithObjects: touch, nil] withEvent: event];
        }
        else if(touch == self.rightJoystick.touchToTrack){
            [self.rightJoystick touchesMoved: [[NSSet alloc] initWithObjects: touch, nil] withEvent: event];
        }
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(touch == self.leftJoystick.touchToTrack){
            [self.leftJoystick touchesEnded: [[NSSet alloc] initWithObjects: touch, nil] withEvent: event];
            [self.leftJoystick setHidden: true];
        }
        else if(touch == self.rightJoystick.touchToTrack){
            [self.rightJoystick touchesEnded: [[NSSet alloc] initWithObjects: touch, nil] withEvent: event];
            [self.rightJoystick setHidden: true];
        }
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(touch == self.leftJoystick.touchToTrack){
            [self.leftJoystick touchesCancelled: [[NSSet alloc] initWithObjects: touch, nil] withEvent: event];
            [self.leftJoystick setHidden: true];
        }
        else if(touch == self.rightJoystick.touchToTrack){
            [self.rightJoystick touchesCancelled: [[NSSet alloc] initWithObjects: touch, nil] withEvent: event];
            [self.rightJoystick setHidden: true];
        }
    }
}

@end
