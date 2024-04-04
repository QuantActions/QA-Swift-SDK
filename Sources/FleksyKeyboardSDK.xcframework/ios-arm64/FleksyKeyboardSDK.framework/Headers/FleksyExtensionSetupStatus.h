//
//  FleksyExtensionSetupStatus.h
//  FleksyContainer
//
//  Created by Marco Vanossi on 8/15/14.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyContainer_FleksyExtensionSetupStatus_h
#define FleksyContainer_FleksyExtensionSetupStatus_h

// The values of these are purposefully unrelated to the semantics
// to prevent static analysis
#define FleksyDidBecomeActive @"FleksyFileManagerRestart"
#define FleksyDidBecomeInactive @"FleksyFileManagerReset"

/**
 Contains methods relating to checking if the extension is running or has full access.
 
 @note You don't need to make instances of this class.
 @note methods in this class rely on private API.
 @note most of the methods from this class have *major* caveats associated with them. Proceed with caution.
 */
@interface FleksyExtensionSetupStatus : NSObject

- (instancetype)init __attribute__((unavailable("All the methods are class methods, you don't need to instantiate this")));
/**
 @returns if the extension was added to settings in the system settings app
 @param extensionBundleId The bundle identifier of the keyboard extension that needs to be checked.
 */
+ (BOOL)isAddedToSettingsKeyboardExtensionWithBundleId:(NSString *)extensionBundleId;
/**
 @returns if the extension is currently the selected keyboard. 
 @note there are several unavoidable cases where this will not return a correct value, the user opening the app with fleksy enabled,
 then going out of the app and disabling Fleksy is one of them. This is only really useful in the onboarding sequence.
 @note this function relies on private API.
 */
+ (BOOL)isExtensionActive;

@end
#endif