#pragma once

#ifndef __X_PATH__
#define __X_PATH__

#include <x_foundation/XString.h>

namespace xf {

class XPath
{
public:
    enum
    {
        CAPACITY = 512
    };

public:
    XPath()
    : m_chars("")
    , m_size(0)
    {
    }

    XPath(const XString& str);

    void AssignPath(const XPath& path);
    bool TryAssignXStr(const XString& str);
    bool TryAssignXStrBranch(const XString& str);

    bool TryJoin(const XString& head, const XString& tail);

    bool TryAppendSep();
    bool TryAppendXStr(const XString& str);

public:
    const char* GetChars() const
    { return m_chars; }

    size_t GetSize() const
    { return m_size; }

private:
    char m_chars[CAPACITY];

private:
    size_t m_size;

private:
    static char m_sep;
};


} // end_of_namespace:xf

#endif
