#pragma once

#ifndef __X_BUFFER_STREAM__
#define __X_BUFFER_STREAM__

#include <x_foundation/XStream.h>
#include <x_foundation/XBuffer.h>

namespace xf {

class XBufferStream : public XStream
{
public:
    XBinaryStream(std::shared_ptr<XBuffer> bufferp)
    : m_bufferp(bufferp)
    , m_readIndex(0)
    { }

    virtual ~XBinaryStream()
    { }

    size_t GetSize() override
    { return m_bufferp->GetSize(); }

    size_t ReadBytes(size_t size, byte_t* outBytes) override
    { 
        size_t readSize = m_bufferp->ReadBytes(m_readIndex, size, outBytes); 
        m_readIndex += readSize;
        return readSize;
    }

private:
    std::shared_ptr<XBuffer> m_bufferp;

private:
    size_t m_readIndex;

};

} // end_of_namespace:xf

#endif
