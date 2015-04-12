#pragma once

#ifndef __X_STRING__
#define __X_STRING__

#include <stdlib.h>
#include <string.h>

namespace xf {

class XString
{
public:
    static XString EMPTY;

public:
    inline XString()
    : m_strPtr("")
    , m_strLen(0)
    {}

    inline XString(const char* strPtr)
    : m_strPtr(strPtr)
    , m_strLen(strlen(strPtr))
    {}

    inline XString(const char* strPtr, size_t strLen)
    : m_strPtr(strPtr)
    , m_strLen(strLen)
    {}

public:
    inline const char* GetPtr() const { return m_strPtr; }
    inline size_t GetLen() const { return m_strLen; }

public:
    inline size_t GetLastIndexOf(char inCharCode) const
    {
        size_t retIndex;
        if (!TryGetLastIndexOf(inCharCode, retIndex))
            return (size_t)-1;

        return retIndex;
    }
    
    inline XString GetSliceRight(size_t index) const
    {
        XString retSlice;
        if (!TryGetSliceRight(index, retSlice))
            return EMPTY;

        return retSlice;
    }

public:
    inline bool TryGetLastIndexOf(char inCharCode, size_t& outIndex) const
    {
        const char* endCharPtr = m_strPtr + m_strLen;
        if (m_strPtr == endCharPtr)
            return false;

        endCharPtr--;

        while (endCharPtr != m_strPtr)
        {
            if (*endCharPtr == inCharCode)
            {
                outIndex = (endCharPtr - m_strPtr);
                outIndex++;
                return true;        
            }
            endCharPtr--;
        }

        outIndex = 0;
        return true;
    }

    inline bool TryGetSliceRight(size_t index, XString& outSlice) const
    {
        if (index >= m_strLen)
            return false;

        outSlice = XString(m_strPtr + index, m_strLen - index); 
        return true;
    }

private:
    const char* m_strPtr;
    size_t m_strLen;
};


} // end_of_namespace:xf

#endif
