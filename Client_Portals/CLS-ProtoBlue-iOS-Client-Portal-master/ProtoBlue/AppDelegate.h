//
//  AppDelegate.h
//  ProtoBlue
//
//  Created by Lance T. Walker on 10/19/18.
//  Copyright © 2018 CodeLife-Productions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow * window;

// Core Data Defaults:
@property (readonly, strong) NSPersistentContainer *persistentContainer;
- (void) saveContext;
@end

