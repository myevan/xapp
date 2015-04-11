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

    inline void AppendCStr(const char* inPtr)
    {
        m_curPos += strlen(inPtr);
    }

    inline void AppendXStr(const XString& in)
    {
        m_curPos += in.GetLen();
    }

    inline void AppendForm(size_t inMaxLen, const char* fmt, ...)
    {
        m_curPos += inMaxLen;
    }

    inline size_t GetLen()
    {
        return m_curPos;
    }

private:
    size_t m_curPos; 
};




} // end_of_namespace:xf

#endif
