#include "StdAfx.h"
#include "XBinary.h"
#include "XDebugMacros.h"

namespace xf {

void XBinary::ReadBytes(size_t index, size_t size, byte_t* outBytes)
{
    x_assert(index + size < m_size);
    memcpy(outBytes, m_bytes + index, size);
}

void XBinary::WriteBytes(size_t index, size_t size, byte_t* inBytes)
{
    x_assert(index + size < m_size);
    memcpy(m_bytes + index, inBytes, size);
}

} // end_of_namespace:xf
