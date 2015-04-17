#pragma once

#ifndef __X_BUFFER_
#define __X_BUFFER__

#include <x_foundation/XBinary.h>
#include <x_foundation/XLogMacros.h>

#include <memory>

namespace xf {

class XBuffer : public XBinary
{
public:
    virtual ~XBuffer()
    {
        byte_t* bytes = GetBytes();
        if (bytes != NULL)
        {
            x_debugn("free");
            free(bytes);
        }
    }

public:
    inline XBuffer(size_t size, size_t capacity)
    : XBinary((byte_t*)malloc(capacity), size)
    , m_capacity(capacity)
    {
        x_debugn("alloc");
    }

    size_t GetCapacity()
    { return m_capacity; }

private:
    size_t m_capacity;
};

} // end_of_namespace:xf.android

#endif

