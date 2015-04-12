//
//  ViewController.m
//  hello
//
//  Created by Song Young-jin on 2015. 4. 12..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

#import "ViewController.h"

#include <x_foundation/XBaseConfig.h>
#include <x_foundation/XLogMacros.h>
#include <x_foundation/XSystem.h>

using namespace xf;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    XBaseConfig& baseConfig = XBaseConfig::GetBaseConfig();
    const XString& title = baseConfig.GetTitle();
    self.mainLabel.stringValue = [NSString stringWithUTF8String:title.GetPtr()];
    
    x_debugn("!!");
    
    
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
