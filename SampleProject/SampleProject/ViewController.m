//
//  ViewController.m
//  SampleProject
//
//  Created by Andy on 10/9/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import "ViewController.h"

@import WowWeeMiPSDK;

@interface ViewController () <MipRobotDelegate>
@property (nonatomic, weak) MipRobot *mip;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self addNotificationObservers];
    [MipRobotFinder sharedInstance];
}

- (void)dealloc {
    [self removeNotificationObservers];
    self.mip = nil;
}

- (void)viewDidAppear:(BOOL)animated {
    // We need to wait 1 second to make sure that bluetooth is ready
    //[self performSelector:@selector(scan) withObject:nil afterDelay:1];
    [self scan];
}

- (void)scan {
    [[MipRobotFinder sharedInstance] scanForAllRobots];
}

- (void)addNotificationObservers {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(mipFoundNotification:) name:MipRobotFinderNotificationID object:nil];
}
     
- (void)removeNotificationObservers {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:MipRobotFinderNotificationID object:nil];
}

#pragma mark - Button Actions
- (IBAction)playSoundPressed:(id)sender {
    NSLog(@"Playing MiP Sound");
    
    // Distinguish different robot by mipRobotType
    if(self.mip.mipRobotType == MipType_MinionMip) {
        // Playing sound in TurboDave by kMinionMipSoundFileValue
        kMinionMipSoundFileValue value;
        switch (rand()%4) {
            case 0:
                value = kMinionMipSoundFile_SPEECH_S_DMF_MINION_HELLO;
                break;
                
            case 1:
                value = kMinionMipSoundFile_NEW_FART_WET;
                break;
                
            case 2:
                value = kMinionMipSoundFile_SCREAMS_DMF_MINION_SCREAMS_INTO_TRASH_CAN_DM2;
                break;
                
            default:
                value = kMinionMipSoundFile_HAPPY_KEVIN_DIAL_116_OH_NO_ME_LE_DO_IT;
                break;
        }
        [(MinionMipRobot*)self.mip minionPlaySoundWithEnum:value];
    }
    else {
        // When playing a sound we need to first create a sound object, all available builtin sounds are avaialble as constants using kMipSoundFile
        kMipSoundFileValue value;
        switch (rand()%4) {
            case 0:
                value = kMipSoundFile_MIP_FIGHT;
                break;
                
            case 1:
                value = kMipSoundFile_MIP_IN_LOVE;
                break;
                
            case 2:
                value = kMipSoundFile_MIP_3;
                break;
                
            default:
                value = kMipSoundFile_MIP_MUSIC;
                break;
        }
        MipRobotSound *mipSound = [MipRobotSound mipRobotSoundWithFile:value];
        
        [self.mip mipPlaySound:mipSound];
    }
}

- (IBAction)changeChestRGBPressed:(id)sender {
    NSLog(@"Changing RGB colour");
    
    // Pass a UIColor here to define what colour you want the Chest RGB to turn
    UIColor* ledColor;
    switch (rand()%7) {
        case 0:
            ledColor = [UIColor redColor];
            break;
            
        case 1:
            ledColor = [UIColor greenColor];
            break;
            
        case 2:
            ledColor = [UIColor yellowColor];
            break;
            
        case 3:
            ledColor = [UIColor orangeColor];
            break;
            
        case 4:
            ledColor = [UIColor purpleColor];
            break;
            
        case 5:
            ledColor = [UIColor whiteColor];
            break;
            
        case 6:
            ledColor = [UIColor blueColor];
            break;
    }
    
    [self.mip setMipChestRGBLedWithColor:ledColor];
}

- (IBAction)falloverPressed:(id)sender {
    NSLog(@"MiP is falling forward.... Tiiiiiimmmmmmbbeeeeer!");
    
    // Mip can fall forward or backward, in our example we are just simply making him fall forward
    [self.mip mipFalloverWithStyle:kMipPositionFaceDown]; // only kMipPositionFaceDown / kMipPositionOnBack
}



#pragma mark - MipRobotFinder Notification
- (void)mipFoundNotification:(NSNotification *)note {
    NSDictionary *noteDict = note.userInfo;
    if (!noteDict || !noteDict[@"code"]) {
        return;
    }
    MipRobotFinderNote noteType = (MipRobotFinderNote)[noteDict[@"code"] integerValue];
    
    if (noteType == MipRobotFinderNote_MipFound) {
        MipRobot *mip = noteDict[@"data"];
        // Normally you might want to add this object to an array and use a UITableView to display all the found devices for the user to select. For now we just want to print this MiP to the console
        NSLog(@"Found: %@", mip);
        self.mipStatusLabel.text = [NSString stringWithFormat:@"Found MiP: %@", mip.name];
        
        // We have one MiP so stop scanning
        [[MipRobotFinder sharedInstance] stopScanForMips];
        
        // Before connecting we want to setup which class is going to handle callbacks, for simplicity we are going to use this class for everything but normally you might use a different class
        mip.delegate = self;
        
        self.mipStatusLabel.text = [NSString stringWithFormat:@"Connecting: %@", mip.name];
        
        // Lets connect
        [mip connect];
    } else if (noteType == MipRobotFinderNote_BluetoothError) {
        CBCentralManagerState errorCode = (CBCentralManagerState)[noteDict[@"data"] integerValue];
        if (errorCode == CBCentralManagerStateUnsupported) {
            NSLog(@"Bluetooth Unsupported on this device");
            self.mipStatusLabel.text = @"Bluetooth Unsupported on this device";
        } else if (errorCode == CBCentralManagerStatePoweredOff) {
            NSLog(@"Bluetooth is turned off");
            self.mipStatusLabel.text = @"Bluetooth Unsupported on this device";
        }
    } else if (noteType == MipRobotFinderNote_BluetoothIsAvailable) {
        //[[MipRobotFinder sharedInstance] scanForMips];
    }
}

#pragma mark - MipRobot Callbacks


- (void) MipDeviceReady:(MipRobot *)mip {
    self.mip = mip;
    // Yay we are connected and ready to talk
    self.mipStatusLabel.text = [NSString stringWithFormat:@"Connected: %@", mip.name];
    self.playSoundButton.enabled = YES;
    self.changeRGBColourButton.enabled = YES;
    self.falloverButton.enabled = YES;
    self.driveButton.enabled = YES;
    self.weightLevel.enabled =YES;


    

    
    [self.mip readMipSensorWeightLevel];
    
    
    [self.mip getMipClapStatus];
    
    
    [self.mip getMipGestureMode];
    
}



-(void) MipRobot:(MipRobot *)mip didReceiveNumberOfClaps:(NSUInteger)claptimes{
    NSLog(@"(void) MipRobot:(MipRobot *)mip didReceiveNumberOfClaps:(NSUInteger)claptimes");
}
-(void) MipRobot:(MipRobot *)mip didReceiveClapDetectionStatusIsEnabled:(bool)isEnabled withMSTiming:(NSUInteger)milliseconds{
    
    NSLog(@"didReceiveClapDetectionStatusIsEnabled %d %lu",isEnabled, (unsigned long)milliseconds);
    
    
    if (!isEnabled)
    {
        [self.mip setMipClapDelayTime:1000];
        [self.mip setMipClapEnable:true];
    }
}


- (void) MipDeviceDisconnected:(MipRobot *)mip error:(NSError *)error {
    self.mipStatusLabel.text = [NSString stringWithFormat:@"Disconnected from MiP"];
    self.playSoundButton.enabled = NO;
    self.changeRGBColourButton.enabled = NO;
    self.falloverButton.enabled = NO;
    self.driveButton.enabled = NO;
    self.weightLevel.enabled =NO;
    self.mip = nil;
    [[MipRobotFinder sharedInstance] clearFoundMipList];
    [[MipRobotFinder sharedInstance] scanForMips];
}

-(void) MipRobot:(MipRobot *)mip didReceiveWeightReading:(uint8_t)value learningForward:(bool)learningForward {
    NSLog(@"didReceiveWeightReading");
    
    int8_t weight = value;
    
    [self.weightLevel setText:[NSString stringWithFormat:@"Level = %d !",weight]];
    
    [self performSelector:@selector(resetLevel) withObject:nil afterDelay:2];
    
}

-(void) MipRobot:(MipRobot *)mip didReceiveGestureMode:(kMipGestureModeValue)value
{
    if (value == kMipGestureMode_Off)
    {
        [self.mip setMipGestureMode:kMipGestureMode_On];
        [self.mip getMipGestureMode];
    }else
    {
        
        NSLog(@"Gesture ready");
    }
}

-(void) MipRobot:(MipRobot *)mip didReceiveGesture:(kMipGestureValue)value{
    
    NSLog(@"didReceiveGesture %@",[MipCommandValues gestureText:value]);
    
}

-(void)resetLevel{
[self.weightLevel setText:[NSString stringWithFormat:@"Weight Level"]];
}
@end
