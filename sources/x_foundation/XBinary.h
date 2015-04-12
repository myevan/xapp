#pragma once

#ifndef __X_BINARY__
#define __X_BINARY__

namespace xf {

class XBinary
{
public:
    inline XBinary()
    : m_binPtr(NULL)
    , m_binLen(0)
    , m_refCount(0)
    {}

    inline XBinary(unsigned char* strPtr, size_t strLen)
    : m_binPtr(strPtr)
    , m_binLen(strLen)
    , m_refCount(0)
    {}

    virtual void IncRef() 
    {
        m_refCount++; 
    }

    virtual void DecRef() 
    {
        m_refCount--;
        if (m_refCount <= 0)
        {
            DeleteThis();
        }
    }

protected:
    virtual void DeleteThis()
    {}


public:
    inline const unsigned char* GetPtr() const { return m_binPtr; }
    inline size_t GetLen() const { return m_binLen; }

private:
    unsigned char* m_binPtr;
    size_t m_binLen;

private:
    int m_refCount;
};

} // end_of_namespace:xf

#endif

