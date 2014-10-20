//
//  DriveViewController.h
//  MiPSampleProject
//
//  Created by Forrest Chan on 20/10/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JoystickView.h"


@interface DriveViewController : UIViewController<JoystickViewDelegate>

@property (weak, nonatomic) IBOutlet JoystickView *leftJoystick;
@property (weak, nonatomic) IBOutlet JoystickView *rightJoystick;

@end
