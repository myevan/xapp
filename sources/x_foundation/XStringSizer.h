#pragma once

#ifndef __X_STRING_SIZER__
#define __X_STRING_SIZER__

namespace xf {

class XStringSizer
{
public:
    XStringSizer()
    : curPos(0)
    {}

    void AppendChar(const char inChar)
    {
        curPos++;
    }

    void AppendXStr(const XString& in)
    {
        curPos += in.GetLen();
    }

    void AppendIntf(size_t inMaxLen, const char* fmt, int value)
    {
        curPos += inMaxLen;
    }

    size_t GetLen()
    {
        return curPos;
    }

private:
    size_t m_maxLen; 
};




} // end_of_namespace:xf

#endif
