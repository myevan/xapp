#pragma once

#ifndef __X_BASE_CONFIG__
#define __X_BASE_CONFIG__

#include <x_foundation/XString.h>

namespace xf {

class XBaseConfig
{
public:
    static XBaseConfig& GetBaseConfig();

public:
    const XString& GetTitle() const;

};

} // end_of_namespace:xf

#endif

