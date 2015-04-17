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
    : m_bytes(NULL)
    , m_size(0)
    {}

    inline XBinary(byte_t* bytes, size_t size)
    : m_bytes(bytes)
    , m_size(size)
    {}

    void ReadBytes(size_t index, size_t size, byte_t* outBytes)
    {
        assert(index + size < m_size);
        memcpy(outBytes, m_bytes + index, size);
    }

    void WriteBytes(size_t index, size_t size, byte_t* inBytes)
    {
        assert(index + size < m_size);
        memcpy(m_bytes + index, inBytes, size);
    }

public:
    inline byte_t* GetBytes() 
    { return m_bytes; }

    inline const byte_t* GetBytes() const 
    { return m_bytes; }

    inline size_t GetSize() const 
    { return m_size; }

private:
    byte_t* m_bytes;
    size_t  m_size;
};

} // end_of_namespace:xf

#endif

