//
//  ViewController.m
//  hello
//
//  Created by Song Young-jin on 2015. 4. 12..
//  Copyright (c) 2015년 com.example. All rights reserved.
//

#import "ViewController.h"

#import <x_foundation/XPlatform.h>
#import <x_foundation/XStringBuilder.h>
#import <x_foundation/XDebugMacros.h>
#import <x_foundation/XStdMacros.h>

#import <x_interface/XLua.h>

#import <lua_tinker.h>

#import <string>
#import <memory>

using namespace xf;
using namespace xi;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    lua_State* L = lua_open();
    
    luaopen_base(L);
    
    lua_register(L, "print",    &XLua::Print);
    lua_register(L, "require",  &XLua::DoFile);
    lua_register(L, "dofile",   &XLua::DoFile);
    
    char luaLine[1024];
    XStringBuilder luaLineBuilder(luaLine, sizeof(luaLine));
    luaLineBuilder.AppendCStr("dofile(");
    luaLineBuilder.AppendChar('"');
    luaLineBuilder.AppendCStr("main.lua");
    luaLineBuilder.AppendChar('"');
    luaLineBuilder.AppendCStr(")");
    lua_tinker::dostring(L, luaLine);
    
    lua_close(L);
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
