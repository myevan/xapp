//
//  ViewController.m
//  hello
//
//  Created by Song Young-jin on 2015. 4. 12..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

#import "ViewController.h"

#import <x_foundation/XBaseConfig.h>
#import <x_foundation/XLogMacros.h>
#import <x_foundation/XSystem.h>
#import <x_foundation/XBinary.h>
#import <x_foundation/ns/NSString+XString.h>

#import <string>
#import <memory>

using namespace xf;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    XBaseConfig& baseConfig = XBaseConfig::GetBaseConfig();
    const XString& title = baseConfig.GetTitle();
    self.mainLabel.stringValue = [NSString stringWithXString:title];
    
    x_debugn("!!");
    
    std::string testAbsPath;
    XSystem& system = XSystem::GetSystem();
    if (!system.TryGetResourceAbsPath("", "test.txt", testAbsPath))
    {
        x_debugn("not_found_test");
        return;
    }
    
    x_debugn(testAbsPath);
    
    std::shared_ptr<XText> textPtr = system.LoadFileText(testAbsPath);
    if (!textPtr)
    {
        x_debugn("not_loaded_text");
        return;
    }
    
    x_debugn(textPtr->GetChars());
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
