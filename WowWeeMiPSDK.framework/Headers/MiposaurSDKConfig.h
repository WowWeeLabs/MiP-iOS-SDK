//
//  MiposaurSDKConfig.h
//  WowWeeMiposaurSDK
//
//  Created by Andy on 17/9/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

// These can be overridden by defining them before importing the SDK


typedef enum {
    MRFScanOptionMask_ShowAllDevices       = 0,
    MRFScanOptionMask_FilterByProductId    = 1 << 0,
    MRFScanOptionMask_FilterByServices     = 1 << 1,
    MRFScanOptionMask_FilterByDeviceName   = 1 << 2,
} MiposaurRobotFinderScanOptions;

#ifndef MIPOSAUR_SCAN_OPTIONS
#define MIPOSAUR_SCAN_OPTIONS MRFScanOptionMask_ShowAllDevices | MRFScanOptionMask_FilterByProductId | MRFScanOptionMask_FilterByServices
#endif