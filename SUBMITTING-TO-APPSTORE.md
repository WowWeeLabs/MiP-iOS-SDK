Submitting to the Apple AppStore
==================================

It looks like Apple is currently rejecting apps which have a framework that includes simulator support. 

We have a special version of the framework which has stripped out simulator support for submitting to the AppStore.

It's exactly the same as the normal framework except it only includes mobile device support.

Please refer to [issue #4](https://github.com/WowWeeLabs/MiP-iOS-SDK/issues/4) if you have any questions on this

If you wish to strip the framework yourself you can use the following command on OSX

    lipo -remove i386 -remove x86_64 WowWeeMiPSDK -output WowWeeMiPSDK