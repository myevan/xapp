#pragma once

#ifndef __X_PATH__
#define __X_PATH__

#include <x_foundation/XString.h>

namespace xf {

class XPath
{
public:
    static XString GetPathLeaf(const XString& path);

};


} // end_of_namespace:xf

#endif
