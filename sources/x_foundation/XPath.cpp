#include "StdAfx.h"

#include "XPath.h"
#include "XDebugMacros.h"

namespace xf {

char XPath::m_sep = '/';

XPath::XPath(const XString& str)
: m_chars("")
, m_size(0)
{
    x_verify(TryAssignXStr(str), "TOO_LONG_PATH");
}

void XPath::AssignPath(const XPath& path)
{
    size_t pathSize = path.GetSize();
    memcpy(m_chars, path.GetChars(), pathSize);
    m_size = pathSize;
    m_chars[m_size] = '\0';
}

bool XPath::TryAssignXStr(const XString& str)
{
    size_t strSize = str.GetSize();
    if (strSize >= CAPACITY - 1)
        return false;

    memcpy(m_chars, str.GetChars(), strSize);
    m_size = strSize;
    m_chars[m_size] = '\0';
    return true;
}

bool XPath::TryAssignXStrBranch(const XString& str)
{
    XString branch = str.GetBranch(m_sep);
    return TryAssignXStr(branch);
}

bool XPath::TryAppendSep()
{
    if (m_size > 0 && m_chars[m_size - 1] != m_sep)
    {
        if (m_size + 1 >= CAPACITY - 1)
            return false;

        m_chars[m_size] += m_sep;
        m_size++;
    }
    return true;
}

bool XPath::TryAppendXStr(const XString& str)
{
    size_t strSize = str.GetSize();
    if (m_size + strSize >= CAPACITY - 1)
        return false;

    memcpy(m_chars + m_size, str.GetChars(), strSize);
    m_size += strSize;
    m_chars[m_size] = '\0';
    return true;
}

bool XPath::TryJoin(const XString& branch, const XString& leaf)
{
    const size_t branchSize = branch.GetSize();
    const char* branchChars = branch.GetChars();
    if (branchSize >= CAPACITY - 1)
        return false;
    
    memcpy(m_chars, branchChars, branchSize);
    m_size += branchSize;

    if (!TryAppendSep())
        return false;

    const size_t leafSize = leaf.GetSize();
    const char* leafChars = branch.GetChars();
    if (m_size + leafSize >= CAPACITY - 1)
        return false;

    memcpy(m_chars, leafChars, leafSize);
    m_size += leafSize;

    m_chars[m_size] = '\0';
    return true;
}

} // end_of_namespace:xf
