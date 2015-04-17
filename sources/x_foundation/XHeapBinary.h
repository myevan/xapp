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
    template<typename T>
    static std::shared_ptr<T> AllocBinary(size_t binLen)
    {
        return std::shared_ptr<T>(new T(binLen), FreeBinary<T>);
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
};

} // end_of_namespace:xf.android

#endif

