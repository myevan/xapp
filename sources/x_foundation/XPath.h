#pragma once

#ifndef __X_PATH__
#define __X_PATH__

#include <x_foundation/XString.h>

namespace xf {

class XPath
{
public:
    XPath();
    XPath(const char* str);
    XPath(const XString& str);

    void AssignPath(const XPath& path);
    void AssignXStr(const XString& str);
    void AssignSStr(const std::string& str);

    void AppendPath(const XPath& path);
    void AppendXStr(const XString& str);
    void AppendSStr(const std::string& str);
    void AppendSep();

public:
    void SplitBranchAndLeaf(XPath& outBranch, XPath& outLeaf) const;

    void GetBranchExceptLeafs(size_t leafCount, XPath& outBranch) const;
    void GetLeafExceptRelNodes(size_t& outRelNodeCount, XPath& outLeaf) const;

    bool IsRelPath() const;


    XString ToXStr() const
    { return XString(m_str.c_str(), m_str.length()); }

    const std::string& ToSStr() const
    { return m_str; }

    const char* GetChars() const
    { return m_str.c_str(); }

    size_t GetSize() const
    { return m_str.length(); }

private:
    std::string m_str;

private:
    static char m_sep;
};


} // end_of_namespace:xf

#endif
