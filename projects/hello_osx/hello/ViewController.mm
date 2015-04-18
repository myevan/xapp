//
//  ViewController.m
//  hello
//
//  Created by Song Young-jin on 2015. 4. 12..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

#import "ViewController.h"

#import <x_foundation/XDebugMacros.h>
#import <x_foundation/XBaseConfig.h>
#import <x_foundation/XPlatform.h>
#import <x_foundation/XBinary.h>
#import <x_foundation/ns/NSString+XString.h>

#import <string>
#import <memory>

using namespace xf;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    x_debug("Hello World");

    auto& baseConfig = XBaseConfig::GetBaseConfig();
    const auto& title = baseConfig.GetTitle();
    self.mainLabel.stringValue = [NSString stringWithXString:title];
    
    auto& fileManager = XPlatform::GetFileManager();
    auto textp = fileManager.LoadText("app:test.txt");
    if (!textp)
    {
        x_debug("not_loaded_text");
        return;
    }
    
    x_debug(textp->GetChars());
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
