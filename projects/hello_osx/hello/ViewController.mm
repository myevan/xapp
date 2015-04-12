//
//  ViewController.m
//  hello
//
//  Created by Song Young-jin on 2015. 4. 12..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

#import "ViewController.h"

#include <x_foundation/XInformation.h>
#include <x_foundation/XLogMacros.h>

using namespace xf;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    const XString& title = XInformation::GetTitle();
    self.mainLabel.stringValue = [NSString stringWithUTF8String:title.GetPtr()];
    
    x_debugn("!!");
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
