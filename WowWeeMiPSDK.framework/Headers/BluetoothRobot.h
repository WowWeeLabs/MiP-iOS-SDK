//
//  BluetoothRobot.h
//  bttester
//
//  Created by Andy on 16/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

@interface BluetoothRobot : NSObject

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic) BOOL autoReconnect;

- (void)connect;
- (void)connectWithCallback:(void (^)(NSError *))callback;
- (void)disconnect;
- (BOOL)isConnected;

@end
