#include "StdAfx.h"

#include "XPath.h"
#include "XDebugMacros.h"

namespace xf {

char XPath::m_sep = '/';

XPath:: XPath()
{
}

XPath::XPath(const char* str)
{
    m_str = str;
}

XPath::XPath(const XString& str)
{
    m_str = str.ToString();
}

void XPath::AssignPath(const XPath& path)
{
    m_str = path.m_str;
}

void XPath::AssignXStr(const XString& str)
{
    m_str = str.ToString();
}

void XPath::AssignSStr(const std::string& str)
{
    m_str = str;
}

void XPath::AppendSep()
{
    size_t strLen = m_str.length();
    if (strLen > 0 && m_str[strLen - 1] == m_sep)
    {
        return;
    }

    m_str += m_sep;
}

void XPath::AppendPath(const XPath& path)
{
    if (path.m_str.empty())
        return;

    AppendSep();
   
    m_str += path.m_str; 
}
void XPath::AppendXStr(const XString& str)
{
    AppendSep();
    
    m_str.append(str.GetChars(), str.GetSize());
}

void XPath::AppendSStr(const std::string& str)
{
    AppendSep();
   
    m_str += str; 
}

void XPath::GetBranchExceptLeafs(size_t leafCount, XPath& outBranch) const
{
    int endIndex = m_str.length() - 1;

    size_t sepIndex = std::string::npos;
    while (endIndex >= 0 && leafCount > 0)
    {
        sepIndex = m_str.find_last_of(m_sep, endIndex + 1);
        if (sepIndex == std::string::npos)
            break;

        endIndex = sepIndex - 1;
        leafCount--;
    }

    outBranch.AssignSStr(m_str.substr(0, sepIndex));
}

bool XPath::IsRelPath() const
{
    if (m_str.empty())
        return true;

    if (m_str[0] == '.')
        return true;

    return false;
}

void XPath::GetLeafExceptRelNodes(size_t& outRelNodeCount, XPath& outLeaf) const
{
    size_t relNodeCount = 0;
    size_t curIndex = 0;
    size_t len = m_str.length();

    while (curIndex < len)
    {
        size_t sepIndex = m_str.find_first_of(m_sep, curIndex);
        if (sepIndex == std::string::npos)
            break;

        if (m_str[curIndex] != '.')
            break;

        if (m_str[curIndex + 1] == '.')
            relNodeCount++;

        curIndex = sepIndex + 1;
    }

    outRelNodeCount = relNodeCount;
    outLeaf.AssignSStr(m_str.substr(curIndex));
}

void XPath::SplitBranchAndLeaf(XPath& outBranch, XPath& outLeaf) const
{
    size_t lastSepIndex = m_str.find_last_of(m_sep);
    outBranch.AssignSStr(m_str.substr(0, lastSepIndex));
    outLeaf.AssignSStr(m_str.substr(lastSepIndex + 1));
}

} // end_of_namespace:xf
