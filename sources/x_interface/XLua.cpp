#include "StdAfx.h"
#include "XLua.h"

#include <x_foundation/XPlatform.h>
#include <x_foundation/XDebugMacros.h>
#include <x_foundation/XStringBuilder.h>

#include <lua_tinker.h>

using namespace xf;

namespace xi { 

int XLua::Print(lua_State* L)
{
    int n = lua_gettop(L);
    lua_getglobal(L, "tostring");

    const size_t PRINT_TEXT_CAPACITY = 4096;
    XStringBuilder textBuilder((char*)alloca(PRINT_TEXT_CAPACITY), PRINT_TEXT_CAPACITY);
    for (int i = 1; i <= n; ++i)
    {
        lua_pushvalue(L, -1);
        lua_pushvalue(L, i);
        lua_call(L, 1, 1);

        const char* paramChars = lua_tostring(L, -1); 
        if (paramChars == NULL)
            return luaL_error(L, "NO_STRING_IN_LUA_STACK:%s", textBuilder.GetChars());

        if (i > 1)
        {
            if (!textBuilder.TryAppendChar(' '))
                return luaL_error(L, "TOO_LONG_STRING_TO_PRINT:%s", textBuilder.GetChars());
        }

        const size_t paramSize = lua_strlen(L, -1); 
        if (!textBuilder.TryAppendCStr(paramChars, paramSize))
        {
            return luaL_error(L, "TOO_LONG_STRING_TO_PRINT:%s PARAM:%s", textBuilder.GetChars(), paramChars);
        }
        lua_pop(L, 1);
    }

    XString text(textBuilder.ToString());

    lua_Debug ar;
    if(lua_getstack(L, 1, &ar) == 1)
    {
        auto& logger = xf::XPlatform::GetLogger();  

        lua_getinfo(L, "nSlu", &ar);

        if (ar.name)
            logger.Print(xf::X_LOG_DEBUG, text, ar.source, ar.currentline, ar.name);
        else
            logger.Print(xf::X_LOG_DEBUG, text, ar.source, ar.currentline, "__global__");
    }
    else
    {
        x_debug(text);
    }
    return 0;
}

int XLua::DoFile(lua_State* L)
{
    const char* modulePath = lua_tostring(L, -1);
    if (!modulePath)
        return luaL_error(L, "not string in the lua stack");

    x_debug(modulePath);

    char moduleUri[512];
    sprintf(moduleUri, "app:%s", modulePath);

    auto& fileManager = XPlatform::GetFileManager();
    auto moduleTextp = fileManager.LoadText(moduleUri);
    auto& moduleText = *moduleTextp;
    auto moduleTextSize = moduleText.GetSize();
    auto moduleTextChars = moduleText.GetChars();
    lua_tinker::dobuffer(L, moduleTextChars, moduleTextSize, moduleUri);

    lua_pop(L, 1);

    return 0;
}

} // end_of_namespace:xi
