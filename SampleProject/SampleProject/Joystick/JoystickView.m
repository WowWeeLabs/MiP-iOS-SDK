//
//  Joystick.m
//  MIP
//
//  Created by Josh Savage on 9/9/13.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import "JoystickView.h"

@interface JoystickView ()

@property (nonatomic, readonly) float frameRadius;

@end

@implementation JoystickView

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder: aDecoder];
    if(self){
        [self initJoystick];
    }
    return self;
}

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self initJoystick];
    }
    return self;
}

- (void)initJoystick {
    _joystickCenterScale = 1.0;
}

- (void)setJoystickCenterImage: (NSString *)joystickCenter frameImage: (NSString *)joystickFrame {
    UIImage *joyCenterImage = [UIImage imageNamed: joystickCenter];
    UIImageView *joyCenterView = [[UIImageView alloc] initWithImage: joyCenterImage];
    [self setJoystickCenter: joyCenterView];
    
    UIImage *joyFrameImage = [UIImage imageNamed: joystickFrame];
    UIImageView *joyFrameView = [[UIImageView alloc] initWithImage: joyFrameImage];
    [self setJoystickFrame: joyFrameView];
}

- (void)setJoystickCenter:(UIImageView *)joystickCenter {
    [self.joystickCenter removeFromSuperview];
    _joystickCenter = joystickCenter;
    [self addSubview: self.joystickCenter];
    [self setJoystickCenterScale: self.joystickCenterScale];
    
    self.joystickCenter.center = CGPointMake(self.frame.size.width / 2, self.frame.size.height / 2);
}

- (void)setJoystickCenterScale: (float)scale {
    [self.joystickCenter setTransform: CGAffineTransformScale(CGAffineTransformIdentity, scale, scale)];
}

- (void)setFrame:(CGRect)frame {
    [super setFrame: frame];
    [self.joystickFrame setFrame: CGRectMake(0, 0, frame.size.width, frame.size.height)];
    _frameRadius = frame.size.width / 2;
}

- (void)setJoystickFrame:(UIImageView *)joystickFrame {
    [self.joystickFrame removeFromSuperview];
    
    CGSize size = self.frame.size;
    
    _joystickFrame = joystickFrame;
    [self.joystickFrame setFrame: CGRectMake(0, 0, size.width, size.height)];
    [self addSubview: self.joystickFrame];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(!self.touchToTrack){
            self.touchToTrack = touch;
            
            //CGPoint location = [touch locationInView: self];
            //CGPoint locationZeroed = CGPointMake(location.x - self.frame.size.width / 2, location.y - self.frame.size.height / 2);
            
            if([self.delegate respondsToSelector: @selector(joystickActive:)]){
                [self.delegate joystickActive: self];
            }
            if([self.delegate respondsToSelector: @selector(joystickUpdate:vector:)]){
                [self.delegate joystickUpdate: self vector: [self joystickVector]];
            }
        }
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(self.touchToTrack == touch){
            CGPoint location = [touch locationInView: self];
            CGPoint locationZeroed = CGPointMake(location.x - self.frame.size.width / 2, location.y - self.frame.size.height / 2);
            
            float angle = atan2f(locationZeroed.x, locationZeroed.y);
            float maxX = sinf(angle) * (self.frameRadius - self.joystickCenter.frame.size.width / 2);
            float maxY = cosf(angle) * (self.frameRadius - self.joystickCenter.frame.size.height / 2);
                        
            if((maxX > 0 && locationZeroed.x > maxX) || (maxX < 0 && locationZeroed.x < maxX)){
                location.x = maxX + self.frame.size.width / 2;
            }
            
            if((maxY > 0 && locationZeroed.y > maxY) || (maxY < 0 && locationZeroed.y < maxY)){
                location.y = maxY + self.frame.size.height / 2;
            }
            
            if(self.lockToVerticalAxis){
                location.x = self.joystickCenter.center.x;
            }
            if(self.lockToHorizontalAxis){
                location.y = self.joystickCenter.center.y;
            }
            
            [self.joystickCenter setCenter: location];
            
            if([self.delegate respondsToSelector: @selector(joystickUpdate:vector:)]){
                [self.delegate joystickUpdate: self vector: [self joystickVector]];
            }
        }
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(self.touchToTrack == touch){
            [self reset];
            if([self.delegate respondsToSelector: @selector(joystickUpdate:vector:)]){
                [self.delegate joystickUpdate: self vector: [self joystickVector]];
            }
            
            if([self.delegate respondsToSelector: @selector(joystickInactive:)]){
                [self.delegate joystickInactive: self];
            }
        }
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
    for(UITouch *touch in touches){
        if(self.touchToTrack == touch){
            [self reset];
            if([self.delegate respondsToSelector: @selector(joystickUpdate:vector:)]){
                [self.delegate joystickUpdate: self vector: [self joystickVector]];
            }
            
            if([self.delegate respondsToSelector: @selector(joystickInactive:)]){
                [self.delegate joystickInactive: self];
            }
        }
    }
}

- (CGVector)joystickVector {
    CGVector vector = CGVectorMake((self.joystickCenter.center.x - self.frame.size.width / 2) / (self.frameRadius / 2), -(self.joystickCenter.center.y - self.frame.size.height / 2) / (self.frameRadius / 2));
    
    return vector;
}

- (void)reset {
    self.touchToTrack = nil;
    self.joystickCenter.center = CGPointMake(self.frame.size.width / 2, self.frame.size.height / 2);
}

@end
