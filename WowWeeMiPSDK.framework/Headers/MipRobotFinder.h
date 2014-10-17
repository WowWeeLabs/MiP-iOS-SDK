/*
 * Copyright 2010-2014 WowWee Group Ltd, All Rights Reserved.
 *
 * Licensed under the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

@import CoreBluetooth;

#import "MipRobot.h"
#import "BluetoothRobotFinder.h"

FOUNDATION_EXPORT NSString *const MipRobotFinderNotificationID;
FOUNDATION_EXPORT bool const MIP_ROBOT_FINDER_DEBUG_MODE;

/**
 These are the values that can be sent from MipRobotFinder
 */
typedef enum : NSUInteger {
    MipRobotFinderNote_MipFound = 1,
    MipRobotFinderNote_MipListCleared,
    MipRobotFinderNote_BluetoothError,
    MipRobotFinderNote_BluetoothIsOff,
    MipRobotFinderNote_BluetoothIsAvailable,
} MipRobotFinderNote;

@interface MipRobotFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

/**

 */
@property (nonatomic, strong, readonly) NSMutableArray *mipsFound;
@property (nonatomic, strong, readonly) NSMutableArray *mipsConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

// Log level
@property (nonatomic, assign) MIPLogLevel logLevel;

/**
 Starts the BLE scanning
 */
-(void)scanForMips;

/**
 Starts the BLE scanning for a specified number of seconds. Normally you should use this method because endlessly scanning is very battery intensive.
 */
-(void)scanForMipsForDuration:(NSUInteger)seconds;
-(void)stopScanForMips;
-(void)clearFoundMipList;

/**
 Quick access to first connected MiP in mipsConnected list
 @return mipsConnected[0] or nil if mipsConnected is empty
 */
-(MipRobot *)firstConnectedMip;

@end