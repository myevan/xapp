#include "StdAfx.h"

#include <assert.h>

#include <x_foundation/XLogMacros.h>
#include <x_foundation/XSystem.h>

using namespace xf;

int main(int argc, const char** argv)
{
    XSystem& system = XSystem::GetSystem();
    std::shared_ptr<XText> textPtr = system.LoadFileText("test.txt");
    if (!textPtr)
    {
        x_debugn("not_loaded_text");
        return -1;
    }
    
    x_debugn(textPtr->GetChars());
    return 0;
}
