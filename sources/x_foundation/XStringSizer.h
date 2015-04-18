#pragma once

#ifndef __X_STRING_SIZER__
#define __X_STRING_SIZER__

namespace xf {

class XStringSizer
{
public:
    XStringSizer()
    : m_curPos(0)
    {}

    inline void AppendChar(const char inChar)
    {
        m_curPos++;
    }

    inline void AppendCStr(const char* inChars)
    {
        m_curPos += strlen(inChars);
    }

    inline void AppendXStr(const XString& inStr)
    {
        m_curPos += inStr.GetSize();
    }

    inline void AppendForm(size_t inMaxSize, const char* fmt, ...)
    {
        m_curPos += inMaxSize;
    }

    inline size_t GetSize()
    {
        return m_curPos;
    }

private:
    size_t m_curPos; 
};




} // end_of_namespace:xf

#endif
