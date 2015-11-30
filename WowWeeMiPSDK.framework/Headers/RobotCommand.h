//
//  BluetoothRobotCommand.h
//  Minimiposaur Factory Tester
//
//  Created by Andy on 19/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

typedef void(^CommandCallbackBlock)(NSError *);

@interface RobotCommand : NSObject

@property (nonatomic, assign, readonly) uint8_t cmdByte;
@property (nonatomic, strong, readonly) NSArray *dataArray;
@property (nonatomic, strong) CommandCallbackBlock completedCallback;
@property (nonatomic, assign, readonly) NSUInteger length;

+ (RobotCommand *)robotCommandWithAsciiHexString:(NSString *)asciiHex;

+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command;

+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1;
+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1 byte2:(uint8_t)byte2;
+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1 byte2:(uint8_t)byte2 byte3:(uint8_t)byte3;
+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1 byte2:(uint8_t)byte2 byte3:(uint8_t)byte3 byte4:(uint8_t)byte4;
+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1 byte2:(uint8_t)byte2 byte3:(uint8_t)byte3 byte4:(uint8_t)byte4 byte5:(uint8_t)byte5;
+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1 byte2:(uint8_t)byte2 byte3:(uint8_t)byte3 byte4:(uint8_t)byte4 byte5:(uint8_t)byte5 byte6:(uint8_t)byte6;
+ (RobotCommand *)robotCommandWithUInt8:(uint8_t)command byte1:(uint8_t)byte1 byte2:(uint8_t)byte2 byte3:(uint8_t)byte3 byte4:(uint8_t)byte4 byte5:(uint8_t)byte5 byte6:(uint8_t)byte6 byte7:(uint8_t)byte7;

+ (RobotCommand *)robotCommandWithBytes:(uint8_t)command byteCount:(unsigned int)byteCount bytes:(uint8_t)bytes, ...;
+ (RobotCommand *) robotCommandWithData:(NSData *)data;

- (id) initWithUInt8:(uint8_t)command;
- (id) initWithUInt8:(uint8_t)command withDataArray:(NSArray *)dataArray;
- (id) initWithRawCommandByteArray:(NSArray *)byteArray;

- (NSData *) data;

- (NSString *) description;

@end
