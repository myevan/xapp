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
    : m_textPtr("")
    , m_textLen(0)
    {}

    inline XString(const char* textPtr)
    : m_textPtr(textPtr)
    , m_textLen(strlen(textPtr))
    {}

    inline XString(const char* textPtr, size_t textLen)
    : m_textPtr(textPtr)
    , m_textLen(textLen)
    {}

public:
    inline const char* GetTextPtr() const { return m_textPtr; }
    inline size_t GetTextLen() const { return m_textLen; }

public:
    inline size_t GetLastIndexOf(char inCharCode) const
    {
        size_t retIndex;
        if (!TryGetLastIndexOf(inCharCode, retIndex))
            return (size_t)-1;

        return retIndex;
    }
    
    inline XString GetUnsafeRight(size_t index) const
    {
        XString retSlice;
        if (!TryGetUnsafeRight(index, retSlice))
            return EMPTY;

        return retSlice;
    }

public:
    inline bool TryGetLastIndexOf(char inCharCode, size_t& outIndex) const
    {
        const char* endCharPtr = m_textPtr + m_textLen;
        if (m_textPtr == endCharPtr)
            return false;

        endCharPtr--;

        while (endCharPtr != m_textPtr)
        {
            if (*endCharPtr == inCharCode)
            {
                outIndex = (endCharPtr - m_textPtr);
                outIndex++;
                return true;        
            }
            endCharPtr--;
        }

        outIndex = 0;
        return true;
    }

    inline bool TryGetUnsafeRight(size_t index, XString& outSlice) const
    {
        if (index >= m_textLen)
            return false;

        outSlice = XString(m_textPtr + index, m_textLen - index); 
        return true;
    }

private:
    const char* m_textPtr;
    size_t m_textLen;
};


} // end_of_namespace:xf

#endif
