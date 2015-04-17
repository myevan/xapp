#pragma once

#ifndef __X_BINARY__
#define __X_BINARY__

#include <x_foundation/XTypes.h>

namespace xf {

class XBinary
{
public:
    virtual ~XBinary() 
    {}

    inline XBinary()
    : m_binPtr(NULL)
    , m_binLen(0)
    {}

    inline XBinary(byte_t* strPtr, size_t strLen)
    : m_binPtr(strPtr)
    , m_binLen(strLen)
    {}

public:
    inline const byte_t* GetPtr() const { return m_binPtr; }
    inline size_t GetLen() const { return m_binLen; }

protected:
    byte_t* m_binPtr;
    size_t m_binLen;
};

} // end_of_namespace:xf

#endif

