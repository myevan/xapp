#pragma once

#ifndef __X_LUA__
#define __X_LUA__

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
};

namespace xi { 

class XLua
{
public:
    static int Print(lua_State* L);
    static int DoFile(lua_State* L);
};

} // end_of_namespace:xi

#endif

