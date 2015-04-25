#include "StdAfx.h"

#include <x_foundation/XPlatform.h>
#include <x_foundation/XDebugMacros.h>
#include <x_foundation/XStringBuilder.h>

#include <lua_tinker.h>

using namespace xf;

namespace xlua { 

int Print(lua_State* L)
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

int DoFile(lua_State* L)
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

} // end_of_namespace:xlua

int cpp_func(int arg1, int arg2)
{
    return arg1 + arg2;
}

int main(int argc, const char** argv)
{
    auto& fileManager = XPlatform::GetFileManager();
    fileManager.SetProgramPath(argv[0]);

    // Lua 를 초기화 한다.
    lua_State* L = lua_open();

    // Lua 기본 함수들을 로드한다.- print() 사용
    luaopen_base(L);

    lua_register(L, "print", &xlua::Print);
    lua_register(L, "require", &xlua::DoFile);
    lua_register(L, "dofile", &xlua::DoFile);

    // LuaTinker 를 이용해서 함수를 등록한다.
    lua_tinker::def(L, "cpp_func", cpp_func);

    // sample1.lua 파일을 로드/실행한다.
    lua_tinker::dostring(L, "dofile(\"main.lua\")");

    // sample1.lua 의 함수를 호출한다.
    int result = lua_tinker::call<int>(L, "lua_func", 3, 4);

    // lua_func(3,4) 의 결과물 출력
    printf("lua_func(3,4) = %d\n", result);

    // 프로그램 종료
    lua_close(L);

    return 0;
}
