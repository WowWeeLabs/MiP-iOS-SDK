WowWee MiP iOS SDK
================================
[![Gitter](https://badges.gitter.im/Join Chat.svg)](https://gitter.im/WowWeeLabs/MiP-iOS-SDK?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

![](Images/MiP.png)

The free MiP iOS SDK lets you control your [WowWee MiP robot](www.meetmip.com) on devices running iOS 8.0 and above and Xcode 6. To use this SDK you will also need a physical MiP robot.

There is also an [Android SDK](https://github.com/WowWeeLabs/MiP-Android-SDK) available.

For information on WowWee products visit: <http://www.wowwee.com>

Table of Contents
---------------------------------------

- [Quick Installation](#quick-installation)
- [Notes about the SDK](#notes-about-the-sdk)
- [Using the SDK](#using-the-sdk)
	- [Finding a MiP](#finding-mips)
	- [Connecting to MiP](#connecting-to-mip)
	- [Driving MiP](#driving-mip)
 	- [Other Cool Stuff](#other-cool-stuff)
- SDK Documentation (coming soon)
- [License](#license)
- [Contributing](#contributing)
- [Credits](#credits)
- [Projects using this SDK](#projects-using-this-sdk)


Quick Installation
---------------------------------

1. Clone the repository

		git clone https://github.com/WowWeeLabs/MiP-iOS-SDK.git

2. In XCode, create a new project. The simplest application is a Single-View application.

3. Open the project navigator in Xcode and drag the **WowWeeMiPSDK.framework** file from the Mac OS Finder to the Frameworks directory for your project in XCode.

![](Images/Project-Navigator-Example.png)

4. Confirm that the framework is added to your project by going into _Project Settings_ (first item in the project navigator), then click the first target (e.g. _MiPSampleProject_), then _Build Phases_. If there is not a _"Copy Files"_ phase., click the top left + to add one. Set the destination to _"Frameworks"_ and add the framework file under the _"Name"_ section.

![](Images/Copy-Framework-Example.png)

Also make that the framework is present under the _"Link Binary With Libraries"_ section.
	
![](Images/Link-Frameworks-Example.png)

5. In the ViewController.h file, add the following line at the top of the file:

		@import WowWeeMiP;
	
Alternatively you can add this line into your Project-Prefix.pch (e.g. _MiPSampleProject-Prefix.pch_) file so that you don't need to import in each class your planning to use the SDK in.
	
6. Check that the project compiles successfully after completing the above steps by pressing ⌘+b in Xcode to build the project. The project should build successfully.

7. Choose the classes you want to handle the delegate callbacks from a MiP Robot, these classes will receive callbacks for when events happen (such as finding a new robot, robot connected, robot falls over etc) in this case we will simply choose our ViewController.

To receive MiP Finder notifications, in the ViewController.h file, modify the following sections:
	
		- (void)viewDidLoad {
		  	[super viewDidLoad];
		  	
			// listen for callbacks
		  	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(mipFoundNotification:) name:MipRobotFinderNotificationID object:nil];
		  	
		  	// Init the robot finder
		  	[MipRobotFinder sharedInstance];
		}

		- (void)dealloc {
		  [[NSNotificationCenter defaultCenter] removeObserver:self name:MipRobotFinderNotificationID object:nil];
		}
		
		- (void)mipFoundNotification:(NSNotification *)note {
			NSDictionary *noteDict = note.userInfo;
			if (!noteDict || !noteDict[@"code"]) {
				// Looks like an invalid notification
			    return;
			}
			MipRobotFinderNotificationValue noteType = (MipRobotFinderNotificationValue)[noteDict[@"code"] integerValue];

			if (noteType == MipRobotFinder_MipFound) {
			    MipRobot *mip = noteDict[@"data"];
			    NSLog(@"Found: %@", mip);
			    mip.delegate = self;

				// TODO: change this if you don't need to automatically connect to first mip
				[mip connect];
			} else if (noteType == MipRobotFinder_BluetoothError) {
			    CBCentralManagerState errorCode = (CBCentralManagerState)[noteDict[@"data"] integerValue];
			    if (errorCode == CBCentralManagerStateUnsupported) {
			        NSLog(@"Bluetooth Unsupported on this device");
			    } else if (errorCode == CBCentralManagerStatePoweredOff) {
			        NSLog(@"Bluetooth is turned off");
		        }
			}
		}

    To receive MiP callbacks, in the ViewController.h file, change the interface to match the following:

		@interface ViewController <MiPRobotDelegate>
	
	In the interface definition add the following callbacks:
	
		- (void) MipDeviceReady:(MipRobot *)mip {
			NSLog(@"We are connected to MiP and ready to go");
		}

		- (void) MipDeviceDisconnected:(MipRobot *)mip error:(NSError *)error {
			NSLog(@"A mip was disconnected");
		}

8. You should be now ready to go! Plug in an iOS device then compile and run the project using ⌘+r . When you turn on a MiP you should see some debug messages in the logs.


Using the SDK
---------------------------------

### Finding MiPs
Once your application is listening to notifications, you need to issue the following call:

	[[MipRobotFinder sharedInstance] scanForMips];

Scanning is battery intensive so we recommend you don't continuously scan, instead you can use this to scan for 5 seconds then stop:

	[[MipRobotFinder sharedInstance] scanForMipsForDuration:5];

After a mip is found, the MipRobotFinder will send a notification with the following dictionary for the notification userInfo 

	{
		"code": MipRobotFinder_MipFound,
		"data": <MipRobot>		
	}

You can handle this notification using the following snippet from the sample project

	- (void)mipFoundNotification:(NSNotification *)note {
		if (noteType == MipRobotFinder_MipFound) {
	        MipRobot *mip = noteDict[@"data"];
	        NSLog(@"Found: %@", mip);
	    }
	}

In our sample project we automatically connect to the first MiP we find, however you can store these references and use them later, there is no need to connect initially. 

#### Special Note about using MipRobot objects
When MiPs are no longer available (e.g. the player turns one off), they will still contain a valid MipRobot instance object. The only way to know if the MiP is available is to try to connect to it, or do another scan.

### Connecting to MiP
-- Coming soon!

### Driving MiP
-- Coming soon!

### Playing a sound
-- Coming soon!

### Other Cool Stuff
-- Coming soon!


Notes about the SDK
---------------------------------

### CocoaPods Compatible

For now we do not support CocoaPods. Pull requests are welcome.

### Simulator Support

Our SDK fully builds for the simulator, however at present the IOS simulator does not support Bluetooth Low Energy. This means you will not be able to properly test the functionality without using a real IOS device.

### Submitting to the AppStore

Our SDK is a universal build which means it includes support for all platforms. Currently however Apple does not allow frameworks which contain simulator support to be submitted to the appstore. We provide a special framework for this purpose, but also it's very easy to do yourself. You can use the lipo tool provided on OSX.

    lipo -remove i386 -remove x86_64 WowWeeMiPSDK -output WowWeeMiPSDK

### Apple Watch Support

At present we don't have an Apple Watch device to test with. When it becomes available we are open to adding support for WatchKit.

### Full Source Code

At this stage we do not plan on releasing our full library source code. 

### Are there any restrictions on releasing my own application?

The SDK is currently and will always be free for you to build and release your own applications. Your welcome to charge money or release free applications using our SDK without restrictions.

If you create a great application, all we ask is that you provide a link for people to purchase their own MiP so they can enjoy your product.

### OSX Support

Currently the SDK is not available for OSX however we will make this available if it's important to you. If that's the case please open up an issue in the bug tracker.
.
### Can I use your cool joystick class?

Yes we have provided the source code in our sample project, feel free to use this or make changes as you want. We would love pull requests.

### Can I create other language versions of the SDK?

The lower level BLE command protocol is available in our [MiP-BLE-Protocol](http://github.com/WowWeeLabs/MiP-BLE-Protocol) repository.


License
---------------------------------
MiP iOS SDK is available under the Apache License, Version 2.0 license. See the [LICENSE.txt](https://raw.githubusercontent.com/WowWeeLabs/MiP-iOS-SDK/master/LICENSE.md) file for more info.

You are free to use our SDK in your own projects whether free or paid. There are no restrictions on releasing into the Apple App Store or Google Play.


Contributing
---------------------------------
We happily accept any pull requests and monitor issues on GitHub regularly. Please feel free to give us your suggestions or enhancements. Please note that due to resource constraints we most likely cannot add new features to the MiP robot himself, but we will certainly consider them for inclusion to future robots/versions.

Tell your friends, fork our project, buy our robot and share with us your own projects! These are the best kinds of positive feedback to us.

Credits
---------------------------------
* [YMSCoreBluetooth](https://github.com/kickingvegas/YmsCoreBluetooth.git) & [Our Fork](https://github.com/WowWeeLabs/YmsCoreBluetooth)
* [MSWeakTimer](https://github.com/mindsnacks/MSWeakTimer)
* [NSTimer-Blocks](https://github.com/jivadevoe/NSTimer-Blocks)
* [OWQueueStack](https://github.com/yangyubo/OWQueueStack)

Projects using this SDK
---------------------------------
* [WowWee MiP Official App](https://itunes.apple.com/us/app/mip-app/id768591497?mt=8)
* Send us a pull request to add your app here
