#include "StdAfx.h"

#include <x_foundation/ns/XSystem.h>

using namespace xf;

namespace xf {

XSystem& XSystem::GetSystem()
{
    static ns::XSystem s_system;
    return s_system;
}

} // end_of_namespace:xf

namespace xf { namespace ns {

XSystem::XSystem()
{
    m_mainBundle = [NSBundle mainBundle];
}

bool XSystem::TryGetResourceAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath)
{
    NSString* nFileName = [NSString stringWithUTF8String:fileName.GetPtr()];
    NSString* nDirRelPath = [NSString stringWithUTF8String:dirRelPath.GetPtr()];
    NSString* nResAbsPath = [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirRelPath];
    if (nResAbsPath == nil) 
        return false;

    const char* cResAbsPath = [nResAbsPath UTF8String];
    outAbsPath = cResAbsPath;
    return true;
}

} } // end_of_namespace:xf.ns
