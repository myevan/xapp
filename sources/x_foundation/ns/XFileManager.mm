#include "StdAfx.h"

#import "x_foundation/ns/XFileManager.h"
#import "x_foundation/ns/NSString+XString.h"

using namespace xf;

namespace xf { namespace ns {

XFileManager::XFileManager()
{
    m_mainBundle = [NSBundle mainBundle];
}

std::shared_ptr<XText> XFileManager::LoadText(const XString& uri)
{
    size_t schemeSepIndex;
    if (!uri.TryGetFirstIndexOf(':', schemeSepIndex))
        return std::shared_ptr<XText>();

    XString scheme = uri.GetSliceLeft(schemeSepIndex);
    if (scheme.Equals("app"))
    {
        size_t lastSlashIndex;
        if (!uri.TryGetLastIndexOf('/', lastSlashIndex))
            lastSlashIndex = schemeSepIndex;

        XString xFileName = uri.GetSliceRight(lastSlashIndex + 1);
        XString xDirPath = uri.GetSlice(schemeSepIndex + 1, lastSlashIndex);

        NSString* nDirPath = [NSString stringWithXString:xDirPath];
        NSString* nFileName = [NSString stringWithXString:xFileName];
        NSString* nFileAbsPath = [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
        if (nFileAbsPath == nil) 
            return std::shared_ptr<XText>();

        XString xFileAbsPath([nFileAbsPath UTF8String], [nFileAbsPath length]);
        return xf::XFileManager::LoadText(xFileAbsPath);
    }

    return std::shared_ptr<XText>();
}

} } // end_of_namespace:xf.ns
