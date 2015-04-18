#include "StdAfx.h"

#include <assert.h>

#include <x_foundation/XPlatform.h>
#include <x_foundation/XDebugMacros.h>

using namespace xf;

int main(int argc, const char** argv)
{
    XSystem& system = XPlatform::GetSystem();
    std::shared_ptr<XText> textPtr = system.LoadFileText("test.txt");
    if (!textPtr)
    {
        x_debug("not_loaded_text");
        return -1;
    }
    
    x_debug(textPtr->GetChars());
    return 0;
}
