#pragma once

#ifndef __X_LUA__
#define __X_LUA__

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
};

namespace xlua { 

int Print(lua_State* L);
int DoFile(lua_State* L);

}

#endif

