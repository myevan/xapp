#include "StdAfx.h"
#include "XText.h"
#include "XDebugMacros.h"

namespace xf {

void XText::WriteEndChar()
{
    byte_t* bytes = GetBytes();
    size_t size = GetSize();
    size_t capacity = GetCapacity();
    x_assert(size <= capacity);
    bytes[size] = 0;
}

} // end_of_namespace:xf

