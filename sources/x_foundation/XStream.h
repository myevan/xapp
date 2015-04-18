#pragma once

#ifndef __X_STREAM__
#define __X_STREAM__

#include <x_foundation/XTypes.h>

namespace xf {

class XStream
{
public:
    XStream()
    { }

    virtual ~XStream()
    { }

    virtual size_t GetSize()
    { return 0; }

    virtual size_t ReadBytes(size_t byteCount, byte_t* outBytes)
    { return 0; }
};

} // end_of_namespace:xf

#endif
