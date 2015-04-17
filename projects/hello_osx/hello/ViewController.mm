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
#import <x_foundation/XFileBinary.h>
#import <x_foundation/ns/NSString+XString.h>

#import <string>
#import <memory>

using namespace xf;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    XBaseConfig& baseConfig = XBaseConfig::GetBaseConfig();
    const XString& title = baseConfig.GetTitle();
    self.mainLabel.stringValue = [NSString stringWithUTF8String:title.GetPtr()];
    
    x_debugn("!!");
    
    std::string testAbsPath;
    XSystem& system = XSystem::GetSystem();
    if (!system.TryGetResourceAbsPath("", "test.txt", testAbsPath))
    {
        x_debugn("not_found_test");
        return;
    }
    
    x_debugn(testAbsPath);
    
    std::shared_ptr<XBinary> binPtr = XFileBinary::LoadFileBinary(testAbsPath);
    if (!binPtr)
    {
        x_debugn("not_loaded_bin");
        return;
    }
    
    std::string binText((const char*)binPtr->GetPtr(), binPtr->GetLen());
    x_debugn(binText);
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
