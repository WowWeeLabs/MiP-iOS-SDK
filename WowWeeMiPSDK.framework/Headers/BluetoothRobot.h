//
//  BluetoothRobot.h
//  bttester
//
//  Created by Andy on 16/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import <Foundation/Foundation.h>

// Notificaitons
FOUNDATION_EXPORT NSString *const ROBOT_COMMAND_RECIEVED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const ROBOT_CONNECTED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const ROBOT_DISCONNECTED_NOTIFICATION_NAME;

@interface BluetoothRobot : NSObject

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic) BOOL autoReconnect;
@property (nonatomic) BOOL useCommandQueue;

- (void)connect;
- (void)connectWithCallback:(void (^)(NSError *))callback;
- (void)disconnect;
- (BOOL)isConnected;

@end
