#include "StdAfx.h"

#include <x_foundation/XPath.h>
#include <x_foundation/XString.h>

namespace xf {

XString XPath::GetPathLeaf(const XString& path)
{
    size_t lastSepIndex = path.GetLastIndexOf('/');
    return path.GetSliceRight(lastSepIndex + 1);
}

} // end_of_namespace:xf
