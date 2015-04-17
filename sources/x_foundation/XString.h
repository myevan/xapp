#pragma once

#ifndef __X_STRING__
#define __X_STRING__

#include <string>

namespace xf {

class XString
{
public:
    static XString EMPTY;

public:
    inline XString()
    : m_chars("")
    , m_size(0)
    {}

    inline XString(const char* chars)
    : m_chars(chars)
    , m_size(strlen(chars))
    {}

    inline XString(const char* chars, size_t size)
    : m_chars(chars)
    , m_size(size)
    {}

    inline XString(const std::string& str)
    : m_chars(str.c_str())
    , m_size(str.length())
    {}

public:
    inline const char* GetChars() const 
    { return m_chars; }

    inline size_t GetSize() const 
    { return m_size; }

    inline operator const char* () const
    { return m_chars; }

public:
    inline void GetString(std::string& outStr) const
    {
        outStr.assign(m_chars, m_size);
    }

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
        const char* endCharPtr = m_chars + m_size;
        if (m_chars == endCharPtr)
            return false;

        endCharPtr--;

        while (endCharPtr != m_chars)
        {
            if (*endCharPtr == inCharCode)
            {
                outIndex = (endCharPtr - m_chars);
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
        if (index >= m_size)
            return false;

        outSlice = XString(m_chars + index, m_size - index); 
        return true;
    }

private:
    const char* m_chars;
    size_t m_size;
};


} // end_of_namespace:xf

#endif
