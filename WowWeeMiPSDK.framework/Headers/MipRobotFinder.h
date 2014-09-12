//
//  BTCentralManager.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

// TODO: Should make this a subclass of BluetoothManager

@import CoreBluetooth;
#import "MipRobot.h"
#import "BluetoothRobotFinder.h"

FOUNDATION_EXPORT NSString *const MipRobotFinderNotificationID;
FOUNDATION_EXPORT bool const MIP_ROBOT_FINDER_DEBUG_MODE;

typedef enum {
    MRFScanOptionMask_ShowAllDevices       = 0,
    MRFScanOptionMask_FilterByProductId    = 1 << 0,
    MRFScanOptionMask_FilterByServices     = 1 << 1,
    MRFScanOptionMask_FilterByDeviceName   = 1 << 2,
} MipRobotFinderScanOptions;

typedef enum : NSUInteger {
    MipRobotFinder_MipFound = 1,
    MipRobotFinder_MipListCleared,
    MipRobotFinder_BluetoothError,
    MipRobotFinder_BluetoothIsOff,
    MipRobotFinder_BluetoothIsAvailable,
} MipRobotFinderNotificationValue;

@interface MipRobotFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

@property (assign, nonatomic) MipRobotFinderScanOptions scanOptionsFlagMask;

@property (nonatomic, strong, readonly) NSMutableArray *mipsFound;
@property (nonatomic, strong, readonly) NSMutableArray *mipsConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

+(id)sharedInstance;

-(void)scanForMips;
-(void)scanForMipsForDuration:(NSUInteger)seconds; // Scan only for a specified number of seconds (stops battery drain)
-(void)stopScanForMips;
-(MipRobot *)firstConnectedMip;
-(void)clearFoundMipList;

@end