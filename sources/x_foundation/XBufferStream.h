#pragma once

#ifndef __X_BUFFER_STREAM__
#define __X_BUFFER_STREAM__

#include <x_foundation/XStream.h>
#include <x_foundation/XBuffer.h>

namespace xf {

class XBufferStream : public XStream
{
public:
    XBufferStream(std::shared_ptr<XBuffer> bufp)
    : m_bufp(bufp)
    , m_readIndex(0)
    { }

    virtual ~XBufferStream()
    { }

    size_t GetSize() override
    { 
        XBuffer& buf = *m_bufp;
        return buf.GetSize(); 
    }

    size_t ReadBytes(size_t size, byte_t* outBytes) override
    { 
        XBuffer& buf = *m_bufp;
        buf.ReadBytes(m_readIndex, size, outBytes); 
        m_readIndex += size;
        return size;
    }

private:
    std::shared_ptr<XBuffer> m_bufp;

private:
    size_t m_readIndex;

};

} // end_of_namespace:xf

#endif
