#include "StdAfx.h"

#include <x_foundation/XBaseConfig.h>
#include <x_foundation/XString.h>

namespace xf {

XBaseConfig& XBaseConfig::GetBaseConfig()
{
    static XBaseConfig s_baseConfig;
    return s_baseConfig;
}

const XString& XBaseConfig::GetTitle() const
{
    static XString s_title("XApplication");
    return s_title;
}

} // end_of_namespace:xf
