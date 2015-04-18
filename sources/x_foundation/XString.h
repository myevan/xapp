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

    inline bool Equals(const char* chars) const
    {
        for (size_t i = 0; i != m_size; ++i)
        {
            if (m_chars[i] != chars[i])
                return false;
        }

        if (chars[m_size] != '\0')
            return false;

        return true;
    }

    inline size_t GetFirstIndexOf(char inCharCode) const
    {
        size_t retIndex;
        if (!TryGetFirstIndexOf(inCharCode, retIndex))
            return (size_t)-1;

        return retIndex;
    }

    inline size_t GetLastIndexOf(char inCharCode) const
    {
        size_t retIndex;
        if (!TryGetLastIndexOf(inCharCode, retIndex))
            return (size_t)-1;

        return retIndex;
    }
    
    inline XString GetSlice(size_t leftIndex, size_t rightIndex) const
    {
        if (leftIndex >= m_size)
            return EMPTY;

        if (rightIndex >= m_size)
            return EMPTY;

        if (leftIndex >= rightIndex)
            return EMPTY;

        return XString(m_chars + leftIndex, rightIndex - leftIndex); 
    }

    inline XString GetSliceLeft(size_t index) const
    {
        if (index >= m_size)
            return EMPTY;

        return XString(m_chars, index); 
    }

    inline XString GetSliceRight(size_t index) const
    {
        if (index >= m_size)
            return EMPTY;

        return XString(m_chars + index, m_size - index); 
    }

public:
    inline bool TryGetFirstIndexOf(char inCharCode, size_t& outIndex) const
    {
        const char* baseCharPtr = m_chars;
        const char* endCharPtr = m_chars + m_size;
        if (baseCharPtr == endCharPtr)
            return false;

        const char* eachCharPtr = baseCharPtr;
        while (eachCharPtr != endCharPtr)
        {
            if (*eachCharPtr == inCharCode)
            {
                outIndex = (eachCharPtr - baseCharPtr);
                return true;        
            }
            eachCharPtr++;
        }

        return false;
    }

    inline bool TryGetLastIndexOf(char inCharCode, size_t& outIndex) const
    {
        const char* baseCharPtr = m_chars;
        const char* eachCharPtr = m_chars + m_size;
        if (baseCharPtr == eachCharPtr)
            return false;

        eachCharPtr--;

        while (eachCharPtr != baseCharPtr)
        {
            if (*eachCharPtr == inCharCode)
            {
                outIndex = (eachCharPtr - baseCharPtr);
                return true;        
            }
            eachCharPtr--;
        }

        return false;
    }


private:
    const char* m_chars;
    size_t m_size;
};


} // end_of_namespace:xf

#endif
