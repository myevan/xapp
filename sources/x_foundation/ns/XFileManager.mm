#include "StdAfx.h"

#import "x_foundation/ns/XFileManager.h"
#import "x_foundation/ns/NSString+XString.h"

using namespace xf;

namespace xf { namespace ns {

XFileManager::XFileManager()
{
    m_mainBundle = [NSBundle mainBundle];
}

bool XFileManager::TryGetResourceAbsPath(const XString& dirPath, const XString& fileName, std::string& outAbsPath)
{
    NSString* nResAbsPath = XFileManager::NSGetResourceAbsPath(dirPath, fileName);
    if (nResAbsPath == nil) 
        return false;

    const char* cResAbsPath = [nResAbsPath UTF8String];
    outAbsPath = cResAbsPath;
    return true;
}

XBinary* XFileManager::TryGetResourceBinary(const XString& dirPath, const XString& fileName)
{
    NSString* nResAbsPath = XFileManager::NSGetResourceAbsPath(dirPath, fileName);
    if (nResAbsPath == nil) 
        return NULL;

    return NULL; 
}

NSString* XFileManager::NSGetResourceAbsPath(const XString& dirPath, const XString& fileName)
{
    NSString* nDirPath = [NSString stringWithXString:dirPath];
    NSString* nFileName = [NSString stringWithXString:fileName];
    return [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
}

} } // end_of_namespace:xf.ns
