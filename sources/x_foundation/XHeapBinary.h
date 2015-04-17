#pragma once

#ifndef __X_HEAP_BINARY__
#define __X_HEAP_BINARY__

#include <x_foundation/XBinary.h>
#include <x_foundation/XLogMacros.h>

#include <memory>

namespace xf {

class XHeapBinary : public XBinary
{
public:
    virtual ~XHeapBinary()
    {
        if (m_binPtr != NULL)
        {
            x_debugn("free");
            free(m_binPtr);
        }
    }

protected:
    inline XHeapBinary()
    : XBinary()
    {
    }

    inline XHeapBinary(size_t binLen)
    : XBinary((byte_t*)malloc(binLen), binLen)
    {
        x_debugn("alloc");
    }
};

} // end_of_namespace:xf.android

#endif

