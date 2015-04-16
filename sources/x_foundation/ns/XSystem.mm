#include "StdAfx.h"

#include <x_foundation/ns/XSystem.h>
#include <x_foundation/ns/XString.h>

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

bool XSystem::TryGetResourceAbsPath(const XString& dirPath, const XString& fileName, std::string& outAbsPath)
{
    NSString* nDirPath = [NSString stringWithUTF8String:dirPath.GetPtr() length:dirPath.GetLen()];
    NSString* nFileName = [NSString stringWithUTF8String:fileName.GetPtr() length:fileName.GetLen()];
    NSString* nResAbsPath = [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
    if (nResAbsPath == nil) 
        return false;

    const char* cResAbsPath = [nResAbsPath UTF8String];
    outAbsPath = cResAbsPath;
    return true;
}

} } // end_of_namespace:xf.ns
