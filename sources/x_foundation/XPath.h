#pragma once

#ifndef __X_PATH__
#define __X_PATH__

namespace xf {

class XString;

class XPath
{
public:
    static XString GetPathLeaf(const XString& path);

};


} // end_of_namespace:xf

#endif
