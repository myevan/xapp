#include <x_foundation/XPath.h>

namespace xf {

XString XPath::GetPathLeaf(const XString& path)
{
    size_t lastSepIndex = path.GetLastIndexOf('/');
    return path.GetUnsafeRight(lastSepIndex);
}

} // end_of_namespace:xf
