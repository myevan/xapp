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

    void WriteEndChar();

    inline char* GetChars() 
    { return (char*)GetBytes(); }

    inline const char* GetChars() const 
    { return (const char*)GetBytes(); }

    inline operator const char*()
    { return (char*)GetBytes(); }

    inline operator const char*() const
    { return (char*)GetBytes(); }

};

} // end_of_namespace:xf

#endif

