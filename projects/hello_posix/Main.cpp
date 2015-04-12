#include "StdAfx.h"

#include <x_foundation/XLogMacros.h>
#include <x_foundation/XBaseConfig.h>

using namespace xf;

int main(int argc, const char** argv)
{
    XBaseConfig& baseConfig = XBaseConfig::GetBaseConfig();
    const XString& title = baseConfig.GetTitle();
    x_debugn(title.GetPtr());
    return 0;
}
