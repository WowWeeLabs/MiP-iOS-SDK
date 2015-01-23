Submitting to the Apple AppStore
==================================

It seems Apple rejects universal framework with i386 and x86_64 architecture support. 
More details can be found in this thread, particularly user big3 (from Apple)’s respond:
https://devforums.apple.com/thread/244357?start=25&tstart=0

We can use lipo tool to strip the support for i386 and x86_64 before submit, but note that stripping these 2 architectures will result in failure to compile for Simulator.

Please refer to [issue #4](https://github.com/WowWeeLabs/MiP-iOS-SDK/issues/4) if you have any questions on this

If you wish to strip the framework yourself you can use the following command on OSX

    lipo -remove i386 -remove x86_64 WowWeeMiPSDK -output WowWeeMiPSDK
