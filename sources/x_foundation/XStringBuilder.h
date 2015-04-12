#pragma once

#ifndef __X_STRING_BUILDER__
#define __X_STRING_BUILDER__

namespace xf {

class XStringBuilder
{
public:
    XStringBuilder(char* bufPtr, size_t maxLen)
    : m_bufPtr(bufPtr)
    , m_maxLen(maxLen)
    , m_curPos(0)
    {
        if (m_maxLen > 1)
            m_maxLen -= 1; // for last '\0' char
    }

    inline bool TryAppendCStr(const char* inPtr, size_t inLen)
    {
        size_t nextPos = m_curPos + inLen;
        if (nextPos >= m_maxLen)
        {
            nextPos = m_maxLen;
        }

        size_t copyLen = nextPos - m_curPos;
        if (copyLen == 0)
        {
            return false;
        }

        const char* srcPtr = inPtr;
        char* dstPtr = m_bufPtr + m_curPos;
        for (size_t i = 0; i != copyLen; ++i)
            dstPtr[i] = srcPtr[i];
        
        m_curPos = nextPos;
        m_bufPtr[m_curPos] = '\0';
        return true;
    }

    inline bool TryAppendChar(const char inChar)
    {
        if (m_curPos == m_maxLen)
            return false;

        m_bufPtr[m_curPos] = inChar;
        m_curPos++;
        m_bufPtr[m_curPos] = '\0';
        return true;
    }

    inline void AppendChar(const char inChar)
    {
        TryAppendChar(inChar);
    }

    inline void AppendCStr(const char* inPtr)
    {
        TryAppendCStr(inPtr, strlen(inPtr));
    }

    inline void AppendXStr(const XString& in)
    {
        TryAppendCStr(in.GetPtr(), in.GetLen());
    }

    inline void AppendForm(size_t inMaxLen, const char* fmt, int value)
    {
        char* inBuf = (char*)alloca(inMaxLen);
        sprintf(inBuf, fmt, value);
        TryAppendCStr(inBuf, strlen(inBuf));
    }
    
    inline const char* GetPtr() { return m_bufPtr; }
    inline size_t GetLen() { return m_curPos; }

private:
    char* m_bufPtr;
    size_t m_maxLen;
    size_t m_curPos;
};

} // end_of_namespace:xf

#endif
