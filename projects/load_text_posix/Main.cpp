#include "StdAfx.h"

#include <assert.h>

#include <x_foundation/XPlatform.h>
#include <x_foundation/XDebugMacros.h>

using namespace xf;

int main(int argc, const char** argv)
{
    auto& fileManager = XPlatform::GetFileManager();
    auto textp = fileManager.LoadFileText("test.txt");
    if (!textp)
    {
        x_debug("not_loaded_text");
        return -1;
    }
    
    x_debug(textp->GetChars());
    return 0;
}
