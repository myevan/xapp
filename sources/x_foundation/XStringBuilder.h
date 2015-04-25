#pragma once

#ifndef __X_STRING_BUILDER__
#define __X_STRING_BUILDER__

namespace xf {

class XStringBuilder
{
public:
    XStringBuilder(char* chars, size_t capacity)
    : m_chars(chars)
    , m_capacity(capacity)
    , m_size(0)
    {
        if (m_capacity > 1)
            m_capacity -= 1; // for last '\0' char
    }

    inline bool TryAppendCStr(const char* inChars, size_t inSize)
    {
        size_t nextPos = m_size + inSize;
        if (nextPos >= m_capacity)
        {
            nextPos = m_capacity;
        }

        size_t copyLen = nextPos - m_size;
        if (copyLen == 0)
        {
            return false;
        }

        const char* srcChars = inChars;
        char* dstChars = m_chars + m_size;
        for (size_t i = 0; i != copyLen; ++i)
            dstChars[i] = srcChars[i];
        
        m_size = nextPos;
        m_chars[m_size] = '\0';
        return true;
    }

    inline bool TryAppendChar(const char inChar)
    {
        if (m_size == m_capacity)
            return false;

        m_chars[m_size] = inChar;
        m_size++;
        m_chars[m_size] = '\0';
        return true;
    }

    inline void AppendChar(const char inChar)
    {
        TryAppendChar(inChar);
    }

    inline void AppendCStr(const char* inChars)
    {
        TryAppendCStr(inChars, strlen(inChars));
    }

    inline void AppendXStr(const XString& inStr)
    {
        TryAppendCStr(inStr.GetChars(), inStr.GetSize());
    }

    inline void AppendForm(size_t inCapacity, const char* fmt, int value)
    {
        char* inBuf = (char*)alloca(inCapacity);
        sprintf(inBuf, fmt, value);
        TryAppendCStr(inBuf, strlen(inBuf));
    }
    
    inline const char* GetChars() 
    { return m_chars; }

    inline size_t GetSize() 
    { return m_size; }

    inline XString ToString()
    { return XString(m_chars, m_size); }

private:
    char* m_chars;
    size_t m_capacity;
    size_t m_size;
};

} // end_of_namespace:xf

#endif
