/* Copyright 2016 Realm Inc - All Rights Reserved
 * Proprietary and Confidential
 */

// Asynchronously submits build information to Realm if running in an iOS
// simulator or on OS X if a debugger is attached. Does nothing if running on an
// iOS / watchOS device or if a debugger is *not* attached.
//
// To be clear: this does *not* run when your app is in production or on
// your end-user’s devices; it will only run in the simulator or when a debugger
// is attached.
//
// Why are we doing this? In short, because it helps us build a better product
// for you. None of the data personally identifies you, your employer or your
// app, but it *will* help us understand what language you use, what iOS
// versions you target, etc. Having this info will help prioritizing our time,
// adding new features and deprecating old features. Collecting an anonymized
// bundle & anonymized MAC is the only way for us to count actual usage of the
// other metrics accurately. If we don’t have a way to deduplicate the info
// reported, it will be useless, as a single developer building their Swift app
// 10 times would report 10 times more than a single Objective-C developer that
// only builds once, making the data all but useless.
// No one likes sharing data unless it’s necessary, we get it, and we’ve
// debated adding this for a long long time. Since Realm is a free product
// without an email signup, we feel this is a necessary step so we can collect
// relevant data to build a better product for you. If you truly, absolutely
// feel compelled to not send this data back to Realm, then you can set an env
// variable named REALM_DISABLE_ANALYTICS. Since Realm is free we believe
// letting these analytics run is a small price to pay for the product & support
// we give you.
//
// Currently the following information is reported:
// - What kind of JavaScript framework is being used (e.g. React Native).
// - What version of Realm is being used, and from which language (obj-c or Swift).
// - What version of OS X it's running on (in case Xcode aggressively drops
//   support for older versions again, we need to know what we need to support).
// - The minimum iOS/OS X version that the application is targeting (again, to
//   help us decide what versions we need to support).
// - An anonymous MAC address and bundle ID to aggregate the other information on.
// - What version of Swift is being used (if applicable).

#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

void RLMSendAnalytics();

#ifdef __cplusplus
}
#endif
