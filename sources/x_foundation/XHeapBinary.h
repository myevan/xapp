#pragma once

#ifndef __X_HEAP_BINARY__
#define __X_HEAP_BINARY__

#include <x_foundation/XBinary.h>

#include <x_foundation/XLogMacros.h>

namespace xf {

class XHeapBinary : public XBinary
{
public:
    template<typename T>
    static T* AllocBinary(size_t binLen)
    {
        return new T(binLen);
    }

    template<typename T>
    static void FreeBinary(T* delBinPtr)
    {
        if (delBinPtr != NULL)
        {
            delete delBinPtr;
        }
    }

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
    : XBinary((unsigned char*)malloc(binLen), binLen)
    {
        x_debugn("alloc");
    }

    void DeleteThis()
    {
        FreeBinary(this);
    }
};

} // end_of_namespace:xf.android

#endif

