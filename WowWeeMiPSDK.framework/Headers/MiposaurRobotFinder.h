/*
 * Copyright 2010-2014 WowWee Group Ltd, All Rights Reserved.
 *
 * Licensed under the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

@import CoreBluetooth;

#import "MiposaurRobot.h"
#import "BluetoothRobotFinder.h"

FOUNDATION_EXPORT NSString *const MiposaurRobotFinderNotificationID;
FOUNDATION_EXPORT bool const MIPOSAUR_ROBOT_FINDER_DEBUG_MODE;

/**
 These are the values that can be sent from MiposaurRobotFinder
 */
typedef enum : NSUInteger {
    MiposaurRobotFinderNote_MiposaurFound = 1,
    MiposaurRobotFinderNote_MiposaurListCleared,
    MiposaurRobotFinderNote_BluetoothError,
    MiposaurRobotFinderNote_BluetoothIsOff,
    MiposaurRobotFinderNote_BluetoothIsAvailable,
    MiposaurRobotFinderNote_BluetoothNotSupport
} MiposaurRobotFinderNote;

@interface MiposaurRobotFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

/**

 */

@property (nonatomic, strong, readonly) NSMutableArray *miposaursFound;
@property (nonatomic, strong, readonly) NSMutableArray *miposaursConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

// Log level
@property (nonatomic, assign) MIPOSAURLogLevel logLevel;

/**
 Starts the BLE scanning
 */
-(void)scanForMiposaurs;

/**
 Starts the BLE scanning for a specified number of seconds. Normally you should use this method because endlessly scanning is very battery intensive.
 */
-(void)scanForMiposaursForDuration:(NSUInteger)seconds;
-(void)stopScanForMiposaurs;
-(void)clearFoundMiposaurList;

/**
 Quick access to first connected miposaur in mipsConnected list
 @return mipsConnected[0] or nil if mipsConnected is empty
 */
-(MiposaurRobot *)firstConnectedMiposaur;

@end