//
//  BluetoothRobotFinder.h
//  Bluetooth Library Tester
//
//  Created by Andy on 19/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

@class BluetoothRobot;

@interface BluetoothRobotFinder : NSObject

@property (nonatomic, strong) NSArray *autoConnectRobotIdentifiers;
@property (nonatomic, assign) bool autoConnectToKnownRobotIdentifiers;

- (void) addAutoConnectRobot:(BluetoothRobot *)robot;
- (void) removeAutoConnectRobot:(BluetoothRobot *)robot;

@end
