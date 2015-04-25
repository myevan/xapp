#include "StdAfx.h"

#include <x_foundation/XPlatform.h>
#include <x_foundation/XStringBuilder.h>
#include <x_foundation/XDebugMacros.h>
#include <x_foundation/XStdMacros.h>

#include <x_interface/XLua.h>

#include <lua_tinker.h>

using namespace xf;
using namespace xi;

int main(int argc, const char** argv)
{
    auto& fileManager = XPlatform::GetFileManager();
    fileManager.SetExecFilePath(argv[0]);
    fileManager.SetDataDirPath("../data/lua_posix");

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

    return 0;
}
