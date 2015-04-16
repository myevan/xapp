#include "StdAfx.h"

#import "x_foundation/ns/XSystem.h"
#import "x_foundation/ns/NSString+XString.h"

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
    NSString* nResAbsPath = XSystem::NSGetResourceAbsPath(dirPath, fileName);
    if (nResAbsPath == nil) 
        return false;

    const char* cResAbsPath = [nResAbsPath UTF8String];
    outAbsPath = cResAbsPath;
    return true;
}

XBinary* XSystem::TryGetResourceBinary(const XString& dirPath, const XString& fileName)
{
    NSString* nResAbsPath = XSystem::NSGetResourceAbsPath(dirPath, fileName);
    if (nResAbsPath == nil) 
        return NULL;

    return NULL; 
}

NSString* XSystem::NSGetResourceAbsPath(const XString& xDirPath, const XString& xFileName)
{
    NSString* nDirPath = [[[NSString alloc] initWithBytes:xDirPath.GetPtr() length:xDirPath.GetLen() encoding:NSUTF8StringEncoding] autorelease];
    //NSString* nFileName = [[[NSString alloc] initWithBytes:xFileName.GetPtr() length:xFileName.GetLen() encoding:NSUTF8StringEncoding] autorelease];
    NSString* nFileName = [NSString stringWithXString:xFileName];
    return [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
}

} } // end_of_namespace:xf.ns
