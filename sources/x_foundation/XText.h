#pragma once

#ifndef __X_TEXT__
#define __X_TEXT__

#include <x_foundation/XBuffer.h>

namespace xf {

class XText : public XBuffer
{
public:
    inline XText(size_t size, size_t capacity)
    : XBuffer(size, capacity + 1)
    {
    }

    void MakeEndChar()
    {
        byte_t* bytes = GetBytes();
        size_t size = GetSize();
        size_t capacity = GetCapacity();
        assert(size <= capacity);
        bytes[size] = 0;
    }

    inline char* GetChars() 
    { return (char*)GetBytes(); }

    inline const char* GetChars() const 
    { return (const char*)GetBytes(); }
};

} // end_of_namespace:xf

#endif

